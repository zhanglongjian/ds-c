template<class ElemType>
void CreaTree(BTree<ElemType>* &b,char *str)/*���ù�������벢����������*/
{sqStack<BTree<ElemType>*> stack;BTree<ElemType> *p;int k;char ch;
 ElemType x;istringstream cin(str);b=NULL;
 while(cin>>ch)
  switch(ch)
  {case'(':stack.Push(p);k=1;break;//Ϊ����
   case')':stack.Pop();break;
   case',':k=2;break;//Ϊ�ҽ��
   default:
    cin.putback(ch);cin>>x;//��ch�˻�������,���°�ElemType���Ͷ���x
	p=new BTree<ElemType>(x);       
    if(!b)b=p;else//Ϊ�����
    {switch(k){
     case 1:stack.GetTop()->LChild=p;break;
     case 2:stack.GetTop()->RChild=p;break;}
    }
  }//switch(ch)ע�⻨���Ų��
} 