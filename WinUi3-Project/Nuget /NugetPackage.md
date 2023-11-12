## 실행결과
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/5c9084ac-e025-4e4c-bf5e-76362687d73d)
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/d62dd90d-cbfe-4e35-b651-15c16f8edfb3)

## 코드
### xaml.cpp
```cpp
// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.
using namespace winrt::Microsoft::Graphics::Canvas::UI::Xaml;

struct winrt::Windows::UI::Color col = winrt::Microsoft::UI::Colors::Green();





namespace winrt::App1::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        px = 200;
        py = 200;
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }


}


void winrt::App1::implementation::MainWindow::CanvasControl_PointerMoved(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::PointerRoutedEventArgs const& e)
{
    CanvasControl canvas = sender.as<CanvasControl>();
    px = e.GetCurrentPoint(canvas).Position().X;
    py = e.GetCurrentPoint(canvas).Position().Y;
    canvas.Invalidate();

}


void winrt::App1::implementation::MainWindow::CanvasControl_Draw(winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl const& sender, winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs const& args)
{
    args.DrawingSession().DrawEllipse(px, py, 80, 60, col, 8);
    args.DrawingSession().DrawLine(300, 300, 500, 200, col, 5);
    args.DrawingSession().DrawCircle(150, 150, 100, col, 5);
    args.DrawingSession().DrawRectangle(100, 400, 200, 100, col, 5);
    args.DrawingSession().DrawRoundedRectangle(400, 500, 100, 200, 20, 20, col, 5);
    args.DrawingSession().DrawText(L"Hello World", 100, 100, col);

}
```
## xaml.h
```xaml
// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "MainWindow.g.h"
#include <winrt/Microsoft.Graphics.Canvas.UI.Xaml.h>//Canvas를 사용하기 위해 추가
#include <winrt/Microsoft.UI.XAML.Input.h>
#include <winrt/Microsoft.UI.Input.h> //마우스 사용을 위해 추가  

namespace winrt::App1::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        int32_t MyProperty();
        void MyProperty(int32_t value);
        float px, py;

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void CanvasControl_PointerMoved(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::PointerRoutedEventArgs const& e);
        void CanvasControl_Draw(winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl const& sender, winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs const& args);
    };
}

namespace winrt::App1::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
```
