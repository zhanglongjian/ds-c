template <class T>
int Insert(BTree<T>* &root,T& x)
{
BTree<T> *p=root,*q=NULL;
while(p)
{
q=p;
if(x<p->data)p=p->LChild;else if(x>p->data)p=p->RChild;
 else{cout<<"ÒÑ¾­´æÔÚ"<<x;return 0;}
}
p=new BTree<T>(x);
if(!root)root=p;else if(x<q->data)q->LChild=p;else q->RChild=p;
return 1;
}
