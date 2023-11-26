## 실행결과
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/5995873f-6b3d-46d7-9e54-d657a00cb91b)
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/1f9a8d5f-b896-49e1-a343-202f2f934d96)
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/5bccb69c-a2e4-476c-83fd-a54ca59b9ace)
## 코드
```xaml
<?xml version="1.0" encoding="utf-8"?>
<Window
    x:Class="page5.MainWindow"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="using:page5"
    xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
    xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
    mc:Ignorable="d">

    <StackPanel Orientation="Horizontal" HorizontalAlignment="Center" VerticalAlignment="Center">
        <PersonPicture x:Name="PersonPicture" Height="300" VerticalAlignment="Top" Margin="0, 30, 50, 0"/>
        <RadioButtons Header="Options:">
            <RadioButton x:Name="ProfileImageRadio" Checked="ProfileImageRadio_Checked">Profile Image</RadioButton>
            <RadioButton x:Name="DisplayNameRadio" Checked="DisplayNameRadio_Checked">Display Name</RadioButton>
            <RadioButton x:Name="InitialRadio" Checked="InitialRadio_Checked">Initials</RadioButton>
        </RadioButtons>
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
#include "winrt/Microsoft.UI.Xaml.Media.Imaging.h"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Media::Imaging;
using namespace Windows::Foundation;
using namespace std;

 


// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::page5::implementation
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


void winrt::page5::implementation::MainWindow::ProfileImageRadio_Checked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    BitmapImage bimg;
    Uri uri = Uri(to_hstring("https://learn.microsoft.com/windows/uwp/contacts-and-calendar/images/shoulder-tap-static-payload.png"));
    bimg.UriSource(uri);
    PersonPicture().ProfilePicture(bimg);
}


void winrt::page5::implementation::MainWindow::DisplayNameRadio_Checked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    PersonPicture().ProfilePicture(NULL);
    PersonPicture().Initials(to_hstring(""));
    PersonPicture().DisplayName(to_hstring("JaeGyeong"));
}


void winrt::page5::implementation::MainWindow::InitialRadio_Checked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    PersonPicture().ProfilePicture(NULL);
    PersonPicture().Initials(to_hstring("Gy"));
}

```
