## 펜만들기
### 개발환경
  Visiual Studio-MFC프로젝트-단일문서기반  
### 꾸미기
좌측 상단 Slider Control 설치 우측 상단 Button 설치
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/7a32a518-b428-4098-b21b-133a519bd006)


Slider Control 변수추가-이름 m_Slider


![image](https://github.com/gryrryfh/visual-programming/assets/50912987/d5e8c3c8-f6ac-4f96-ac25-b82292a2d595)


### 코드
``` mfc
// 프로젝트명(클래스)는 다시 설정해야함
int n;
void CMFCApplication2Dlg::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult) //슬라이더
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	*pResult = 0;
	n = m_Slider.GetPos();

}

COLORREF m_Col;
void CMFCApplication2Dlg::OnMouseMove(UINT nFlags, CPoint point) // 마우스움직임관련 코드
{
	if (nFlags & MK_LBUTTON) { // or if(nFlags == MK_LBUTTON)
		CClientDC dc(this);
		CPen pen(PS_SOLID, n, m_Col);
		dc.SelectObject(&pen); // 컨텍스트에 생성한 펜을 선택하여 현재 그래픽 작업에 사용할 선을 설정
		dc.MoveTo(point); // 컨텍스트에서 그리기 시작 지점을 마우스의 현재 위치로 설정
		dc.LineTo(point); // 이전 위치에서부터 마우스의 현재 위치까지 선을 그림
	}
	CDialogEx::OnMouseMove(nFlags, point); // 기본 클래스인 CDialogEx의 OnMouseMove 함수를 호출하여 이벤트를 처리
}

void CMFCApplication2Dlg::OnBnClickedButton1() //버튼 관련 코드
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) //Do.Modal= 모달 다이얼로그 띄움
	{
		m_Col = dlg.GetColor();
	}

}

```

### 실행 결과
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/6451b61a-1c6f-4b27-8f34-807338caa6bd)
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/92909af6-7123-4bb2-affc-cce47da8c4e0)
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/0320f416-eb2a-46cf-912d-0baddd428e73)
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/03022cde-b1f1-4115-bef1-e89364564965)


