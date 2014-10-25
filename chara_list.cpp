// chara_list.cpp: implementation of the chara_list class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "chara_list.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

chara_list::chara_list()
{
	m_lst=NULL;
	m_lst=new char[100];
	memset(m_lst,0,100);
	m_index=0;
}
chara_list::chara_list(chara_list& lst)
{
	m_lst=NULL;
	m_lst=new char[100];
	memcpy(m_lst,lst.m_lst,100);
	m_index=lst.m_index;
}

chara_list::~chara_list()
{
	delete m_lst;
}
//添加一个字符进去
void chara_list::add(char ch)
{
	int i;
	bool is_add=true;
	for (i=0;i<m_index;i++)
	{
		if (m_lst[i]==ch)
		{
			is_add=false;
		}
	}
	if (is_add)//列表中还没有
	{
		m_lst[m_index]=ch;
		m_index++;
	}
}
//添加一个表进去
void chara_list::add(chara_list lst)
{
	int i;
	for (i=0;i<lst.m_index;i++)
	{
		this->add(lst.m_lst[i]);
	}
}
