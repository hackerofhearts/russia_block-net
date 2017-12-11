/*// Russia0.h: interface for the CRussia0 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RUSSIA0_H__CCAB5FC2_E41F_11D5_B2C4_5254AB2BD63E__INCLUDED_)
#define AFX_RUSSIA0_H__CCAB5FC2_E41F_11D5_B2C4_5254AB2BD63E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Russia.h"

class CRussia0 : public CRussia  
{
public:
	CRussia0();
	virtual ~CRussia0();
	void LineDelete(int a[][4]);
    bool Meet0(int a[][4],int direction,CPoint p);
	void Move(int direction);
	void DrawWill(int a[][4]);
	void Start();
	void DrawJiemian(CDC*pDC);

	CPoint NowPosition0;//第二个活动位置
	int Now0[4][4];//第二个活动方块
	CBitmap jiemian0;//背景

};

#endif // !defined(AFX_RUSSIA0_H__CCAB5FC2_E41F_11D5_B2C4_5254AB2BD63E__INCLUDED_)
*/