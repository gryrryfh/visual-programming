## 계산기

#include microsoft.ui.xaml.window.h
auto windowNative{this->try_as<::WindowNative>()};
HWND hWnd{0};
windowNative->get_WindowHandle(&hWnd);
SetWindowPos(hWnd, NULL, 300, 500, 250, 300, NULL);
this->Title(L"Calculator");

va=stod(a().Text().c_str());
vb=stod(b().Text().c_str());
vc=va+vb
c().Text(to_wstring(vc));

나올만한거 stod, to_wstring, windowNative


## Win2D

PointerMoved="CanvasControl_PointerMoved"
Draw="CanvasControl_Draw" ClearColor="CornflowerBlue
winrt/Microsoft.Graphics.Canvas.UI.Xaml.h
winrt/Microsoft.UI.Xaml.Input.h
winrt/Microsoft.UI.Input.h
CanvasControl=sender.as<CanvasControl>
px=e.GetCurrentPoint(canvas).Position().X;
py=E.GetCurrentPoint(canvas).Position().Y;
canvas.Invalidate();


args.DrawingSession().DrawEllipse(px, py, 80, 60, col, 8);
args.DrawingSession().DrawText( 내용, px, py, winrt::Microsoft::UI::Colors::Yellow());
