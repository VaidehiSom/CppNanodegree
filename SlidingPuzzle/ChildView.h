
// ChildView.h : interface of the CChildView class
//

#pragma once
#include "SlidingPuzzleDocument.h"

// CChildView window

class CChildView : public CWnd
{
	public:
		// Construction
		CChildView(CSlidingPuzzleDocument *pDocument);
		virtual ~CChildView(); // Overrides
		// Operations
		void GameOver();
		// Generated message map function
		afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

	
	protected:
		// Overrides
		virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
		// Generated message map functions
		afx_msg void OnPaint();
		DECLARE_MESSAGE_MAP()

	private:
		CSlidingPuzzleDocument *m_pDocument;	
};

