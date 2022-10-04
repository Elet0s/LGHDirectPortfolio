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
	 OnMon(false)
{

}
MouseActor::~MouseActor()
{
	
}

void MouseActor::SetTileRenderer(TileMapRenderer* _TileMapRenderer)
{
	TileMap = _TileMapRenderer;
}

void MouseActor::Start()
{
	if (false == GameEngineInput::GetInst()->IsKey("MouseLeft"))
	{
		GameEngineInput::GetInst()->CreateKey("MouseLeft", VK_LBUTTON);
	}
	if (false == GameEngineInput::GetInst()->IsKey("MouseLeft"))
	{
		GameEngineInput::GetInst()->CreateKey("MouseRight", VK_RBUTTON);
	}

	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->GetTransform().SetLocalScale({ 64.0f, 32.0f, 0.0f });
}
void MouseActor::Update(float _DeltaTime)
{
	{
		float4 MousePos = Level->GetMainCamera()->GetMouseWorldPositionToActor();
		MX = roundf((MousePos.x / 32.0f + MousePos.y / -16.0f) / 2.0f);
		MY = roundf((MousePos.x / -32.0f + MousePos.y/ -16.0f) / 2.0f);
		int XIndex = static_cast<int>(MX);
		int YIndex = static_cast<int>(MY);

		if (XIndex >= 0 && YIndex >= 0 && XIndex + 1 <= TileMap->TileX && YIndex + 1 <= TileMap->TileY)
		{
			if (TileMap->Tiles[YIndex][XIndex].IsMapObject == false)
			{
				MZ = TileMap->Tiles[YIndex][XIndex].Z;

				float XX = (MX * 32) + (MY * -32);
				float YY = (MX * -16) + (MY * -16) + (MZ * 16) - 16;
				Renderer->GetTransform().SetWorldPosition({ XX, YY,-99.0f,0.0f });
				 if (XIndex + 1 == TileMap->TileX || YIndex + 1 == TileMap->TileY)
				{
					Renderer->SetTexture("ST01.png");
				}
				else if (TileMap->Tiles[YIndex][XIndex].Z + 2 <= TileMap->Tiles[YIndex + 1][XIndex + 1].Z)
				{
					Renderer->SetTexture("ST02.png");
				}
				else
				{
					Renderer->SetTexture("ST01.png");
				}


				if (TileMap->Tiles[YIndex][XIndex].IsUnit != PlayUnitGroup::None)
				{
					//HP,Mp, 상태이상 Ui On 해줘야함
					TileMap->Tiles[YIndex][XIndex].MouseOnUint = true;
				}
				else 
				{
					TileMap->Tiles[YIndex][XIndex].MouseOnUint = false;
				}
				 if (TileMap->Tiles[YIndex][XIndex].IsMon != MonUnitGroup::None)
				{
					 TileMap->Tiles[YIndex][XIndex].MouseOnUint = true;
				} 
				 else
				 {
					 TileMap->Tiles[YIndex][XIndex].MouseOnUint = false;
				 }
			}
			else if (TileMap->Tiles[YIndex][XIndex].IsMapObject == true)
			{
				Renderer->SetTexture("ST00.png");
			}
		}
	}

	//////// 마우스드래그 이동하는 기능 ///////////
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
			//SetCursorPos(ptMouse1.x, ptMouse1.y);
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
void MouseActor::End()
{

}