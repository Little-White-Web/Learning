#define TRUE 1
#define FALSE -1
#define OK 1
#define ERROR -1

typedef struct{			//˳��ջ�ṹ
	int* base;
	int* top;
	int stacksize;
}SqStack;

typedef struct QNode{		//�������нṹ
	int data;
	struct QNode* next;
}QNode;
typedef struct{				//��ͷ����βָ��ṹ
	QNode* front;
	QNode* rear;
}LinkQueue;

int InitStack(SqStack &S);		//ջ����еĻ�������
int InitQueue(LinkQueue &Q);

int StackEmpty(SqStack S);
int QueueEmpty(LinkQueue Q);

int Pop(SqStack &S,int &e);
int DeQueue(LinkQueue &Q,int &e);

int Push(SqStack &S,int &e);
int EnQueue(LinkQueue &Q,int &e);