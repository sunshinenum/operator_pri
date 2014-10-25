// chara_list.h: interface for the chara_list class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHARA_LIST_H__B3EBC667_B4EA_4A50_B0B3_B03D62704615__INCLUDED_)
#define AFX_CHARA_LIST_H__B3EBC667_B4EA_4A50_B0B3_B03D62704615__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class chara_list  
{
public:
	void init();
	void add(char ch);//重复了也添加
	void add(chara_list lst);

	char* m_lst;
	int m_index;
	
	chara_list(chara_list& lst);
	chara_list();
	virtual ~chara_list();
};

#endif // !defined(AFX_CHARA_LIST_H__B3EBC667_B4EA_4A50_B0B3_B03D62704615__INCLUDED_)
