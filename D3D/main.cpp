#include "Engine.h"
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"DirectXTK.lib")

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		ErrorLogger::Log(hr, "Failed to call CoInitialize.");
		return -1;
	}

	Engine engine;
	engine.Initialize(hInstance, "WYTEngine", "MyWindowClass", 1600u, 900u);
	while (engine.ProcessMessages() == true)
	{
		engine.Update();
		engine.RenderFrame();
	}

	return 0;
}


//INPUT ASSEMBLER - COMPLETED
//VERTEX SHADER - COMPLETED
//RASTERIZER
//PIXEL SHADER
//OUTPUT MERGER