#define MAX_VERTEX_NUM 20 /* ��ඥ����� */
#define INFINITY 32768    /*��ʾ����ֵ������*/ 
typedef enum{DG,DN,UDG,UDN} GraphKind; 
/*ͼ�����ࣺ�ֱ��ʾ����ͼ��������������ͼ��������*/
typedef char VertexData; /* ������������ */

 typedef struct
 {
   VertexData vertex[MAX_VERTEX_NUM]; /* ������������ */
   int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; /* �ڽӾ��󣬶���Ȩͼ����1(��)��0(��)��ʾ�������ڽ���񣻶Դ�Ȩͼ����ΪȨֵ */
   int vexnum,arcnum; /* ͼ�Ķ������ͱ��� */
   GraphKind kind; /* ͼ�������־ */
 } AdjMatrix;

 int LocateVex(AdjMatrix G,VertexData v)
 { /* ��ʼ������ͼG���ڣ�u��G�ж�������ͬ���� */
   /* �����������G�д��ڶ���u���򷵻ظö�����ͼ��λ�ã����򷵻�-1 */
   int i;
   for(i=0;i<G.vexnum;i++)
     if(G.vertex[i]==v) return i;
   return -1;
 }


 void Display(AdjMatrix G)
 { /* ����ڽӾ���洢��ʾ��ͼG */
   int i,j;
   
   printf("%d vertexs are:",G.vexnum);
   for(i=0;i<G.vexnum;i++) /* ���G.vertex[ ] */
     printf("%c ",G.vertex[i]);
   printf("\nG.arcs[ ][ ]:\n"); /* ���G.arcs[ ][ ] */
   for(i=0;i<G.vexnum;i++)
   {
     for(j=0;j<G.vexnum;j++)
       printf("%d ",G.arcs[i][j]);
     printf("\n");
   }

 }


void CreateDG(AdjMatrix *G)
{ /*   �����ڽӾ����ʾ������������ͼ(*G)   */
 int i,j,k;     
 VertexData v1,v2;
 (*G).kind=DN; 
 scanf("%d,%d%*c",&(*G).vexnum,&(*G).arcnum);  /*����ͼ�Ķ������ͻ���*/  
 for(i=0;i<(*G).vexnum;i++) /* ���춥���������� */
  scanf("%c%*c",&(*G).vertex[i]);  /*���붥������*/
 for(i=0;i<(*G).vexnum;i++) /* ��ʼ���ڽӾ��� */
   for(j=0;j<(*G).vexnum;j++)
     (*G).arcs[i][j]=0; 
 
 for(k=0;k<(*G).arcnum;k++)
    {
         scanf("%c,%c%*c",&v1,&v2);  
         /*����һ�����������������Ƽ�Ȩֵ*/
         i=LocateVex(*G,v1);
         j=LocateVex(*G,v2);
         (*G).arcs[i][j]=1;
   }       
 }