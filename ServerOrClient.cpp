// ServerOrClient.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "ServerOrClient.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerOrClient dialog


CServerOrClient::CServerOrClient(CWnd* pParent /*=NULL*/)
	: CDialog(CServerOrClient::IDD, pParent)
{
	//{{AFX_DATA_INIT(CServerOrClient)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CServerOrClient::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServerOrClient)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CServerOrClient, CDialog)
	//{{AFX_MSG_MAP(CServerOrClient)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerOrClient message handlers
