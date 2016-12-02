#define MAX_VERTEX_NUM 20 /* 最多顶点个数 */
#define INFINITY 32768    /*表示极大值，即∞*/ 
typedef enum{DG,DN,UDG,UDN} GraphKind; 
/*图的种类：分别表示有向图、有向网、无向图、无向网*/
typedef char VertexData; /* 顶点名称类型 */

 typedef struct
 {
   VertexData vertex[MAX_VERTEX_NUM]; /* 顶点名称数组 */
   int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; /* 邻接矩阵，对无权图，用1(是)或0(否)表示顶点相邻接与否；对带权图，则为权值 */
   int vexnum,arcnum; /* 图的顶点数和边数 */
   GraphKind kind; /* 图的种类标志 */
 } AdjMatrix;

 int LocateVex(AdjMatrix G,VertexData v)
 { /* 初始条件：图G存在，u和G中顶点有相同特征 */
   /* 操作结果：若G中存在顶点u，则返回该顶点在图中位置；否则返回-1 */
   int i;
   for(i=0;i<G.vexnum;i++)
     if(G.vertex[i]==v) return i;
   return -1;
 }


 void Display(AdjMatrix G)
 { /* 输出邻接矩阵存储表示的图G */
   int i,j;
   
   printf("%d vertexs are:",G.vexnum);
   for(i=0;i<G.vexnum;i++) /* 输出G.vertex[ ] */
     printf("%c ",G.vertex[i]);
   printf("\nG.arcs[ ][ ]:\n"); /* 输出G.arcs[ ][ ] */
   for(i=0;i<G.vexnum;i++)
   {
     for(j=0;j<G.vexnum;j++)
       printf("%d ",G.arcs[i][j]);
     printf("\n");
   }

 }


void CreateDG(AdjMatrix *G)
{ /*   采用邻接矩阵表示法，创建有向图(*G)   */
 int i,j,k;     
 VertexData v1,v2;
 (*G).kind=DN; 
 scanf("%d,%d%*c",&(*G).vexnum,&(*G).arcnum);  /*输入图的顶点数和弧数*/  
 for(i=0;i<(*G).vexnum;i++) /* 构造顶点名称数组 */
  scanf("%c%*c",&(*G).vertex[i]);  /*输入顶点名称*/
 for(i=0;i<(*G).vexnum;i++) /* 初始化邻接矩阵 */
   for(j=0;j<(*G).vexnum;j++)
     (*G).arcs[i][j]=0; 
 
 for(k=0;k<(*G).arcnum;k++)
    {
         scanf("%c,%c%*c",&v1,&v2);  
         /*输入一条弧的两个顶点名称及权值*/
         i=LocateVex(*G,v1);
         j=LocateVex(*G,v2);
         (*G).arcs[i][j]=1;
   }       
 }