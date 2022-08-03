#include "PreCompile.h"
#include "GameEngineFontRenderer.h"

GameEngineFontRenderer::GameEngineFontRenderer()
	: Font(nullptr)
	, FontSize(20.0f)
	, Color(float4::WHITE)
	, ScreenPostion(float4::ZERO)
{
}

GameEngineFontRenderer::~GameEngineFontRenderer()
{
}

void GameEngineFontRenderer::SetText(const std::string& _Text, const std::string& _Font)
{
	Text = _Text;
	Font = GameEngineFont::Find(_Font);
}

void GameEngineFontRenderer::Start()
{
	PushRendererToMainCamera();
}

// ������ ������������ �ʿ䰡 ������ �����
void GameEngineFontRenderer::Render(float _DeltaTime)
{
	// �̰Ŵ� ����Ÿ���� �ؾ߰ڳ׿�.
	if (nullptr == Font)
	{
		return;
	}

	// �̳༮�� ���ο��� �������� �ϴ����� ������.
	// ���� ȭ�鿡�ٰ� �׸��� �ȵ���?
	// ����Ÿ��
	// ���ڴ� �Ǵٸ� ����Ÿ�ٿ� �׸��̴ϴ�.

	Font->FontDraw(Text, FontSize, ScreenPostion, Color);
}