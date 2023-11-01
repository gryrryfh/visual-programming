## 개발환경  
Visual studio 2022   
  
## 개발과정  
단일문서-mfcstandard-클래스뷰-뷰클래스 함수추가-onmydraw 내용추가 클래스마법사 app클래스-가상함수 onidle 내용추가  
  
## 실행결과  

https://github.com/gryrryfh/visual-programming/assets/50912987/972585fc-5419-4881-bca9-1e8199497533

## 코드설명  
OnIdle 함수는 MFC 애플리케이션에서 사용자의 입력이 없거나 시스템이 다른 작업을 처리하는 상태일 때 호출되는 함수  
애플리케이션의 추가적인 작업을 수행하거나 업데이트를 처리할 수 있다  
OnIdle함수는 UI 업데이트, 계산, 백그라운드 작업 등을 수행하는 데 사용  
여러 개의 뷰에서 무작위로 선을 그리며, 각 뷰가 병렬로 작업을 수행하는 것처럼 보이게 한다  
선그리기 : moveto-lineto

## 코드  
OnMyDraw  
``` c++
int CMultiTasking5View::OnMyDraw()
{
	CClientDC dc(this);
	RECT r1; 
	GetClientRect(&r1); 

	int startX = rand() % r1.right;
	int startY = rand() % r1.bottom;
	int endX = startX + rand() % 48;
	int endY = startY + rand() % 48;

	BYTE r = rand() % 256;
	BYTE g = rand() % 256;
	BYTE b = rand() % 256;
	COLORREF col = RGB(r, g, b);

	HPEN hPen = CreatePen(PS_SOLID, 1, col);
	HPEN hOldPen = (HPEN)SelectObject(dc.m_hDC, hPen);

	dc.MoveTo(startX, startY);
	dc.LineTo(endX, endY);

	SelectObject(dc.m_hDC, hOldPen);
	DeleteObject(hPen);

	return 0;
}

```
OnIdle
```
BOOL CMultiTasking5App::OnIdle(LONG lCount)
{
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
