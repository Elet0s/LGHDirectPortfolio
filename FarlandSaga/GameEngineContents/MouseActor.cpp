#include "PreCompile.h"
#include"MouseActor.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

MouseActor::MouseActor()
	:Renderer(nullptr),
	 ptMouse1(),
	ptMouse2(),
	ptMouse3(),
	Level(),
	MousePosition(),
	MX(0),
	MY(0),
	MZ(0),
	TileMap(),
	 OnUnit(false),
	 OnMon(false),
	MouseOnX(0),
	MouseOnY(0)
{

}
MouseActor::~MouseActor()
{
	
}

void MouseActor::SetTileRenderer(TileMapRenderer* _TileMapRenderer)
{
	TileMap = _TileMapRenderer;
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->GetTransform().SetLocalScale({ 64.0f, 32.0f, 0.0f });
}

void MouseActor::Start()
{
	MouseCol_ = CreateComponent<GameEngineCollision>();
	MouseCol_->GetTransform().SetLocalScale({ 16.0f, 20.0f , 0.0f });
	MouseCol_->ChangeOrder(OBJECTORDER::Mouse);

	if (false == GameEngineInput::GetInst()->IsKey("MouseLeft"))
	{
		GameEngineInput::GetInst()->CreateKey("MouseLeft", VK_LBUTTON);
	}
	if (false == GameEngineInput::GetInst()->IsKey("MouseLeft"))
	{
		GameEngineInput::GetInst()->CreateKey("MouseRight", VK_RBUTTON);
	}
}
void MouseActor::Update(float _DeltaTime)
{

	float4 MousePos = Level->GetMainCamera()->GetMouseWorldPositionToActor();
	MouseCol_->GetTransform().SetLocalPosition(MousePos);
	MX = roundf((MousePos.x / 32.0f + MousePos.y / -16.0f) / 2.0f);
	MY = roundf((MousePos.x / -32.0f + MousePos.y / -16.0f) / 2.0f);
	MouseOnX = static_cast<int>(MX);
	MouseOnY = static_cast<int>(MY);

	if (TileMap != nullptr)
	{
		if (MouseOnX >= 0 && MouseOnY >= 0 && MouseOnX + 1 <= TileMap->TileX && MouseOnY + 1 <= TileMap->TileY)
		{
			if (Renderer->IsUpdate() == false)
			{
				Renderer->On();
			}
			if (TileMap->Tiles[MouseOnY][MouseOnX].TileIndex == 64 || TileMap->Tiles[MouseOnY][MouseOnX].TileIndex == 63 || TileMap->Tiles[MouseOnY][MouseOnX].TileIndex == 62 || TileMap->Tiles[MouseOnY][MouseOnX].TileIndex == 61)
			{
				Renderer->Off();
			}
			if (TileMap->Tiles[MouseOnY][MouseOnX].IsMapObject == false)
			{
				MZ = TileMap->Tiles[MouseOnY][MouseOnX].Z;

				float XX = (MX * 32) + (MY * -32);
				float YY = (MX * -16) + (MY * -16) + (MZ * 16) - 16;

				Renderer->GetTransform().SetWorldPosition({ XX, YY,-(TileMap->Tiles[MouseOnY][MouseOnX].TileDepth + 0.5f),0.0f });
				if (MouseOnX + 1 == TileMap->TileX || MouseOnY + 1 == TileMap->TileY)
				{
					Renderer->SetTexture("ST01.png");
				}
				else if (TileMap->Tiles[MouseOnY][MouseOnX].Z + 2 <= TileMap->Tiles[MouseOnY + 1][MouseOnX + 1].Z)
				{
					Renderer->SetTexture("ST02.png");
				}
				else
				{
					Renderer->SetTexture("ST01.png");
				}


				if (TileMap->Tiles[MouseOnY][MouseOnX].IsUnit != PlayUnitGroup::None)
				{
					OnUnit = true;
					//HP,Mp, 상태이상 Ui On 해줘야함
				}
				else
				{
					OnUnit = false;
					//off

				}
				if (TileMap->Tiles[MouseOnY][MouseOnX].IsMon != MonUnitGroup::None)
				{

					//몬스터 정보 ui on
					OnMon = true;
				}
				else
				{
					//off
					OnMon = false;
				}
			}
			else if (TileMap->Tiles[MouseOnY][MouseOnX].IsMapObject == true)
			{
				Renderer->Off();
			}
			if (true == GameEngineInput::GetInst()->IsDown("MouseLeft"))
			{
				if (OnUnit == true)
				{
					TileMap->Tiles[MouseOnY][MouseOnX].ClickOnUint = true;
				}
				else if (OnMon == true)
				{
					TileMap->Tiles[MouseOnY][MouseOnX].ClickOnUint = true;
				}
			}
		}
		else
		{
			Renderer->Off();
		}
	}
	//////// 마우스드래그 이동하는 기능 ///////////
	if (Level->GetOrder() != 1)
	{

		if (OnUnit == false && OnMon == false)
		{
			if (true == GameEngineInput::GetInst()->IsDown("MouseLeft"))
			{
				GetCursorPos(&ptMouse1);
				ScreenToClient(GameEngineWindow::GetHWND(), &ptMouse1);
			}
			if (true == GameEngineInput::GetInst()->IsPress("MouseLeft"))
			{
				GetCursorPos(&ptMouse2);
				ScreenToClient(GameEngineWindow::GetHWND(), &ptMouse2);
			}
			ptMouse3.x = ptMouse2.x - ptMouse1.x;
			ptMouse3.y = ptMouse2.y - ptMouse1.y;

			if (ptMouse3.x > 0)
			{
				Level->GetMainCameraActorTransform().SetLocalMove(-Level->GetMainCameraActorTransform().GetRightVector() * static_cast<float>(ptMouse3.x));
				ptMouse3.x = 0;
				ptMouse1.x = ptMouse2.x;
			}
			else if (ptMouse3.x < 0)
			{
				Level->GetMainCameraActorTransform().SetLocalMove(Level->GetMainCameraActorTransform().GetRightVector() * static_cast<float>(-ptMouse3.x));
				ptMouse3.x = 0;
				ptMouse1.x = ptMouse2.x;
			}

			if (ptMouse3.y > 0)
			{
				Level->GetMainCameraActorTransform().SetLocalMove(Level->GetMainCameraActorTransform().GetUpVector() * static_cast<float>(ptMouse3.y));
				ptMouse3.y = 0;
				ptMouse1.y = ptMouse2.y;
			}
			else if (ptMouse3.y < 0)
			{
				Level->GetMainCameraActorTransform().SetLocalMove(-Level->GetMainCameraActorTransform().GetUpVector() * static_cast<float>(-ptMouse3.y));
				ptMouse3.y = 0;
				ptMouse1.y = ptMouse2.y;
			}
		}
	}
}
void MouseActor::End()
{

}