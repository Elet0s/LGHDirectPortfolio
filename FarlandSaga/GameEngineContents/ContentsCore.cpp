#include "PreCompile.h"
#include "ContentsCore.h"
#include "GameEngineContents/TitleLevel.h"
#include "GameEngineContents/Stage01.h"

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
	
	GameEngineDirectory Dir;

	Dir.MoveParentToExitsChildDirectory("ConstantResources");
	Dir.Move("ConstantResources");
	Dir.Move("BMP");

	std::vector<GameEngineFile> Shaders = Dir.GetAllFile();

	for (size_t i = 0; i < Shaders.size(); i++)
	{
		GameEngineTexture::Load(Shaders[i].GetFullPath());
	}

	Dir.MoveParentToExitsChildDirectory("ConstantResources");
	Dir.Move("ConstantResources");
	Dir.Move("CUP");

	GameEngineFolderTexture::Load(Dir.GetFullPath());

	Dir.MoveParentToExitsChildDirectory("ConstantResources");
	Dir.Move("ConstantResources");
	Dir.Move("AN");

	GameEngineFolderTexture::Load(Dir.GetFullPath());

	///////////////// �̹��� cut /////////////////

	GameEngineTexture::Cut("LeonIdle.png", 3, 1);

	///////////////// RTTI �� Ÿ�� Ÿ�� �������̼�/////////////////
	CreateLevel<TitleLevel>("Title");
	CreateLevel<Stage01>("Stage01");
	ChangeLevel("Title");

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