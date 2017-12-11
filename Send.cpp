// Send.cpp : implementation file
//

#include "stdafx.h"
#include "8_1.h"
#include "Send.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSend dialog


CSend::CSend(CWnd* pParent /*=NULL*/)
	: CDialog(CSend::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSend)
	m_sendedit = _T("");
	//}}AFX_DATA_INIT
}


void CSend::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSend)
	DDX_Text(pDX, IDC_SENDEDIT, m_sendedit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSend, CDialog)
	//{{AFX_MSG_MAP(CSend)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSend message handlers

void CSend::OnSend() 
{
	// TODO: Add your control notification handler code here
	   	UpdateData();
    	CMainFrame *pFrame=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	    UpdateData(FALSE);	
		char pMsg[10000];
		sprintf(pMsg,":%s",m_sendedit.GetBuffer(10000));
		if(pFrame->ynserver==1)
		{
			CMy8_1App *App=( CMy8_1App * )AfxGetApp();
	    	pFrame->SendMsg(App->pRequestSave,pMsg);
		}
		else if(pFrame->ynserver==2)
			if(pFrame->m_pSocket)
			{
				pFrame->SendMsg(pFrame->m_pSocket,pMsg);
			}
	
}
