#pragma once
#include <GameEngineCore/CoreMinimal.h>

class GameEngineTextureRenderer;
class MyDialogBox : public GameEngineActor
{
public:
	MyDialogBox();
	~MyDialogBox();

	MyDialogBox(const MyDialogBox& _Other) = delete;
	MyDialogBox(MyDialogBox&& _Other) noexcept = delete;
	MyDialogBox& operator=(const MyDialogBox& _Other) = delete;
	MyDialogBox& operator=(MyDialogBox&& _Other) noexcept = delete;

	inline void SetDialogLevel(int _Level)
	{
		DialogLevel_ = _Level;
	}
	inline bool DialogEnd()
	{
		if (DialogEnd_ == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool DialogEnd_;
	int DialogLevel_;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

	GameEngineTextureRenderer* DialogBoxRenderer01;
	GameEngineTextureRenderer* DialogBoxRenderer02;
	GameEngineTextureRenderer* DialogFaceRenderer01;
	GameEngineTextureRenderer* DialogFaceRenderer02;
	GameEngineFontRenderer* DialogUpName;
	GameEngineFontRenderer* DialogDownName;
	GameEngineFontRenderer* DialogUpText01;
	GameEngineFontRenderer* DialogUpText02;
	GameEngineFontRenderer* DialogUpText03;
	GameEngineFontRenderer* DialogDownText01;
	GameEngineFontRenderer* DialogDownText02;
	GameEngineFontRenderer* DialogDownText03;


	int DialogStack_;

private:


};