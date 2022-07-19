#pragma once
#include <filesystem>

class GameEnginePath
{

public:
	static std::string GetExtension(const std::string& _Path);
	static std::string GetFileName(const std::string& _Path);

	GameEnginePath();
	GameEnginePath(const std::filesystem::path& _Path);
	~GameEnginePath();

	GameEnginePath(const GameEnginePath& _Other) = delete;
	GameEnginePath(GameEnginePath&& _Other) noexcept = delete;
	GameEnginePath& operator=(const GameEnginePath& _Other) = delete;
	GameEnginePath& operator=(GameEnginePath&& _Other) noexcept = delete;

	void SetCurrentPath();

	bool IsExits();

	std::string GetExtension() const;

	std::string GetFileName() const;

	std::string GetFullPath() const;


protected:
	std::filesystem::path Path_;

private:
};

