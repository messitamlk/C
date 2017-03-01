#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 20
#define STACKINCREMENT  1
#define  OK 1
#define OVERFLOW -1
#define TRUE  1
#define FALSE   0
typedef int SElemType;
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack,*Stack;
int StackEmpty(SqStack &s);//��ջSΪ�գ��򷵻�TURE,���򷵻�FALSE
Stack InitStack(SqStack &s);//����һ������Ϊʮ�Ŀ�ջ�����������ַ
int Push(SqStack &S, SElemType);//ѹջ
SElemType Pop(SqStack &S, SElemType&e);
void conversion();//��������һ���Ǹ�ʮ������������ӡ��������ֵ��N������
int main()
{ 
	
	/*SqStack S;
	int e;
	 InitStack(S);
	Push(S, 5);
	Push(S, 6);
	Pop(S,e);
	
printf("%d",e);*/
conversion();
	return 0;
}
Stack InitStack(SqStack &s)
{
	
	
 s.top= (SElemType*)malloc(STACK_INIT_SIZE *sizeof(SElemType));
	s.base = s.top;
	s.stacksize = STACK_INIT_SIZE;
	return  &s;
}
int Push(SqStack &s, SElemType e)
{
	if (s.top - s.base >= s.stacksize)
	{
		s.base = (SElemType *)realloc(s.base, (STACK_INIT_SIZE + STACKINCREMENT)*sizeof(SElemType));
		s.top = s.base + s.stacksize;
		s.stacksize += STACKINCREMENT;
	}
	*s.top++ = e;
	return OK;
}
SElemType Pop(SqStack &s, SElemType &e)

{
	
	if (s.base == s.top)return OVERFLOW;
	e = *--s.top;
	return OK;
}
void conversion() {
	SqStack Q;
	int n,N,e;
	InitStack(Q);
	printf("������Ҫת��������\n");
	scanf("%d", &n);
	printf("������Ҫת���Ľ��ƣ�\n");
	scanf("%d", &N);
	while (n) { Push(Q, n % N);
	n = n / N;
	}
	while (StackEmpty(Q)) {
		Pop(Q, e);
		printf("%d", e);
	
	}
	printf("\n");
}
int StackEmpty(SqStack &s) {
	if (s.base == s.top)return FALSE;
	return TRUE;
}