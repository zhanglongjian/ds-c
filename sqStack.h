#include "stdio.h"

#ifndef ElemType
#define ElemType int /*��ʵ��Ӧ����,��ElemType�����ʵ������*/
#endif/*typedef int ElemType;*/

#ifndef SQ_Stack              /*�� #if !defined(SQ_Stack)*/
#define SQ_Stack

#ifndef MaxSize/*MaxSizeδ���������*/
#define MaxSize 100  /*˳��ջ������,ջ�洢Ԫ�ظ���*/
#endif
  
typedef struct{
ElemType data[MaxSize];/*����洢ջ��Ԫ�ص�����*/
int top;                 /*ջ��λ��*/
}sqStack;

void InitStack(sqStack *S)/*��ʼ��ջ*/ 
{S->top=-1;} 

int Empty(sqStack *S)/*��ջ��*/
{return S->top==-1?1:0;}

int Full(sqStack *S)/*��ջ��*/
{return S->top==MaxSize-1;}

int Push(sqStack *S,ElemType x)/*��ջ*/
{if(Full(S))return 0;/*{printf("ջ��!\n");}*/
 S->data[++S->top]=x;return 1;}

int Pop(sqStack *S,ElemType *x)/*��ջ*/     
{if(Empty(S))return 0;/*{printf("ջ��!");}*/
 *x=S->data[S->top--];return 1;}

int GetTop(sqStack *S,ElemType *x)/*ȡջ��Ԫ��*/
{if(Empty(S))return 0;/*{printf("ջ��!");}*/
 *x=S->data[S->top];
 return 1;}

#endif
