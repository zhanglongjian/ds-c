//ջ
//#include <iostream.h>
//using namespace std;
#ifndef SQ_Stack2              //�� #if !defined(SQ_Stack)
#define SQ_Stack2

template<class ElemType>
class sqStack{
ElemType *data,X; //����洢ջ��Ԫ�ص�����
int top,MaxSize;  //ջ��λ��,˳��ջ������
public://��ʼ��ջ
sqStack(int n=100):top(-1),MaxSize(n),X(0){data=new ElemType[n];} 

int Empty(){return top==-1?1:0;}//��ջ��

int Full(){return top==MaxSize-1;}//��ջ��

int Push(ElemType x)//��ջ
{if(Full())return 0;//{printf("ջ��!\n");}
 data[++top]=x;return 1;}

ElemType Pop()//��ջ     
{if(Empty())return X;//{printf("ջ��!");}
 return data[top--];}

ElemType GetTop()//ȡջ��Ԫ��
{if(Empty())return X;//{printf("ջ��!");}
 return data[top];}

};
#endif