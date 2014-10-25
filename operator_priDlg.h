// operator_priDlg.h : header file
//

#if !defined(AFX_OPERATOR_PRIDLG_H__DF09C621_D04F_465D_9325_DF040E80836C__INCLUDED_)
#define AFX_OPERATOR_PRIDLG_H__DF09C621_D04F_465D_9325_DF040E80836C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COperator_priDlg dialog
#include "stack.h"
class COperator_priDlg : public CDialog
{
// Construction
public:
	void gy_eq();
	char get_up_lv_ch_center(char ch);
	int get_pri();
	char get_up_lv_ch(char ch);
	void gy();
	void move_in();
	char get_first_ter();
	bool is_ter(char ch);
	bool is_non_ter(char ch);
	char** m_ppritbl;
	int get_index(char* buffer,char ch);
	char** m_non_ter_op_g;
	unsigned int m_non_ter_op_len;
	chara_list* m_lastVT_list;
	chara_list* m_firstVT_list;
	char* m_non_op;
	char* m_ter_op;
	bool is_ter_op(char* non_ter_op,char ch);
	char* final_op;
	char* g_buffer;
	stack* m_stk_ch;
	stack* m_stk_input;
	COperator_priDlg(CWnd* pParent = NULL);	// standard constructor

	CString str_ch_stk;
	CString str_input_stk;
	CString str_action_stk;
// Dialog Data
	//{{AFX_DATA(COperator_priDlg)
	enum { IDD = IDD_OPERATOR_PRI_DIALOG };
	CListCtrl	m_list_final;
	CListCtrl 	m_list_lastVT;
	CListCtrl 	m_op_pri_list;
	CListCtrl 	m_list_firstVT;
	CString	m_LANG;
	CString	m_LANG_PATH;
	CString	m_TERMINAL_LIST;
	CString	m_NON_TERMINAL_LIST;
	CString	m_sentence;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COperator_priDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COperator_priDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonOpenG();
	afx_msg void OnButtonAnalysis();
	afx_msg void OnButtonMakeList();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonClean();
	afx_msg void OnButtonStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPERATOR_PRIDLG_H__DF09C621_D04F_465D_9325_DF040E80836C__INCLUDED_)
