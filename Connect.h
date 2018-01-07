#if !defined(AFX_CONNECT_H__BFB4EDB7_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_)
#define AFX_CONNECT_H__BFB4EDB7_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Connect.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CConnect dialog

class CConnect : public CDialog
{
// Construction
public:
	CConnect(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CConnect)
	enum { IDD = IDD_DIALOG2 };
	//接口
	UINT	m_port;
	//服务器名
	CString	m_server;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConnect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CConnect)
 	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_CONNECT_H__BFB4EDB7_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_)
