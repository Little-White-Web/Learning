#include <iostream>
#include "Search.h"
using namespace std;

int main(){
	int key;				//键值
	printf("折半查找：\n");
	SSTable T1;				//定义顺序表T1
	CreateSST(T1);				//构造T1
	printf("输入key值：");
	scanf("%d",&key);			//输入key值
	if(Search_Bin(T1,key)!=-1)		//折半查找key
		printf("查找成功！下标为%d\n",Search_Bin(T1,key)+1);
	else printf("查找失败！\n");

	printf("\n*************************************************\n\n");

	printf("二叉排序树：\n");
	BiTree T2=NULL;				//定义二叉树T2,并初始化NULL（不初始化将异常，这是个巨坑，虽然是低级错误）
	CreateBST(T2);				//构造T2
	printf("输入key值：");
	scanf("%d",&key);			//输入key值
	if(SearchBST(T2,key))			//在排序树中查找key
		printf("查找成功！地址为%p\n",SearchBST(T2,key));
	else printf("查找失败！\n");

	printf("\n*************************************************\n\n");

	printf("哈希表：\n");
	HashTable T3;				//定义哈希表T3
	CreateHash(T3);				//构造T3
	printf("输入key值：");
	scanf("%d",&key);			//输入key值
	if(SearchHash(T3,key)!=-1)		//在哈希表中查找key
		printf("查找成功！下标为%d\n\n",SearchHash(T3,key)+1);
	else printf("查找失败！\n\n");
	return OK;
}
