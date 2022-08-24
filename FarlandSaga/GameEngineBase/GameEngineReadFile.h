#pragma once
#include "GameEngineFile.h"

class GameEngineReadFile : private GameEngineFile
{
private:
	GameEngineReadFile();
	GameEngineReadFile(const std::string& _Path);
	GameEngineReadFile(std::filesystem::path _Path);
	GameEngineReadFile(const GameEngineReadFile& _Other);
	~GameEngineReadFile();

	GameEngineReadFile& operator=(const GameEngineReadFile& _Other) = delete;
	GameEngineReadFile& operator=(GameEngineReadFile&& _Other) noexcept = delete;
};