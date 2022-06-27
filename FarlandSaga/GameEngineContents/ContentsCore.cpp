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
	// GameEngineDebug::ConsoleOpen();

	// 리소스를 로드하는데.

	// RTTI 런 타임 타입 인포메이션
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	ChangeLevel("Play");

	// 게임컨텐츠 정의
	// 이 게임에는 타이틀화면
	//            스테이지1
	//            스테이지2
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