// SCDemoDlg.h : header file
// any questions or suggesstion, pls contact MSN: (dxtou@hotmail.com)

#if !defined(AFX_SCDEMODLG_H__33636AF0_1C8D_47C4_9EE6_9FC703DBAE2A__INCLUDED_)
#define AFX_SCDEMODLG_H__33636AF0_1C8D_47C4_9EE6_9FC703DBAE2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SCStkDrv.h"
#include "LoadDll.h"
#include ".\kthread.h"

/////////////////////////////////////////////////////////////////////////////
// CSCDemoDlg dialog

class CSCDemoDlg : public CDialog
{
protected:
	struct TMLink {
		SCMarket *m_pm;
		TMLink *m_pNext;
	};

// Construction
public:
	CSCDemoDlg(CWnd* pParent = NULL);	// standard constructor
	~CSCDemoDlg();
    bool start_flage;
	bool test_flage;
	CString fdata;
	CString fdata1;
	CString fdata2;
	CString fdata3;
// Dialog Data
	//{{AFX_DATA(CSCDemoDlg)
	enum { IDD = IDD_SCDEMO_DIALOG };
	CEdit	m_editData;
	CTreeCtrl	m_treeStock;
	CListBox	m_lstTitle;
	CListBox	m_lstFunc;
	CString	m_strData;
	int		m_nLstFunc;
	int		m_nLstTitle;
	CTime	m_dateStart;
	CTime	m_dateEnd;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSCDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSCDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeListFunc();
	afx_msg void OnSelchangeListTitle();
	afx_msg void OnSelchangedTreeStock(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClearPrevAsk();
	afx_msg void OnUsername();
	//}}AFX_MSG
	afx_msg LRESULT OnReply(WPARAM wParam, LPARAM lParam);		//新接口消息处理
	DECLARE_MESSAGE_MAP()

protected:
	BOOL _AddMarket2Link(SCMarket *pm);
	void _DeleteMLink();
	SCMarket *_GetMarket(WORD wMarket);
	TMLink *_GetMarketLnk(WORD wMarket);

	void _InitTree();
	void _SCAskData();

protected:
	TMLink					*m_pMLHead, *m_pMLTail;
	long					m_lAskIndex;
	long					m_lLastNow;
	CLoadDll				m_Dll;
	BOOL					m_bIMTitle;
	SCIMTitle				*m_pIMTitle;
	int						m_nIMCnt;
	char					m_cClass;
	long					m_lClassDate;
    CKThread                m_CKThread;
	//CKThread                m_CKThread1;
	//CKThread                m_CKThread2;
	UINT_PTR                m_timer;
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnTimer(UINT nIDEvent);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCDEMODLG_H__33636AF0_1C8D_47C4_9EE6_9FC703DBAE2A__INCLUDED_)
