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


	/////////////////리소스 불러오는 부분/////////////////
	
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

	///////////////// 이미지 cut /////////////////

	GameEngineTexture::Cut("LeonIdle.png", 3, 1);

	///////////////// RTTI 런 타임 타입 인포메이션/////////////////
	CreateLevel<TitleLevel>("Title");
	CreateLevel<Stage01>("Stage01");
	ChangeLevel("Title");

}

void ContentsCore::Update(float _DeltaTime)
{
	// 서버가 종료되었어.
	// 무조건 경고 메세지창을 띄워줘야한다.


}

void ContentsCore::End()
{
	int a = 0;
}