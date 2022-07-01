#include "PreCompile.h"
#include "GameEngineShader.h"
#include "GameEngineVertexShader.h"
#include "GameEnginePixelShader.h"

void GameEngineShader::AutoCompile(const std::string& _Path)
{
	GameEngineFile File = GameEngineFile(_Path);
	File.Open(OpenMode::Read, FileMode::Text);

	std::string AllHlslCode = File.GetString();
	AllHlslCode.resize(File.GetFileSize());

	File.Read(&AllHlslCode[0], AllHlslCode.size(), AllHlslCode.size());

	size_t VSEntryIndex = AllHlslCode.find("_VS(");
	// 0123456789
	//"a Color_VS("
	// VSEntryIndex == 7
	if (std::string::npos != VSEntryIndex)
	{
		// size_t VSEntryIndex = AllHlslCode.find("_VS(");
		// 7부터 찾아라 앞쪽으로
		// 1
		size_t FirstIndex = AllHlslCode.find_last_of(" ", VSEntryIndex);
		// "01234567"
		// substr(2, 3); "234"

		// ' 'Color_VS 
		std::string EntryName = AllHlslCode.substr(FirstIndex + 1, VSEntryIndex - FirstIndex);
		EntryName += "_VS";
		GameEngineVertexShader::Load(_Path, EntryName);

		int a = 0;
		// GameEngineVertexShader::Load(_Path, );
	}

	size_t PSEntryIndex = AllHlslCode.find("_PS(");
	if (std::string::npos != PSEntryIndex)
	{
		AllHlslCode.find_last_of(" ", PSEntryIndex);

		int a = 0;
	}

	// File.GetFileSize();

}

GameEngineShader::GameEngineShader()
	: Version("")
{
}

GameEngineShader::~GameEngineShader()
{
}



void GameEngineShader::CreateVersion(const std::string& _ShaderType, UINT _VersionHigh, UINT _VersionLow)
{
	Version = "";
	Version += _ShaderType + "_"; // vs_
	Version += std::to_string(_VersionHigh); // vs_5
	Version += "_"; // vs_5_
	Version += std::to_string(_VersionLow); // vs_5_0
}