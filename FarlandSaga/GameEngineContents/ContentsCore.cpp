#include "PreCompile.h"
#include "ContentsCore.h"
#include "GameEngineContents/TitleLevel.h"
#include "GameEngineContents/Stage01.h"
#include"GameEngineContents/EndLevel.h"
#include <GameEngineBase/GameEngineSound.h>

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
		Dir.Move("Sound");
		Dir.Move("BGM");
		std::vector<GameEngineFile> Sound = Dir.GetAllFile();
		for (GameEngineFile& SoundPlay : Sound)
		{
			GameEngineSound::LoadRessource(SoundPlay);
		}
	}
	///////////////// �̹��� cut /////////////////

	GameEngineTexture::Cut("LeonWind.png", 3, 1);
	GameEngineTexture::Cut("LeonWalkU.png", 4, 1);
	GameEngineTexture::Cut("LeonWalkD.png", 4, 1);
	GameEngineTexture::Cut("LeonIdle.png", 6, 1);
	///////////////// RTTI �� Ÿ�� Ÿ�� �������̼�/////////////////
	if (false == GameEngineInput::GetInst()->IsKey("LevelChange"))
	{
		GameEngineInput::GetInst()->CreateKey("LevelChange", 'P');
	}

	CreateLevel<TitleLevel>("Title");
	CreateLevel<Stage01>("Stage01");
	CreateLevel<EndLevel>("Ending");
	ChangeLevel("Title");

	GameEngineGUI::CreateGUIWindow<GameEngineStatusWindow>("�ҷ��� ������ �����ϼ���", nullptr);
}

void ContentsCore::Update(float _DeltaTime)
{
	// ������ ����Ǿ���.
	// ������ ��� �޼���â�� �������Ѵ�.


}

void ContentsCore::End()
{
	int a = 0;
}