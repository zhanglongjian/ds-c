template<class ElemType>
void PreOrder(BTree<ElemType> *bt)//ǰ�����������,btΪ�����ָ��
{ if(bt){// 
  cout<<ElemType(*bt)<<',';PreOrder(bt->LChild);PreOrder(bt->RChild);}
}

template<class ElemType>
void PostOrder(BTree<ElemType> *bt)//�������������,btΪ�����ָ��
{if(bt){ 
  PostOrder(bt->LChild);PostOrder(bt->RChild);cout<<ElemType(*bt)<<',';}
}