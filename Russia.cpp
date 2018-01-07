// Russia.cpp: implementation of the CRussia class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "main.h"
#include "Russia.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRussia::CRussia()
{
	jiemian.LoadBitmap(IDB_BITMAP2);
	fangkuai.LoadBitmap(IDB_BITMAP4);
	fangkuai2.LoadBitmap(IDB_BITMAP6);
    jiemian2.LoadBitmap(IDB_BITMAP5); 

}

CRussia::~CRussia()
{

}

void CRussia::Start()
{
	end=false;//运行结束标志
    m_Score=0;		//初始分数
	m_Speed=0;		//初始速度
	m_Level=0;		//初始难度
	m_RowCount=18;	//行数
	m_ColCount=12;	//列数
	Count=7;		//方块种类

	for(int i=0;i<m_RowCount;i++)
		for(int j=0;j<m_ColCount;j++)
		{
			Russia[i][j]=0;
		}

	for(i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			Now[i][j]=0;
			Will[i][j]=0;
		}
    //Will[][]
	DrawWill();
	Sleep(500);
	//Now[][]&Will[][]
	DrawWill();

}
void CRussia::DrawJiemian1(int a,int b,CDC*pDC)
{	
	CDC Dc;
	if(Dc.CreateCompatibleDC(pDC)==FALSE)
		AfxMessageBox("Can't create DC");
	//画背景
    Dc.SelectObject(jiemian);
	pDC->BitBlt(a,b,500,550,&Dc,0,0,SRCCOPY);

    //画分数，速度，难度
	int nOldDC=pDC->SaveDC();	
	//设置字体
	CFont font;    
	if(0==font.CreatePointFont(300,"Comic Sans MS"))
					{
						AfxMessageBox("Can't Create Font");
					}
	pDC->SelectObject(&font);
    //设置字体颜色及其背景颜色
	CString str;
	pDC->SetTextColor(RGB(39,244,10));
	pDC->SetBkColor(RGB(255,255,0));
    //输出数字
	str.Format("%d",m_Level);
	if(m_Level>=0)
		pDC->TextOut(a+440,b+120,str);

	str.Format("%d",m_Speed);	
	if(m_Speed>=0)	
		pDC->TextOut(a+440,b+64,str);

	str.Format("%d",m_Score);	
	if(m_Score>=0)
		pDC->TextOut(a+440,b+2,str);

	pDC->RestoreDC(nOldDC);

//	DrawScore(pDC);
    //如果有方块，显示方块
	//游戏区
	for(int i=0;i<m_RowCount;i++)
		for(int j=0;j<m_ColCount;j++)
			if(Russia[i][j]==1)
			{
				Dc.SelectObject(fangkuai);
				pDC->BitBlt(a+j*30,b+i*30,30,30,&Dc,0,0,SRCCOPY);
			}
    //预先图形
	for(int n=0;n<4;n++)
		for(int m=0;m<4;m++)
			if(Will[n][m]==1)
			{	
				Dc.SelectObject(fangkuai);
				pDC->BitBlt(a+365+m*30,b+240+n*30,30,30,&Dc,0,0,SRCCOPY);
			}
}

void CRussia::DrawJiemian2(int a,int b,CDC*pDC)
{	
	CDC Dc;
	if(Dc.CreateCompatibleDC(pDC)==FALSE)
		AfxMessageBox("Can't create DC");
	//画背景
    Dc.SelectObject(jiemian2);
	pDC->BitBlt(a,b,240,460,&Dc,0,0,SRCCOPY);

    //画分数，速度，难度
    //设置字体颜色及其背景颜色
	CString str;
	pDC->SetTextColor(RGB(198,24,190));
	pDC->SetBkColor(RGB(255,255,0));
    //输出数字
	str.Format("%d",m_Level);
	if(m_Level>=0)
		pDC->TextOut(a+50,b+70,str);

	str.Format("%d",m_Speed);	
	if(m_Speed>=0)	
		pDC->TextOut(a+50,b+42,str);

	str.Format("%d",m_Score);	
	if(m_Score>=0)
		pDC->TextOut(a+50,b+12,str);

    //如果有方块，显示方块
	//游戏区
	for(int i=0;i<m_RowCount;i++)
		for(int j=0;j<m_ColCount;j++)
			if(Russia[i][j]==1)
			{
				Dc.SelectObject(fangkuai2);
				pDC->BitBlt(a+j*20,b+100+i*20,30,30,&Dc,0,0,SRCCOPY);
			}
    //预先图形
	for(int n=0;n<4;n++)
		for(int m=0;m<4;m++)
			if(Will[n][m]==1)
			{	
				Dc.SelectObject(fangkuai2);
				pDC->BitBlt( a+120+m*20,b+10+n*20,30,30,&Dc,0,0,SRCCOPY);
			}
}
void CRussia::DrawWill()
{
	int i,j;
	int k=4,l=4;

    //把将要出现的方块给当前数组，并把将要出现数组赋值为零
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			Now[i][j]=Will[i][j];
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
//适应于难度扩展
/*	case 7:
		Will[0][0]=1;
		Will[1][0]=1;
		Will[1][1]=1;
		Will[1][2]=1;
		Will[0][2]=1;
		break;
	case 8:
		Will[0][0]=1;
		Will[1][0]=1;
		Will[2][0]=1;
		Will[1][1]=1;
		Will[1][2]=1;
		break;
*/
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
	NowPosition.x=0;
	NowPosition.y=m_ColCount/2;

}



//是否遇到了边界或者有其他方块档住了
bool CRussia::Meet(int a[][4],int direction,CPoint p)
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
			switch(direction)
			{
			case 1:	//左移
				if((p.y+j-1)<0) goto exit;
				if(Russia[p.x+i][p.y+j-1]==1) goto exit;
				break;
			case 2://右移
				if((p.y+j+1)>=m_ColCount) goto exit;
				if(Russia[p.x+i][p.y+j+1]==1) goto exit;
				break;
			case 3://下移
				if((p.x+i+1)>=m_RowCount) goto exit;
				if(Russia[p.x+i+1][p.y+j]==1) goto exit;
				break;
			case 4://变换
				if(!Change(a,p,Russia)) goto exit;				
				for(i=0;i<4;i++)
					for(j=0;j<4;j++)
					{
						Now[i][j]=After[i][j];
						a[i][j]=Now[i][j];
					}
				return false;
				break;
			}
		}
	int x,y;
	x=p.x;
	y=p.y;
	//移动位置，重新给数组赋值
	switch(direction)
	{
	case 1:
		y--;break;
	case 2:
		y++;break;
	case 3:
		x++;break;
	case 4:
		break;
	}
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(a[i][j]==1)
				Russia[x+i][y+j]=1;

	return false;
exit:
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(a[i][j]==1)
				Russia[p.x+i][p.y+j]=1;
	return true;
}

//转换
bool CRussia::Change(int a[][4], CPoint p,int  b[][100])
{
	int tmp[4][4];
	int i,j;
	int k=4,l=4;

	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			tmp[i][j]=a[j][3-i];
			After[i][j]=0;	//存放变换后的方块矩阵
		}
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(tmp[i][j]==1)
			{
				if(k>i) k=i;
				if(l>j) l=j;
			}
	for(i=k;i<4;i++)
		for(j=l;j<4;j++)
		{
			After[i-k][j-l]=tmp[i][j];
		}	//把变换后的矩阵移到左上角

		//判断是否接触，是：返回失败
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{	
			if(After[i][j]==0) continue;
			if(((p.x+i)>=m_RowCount)||((p.y+j)<0)||((p.y+j)>=m_ColCount)) return false;
			if(b[p.x+i][p.y+j]==1)
				return false;
		}
	return true;
}


void CRussia::Move(int direction)
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
			LineDelete();	
//			DrawWill();
			break;
		}
		NowPosition.x++;
		break;
		//上
	case 4:
		Meet(Now,4,NowPosition);
		break;
	default:
		break;
	}

}
//消去行
void CRussia::LineDelete()
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
			{
				//上行给下行
				for(int l=0;l<m_ColCount;l++)
				{
					Russia[k][l]=Russia[k-1][l];
				}
			}
			//第一行为零
			for(int l=0;l<m_ColCount;l++)
			{
				Russia[0][l]=0;
			}
		}
	}
    
	DrawWill();


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
	m_Speed=m_Score/100;
	m_Level=m_Speed;
	for(i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(Now[i][j]==1)
				//到了顶点
				if(Russia[i+NowPosition.x][j+NowPosition.y]==1)
				{
					end=true;
					AfxMessageBox("游戏结束！");
					return;
				}

}
