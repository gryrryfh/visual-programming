## 실행환경
Visual Studio 2022 WinUi3 C++
## 내용
파란 배경에 입력한 내용이 점점 커지는 노란색 글자배너

## 코드
프로그램명 : App1
xaml.cpp
``` c++
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

#include <winrt/Microsoft.Graphics.Canvas.Text.h>
using namespace winrt::Microsoft::Graphics::Canvas::Text;
float a1, a2 = 250;
float fontSize = 242.0f;

void winrt::App1::implementation::MainWindow::CanvasControl_Draw(winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl const& sender, winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs const& args)
{
    CanvasTextFormat format;
    CanvasControl canvas = sender.as<CanvasControl>();
    format.HorizontalAlignment(CanvasHorizontalAlignment::Center);
    format.VerticalAlignment(CanvasVerticalAlignment::Center);
    format.FontSize(fontSize);

    a1 += 5.0;
    fontSize += 1.0f;

    if (a1 > 1800) {
        a1 = 0;
        fontSize = 100.0f;
    }

    //args.DrawingSession().DrawEllipse(px, py, 180, 160, winrt::Microsoft::UI::Colors::Green(), 16);
    args.DrawingSession().DrawText(L"ANU", a1, a2, winrt::Microsoft::UI::Colors::Yellow(), format);

    canvas.Invalidate();
}
```
xaml.h
``` xaml.h
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
xaml
``` xaml
<?xml version="1.0" encoding="utf-8"?>
<Window
    x:Class="App1.MainWindow"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="using:App1"
    xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
    xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
    xmlns:canvas="using:Microsoft.Graphics.Canvas.UI.Xaml"
    mc:Ignorable="d">
    <Grid>
        <canvas:CanvasControl PointerMoved="CanvasControl_PointerMoved"
                              Draw="CanvasControl_Draw"
                              ClearColor="CornflowerBlue"/>
    </Grid>
</Window>   
```
## 실행결과


https://github.com/gryrryfh/visual-programming/assets/50912987/d17dcdfb-30a9-42f1-9735-8f7681681020


