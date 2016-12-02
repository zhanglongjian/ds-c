template<class T>
class MGraph
{
protected:
 T** a;T noEdge;int n,e;
public:
MGraph(int nSize=0,T noedg=INF)
{
 int i,j;n=nSize;e=0;noEdge=noedg;a=new T*[n];
 for(i=0;i<n;i++)
 {a[i]=new T[n];for(j=0;j<n;j++)a[i][j]=noEdge;a[i][i]=0;}
}
~MGraph(){for(int i=0;i<n;i++)delete []a[i];delete []a;}
int Insert(int u,int v,T w=1)
{
if(u<0||v<0||u>n-1||v>n-1||u==v)return 0;
if(a[u][v]!=noEdge)return 0;a[u][v]=w;e++;return 1;
}
void Display()
{ /* 输出邻接矩阵存储表示的图G */
   int i,j;
   cout<<"图G("<<n<<","<<e<<")"<<"邻接矩阵a["<<n<<"]["<<n<<"]:\n";
   for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
     if(a[i][j]==INF)cout<<"∞ ";else cout<<setw(3)<<left<<a[i][j];
     cout<<endl;
   }
}
};