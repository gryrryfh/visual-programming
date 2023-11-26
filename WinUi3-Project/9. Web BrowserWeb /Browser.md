## 실행결과
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/ea5d56e9-40b0-4560-9274-139413374b55)
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/f443e50f-20e6-4c2d-bc43-f5fbee424cf0)
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/b2ec11df-37aa-4e32-a11a-b1f3d5071775)

## 코드
```xaml
<?xml version="1.0" encoding="utf-8"?>
<Window
    x:Class="page9.MainWindow"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="using:page9"
    xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
    xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
    xmlns:controls="using:Microsoft.UI.Xaml.Controls" 
    mc:Ignorable="d">

    <Grid RequestedTheme="Default">
        <Grid.RowDefinitions>
            <RowDefinition Height="2*" />
            <RowDefinition Height="1*" />
            <RowDefinition Height="8*" />
        </Grid.RowDefinitions>
        <TextBox x:Name="url_text" Grid.Row="0" Header=" Enter url:"
             PlaceholderText="url" HorizontalAlignment="Stretch" VerticalAlignment="Stretch" FontSize="24" Margin="5, 5, 5, 5">
            <TextBox.ContextFlyout>
                <controls:MenuFlyout>
                    <MenuFlyoutItem Text="-paste" Icon=" Paste" Click="MenuFlyoutItem_Click">
                    </MenuFlyoutItem>
                </controls:MenuFlyout>
            </TextBox.ContextFlyout>
        </TextBox>
        <Button x:Name="get_button" Click="get_button_Click" Content="Get" Grid.Row="1" HorizontalAlignment="Stretch" VerticalAlignment="Stretch" FontSize="24" Margin="5, 5, 5, 5" />
        <controls:WebView2 x:Name="MyWebView" Grid.Row="2" Source="https://www.google.com" HorizontalAlignment="Stretch" VerticalAlignment="Stretch"/>
    </Grid>
    
</Window>

```
```c++
// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
using namespace winrt;
using namespace Microsoft::UI::Xaml;
namespace winrt::page9::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
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


void winrt::page9::implementation::MainWindow::MenuFlyoutItem_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
url_text().PasteFromClipboard();
}


void winrt::page9::implementation::MainWindow::get_button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    winrt::hstring sss = url_text().Text();
    try
    {
        if (sss.size() == 0)
        {
            MessageBox(NULL, L"오류", L"url을 입력하시오", MB_OK);
            return;
    } 
    winrt::Windows::Foundation::Uri uri(url_text().Text());
    MyWebView().Source(uri);
	}
	catch (winrt::hresult_error const& e)
	{
		winrt::hstring err = e.message();
        MessageBox(NULL, err.c_str(), L"오류", MB_OK);
	}
}

```
