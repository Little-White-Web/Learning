#include <iostream>
#include "Stack&Queue.h"
using namespace std;

int main(){
	printf("顺序栈操作：\n");
	SqStack S;
	InitStack(S);			//初始化顺序栈
	if(StackEmpty(S)){
		printf("栈空！现依次插入1到5！\n");
		for(int i=1;i<=5;i++){
			Push(S,i);			//数据入栈
		}
		printf("插入之后的数据：");
		for(i=1;i<=5;i++){
			int e;
			Pop(S,e);			//数据出栈并记录
			printf("%d\t",e);
		}
		printf("\n\n");
	}

	printf("单队列操作：\n");
	LinkQueue Q;
	InitQueue(Q);			//初始化单队列
	if(QueueEmpty(Q)){
		printf("队空！现依次插入1到5！\n");
		for(int i=1;i<=5;i++){
			EnQueue(Q,i);		//数据入队
		}
		printf("插入之后的数据：");
		for(i=1;i<=5;i++){
			int e;
			DeQueue(Q,e);		//数据出队并记录
			printf("%d\t",e);
		}
		printf("\n");
	}
	return OK;
}