template<class ElemType>
void Insert(LinkList< BTree<ElemType> > &A,BTree<ElemType> t)
{/*结点t插入线性表A中，A中元素从小到大，若值相等，则插入相等值后面*/
 int i;
 for(i=1;i<=A.GetLen();i++)if(t<A[i])break;
 A.InsElem(i,t);
}

template<class ElemType>
void CreateHFMTree(LinkList< BTree<ElemType> > &A)
{/*利用线性表中子树创建哈夫曼树*/
 int i,n=A.GetLen(),m=2*n-1;
 for(i=1;i<m;i+=2)Insert(A,A[i]+A[i+1]);
}
