#pragma once
#include <GameEngineCore/GameEngineActor.h>

class MyDialogBox : public GameEngineActor
{
public:
	MyDialogBox();
	~MyDialogBox();

	MyDialogBox(const MyDialogBox& _Other) = delete;
	MyDialogBox(MyDialogBox&& _Other) noexcept = delete;
	MyDialogBox& operator=(const MyDialogBox& _Other) = delete;
	MyDialogBox& operator=(MyDialogBox&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

	GameEngineTextureRenderer* Renderer;
private:


};