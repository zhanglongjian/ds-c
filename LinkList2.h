//#include <iostream.h>
//using namespace std;
#ifndef List2
#define List2
template<class ElemType>
class List{
public:
virtual int GetLen()=0;/*�����Ա���*/
virtual ElemType &GetElem(int i)=0;/*ȡ��i��Ԫ��,i=1~n*/
ElemType &operator[](int i){return GetElem(i);}//�±�����
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
ElemType data; //���ֵ
LNode *next;   //�洢��һ�����ĵ�ַ
operator ElemType(){return data;}//����ת��,����dataֵ��
LNode(ElemType d=0,LNode *n=NULL):data(d),next(n){}//���캯���ó�ֵ
LNode<ElemType> &operator=(ElemType d){data=d;return *this;}//��ֵ����
LNode<ElemType> &operator=(LNode<ElemType> d){data=d.data;return *this;}
int operator<(ElemType x){return data<x;}//����<�����
int operator<=(ElemType x){return data<=x;}//����<=�����
int operator>(ElemType x){return data>x;}//����>�����
int operator>=(ElemType x){return data>=x;}//����>=�����
int operator==(ElemType x){return data==x;}//����==�����
int operator!=(ElemType x){return data!=x;}//����!=�����
};

template<typename ElemType>
class LinkList:public List< ElemType >{
LNode<ElemType> *head,*H; //�洢��һ�����ĵ�ַ
public://���캯����ʼ����ͷ��㵥����
LinkList(){head=new LNode<ElemType>;H=new LNode<ElemType>;}

int GetLen()//�����Ա���,����¼��ͷ���data����O(1)
{int num=0;LNode<ElemType> *p=head->next;
 while(p!=NULL){num++;p=p->next;}
 return(num);
}

ElemType &GetElem(int i)//ȡ��i��Ԫ�ص�ַ(i=1~n),ͨ������ת��ȡֵ
{LNode<ElemType> *p;int pos=1;
 p=head->next;//��pָ���һ�����a1
 if(i<1||i>GetLen())return head->data;
 while(pos<i){p=p->next;pos++;}
 return p->data;
}

int Locate(ElemType x)//����ֵΪxԪ�ص�λ��n,û�ҵ�����0
{LNode<ElemType> *p=head->next;int n=1;//��pָ���һ�����a1
 while(p!=NULL)if(p->data!=x)p=p->next,n++;else return n;
 return 0;
}

int InsElem(int i,ElemType x)//��iλ�ò���Ԫ��x,i=1~n
{LNode<ElemType> *p,*s;int pos=0;
 p=head; //��pָ��ͷ���a0
 if(i<1||i>GetLen()+1) return 0;
 s=new LNode<ElemType>;s->data=x;
 while(pos<i-1)//pָ��ai-1ʱ�˳�
    {p=p->next;pos++;}
 s->next=p->next;//ai��Ϊs����һ���(pָ��ai-1)
 p->next=s;//s��Ϊai-1����һ���
 return 1;
}

int DelElem(int i)//ɾ�����Ա��е�i��λ���ϵ�Ԫ��
{int pos=0;LNode<ElemType> *q,*p=head;
 if(i<1||i>GetLen())return 0;
 while(pos<i-1){p=p->next;pos++;}
 q=p->next;//qָ��ai,pָ��ai-1
 p->next=q->next;
 delete q;return 1;
}

void DispList(char c=',',char c2='\n')//����Ԫ�����
{LNode<ElemType> *p=head->next;
 if(p==NULL){cout<<"�ձ�";if(c2)if(c2=='\n')cout<<endl;else cout<<c2;return;}
 while(p!=NULL){cout<<p->data;if(c)cout<<c;p=p->next;}
 if(c2)if(c2=='\n')cout<<endl;else cout<<c2;
} 
};
#endif