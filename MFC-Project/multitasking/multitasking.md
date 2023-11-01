## 개발환경  
Visual studio 2022   
  
## 개발과정  
단일문서-mfcstandard-클래스뷰-뷰클래스 함수추가-onmydraw 내용추가 클래스마법사 app클래스-가상함수 onidle 내용추가  
  
## 실행결과  

https://github.com/gryrryfh/visual-programming/assets/50912987/972585fc-5419-4881-bca9-1e8199497533

## 코드설명

## 코드  
OnMyDraw  
``` c++
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

```
OnIdle
```
BOOL CMultiTasking5App::OnIdle(LONG lCount)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	POSITION pos = GetFirstDocTemplatePosition();
	CDocTemplate* p = GetNextDocTemplate(pos);
	pos = p->GetFirstDocPosition();
	CMultiTasking5Doc* pDoc = (CMultiTasking5Doc*)p->GetNextDoc(pos);
	pos = pDoc->GetFirstViewPosition();
	CMultiTasking5View* pView = (CMultiTasking5View*)pDoc->GetNextView(pos);
	pView->OnMyDraw();
	return (true);
	//return CWinApp::OnIdle(lCount);
}
```
