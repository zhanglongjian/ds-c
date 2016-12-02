template<class ElemType>
void PreOrder(BTree<ElemType> *bt)//前序遍历二叉树,bt为根结点指针
{ if(bt){// 
  cout<<ElemType(*bt)<<',';PreOrder(bt->LChild);PreOrder(bt->RChild);}
}

template<class ElemType>
void InOrder(BTree<ElemType> *bt)//中序遍历二叉树,bt为根结点指针
{if(bt){ 
  InOrder(bt->LChild);cout<<ElemType(*bt)<<',';InOrder(bt->RChild);}
}
