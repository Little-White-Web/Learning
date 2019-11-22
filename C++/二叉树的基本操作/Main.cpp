#include <iostream>
#include "BiTree.h"
using namespace std;

int main(){
	BiTree T;			//生成一颗二叉树
	printf("先序创建二叉树，输入*结束叶子节点的输入！\n>>");
	CreateBiTree(T);	//构造（初始化）这颗二叉树

	printf("\n先序遍历：\n");
	PreOrderTraverse(T,PrintElement);	//先序遍历
	printf("\n\n中序遍历：\n");
	InOrderTraverse(T,PrintElement);	//中序遍历
	printf("\n\n后序遍历\n");
	PostOrderTraverse(T,PrintElement);	//后序遍历
	printf("\n\n");

	printf("树的深度=%d\n",TreeDeep(T));	//打印树的深度
	printf("叶子个数=%d\n\n",LeafCount(T));	//打印叶子节点数
	return OK;
}
