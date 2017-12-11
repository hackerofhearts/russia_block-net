#if !defined(AFX_REQUEST_H__BFB4EDBA_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_)
#define AFX_REQUEST_H__BFB4EDBA_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Request.h : header file
//

class CMainFrame;


/////////////////////////////////////////////////////////////////////////////
// CRequest command target

class CRequest : public CSocket
{
// Attributes
public:

// Operations
public:
	CRequest(CMainFrame*pMainFrame);
	virtual ~CRequest();

// Overrides
public:
	CMainFrame *m_pMainFrame;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRequest)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CRequest)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REQUEST_H__BFB4EDBA_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_)
