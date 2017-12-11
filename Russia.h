// Russia.h: interface for the CRussia class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RUSSIA_H__CCAB5FC1_E41F_11D5_B2C4_5254AB2BD63E__INCLUDED_)
#define AFX_RUSSIA_H__CCAB5FC1_E41F_11D5_B2C4_5254AB2BD63E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRussia  
{
public:

	CRussia();
	virtual ~CRussia();
	void LineDelete();
	void Move(int direction);
	bool Change(int a[][4],CPoint p,int  b[][100]);
	bool Meet(int a[][4],int direction,CPoint p);
	void DrawWill();
	void DrawJiemian1(int a,int b,CDC*pDC);
	void DrawJiemian2(int a,int b,CDC*pDC);
	void Start();

	int Russia[100][100];//游戏数组
	int Now[4][4];	// 当前图形
	int Will[4][4];	//上一图形
	int After[4][4];	//变换后的图形
	CPoint NowPosition;	//当前图形的左上角位置
	int Count;		//当前可能出现的图形形状数,
	bool end;  //游戏结束
	int m_Level;	//级别
	int m_Speed;	//速度
	int m_Score;    //分数
	int m_RowCount,m_ColCount;//行列数
	CBitmap fangkuai;//方块
	CBitmap jiemian;//背景
    CBitmap jiemian2;
	CBitmap fangkuai2;


};

#endif // !defined(AFX_RUSSIA_H__CCAB5FC1_E41F_11D5_B2C4_5254AB2BD63E__INCLUDED_)
