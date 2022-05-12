#pragma once
#include "GameEngineFile.h"

class GameEngineWriteFile : private GameEngineFile
{
public:
	GameEngineWriteFile();
	GameEngineWriteFile(const std::string& _Path);
	GameEngineWriteFile(std::filesystem::path _Path);
	GameEngineWriteFile(const GameEngineWriteFile& _Other);
	~GameEngineWriteFile();

	GameEngineWriteFile& operator=(const GameEngineWriteFile& _Other) = delete;
	GameEngineWriteFile& operator=(GameEngineWriteFile&& _Other) noexcept = delete;

protected:


private:
};

