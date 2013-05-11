// SCDemo.h : main header file for the SCDEMO application
// any questions or suggesstion, pls contact MSN: (dxtou@hotmail.com)

#if !defined(AFX_SCDEMO_H__7069185D_20B5_42FD_985D_E9E5EFF62DC0__INCLUDED_)
#define AFX_SCDEMO_H__7069185D_20B5_42FD_985D_E9E5EFF62DC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSCDemoApp:
// See SCDemo.cpp for the implementation of this class
//

class CSCDemoApp : public CWinApp
{
public:
	CSCDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSCDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSCDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCDEMO_H__7069185D_20B5_42FD_985D_E9E5EFF62DC0__INCLUDED_)
