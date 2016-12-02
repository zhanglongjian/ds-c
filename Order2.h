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

template<class ElemType>
void PostOrder(BTree<ElemType> *bt)//后序遍历二叉树,bt为根结点指针
{if(bt){ 
  PostOrder(bt->LChild);PostOrder(bt->RChild);cout<<ElemType(*bt)<<',';}
}