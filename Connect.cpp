// Connect.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "Connect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConnect dialog


CConnect::CConnect(CWnd* pParent /*=NULL*/)
	: CDialog(CConnect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConnect)
	m_server = _T("wps");
	m_port = 100;
	//}}AFX_DATA_INIT
}


void CConnect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_SERVER, m_server);

}


BEGIN_MESSAGE_MAP(CConnect, CDialog)
	//{{AFX_MSG_MAP(CConnect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConnect message handlers
