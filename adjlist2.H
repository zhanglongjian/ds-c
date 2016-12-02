#define MAX_VERTEX_NUM 20
 typedef enum{DG,DN,UDG,UDN} GraphKind; /* {����ͼ,������,����ͼ,������} */
 typedef char VertexData; /* ������������ */
 typedef struct ArcNode
 {
   int adjvex; /* �ڽӵ���,�û���ָ��Ķ����λ�� */
   int weight;   /*Ȩֵ��*/
   struct ArcNode *nextarc; /* ָ����һ���߽���ָ���� */   
 }ArcNode; /* �߽�� */

 typedef struct
 {
   VertexData data; /* ������Ϣ */
   ArcNode *firstarc; /* ��һ�������ĵ�ַ,ָ���һ�������ö���Ļ���ָ�� */
 }VertexNode; /* ��ͷ��� */
 typedef struct
 {
   VertexNode vertex[MAX_VERTEX_NUM];
   int vexnum,arcnum; /* ͼ�ĵ�ǰ�������ͻ��� */
   GraphKind kind; /* ͼ�������־ */
 }AdjList;

 int LocateVex(AdjList G,VertexData v)
 { /* ��ʼ������ͼG���ڣ�u��G�ж�������ͬ���� */
   /* �����������G�д��ڶ���u���򷵻ظö�����ͼ��λ�ã����򷵻�-1 */
   int i;
   for(i=0;i<G.vexnum;i++)
     if(G.vertex[i].data==v)
       return i;
   return -1;
 }


 void Display(AdjList G)
 { /* ���ͼ���ڽӱ�G */
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
 { /* �����ڽӱ��洢�ṹ������û�������Ϣͼ����G(��һ����������4��ͼ) */
   int i,j,k; 
   VertexData v1,v2; /* ���ӱ߻򻡵�2���� */
   ArcNode *s;
   (*G).kind =DG;
   scanf("%d,%d%*c",&(*G).vexnum,&(*G).arcnum);
   for(i=0;i<(*G).vexnum;i++) /* ���춥������ */
   {
     scanf("%c%*c",&(*G).vertex[i].data);
     (*G).vertex[i].firstarc=NULL; /* ��ʼ����ö����йصĳ������� */
   }
   for(k=0;k<(*G).arcnum;k++) /* ������ػ����� */
   {    
     scanf("%c,%c%*c",&v1,&v2);
     i=LocateVex(*G,v1); /* ��β */
     j=LocateVex(*G,v2); /* ��ͷ */
     s=(ArcNode *)malloc(sizeof(ArcNode));
     s->adjvex=j;
     s->nextarc=(*G).vertex[i].firstarc;
     (*G).vertex[i].firstarc=s;   /* ���ڵ�i��Ԫ��(����)�ı�ͷ */
   }
 }