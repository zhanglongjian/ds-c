//#include <iostream.h>
//using namespace std;
#ifndef List2
#define List2
template<class ElemType>
class List{
public:
virtual int GetLen()=0;/*求线性表长度*/
virtual ElemType &GetElem(int i)=0;/*取第i个元素,i=1~n*/
ElemType &operator[](int i){return GetElem(i);}//下标重载
virtual int Locate(ElemType x)=0;
virtual int InsElem(int i,ElemType x)=0;
virtual int DelElem(int i)=0;
virtual void DispList(char c=',',char c2='\n')=0;
};
#endif

#ifndef sq_List2
#define sq_List2

template<typename ElemType>
class sqList:public List<ElemType>{
ElemType *data,X;   //定义存储表中元素的数组
int Length,MaxLen;  //线性表的实际长度
public://构造函数初始化顺序表
sqList(int n=100):MaxLen(n),Length(0),X(0){data=new ElemType[n];}
int GetLen(){return Length;}//求线性表长度

ElemType &GetElem(int i)//取第i个元素值,i=1~n
{if(i<1||i>Length)return X;//返回随机数
 return data[i-1];}
//ElemType &operator[](int i){return GetElem(i);}//下标重载

int Locate(ElemType x)//查找值为x元素的位置,没找到返回a0
{int i;
for(i=0;i<Length;i++)if(!(data[i]!=x))return i+1;
return 0;}

int InsElem(int i,ElemType x)//第i位置插入结点x,i=1~n
{int j;
 if(Length==MaxLen)return 0;//表已满 
 if(i<1||i>Length+1)return 0;//插入位置出错
 for(j=Length;j>=i;j--)data[j]=data[j-1];//数据元素后移 
 data[i-1]=x;Length++;  //插入x,表长度加1 
 return 1;}

int DelElem(int i)//删除线性表中第i个位置上的元素 
{int j;
 if(i<1||i>Length)return 0;//检查空表及删除位置的合法性
 for(j=i;j<=Length-1;j++)data[j-1]=data[j];//向前移动元素
 Length--;return 1;}

void DispList(char c=',',char c2='\n')//输出线性表中每个元素值
{int i;
if(Length==0){cout<<"空表";if(c2)if(c2=='\n')cout<<endl;else cout<<c2;return;}
for(i=0;i<Length;i++){cout<<data[i];if(c)cout<<c;}
if(c2)if(c2=='\n')cout<<endl;else cout<<c2;
}

};

#endif