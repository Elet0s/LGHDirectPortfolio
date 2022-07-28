#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineTextureRenderer;
class Flower : public GameEngineActor
{
public:
	Flower();
	~Flower();


	Flower(const Flower& _Other) = delete;
	Flower(Flower&& _Other) noexcept = delete;
	Flower& operator=(const Flower& _Other) = delete;
	Flower& operator=(Flower&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

	GameEngineTextureRenderer* Renderer;

private:

};