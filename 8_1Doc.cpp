// 8_1Doc.cpp : implementation of the CMy8_1Doc class
//

#include "stdafx.h"
#include "8_1.h"

#include "8_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy8_1Doc

IMPLEMENT_DYNCREATE(CMy8_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy8_1Doc, CDocument)
	//{{AFX_MSG_MAP(CMy8_1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy8_1Doc construction/destruction

CMy8_1Doc::CMy8_1Doc()
{
	// TODO: add one-time construction code here

}

CMy8_1Doc::~CMy8_1Doc()
{
}

BOOL CMy8_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMy8_1Doc serialization

void CMy8_1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMy8_1Doc diagnostics

#ifdef _DEBUG
void CMy8_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy8_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy8_1Doc commands
