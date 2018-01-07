#if !defined(AFX_SERVERORCLIENT_H__BFB4EDB6_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_)
#define AFX_SERVERORCLIENT_H__BFB4EDB6_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ServerOrClient.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CServerOrClient dialog

class CServerOrClient : public CDialog
{
// Construction
public:
	CServerOrClient(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CServerOrClient)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerOrClient)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CServerOrClient)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERORCLIENT_H__BFB4EDB6_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_)
