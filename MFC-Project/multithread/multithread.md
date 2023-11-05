## 실행결과
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/b4b506dc-7c90-4bb3-b1ff-5d853184b398)
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/42838944-3c42-4998-8672-90ee30048754)


## 코드 
``` c++
UINT MyThread(LPVOID pParam);
UINT MyThread(LPVOID pParam)
{
  	SData * pData = (SData*)pParam;
        // Find max 여기에 최소값을 찾는 프로그램을 작성하세요.
	for (int i = 0; i < 9; i++) {
		if (pData->array[i] < pData->min)
			pData->min = pData->array[i];
	}

  	::PostMessage(pData->NotifyWindow, WM_MAX, 0, 0);
	return 0;
}

void CMyView::OnFindmax()
{
	data.array[0]=10;
	data.array[1]=30;
	data.array[2]=20;
	data.array[3]=40;
	data.array[4]=60;
	data.array[5]=80;
	data.array[6]=70;
	data.array[7]=90;
	data.array[8]=99;
	data.array[9]=50;

	data.min=100;
	data.NotifyWindow = m_hWnd;
	AfxBeginThread(MyThread, &data);
}
LRESULT CMyView::OnMaxFound(WPARAM wParam, LPARAM lParam)
{
	CMyDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CString msg;
	msg.Format(L"Min of the array = %d", data.min);
	pDoc->str = msg;
	TerminateThread(Thread, 0);
	Invalidate();
	return 0L;
}
```
