template<class ElemType>
void GeneralizedList(BTree<ElemType> *bt)
{//��������������,btΪ�����ָ��
if(bt)
{
  cout<<ElemType(*bt);
  if(bt->LChild||bt->RChild)cout<<'(';
  GeneralizedList(bt->LChild);
  if(bt->RChild)cout<<',';
  GeneralizedList(bt->RChild);
  if(bt->LChild||bt->RChild)cout<<')';
}
}
