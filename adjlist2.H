#define MAX_VERTEX_NUM 20
 typedef enum{DG,DN,UDG,UDN} GraphKind; /* {有向图,有向网,无向图,无向网} */
 typedef char VertexData; /* 顶点数据类型 */
 typedef struct ArcNode
 {
   int adjvex; /* 邻接点域,该弧所指向的顶点的位置 */
   int weight;   /*权值域*/
   struct ArcNode *nextarc; /* 指向下一个边结点的指针域 */   
 }ArcNode; /* 边结点 */

 typedef struct
 {
   VertexData data; /* 顶点信息 */
   ArcNode *firstarc; /* 第一个表结点的地址,指向第一条依附该顶点的弧的指针 */
 }VertexNode; /* 表头结点 */
 typedef struct
 {
   VertexNode vertex[MAX_VERTEX_NUM];
   int vexnum,arcnum; /* 图的当前顶点数和弧数 */
   GraphKind kind; /* 图的种类标志 */
 }AdjList;

 int LocateVex(AdjList G,VertexData v)
 { /* 初始条件：图G存在，u和G中顶点有相同特征 */
   /* 操作结果：若G中存在顶点u，则返回该顶点在图中位置；否则返回-1 */
   int i;
   for(i=0;i<G.vexnum;i++)
     if(G.vertex[i].data==v)
       return i;
   return -1;
 }


 void Display(AdjList G)
 { /* 输出图的邻接表G */
   int i;
   ArcNode *p;
   printf("%d vertexs:",G.vexnum);
   for(i=0;i<G.vexnum;i++)
     printf("%c ",G.vertex[i].data);
   printf("\n%d arcs(or sides):\n",G.arcnum);
   for(i=0;i<G.vexnum;i++)
   {
     p=G.vertex[i].firstarc;
     while(p)
     {
         printf("%c->%c ",G.vertex[i].data,G.vertex[p->adjvex].data);
         p=p->nextarc;
     }
     printf("\n");
   }
 }


 void CreateDG(AdjList *G)
 { /* 采用邻接表存储结构，构造没有相关信息图或网G(用一个函数构造4种图) */
   int i,j,k; 
   VertexData v1,v2; /* 连接边或弧的2顶点 */
   ArcNode *s;
   (*G).kind =DG;
   scanf("%d,%d%*c",&(*G).vexnum,&(*G).arcnum);
   for(i=0;i<(*G).vexnum;i++) /* 构造顶点向量 */
   {
     scanf("%c%*c",&(*G).vertex[i].data);
     (*G).vertex[i].firstarc=NULL; /* 初始化与该顶点有关的出弧链表 */
   }
   for(k=0;k<(*G).arcnum;k++) /* 构造相关弧链表 */
   {    
     scanf("%c,%c%*c",&v1,&v2);
     i=LocateVex(*G,v1); /* 弧尾 */
     j=LocateVex(*G,v2); /* 弧头 */
     s=(ArcNode *)malloc(sizeof(ArcNode));
     s->adjvex=j;
     s->nextarc=(*G).vertex[i].firstarc;
     (*G).vertex[i].firstarc=s;   /* 插在第i个元素(出弧)的表头 */
   }
 }