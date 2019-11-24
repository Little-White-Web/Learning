#include <iostream>
#include "Search.h"
using namespace std;

int CreateSST(SSTable &T){				//创建有序表
	printf("创建有序表，请输入表的长度：");
	scanf("%d",&T.length);				//输入表长
	T.elem=(int*)malloc(T.length*sizeof(int));	//分配空间
	if(!T.elem) exit(FALSE);
	printf("依次输入%d个有序整数：\n",T.length);
	for(int i=0;i<T.length;i++){
		scanf("%d",&T.elem[i]);			//输入数据
		getchar();				//抵消回车符
	}
	return OK;
}

int Search_Bin(SSTable T,int key){			//折半查找
	int low=0,high=T.length-1;			//查找区间
	while(low<=high){
		int mid=(low+high)/2;			//区间的中点
		if(T.elem[mid]==key) return mid;	//找到结果，返回其下标
		else if(key<T.elem[mid]) high=mid-1;	//在前半区间查找
		else low=mid+1;				//在后半区间查找
	}
	return -1;					//查无此元素，返回-1
}

//*************************************************************************************

int CreateBST(BiTree &T){				//创建二叉排序树
	printf("创建二叉排序树，请输入数字（-1结束）：\n");
	int data;scanf("%d",&data);			//输入数据
	while(data != -1){
		getchar();				//抵消回车符
		Insert(T,data);				//插入数据到树中
		scanf("%d",&data);			//输入下一条数据
	}
	return OK;
}

BiTree SearchBST(BiTree T,int key){			//在排序树中查找key
	if(!T || T->data==key) return T;		//T为空，或T=key，返回根节点
	else if(key<T->data)
		return (SearchBST(T->lchild,key));	//key<T，在左子树查找
	else
		return (SearchBST(T->rchild,key));	//key>T，在右子树查找
}

int Insert(BiTree &T,int data){				//二叉排序树插入操作
	BiTree p=(BiTree)malloc(sizeof(BiTNode));	//分配一个节点
	if(!p) exit(FALSE);
	p->data=data;					//给该节点赋值
	p->lchild=p->rchild=NULL;			//左右孩子指针初始化NULL
	if(!T){T=p;return OK;}				//若T为空树，则p作为T的根节点
	if(!(T->lchild) && p->data<T->data){		//若T左子树为空，且p<T，则p作为T的左子树
		T->lchild=p;
		return OK;
	}
	if(!(T->rchild) && p->data>T->data){		//若T右子树为空，且p>T，则p作为T的右子树
		T->rchild=p;
		return OK;
	}
	if(p->data<T->data) Insert(T->lchild,p->data);	//若根左右都非空，则分别在，左右子树递归
	if(p->data>T->data) Insert(T->rchild,p->data);	//直到找到叶子节点，然后执行上述操作
	return OK;
}

//*******************************************************************************************

int CreateHash(HashTable &T){				//创建哈希表
	printf("创建哈希表，请输入表的容量：");
	scanf("%d",&T.size);				//输入表容量
	T.elem=(HashData*)malloc(T.size*sizeof(HashData));//分配空间给表T
	T.count=0;					//初始元素个数为0
	for(int i=0;i<T.size;i++){
		T.elem[i].data=0;
		T.elem[i].state=false;			//初始化所有单元的状态为无值
	}
	printf("依次输入数据（-1结束）：\n");
	while(T.count<T.size){
		int data;scanf("%d",&data);		//输入数据
		if(data==-1) return OK;			//若输入-1，结束输入
		int addr=data%T.size;			//Hash地址
		while(T.elem[addr].state){		//若地址冲突
			addr++;				//地址加一
			if(addr>T.size-1) addr=0;	//若新地址超出表容量，则从0号单元重新找
		}
		T.elem[addr].data=data;			//给该地址的数据赋值
		T.elem[addr].state=true;		//存数据后改状态为有值
		T.count++;				//计数加一
	}
	return OK;
}

int SearchHash(HashTable T,int key){			//哈希查找
	int addr=key%T.size;
	if(key==T.elem[addr].data) return addr;		//查找匹配，返回地址
	addr=NextAddr(T,addr,key);			//不匹配，调用递归查找
	return addr;					//返回最终地址，不一定匹配
}

int NextAddr(HashTable T,int addr,int key){		//取下一个地址（查找不匹配时使用）
	static const int start=addr;			//记录初始地址
	addr+=1;
	if(addr>T.size-1) addr=0;			//地址超出容量，从0号单元开始找
	if(addr==start) return -1;			//再次找到初始地址，说明查找失败
	if(key==T.elem[addr].data) return addr;		//查找匹配，返回该地址
	return NextAddr(T,addr,key);			//递归查找
}
