// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "ChildView.h"
#include "SlidingPuzzle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildView

CChildView::CChildView(CSlidingPuzzleDocument *pDocument) : m_pDocument(pDocument) {
	ASSERT(pDocument != NULL);
}

CChildView::~CChildView() {}

BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	CFont font;
	font.CreatePointFont(180, TEXT("Times New Roman"), &dc);
	CFont *pDefFont = dc.SelectObject(&font);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			dc.Rectangle(CRect(m_pDocument->GetTile(i, j).tilePos, CSize(CTile::width, CTile::height)));
			if (m_pDocument->GetTile(i, j).number == 0)
				continue;
			CString s;
			s.Format(TEXT("%d"), m_pDocument->GetTile(i, j).number);
			dc.DrawText(s, CRect(m_pDocument->GetTile(i, j).tilePos, CSize(CTile::width, CTile::height)), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}

	dc.SelectObject(pDefFont);
}

void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// Message handler code
	switch (nChar) 
	{
		case VK_DOWN:
			m_pDocument->Slide(Up);
			break;
		case VK_LEFT:
			m_pDocument->Slide(Right);
			break;
		case VK_RIGHT:
			m_pDocument->Slide(Left);
			break;
		case VK_UP:
			m_pDocument->Slide(Down);
			break;
	}
	Invalidate();
}

void CChildView::GameOver() 
{
	// Game over
	MessageBox(TEXT("You Won the Game!!!"));
}
