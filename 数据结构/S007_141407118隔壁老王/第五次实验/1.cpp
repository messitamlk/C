#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define OVERFLOW  -1
#define OK 1
#define ERROR 0
typedef  char	TElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
int CreateBiTree(BiTree T)
{
TElemType ch;
scanf("%s",&ch);
if(ch=='0'){T = NULL; return 0;}
else{
if(! (T= (BiTNode*)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
T->data = ch;
printf("ÇëÊäÈë×óº¢×Ó£º");
CreateBiTree(T->lchild);
printf("ÇëÊäÈëÓÒº¢×Ó£º");
CreateBiTree(T->rchild);
}
return OK;
}
int Visit(TElemType e)
{
	printf("%s",e);
	return OK;
}
int PreOederTraverse(BiTree T,Visit)
{
	if(T)
	{
		if(Visit(T->data))
			if(PreOederTraverse(T->lchild,Visit))
				if(PreOederTraverse(T->rchild,Visit))
					return OK;
				return ERROR;
	}else return OK;
}
int main()
{
	BiTree T;
	CreateBiTree(T);
	PreOederTraverse(T,Visit);
	return 0 ;

}