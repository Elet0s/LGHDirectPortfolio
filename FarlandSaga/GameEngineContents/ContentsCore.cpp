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
#include <GameEngineBase/magic_enum.hpp>

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
	// string 최적화를 위한녀석.
	std::string_view Value = magic_enum::enum_name(OBJECTORDER::Player);
	std::string Name = Value.data();

	/////////////////쉐이더 불러오는 부분/////////////////

	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("GameEngineResources");
		Dir.Move("ContentsShaderResource");
		Dir.Move("Shader");

		std::vector<GameEngineFile> Shaders = Dir.GetAllFile("hlsl");

		for (size_t i = 0; i < Shaders.size(); i++)
		{
			GameEngineShader::AutoCompile(Shaders[i].GetFullPath());
		}
	}

	{
		GameEngineRenderingPipeLine* NewPipe = GameEngineRenderingPipeLine::Create("RGBAEffect");
		NewPipe->SetInputAssembler1VertexBuffer("FullRect");
		NewPipe->SetInputAssembler2IndexBuffer("FullRect");
		NewPipe->SetVertexShader("RGBAEffect.hlsl");
		NewPipe->SetPixelShader("RGBAEffect.hlsl");
	}

	/////////////////리소스 불러오는 부분/////////////////
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
		Dir.Move("MonUnit");
		Dir.Move("Goblin");
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

	///////////////// 이미지 cut /////////////////

	GameEngineTexture::Cut("LeonWalkU.png", 4, 1);
	GameEngineTexture::Cut("LeonWalkD.png", 4, 1);
	GameEngineTexture::Cut("LeonIdle.png", 6, 1);
	GameEngineTexture::Cut("GoblinIdle.png", 3, 1);
	
	///////////////// 폰트 /////////////////
	GameEngineFont::Load("휴먼고딕");

	///////////////// RTTI 런 타임 타입 인포메이션/////////////////
	if (false == GameEngineInput::GetInst()->IsKey("NextLevel"))
	{
		GameEngineInput::GetInst()->CreateKey("NextLevel", 'P');
	}
	GameEngineGUI::CreateGUIWindow<GameEngineStatusWindow>("GameManager", nullptr);
	CreateLevel<MapEditorLevel>("MapEditor");

	CreateLevel<TitleLevel>("Title");
	CreateLevel<Event01>("Event01");
	CreateLevel<Stage01>("Stage01");
	CreateLevel<Event02>("Event02");
	CreateLevel<Stage02>("Stage02");
	CreateLevel<Event03>("Event03");
	CreateLevel<Stage03>("Stage03");
	CreateLevel<EndLevel>("Ending");
	ChangeLevel("Title");




}

void ContentsCore::Update(float _DeltaTime)
{
	// 서버가 종료되었어.
	// 무조건 경고 메세지창을 띄워줘야한다.
}

void ContentsCore::End()
{
	SoundPlayer::BGMPlay_->Destory();
}