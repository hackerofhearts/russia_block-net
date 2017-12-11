
// 8_1.h : main header file for the 8_1 application
//

#if !defined(AFX_8_1_H__BFB4EDA6_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_)
#define AFX_8_1_H__BFB4EDA6_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "Request.h"	// Added by ClassView

/////////////////////////////////////////////////////////////////////////////
// CMy8_1App:
// See 8_1.cpp for the implementation of this class
//

class CMy8_1App : public CWinApp
{
public:
    //保存客户端
	CRequest *pRequestSave;
	//保存接收信息（下棋位置）
    char str[10000];
	CMy8_1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy8_1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMy8_1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_8_1_H__BFB4EDA6_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_)
