#if !defined(AFX_LISENT_H__BFB4EDB9_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_)
#define AFX_LISENT_H__BFB4EDB9_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Lisent.h : header file
//

class CMainFrame;

/////////////////////////////////////////////////////////////////////////////
// CLisent command target

class CLisent : public CSocket
{
// Attributes
public:
	CMainFrame *m_pMainFrame;
// Operations
public:
	CLisent(CMainFrame *pMainFrame);
	virtual ~CLisent();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLisent)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CLisent)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_LISENT_H__BFB4EDB9_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_)
