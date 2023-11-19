## 실행환경
Visual Studio 2022 WinUi3 C#
## 내용
C#과 WinUI3를 사용한 곱하기 계산기
## 실행결과
https://github.com/gryrryfh/visual-programming/assets/50912987/a4024a0b-c0bd-49e2-be2a-f495cf3ea6c8
## 코드
## mainwindow.xaml
```xaml
<?xml version="1.0" encoding="utf-8"?>
<Window
    x:Class="App2.MainWindow"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="using:App2"
    xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
    xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
    mc:Ignorable="d">

    <Grid>
      

        <StackPanel>
            <StackPanel Orientation="Horizontal" HorizontalAlignment="Center">
                <TextBox x:Name="txtNumber1" Width="100" FontSize="24" Margin="5"/>
                <Button Content="*" FontSize="24" Click="OnMultiplyClick"/>
                <TextBox x:Name="txtNumber2" Width="100" FontSize="24" Margin="5"/>
            </StackPanel>
            <TextBlock x:Name="resultText" FontSize="24" FontWeight="Bold"/>
        </StackPanel>
    </Grid>
</Window>
```
## Mainwindow.xaml.cs
```c#
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;

namespace App2
{
    public sealed partial class MainWindow : Window
    {
        public MainWindow()
        {
            this.InitializeComponent();
        }
        private void OnMultiplyClick(object sender, RoutedEventArgs e)
        {
            if (double.TryParse(txtNumber1.Text, out double number1) && double.TryParse(txtNumber2.Text, out double number2))
            {
                double result = number1 * number2;
                resultText.Text = $"Result: {result}";
            }
            else
            {
                resultText.Text = "숫자를 입력하세요";
            }
        }
    }
}
```


