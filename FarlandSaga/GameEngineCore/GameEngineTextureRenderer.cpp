#include "PreCompile.h"
#include "GameEngineTextureRenderer.h"
#include "GameEngineTexture.h"
#include "GameEngineFolderTexture.h"

void FrameAnimation::Reset()
{
	Info.FrameTime = 0.0f;
	Info.CurFrame = Info.Start;
}


void FrameAnimation::Update(float _Delta)
{

	Info.FrameTime += _Delta;

	if (nullptr != Time)
	{
		Time(Info, _Delta);
	}

	if (false == bOnceStart
		&& Info.CurFrame == Info.Start
		&& nullptr != Start)
	{
		Start(Info);
		bOnceStart = true;
		bOnceEnd = false;
	}

	if (Info.Inter <= Info.FrameTime)
	{
		++Info.CurFrame;
		if (nullptr != Frame)
		{
			Frame(Info);
		}

		if (nullptr != Texture)
		{
			ParentRenderer->SetTexture(Texture, Info.CurFrame);
		}
		else if (nullptr != FolderTexture)
		{
			ParentRenderer->FrameDataReset();
			ParentRenderer->SetTexture(FolderTexture->GetTexture(Info.CurFrame));
		}
		else
		{
			MsgBoxAssert("�ؽ�ó�� ���õ��� ���� �ִϸ��̼� �Դϴ�.");
		}

		if (Info.CurFrame >= Info.End)
		{
			if (false == bOnceEnd && nullptr != End)
			{
				End(Info);
				bOnceEnd = true;
				bOnceStart = false;
			}

			if (true == Info.Loop)
			{
				Info.CurFrame = Info.Start;
			}
			else {
				Info.CurFrame = Info.End;
			}
		}

		Info.FrameTime -= Info.Inter;
	}
}

GameEngineTextureRenderer::GameEngineTextureRenderer()
{
}

GameEngineTextureRenderer::~GameEngineTextureRenderer()
{
}

void GameEngineTextureRenderer::Start()
{
	GameEngineDefaultRenderer::Start();
	SetPipeLine("TextureAtlas");

	FrameData.PosX = 0.0f;
	FrameData.PosY = 0.0f;
	FrameData.SizeX = 1.0f;
	FrameData.SizeY = 1.0f;

	ShaderResources.SetConstantBufferLink("AtlasData", FrameData);
}

void GameEngineTextureRenderer::SetTexture(GameEngineTexture* _Texture)
{
	CurTex = _Texture;
	ShaderResources.SetTexture("Tex", _Texture);
}

void GameEngineTextureRenderer::SetTexture(const std::string& _Name)
{
	CurTex = ShaderResources.SetTexture("Tex", _Name);
}

void GameEngineTextureRenderer::SetFrame(UINT _Index)
{
	FrameData = CurTex->GetFrameData(_Index);
}


void GameEngineTextureRenderer::SetTexture(const std::string& _Name, UINT _Index)
{
	SetTexture(_Name);
	SetFrame(_Index);
}

void GameEngineTextureRenderer::SetTexture(GameEngineTexture* _Texture, UINT _Index)
{
	if (nullptr == _Texture)
	{
		MsgBoxAssert("�������� �ʴ� �ؽ�ó�� ����Ϸ��� �߽��ϴ�.");
		return;
	}

	SetTexture(_Texture);
	SetFrame(_Index);
}

// ���� �����ӿ� ���´�.
void GameEngineTextureRenderer::AnimationBindStart(const std::string& _AnimationName, std::function<void(const FrameAnimation_DESC&)> Function)
{
	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

	if (FrameAni.end() == FrameAni.find(Name))
	{
		MsgBoxAssert("�������� �ʴ� �ִϸ��̼����� ü���� �Ϸ��� �߽��ϴ�.");
		return;
	}

	FrameAni[Name].Start = Function;
}
// ������ �����ӿ� ���´�
void GameEngineTextureRenderer::AnimationBindEnd(const std::string& _AnimationName, std::function<void(const FrameAnimation_DESC&)> Function)
{
	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

	if (FrameAni.end() == FrameAni.find(Name))
	{
		MsgBoxAssert("�������� �ʴ� �ִϸ��̼����� ü���� �Ϸ��� �߽��ϴ�.");
		return;
	}

	FrameAni[Name].End = Function;
}
// �������� �ٲ𶧸��� ���´�
void GameEngineTextureRenderer::AnimationBindFrame(const std::string& _AnimationName, std::function<void(const FrameAnimation_DESC&)> Function)
{
	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

	if (FrameAni.end() == FrameAni.find(Name))
	{
		MsgBoxAssert("�������� �ʴ� �ִϸ��̼����� ü���� �Ϸ��� �߽��ϴ�.");
		return;
	}

	FrameAni[Name].Frame = Function;
}

// Update
void GameEngineTextureRenderer::AnimationBindTime(const std::string& _AnimationName, std::function<void(const FrameAnimation_DESC&, float)> Function)
{
	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

	if (FrameAni.end() == FrameAni.find(Name))
	{
		MsgBoxAssert("�������� �ʴ� �ִϸ��̼����� ü���� �Ϸ��� �߽��ϴ�.");
		return;
	}

	FrameAni[Name].Time = Function;
}

void GameEngineTextureRenderer::CreateFrameAnimationFolder(const std::string& _AnimationName, const FrameAnimation_DESC& _Desc)
{
	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

	if (FrameAni.end() != FrameAni.find(Name))
	{
		MsgBoxAssert("�̹� �����ϴ� �ִϸ��̼��� �� ������� �߽��ϴ�.");
		return;
	}

	FrameAnimation& NewAni = FrameAni[Name];
	NewAni.Info = _Desc;
	NewAni.ParentRenderer = this;
	NewAni.Texture = nullptr;
	NewAni.FolderTexture = GameEngineFolderTexture::Find(_Desc.TextureName);

	if (NewAni.Info.Start == -1)
	{
		NewAni.Info.Start = 0;
	}

	if (NewAni.Info.End == -1)
	{
		NewAni.Info.End = NewAni.FolderTexture->GetTextureCount() - 1;
	}
}

void GameEngineTextureRenderer::CreateFrameAnimation(const std::string& _AnimationName, const FrameAnimation_DESC& _Desc)
{
	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

	if (FrameAni.end() != FrameAni.find(Name))
	{
		MsgBoxAssert("�̹� �����ϴ� �ִϸ��̼��� �� ������� �߽��ϴ�.");
		return;
	}

	FrameAnimation& NewAni = FrameAni[Name];
	NewAni.Info = _Desc;
	NewAni.ParentRenderer = this;
	NewAni.Texture = GameEngineTexture::Find(_Desc.TextureName);
	NewAni.FolderTexture = nullptr;
}

void GameEngineTextureRenderer::ChangeFrameAnimation(const std::string& _AnimationName)
{
	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

	if (FrameAni.end() == FrameAni.find(Name))
	{
		MsgBoxAssert("�������� �ʴ� �ִϸ��̼����� ü���� �Ϸ��� �߽��ϴ�.");
		return;
	}

	if (CurAni != &FrameAni[Name])
	{
		CurAni = &FrameAni[Name];
		CurAni->Reset();
	}

}

void GameEngineTextureRenderer::FrameDataReset()
{
	FrameData = { 0.0f , 0.0f, 1.0f, 1.0f };
}


void GameEngineTextureRenderer::Update(float _Delta)
{
	if (nullptr != CurAni)
	{
		CurAni->Update(_Delta);
	}
}