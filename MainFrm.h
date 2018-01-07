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
	//发送消息对话框
	CSend dlg2;
	//端口
	UINT m_Port;
	//服务器名称
	LPCTSTR m_Server;
	//请求连接
	CRequest *m_pSocket;
	//监听Socket
	CLisent *m_pListening;
	//服务器为客户请求建立的Socket队列
	CPtrList m_pList;      
	//是否服务器
	int ynserver;
	//服务器或者客户端  
	void OnSorc();
	//连接服务器
	CRequest* ConnectServer();
	//发送消息
	void SendMsg(CRequest*pRequest,char *pMsg);
	//接受消息
	void FetchMsg(CRequest*pRequest);
	//设置服务器
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
	//发送信息（菜单）
 	afx_msg void OnSend();
	//连接网络（菜单）
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__BFB4EDAA_DAE1_11D5_B2C4_5254AB2BD63E__INCLUDED_)
