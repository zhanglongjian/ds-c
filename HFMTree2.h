template<class ElemType>
void Insert(LinkList< BTree<ElemType> > &A,BTree<ElemType> t)
{/*���t�������Ա�A�У�A��Ԫ�ش�С������ֵ��ȣ���������ֵ����*/
 int i;
 for(i=1;i<=A.GetLen();i++)if(t<A[i])break;
 A.InsElem(i,t);
}

template<class ElemType>
void CreateHFMTree(LinkList< BTree<ElemType> > &A)
{/*�������Ա�������������������*/
 int i,n=A.GetLen(),m=2*n-1;
 for(i=1;i<m;i+=2)Insert(A,A[i]+A[i+1]);
}
