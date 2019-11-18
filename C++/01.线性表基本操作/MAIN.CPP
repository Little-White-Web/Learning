#include <iostream>
#include "List.h"
using namespace std;

int main(){
	printf("顺序表操作:\n");
	SqList L1,L2,L3;				//定义三个顺序表
	InitList(L1);InitList(L2);		//初始化L1，L2
	printf("完成初始化顺序表L1,L2!\n");
	printf("L1:\t");
	ListDisplay(L1);				//打印L1
	printf("L2:\t");
	ListDisplay(L2);				//打印L2
	printf("插入数据:\n");
	for(int i=1;i<=5;i++){			//L1，L2插入测试数据
		ListInsert(L1,i,i);
		ListInsert(L2,i,i+3);
	}
	printf("L1:\t");
	ListDisplay(L1);				//再次打印L1
	printf("L2:\t");
	ListDisplay(L2);				//再次打印L2
	MergeList(L1,L2,L3);			//L1，L2合并到L3
	printf("完成L1与L2合并到L3!\n");
	printf("L3:\t");
	ListDisplay(L3);				//打印L3

	printf("\n单链表操作:\n");
	LinkList L4,L5,L6;				//定义三个链表
	InitList(L4);InitList(L5);		//初始化L4，L5
	printf("完成初始化单链表L4,L5!\n");
	printf("L4:\t");
	ListDisplay(L4);				//打印L4
	printf("L5:\t");
	ListDisplay(L5);				//打印L5
	printf("插入数据:\n");
	for(i=1;i<=5;i++){				//L4，L5插入测试数据
		ListInsert(L4,i,i+10);
		ListInsert(L5,i,i+12);
	}
	printf("L4:\t");
	ListDisplay(L4);				//再次打印L4
	printf("L5:\t");
	ListDisplay(L5);				//再次打印L5
	MergeList(L4,L5,L6);			//L4，L5合并到L6
	printf("完成L4与L5合并到L6!\n");
	printf("L6:\t");
	ListDisplay(L6);				//打印L6
	return OK;
}