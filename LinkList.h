#include "stdio.h"
#include "malloc.h"

#ifndef ElemType
#define ElemType int
/*typedef int ElemType;*/
#endif

#ifndef Link_List   /*�� #if !defined(Link_List)*/
#define Link_List

typedef struct LNode{
ElemType data;            /*���ֵ*/
struct LNode *next;       /*�洢��һ�����ĵ�ַ*/
}*LinkList;

LinkList InitList()/*��ʼ����ͷ��㵥����*/
{LinkList L=(LinkList)malloc(sizeof(struct LNode));/*C++:LNode * L=new LNode;*/
 L->next=NULL;return L;}       

int GetLen(LinkList L)/*�����Ա���,����¼��ͷ���data����O(1)*/
{int num=0;LinkList p=L->next;
 while(p!=NULL){num++;p=p->next;}
 return(num);
}

LinkList GetElem(LinkList L,int i)/*ȡ��i��Ԫ�ص�ַ,i=1~n*/
{LinkList p;int pos=1;
 p=L->next;/*��pָ���һ�����a1*/
 if(i<1||i>GetLen(L))return NULL;
 while(pos<i){p=p->next;pos++;}
 return p;
}

int Locate(LinkList L,ElemType x)/*����ֵΪxԪ�ص�λ��(1~n),û�ҵ�����NULL*/
{LinkList p=L->next;int i,n=1;char *a=(char*)&x,*b;/*��pָ���һ�����a1*/
 while(p!=NULL){for(i=0,b=(char*)&p->data;i<sizeof(x);i++)if(a[i]!=b[i])break;if(i<sizeof(x))p=p->next,n++;else return n;}
 return 0;
}

int InsElem(LinkList L,int i,ElemType x)/*��iλ�ò���Ԫ��x,i=1~n*/
{LinkList p,s;int pos=0;
 p=L; /*��pָ��ͷ���a0*/
 if(i<1||i>GetLen(L)+1) return 0;
 s=(LinkList)malloc(sizeof(struct LNode));s->data=x;
 while(pos<i-1)/*pָ��ai-1ʱ�˳�*/
    {p=p->next;pos++;}
 s->next=p->next;/*ai��Ϊs����һ���(pָ��ai-1)*/
 p->next=s;/*s��Ϊai-1����һ���*/
 return 1;
}

int InsNode(LinkList L,int i,LinkList s)/*��iλ�ò�����x,i=1~n*/
{LinkList p;int pos=0;
 p=L;/*��pָ��ͷ���a0*/
 if(i<1||i>GetLen(L)+1) return 0;
 while(pos<i-1)/*pָ��ai-1ʱ�˳�*/
     { p=p->next;pos++;}
 s->next=p->next;/*ai��Ϊs����һ���(pָ��ai-1)*/
 p->next=s;/*s��Ϊai-1����һ���*/
 return 1;
}

int DelElem(LinkList L,int i)/*ɾ�����Ա��е�i��λ���ϵ�Ԫ��*/
{int pos=0;LinkList q,p=L;
 if(i<1||i>GetLen(L))return 0;
 while(pos<i-1){p=p->next;pos++;}
 q=p->next;/*qָ��ai,pָ��ai-1*/
 p->next=q->next;
 free(q);return 1;
}

void DispList(LinkList L)/*����Ԫ�����*/
{LinkList p=L->next;
 if(p==NULL){printf("�ձ�\n");return;}
 while(p!=NULL){printf("%d,",p->data);p=p->next;}
 printf("\n");
} 

#endif