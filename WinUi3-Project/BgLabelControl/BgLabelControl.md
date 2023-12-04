

## 코드
https://github.com/gryrryfh/BgLabelControlApp  
  
## 설명  
Visual Studio 2022-빈앱, 패키지됨(WinUI 3)BgLabelControlApp  
솔루션탐색기-새항목추가-사용자정의컨트롤(WinUI3)BgLabelControl 생성  
런타임 클래스를 구현하기 위해 프로젝트 디렉터리에 있는 BgLabelControl.idl,BgLabelControl.h,BgLabelControl.cpp이 생성됨  

BgLabelControl.h : Label 및 LabelProperty 속성을 구현하고, OnLabelChanged 라는 정적 이벤트 처리기를 추가  
BgLabelControl.cpp : 속성 변경 콜백을 사용하여 종속성 속성을 등록하는 방법을 확인할 수 있도록 제공  
pch.h : #include <winrt/Windows.UI.Xaml.Interop.h>추가  
themes폴더 생성, 그 안에 새항목추가 Resource Dictionary(WinUI) Generic.xaml 기본 스타일이 설정하는 유일한 속성은 컨트롤 템플릿  
xaml에 <local:BgLabelControl Background="Green" Label="I Love ANU"/>추가  
xaml.h에 #include "BgLabelControl.h" 추가  

템플릿 기반 컨트롤은 Microsoft.UI.Xaml.Controls.Control 에서 상속되며 XAML 컨트롤 템플릿을 사용하여 사용자 지정할 수 있는 시각적 구조와 시각적 동작을 갖는다  

## 실행결과  
  
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/ce4aa7c2-f5c9-4650-a02b-6d3bae6faa92)  

