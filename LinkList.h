#include "stdio.h"
#include "malloc.h"

#ifndef ElemType
#define ElemType int
/*typedef int ElemType;*/
#endif

#ifndef Link_List   /*或 #if !defined(Link_List)*/
#define Link_List

typedef struct LNode{
ElemType data;            /*结点值*/
struct LNode *next;       /*存储下一个结点的地址*/
}*LinkList;

LinkList InitList()/*初始化带头结点单链表*/
{LinkList L=(LinkList)malloc(sizeof(struct LNode));/*C++:LNode * L=new LNode;*/
 L->next=NULL;return L;}       

int GetLen(LinkList L)/*求线性表长度,若记录于头结点data域则O(1)*/
{int num=0;LinkList p=L->next;
 while(p!=NULL){num++;p=p->next;}
 return(num);
}

LinkList GetElem(LinkList L,int i)/*取第i个元素地址,i=1~n*/
{LinkList p;int pos=1;
 p=L->next;/*让p指向第一个结点a1*/
 if(i<1||i>GetLen(L))return NULL;
 while(pos<i){p=p->next;pos++;}
 return p;
}

int Locate(LinkList L,ElemType x)/*查找值为x元素的位置(1~n),没找到返回NULL*/
{LinkList p=L->next;int i,n=1;char *a=(char*)&x,*b;/*让p指向第一个结点a1*/
 while(p!=NULL){for(i=0,b=(char*)&p->data;i<sizeof(x);i++)if(a[i]!=b[i])break;if(i<sizeof(x))p=p->next,n++;else return n;}
 return 0;
}

int InsElem(LinkList L,int i,ElemType x)/*第i位置插入元素x,i=1~n*/
{LinkList p,s;int pos=0;
 p=L; /*让p指向头结点a0*/
 if(i<1||i>GetLen(L)+1) return 0;
 s=(LinkList)malloc(sizeof(struct LNode));s->data=x;
 while(pos<i-1)/*p指向ai-1时退出*/
    {p=p->next;pos++;}
 s->next=p->next;/*ai作为s的下一结点(p指向ai-1)*/
 p->next=s;/*s作为ai-1的下一结点*/
 return 1;
}

int InsNode(LinkList L,int i,LinkList s)/*第i位置插入结点x,i=1~n*/
{LinkList p;int pos=0;
 p=L;/*让p指向头结点a0*/
 if(i<1||i>GetLen(L)+1) return 0;
 while(pos<i-1)/*p指向ai-1时退出*/
     { p=p->next;pos++;}
 s->next=p->next;/*ai作为s的下一结点(p指向ai-1)*/
 p->next=s;/*s作为ai-1的下一结点*/
 return 1;
}

int DelElem(LinkList L,int i)/*删除线性表中第i个位置上的元素*/
{int pos=0;LinkList q,p=L;
 if(i<1||i>GetLen(L))return 0;
 while(pos<i-1){p=p->next;pos++;}
 q=p->next;/*q指向ai,p指向ai-1*/
 p->next=q->next;
 free(q);return 1;
}

void DispList(LinkList L)/*链表元素输出*/
{LinkList p=L->next;
 if(p==NULL){printf("空表\n");return;}
 while(p!=NULL){printf("%d,",p->data);p=p->next;}
 printf("\n");
} 

#endif