#include "PreCompile.h"
#include "GameEngineDebug.h"
#include<iostream>
HANDLE  GameEngineDebug::hConsole = nullptr;

GameEngineDebug::GameEngineDebug()
{
}

GameEngineDebug::~GameEngineDebug()
{
}

void GameEngineDebug::LeakCheckOn()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
}

void GameEngineDebug::ConsoleOpen() /// 콘솔창 뜨우는 부분
{
	if (AllocConsole())
	{
		FILE* File;
		freopen_s(&File, "CONIN$", "rb", stdin);
		freopen_s(&File, "CONOUT$", "wb", stdout);
		freopen_s(&File, "CONOUT$", "wb", stderr);

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout << "Console Start" << std::endl;
	}
}

void GameEngineDebug::OutPutString(const std::string& _Text) /// 콘솔창 출력 구문
{
	OutputDebugStringA((_Text + "\n").c_str());
}

void GameEngineDebug::Destroy()//콘솔창 닫는 구문
{
	if (nullptr != hConsole)
	{
		FreeConsole();
	}
}