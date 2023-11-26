## 실행결과
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/2423f74f-89ac-4062-96fc-a334f71022eb)
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/469d2634-f3be-4b3b-b1d5-723e521f054f)
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/1d39a59c-b02f-4579-b119-9c82ed60110b)

## 코드
```xaml
<?xml version="1.0" encoding="utf-8"?>
<Window
    x:Class="page7.MainWindow"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="using:page7"
    xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
    xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
    mc:Ignorable="d">
    <Grid>
        <Grid.RowDefinitions>
            <RowDefinition Height="40"/>
            <RowDefinition Height="60"/>
        </Grid.RowDefinitions>
        <Grid.ColumnDefinitions>
            <ColumnDefinition Width="Auto"/>
        </Grid.ColumnDefinitions>
        
        <Grid Grid.Row="0" Background="Gainsboro" CornerRadius="10">
            <MenuBar>
        <MenuBarItem Title="File">
                    <MenuFlyoutItem Text="Save" Click="MenuFlyoutItem_Click" Icon="Save">
                        <MenuFlyoutItem.KeyboardAccelerators>
                            <KeyboardAccelerator Key="S" Modifiers="Control"/>
                        </MenuFlyoutItem.KeyboardAccelerators>
                    </MenuFlyoutItem>
                    <MenuFlyoutItem Text="Open" Click="MenuFlyoutItem_Click_1" Icon="Page">
                        <MenuFlyoutItem.KeyboardAccelerators>
                            <KeyboardAccelerator Key="O" Modifiers="Control"/>
                        </MenuFlyoutItem.KeyboardAccelerators>
                    </MenuFlyoutItem>
                    <MenuFlyoutSubItem Text="New"  Icon="Add">
                        <MenuFlyoutItem Text="Plain Text Document"/>
                        <MenuFlyoutItem Text="Rich Text Document"/>
                        <MenuFlyoutItem Text="Other Formats..."/>
                    </MenuFlyoutSubItem>
                    <MenuFlyoutSeparator/>
                    <MenuFlyoutItem Text="Exit" Click="MenuFlyoutItem_Click_3" Icon="Cancel">
                        <MenuFlyoutItem.KeyboardAccelerators>
                            <KeyboardAccelerator Key="E" Modifiers="Control"/>
                        </MenuFlyoutItem.KeyboardAccelerators>
                    </MenuFlyoutItem>
                </MenuBarItem>
        <MenuBarItem Title="View">
            <MenuFlyoutItem Text="Oputput" Click="MenuFlyoutItem_Click_4"/>
            <MenuFlyoutSeparator/>
                    <RadioMenuFlyoutItem Text="Small icons" GroupName="SizeGroup" Click="RadioMenuFlyoutItem_Click"/>
                    <RadioMenuFlyoutItem Text="Medium icons" GroupName="SizeGroup" Click="RadioMenuFlyoutItem_Click_1"/>
                    <RadioMenuFlyoutItem Text="Large icons" GroupName="SizeGroup" Click="RadioMenuFlyoutItem_Click_2"/>
                </MenuBarItem>
    </MenuBar>
            
    </Grid>
        <Grid Grid.Row="1" Padding="15">
                <TextBlock x:Name="TBlock"> You Clicked: </TextBlock>
            </Grid>
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

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::page7::implementation
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


void winrt::page7::implementation::MainWindow::MenuFlyoutItem_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    TBlock().Text(L"Save");
}


void winrt::page7::implementation::MainWindow::MenuFlyoutItem_Click_1(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    TBlock().Text(L"Open");
}





void winrt::page7::implementation::MainWindow::MenuFlyoutItem_Click_3(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    TBlock().Text(L"Exit");
}


void winrt::page7::implementation::MainWindow::MenuFlyoutItem_Click_4(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    TBlock().Text(L"Oputput");
}


void winrt::page7::implementation::MainWindow::RadioMenuFlyoutItem_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{

}


void winrt::page7::implementation::MainWindow::RadioMenuFlyoutItem_Click_1(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{

}


void winrt::page7::implementation::MainWindow::RadioMenuFlyoutItem_Click_2(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{

}

```
