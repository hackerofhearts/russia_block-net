// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "8_1.h"
#include "ServerOrClient.h"
#include "Connect.h"
#include "Send.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(IDC_SEND, OnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_pSocket=NULL;
	m_Server="";
	m_Port=100;
	m_pListening=NULL;
	m_pList.RemoveAll();
	
}

CMainFrame::~CMainFrame()
{
	if(m_pSocket)
		delete m_pSocket;
	delete m_pListening;
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
/*	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
*/
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.dwExStyle=cs.dwExStyle|WS_EX_TOPMOST;	//
	cs.style=WS_SYSMENU|WS_OVERLAPPED|WS_MINIMIZEBOX;//; 
	cs.cx=500;
	cs.cy=590;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnSend() 
{
	// TODO: Add your command handler code here
	if(ynserver==1)
	{
		CMy8_1App *App=( CMy8_1App * )AfxGetApp();
		if(!App->pRequestSave)
		{
			MessageBox("没有连接到任何服务器","警告信息",MB_OK);
			return;
		}
		dlg2.DoModal();	
		return;
	}
    if(ynserver==2)
	{
		if(!m_pSocket)
		{
			MessageBox("没有连接到任何服务器","警告信息",MB_OK);
			return;
		}
		dlg2.DoModal();
	}
	
}

void CMainFrame::FetchMsg(CRequest *pRequest)
{
	char pMsg[10000],tempMsg[1000];
	int ByteCount;
	int End=0;
	CStringArray *temp=new CStringArray;
	char AnMsg[10100];

	
	strcpy(pMsg,"");
	do
	{
		strcpy(tempMsg,"");
		ByteCount=pRequest->Receive(tempMsg,1000);
		if(ByteCount>1000||ByteCount<=0)
		{
			MessageBox("接受网络信息发生错误","警告信息",MB_OK);
			return ;
        }
		else if(ByteCount<1000&&ByteCount>0)
		{
			End=1;
		}
		tempMsg[ByteCount]=0;
		strcat(pMsg,tempMsg);
	}while(End==0);

	char yesno[2];
	strcpy(yesno,"");
	strncat(yesno,pMsg,1);
	int p=strcmp(yesno,":");
	if(p==0)
	{
		MessageBox(pMsg,"对方来信",MB_OK);
  		return;
	}

//	if(ynserver==1)
//	{
		CMy8_1App *App=( CMy8_1App * )AfxGetApp();
		strcpy(App->str,pMsg);
		
//		MessageBox(App->str,"网络信息",MB_OK);
//		sprintf(AnMsg,"我们收到您发来的信息""%s""谢谢!",pMsg);
//		SendMsg(pRequest,AnMsg);
//	}
	
//	if(ynserver==2)
//	{	
//		dlg2.m_sendedit=pMsg;
//		dlg2.UpdateData(FALSE);
//	}
	
}

void CMainFrame::SendMsg(CRequest *pRequest, char *pMsg)
{
	pRequest->Send(pMsg,strlen(pMsg));
}

CRequest* CMainFrame::ConnectServer()
{
	CRequest *pSocket=new CRequest(this);
	if(!(pSocket->Create()))
	{
		delete pSocket;
		MessageBox("创建Socket失败","警告信息",MB_OK);
        return NULL;
	}
	//连接到服务器
	if(!pSocket->Connect(m_Server,m_Port))
	{
		delete pSocket;
		MessageBox("请求连接到服务器失败","警告信息",MB_OK);
        return NULL;
	}
	return pSocket;

}

void CMainFrame::OnOpen() 
{
	// TODO: Add your command handler code here
//	if(ynserver==1)
//		return;
	if(m_pSocket)
	{
		MessageBox("已经连接到服务器,请关闭连接再试一次!","警告信息",MB_OK);
		return;
	}
	CConnect dlg1;
	if(dlg1.DoModal()==IDOK)
	{
		m_Server=dlg1.m_server ;
		m_Port=dlg1.m_port;
		m_pSocket=new CRequest(this);
		if(!(m_pSocket=ConnectServer()))
		{
			m_pSocket=NULL;
			return;
		}
	}
}

void CMainFrame::OnSet() 
{
	// TODO: Add your command handler code here
		m_pListening=new CLisent(this);
		if(m_pListening->Create(100))
		{
			if(!m_pListening->Listen())
			{
				MessageBox("端口设置错误!","网络信息",MB_OK);
			}
		}

}

void CMainFrame::OnSorc() 
{
	// TODO: Add your command handler code here
	CServerOrClient dlg;
	if(dlg.DoModal()==IDOK)
	{
		//如果服务器
		//设置服务器
		 OnSet();
		 //标志
		 ynserver=1; 
	}
    else
	{   
		//否则，打开连接对话框
		OnOpen();
		//标志
		ynserver=2; 
	}
}

 

//void CMainFrame::OnNet() 
//{
	// TODO: Add your command handler code here
//	OnSorc();
//}
