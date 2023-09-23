## Modeless Dialog 
### 개발환경 : Visual Studio 2022

### 이론 : 모달과 모달리스의 차이
* 모달 : 모달 창이 열렸을 땐 기존 창에 있는 창을 사용하지 못하는 방식  
* 모달리스 : 어느 하나의 다이얼로그 창이 있어도 프로그램 제어권을 하지 않으므로 다른 작업을 할 수 있는 방식  
* 모달: 생성-DoModal, 종료-EndDialog, 인스턴스 선언-지역변수  
* 모달리스 : 생성 : Create, 종료-DestroyWindow(), 인스턴스 선언-전역변수  
  
### 개발 과정
* Visual Studio 2022 새프로젝트-MFC-대화상자기반

![image](https://github.com/gryrryfh/visual-programming/assets/50912987/3c02b400-4058-44b0-8f2a-51ba5ea0dac0)  
  
* Dialog에 ListBox와 Button을 생성
  
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/f91bec56-4ea9-4f54-af35-4f661b0d6a6f)  
  
* ListBox 변수추가-범주 컨트롤, m-List이름으로 변경
  
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/633587ea-fe90-44b8-b9f3-b44fbf136c12)  
  
* 이때 생성한 Button을 누르면 새 Dialog가 열리게 리소스뷰-Dialog-리소스 삽입
    
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/ed52ece1-3539-4e6a-a95a-349f025cf6bb)  
  
* 생성된 Dialog에 Edit Control, Button 생성
    
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/97800ad1-4dda-46d8-be58-01c0bd2c3565)  
  
* Edit Control 변수추가-범주 값, m-String이름으로 변경
  
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/0470c8d9-2081-4386-b527-75831cca5051)  
  
* 새로 생성된 Dialog에 클래스추가-CModeless로 생성
  
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/37c4e844-9f35-474d-a520-518ddb670822)  
  
* 부모 창 cpp파일에 Modeless 형태로 코딩
    
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/0666cc4b-2741-43a7-834c-96486ddef7c6) 
  
* CModeless클래스에 클래스마법사-가상함수 PostNcDestroy와 속성뷰의 메시지- WM_Close를 추가
     
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/ff1f579b-dbaf-4967-90f5-82f0a6bd1e1c)  
  
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/13976f66-a565-4138-9f0c-0f545ff79dce)  
  
* CModeless에서 Button을 누르면 부모 ListBox에 나타나도록 코딩
    
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/4649e158-54c3-4ab1-8faf-ce30a42cef35)  
  
### 코드
```C++
//부모 다이어로그 C++ 코드

// My1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "My1.h"
#include "My1Dlg.h"
#include "afxdialogex.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CModeless.h"


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy1Dlg 대화 상자



CMy1Dlg::CMy1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
}

BEGIN_MESSAGE_MAP(CMy1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST1, &CMy1Dlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy1Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMy1Dlg 메시지 처리기

BOOL CMy1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMy1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMy1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMy1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy1Dlg::OnLbnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy1Dlg::OnBnClickedButton1()
{
	CModeless* pDlg = new CModeless;
	pDlg->Create(IDD_DIALOG1);
	pDlg->ShowWindow(SW_SHOW);
}
```
```C++
//자식 Modeless C++ 다이어로그 코드
// CModeless.cpp: 구현 파일
//

#include "pch.h"
#include "My1.h"
#include "afxdialogex.h"
#include "CModeless.h"
#include "My1Dlg.h"


// CModeless 대화 상자

IMPLEMENT_DYNAMIC(CModeless, CDialogEx)

CModeless::CModeless(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_String(_T(""))
{

}

CModeless::~CModeless()
{
}

void CModeless::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_String);
}


BEGIN_MESSAGE_MAP(CModeless, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CModeless::OnBnClickedButton1)
END_MESSAGE_MAP()


// CModeless 메시지 처리기


void CModeless::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CDialogEx::PostNcDestroy();
}


void CModeless::OnClose()
{
	
	DestroyWindow();

	CDialogEx::OnClose();
}


void CModeless::OnBnClickedButton1()
{
	CMy1Dlg* dlg = (CMy1Dlg*)GetParent();
	UpdateData(true);
	dlg->m_List.AddString(m_String);
}
```
### 실행결과
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/f7035bf9-35d4-4acf-95c9-c083cfd4a731)
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/30613586-3632-4704-871e-e4603e9d9f5a)
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/e764f374-72a3-4d30-9e63-2c17fe3181d1)


