#include "math.h"
//利用顺序堆栈实现后缀算术表达式(可用运算符+-*/^分别表示加减乘除乘方)的计算功能。
//后缀表达式:5 1 5 / - 5 * 1 + 2 ^ , 运行结果:625
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
    y=s.Pop();x=s.Pop();s.Push(fun(x,y,c));break;//操作符
  default:cin.putback(c);cin>>x;s.Push(x);break;//操作数进栈
  }
}
return s.Pop();
}
