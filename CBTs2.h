template<class ElemType>
void CreaTree(BTree<ElemType>* &b,char *str)/*利用广义表输入并创建二叉树*/
{sqStack<BTree<ElemType>*> stack;BTree<ElemType> *p;int k;char ch;
 ElemType x;istringstream cin(str);b=NULL;
 while(cin>>ch)
  switch(ch)
  {case'(':stack.Push(p);k=1;break;//为左结点
   case')':stack.Pop();break;
   case',':k=2;break;//为右结点
   default:
    cin.putback(ch);cin>>x;//将ch退回输入流,重新按ElemType类型读到x
	p=new BTree<ElemType>(x);       
    if(!b)b=p;else//为根结点
    {switch(k){
     case 1:stack.GetTop()->LChild=p;break;
     case 2:stack.GetTop()->RChild=p;break;}
    }
  }//switch(ch)注意花括号层次
} 