#include <iostream>
#include "BiTree.h"
using namespace std;

int CreateBiTree(BiTree &T){			//按先序构造二叉树
	char ch;
	scanf("%c",&ch);
	if(ch=='*') T=NULL;
	else{
		if( !(T=(BiTree)malloc(sizeof(BiTNode))) ) exit(FALSE);
		T->data=ch;			//生成根节点
		CreateBiTree(T->lchild);	//构造左子树
		CreateBiTree(T->rchild);	//构造右子树
	}
	return OK;
}

int PreOrderTraverse(BiTree T,int (*Visit)(char e)){		//先序遍历
	if(T){
		if(Visit(T->data)){				//访问根节点
			if(PreOrderTraverse(T->lchild,Visit)){	//遍历左子树
				if(PreOrderTraverse(T->rchild,Visit)) return OK;//遍历右子树
			}
		}
		return ERROR;
	}
	else return OK;
}

int InOrderTraverse(BiTree T,int (*Visit)(char e)){	//中序遍历
	if(T){
		if(InOrderTraverse(T->lchild,Visit)){	//遍历左子树
			if(Visit(T->data)){		//访问根节点
				if(InOrderTraverse(T->rchild,Visit)) return OK;//遍历右子树
			}
		}
	}
	return OK;
}

int PostOrderTraverse(BiTree T,int (*Visit)(char e)){		//后序遍历
	if(T){
		if(PostOrderTraverse(T->lchild,Visit)){		//遍历左子树
			if(PostOrderTraverse(T->rchild,Visit)){	//遍历右子树
				if(Visit(T->data)) return OK;	//访问根节点
			}
		}
	}
	return OK;
}

int TreeDeep(BiTree T){					//求树的深度
	int deep=0;					//初始深度为0
	if(T){
		int ldeep=TreeDeep(T->lchild);		//求左子树深度
		int rdeep=TreeDeep(T->rchild);		//求右子树深度
		deep = ldeep>=rdeep ? ldeep+1:rdeep+1;	//将较大的深度+1赋给根节点的深度
	}
	return deep;
}

int LeafCount(BiTree T){				//求叶子节点个数
	static int count=0;				//初始个数为0
	if(T){
		if(!T->lchild && !T->rchild){
			count++;			//左右孩子都为空（即叶子）计数加一
		}
		LeafCount(T->lchild);			//访问左节点
		LeafCount(T->rchild);			//访问右节点
	}
	return count;
}

int PrintElement(char e){				//打印元素(Visit函数)
	printf("%c\t",e);
	return OK;
}
