#include "math.h"
//����˳���ջʵ�ֺ�׺�������ʽ(���������+-*/^�ֱ��ʾ�Ӽ��˳��˷�)�ļ��㹦�ܡ�
//��׺���ʽ:5 1 5 / - 5 * 1 + 2 ^ , ���н��:625
double fun(double x,double y,char c)
{
double z;
switch(c) 
{
  case '+':z=x+y;break; 
  case '-':z=x-y;break;
  case '*':z=x*y;break;
  case '/':z=x/y;break;
  case '^':z=pow(x,y); 
}
return z;
}
float Cal(const char in[80])
{
sqStack<double> s;char c;double x,y;istringstream cin(in);
while(cin>>c)
{if(c=='#')break;
 switch(c)
  {
  case '+':case '-':case '*':case '/':case '^': 
    y=s.Pop();x=s.Pop();s.Push(fun(x,y,c));break;//������
  default:cin.putback(c);cin>>x;s.Push(x);break;//��������ջ
  }
}
return s.Pop();
}
