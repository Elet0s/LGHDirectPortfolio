#pragma once
#include "GameEnginePath.h"

enum class OpenMode
{
	Read,
	Write,
};

class GameEngineFile : public GameEnginePath //파일경로를 이용해 파일을 관리하는 클래스
{
public:

	GameEngineFile();
	GameEngineFile(const char* _Path);
	GameEngineFile(std::filesystem::path _Path);
	GameEngineFile(const GameEngineFile& _Other);
	~GameEngineFile();

	void Open(OpenMode _Mode);

	void ReadOpen()
	{
		Open(OpenMode::Read);
	}

	void WriteOpen()
	{
		Open(OpenMode::Write);
	}

	void Close();

	void Create()
	{
		Open(OpenMode::Write);
		Close();
	}

protected:


private:
	FILE* FilePtr;
};

