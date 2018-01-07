// Russia0.cpp: implementation of the CRussia0 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "main.h"
#include "Russia0.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRussia0::CRussia0()
{
	jiemian0.LoadBitmap(IDB_BITMAP11);


}

CRussia0::~CRussia0()
{

}

void CRussia0::DrawJiemian(CDC *pDC)
{
	CDC Dc;
	if(Dc.CreateCompatibleDC(pDC)==FALSE)
		AfxMessageBox("Can't create DC");
	//画背景
    Dc.SelectObject(jiemian0);
	pDC->BitBlt(0,0,500,600,&Dc,0,0,SRCCOPY);

    //画分数，速度，难度
    //设置字体颜色及其背景颜色
	CString str;
	pDC->SetTextColor(RGB(198,24,190));
	pDC->SetBkColor(RGB(255,255,0));
    //输出数字
	str.Format("%d",m_Level);
	if(m_Level>=0)
		pDC->TextOut(80,70,str);

	str.Format("%d",m_Speed);	
	if(m_Speed>=0)	
		pDC->TextOut(80,42,str);

	str.Format("%d",m_Score);	
	if(m_Score>=0)
		pDC->TextOut(80,12,str);

    //如果有方块，显示方块
	//游戏区
	for(int i=0;i<m_RowCount;i++)
		for(int j=0;j<m_ColCount;j++)
			if(Russia[i][j]==1)
			{
				Dc.SelectObject(fangkuai2);
				pDC->BitBlt(j*20,100+i*20,30,30,&Dc,0,0,SRCCOPY);
			}
    //预先图形
	for(int n=0;n<4;n++)
		for(int m=0;m<4;m++)
			if(Will[n][m]==1)
			{	
				Dc.SelectObject(fangkuai2);
				pDC->BitBlt( 220+m*20,10+n*20,30,30,&Dc,0,0,SRCCOPY);
			}

}

void CRussia0::Start()
{
	end=false;//运行结束标志
    m_Score=0;		//初始分数
	m_Speed=0;		//初始速度
	m_Level=0;		//初始难度
	m_RowCount=25;	//行数
	m_ColCount=25;	//列数
	Count=7;		//方块种类

	for(int i=0;i<m_RowCount;i++)
		for(int j=0;j<m_ColCount;j++)
		{
			Russia[i][j]=0;
		}

	for(i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			Now0[i][j]=0;
			Now[i][j]=0;
			Will[i][j]=0;
		}
    //Will[][]
 	DrawWill(Now0);
	DrawWill(Now);
	Sleep(500);
	//Now[][]&Will[][]
	DrawWill(Now);
 	DrawWill(Now0);

}

void CRussia0::DrawWill(int a[][4])
{
	int i,j;
	int k=4,l=4;

    //把将要出现的方块给当前数组，并把将要出现数组赋值为零
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			a[i][j]=Will[i][j];
			Will[i][j]=0;
		}
	//初始化随即数种子
	srand(GetTickCount());
	int nTemp=rand()%Count;
	//各种图形
	switch(nTemp)
	{
	case 0:
		Will[0][0]=1;
		Will[0][1]=1;
		Will[1][0]=1;
		Will[1][1]=1;
		break;
	case 1:
		Will[0][0]=1;
		Will[0][1]=1;
		Will[1][0]=1;
		Will[2][0]=1;
		break;
	case 2:
		Will[0][0]=1;
		Will[0][1]=1;
		Will[1][1]=1;
		Will[2][1]=1;
		break;
	case 3:
		Will[0][1]=1;
		Will[1][0]=1;
		Will[1][1]=1;
		Will[2][0]=1;
		break;
	case 4:
		Will[0][0]=1;
		Will[1][0]=1;
		Will[1][1]=1;
		Will[2][1]=1;
		break;
	case 5:
		Will[0][0]=1;
		Will[1][0]=1;
		Will[1][1]=1;
		Will[2][0]=1;
		break;
	case 6:
		Will[0][0]=1;
		Will[1][0]=1;
		Will[2][0]=1;
		Will[3][0]=1;
		break;

	}

	int tmp[4][4];
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			tmp[i][j]=Will[j][3-i];

	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(tmp[i][j]==1)
			{
				if(k>i) k=i;
				if(l>j) l=j;
			}

	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			Will[i][j]=0;
	//把变换后的矩阵移到左上角
	for(i=k;i<4;i++)
		for(j=l;j<4;j++)
			Will[i-k][j-l]=tmp[i][j];

    //开始位置
	if(a==Now)
	{
		NowPosition.x=0;
		NowPosition.y=m_ColCount/4;
	}
	if(a==Now0)
	{
		NowPosition0.x=0;
		NowPosition0.y=3*m_ColCount/4;
	}


}

void CRussia0::Move(int direction)
{
	if(end) return;

	switch(direction)
	{
		//左
	case 1:
		if(Meet(Now,1,NowPosition)) break;
		NowPosition.y--;
		break;
		//右
	case 2:
		if(Meet(Now,2,NowPosition)) break;
		NowPosition.y++;
		break;
		//下
	case 3:
		if(Meet(Now,3,NowPosition))
		{
			LineDelete(Now);	
			break;
		}
		NowPosition.x++;
		break;
		//上
	case 4:
		Meet(Now,4,NowPosition);
		break;
			//左
	case 5:
		if(Meet(Now0,1,NowPosition0)) break;
		NowPosition0.y--;
		break;
		//右
	case 6:
		if(Meet(Now0,2,NowPosition0)) break;
		NowPosition0.y++;
		break;
		//下
	case 7:
		if(Meet(Now0,3,NowPosition0))
		{
			LineDelete(Now0);	
			break;
		}
		NowPosition0.x++;
		break;
		//上
	case 8:
		Meet0(Now0,8,NowPosition0);
		break;
	default:
		break;
	}

}

bool CRussia0::Meet0(int a[][4], int direction, CPoint p)
{
	int i,j;
	//先把原位置清0 
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(a[i][j]==1)
				Russia[p.x+i][p.y+j]=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(a[i][j]==1)
			{
				if(!Change(a,p,Russia)) 
				{
					for(i=0;i<4;i++)
						for(j=0;j<4;j++)
							if(a[i][j]==1)
								Russia[p.x+i][p.y+j]=1;
					return true;
				}				
				for(i=0;i<4;i++)
				for(j=0;j<4;j++)
					{
						Now0[i][j]=After[i][j];
						a[i][j]=Now0[i][j];
					}
				return false;			
			}
	return true;

}

void CRussia0::LineDelete(int a[][4])
{
	int m=0;		//本次共消去的行数
	bool flag=0;
	for(int i=0;i<m_RowCount;i++)
	{
		//检查要不要消行
		flag=true;
		for(int j=0;j<m_ColCount;j++)
			if(Russia[i][j]==0)
				flag=false;
		//如果要
		if(flag==true)
		{
			m++;
			for(int k=i;k>0;k--)
			//上行给下行
				for(int l=0;l<m_ColCount;l++)
					Russia[k][l]=Russia[k-1][l];
			//第一行为零
			for(int l=0;l<m_ColCount;l++)
				Russia[0][l]=0;			
		}
	}
    
	DrawWill(a);

	//加分
	switch(m)
	{
	case 1:
		m_Score++;
		break;
	case 2:
		m_Score+=3;
		break;
	case 3:
		m_Score+=6;
		break;
	case 4:
		m_Score+=10;
		break;
	default:
		break;
	}

	//速度
	m_Speed=m_Score/50;
	m_Level=m_Speed;
	for(i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			if(Now[i][j]==1&&a==Now0)
				//到了顶点
				if(Russia[i+NowPosition0.x][j+NowPosition0.y]==1)
				{
					end=true;
					AfxMessageBox("游戏结束！");
					return;
				}
			if(Now0[i][j]==1&&a==Now)
				if(Russia[i+NowPosition.x][j+NowPosition.y]==1)
				{
					end=true;
					AfxMessageBox("游戏结束！");
					return;
				}
		}
}
