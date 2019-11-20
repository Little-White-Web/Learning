#include <iostream>
#include "BiTree.h"
using namespace std;

int CreateBiTree(Bitree &T){		//�������������
	int d;
	scanf("%d",&d);
	if(!d) T=NULL;
	else{
		if( !(T=(BiTree)malloc(sizeof(BiTNode))) ) exit(FALSE);
		T->data=d;					//���ɸ��ڵ�
		CreateBiTree(T->lchild);	//����������
		CreateBiTree(T->rchild);	//����������
	}
	retrun OK;
}

int PreOrderTraverse(BiTree T,int (*Visit)(int e)){		//�������
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

int InOrderTraverse(BiTree T,int (*Visit)(int e)){		//�������
	InitStack();Push(S,T);		//��ָ���ջ
	while(!StackEmpty(S)){
		while(GetTop(S,p) && p) Push(S,p->lchild);		//�����ߵ���ͷ
		Pop(S,p);				//��ָ����ջ
		if(!StackEmpty(S)){				//���ʽڵ㣬����һ��
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