#include "stdio.h"

#ifndef ElemType
#define ElemType int /*在实际应用中,将ElemType定义成实际类型*/
#endif/*typedef int ElemType;*/

#ifndef SQ_Stack              /*或 #if !defined(SQ_Stack)*/
#define SQ_Stack

#ifndef MaxSize/*MaxSize未定义过则定义*/
#define MaxSize 100  /*顺序栈的容量,栈存储元素个数*/
#endif
  
typedef struct{
ElemType data[MaxSize];/*定义存储栈中元素的数组*/
int top;                 /*栈顶位置*/
}sqStack;

void InitStack(sqStack *S)/*初始化栈*/ 
{S->top=-1;} 

int Empty(sqStack *S)/*判栈空*/
{return S->top==-1?1:0;}

int Full(sqStack *S)/*判栈满*/
{return S->top==MaxSize-1;}

int Push(sqStack *S,ElemType x)/*入栈*/
{if(Full(S))return 0;/*{printf("栈满!\n");}*/
 S->data[++S->top]=x;return 1;}

int Pop(sqStack *S,ElemType *x)/*出栈*/     
{if(Empty(S))return 0;/*{printf("栈空!");}*/
 *x=S->data[S->top--];return 1;}

int GetTop(sqStack *S,ElemType *x)/*取栈顶元素*/
{if(Empty(S))return 0;/*{printf("栈空!");}*/
 *x=S->data[S->top];
 return 1;}

#endif
