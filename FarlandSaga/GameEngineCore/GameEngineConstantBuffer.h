#pragma once
#include <string>
#include <list>
#include <map>
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineBase/GameEngineNameObject.h>

class GameEngineConstantBuffer : public GameEngineNameObject
{
private:

public:
	static GameEngineConstantBuffer* Find(const std::string& _Name, int _ByteSize)
	{
		std::string UpperName = GameEngineString::ToUpperReturn(_Name);

		std::map<std::string, std::map<int, GameEngineConstantBuffer*>>::iterator NameIter = NamedRes.find(UpperName);

		if (NamedRes.end() == NameIter)
		{
			return nullptr;
		}

		std::map<int, GameEngineConstantBuffer*>& SizeMap = NameIter->second;

		std::map<int, GameEngineConstantBuffer*>::iterator SizeIter = SizeMap.find(_ByteSize);

		if (SizeIter == SizeMap.end())
		{
			return nullptr;
		}

		return SizeIter->second;
	}

	static GameEngineConstantBuffer* Create(
		const std::string& _Name,
		D3D11_SHADER_BUFFER_DESC _Desc,
		ID3D11ShaderReflectionConstantBuffer* _CBufferPtr
	)
	{
		GameEngineConstantBuffer* NewBuffer = CreateResName(_Name, _Desc.Size);

		return NewBuffer;
	}

	//static void ResourcesDestroy()
	//{
	//	for (auto& Res : UnNamedRes)
	//	{
	//		delete Res;
	//	}

	//	for (auto& Res : NamedRes)
	//	{
	//		delete Res.second;
	//	}
	//}

protected:
	//              이름                바이트 사이즈

	// 상수버퍼에 이름이 없으면 
	static GameEngineConstantBuffer* CreateRes(const std::string& _Name)
	{

		GameEngineConstantBuffer* NewRes = new GameEngineConstantBuffer();
		NewRes->SetName(_Name);

		return NewRes;
	}

	static GameEngineConstantBuffer* CreateResName(const std::string& _Name, int _ByteSize)
	{
		std::string Name = GameEngineString::ToUpperReturn(_Name);

		GameEngineConstantBuffer* FindBuffer = Find(_Name, _ByteSize);

		if (nullptr != FindBuffer)
		{
			return FindBuffer;
		}
		GameEngineConstantBuffer* Res = CreateRes(Name);

		// std::map<int, GameEngineConstantBuffer*> NamedRes[Name].find();

		// std::map<std::string, std::map<int, GameEngineConstantBuffer*>>::iterator SizeIter = NamedRes.find(Name);

		// SizeIter->second.find(_ByteSize);


		return Res;
	}

	//static ResType* CreateResUnName()
	//{
	//	ResType* Res = CreateRes();
	//	UnNamedRes.push_back(Res);
	//	return Res;
	//}

private:
	static std::map<std::string, std::map<int, GameEngineConstantBuffer*>> NamedRes;


public:
	D3D11_SHADER_BUFFER_DESC Desc;

	GameEngineConstantBuffer();
	~GameEngineConstantBuffer();

	GameEngineConstantBuffer(const GameEngineConstantBuffer& _Other) = delete;
	GameEngineConstantBuffer(GameEngineConstantBuffer&& _Other) noexcept = delete;
	GameEngineConstantBuffer& operator=(const GameEngineConstantBuffer& _Other) = delete;
	GameEngineConstantBuffer& operator=(GameEngineConstantBuffer&& _Other) noexcept = delete;

protected:

private:
};

