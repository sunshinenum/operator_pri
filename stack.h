// stack.h: interface for the stack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STACK_H__0D7B6E88_AF21_436F_B410_EB49D1D346DF__INCLUDED_)
#define AFX_STACK_H__0D7B6E88_AF21_436F_B410_EB49D1D346DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class stack  
{
public:
	char get_scnd();
	char get_top();
	void pop();
	void push(char ch);
	char* stk;
	int index;
	stack();
	virtual ~stack();

};

#endif // !defined(AFX_STACK_H__0D7B6E88_AF21_436F_B410_EB49D1D346DF__INCLUDED_)
