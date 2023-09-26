## 요구사항
* 펜의 굵기를 선택할 수 있다
* 펜의 색상을 선택할 수 있다
* 저장할 수 있다
* 읽을 수 있다
* 콘텍스트 메뉴로 굵기와 색상을 선택할 수 있다
* 키보드 1~9까지 누르면 펜의 굵기를 바꿀 수 있다

* 채점: 100점

## 코드
* View cpp 코드
```cpp
#include "CLine.h"
void CPenView::OnDraw(CDC* pDC)
{
	CPenDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int n = pDoc->m_oa.GetSize();
	for (int i = 0;i < n;i++) {
		CLine* pLine = (CLine *)pDoc->m_oa[i];
		pLine->Draw(pDC);
	}
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CPenView 인쇄

BOOL CPenView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPenView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPenView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPenView 진단

#ifdef _DEBUG
void CPenView::AssertValid() const
{
	CView::AssertValid();
}

void CPenView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPenDoc* CPenView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPenDoc)));
	return (CPenDoc*)m_pDocument;
}
#endif //_DEBUG

COLORREF Col;
int Size;
// CPenView 메시지 처리기
void CPenView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nFlags == MK_LBUTTON) {
		CPenDoc* pDoc = GetDocument();
		CLine* pLine = new CLine(opnt, point, Size, Col);
		pDoc->m_oa.Add(pLine);
		Invalidate(FALSE);
	}
	opnt = point;
	CView::OnMouseMove(nFlags, point);
}


void CPenView::OnSelectColor()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		Col = dlg.GetColor();
	}
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CPenView::OnSize1()
{
	Size = 1;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CPenView::OnSize4()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Size = 4;
}


void CPenView::OnSize8()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Size = 8;
}


void CPenView::OnSize16()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Size = 16;
}


void CPenView::OnSize32()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Size = 32;
}


void CPenView::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	CMenu m;
	m.LoadMenuW(IDR_MAINFRAME);
	CMenu* p;
	p = m.GetSubMenu(4);
	p->TrackPopupMenu(NULL, point.x, point.y, this, NULL);
}


BOOL CPenView::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN) {
		if (pMsg->wParam == '1') { Size = 1; }
		if (pMsg->wParam == '2') { Size = 2; }
		if (pMsg->wParam == '3') { Size = 3; }
		if (pMsg->wParam == '4') { Size = 4; }
		if (pMsg->wParam == '5') { Size = 5; }
		if (pMsg->wParam == '6') { Size = 6; }
		if (pMsg->wParam == '7') { Size = 7; }
		if (pMsg->wParam == '8') { Size = 8; }
		if (pMsg->wParam == '9') { Size = 9; }

	}

	return CView::PreTranslateMessage(pMsg);
}
```
## 디자인
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/8a51fc69-0db4-4577-80d8-7da79933ac71)

  
## 실행결과

https://github.com/gryrryfh/visual-programming/assets/50912987/b90e349e-c551-4d44-b3fb-83b6d0d1280c


