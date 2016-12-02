//栈
//#include <iostream.h>
//using namespace std;
#ifndef SQ_Stack2              //或 #if !defined(SQ_Stack)
#define SQ_Stack2

template<class ElemType>
class sqStack{
ElemType *data,X; //定义存储栈中元素的数组
int top,MaxSize;  //栈顶位置,顺序栈的容量
public://初始化栈
sqStack(int n=100):top(-1),MaxSize(n),X(0){data=new ElemType[n];} 

int Empty(){return top==-1?1:0;}//判栈空

int Full(){return top==MaxSize-1;}//判栈满

int Push(ElemType x)//入栈
{if(Full())return 0;//{printf("栈满!\n");}
 data[++top]=x;return 1;}

ElemType Pop()//出栈     
{if(Empty())return X;//{printf("栈空!");}
 return data[top--];}

ElemType GetTop()//取栈顶元素
{if(Empty())return X;//{printf("栈空!");}
 return data[top];}

};
#endif