#include <Windows.h>

#pragma comment(lib, "GameEngineBase.lib")

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineSound.h>


int main()
{
	GameEngineDirectory Dir;

	if (false == Dir.MoveParentToExitsChildDirectory("Resources"))
	{
		MsgBoxAssert("경로를 찾지 못했습니다.");
		return 0;
	}


	while (true)
	{

	}

	return 0;
}