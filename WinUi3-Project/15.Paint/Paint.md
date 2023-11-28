
https://github.com/gryrryfh/visual-programming/assets/50912987/47a4227c-463f-4931-b118-65a25359ffa1
소스코드 : https://github.com/gryrryfh/WinUI3Paint
실행결과 : Uploading WinUI Desktop 2023-11-28 14-46-05.mp4…

개선내용 : enable왼쪽에 메뉴바를 하나 더 생성해 지우개 기능 추가(지우개메뉴를 누르면 배경색으로 변하고 선 굵기가 커진다)
```cpp
void winrt::WinUI3Pen::implementation::MainWindow::MenuFlyoutItem_Click_4(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    myCol = winrt::Microsoft::UI::Colors::CornflowerBlue();
    mySize = 50;
}

```
저장, 불러오기 개선 : 일관된 파일 경로, 파일 작업에 대한 오류 검사, 예외가 있는 C++ 표준 라이브러리 파일 I/O 사용 등 제안된 개선 사항이 통합(gpt참조)
```cpp
#include <fstream>
#include <stdexcept>
#include <iostream>
void winrt::WinUI3Pen::implementation::MainWindow::MenuFlyoutItem_Click_1(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    const char* filePath = "C:/Users/PC/source/repos/WinUI3Pen-master/WinUI3Pen-master/my.txt";

    try
    {
        // Saving data using C++ standard library file I/O
        std::ofstream outFile(filePath);
        if (outFile.is_open())
        {
            int num = vx.size();
            outFile << num << '\n';
            for (int i = 0; i < num; i++)
            {
                outFile << vx[i] << ' ' << vy[i] << ' ' << static_cast<int>(col[i].A) << ' '
                    << static_cast<int>(col[i].B) << ' ' << static_cast<int>(col[i].G) << ' '
                    << static_cast<int>(col[i].R) << ' ' << size[i] << '\n';
            }
            outFile.close();
            MessageBox(NULL, L"The File was opened\n", L"Hi", NULL);
        }
        else
        {
            throw std::runtime_error("Error opening file for writing");
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        MessageBox(NULL, L"The File was not opened\n", L"hi2", NULL);
    }
}

void winrt::WinUI3Pen::implementation::MainWindow::MenuFlyoutItem_Click_2(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    const char* filePath = "C:/Users/PC/source/repos/WinUI3Pen-master/WinUI3Pen-master/my.txt";

    try
    {
        // Loading data using C++ standard library file I/O
        std::ifstream inFile(filePath);
        if (inFile.is_open())
        {
            vx.clear();
            vy.clear();
            col.clear();
            size.clear();

            int num;
            float vx1, vy1, size1;
            int colA, colB, colG, colR;

            inFile >> num;
            for (int i = 0; i < num; i++)
            {
                inFile >> vx1 >> vy1 >> colA >> colB >> colG >> colR >> size1;
                vx.push_back(vx1);
                vy.push_back(vy1);
                myCol.A = static_cast<uint8_t>(colA);
                myCol.B = static_cast<uint8_t>(colB);
                myCol.G = static_cast<uint8_t>(colG);
                myCol.R = static_cast<uint8_t>(colR);
                col.push_back(myCol);
                size.push_back(size1);
            }
            inFile.close();
            CanvasControl_PointerReleased(NULL, NULL);
        }
        else
        {
            throw std::runtime_error("Error opening file for reading");
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        MessageBox(NULL, L"The File was not opened\n", L"hi2", NULL);
    }
}
```

