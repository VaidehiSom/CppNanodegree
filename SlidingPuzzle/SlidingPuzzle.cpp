
// SlidingPuzzle.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "SlidingPuzzle.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSlidingPuzzleApp

BEGIN_MESSAGE_MAP(CSlidingPuzzleApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CSlidingPuzzleApp::OnAppAbout)
END_MESSAGE_MAP()


// CSlidingPuzzleApp construction

CSlidingPuzzleApp::CSlidingPuzzleApp() noexcept
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
	#ifdef _MANAGED
		// If the application is built using Common Language Runtime support (/clr):
		//     1) This additional setting is needed for Restart Manager support to work properly.
		//     2) In project, one must add a reference to System.Windows.Forms in order to build.
		System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif
	SetAppID(_T("SlidingPuzzle.AppID.NoVersion"));
}

// The only CSlidingPuzzleApp object
CSlidingPuzzleApp theApp;


// CSlidingPuzzleApp initialization

BOOL CSlidingPuzzleApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Setting to include all the common control classes one wants to use in our application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	// To create the main window, this code creates a new frame window
	// object and then sets it as the application's main window object
	CFrameWnd* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// create and load the frame with its resources
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, nullptr,
		nullptr);

	// The one and only window has been initialized, show and update it
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

int CSlidingPuzzleApp::ExitInstance()
{
	AfxOleTerm(FALSE);
	return CWinApp::ExitInstance();
}

class CAboutDlg : public CDialogEx
{
	public:
		CAboutDlg() noexcept;
		// Dialog Data
		#ifdef AFX_DESIGN_TIME
			enum { IDD = IDD_ABOUTBOX };
		#endif

	protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		// Implementation
		DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX) {}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

void CSlidingPuzzleApp::OnAppAbout()
{
	// run the dialog
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}



