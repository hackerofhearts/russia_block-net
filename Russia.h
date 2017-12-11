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

	int Russia[100][100];//��Ϸ����
	int Now[4][4];	// ��ǰͼ��
	int Will[4][4];	//��һͼ��
	int After[4][4];	//�任���ͼ��
	CPoint NowPosition;	//��ǰͼ�ε����Ͻ�λ��
	int Count;		//��ǰ���ܳ��ֵ�ͼ����״��,
	bool end;  //��Ϸ����
	int m_Level;	//����
	int m_Speed;	//�ٶ�
	int m_Score;    //����
	int m_RowCount,m_ColCount;//������
	CBitmap fangkuai;//����
	CBitmap jiemian;//����
    CBitmap jiemian2;
	CBitmap fangkuai2;


};

#endif // !defined(AFX_RUSSIA_H__CCAB5FC1_E41F_11D5_B2C4_5254AB2BD63E__INCLUDED_)
