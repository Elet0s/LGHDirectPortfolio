#include "PreCompile.h"
#include "ContentsCore.h"
#include "GameEngineContents/TitleLevel.h"
#include "GameEngineContents/PlayLevel.h"

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

	GameEngineDirectory Dir;

	Dir.MoveParentToExitsChildDirectory("ConstantResources");
	Dir.Move("ConstantResources");
	Dir.Move("BMP");

	std::vector<GameEngineFile> Shaders = Dir.GetAllFile();

	for (size_t i = 0; i < Shaders.size(); i++)
	{
		GameEngineTexture::Load(Shaders[i].GetFullPath());
	}

	//Dir.MoveParentToExitsChildDirectory("ConstantResources");
	//Dir.Move("ConstantResources");
	//Dir.Move("Texture");
	//
	//std::vector<GameEngineFile> Shaders2 = Dir.GetAllFile();
	//
	//for (size_t i = 0; i < Shaders2.size(); i++)
	//{
	//	GameEngineTexture::Load(Shaders2[i].GetFullPath());
	//}

	// �̰� ����� �մϴ�.
	//GameEngineTexture::Cut("Boss_Left.bmp", 5, 7);



	// ���ҽ��� �ε��ϴµ�.

	// RTTI �� Ÿ�� Ÿ�� �������̼�
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	ChangeLevel("Title");

	// ���������� ����
	// �� ���ӿ��� Ÿ��Ʋȭ��
	//            ��������1
	//            ��������2
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