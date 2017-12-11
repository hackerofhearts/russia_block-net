// Lisent.cpp : implementation file
//

#include "stdafx.h"
#include "8_1.h"
#include "Lisent.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLisent

CLisent::CLisent(CMainFrame *pMainFrame)
{
    m_pMainFrame=pMainFrame;
}

CLisent::~CLisent()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CLisent, CSocket)
	//{{AFX_MSG_MAP(CLisent)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CLisent member functions

void CLisent::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
		CRequest *pSocket=new CRequest(m_pMainFrame);
	if(m_pMainFrame->m_pListening->Accept(*pSocket))
	{
		m_pMainFrame->m_pList.AddTail(pSocket);
		CMy8_1App *App=( CMy8_1App * )AfxGetApp();
		App->pRequestSave=pSocket;
	}
	else 
		delete pSocket;
	
	CSocket::OnAccept(nErrorCode);
}
