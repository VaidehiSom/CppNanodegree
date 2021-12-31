
// SlidingPuzzle.h : main header file for the SlidingPuzzle application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSlidingPuzzleApp:
// See SlidingPuzzle.cpp for the implementation of this class
//

class CSlidingPuzzleApp : public CWinApp
{
	public:
		CSlidingPuzzleApp() noexcept;

		// Overrides
		virtual BOOL InitInstance();
		virtual int ExitInstance();

		// Implementation
		afx_msg void OnAppAbout();
		DECLARE_MESSAGE_MAP()
};

extern CSlidingPuzzleApp theApp;
