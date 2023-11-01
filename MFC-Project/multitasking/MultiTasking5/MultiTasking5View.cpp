
// MultiTasking5View.cpp: CMultiTasking5View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MultiTasking5.h"
#endif

#include "MultiTasking5Doc.h"
#include "MultiTasking5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMultiTasking5View

IMPLEMENT_DYNCREATE(CMultiTasking5View, CView)

BEGIN_MESSAGE_MAP(CMultiTasking5View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMultiTasking5View 생성/소멸

CMultiTasking5View::CMultiTasking5View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMultiTasking5View::~CMultiTasking5View()
{
}

BOOL CMultiTasking5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMultiTasking5View 그리기

void CMultiTasking5View::OnDraw(CDC* /*pDC*/)
{
	CMultiTasking5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMultiTasking5View 인쇄

BOOL CMultiTasking5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMultiTasking5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMultiTasking5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMultiTasking5View 진단

#ifdef _DEBUG
void CMultiTasking5View::AssertValid() const
{
	CView::AssertValid();
}

void CMultiTasking5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMultiTasking5Doc* CMultiTasking5View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiTasking5Doc)));
	return (CMultiTasking5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMultiTasking5View 메시지 처리기


int CMultiTasking5View::OnMyDraw()
{
	CClientDC dc(this);
	RECT r1; // 창의 크기를 저장할 구조체
	GetClientRect(&r1); // 창의 크기를 읽어 옴

	// 선의 시작점과 끝점 좌표 계산
	int startX = rand() % r1.right;
	int startY = rand() % r1.bottom;
	int endX = startX + rand() % 48;
	int endY = startY + rand() % 48;

	// 무작위 RGB 색상 생성
	BYTE r = rand() % 256;
	BYTE g = rand() % 256;
	BYTE b = rand() % 256;
	COLORREF col = RGB(r, g, b);

	// 펜(선) 객체 생성 및 선택
	HPEN hPen = CreatePen(PS_SOLID, 1, col);
	HPEN hOldPen = (HPEN)SelectObject(dc.m_hDC, hPen);

	// 선을 그리기
	dc.MoveTo(startX, startY);
	dc.LineTo(endX, endY);

	// 펜(선) 객체 해제
	SelectObject(dc.m_hDC, hOldPen);
	DeleteObject(hPen);

	return 0;
}

