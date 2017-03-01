#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define OVERFLOW -1
typedef int QElemType;
typedef struct QNode
{
QElemType data;
struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
QueuePtr front;
QueuePtr rear;
}LinkQueue;
int InitQueue(LinkQueue&Q){
	Q.front =Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}
int EnQueue(LinkQueue&Q,QElemType e){
QueuePtr p;
p = (QueuePtr)malloc(sizeof(QNode));
if(!Q.front)exit(OVERFLOW);
p->data = e;
p->next = NULL;
Q.rear->next = p;
Q.rear = p;
return OK;
}//入队
int DeQueue(LinkQueue&Q,QElemType &e){
QueuePtr p;
if(Q.front==Q.rear)return OVERFLOW ;
p = Q.front->next;
e = p->data;
Q.front->next = p->next;
if(Q.rear == p)Q.rear = Q.front;
free(p);//出队
return OK;
}
int main ()
{
	LinkQueue Q;
	int e=5,i=0;
	InitQueue(Q);
	EnQueue(Q,5);
printf("%d",DeQueue(Q,i));
printf("%d",i);

	return 0;

}