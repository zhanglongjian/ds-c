template<class ElemType>
void CreaTree(BTree<ElemType>* &T)/*�������������벢����������,��������ʱ��"^"��ʾ*/
{/*�����������T��ָ���ָ���ָ�룬���޸�*T���޸���ʵ��(��ָ��)����*/
 char ch;ElemType x; /*ABD^G^^^CE^^F^^*/
 cin>>ch; 
 if(ch=='^')T=NULL;/*����ո񣬽���Ӧָ���ÿ�*/
  else                           /*����ǿո�*/
  {
   cin.putback(ch);cin>>x;//��ch�˻�������,���°�ElemType���Ͷ���x
   T=new BTree<ElemType>(x);/*���ɸ����*/
   CreaTree(T->LChild);/*����������*/
   CreaTree(T->RChild);/*����������*/
  }
}
