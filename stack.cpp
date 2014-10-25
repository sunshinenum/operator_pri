// stack.cpp: implementation of the stack class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "operator_pri.h"
#include "stack.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define STACK_SIZE 100
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

stack::stack()
{
	stk=new char[STACK_SIZE];
	memset(stk,0,STACK_SIZE);
	index=-1;
}
char stack:: get_top()
{
	return stk[index];
}
void stack::pop()
{
	stk[index]=0;
	index--;
}
void stack::push(char ch)
{
	index++;
	stk[index]=ch;
}
stack::~stack()
{
	delete stk;
}

char stack::get_scnd()
{
	if (index==-1)
	{
		return 127;
	}else
		return stk[index-1];
}
