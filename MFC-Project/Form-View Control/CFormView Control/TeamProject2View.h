
// TeamProject2View.h: CTeamProject2View 클래스의 인터페이스
//

#pragma once


class CTeamProject2View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CTeamProject2View() noexcept;
	DECLARE_DYNCREATE(CTeamProject2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_TEAMPROJECT2_FORM };
#endif

// 특성입니다.
public:
	CTeamProject2Doc* GetDocument() const;

// 작업입니다.
public:
	CPoint opnt;
// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CTeamProject2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg void OnSelectColor();
	afx_msg void OnSize2();
	afx_msg void OnSize4();
	afx_msg void OnSize8();
	afx_msg void OnSize16();
	afx_msg void OnSize32();
	CEdit m_Edit;
	CSpinButtonCtrl m_Spin;
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);

	afx_msg void OnBnClickedButton3();
	CStatic m_Pic;
	afx_msg void OnBnClickedRadio4();
};

#ifndef _DEBUG  // TeamProject2View.cpp의 디버그 버전
inline CTeamProject2Doc* CTeamProject2View::GetDocument() const
   { return reinterpret_cast<CTeamProject2Doc*>(m_pDocument); }
#endif

