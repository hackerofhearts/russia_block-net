// MainFrm.h : interface of the CMainFrame class

#if !defined(AFX_MAINFRM_H__BFB4EDAA_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_)
#define AFX_MAINFRM_H__BFB4EDAA_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_
#include "Lisent.h"
#include "Request.h"	// Added by ClassView
#include "Send.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)
 void OnOpen();
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);	
	//}}AFX_VIRTUAL

// Implementation
public:
	//������Ϣ�Ի���
	CSend dlg2;
	//�˿�
	UINT m_Port;
	//����������
	LPCTSTR m_Server;
	//��������
	CRequest *m_pSocket;
	//����Socket
	CLisent *m_pListening;
	//������Ϊ�ͻ���������Socket����
	CPtrList m_pList;      
	//�Ƿ������
	int ynserver;
	//���������߿ͻ���  
	void OnSorc();
	//���ӷ�����
	CRequest* ConnectServer();
	//������Ϣ
	void SendMsg(CRequest*pRequest,char *pMsg);
	//������Ϣ
	void FetchMsg(CRequest*pRequest);
	//���÷�����
 	void OnSet();
 
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//������Ϣ���˵���
 	afx_msg void OnSend();
	//�������磨�˵���
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__BFB4EDAA_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_)
