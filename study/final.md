# 1. update data



# 2. getdlgitemint



# 3. windows app sdk


# 4.  칸메꾸기 코드 2장cpoint 



# 5. 매크로 colordef
□ 색상 변경   COLORREF col; 
○ [색상] 버튼을 하나 넣고, 코드를 작성한다.
// COLORREF col; 선언을 한다.
CColorDialog dlg;
if(dlg.DoModal()==IDOK){
  col = dlg.GetColor();
}




# 6. 다이얼로그 중에서 모덜리스 다이얼러고 생성(칸메꾸기


# 7. dll, lib 차이


# 8. cpu 효율적인 활용(timer, onidle(어느곳의 클래스인가

# 9. winui3 칸메꾸기

# 10. win2d direct 에 사용한거 nuget사용함




1장 연습문제

1. WinUI 3는 Windows 7, Windows 8의 앱에서 최신 컨트롤, 스타일 및 기능을 사용할 수 있다.   ( O / X )

2. Windows 앱 SDK (10.0.17134.0 버전 이상)에는 C++/WinRT를 사용할 수 있다. ( O / X )

3. WinUI 2에서는 UWP, WinUI 3에서는 Win32 기반 앱을 개발할 수 있다. ( O / X )

단답형 문제

4. ____는 헤더 파일 기반 라이브러리로 구현된 WinRT API용 C++17 언어입니다.

5. Microsoft에서 개발한 차세대 WinUI 프레임워크는?

6. WinUI 3는 Windows ____, _____  환경의 UI를 사용하여 제작한다.

4문 1택 문제

7. C++/CLI, C++/CX에 비해 성능과 문법이 개선되어 Win32, UWP 앱 개발 등에서 표준으로 많이 사용하고 있는 언어는?

가. C++/CLI

나. C++/CX

다. C++/WinRT

라. WinUI 3

8. WinUI 3에서 지원하지 않는 플랫폼은?

가. UWP

나. Win32

다. XBox

라. Hololens

9. Microsoft 사의 개발환경이 아닌 것은?

가. WinUI 3

나. MFC

다. WinUI 2

라. Dev-C++

​

2장 연습문제

OX 문제

2. StackPanel의 속성 중 Orientation은 방향을 지정하는 속성이다. ( O / X )

3. Button의 속성 중 Click은 버튼을 클릭하면 실행되는 함수명을 지정하는 속성이다. ( O / X )

4. XAML은 마크다운 언어이다. ( O / X )

단답형 문제

5. StackPanel의 VerticalAlignment 속성에서 수직 정렬을 중앙으로 하기 위한 값은?

6. WinUI 3를 실행하기 위한 단축키(디버그하지 않고 시작)는?

7. Button의 클래스 명을 지정하기 위한 속성 명은?

4문 1택 문제

8. C++/WinRT에서 버튼의 텍스트를 변경하기 위한 함수는?

가. Content()

나. Text()

다. scanf()

라. String()

9. WinUI 3의 UI를 작성하기 위해 사용하는 언어는?

가. C++/WinRT

나. XAML

다. Python

라. JAVA

10. WinUI 3 프로젝트의 구성 파일들을 확인하기 위한 탐색기는?

가. 테스트 탐색기

나. Git 변경 내용

다. 서버 탐색기

라. 솔루션 탐색기

​

3장 연습문제

OX 문제

1. 덧셈에서 사용했던 MainWindow.xaml의 버튼 이름을 곱셈에서 그대로 사용해도 오류가       나지 않는다.  ( O / X )

2. SetWindowPos()를 사용하면 실행 창의 크기를 조정할 수 있다. ( O / X )

3. Button의 새 이벤트 처리기를 생성하면 MainWindow.cpp에서 메서드가 생성된다. 

  ( O / X )

단답형 문제

4. 밑줄 친 3개의 빈칸에 알맞은 코드를 각각 완성하시오.

void winrt::caculator::implementation::MainWindow::subtract_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)

{

    va = _____(a().Text().c_str());

    vb = _____(b().Text().c_str());

    vc = va - vb;

    c().Text(_________(vc));

}

5. orientation 속성을 수직으로 설정할 수 있는 함수는?

6. 여백을 조정할 수 있는 것은?

4문 1택 문제

7. 다음 밑줄 친 빈칸에 공통으로 들어갈 수 있는 함수는?

MainWindow::MainWindow()

    {

        InitializeComponent();

        auto ___________{ this->try_as<::I________>() };

        HWND hWnd{ 0 };

        ___________ ->get_WindowHandle(&hWnd);

        SetWindowPos(hWnd, NULL, 300, 500, 250, 300, NULL);

        this->Title(L"Caculator");

    }

가. SetPos

나. WindowSize

다. window automation

라. WindowNative

​

4장 연습문제

OX 문제

2. WinUi 3 Gallery를 통해 다양한 컨트롤들의 예시를 볼 수 있다. ( O / X )

3. WinUi 3 Gallery를 통해 다양한 스타일들의 예시를 볼 수 있다. ( O / X )

4. TextBox에서 입력을 제한하는 속성은 IsReadOnly이다. ( O / X )

단답형 문제

5. 클래스들의 속성들을 모아놓아 정리해놓은 가이드의 이름은?

6. 선택한 Text를 하얀색으로 강조하는 코드를 완성하여라.

<TextBox Name="Semple" UriS           ource="White" MinWidth="400" />

7. TextBox에서 텍스트 색 변경하는 속성은?

4문 1택 문제

8. TextBox의 텍스트 크기를 설정할 수 있는 속성은?

가. Text

나. FontFamily

다. FontSize

라. FontStyle

9. TextBox에서 True로 설정 시 사용 가능 너비 초과 시 줄 바꿔주는 속성은?

마. TextWrapping

바. IsSpellCheckEnabled

사. AcceptsReturn

아. MinWidth

10. TextBox의 최소 너비를 설정하는 속성값은?

자. TextWrapping

차. MinWidth

카. MinHight

타. IsSpellCheckEnabled

​

5장 연습문제

OX 문제

3. PersonPicture는 사진만 띄울 수 있다. ( O / X )

4. PersonPicture는 WinUi3 Gallery에서 Layout 카테고리에 속한다. ( O / X )

5. 한 개의 라디오 버튼에서 동시에 여러개 버튼 선택이 불가능하다.  ( O / X )

단답형 문제

6. PersonPicture는 무슨 기능을 하는 컨트롤인가?

7. PersonPicture에서 URL로 PNG 이미지를 가져오기 위해 빈칸을 채우시오.

<PersonPicture x:Name="personPicture" Height="300" VerticalAlignment="Top" ProfilePicture="https://docs.microsoft.com/windows/uwp/contacts- and-calendar/images/shoulder-tap-static-payload.   o“ />

8. DisplayName에 관해 설명하시오.

4문 1택 문제

9. PersonPicture의 프로필 이미지 속성으로 옳은 것은?

가. PersonPicture

가. BadgeNumber

나. Contact

다. ProgilePicture

10. DisplayName에 ”Gil Dong“이라 설정하였다. 올바르게 실행된 것은?

가. GD

나. Dong

다. Gil

라. Gil Dong

11. 라디오 버튼을 하나의 묶음으로 인식하게 해주는 컨트롤은?

가. RadioButton

나. RadioChecked

다. RadioButtons

라. CheckBox

​

6장 연습문제

OX 문제

1. VariableSizedWrapGrid를 통해 이미지나 컨트롤을 배치할 수 있다. ( O / X )

2. VariableSizedWrapGrid에서 각 셀의 높이를 설정하는 속성은 CellHeight이다. ( O / X )

3. 이미지는 로컬 이미지만 출력할 수 있다. ( O / X )

단답형 문제

4. 이미지를 출력하기 위해 빈칸(노란색 바탕)을 채워 다음 코드를 완성하여라.

<Image Height="300">

<Image.Source>

<BitmapImage UriSource="https://github.com/microsoft/WinUI-Gallery/

blob/main/WinUIGallery/Assets/SampleMedia/

LandscapeImage1.jpg?raw=true"/>

</Image.Source>

</Image>

5. VariableSizedWrapGrid에서 최대 행렬 개수를 설정하는 속성은?

6. Grid에서 열의 너비를 정하기 위한 속성은?

4문 1택 문제

7. 각 행의 높이와 각 열의 너비를 설정할 수 있는 레이아웃 컨트롤은?

가. VariableSizedWrapGrid

나. StackPanel

다. Canvas

라. Grid

8. 배치 방향을 설정하는 속성은?

가. Orientation

나. Direction

다. Position

라. Order

9. 이미지를 셀의 크기에 맞게 채우는 속성값은?

가. Stretch=”Fill”

​

7장 연습문제

OX 문제

1. 메뉴바를 추가하려면 MenuFlyoutItem 태그를 사용해야 한다.       ( O / X )

1. 메뉴를 선택할 때 발생하는 이벤트는 Click 이벤트이다.            ( O / X )

2. 라디오 메뉴를 사용할 때 그룹을 지정하기 위해 동일한 GroupName을 가져야 한다. 

                                                                     ( O / X )

단답형 문제

3. ‘환경설정’ 메뉴바 안에 ‘일반’ 메뉴와 ‘고급’ 메뉴를 만들기 위해 빈칸(노란색 바탕)을 채워 다음 코드를 완성하여라.

<MenuBar>

<MenuBarItem Title="환경설정">

<                Text="일반"/>

<                Text="고급"/>

</MenuBarItem>

</MenuBar>

4. ‘도구’ 메뉴에 단축키 ‘Ctrl + F’ 기능을 추가하기 위해 빈칸(노란색 바탕)을 채워 다음 코드를 완성하여라.

<MenuFlyoutItem Text="도구">

<MenuFlyoutItem.KeyboardAccelerators>

<                                                />

</MenuFlyoutItem.KeyboardAccelerators>

</MenuFlyoutItem>

5. ‘프로젝트’라는 이름을 가지고 ‘Page’ 아이콘을 가진 메뉴바를 코드로 작성하시오.

4문 1택 문제

6. 서브 메뉴를 만들기 위해서 필요한 태그는 무엇인가요?

가. MenuBar

나. RadioMenuFlyoutItem

다. MenuFlyoutSubItem

라. MenuFlyoutItem

7. 단축키 ‘Ctrl + R’ 기능을 추가하기 위한 태그로 올바른 것은? 

가. <KeyboardAccelerator Modifiers="Shift" Key="R"/>

나. <KeyboardAccelerator Modifiers="Control" Key="M"/>

다. <KeyboardAccelerator Modifiers="Shift" Key="S"/>

라. <KeyboardAccelerator Modifiers="Control" Key="R"/>

8. MenuFlyout에서 항목을 구분하는 수평선을 생성하는 태그는 무엇인가요?

가. MenuFlyoutSeparator

나. MenuFlyout

다. MenuBarItem

라. MenuBar

​

8장 연습문제

OX 문제

1. ComboBox의 Item이 변경되었을 때 실행되는 함수를 지정하는 속성은 SelectionChanged이다. ( O / X )

2. 시간을 활용하기 위해서는 #include<string> 헤더파일을 추가해야한다. ( O / X )

3. 문자열 변수와 문자열 변수를 더하면 문자열이 합쳐진다. ( O / X )

단답형 문제

4. 카테고리를 만들고 싶을 때 콤보 박스를 만들기 위한 태그는?

5. ComboBox의 goal 객체가 선택되었는지 확인하기 위한 코드를 완성하시오.

if ( goal().           () ) flag = true;

else flag = false;

6. 콤보 박스에 아이템을 추가하기 위한 태그는?

4문 1택 문제

7. 아래 사진과 같은 메뉴를 만들기 위한 태그는?

  

가. Pivot

나. ComboBox

다. Button

라. Grid

​

8. 피봇 메뉴의 아이템을 추가하기 위한 태그는?

가. PivotItem

나. ItemPivot

다. ComboBox

라. ComboBoxItem

9. 피봇 메뉴의 아이템에 텍스트를 넣는 속성은?

가. Header

나. Title

다. Click

라. x:Name

​

9장 연습문제

OX 문제

1. MainWindow.xaml에서 Click 부분을 더블클릭하면 새 이벤트처리기가 생성된다.

  ( O / X )

2. GridRowDefinitions는 하나 이상의 RowDefinition 요소를 제공한다. ( O / X )

3. URL 주소를 잘못 입력해도 그 주소로 페이지가 이동된다. ( O / X )

단답형 문제

4. 주소창의 제목을 나타낼 수 있는 것은?

5. 다음 빈칸에 공통으로 들어갈 코드를 작성하시오.

void winrt::Browser::implementation::MainWindow::get_button_Click(winrt::Windows::Foundation::IInspectable const& seder, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)

{

    winrt::hstring sss =                    ();

    try

    {

        if (sss.size() == 0)

        {

            MessageBox(NULL, L"오류", L"url을 입력하시오", MB_OK);

            return;

        }

​

        winrt::Windows::Foundation::Uri uri(                    ());

        MyWebView().Source(uri);

    }

6. MainWindow.xaml에서 실행하였을 때 첫 페이지가 구글로 웹페이지가 나오도록 하는 코드는?

4문 1택 문제

7. 사용자 지정 컨트롤을 만들기 위한 UI 컨트롤 및 클래스를 제공하는 것은?

가. xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"

나. xmlns:controls="using:Microsoft.UI.Xaml.Controls“

다. xmlns:local="using:Browser"

라. x:Class="Browser.MainWindow"

8. 하나 이상의 RowDefinition 요소를 제공하는 것은?

가. GridRow

나. Grid.RowDefinitions

다. Grid.Row

라. Grid.column

​

10장 연습문제

OX 문제

1. ShowPaused 속성은 프로그래스 바의 정지 상태를 사용자에게 전달하는 속성이다. 

( O / X )

1. 라디오 버튼에서 버튼을 미리 선택되도록 설정하는 속성은 IsChecked 이다. ( O / X )

2. ProgressBar().IsIndeterminate(true); 는 실제 값을 표시한다. ( O / X )

단답형 문제

3. 작업의 진행 상태를 사용자에게 알려줄 때 사용하는 컴포넌트는?

4. 라디오 버튼을 선택할 때 실행되는 이벤트의 이름은?

5. 가로 길이가 200인 프로그래스 바를 만드는 코드는?

4문 1택 문제

6.  프로그래스 바의 상태를 ‘에러’로 만들기 위해 필요한 cpp 코드가 아닌 것은?

가. ProgressBar().ShowPaused(false); 

나. ProgressBar().ShowError(true); 

다. ProgressBar().IsIndeterminate(true);

라. ProgressBar().ShowError(false); 

​

11장 연습문제

1. SuppressNavigationTransitionInfo 태그는 새로운 페이지가 왼쪽에서 밀려 나타나는 애니메이션을 적용한다. ( O / X )

2. GoBack 함수는 가장 최근 항목으로 이동시키준다. ( O / X )

3. 페이지를 전환할 때 여러 가지 애니메이션을 적용할 수 있다. ( O / X )

단답형 문제

4. 이전 페이지로 이동하기 위해 빈칸(노란색 바탕)을 채워 다음 코드를 완성하여라.

void 

winrt::App1::implementation::MainWindow::BackwardButton1_Click(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&){

    if (                                      ){

        ContentFrame1().GoBack();

    }

}

5. 이미지 전환 애니메이션 중 Suppress은 어떤 애니메이션을 나타내나요?

6. 현재 프로젝트에서 새로운 페이지를 추가하는 방법은?

4문 1택 문제

7. 페이지를 전환에 적용할 수 있는 애니메이션 기능 중 아닌 것은?

가. Entrance

나. Slide from Diagonal

다. Drill In

라. Slide from Left

8. 페이지 전환 애니메이션 중 Slide from Right를 적용하여 앞으로 이동할 경우 어떤 일이 일어나는가?

가. 왼쪽에서 새로운 페이지가 밀리면서 나타난다

나. 이전 페이지가 흐려지면서 새로운 페이지가 나타난다

다. 오른쪽에서 새로운 페이지가 밀리면서 나타난다

라. 새로운 페이지가 반짝이면서 나타난다

​

12장 연습문제

1. NuGet 패키지는 매 프로젝트마다 설치하여야 활용할 수 있다. ( O / X )

2. 도형이 마우스 포인터를 따라 움직이도록 하는 메소드는 PointerPressed다. ( O / X )

3. DrawCircle에서 테두리 색상을 설정할 수 있다. ( O / X )

단답형 문제

4. 반지름이 150이고, 테두리가 5인 원을 그려라.

args.DrawingSession().DrawCircle(150, 150, 100, col, 5);

5. 다음은 마우스가 이동함에 따라 도형이 움직이도록 캔버스 화면을 초기화시켜주는 일부분이다. 코드를 완성하여라.

CanvasControl canvas = sender.as<CanvasControl>();

px = e.GetCurrentPoint(canvas).Position().X;

py = e.GetCurrentPoint(canvas).Position().Y;

canvas.Invalidate();

6. 다음 캔버스의 배경색을 초록색으로 설정하여라.

<canvas:CanvasControl

PointerMoved="CanvasControl_PointerMoved" Draw="CanvasControl_Draw" 

ClearColor="Green"/>

4문 1택 문제

7. 캔버스에 텍스트를 출력하기 위한 메서드는?

가. DrawText

나. FillText

다. DrawMessage

라. FillMessage

8. 다음 중 반지름에 대해 2개의 인수를 취하는 메서드는?

가. DrawEllipse

나. DrawCircle

다. DrawRoundedRectangle

라. DrawSphere

1. 내부가 색칠된 원을 그리는 메서드는?

가. DrawEllipse

나. FillEllipse

다. PaintEllipse

라. ColorEllipse

​

13장 연습문제

OX 문제

1. CanvasControl의 고유 속성으로 PointerPressed, ClearColor, Draw등이 있다. 

( O / X )

2. Grid는 행과 열을 사용하는 레이아웃 패널이다. ( O / X )

3. winrt/Microsoft.Graphics.Canvas.UI.Xaml.h는 CanvasControl을 쓸 수 있도록 해주는     헤더파일이다. ( O / X )

단답형 문제

4. 벡터의 뒤에 값을 넣을 때 쓰는 함수는 무엇인가?

5. PointerMoved을 설명하라.

6. (5,5)좌표와 (20,30)좌표를 잇는 초록색의 굵기가 25되는 직선이 있다 밑의 공백을 채워라.

args.DrawingSession().DrawLine(5, - 1‘], vx[i], 30, Colors::Green(), 4555);

4문 1택 문제

7. 마우스의 입력의 시작을 감지하는 이벤트는?

가. Draw

나. PointerReleased

다. PointerMoved

라. PointerPressed

8. 벡터의 뒤에 값을 넣는 방법은?

가. push_back()

나. empty()

다. back()

라. end()

9. 캔버스의 배경을 색칠하는 이벤트는?

가. CustomDevice

나. ClearColor

다. Device

라. DpiScale

​

14장 연습문제

OX 문제

1. AppBarToggleButton의 Icon은 그래픽 콘텐츠 설정이다. ( O / X )

2. Grid의 Row에서 젤 위에 두기 위해 1로 초기화해야 한다. ( O / X )

3. ColorPicker의 IsColorSliderVisible은 슬라이더가 표시되는지를 설정하는 것이다. ( O / X )

단답형 문제

4. ColorSpectrumShape의 형태에 대해 적어라.

5. AppBarToggleButton을 설명하라.

6. Slider를 설명하라

4문 1택 문제

7. AppBarToggleButton에서 텍스트를 설정하는 것은?

가. Icon

나. IsChecked

다. label

라. Click

​

8. Grid에서 첫 번째 열, 세 번째 행인 것은?

가. Grid.Column=“1”, Grid.Row=“2”

나. Grid.Column=“0”, Grid.Row=“2”

다. Grid.Column=“1”, Grid.Row=“3”

라. Grid.Column=“0”, Grid.Row=“3”

​

9. 가시적인 상태를 고르시오.

가. Visible

나. Vertical

다. Collapsed

라. Horizontal

​

15장 연습문제

OX 문제

1. MenuFlyoutItem은 MenuBarItem의 자식이다. ( O / X )

2. fopenf_s는 파일을 여는 것이다. ( O / X )

3. fscanf_s는 파일에 쓰는 것이다. ( O / X )

단답형 문제

4. errno_t에 대해 설명하라.

5. fprintf_s에 대해 설명하라.

6. 메뉴바의 아이템을 어떻게 쓰는가?

4문 1택 문제

7. 쓰기 모드로 C:/Users/1에 one.txt로 파일을 열려고 한다. 알맞은 것은? (FILE 포인터는 fw이다.)

가. errno_t err = fopen_s(&fw, "C:/Users/1/one.txt", "w");

나. errno_t err = fopen_s("C:/Users/1/one.txt", &fw, "w");

다. errno_t err = fopen_s(&fw, "C:/Users/1/one.txt/", "w");

라. errno_t err = fopen_s("C:/Users/1/one.txt/", &fw, "w");

8. FILE *f 로 파일을 열어놓은 상태이다. 올바르게 닫는 것은 무엇인가?

가. f.fclose;

나. fclose().f;

다. f.fclose(f);

라. fclose(f);

9. ContentPresenter의 배경색을 설정하는 속성은 무엇인가?

가. ClearColor

나. IsVisible

다. ContentSource

라. Background

​

​

01장 해답

1–X, 2–O, 3–O, 4–C++/WinRT, 5–WinUI 3, 6–10, 11, 7–다, 8–가, 9–라

02장 해답

1–O, 2–O, 3–X, 4–Center, 5–Ctrl+F5, 6–x:Name, 7–가, 8–나, 9–라

03장 해답

1–X, 2–O, 3–O, 4–stod, stod, to_wstring, 5–Vertical, 6-Margin, 7-라

04장 해답

1–O, 2–O, 3–O, 4–API(Application Programming Interface), 5–SelectionHighlightColor, 6–Foreground, 7–다, 8–가, 9–나

05장 해답

1–X, 2–X, 3–O, 4–사진, 이름, 이니셜을 띄운다, 5–png, 6–PresonalPiture의 프로필 이름 설정, 7–라, 8–가, 9–다

06장 해답

1–O, 2–X, 3–X, 4–UriSource, 5–MaximumRowsOrColumns, 6–ColumnDefinition(s), 7–라, 8–가, 9–가(UniformToFill: 셀의 너비에 맞게 이미지 크기를 늘리는 속성.)

07장 해답

1–O, 2–O, 3–O, 4–MenuFlyoutItem, 5–KeyboardAccelerator Modifiers="Control" Key="T", 6–<MenuFlyoutItem Text="프로젝트" Icon="Page"/>, 7–다, 8–라, 9–가

08장 해답

1–O, 2–X, 3–O, 4–<ComboBox>, 5–IsSelected, 6–<ComboBoxItem>, 7–가, 8–가, 9–가

09장 해답

1–O, 2–O, 3–X, 4–Header, 5–url_text().Text, 6–Source="http://www.google.com", 7–나, 8–나

10장 해답

1–O, 2–O, 3–X, 4–프로그래스 바, 5–Checked 이벤트, 6–<ProgressBar Width="200"/>, 7–라

11장 해답

1–X, 2–O, 3–O, 4–ContentFrame1().BackStackDepth()>0, 5–애니메이션 없이 페이지가 급격하게 바뀐다, 6–[솔루션 탐색기]를 열고 새 페이지를 추가할 솔루션 위에서 오른쪽 마우스를 클릭하여 [추가] > [새 항목]을 선택합니다. 이후 원하는 페이지 종류를 선택하고 이름과 위치를 지정합니다., 7–나, 8–다

12장 해답

1–O, 2–X, 3–O, 4–DrawCircle/150/5, 5–canvas.Invalidate();, 6–ClearColor="Green", 7–가, 8–다, 9–나

13장 해답

1-X, 2-O, 3-O, 4-push_back(), 5-터치, 마우스 및 펜/스타일러스이 이동될 때 발생하는 이벤트입니다, 6-DrawLine, 5, 20, 25, 7-라, 8-가, 9-나

14장 해답

1-O, 2-X, 3-O, 4-사각형, 원, 5-아이콘이 있는 toggle 형식의 버튼입니다., 6-트랙에 따른 값 범위에서 값을 설정하는 것입니다., 7-다, 8-나, 9-가

15장 해답

1-O, 2-O, 3-X, 4-오류를 받을 수 있는 자료형입니다, 5-파일에 글을 쓰는 것입니다, 6-MenuBarItem, 7-가, 8-라, 9-라
