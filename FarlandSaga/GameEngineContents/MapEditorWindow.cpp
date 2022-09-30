#include "PreCompile.h"
#include "MapEditorWindow.h"
#include "TileMapActor.h"

MapEditorWindow::MapEditorWindow()
    : Scale{ 30, 30 , 0}
    , ZScale{0}
    , SelectTile(-1)
    , ButtonCheaker(false)
    , LoadCheaker(false)
    ,MapObjectSet(false)
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
    if (LoadCheaker == false)//텍스처 로드
    {
        if (true == ImGui::Button("FolderTextureLoad"))
        {
            GameEngineDirectory TextureDir;
            TextureDir.MoveParentToExitsChildDirectory("ConstantResources");
            TextureDir.Move("ConstantResources");
            TextureDir.Move("Map");

            std::string Path = GameEngineGUI::OpenFolderDlg(GameEngineString::AnsiToUTF8Return("폴더 텍스처 로드"), TextureDir.GetFullPath());

            if (false == Path.empty())
            {
                SelectFolderTexture = GameEnginePath::GetFileName(Path);

                //GameEngineFolderTexture::Load(Path.c_str());
            }
            LoadCheaker = true;
        }
    }

    if (false == SelectFolderTexture.empty())
    {

        ImGui::Text("LodingFolder ->");
        ImGui::SameLine();
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
        int Index;
        TileMap->TileRenderer->GetTileIndex(_Level->GetMainCamera()->GetMouseWorldPositionToActor(), X, Y);//몇번째 타일인지
        TileMap->TileRenderer->SetZIndex(X, Y, Z, Index);
        SelectIndex += "X." + std::to_string(X) + " ";
        SelectIndex += "Y." + std::to_string(Y) + " ";
        if (X >= 0 && Y >= 0)
        {
            SelectIndex += "Z." + std::to_string(Z) + " ";
            SelectIndex += "Index." + std::to_string(Index);
        }
        ImGui::Text(SelectIndex.c_str());



        GameEngineFolderTexture* Texture = GameEngineFolderTexture::Find(SelectFolderTexture);
        if (nullptr != Texture)
        {
            ImGui::BeginChildFrame(ImGui::GetID("TileSelect"), { 90 * 5, 500 });
            for (size_t i = 15; i < 65; i++)
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

            if (nullptr != Texture)
            {
                ImGui::BeginChildFrame(ImGui::GetID("TileSelect2"), { 90 * 5, 500 });
                for (size_t i = 0; i < 15; i++)
                {
                    GameEngineTexture* Ztile = Texture->GetTexture(i);
                    if (ImGui::ImageButton(reinterpret_cast<ImTextureID>(Ztile->CreateShaderResourceView()), { 64, 32 }))
                    {
                        SelectZTile = i;
                    }
                    if (0 != (i + 1) % 5)
                    {
                        ImGui::SameLine();
                    }
                }
                ImGui::EndChildFrame();
            }

        if (nullptr != Texture)
        {
            ImGui::BeginChildFrame(ImGui::GetID("ObjectSelect3"), { 90 * 5, 500 });
            for (size_t i = 65; i < 93; i++)
            {
                GameEngineTexture* Ztile = Texture->GetTexture(i);
                if (ImGui::ImageButton(reinterpret_cast<ImTextureID>(Ztile->CreateShaderResourceView()), { 64, 32 }))
                {
                    SelectOTile = i;
                }
                if (0 != (i + 1) % 5)
                {
                    ImGui::SameLine();
                }
            }
            ImGui::EndChildFrame();
        }

        if (true == GameEngineInput::GetInst()->IsDown("TileSet") // 선택한 설정으로 타일 설정
            && nullptr != Texture
            && -1 != SelectTile
            && SelectTile < Texture->GetTextureCount())
        {
            float4 MousePos = _Level->GetMainCamera()->GetMouseWorldPositionToActor();//현재 마우스 위치 가져오는 부분
            TileMap->TileRenderer->SetTileIndex(MousePos, SelectTile, ZScale[0], SelectZTile , SelectOTile);
        }
        if (true == ImGui::Button("Save"))
        {
            GameEngineDirectory Dir;
            Dir.MoveParentToExitsChildDirectory("ConstantResources");
            Dir.Move("ConstantResources");
            Dir.Move("Data");

            GameEngineFile SaveFile = (Dir.GetFullPath() + "\\" + SelectFolderTexture + ".MapData").c_str();
            SaveFile.Open(OpenMode::Write, FileMode::Binary);

            int Size = static_cast<int>(TileMap->TileRenderer->Tiles.size());
            SaveFile.Write(&Size, sizeof(int));

            for (size_t y = 0; y < TileMap->TileRenderer->Tiles.size(); y++)
            {
                int XSize = static_cast<int>(TileMap->TileRenderer->Tiles[y].size());
                SaveFile.Write(&XSize, sizeof(int));

                for (size_t x = 0; x < TileMap->TileRenderer->Tiles[y].size(); x++)
                {
                    int  Tileindex = TileMap->TileRenderer->Tiles[y][x].TileIndex;
                    SaveFile.Write(&Tileindex, sizeof(int));
                    int TileZ = TileMap->TileRenderer->Tiles[y][x].Z;
                    SaveFile.Write(&TileZ, sizeof(int));
                    int TileZindex = TileMap->TileRenderer->Tiles[y][x].Zindex;
                    SaveFile.Write(&TileZindex, sizeof(int));
                    int TileOindex = TileMap->TileRenderer->Tiles[y][x].Oindex;
                    SaveFile.Write(&TileOindex, sizeof(int));
                    //  int TileDepth = TileMap->TileRenderer->Tiles[y][x].TileDepth;
                    //  SaveFile.Write(&TileDepth, sizeof(int));
                }
            }
        }
        if (true == ImGui::Button("Load"))
        {
            GameEngineDirectory Dir;
            Dir.MoveParentToExitsChildDirectory("ConstantResources");
            Dir.Move("ConstantResources");
            Dir.Move("Data");

            GameEngineFile LoadFile = (Dir.GetFullPath() + "\\" + SelectFolderTexture + ".MapData").c_str();
            LoadFile.Open(OpenMode::Read, FileMode::Binary);

            int Size = 0;
            LoadFile.Read(&Size, sizeof(int), sizeof(int));

            for (size_t y = 0; y < Size; y++)
            {
                int XSize = 0;
                LoadFile.Read(&XSize, sizeof(int), sizeof(int));

                for (size_t x = 0; x < XSize; x++)
                {
                    int Tileindex = TileMap->TileRenderer->Tiles[y][x].TileIndex;
                    LoadFile.Read(&Tileindex, sizeof(int), sizeof(int));
                    //  TileMap->TileRenderer->Tiles[y][x].TileIndex = Tileindex;

                    int TileZ = TileMap->TileRenderer->Tiles[y][x].Z;
                    LoadFile.Read(&TileZ, sizeof(int), sizeof(int));
                    //   TileMap->TileRenderer->Tiles[y][x].Z = TileZ; 

                    int TileZindex = TileMap->TileRenderer->Tiles[y][x].Zindex;
                    LoadFile.Read(&TileZindex, sizeof(int), sizeof(int));

                    int TileOindex = TileMap->TileRenderer->Tiles[y][x].Zindex;
                    LoadFile.Read(&TileZindex, sizeof(int), sizeof(int));

                    TileMap->TileRenderer->LoadTileIndex(static_cast<int>(y), static_cast<int>(x), Tileindex, TileZ, TileZindex, TileOindex);

                    //     int TileDepth = TileMap->TileRenderer->Tiles[y][x].TileDepth;
                    //     LoadFile.Read(&Tileindex, sizeof(int), sizeof(int));
                    //     TileMap->TileRenderer->Tiles[y][x].TileDepth = TileDepth;

                }

            }
        }
    }
}