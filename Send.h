#if !defined(AFX_SEND_H__BFB4EDB8_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_)
#define AFX_SEND_H__BFB4EDB8_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Send.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSend dialog

class CSend : public CDialog
{
// Construction
public:
	CSend(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSend)
	enum { IDD = IDD_DIALOG3 };
	//发送的信息
	CString	m_sendedit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSend)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSend)
	//发送信息
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEND_H__BFB4EDB8_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_)
