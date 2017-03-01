#include<stdio.h>
#include<stdlib.h>
#define  NULL  0
#define  N     4     /* N��ʾͼ�Ķ��������� */
typedef  struct  ArcNode{
   int      adjvex;
   struct   ArcNode *nextarc;
}ArcNode;
typedef  struct  VNode{
   int      data;     /* ע��ͼ�Ķ�����Ϣ������ */
   ArcNode  *firstarc;
} VNode,Adjlist[N];   /* ���N������ */
int visited[N]={0};        /* ȫ�ֱ�������ֵ��0�������ظ����� */
typedef  struct{
   Adjlist   vertices;
   int       vexnum,arcnum;
}ALGraph;    /*�ڽӱ�*/
void Create(ALGraph *G){ /* ����һ������ͼ */
   int       i,j,k;
   ArcNode   *s;
   printf("Please input vexnum  and   arcnum:");
   scanf("%d%d",&G->vexnum,&G->arcnum); 
 /* ���붥����(���N)�ͱ��� */
   printf("Please input each vex message,vex message is int and from 0 start :\n");
   for(i=0;i<G->vexnum;i++){
        /* ����ÿ��������Ϣ��ע�ⶥ�������������������Ŵ�0��ʼ 
������Ϣ�Ƕ�����*/
       scanf("%d",&G->vertices[i].data);
       G->vertices[i].firstarc=NULL;
}
   printf("Please input the edge,edge message is int,int:\n");
   for(k=0;k<G->arcnum;k++){ 
        /* ����ÿ������Ϣ��ע��¼��ߵ���ʽ�����綥��0��1֮���бߣ� */
/* ¼����ȷ��ʽ�ǣ�0,1 */
       scanf("%d,%d",&i,&j);
       s=(ArcNode *)malloc(sizeof(ArcNode));
       s->adjvex=j;
       s->nextarc=G->vertices[i].firstarc;
       G->vertices[i].firstarc=s;
   }
}


void   DFS(ALGraph G,int v){
   /* �Ӷ���v��������������ȱ���,ע�����G������ */
   ArcNode    *w;
   visited[v]=1;
   printf("%3d",G.vertices[v].data);
   for(w=G.vertices[v].firstarc;w;w=w->nextarc)
      if(!visited[w->adjvex])
         DFS(G, w->adjvex);
}
void   DFSGraph(ALGraph G){   /* ���ԴӸ������DFS */
     int i;
     for(i=0;i<G.vexnum;i++)
        if(!visited[i]) {
           printf("\nFrom %d DFS is:",i);
           DFS(G,i);       /* ��i������ȱ��� */
        }
}

main(){
   ALGraph     G;
   Create(&G);
   DFSGraph (G);
   getchar();
   return 0;
}
