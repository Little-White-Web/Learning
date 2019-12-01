#include <iostream>
#include "Sort.h"
using namespace std;

int Partition(int *L,int low,int high){
	L[0]=L[low];						//用第一个记录作枢轴记录
	int pivotkey=L[low];					//枢轴
	while(low<high){					//从表两端交替向中间扫描
		while(low<high && L[high]>=pivotkey) --high;
		L[low]=L[high];					//将比枢轴小的移到低端
		while(low<high && L[low]<=pivotkey) ++low;
		L[high]=L[low];					//将比枢轴大的移到高端
	}
	L[low]=L[0];						//枢轴记录到位
	return low;						//返回枢轴位置
}

void QuickSort(int *L,int low,int high){			//快速排序
	if(low<high){						//长度大于1
		int pivotloc=Partition(L,low,high);		//将L分为两半，并获得枢轴位置
		QuickSort(L,low,pivotloc-1);			//对低子表递归排序
		QuickSort(L,pivotloc+1,high);			//对高子表递归排序
	}
}

void HeapAdjust(int *L,int s,int m){				//调整数据使之成为大顶堆
	int lchild=2*s;						//左孩子
	int rchild=2*s+1;					//右孩子
	int max=s;						//最大者
	if(s<=m){
		if(lchild<=m && L[lchild]>L[max])
			max=lchild;				//若左孩子大于最大者，则替换最大者
		if(rchild<=m && L[rchild]>L[max])
			max=rchild;				//右孩子同理
		if(s!=max){					//若根节点不是最大者
			L[0]=L[s];				//则以0号单元为中间值，交换根节点与最大者
			L[s]=L[max];
			L[max]=L[0];
			HeapAdjust(L,max,m);			//递归调整
		}
	}
}

void HeapSort(int *L,int n){					//堆排序
	for(int i=n-1;i>0;--i)
		HeapAdjust(L,i,n);				//把L[1...L.length]建成大顶堆
	for(i=n-1;i>1;--i){
		L[0]=L[1];					//交换堆顶与最后一个元素，0号单元作中间值
		L[1]=L[i];
		L[i]=L[0];
		HeapAdjust(L,1,i-1);				//重新调整大顶堆
	}
}
