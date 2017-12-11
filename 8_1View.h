// 8_1View.h : interface of the CMy8_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_8_1VIEW_H__BFB4EDAE_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_)
#define AFX_8_1VIEW_H__BFB4EDAE_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_
#include "Russia.h"	// Added by ClassView
//#include "Russiab.h"	// Added by ClassView
#include "Russia0.h"	// Added by ClassView

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy8_1View : public CView
{
protected: // create from serialization only
	CMy8_1View();
	DECLARE_DYNCREATE(CMy8_1View)

// Attributes
public:
	CMy8_1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy8_1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	int net;
//	CRussia0 russia0;

	int player;//几个人
	int view;//哪种界面
	CRussia russia2;
	CRussia russia;//俄罗斯类
	bool start;//开始
	CBitmap fenmian;//封面
	CBitmap xuanze[4];//选择三种图形
	int ixuanze;//选择哪一种游戏
	BOOL m_bPause;//暂停
	virtual ~CMy8_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnContextMenu(CWnd*, CPoint point);
	//{{AFX_MSG(CMy8_1View)
	afx_msg void OnMenuStart();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMenuPause();
	afx_msg void OnUpdateMenuPause(CCmdUI* pCmdUI);
	afx_msg void OnView1();
	afx_msg void OnView2();
	afx_msg void OnUpdateView1(CCmdUI* pCmdUI);
	afx_msg void OnUpdateView2(CCmdUI* pCmdUI);
	afx_msg void OnMenuDstart();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMenuTstart();
	afx_msg void OnNet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 8_1View.cpp
inline CMy8_1Doc* CMy8_1View::GetDocument()
   { return (CMy8_1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_8_1VIEW_H__BFB4EDAE_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_)
