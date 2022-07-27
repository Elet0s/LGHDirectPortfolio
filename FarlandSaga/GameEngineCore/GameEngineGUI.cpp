#include "PreCompile.h"
#include "GameEngineGUI.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GameEngineDevice.h"

std::list<GameEngineGUIWindow*> GameEngineGUI::Windows;

GameEngineGUI::GameEngineGUI()
{
}

GameEngineGUI::~GameEngineGUI()
{
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
//imgui에서 윈도우메세지가 왔을때의 처리는 있지만 넘겨주는 것은 내window에서 직접해줘야 함

void GameEngineGUI::Initialize()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
    ImGui::StyleColorsDark();
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    GameEngineDirectory Dir;

    Dir.MoveParentToExitsChildDirectory("GameEngineResources");
    Dir.Move("GameEngineResources");
    Dir.Move("Font");


    io.Fonts->AddFontFromFileTTF(Dir.PlusFilePath("malgun.ttf").c_str(), 18.0f, NULL, io.Fonts->GetGlyphRangesKorean());


    ImGui_ImplWin32_Init(GameEngineWindow::GetHWND());
    ImGui_ImplDX11_Init(GameEngineDevice::GetDevice(), GameEngineDevice::GetContext());

    GameEngineWindow::GetInst()->SetMessageCallBack(ImGui_ImplWin32_WndProcHandler);
}
void GameEngineGUI::GUIRender(GameEngineLevel* _Level, float _DeltaTime)
{
    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();


    for (GameEngineGUIWindow* GUIWIndow : Windows)
    {
        if (false == GUIWIndow->IsOpen)
        {
            continue;
        }
        GUIWIndow->Begin();
        GUIWIndow->OnGUI(_Level, _DeltaTime);
        GUIWIndow->End();
    }

    // 여기사이에
    
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
    }
}
void GameEngineGUI::GUIDestroy()
{
    for (GameEngineGUIWindow* GUIWIndow : Windows)
    {
        delete GUIWIndow;
    }

    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
}