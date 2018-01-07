//View.cpp : implementation of the CMy8_1View class
//

#include "stdafx.h"
#include "main.h"

#include "Doc.h"
#include "View.h"
#include "MainFrm.h"
#include "resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////


IMPLEMENT_DYNCREATE(CMy8_1View, CView)

BEGIN_MESSAGE_MAP(CMy8_1View, CView)
	ON_WM_CONTEXTMENU()
	//{{AFX_MSG_MAP(CMy8_1View)
	ON_COMMAND(ID_MENU_START, OnMenuStart)
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_MENU_PAUSE, OnMenuPause)
	ON_UPDATE_COMMAND_UI(ID_MENU_PAUSE, OnUpdateMenuPause)
	ON_COMMAND(ID_VIEW_1, OnView1)
	ON_COMMAND(ID_VIEW_2, OnView2)
	ON_UPDATE_COMMAND_UI(ID_VIEW_1, OnUpdateView1)
	ON_UPDATE_COMMAND_UI(ID_VIEW_2, OnUpdateView2)
	ON_COMMAND(ID_MENU_DSTART, OnMenuDstart)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_MENU_TSTART, OnMenuTstart)
	ON_COMMAND(ID_NET, OnNet)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////

CMy8_1View::CMy8_1View()
{
	// TODO: add construction code here
	fenmian.LoadBitmap(IDB_BITMAP1);
	for(int i=0;i<4;i++)
		xuanze[i].LoadBitmap(IDB_BITMAP7+i);
	
	start=false;
	m_bPause=false;
	view=1;
	player=1;
	ixuanze=1;
    net=0;//主机是否
}

CMy8_1View::~CMy8_1View()
{
}

BOOL CMy8_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy8_1View drawing

void CMy8_1View::OnDraw(CDC* pDC)
{
	CMy8_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CDC Dc;
	if(Dc.CreateCompatibleDC(pDC)==FALSE)
		AfxMessageBox("Can't create DC");
//发送消息
///////////////////////////////////////////////
  if(player==4)
  {	   	
    	CMainFrame *pFrame=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	    char msg[10000];
        strcpy(msg,"");
		int i,j;

	if(pFrame->ynserver==1)
	{
       for(i=0;i<4;i++)
		  for(j=0;j<4;j++)
		  {
		      if(russia2.Will[i][j]==0)
			     strcat(msg,"0");
              else
			     strcat(msg,"1");
          }
		for(i=0;i<russia2.m_RowCount;i++)
			for(j=0;j<russia2.m_ColCount;j++)
			{
                if(russia2.Russia[i][j]==0)
				  strcat(msg,"0");
                else
				  strcat(msg,"1");
             }
  		char mm[1];
		itoa(russia2.m_Level,mm,10);
		     strcat(msg,mm);
		itoa(russia2.m_Speed,mm,10);
		     strcat(msg,mm);
        char mmm[5];
		itoa(russia2.m_Score,mmm,10);
		     strcat(msg,mmm);
      
		char pMsg[10000];
		sprintf(pMsg,"%s",msg);
			CMy8_1App *App=( CMy8_1App * )AfxGetApp();
			if(App->pRequestSave!=NULL)
	    	pFrame->SendMsg(App->pRequestSave,pMsg);
		}
	 if(pFrame->ynserver==2)
		if(pFrame->m_pSocket)
		{
        for(i=0;i<4;i++)
		  for(j=0;j<4;j++)
		  {
		      if(russia.Will[i][j]==0)
			     strcat(msg,"0");
              else
			     strcat(msg,"1");
          }
		for(i=0;i<russia.m_RowCount;i++)
			for(j=0;j<russia.m_ColCount;j++)
			{
                if(russia.Russia[i][j]==0)
				  strcat(msg,"0");
                else
				  strcat(msg,"1");
             }
  		char mm[1];
		itoa(russia.m_Level,mm,10);
		     strcat(msg,mm);
		itoa(russia.m_Speed,mm,10);
		     strcat(msg,mm);
        char mmm[5];
		itoa(russia.m_Score,mmm,10);
		     strcat(msg,mmm);
 

    	char pMsg[10000];
		sprintf(pMsg,"%s",msg);
		CMy8_1App *App=( CMy8_1App * )AfxGetApp();
		pFrame->SendMsg(pFrame->m_pSocket,pMsg);
		} 
////////////////////////////////////////////////
//接收消息
 	CMy8_1App *App=( CMy8_1App * )AfxGetApp();
//    char msg[10000];
	strcpy(msg,App->str);
    int k=0;
	  char m[1];
  	if( (pFrame->ynserver==1)&&(App->pRequestSave!=NULL))
  {
	for(i=0;i<4;i++)
	  for(j=0;j<4;j++)
	  {   
	  
	      m[0]=msg[k];
		  int a=atoi(m);
        if(a==0)
		 {			
		     russia.Will[i][j]=0;
			 k++;
		 }
		 else
		 {
		     russia.Will[i][j]=1;
			 k++;
		 }
      }	  

		for(i=0;i<18;i++)//russia.m_RowCount
			for(j=0;j<12;j++)//russia.m_ColCount
			{ 
				m[0]=msg[k];
        		  int a=atoi(m);
               if(a==0)
				{
			       russia.Russia[i][j]=0;
				   k++;
				}
				else
				{
				    russia.Russia[i][j]=1;
					k++;
				}
			}
				m[0]=msg[k];
        		  int a=atoi(m);
				  russia.m_Level=a;
				  k++;
				m[0]=msg[k];
        		   a=atoi(m);
				  russia.m_Speed=a;
				  k++;
				m[0]=msg[k];
        		   a=atoi(m);
				  russia.m_Score=a;



  }			
 if(pFrame->ynserver==2)
  {
k=0;
  for(i=0;i<4;i++)
	  for(j=0;j<4;j++)
	  {
         m[0]=msg[k];
        		  int a=atoi(m);
               if(a==0)
		 {
		     russia2.Will[i][j]=0;
			 k++;
		 }
		 else
		 {
		     russia2.Will[i][j]=1;
			 k++;
		 }
	  }

		for(i=0;i<18;i++)
			for(j=0;j<12;j++)
			{

		  
				m[0]=msg[k];	  
        		  int a=atoi(m);
               if(a==0)
				{
			       russia2.Russia[i][j]=0;
				   k++;
				}
				else
				{
				    russia2.Russia[i][j]=1;
					k++;
				}
			}
				m[0]=msg[k];
        		  int a=atoi(m);
				  russia2.m_Level=a;
				  k++;
				m[0]=msg[k];
        		   a=atoi(m);
				  russia2.m_Speed=a;
				  k++;
				m[0]=msg[k];
        		   a=atoi(m);
				  russia2.m_Score=a;

  }
  }	
  //没有开始，显示封面
	if( !start)
	{
		Dc.SelectObject(fenmian);
		pDC->BitBlt(0,0,500,550,&Dc,0,0,SRCCOPY);
		Dc.SelectObject(xuanze[ixuanze-1]);
		pDC->BitBlt(200,350,150,150,&Dc,0,0,SRCCOPY);

	}
	//显示背景  
	else
	{
		if(view==1)
		{
			if(player==1)
				russia.DrawJiemian1(0,0,pDC);
			if(player==2||player==4)
			{
				russia.DrawJiemian1(500,0,pDC);
				russia2.DrawJiemian1(0,0,pDC);
			}			
		}
		if(view==2)
		{
			if(player==1)
				russia.DrawJiemian2(0,0,pDC);
			if(player==2||player==4)
			{
				russia.DrawJiemian2(253,0,pDC);
				russia2.DrawJiemian2(0,0,pDC);
			}
		}
		if(player==3)
			russia0.DrawJiemian(pDC);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMy8_1View printing

BOOL CMy8_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy8_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy8_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMy8_1View diagnostics

#ifdef _DEBUG
void CMy8_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy8_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy8_1Doc* CMy8_1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy8_1Doc)));
	return (CMy8_1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy8_1View message handlers

void CMy8_1View::OnView2() 
{
	// TODO: Add your command handler code here
	if(player==3)return;
	view=2;
	if(!start)
		return;
		//调整窗口大小
	if(player==1)
		AfxGetMainWnd() ->SetWindowPos(NULL,0,0,253,510,SWP_NOMOVE|SWP_NOZORDER );
	if(player==2||player==4)	
		AfxGetMainWnd() ->SetWindowPos(NULL,0,0,510,510,SWP_NOMOVE|SWP_NOZORDER );
	
}

void CMy8_1View::OnView1() 
{
	// TODO: Add your command handler code here
	if(player==3)return;
	view=1;
	//调整窗口大小
	if(player==1)
		AfxGetMainWnd() ->SetWindowPos(NULL,0,0,500,590,SWP_NOMOVE|SWP_NOZORDER );
	if((player==2)||(player==4))
		AfxGetMainWnd() ->SetWindowPos(NULL,0,0,1000,590,SWP_NOMOVE|SWP_NOZORDER );

	
}

void CMy8_1View::OnUpdateView1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(view==1);
	
}

void CMy8_1View::OnUpdateView2(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(view==2);
	
}

void CMy8_1View::OnMenuTstart() 
{
	// TODO: Add your command handler code here
	AfxGetMainWnd() ->SetWindowPos(NULL,0,0,513,650,SWP_NOMOVE|SWP_NOZORDER );
	player=3;
    start=true;
    russia0.Start();
	SetTimer(1,50*(11-russia0.m_Speed ),NULL); 
	
}

void CMy8_1View::OnMenuStart() 
{
	// TODO: Add your command handler code here
	if(view==1)
		AfxGetMainWnd() ->SetWindowPos(NULL,0,0,500,590,SWP_NOMOVE|SWP_NOZORDER );
	if(view==2)
		AfxGetMainWnd() ->SetWindowPos(NULL,0,0,253,510,SWP_NOMOVE|SWP_NOZORDER );
	player=1;
    start=true;
    russia.Start();
	SetTimer(1,50*(11-russia.m_Speed ),NULL);    
	
}

void CMy8_1View::OnMenuDstart() 
{
	// TODO: Add your command handler code here
	if(view==1)
		AfxGetMainWnd() ->SetWindowPos(NULL,0,0,1000,590,SWP_NOMOVE|SWP_NOZORDER );
	if(view==2)
		AfxGetMainWnd() ->SetWindowPos(NULL,0,0,510,510,SWP_NOMOVE|SWP_NOZORDER );
	player=2;
	start=true;
    russia.Start();
	Sleep(300);
	russia2.Start();
	SetTimer(1,50*(11-russia.m_Speed ),NULL);    
	
}

void CMy8_1View::OnMenuPause() 
{
	// TODO: Add your command handler code here
	m_bPause=!m_bPause;
	if(m_bPause)
		KillTimer(1);
	else
	{
		SetTimer(1,50*(11-russia.m_Speed ),NULL);   
		if(player==4)
		{
			if(net==1)
				SetTimer(1,50*(11-russia2.m_Speed ),NULL);    
			else
				SetTimer(1,50*(11-russia.m_Speed ),NULL);    
		}
	}
	
}

//void CMy8_1View::OnEditPaste() 
//{
	// TODO: Add your command handler code here
	
//}
void CMy8_1View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//下移
	if(player==1)
		russia.Move(3);
	if(player==2)
	{
		russia.Move(3);
		russia2.Move(3);
	}
	if(player==3)
	{
		russia0.Move(3);
		russia0.Move(7);
	}
	if(player==4)
	{
		russia.Move(3);
		russia2.Move(3);
	}
	OnDraw(GetDC());
	CView::OnTimer(nIDEvent);
}
void CMy8_1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
    //没有开始
	if(!start)
	{
		CRect rect;
		rect.left=170;
		rect.top=330;
		rect.right=340;
		rect.bottom=500;

		if(nChar==VK_DOWN)
		{
			if(ixuanze<4)
				ixuanze++;
			else
				ixuanze=1;
				InvalidateRect(&rect);
		}
		if(nChar==VK_UP)
		{
			if(ixuanze>1)
				ixuanze--;
			else
				ixuanze=4;
				InvalidateRect(&rect);
		}
		if(nChar==VK_SPACE)
		{	
			if(ixuanze==1)
				OnMenuStart();
			if(ixuanze==2)
				OnMenuDstart();
			if(ixuanze==3)
				OnMenuTstart();	
			if(ixuanze==4)
				OnNet();
		}
		return;
	}
    //暂停
   	if(m_bPause==TRUE)
		return;

	switch(nChar)
	{
	case VK_LEFT:
		russia.Move(1);russia0.Move(5);
		break;
	case VK_RIGHT:
		russia.Move(2);russia0.Move(6);
		break;		
	case VK_UP:
		russia.Move(4);russia0.Move(8);
		break;
	case VK_DOWN:
		russia.Move(3);russia0.Move(7);
		break;
	case 65:
		russia2.Move(1);russia0.Move(1);
		break;
	case 68:
		russia2.Move(2);russia0.Move(2);
		break;
	case 87:
		russia2.Move(4);russia0.Move(4);
		break;
	case 83:
		russia2.Move(3);russia0.Move(3);
		break;
	}
	//重画
/*//////////////////////////////////////////////
  if(player==4)
  {	   	
    	CMainFrame *pFrame=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	    char msg[10000];
        strcpy(msg,":");
		int i,j;

	if(pFrame->ynserver==1)
	{
//		for(i=0;i<4;i++)
//		  for(j=0;j<4;j++)
//		  {
//		     if(russia.Now[i][j]==0)
//			   strcat(msg,"0");
//            else
//			   strcat(msg,"1");
//          }
        for(i=0;i<4;i++)
		  for(j=0;j<4;j++)
		  {
		      if(russia.Will[i][j]==0)
			     strcat(msg,"0");
              else
			     strcat(msg,"1");
          }
		for(i=0;i<russia.m_RowCount;i++)
			for(j=0;j<russia.m_ColCount;j++)
			{
                if(russia.Russia[i][j]==0)
				  strcat(msg,"0");
                else
				  strcat(msg,"1");
             }

		char pMsg[10000];
		sprintf(pMsg,"%s",msg);
			CMy8_1App *App=( CMy8_1App * )AfxGetApp();
			if(App->pRequestSave!=NULL)
	    	pFrame->SendMsg(App->pRequestSave,pMsg);
		}
	 if(pFrame->ynserver==2)
		if(pFrame->m_pSocket)
		{
//		for(i=0;i<4;i++)
//		  for(j=0;j<4;j++)
//		  {
//		     if(russia.Now[i][j]==0)
//			   strcat(msg,"0");
//             else
//			   strcat(msg,"1");
//          }
        for(i=0;i<4;i++)
		  for(j=0;j<4;j++)
		  {
		      if(russia.Will[i][j]==0)
			     strcat(msg,"0");
              else
			     strcat(msg,"1");
          }
		for(i=0;i<russia.m_RowCount;i++)
			for(j=0;j<russia.m_ColCount;j++)
			{
                if(russia.Russia[i][j]==0)
				  strcat(msg,"0");
                else
				  strcat(msg,"1");
             }
    	char pMsg[10000];
		sprintf(pMsg,"%s",msg);
		CMy8_1App *App=( CMy8_1App * )AfxGetApp();
		pFrame->SendMsg(pFrame->m_pSocket,pMsg);
		}
  } 
*////////////////////////////////////////////////
	OnDraw(GetDC());
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
void CMy8_1View::OnUpdateMenuPause(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_bPause);
}
void CMy8_1View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(point.x>200&&point.x<340&&point.y>350&&point.y<510)
	{
		if(ixuanze==1)
			OnMenuStart();
		if(ixuanze==2)
			OnMenuDstart();
		if(ixuanze==3)
			OnMenuTstart();
		if(ixuanze==4)
			OnNet();
	}
	CView::OnLButtonDown(nFlags, point);
}
void CMy8_1View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(start)
		return;
	CRect rect;
	rect.left=170;
	rect.top=330;
	rect.right=340;
	rect.bottom=580;

	if(point.x>200&&point.x<350)
	{
		if(point.y>350&&point.y<390)
		{
			if(ixuanze!=1)
			{
				ixuanze=1;
				InvalidateRect(&rect);
			}
		}
		if(point.y>390&&point.y<430)
			if(ixuanze!=2)
			{
				ixuanze=2;
				InvalidateRect(&rect);
			}
		if(point.y>430&&point.y<470)
			if(ixuanze!=3)
			{
				ixuanze=3;
				InvalidateRect(&rect);
			}
		if(point.y>470&&point.y<510)
			if(ixuanze!=4)
			{
				ixuanze=4;
				InvalidateRect(&rect);
			}

	}
	CView::OnMouseMove(nFlags, point);
}

void CMy8_1View::OnNet() 
{
	// TODO: Add your command handler code here
    if(net>0)
	{
      russia2.Start();
    	SetTimer(1,50*(11-russia2.m_Speed ),NULL);    
      russia.Start();
      return;
//		delete m_pSocket;
//		m_pSocket=NULL;
	}

	/////////
 	CMainFrame *pFrame=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	pFrame->OnSorc();
	CMainFrame *pApp=(CMainFrame *)AfxGetApp();
    net=pFrame->ynserver;

	if(view==1)
		AfxGetMainWnd() ->SetWindowPos(NULL,0,0,1000,590,SWP_NOMOVE|SWP_NOZORDER );
	if(view==2)
		AfxGetMainWnd() ->SetWindowPos(NULL,0,0,510,510,SWP_NOMOVE|SWP_NOZORDER );
	player=4;
	start=true;
	if(net==1)
	{
      russia2.Start();
    	SetTimer(1,50*(11-russia2.m_Speed ),NULL);    
      russia.Start();
	}
	if(net==2)
	{
      russia.Start();
	SetTimer(1,50*(11-russia.m_Speed ),NULL);    
     russia2.Start();
	}

	Sleep(300);    
	
	
}

void CMy8_1View::OnContextMenu(CWnd*, CPoint point)
{

	// CG: This block was added by the Pop-up Menu component
	{
		if (point.x == -1 && point.y == -1){
			//keystroke invocation
			CRect rect;
			GetClientRect(rect);
			ClientToScreen(rect);

			point = rect.TopLeft();
			point.Offset(5, 5);
		}

		CMenu menu;
		VERIFY(menu.LoadMenu(CG_IDR_POPUP_MY8_1_VIEW));

		CMenu* pPopup = menu.GetSubMenu(0);
		ASSERT(pPopup != NULL);
		CWnd* pWndPopupOwner = this;

		while (pWndPopupOwner->GetStyle() & WS_CHILD)
			pWndPopupOwner = pWndPopupOwner->GetParent();

		pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y,
			pWndPopupOwner);
	}
}
