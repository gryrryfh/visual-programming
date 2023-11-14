## xaml.h
```
        void Add_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void Subtract_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void Multiply_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void Divide_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
```
## cpp
```
using namespace std;
double va, vb, vc;
#include <microsoft.ui.xaml.window.h>
        auto windowNative{ this->try_as<::IWindowNative>() };
        HWND hwnd(0);
        windowNative->get_WindowHandle(&hwnd);
        SetWindowPos(hwnd, NULL, 300, 500, 250, 300, NULL);
        this->Title(L"Calculator");
    }
void winrt::App1::implementation::MainWindow::Add_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{va = stod(a().Text().c_str());
    vb = stod(b().Text().c_str());
    vc = va + vb;
    c().Text(to_wstring(vc));
}
void winrt::App1::implementation::MainWindow::Subtract_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    va = stod(a().Text().c_str());
    vb = stod(b().Text().c_str());
    vc = va - vb;
    c().Text(to_wstring(vc));
}
void winrt::App1::implementation::MainWindow::Multiply_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    va = stod(a().Text().c_str());
    vb = stod(b().Text().c_str());
    vc = va * vb;
    c().Text(to_wstring(vc));
}


void winrt::App1::implementation::MainWindow::Divide_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    va = stod(a().Text().c_str());
    vb = stod(b().Text().c_str());
    vc = va / vb;
    c().Text(to_wstring(vc));
}

```
## xaml
```

        <TextBox x:Name="a" Margin="10"/>
        <TextBox x:Name="b" Margin="10"/>

        <StackPanel Orientation="Horizontal">
            <Button x:Name="Add" Margin="10" Click="Add_Click">+</Button>
            <Button x:Name="Subtract" Margin="10" Click="Subtract_Click">-</Button>
            <Button x:Name="Multiply" Margin="10" Click="Multiply_Click">*</Button>
            <Button x:Name="Divide" Margin="10" Click="Divide_Click">/</Button>
        </StackPanel>
        
        <TextBox x:Name="c" Margin="10"/>
    </StackPanel>
</Window>

```
## xaml.cpp
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





namespace winrt::App5::implementation
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


void winrt::App5::implementation::MainWindow::CanvasControl_PointerMoved(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::PointerRoutedEventArgs const& e)
{
    CanvasControl canvas = sender.as<CanvasControl>();
px = e.GetCurrentPoint(canvas).Position().X; 
py = e.GetCurrentPoint(canvas).Position().Y;
canvas.Invalidate();

}


void winrt::App5::implementation::MainWindow::CanvasControl_Draw(winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl const& sender, winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs const& args)
{
args.DrawingSession().DrawEllipse(px, py, 100, 80, col, 8);
args.DrawingSession().DrawText(L"Hello", px-25, py-15, winrt::Microsoft::UI::Colors::Yellow());
}
```
### xaml.h
```cpp
// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "MainWindow.g.h"
#include <winrt/Microsoft.Graphics.Canvas.UI.Xaml.h>//Canvas를 사용하기 위해 추가
#include <winrt/Microsoft.UI.XAML.Input.h>
#include <winrt/Microsoft.UI.Input.h> //마우스 사용을 위해 추가  

namespace winrt::App5::implementation
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

namespace winrt::App5::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
```
### xaml
```xaml

    xmlns:canvas="using:Microsoft.Graphics.Canvas.UI.Xaml"
    <Grid>
        <canvas:CanvasControl PointerMoved="CanvasControl_PointerMoved"
                              Draw="CanvasControl_Draw"
                              ClearColor="CornflowerBlue"/>
    </Grid>
</Window>   
```
