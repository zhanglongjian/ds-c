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
   printf("%d��������:",G.vexnum);
   for(i=0;i<G.vexnum;i++)
     printf(" %c",G.vertex[i].data);
   printf("\n%d����(��):\n",G.arcnum);
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