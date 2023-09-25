
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
