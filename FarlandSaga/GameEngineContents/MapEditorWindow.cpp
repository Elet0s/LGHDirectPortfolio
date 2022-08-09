#include "PreCompile.h"
#include "MapEditorWindow.h"

MapEditorWindow::MapEditorWindow()
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
        Dir.Move("Texture");
        Dir.Move("Map");

        OPENFILENAME OFN;
        char filePathName[100] = "";
        char lpstrFile[100] = "";
        // static char filter[] = "모든 파일\0*.*\0텍스트 파일\0*.txt\0fbx 파일\0*.fbx";
        static char filter[] = "모든 폴더\0*.\0";

        std::string FullPath = Dir.GetFullPath();

        memset(&OFN, 0, sizeof(OPENFILENAME));
        OFN.lStructSize = sizeof(OPENFILENAME);
        OFN.hwndOwner = nullptr;
        OFN.lpstrFilter = filter;
        OFN.lpstrFile = lpstrFile;
        OFN.nMaxFile = 100;
        OFN.lpstrInitialDir = FullPath.c_str();
        OFN.Flags = OFN_EXPLORER;

        char PrevDir[256] = { 0 };
        GetCurrentDirectoryA(256, PrevDir);

        if (GetOpenFileName(&OFN) != 0) {
            SetCurrentDirectoryA(PrevDir);
        }

        int a = 0;
    }
}