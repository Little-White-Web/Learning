#include <iostream>
#include "BiTree.h"
using namespace std;

int CreateBiTree(BiTree &T){		//按先序构造二叉树
	char ch;
	printf("请输入数据：");
	scanf("%c",&ch);
	getchar();				//抵消回车符
	if(ch=='*') T=NULL;
	else{
		if( !(T=(BiTree)malloc(sizeof(BiTNode))) ) exit(FALSE);
		T->data=ch;					//生成根节点
		CreateBiTree(T->lchild);	//构造左子树
		CreateBiTree(T->rchild);	//构造右子树
	}
	return OK;
}

int PreOrderTraverse(BiTree T,int (*Visit)(char e)){		//先序遍历
	if(T){
		if(Visit(T->data)){			//访问根节点
			if(PreOrderTraverse(T->lchild,Visit)){		//遍历左子树
				if(PreOrderTraverse(T->rchild,Visit)) return OK;	//遍历右子树
			}
		}
		return ERROR;
	}
	else return OK;
}

int InOrderTraverse(BiTree T,int (*Visit)(char e)){		//中序遍历
	if(T){
		if(InOrderTraverse(T->lchild,Visit)){	//遍历左子树
			if(Visit(T->data)){					//访问根节点
				if(InOrderTraverse(T->rchild,Visit)) return OK;	//遍历右子树
			}
		}
	}
	return OK;
}

int PrintElement(char e){			//打印元素
	printf("%c\t",e);
	return OK;
}
