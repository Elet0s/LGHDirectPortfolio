#include "PreCompile.h"
#include "MapEditorWindow.h"
#include "TileMapActor.h"

MapEditorWindow::MapEditorWindow()
    : Scale{ 30, 30 }
{
}

MapEditorWindow::~MapEditorWindow()
{
}


void MapEditorWindow::Initialize(class GameEngineLevel* _Level)
{

}


void MapEditorWindow::OnGUI(GameEngineLevel* _Level, float _DeltaTime)
{
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
    }

    if (false == SelectFolderTexture.empty())
    {
        ImGui::SameLine();
        ImGui::Text(SelectFolderTexture.c_str());
        ImGui::InputInt2("Scale", Scale);

        if (true == ImGui::Button("MapCreate"))
        {
            TileMap->TileRenderer->CreateIsometricTileMap(Scale[0], Scale[1], { 64, 32 }, SelectFolderTexture, 32);
        }
    }


}