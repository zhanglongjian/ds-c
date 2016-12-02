template<class T>
class LGraph
{
protected:
 ENode<T>** a;T noEdge;int n,e;
public:
LGraph(int nSize=0)
{
n=nSize;e=0;a=new ENode<T>*[n];
for(int i=0;i<n;i++)a[i]=NULL;
}
~LGraph()
{
 ENode<T> *p,*q;
 for(int i=0;i<n;i++)
  {p=a[i];q=p;while(p){p=p->nextArc;delete q;q=p;}}
 delete[]a;
}
int Insert(int u,int v,T w=1)
{
 if(u<0||v<0||u>n-1||v>n-1||u==v)return 0;
 if(Exist(u,v))return 0;
 ENode<T>* p=new ENode<T>(v,w,a[u]);
 a[u]=p;e++;return 1;
}
bool Exist(int u,int v)
{
 if(u<0||v<0||u>n-1||v>n-1||u==v)return 0;
 ENode<T>* p=a[u];
 while(p&&p->adjVex!=v)p=p->nextArc;
 if(p)return 1;else return 0;
}
void Display()
{/* 输出邻接表存储表示的图G */
   int i;
   ENode<T>*p;
   cout<<"图G("<<n<<","<<e<<")"<<"邻接表:\n";
   for(i=0;i<n;i++)
   {
     p=a[i];cout<<i<<"邻接的边:";
     while(p)
     {
         cout<<"("<<i<<","<<p->adjVex<<","<<p->w<<"),";
         p=p->nextArc;
     }
     cout<<endl;
   }
}
};