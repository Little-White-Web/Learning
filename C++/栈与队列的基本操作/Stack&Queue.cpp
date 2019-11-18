#include <iostream>
#include "Stack&Queue.h"
using namespace std;

int InitStack(SqStack &S){			//�����ջ
	S.base=(int*)malloc(100*sizeof(int));
	if(!S.base) exit(FALSE);
	S.top=S.base;
	S.stacksize=100;
	return OK;
}

int InitQueue(LinkQueue &Q){		//����ն���
	Q.front=Q.rear=(QNode*)malloc(sizeof(QNode));
	if(!Q.front) exit(FALSE);
	Q.front->next=NULL;
	return OK;
}

int StackEmpty(SqStack S){			//ջ�п�
	if(S.top==S.base) return TRUE;
	else return FALSE;
}

int QueueEmpty(LinkQueue Q){		//�����п�
	if(Q.rear==Q.front) return TRUE;
	else return FALSE;
}

int Pop(SqStack &S,int &e){			//��ջ
	if(S.top==S.base) return ERROR;
	e=*--S.top;
	return OK;
}

int DeQueue(LinkQueue &Q,int &e){	//����
	if(Q.front==Q.rear) return ERROR;
	QNode* p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	return OK;
}

int Push(SqStack &S,int &e){		//��ջ
	if(S.top-S.base>=S.stacksize){	//ջ����׷�ӿռ�
		S.base=(int*)realloc(S.base,(S.stacksize+10)*sizeof(int));
		if(!S.base) exit(FALSE);
		S.top=S.base+S.stacksize;
		S.stacksize+=10;
	}
	*S.top++=e;
	return OK;
}

int EnQueue(LinkQueue &Q,int &e){	//���
	QNode* p=(QNode*)malloc(sizeof(QNode));
	if(!p) exit(FALSE);
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
}