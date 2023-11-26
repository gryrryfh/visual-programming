## 실행결과

![image](https://github.com/gryrryfh/visual-programming/assets/50912987/306dbbd0-87de-438a-b50b-5803024bb8ce)
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/1e1b0d7f-67dc-493f-8f71-42427c1bc4b0)
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/0187d947-2366-4bd3-9916-73f29df4b196)

## 코드
```xaml
<?xml version="1.0" encoding="utf-8"?>
<Window
    x:Class="page8.MainWindow"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="using:page8"
    xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
    xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
    mc:Ignorable="d">

    <StackPanel Margin="20, 20, 20, 20">
        <TextBlock Text="키워드 기반 메모장"/>
        <StackPanel Orientation="Horizontal" Margin=" 20, 20, 20, 20">
            <ComboBox SelectionChanged="ComboBox_SelectionChanged" Header="카테고리" PlaceholderText="카테고리를 선택하세요." Width="200">
                <ComboBoxItem x:Name="schedule">일정</ComboBoxItem>
                <ComboBoxItem x:Name="todo">할 일</ComboBoxItem>
                <ComboBoxItem x:Name="goal">목표</ComboBoxItem>
                <ComboBoxItem x:Name="important">중요한 일</ComboBoxItem>
            </ComboBox>
            <TextBox x:Name="nameInput" Header="키워드" PlaceholderText="메모를 입력하세요" Width="300" HorizontalAlignment="Left" Margin="20, 0, 0, 0"/>
            <Button Content="저장" Click="Button_Click" Margin="20, 30, 0, 0"/>
        </StackPanel>
        <Pivot Title="메모">
            <PivotItem Header="일정">
                <TextBlock x:Name="scheduleL" Margin="20, 20, 20, 20"/>
            </PivotItem>
            <PivotItem Header="할 일">
                <TextBlock x:Name="todoL" Margin="20, 20, 20, 20"/>
            </PivotItem>
            <PivotItem Header="목표">
                <TextBlock x:Name="goalL" Margin="20, 20, 20, 20"/>
            </PivotItem>
            <PivotItem Header="중요한 일">
                <TextBlock x:Name="importantL" Margin="20, 20, 20, 20"/>
            </PivotItem>
            
        </Pivot>
    </StackPanel>
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

#include <ctime>
#pragma warning (disable : 4996)
#include <string>
using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace std;

hstring current_time() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    char buffer[128];
    strftime(buffer, sizeof(buffer), "%H:%M:%S", now);
    return to_hstring(buffer);
}
string selectedL;
hstring text1;
hstring text2;
hstring text3;
hstring text4;



// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::page8::implementation
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


void winrt::page8::implementation::MainWindow::ComboBox_SelectionChanged(winrt::Windows::Foundation::IInspectable const& , winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& )
{
    if (schedule().IsSelected()) {
		selectedL = "scheduleL";
	}
    else if (todo().IsSelected()) {
		selectedL = "todoL";
	}
    else if (goal().IsSelected()) {
		selectedL = "goalL";

	}
    else {
		selectedL = "importantL";
	}
}


void winrt::page8::implementation::MainWindow::Button_Click(winrt::Windows::Foundation::IInspectable const& , winrt::Microsoft::UI::Xaml::RoutedEventArgs const& )
{
    if (selectedL == "scheduleL") {
        text1 = text1 + (nameInput().Text() + L"\t" + current_time() + L"\n\n");
        scheduleL().Text(text1);
        }
    else if (selectedL == "todoL") {
        text2 = text2 + (nameInput().Text() + L"\t" + current_time() + L"\n\n");
        todoL().Text(text2);
    }
    else if (selectedL == "goalL") {
		text3 = text3 + (nameInput().Text() + L"\t" + current_time() + L"\n\n");
		goalL().Text(text3);
	}
    else {text4= text4 + (nameInput().Text() + L"\t" + current_time() + L"\n\n");
    importantL().Text(text4);
	}
	}


```
