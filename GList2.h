template<class ElemType>
void GeneralizedList(BTree<ElemType> *bt)
{//二叉树广义表输出,bt为根结点指针
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
