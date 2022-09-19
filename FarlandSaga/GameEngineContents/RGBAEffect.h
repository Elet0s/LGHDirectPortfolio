#pragma once
#include <GameEngineCore\GameEngineRenderTarget.h>
#include <GameEngineCore\GameEngineRenderSet.h>

class RGBAEffect : public GameEnginePostEffect
{
private:
	RGBAEffect();
	~RGBAEffect();

	RGBAEffect(const RGBAEffect& _Other) = delete;
	RGBAEffect(RGBAEffect&& _Other) noexcept = delete;
	RGBAEffect& operator=(const RGBAEffect& _Other) = delete;
	RGBAEffect& operator=(RGBAEffect&& _Other) noexcept = delete;

	GameEngineRenderTarget* CopyTarget;
protected:
	void EffectInit() override;
	void Effect(GameEngineRenderTarget* _Render) override;

	RenderOption Option;

private:
	GameEngineRenderSet EffectSet;

};