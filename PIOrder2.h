template<class ElemType>
void PreOrder(BTree<ElemType> *bt)//ǰ�����������,btΪ�����ָ��
{ if(bt){// 
  cout<<ElemType(*bt)<<',';PreOrder(bt->LChild);PreOrder(bt->RChild);}
}

template<class ElemType>
void InOrder(BTree<ElemType> *bt)//�������������,btΪ�����ָ��
{if(bt){ 
  InOrder(bt->LChild);cout<<ElemType(*bt)<<',';InOrder(bt->RChild);}
}
