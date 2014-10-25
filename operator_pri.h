// operator_pri.h : main header file for the OPERATOR_PRI application
//

#if !defined(AFX_OPERATOR_PRI_H__DDAF6840_45B4_4478_ADCE_7D45CFFF8ECB__INCLUDED_)
#define AFX_OPERATOR_PRI_H__DDAF6840_45B4_4478_ADCE_7D45CFFF8ECB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "chara_list.h"	// Added by ClassView

/////////////////////////////////////////////////////////////////////////////
// COperator_priApp:
// See operator_pri.cpp for the implementation of this class
//

class COperator_priApp : public CWinApp
{
public:
	COperator_priApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COperator_priApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COperator_priApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPERATOR_PRI_H__DDAF6840_45B4_4478_ADCE_7D45CFFF8ECB__INCLUDED_)
