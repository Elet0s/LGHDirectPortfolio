#pragma once
#include <crtdbg.h>
#include <string>
#include <assert.h>
#include <Windows.h>

class GameEngineDebug
{
public:
	static void LeakCheckOn();

	//  전역 쓸때 const & 오류 메세지 띄우주는 함수니까 const &! 
	// static void MsgBoxAssert(const std::string& _Text);

protected:

private:

	GameEngineDebug();
	~GameEngineDebug();

	GameEngineDebug(const GameEngineDebug& _Other) = delete;
	GameEngineDebug(GameEngineDebug&& _Other) noexcept = delete;
	GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
	GameEngineDebug& operator=(GameEngineDebug&& _Other) noexcept = delete;

};

#define MsgBoxAssert(Text) 	MessageBeep(0); \
MessageBoxA(nullptr, Text, "Error", MB_OK); \
assert(false); 

#define MsgBoxAssertString(Text) 	MessageBeep(0); \
MessageBoxA(nullptr, (Text).c_str(), "Error", MB_OK); \
assert(false); 
