#include "PreCompile.h"
#include "ContentsCore.h"
#include "GameEngineContents/TitleLevel.h"
#include "GameEngineContents/Stage01.h"
#include "GameEngineContents/Stage02.h"
#include "GameEngineContents/Stage03.h"
#include "GameEngineContents/Event01.h"
#include "GameEngineContents/Event02.h"
#include "GameEngineContents/Event03.h"
#include"GameEngineContents/EndLevel.h"
#include <GameEngineBase/GameEngineSound.h>
#include "SoundPlayer.h"
#include "GameEngineContents/MapEditorLevel.h"

#pragma comment(lib, "GameEngineBase.lib")

ContentsCore::ContentsCore()
	: GameEngineCore()
{
}

ContentsCore::~ContentsCore()
{
}

void ContentsCore::Start()
{
	/////////////////���ҽ� �ҷ����� �κ�/////////////////
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("BG");
		std::vector<GameEngineFile> Shaders = Dir.GetAllFile();
		for (size_t i = 0; i < Shaders.size(); i++)
		{
			GameEngineTexture::Load(Shaders[i].GetFullPath());
		}
	}
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("PlayerUnit");
		Dir.Move("LEON");
		std::vector<GameEngineFile> Shaders = Dir.GetAllFile();
		for (size_t i = 0; i < Shaders.size(); i++)
		{
			GameEngineTexture::Load(Shaders[i].GetFullPath());
		}
	}
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		std::vector<GameEngineFile> Shaders = Dir.GetAllFile();
		for (size_t i = 0; i < Shaders.size(); i++)
		{
			GameEngineTexture::Load(Shaders[i].GetFullPath());
		}
	}
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Stage01");
		std::vector<GameEngineFile> Shaders = Dir.GetAllFile();
		for (size_t i = 0; i < Shaders.size(); i++)
		{
			GameEngineTexture::Load(Shaders[i].GetFullPath());
		}
	}
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("UI");
		std::vector<GameEngineFile> Shaders = Dir.GetAllFile();
		for (size_t i = 0; i < Shaders.size(); i++)
		{
			GameEngineTexture::Load(Shaders[i].GetFullPath());
		}
	}
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Face");
		std::vector<GameEngineFile> Shaders = Dir.GetAllFile();
		for (size_t i = 0; i < Shaders.size(); i++)
		{
			GameEngineTexture::Load(Shaders[i].GetFullPath());
		}
	}
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Sound");
		Dir.Move("BGM");
		std::vector<GameEngineFile> Sound = Dir.GetAllFile();
		for (GameEngineFile& SoundPlay : Sound)
		{
			GameEngineSound::LoadRessource(SoundPlay);
		}
	}
	///////////////// �̹��� cut /////////////////

	GameEngineTexture::Cut("LeonWalkU.png", 4, 1);
	GameEngineTexture::Cut("LeonWalkD.png", 4, 1);
	GameEngineTexture::Cut("LeonIdle.png", 6, 1);

	///////////////// ��Ʈ /////////////////
	GameEngineFont::Load("�޸հ��");

	///////////////// RTTI �� Ÿ�� Ÿ�� �������̼�/////////////////
	if (false == GameEngineInput::GetInst()->IsKey("NextLevel"))
	{
		GameEngineInput::GetInst()->CreateKey("NextLevel", 'P');
		GameEngineInput::GetInst()->CreateKey("MoveTitle", '1');
		GameEngineInput::GetInst()->CreateKey("MoveStage01", '2');
		GameEngineInput::GetInst()->CreateKey("MoveStage02", '3');
		GameEngineInput::GetInst()->CreateKey("MoveStage03", '4');
	}

	CreateLevel<TitleLevel>("Title");
	CreateLevel<Event01>("Event01");
	CreateLevel<Stage01>("Stage01");
	CreateLevel<Event02>("Event02");
	CreateLevel<Stage02>("Stage02");
	CreateLevel<Event03>("Event03");
	CreateLevel<Stage03>("Stage03");
	CreateLevel<EndLevel>("Ending");
	CreateLevel<MapEditorLevel>("MapEditor");
	ChangeLevel("MapEditor");

	//GameEngineGUI::CreateGUIWindow<GameEngineStatusWindow>("�ҷ��� ������ �����ϼ���", nullptr);
}

void ContentsCore::Update(float _DeltaTime)
{
	// ������ ����Ǿ���.
	// ������ ��� �޼���â�� �������Ѵ�.
	if (true == GameEngineInput::GetInst()->IsDown("MoveTitle"))
	{
		SoundPlayer::BGMPlay_->Stop();
		GEngine::ChangeLevel("Title");
	}
	if (true == GameEngineInput::GetInst()->IsDown("MoveStage01"))
	{
		SoundPlayer::BGMPlay_->Stop();
		GEngine::ChangeLevel("Stage01");
	}
	if (true == GameEngineInput::GetInst()->IsDown("MoveStage02"))
	{
		SoundPlayer::BGMPlay_->Stop();
		GEngine::ChangeLevel("Stage02");
	}
	if (true == GameEngineInput::GetInst()->IsDown("MoveStage03"))
	{
		SoundPlayer::BGMPlay_->Stop();
		GEngine::ChangeLevel("Stage03");
	}

}

void ContentsCore::End()
{
	SoundPlayer::BGMPlay_->Destory();
}