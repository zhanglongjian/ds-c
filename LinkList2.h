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

#ifndef Link_List2
#define Link_List2
template<typename ElemType>
struct LNode{
ElemType data; //结点值
LNode *next;   //存储下一个结点的地址
operator ElemType(){return data;}//函数转换,对象按data值用
LNode(ElemType d=0,LNode *n=NULL):data(d),next(n){}//构造函数置初值
LNode<ElemType> &operator=(ElemType d){data=d;return *this;}//赋值重载
LNode<ElemType> &operator=(LNode<ElemType> d){data=d.data;return *this;}
int operator<(ElemType x){return data<x;}//重载<运算符
int operator<=(ElemType x){return data<=x;}//重载<=运算符
int operator>(ElemType x){return data>x;}//重载>运算符
int operator>=(ElemType x){return data>=x;}//重载>=运算符
int operator==(ElemType x){return data==x;}//重载==运算符
int operator!=(ElemType x){return data!=x;}//重载!=运算符
};

template<typename ElemType>
class LinkList:public List< ElemType >{
LNode<ElemType> *head,*H; //存储下一个结点的地址
public://构造函数初始化带头结点单链表
LinkList(){head=new LNode<ElemType>;H=new LNode<ElemType>;}

int GetLen()//求线性表长度,若记录于头结点data域则O(1)
{int num=0;LNode<ElemType> *p=head->next;
 while(p!=NULL){num++;p=p->next;}
 return(num);
}

ElemType &GetElem(int i)//取第i个元素地址(i=1~n),通过函数转换取值
{LNode<ElemType> *p;int pos=1;
 p=head->next;//让p指向第一个结点a1
 if(i<1||i>GetLen())return head->data;
 while(pos<i){p=p->next;pos++;}
 return p->data;
}

int Locate(ElemType x)//查找值为x元素的位置n,没找到返回0
{LNode<ElemType> *p=head->next;int n=1;//让p指向第一个结点a1
 while(p!=NULL)if(p->data!=x)p=p->next,n++;else return n;
 return 0;
}

int InsElem(int i,ElemType x)//第i位置插入元素x,i=1~n
{LNode<ElemType> *p,*s;int pos=0;
 p=head; //让p指向头结点a0
 if(i<1||i>GetLen()+1) return 0;
 s=new LNode<ElemType>;s->data=x;
 while(pos<i-1)//p指向ai-1时退出
    {p=p->next;pos++;}
 s->next=p->next;//ai作为s的下一结点(p指向ai-1)
 p->next=s;//s作为ai-1的下一结点
 return 1;
}

int DelElem(int i)//删除线性表中第i个位置上的元素
{int pos=0;LNode<ElemType> *q,*p=head;
 if(i<1||i>GetLen())return 0;
 while(pos<i-1){p=p->next;pos++;}
 q=p->next;//q指向ai,p指向ai-1
 p->next=q->next;
 delete q;return 1;
}

void DispList(char c=',',char c2='\n')//链表元素输出
{LNode<ElemType> *p=head->next;
 if(p==NULL){cout<<"空表";if(c2)if(c2=='\n')cout<<endl;else cout<<c2;return;}
 while(p!=NULL){cout<<p->data;if(c)cout<<c;p=p->next;}
 if(c2)if(c2=='\n')cout<<endl;else cout<<c2;
} 
};
#endif