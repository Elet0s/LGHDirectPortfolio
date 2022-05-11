#pragma once
#include "GameEnginePath.h"

class GameEngineFile;
class GameEngineDirectory : public GameEnginePath //실직적으로 경로를 변경하기 위한 함수
{
public:

	GameEngineDirectory();
	GameEngineDirectory(const char* _Path);
	GameEngineDirectory(std::filesystem::path _Path);
	GameEngineDirectory(const GameEngineDirectory& _Other);
	~GameEngineDirectory();

	void MoveParent();

	void MoveParent(const std::string& _Name);

	bool MoveParentToExitsChildDirectory(const std::string& _Name);

	bool IsRoot();

	void Move(const std::string& _Name);

	std::vector<GameEngineFile> GetAllFile(const std::string& _Ext = "");

	std::vector<GameEngineDirectory> GetAllDirectory();

protected:


private:

};

