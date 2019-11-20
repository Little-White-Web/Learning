#include <iostream>
#include "BiTree.h"
using namespace std;

int CreateBiTree(Bitree &T){		//按先序构造二叉树
	int d;
	scanf("%d",&d);
	if(!d) T=NULL;
	else{
		if( !(T=(BiTree)malloc(sizeof(BiTNode))) ) exit(FALSE);
		T->data=d;					//生成根节点
		CreateBiTree(T->lchild);	//构造左子树
		CreateBiTree(T->rchild);	//构造右子树
	}
	retrun OK;
}

int PreOrderTraverse(BiTree T,int (*Visit)(int e)){		//先序遍历
	if(T){
		if(Visit(T->data)){
			if(PreOrderTraverse(T->lchild)){
				if(PreOrderTraverse(T->rchild)) return OK;
			}
		}
		return ERROR;
	}
	else return OK;
}

int InOrderTraverse(BiTree T,int (*Visit)(int e)){		//中序遍历
	InitStack();Push(S,T);		//根指针进栈
	while(!StackEmpty(S)){
		while(GetTop(S,p) && p) Push(S,p->lchild);		//向左走到尽头
		Pop(S,p);				//空指针退栈
		if(!StackEmpty(S)){				//访问节点，向右一步
			Pop(S,p);
			if(!Visit(P->data)) return ERROR;
			Push(S,p->rchild);
		}
	}
	return OK;
}

int PrintElement(int e){
	print("%d\t",e);
	return OK;
}