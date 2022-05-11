#pragma once
#include <filesystem>

class GameEnginePath //폴더 경로를 관리하는 클래스
{
public:

	GameEnginePath();
	GameEnginePath(const std::filesystem::path& _Path);
	~GameEnginePath();

	GameEnginePath(const GameEnginePath& _Other) = delete;
	GameEnginePath(GameEnginePath&& _Other) noexcept = delete;
	GameEnginePath& operator=(const GameEnginePath& _Other) = delete;
	GameEnginePath& operator=(GameEnginePath&& _Other) noexcept = delete;

	void SetCurrentPath();

	bool IsExits();

	std::string GetExtension();

	std::string GetFileName();

	std::string GetFullPath();

protected:
	std::filesystem::path Path_;

private:
};

