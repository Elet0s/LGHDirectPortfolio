#include "PreCompile.h"
#include "MapEditorWindow.h"
#include "TileMapActor.h"

MapEditorWindow::MapEditorWindow()
    : Scale{ 30, 30 , 0}
    , ZScale{0}
    , SelectTile(-1)
    , ButtonCheaker(false)
    , LoadCheaker(false)
{
}

MapEditorWindow::~MapEditorWindow()
{
}


void MapEditorWindow::Initialize(class GameEngineLevel* _Level)
{
    if (false == GameEngineInput::GetInst()->IsKey("TileSet"))
    {
        GameEngineInput::GetInst()->CreateKey("TileSet", VK_LBUTTON);
    }

}

void MapEditorWindow::OnGUI(GameEngineLevel* _Level, float _DeltaTime)
{
    if (LoadCheaker == false)
    {
        // ImGui::PushID
        if (true == ImGui::Button("FolderTextureLoad"))
        {
            GameEngineDirectory Dir;
            Dir.MoveParentToExitsChildDirectory("ConstantResources");
            Dir.Move("ConstantResources");
            Dir.Move("Map");

            std::string Path = GameEngineGUI::OpenFolderDlg(GameEngineString::AnsiToUTF8Return("폴더 텍스처 로드"), Dir.GetFullPath());

            if (false == Path.empty())
            {
                SelectFolderTexture = GameEnginePath::GetFileName(Path);

                GameEngineFolderTexture::Load(Path.c_str());
            }
            LoadCheaker = true;
        }
    }



        if (false == SelectFolderTexture.empty())
        {

            ImGui::Text("LodingFolder ->");            ImGui::SameLine();
            ImGui::Text(SelectFolderTexture.c_str());
            ImGui::InputInt3("Scale", Scale);

            if (true == ImGui::Button("MapCreate"))
            {
                TileMap->TileRenderer->CreateIsometricTileMap(Scale[0], Scale[1], Scale[2], { 64, 32 }, SelectFolderTexture, 16);
                ButtonCheaker = true;
            }

        }
    
    if (ButtonCheaker == true)
    {

        if (!ImGui::CollapsingHeader("SetTile"))
            return;

        ImGui::InputInt("Change Z", ZScale);

        std::string SelectIndex = "Select Index = ";
        int X;
        int Y;
        int Z;

        TileMap->TileRenderer->GetTileIndex(_Level->GetMainCamera()->GetMouseWorldPositionToActor(), X, Y);//몇번째 타일인지

        TileMap->TileRenderer->SetZIndex(X, Y, Z);

        SelectIndex += "X." + std::to_string(X) + " ";
        SelectIndex += "Y." + std::to_string(Y) + " ";
        if (X >= 0 && Y >= 0)
        {
            SelectIndex += "Z." + std::to_string(Z);
        }

        ImGui::Text(SelectIndex.c_str());


        GameEngineFolderTexture* Texture = GameEngineFolderTexture::Find(SelectFolderTexture);

        if (nullptr != Texture)
        {
            ImGui::BeginChildFrame(ImGui::GetID("TileSelect"), { 90 * 5, 500 });

            for (size_t i = 15; i < Texture->GetTextureCount(); i++)
            {
                GameEngineTexture* TileImage = Texture->GetTexture(i);
                if (ImGui::ImageButton(reinterpret_cast<ImTextureID>(TileImage->CreateShaderResourceView()), { 64, 32 }))
                {
                    SelectTile = i;
                }

                if (0 != (i + 1) % 5)
                {
                    ImGui::SameLine();
                }
            }
            ImGui::EndChildFrame();
        }
       
        ImGui::SameLine();

        if (ButtonCheaker == true)
        {
            GameEngineFolderTexture* Texture = GameEngineFolderTexture::Find(SelectFolderTexture);

            if (nullptr != Texture)
            {
                ImGui::BeginChildFrame(ImGui::GetID("TileSelect2"), { 90 * 5, 500 });

                for (size_t i = 0; i < 15; i++)
                {
                    GameEngineTexture* TileImage = Texture->GetTexture(i);
                    if (ImGui::ImageButton(reinterpret_cast<ImTextureID>(TileImage->CreateShaderResourceView()), { 64, 32 }))
                    {
                        SelectTile = i;
                    }

                    if (0 != (i + 1) % 5)
                    {
                        ImGui::SameLine();
                    }
                }
                ImGui::EndChildFrame();
            }

        }
        if (true == GameEngineInput::GetInst()->IsDown("TileSet")
            && nullptr != Texture
            && -1 != SelectTile
            && SelectTile < Texture->GetTextureCount())
        {

            float4 MousePos = _Level->GetMainCamera()->GetMouseWorldPositionToActor();//현재 마우스 위치 가져오는 부분

            TileMap->TileRenderer->SetTileIndex(MousePos, SelectTile, ZScale[0]);
        }
    }

}
    // TileMap->TileRenderer->
