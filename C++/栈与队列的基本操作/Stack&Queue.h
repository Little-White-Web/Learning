#define TRUE 1
#define FALSE -1
#define OK 1
#define ERROR -1

typedef struct{			//顺序栈结构
	int* base;
	int* top;
	int stacksize;
}SqStack;

typedef struct QNode{		//单链队列结构
	int data;
	struct QNode* next;
}QNode;
typedef struct{			//队头、队尾指针结构
	QNode* front;
	QNode* rear;
}LinkQueue;

int InitStack(SqStack &S);	//栈与队列的基本操作
int InitQueue(LinkQueue &Q);

int StackEmpty(SqStack S);
int QueueEmpty(LinkQueue Q);

int Pop(SqStack &S,int &e);
int DeQueue(LinkQueue &Q,int &e);

int Push(SqStack &S,int &e);
int EnQueue(LinkQueue &Q,int &e);
