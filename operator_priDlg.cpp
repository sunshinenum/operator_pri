// operator_priDlg.cpp : implementation file
//

#include "stdafx.h"
#include "operator_pri.h"
#include "operator_priDlg.h"
#include <Atlbase.h>
#include "chara_list.h"
#include "string.h"
#include "stack.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COperator_priDlg dialog

COperator_priDlg::COperator_priDlg(CWnd* pParent /*=NULL*/)
: CDialog(COperator_priDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COperator_priDlg)
	m_LANG = _T("");
	m_LANG_PATH = _T("");
	m_TERMINAL_LIST = _T("");
	m_NON_TERMINAL_LIST = _T("");
	m_sentence = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COperator_priDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COperator_priDlg)
	DDX_Control(pDX, IDC_LIST_FINAL, m_list_final);
	DDX_Control(pDX, IDC_LIST_LAST_VT, m_list_lastVT);
	DDX_Control(pDX, IDC_LIST_OP_PRI_LIST, m_op_pri_list);
	DDX_Control(pDX, IDC_LIST_FIRSTVT, m_list_firstVT);
	DDX_Text(pDX, IDC_EDIT_G, m_LANG);
	DDX_Text(pDX, IDC_EDIT_G_PATH, m_LANG_PATH);
	DDX_Text(pDX, IDC_EDIT_TERMINAL_LIST, m_TERMINAL_LIST);
	DDX_Text(pDX, IDC_EDIT_NON_TERMINAL_LIST, m_NON_TERMINAL_LIST);
	DDV_MaxChars(pDX, m_NON_TERMINAL_LIST, 100);
	DDX_Text(pDX, IDC_EDIT_SENTENCE, m_sentence);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COperator_priDlg, CDialog)
//{{AFX_MSG_MAP(COperator_priDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON_OPEN_G, OnButtonOpenG)
ON_BN_CLICKED(IDC_BUTTON_ANALYSIS, OnButtonAnalysis)
ON_BN_CLICKED(IDC_BUTTON_MAKE_LIST, OnButtonMakeList)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_CLEAN, OnButtonClean)
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COperator_priDlg message handlers

BOOL COperator_priDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: FirstVT,LastVT��
	m_list_firstVT.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	
	m_list_firstVT.InsertColumn(0, _T("���ս��"), LVCFMT_LEFT, 70);
	m_list_firstVT.InsertColumn(1, _T("FirstVT��"), LVCFMT_LEFT, 156);
	m_list_lastVT.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list_lastVT.InsertColumn(0,_T("���ս��"),LVCFMT_LEFT,70);
	m_list_lastVT.InsertColumn(1, _T("LastVT��"), LVCFMT_LEFT, 156);
	m_list_final.InsertColumn(0,_T("����ջ"),LVCFMT_LEFT, 100);
	m_list_final.InsertColumn(1,_T("���봮"),LVCFMT_LEFT, 100);
	m_list_final.InsertColumn(2,_T("����"),LVCFMT_LEFT, 69);
	m_list_final.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//ָ���ʼ��
	m_ppritbl=NULL;
	m_non_ter_op_g=NULL;
	m_lastVT_list=NULL;
	m_firstVT_list=NULL;
	m_non_op=NULL;
	m_ter_op=NULL;
	final_op=NULL;
	g_buffer=NULL;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COperator_priDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COperator_priDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COperator_priDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void COperator_priDlg::OnButtonOpenG() 
{
	// TODO: ���ķ��ļ�����ʾ��
	CFileDialog dlg(TRUE);
	dlg.m_ofn.lpstrTitle=_T("���ķ��ļ�");
	if (IDOK==dlg.DoModal())
	{
		CFile file(dlg.GetPathName(),CFile::modeRead);
		DWORD flen=file.GetLength();
		g_buffer=new char[flen+3];

		file.Read(g_buffer,flen);
		g_buffer[flen]=0;
		//�ķ��Ϸ����ж�,��β�޻����Զ����
		if (g_buffer[flen]!=10)
		{
			g_buffer[flen]=13;
			g_buffer[flen+1]=10;
			g_buffer[flen+2]=0;
		}

		m_LANG=g_buffer;
		m_LANG_PATH=file.GetFilePath();
		file.Close();
		UpdateData(FALSE);
	}
}

void COperator_priDlg::OnButtonAnalysis() 
{
	// TODO:�����ķ�
	UpdateData(TRUE);

	int i=0,non_op_num=0;//����ս����Ŀ
	for (i=0;i<strlen(g_buffer);i++)
	{
		if (g_buffer[i]=='>')
		{
			non_op_num++;
		}
	}
	m_non_op=new char[non_op_num+1];
	memset(m_non_op,0,non_op_num+1);
	//�ķ��ָ�
	this->m_non_ter_op_len=non_op_num;
	this->m_non_ter_op_g=new char*[m_non_ter_op_len];
	for (int ii=0;ii<non_op_num;ii++)
	{
		m_non_ter_op_g[ii]=NULL;
		m_non_ter_op_g[ii]=new char[32];
		memset(m_non_ter_op_g[ii],0,32);
	}
	int tp_index=0;
	int tp_non_index=0;
	for (int it=0;it<strlen(g_buffer);it++)
	{
		if (g_buffer[it]=='>')
		{
			tp_index=it;
			while(g_buffer[tp_index]!=13)
			{
				tp_index++;
			}
			memcpy(m_non_ter_op_g[tp_non_index],g_buffer+it+1,tp_index-it-1);
			tp_non_index++;
		}
	}
	//���ս���������飬��������ַ���
	int j=0;
	
	for (int ik=0;ik<strlen(g_buffer);ik++)
	{
		if (g_buffer[ik]=='>')
		{
			m_non_op[j]=g_buffer[ik-1];
			j++;
		}
	}
	m_non_op[j]=0;


	m_NON_TERMINAL_LIST=m_non_op;

	
	//���ս����Ŀ
	int k=0;
	for(i=0;i<strlen(g_buffer);i++)
	{
		if (is_ter_op(m_non_op,g_buffer[i]))
		{
			k++;
		}
	}
	m_ter_op=new char[k+1];
	memset(m_ter_op,0,k+1);
	//�ս���������飬���½����ַ���
	k=0;
	for(i=0;i<strlen(g_buffer);i++)
	{
		if (is_ter_op(m_non_op,g_buffer[i])&&(get_index(m_ter_op,g_buffer[i])==-1))//���ս�����ִ��ս����û��
		{
			m_ter_op[k]=g_buffer[i];
			k++;
		}
	}
	m_ter_op[k]=0;
	m_TERMINAL_LIST=m_ter_op;
	//����firstVT,lastVT��
	m_firstVT_list=new chara_list[strlen(m_non_op)];
	m_lastVT_list=new chara_list[strlen(m_non_op)];
	/*	for (i=0;i<strlen(m_non_op);i++)
	{
	m_firstVT_list[i].init();
	m_lastVT_list[i].init();
	}
	*/
	//��һ��firstVT
	for (i=0;i<strlen(m_non_op);i++)
	{
		if (is_ter_op(m_non_op,m_non_ter_op_g[i][0]))//A->a...
		{
			m_firstVT_list[i].add(m_non_ter_op_g[i][0]);
		}else//��һ���Ƿ��ս��,�ڶ������ս��
		{
			if (is_ter_op(m_non_op,m_non_ter_op_g[i][1]))
			{
				m_firstVT_list[i].add(m_non_ter_op_g[i][1]);
			}
		}
		//�ҵ�'|'
		for (j=0;j<strlen(m_non_ter_op_g[i]);j++)
		{
			if (m_non_ter_op_g[i][j]=='|')//�����'|'��֧��n��'|'
			{
				if (is_ter_op(m_non_op,m_non_ter_op_g[i][j+1]))//��һ�����ս��
				{
					m_firstVT_list[i].add(m_non_ter_op_g[i][j+1]);
				}else// '|'���Ƿ��ս��
				{
					if (is_ter_op(m_non_op,m_non_ter_op_g[i][j+2]))
					{
						m_firstVT_list[i].add(m_non_ter_op_g[i][j+2]);
					}
				}
				
			}
		}
		
	}
	//����������firstVT
	
	for (k=0;k<m_non_ter_op_len;k++)
	{
		for (i=0;i<m_non_ter_op_len;i++)
		{
			if (!is_ter_op(m_non_op,m_non_ter_op_g[i][0]))//�Ƿ��ս��
			{
				if (m_non_ter_op_g[i][0]!=m_non_op[i])//���ǵ�ǰ���ս��
				{
					m_firstVT_list[i].add(m_firstVT_list[get_index(m_non_op,m_non_ter_op_g[i][0])]);
				}
			}
			for (j=0;j<strlen(m_non_ter_op_g[i]);j++)
			{
				if (m_non_ter_op_g[i][j]=='|')
				{
					if (!is_ter_op(m_non_op,m_non_ter_op_g[i][j+1]))//�Ƿ��ս��
					{
						m_firstVT_list[i].add(m_firstVT_list[get_index(m_non_op,m_non_ter_op_g[i][j+1])]);
					}
				}
			}
		}
		
	}
	//��firstVT����ӵ�����
	char ch[2];ch[1]=0;
	for (i=0;i<m_non_ter_op_len;i++)
	{
		ch[0]=m_non_op[i];
		CString str=ch;
		m_list_firstVT.InsertItem(i,str);
		str=m_firstVT_list[i].m_lst;
		m_list_firstVT.SetItemText(i,1,str);
	}
	//��ʼLastVT��
	//��һ��
	int num=0;
	
	for (i=0;i<strlen(m_non_op);i++)
	{
		num=strlen(m_non_ter_op_g[i]);
		if (is_ter_op(m_non_op,m_non_ter_op_g[i][num-1]))//A->...a
		{
			m_lastVT_list[i].add(m_non_ter_op_g[i][num-1]);
		}else//���һ���Ƿ��ս��,�����ڶ������ս��
		{
			if (is_ter_op(m_non_op,m_non_ter_op_g[i][num-1]))
			{
				m_lastVT_list[i].add(m_non_ter_op_g[i][num-1]);
			}
		}
		//�ҵ�'|'
		for (j=0;j<strlen(m_non_ter_op_g[i]);j++)
		{
			if (m_non_ter_op_g[i][j]=='|')//�����'|'��֧��n��'|'
			{
				if (is_ter_op(m_non_op,m_non_ter_op_g[i][j-1]))//'|'ǰ��һ�����ս��
				{
					m_lastVT_list[i].add(m_non_ter_op_g[i][j-1]);
				}else// '|'ǰ���Ƿ��ս��
				{
					if (is_ter_op(m_non_op,m_non_ter_op_g[i][j-2]))
					{
						m_lastVT_list[i].add(m_non_ter_op_g[i][j-2]);
					}
				}
				
			}
		}
		
	}
	//����������LastVT
	for (k=0;k<m_non_ter_op_len;k++)
	{
		num=strlen(m_non_ter_op_g[k]);
		for (i=0;i<m_non_ter_op_len;i++)
		{
			if (get_index(m_non_op,m_non_ter_op_g[i][num-1])!=-1)//����Ƿ��ս��
			{
				if (m_non_ter_op_g[i][num-1]!=m_non_op[i])//���ǵ�ǰ���ս��
				{
					m_lastVT_list[i].add(m_lastVT_list[get_index(m_non_op,m_non_ter_op_g[i][num-1])]);
				}
			}
			for (j=0;j<strlen(m_non_ter_op_g[i]);j++)
			{
				if (m_non_ter_op_g[i][j]=='|')
				{
					if (!is_ter_op(m_non_op,m_non_ter_op_g[i][j-1]))//'|'ǰ���Ƿ��ս��
					{
						m_lastVT_list[i].add(m_lastVT_list[get_index(m_non_op,m_non_ter_op_g[i][j-1])]);
					}
				}
			}
		}
	}
	//��LastVT��ʾ������
	for (i=0;i<m_non_ter_op_len;i++)
	{
		ch[0]=m_non_op[i];
		CString str=ch;
		m_list_lastVT.InsertItem(i,str);
		str=m_lastVT_list[i].m_lst;
		m_list_lastVT.SetItemText(i,1,str);
	}
	UpdateData(FALSE);
}
//�ж��ַ��Ƿ����ս��
bool COperator_priDlg::is_ter_op(char* non_ter_op,char ch)
{
	bool is_ter=true;
	if (ch=='|'||ch=='>'||ch==10||ch==13||ch==0)
	{
		return false;
	}
	for(int i=0;i<strlen(non_ter_op);i++)
	{
		if (non_ter_op[i]==ch)//�ս���б��д��ڸ��ַ�
		{
			is_ter=false;
		}
	}
	return is_ter;
}
//��ȡ������ָ���ַ����±�
int COperator_priDlg::get_index(char* buffer,char ch)
{
	int i;
	for (i=0;i<strlen(buffer);i++)
	{
		if (ch==buffer[i])
		{
			return i;
		}
	}
	return -1;
}

void COperator_priDlg::OnButtonMakeList() 
{
	// TODO: �������ȱ�
	//�����ά���飬0,1,2,3 :(��,<,>,=)
	m_ppritbl=new char*[strlen(m_ter_op)];
	for (int i=0;i<strlen(m_ter_op);i++)
	{
		m_ppritbl[i]=new char[strlen(m_ter_op)];
		memset(m_ppritbl[i],48,strlen(m_ter_op));
	}
	//�������ȱ�
	int j=0,k=0;
	for (i=0;i<m_non_ter_op_len;i++)
	{
		for (j=0;j<strlen(m_non_ter_op_g[i]);j++)
		{
			if ((get_index(m_non_op,m_non_ter_op_g[i][j])!=-1)&&is_ter_op(m_non_op,m_non_ter_op_g[i][j+1]))//E+
			{
				char chtp_n_ter_ch=m_non_ter_op_g[i][j];//��ǰ�ķ��ս��
				int index_n_tp=get_index(m_non_op,chtp_n_ter_ch);//��ǰ���ս�����±�
				int index_ter_tp=get_index(m_ter_op,m_non_ter_op_g[i][j+1]);//��ǰ�ս���±�
				for (k=0;k<strlen(m_ter_op);k++)
				{
					if (get_index(m_lastVT_list[index_n_tp].m_lst,m_ter_op[k])!=-1)//LastVT���д���
					{
						m_ppritbl[k][index_ter_tp]=50;//��'>'
					}
				}
			}
			if (is_ter_op(m_non_op,m_non_ter_op_g[i][j])&&(get_index(m_non_op,m_non_ter_op_g[i][j+1])!=-1))//+T
			{
				char chtp_n_ter_ch=m_non_ter_op_g[i][j+1];//��ǰ�ķ��ս��
				int index_n_tp=get_index(m_non_op,chtp_n_ter_ch);//��ǰ���ս�����±�
				int index_ter_tp=get_index(m_ter_op,m_non_ter_op_g[i][j]);//��ǰ�ս���±�
				for (k=0;k<strlen(m_ter_op);k++)
				{
					if (get_index(m_firstVT_list[index_n_tp].m_lst,m_ter_op[k])!=-1)//FirstVT���д���
					{
						m_ppritbl[index_ter_tp][k]=49;//��'<'
					}
				}
			}
			if (is_ter_op(m_non_op,m_non_ter_op_g[i][j])&&(get_index(m_non_op,m_non_ter_op_g[i][j+1])!=-1)&&is_ter_op(m_non_op,m_non_ter_op_g[i][j+2]))//(F)
			{
				int l_index_ter_tp=get_index(m_ter_op,m_non_ter_op_g[i][j]);//���ս���±�
				int r_index_ter_tp=get_index(m_ter_op,m_non_ter_op_g[i][j+2]);//���ս���±�
				m_ppritbl[l_index_ter_tp][r_index_ter_tp]=51;//��'='
			}
		}
	}
	//��ʾ���ȱ�
	m_op_pri_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_op_pri_list.InsertColumn(0,_T("  "),LVCFMT_LEFT,30);
	
	for (i=0;i<strlen(m_ter_op);i++)
	{
		CString str=m_ter_op[i];
		m_op_pri_list.InsertColumn(i+1,str,LVCFMT_LEFT,30);
		m_op_pri_list.InsertItem(i,str);
	}
	
	
	
	for (i=0;i<strlen(m_ter_op);i++)
	{
		for (j=0;j<strlen(m_ter_op);j++)
		{
			if (m_ppritbl[i][j]=='1')
			{
				m_op_pri_list.SetItemText(i,j+1,_T("<"));
			}
			if (m_ppritbl[i][j]=='2')
			{
				m_op_pri_list.SetItemText(i,j+1,_T(">"));
			}
			if (m_ppritbl[i][j]=='3')
			{
				m_op_pri_list.SetItemText(i,j+1,_T("="));
			}

		}
	}
	UpdateData(false);
}

void COperator_priDlg::OnButtonSave() 
{
	// TODO: �������ȱ��ļ���
	
}

void COperator_priDlg::OnButtonClean() 
{
	// TODO: ��ձ������ͷ��ڴ�ռ�
	int i;
	for (i=0;i<strlen(m_ter_op);i++)
	{
		delete m_ppritbl[i];
	}
	delete m_ppritbl;

	m_op_pri_list.DeleteAllItems();

	m_list_lastVT.DeleteAllItems();
	m_list_firstVT.DeleteAllItems();

	delete[] m_lastVT_list;
	delete[] m_firstVT_list;
	delete m_non_op;
	delete m_ter_op;
	
	delete g_buffer;

	m_NON_TERMINAL_LIST="";
	m_TERMINAL_LIST="";
	m_LANG="";
	m_LANG_PATH="";
	
	delete m_stk_ch;
	delete m_stk_input;
	m_list_final.DeleteAllItems();
	UpdateData(FALSE);
}

void COperator_priDlg::OnButtonStart() 
{
	// TODO: ������ȷ����㷨
	UpdateData(TRUE);
	m_stk_ch=new stack();
	m_stk_input=new stack();
	m_stk_input->push('#');
	m_stk_ch->push('#');
	int i=0;
	for (i=0;i<m_sentence.GetLength();i++)
	{
		m_stk_input->push(m_sentence.GetAt(m_sentence.GetLength()-i-1));
	}

	//��ʼ
	while(!((get_first_ter()=='#')&&(m_stk_input->get_top()=='#')))
	{
		if (get_pri()=='1')
		{
			move_in();
		}
		if (get_pri()=='2')
		{
			gy();
		}
		if (get_first_ter()!='#')
		{
			if (get_pri()=='3')
			{
				gy_eq();
			}
		}
		if (get_pri()=='0')
		{
			MessageBox("��䲻�Ϸ�����Լʧ�ܡ�");
			return;
		}
	}
	str_action_stk="��Լ";
	str_ch_stk=m_stk_ch->stk;
	str_input_stk=m_stk_input->stk;
	
	int ct=m_list_final.GetItemCount();
	m_list_final.InsertItem(ct,str_ch_stk);
	m_list_final.SetItemText(ct,1,str_input_stk);
	m_list_final.SetItemText(ct,2,str_action_stk);
}

bool COperator_priDlg::is_non_ter(char ch)
{
	if (get_index(m_non_op,ch)!=-1)
	{
		return true;
	}else
		return false;
}

bool COperator_priDlg::is_ter(char ch)
{
	if (get_index(m_ter_op,ch)!=-1)
	{
		return true;
	}else
		return false;
}
//��ȡ��һ���ս��
char COperator_priDlg::get_first_ter()
{
	if (is_ter(m_stk_ch->get_top()))
	{
		return m_stk_ch->get_top();
	}else
		return m_stk_ch->get_scnd();
}
//�ƽ�
void COperator_priDlg::move_in()
{
	str_action_stk="�ƽ�";
	str_ch_stk=m_stk_ch->stk;
	str_input_stk=m_stk_input->stk;
	int ct=m_list_final.GetItemCount();
	m_list_final.InsertItem(ct,str_ch_stk);
	m_list_final.SetItemText(ct,1,str_input_stk);
	m_list_final.SetItemText(ct,2,str_action_stk);

	m_stk_ch->push(m_stk_input->get_top());
	m_stk_input->pop();
	UpdateData(FALSE);
}
//��Լ
void COperator_priDlg::gy()
{
	str_action_stk="��Լ";
	str_ch_stk=m_stk_ch->stk;
	str_input_stk=m_stk_input->stk;
	
	int ct=m_list_final.GetItemCount();
	m_list_final.InsertItem(ct,str_ch_stk);
	m_list_final.SetItemText(ct,1,str_input_stk);
	m_list_final.SetItemText(ct,2,str_action_stk);
	if (is_ter(m_stk_ch->get_top()))
	{
		char tp=m_stk_ch->get_top();
		m_stk_ch->pop();
		m_stk_ch->push(get_up_lv_ch(tp));
	}else
	{
		char tp;
		m_stk_ch->pop();
		tp=get_up_lv_ch_center(m_stk_ch->get_top());
		m_stk_ch->pop();
		m_stk_ch->pop();
		m_stk_ch->push(get_up_lv_ch(tp));
	}
}
//��ȡ��һ�����ַ�
char COperator_priDlg::get_up_lv_ch(char ch)
{
	char ch_ret;

	for (int i=0;i<strlen(m_non_op);i++)
	{
		if (m_non_ter_op_g[i][strlen(m_non_ter_op_g[i])-1]==ch)
		{
			return m_non_op[i];
		}
	}
	return ch_ret;
}
//��ȡ���ȹ�ϵ
int COperator_priDlg::get_pri()
{
	int x=get_index(m_ter_op,get_first_ter());
	int y=get_index(m_ter_op,m_stk_input->get_top());
	return m_ppritbl[x][y];
}
//��ȡ��һ�����ַ�,�ս�����м�
char COperator_priDlg::get_up_lv_ch_center(char ch)
{
	char ch_ret;
	for (int i=0;i<strlen(m_non_op);i++)
	{
		for (int j=0;j<strlen(m_non_ter_op_g[i]);j++)
		{
			if (m_non_ter_op_g[i][j]==ch)
			{
				ch_ret=m_non_op[i+1];
				return ch_ret;
			}
		}
	}
	return ch_ret;
}
//�������
void COperator_priDlg::gy_eq()
{
	str_action_stk="��Լ";
	str_ch_stk=m_stk_ch->stk;
	str_input_stk=m_stk_input->stk;
	
	int ct=m_list_final.GetItemCount();
	m_list_final.InsertItem(ct,str_ch_stk);
	m_list_final.SetItemText(ct,1,str_input_stk);
	m_list_final.SetItemText(ct,2,str_action_stk);

	char tp;
	tp=get_up_lv_ch_center(m_stk_ch->get_top());
	m_stk_ch->pop();
	m_stk_ch->pop();
	m_stk_ch->push(get_up_lv_ch_center(tp));
	m_stk_input->pop();
}
