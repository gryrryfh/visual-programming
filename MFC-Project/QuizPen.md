펜의 굵기를 선택할 수 있다
펜의 색상을 선택할 수 있다
저장할 수 있다
읽을 수 있다
콘텍스트 메뉴로 굵기와 색상을 선택할 수 있다]키보드 1~9까지 누르면 펜의 굵기를 바꿀 수 있다



	if (pMsg->wParam == '1') m_Size = 1;
	if (pMsg->wParam == '2') m_Size = 2;
	if (pMsg->wParam == '3') m_Size = 3;
	if (pMsg->wParam == '4') m_Size = 4;
	if (pMsg->wParam == '5') m_Size = 5;
	if (pMsg->wParam == '6') m_Size = 6;
	if (pMsg->wParam == '7') m_Size = 7;
	if (pMsg->wParam == '8') m_Size = 8;
	if (pMsg->wParam == '9') m_Size = 9;
	if (pMsg->wParam == '0') m_Size = 10;
	CString str;
	str.Format(L"size = %d", m_Size);
	//MessageBox(str);
	SetWindowText(str);
