
// MainFrm.h : interface of the CMainFrame class
//

#pragma once
#include "ChildView.h"

class CMainFrame : public CFrameWnd
{
	public:
		CMainFrame() noexcept;
		// Overrides
		virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
		virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

		// Implementation
		virtual ~CMainFrame();
		#ifdef _DEBUG
			virtual void AssertValid() const;
			virtual void Dump(CDumpContext& dc) const;
		#endif

		CChildView m_wndView;
		CSlidingPuzzleDocument m_document;

	protected:
		DECLARE_DYNAMIC(CMainFrame)
		// Generated message map functions
		afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
		afx_msg void OnSetFocus(CWnd *pOldWnd);
		DECLARE_MESSAGE_MAP()
};


