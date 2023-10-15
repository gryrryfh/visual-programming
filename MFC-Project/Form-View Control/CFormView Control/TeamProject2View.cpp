
// TeamProject2View.cpp: CTeamProject2View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "TeamProject2.h"
#endif

#include "TeamProject2Doc.h"
#include "TeamProject2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTeamProject2View

IMPLEMENT_DYNCREATE(CTeamProject2View, CFormView)

BEGIN_MESSAGE_MAP(CTeamProject2View, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SELECT_COLOR, &CTeamProject2View::OnSelectColor)
	ON_COMMAND(ID_SIZE_2, &CTeamProject2View::OnSize2)
	ON_COMMAND(ID_SIZE_4, &CTeamProject2View::OnSize4)
	ON_COMMAND(ID_SIZE_8, &CTeamProject2View::OnSize8)
	ON_COMMAND(ID_SIZE_16, &CTeamProject2View::OnSize16)
	ON_COMMAND(ID_SIZE_32, &CTeamProject2View::OnSize32)
	ON_WM_MBUTTONDOWN()
	ON_EN_CHANGE(IDC_EDIT1, &CTeamProject2View::OnEnChangeEdit1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CTeamProject2View::OnDeltaposSpin1)

	ON_BN_CLICKED(IDC_BUTTON3, &CTeamProject2View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_RADIO4, &CTeamProject2View::OnBnClickedRadio4)
END_MESSAGE_MAP()

// CTeamProject2View 생성/소멸

CTeamProject2View::CTeamProject2View() noexcept
	: CFormView(IDD_TEAMPROJECT2_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CTeamProject2View::~CTeamProject2View()
{
}

void CTeamProject2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	DDX_Control(pDX, IDC_SPIN1, m_Spin);
	DDX_Control(pDX, IDC_PIC, m_Pic);

}

BOOL CTeamProject2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CTeamProject2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CTeamProject2View 인쇄

BOOL CTeamProject2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTeamProject2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTeamProject2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CTeamProject2View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CTeamProject2View 진단

#ifdef _DEBUG
void CTeamProject2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CTeamProject2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTeamProject2Doc* CTeamProject2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTeamProject2Doc)));
	return (CTeamProject2Doc*)m_pDocument;
}
#endif //_DEBUG


// CTeamProject2View 메시지 처리기
#include "CLine.h"
int Size;
COLORREF Col;

void CTeamProject2View::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nFlags == MK_LBUTTON) { //마우스 좌클릭을 할 시.
		CTeamProject2Doc* pDoc = GetDocument();
		CLine* pLine = new CLine(opnt, point, Size, Col);
		pDoc->m_oa.Add(pLine);
		Invalidate(FALSE);
	}
	opnt = point; //opnt 변수를 현재 마우스 포인터의 위치로 설정합니다
	CView::OnMouseMove(nFlags, point);

}








void CTeamProject2View::OnDraw(CDC* pDC)
{
	CTeamProject2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int n = pDoc->m_oa.GetSize();
	for (int i = 0; i < n; i++) {
		CLine* pLine = (CLine*)pDoc->m_oa[i];
		pLine->Draw(pDC);

	}
}


void CTeamProject2View::OnSelectColor()
{
	CColorDialog dlg; //클래스의 객체 dlg를 생성합니다. 이 객체는 색상 대화 상자를 나타냅니다
	if (dlg.DoModal() == IDOK) {  //함수를 호출하여 색상 대화 상자를 엽니다. 사용자가 대화 상자에서 "확인" 버튼을 클릭하면, IDOK가 반환되어 조건문이 참이 됩니다.
		Col = dlg.GetColor();
	}
}


void CTeamProject2View::OnSize2()
{
	Size = 2;
}


void CTeamProject2View::OnSize4()
{
	Size = 4;
}


void CTeamProject2View::OnSize8()
{
	Size = 8; 
}


void CTeamProject2View::OnSize16()
{
	Size = 16;
}


void CTeamProject2View::OnSize32()
{
	Size = 32;

}


void CTeamProject2View::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CFormView::OnMButtonDown(nFlags, point);
}


void CTeamProject2View::OnEnChangeEdit1()
{
	CString strSize;
	m_Edit.GetWindowText(strSize);

	// 문자열을 정수로 변환하여 펜의 굵기로 설정
	Size = _ttoi(strSize);

	// 범위를 제한하여 음수나 너무 큰 값이 설정되지 않도록 함
	Size = max(1, min(64, Size));
}


void CTeamProject2View::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}



void CTeamProject2View::OnBnClickedButton3()
{
	CRect rect;//픽쳐 컨트롤의 크기를 저장할 CRect 객체
	m_Pic.GetWindowRect(rect);//GetWindowRect를 사용해서 픽쳐 컨트롤의 크기를 받는다.
	CDC* dc; //픽쳐 컨트롤의 DC를 가져올  CDC 포인터
	dc = m_Pic.GetDC(); //픽쳐 컨트롤의 DC를 얻는다.
	CImage image;//불러오고 싶은 이미지를 로드할 CImage 
	image.Load(_T("test.jpg"));//이미지 로드

	image.StretchBlt(dc->m_hDC, 0, 0, rect.Width(), rect.Height(), SRCCOPY);//이미지를 픽쳐 컨트롤 크기로 조정
	ReleaseDC(dc);//DC 해제
}


void CTeamProject2View::OnBnClickedRadio4()
{
	CRect rect;//픽쳐 컨트롤의 크기를 저장할 CRect 객체
	m_Pic.GetWindowRect(rect);//GetWindowRect를 사용해서 픽쳐 컨트롤의 크기를 받는다.
	CDC* dc; //픽쳐 컨트롤의 DC를 가져올  CDC 포인터
	dc = m_Pic.GetDC(); //픽쳐 컨트롤의 DC를 얻는다.
	CImage image;//불러오고 싶은 이미지를 로드할 CImage 
	image.Load(_T("test.jpg"));//이미지 로드

	image.StretchBlt(dc->m_hDC, 0, 0, rect.Width(), rect.Height(), SRCCOPY);//이미지를 픽쳐 컨트롤 크기로 조정
	ReleaseDC(dc);//DC 해제
}
