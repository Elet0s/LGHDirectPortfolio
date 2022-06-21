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

void GameEngineDebug::ConsoleOpen() /// �ܼ�â �߿�� �κ�
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

void GameEngineDebug::OutPutString(const std::string& _Text) /// �ܼ�â ��� ����
{
	OutputDebugStringA((_Text + "\n").c_str());
}

void GameEngineDebug::Destroy()//�ܼ�â �ݴ� ����
{
	if (nullptr != hConsole)
	{
		FreeConsole();
	}
}