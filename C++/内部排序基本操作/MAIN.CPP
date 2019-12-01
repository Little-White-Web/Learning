#include <iostream>
#include <time.h>
#include "Sort.h"
using namespace std;

int main(){
	srand(time(0));				//设置随机种子
	printf("快速排序：\n现有数据如下：\t");
	int L1[11];				//定义数组L1
	for(int i=1;i<=10;i++){
		L1[i]=rand()%20;		//给数组赋初值（随机值）
		printf("%d\t",L1[i]);
	}
	QuickSort(L1,1,11);			//快速排序
	printf("\n排序后如下：\t");
	for(i=1;i<=10;i++){
		printf("%d\t",L1[i]);		//打印排序后的数据
	}

	printf("\n\n********************************************************\n\n");

	printf("堆排序：\n现有数据如下：\t");
	int L2[11];				//定义数组L2
	for(i=1;i<=10;i++){
		L2[i]=rand()%20;		//给数组赋初值（随机值）
		printf("%d\t",L2[i]);
	}
	HeapSort(L2,11);			//堆排序
	printf("\n排序后如下：\t");
	for(i=1;i<=10;i++){
		printf("%d\t",L2[i]);		//打印排序后的数据
	}
	printf("\n\n");
	return OK;
}
