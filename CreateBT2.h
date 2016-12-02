template<class ElemType>
void CreaTree(BTree<ElemType>* &T)/*以先序序列输入并创建二叉树,虚结点输入时以"^"表示*/
{/*构造二叉链表。T是指向根指针的指针，故修改*T就修改了实参(根指针)本身*/
 char ch;ElemType x; /*ABD^G^^^CE^^F^^*/
 cin>>ch; 
 if(ch=='^')T=NULL;/*读入空格，将相应指针置空*/
  else                           /*读入非空格*/
  {
   cin.putback(ch);cin>>x;//将ch退回输入流,重新按ElemType类型读到x
   T=new BTree<ElemType>(x);/*生成根结点*/
   CreaTree(T->LChild);/*构造左子树*/
   CreaTree(T->RChild);/*构造右子树*/
  }
}
