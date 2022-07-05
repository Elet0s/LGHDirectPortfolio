#pragma once
#include <string>
#include <map>

class ConstantBuffer
{

};

class GameEngineShader
{
public:
	static void AutoCompile(const std::string& _Path);

public:
	GameEngineShader();
	~GameEngineShader();

	GameEngineShader(const GameEngineShader& _Other) = delete;
	GameEngineShader(GameEngineShader&& _Other) noexcept = delete;
	GameEngineShader& operator=(const GameEngineShader& _Other) = delete;
	GameEngineShader& operator=(GameEngineShader&& _Other) noexcept = delete;



protected:
	void CreateVersion(const std::string& _ShaderType, UINT _VersionHigh, UINT _VersionLow);
	void SetEntryPoint(const std::string& _EntryPoint)
	{
		EntryPoint = _EntryPoint;
	}
	ID3DBlob* BinaryPtr;

	std::string Version;

	void ShaderResCheak();

private:
	std::string EntryPoint;
	std::map<unsigned int, ConstantBuffer> ShaderMap;
};

