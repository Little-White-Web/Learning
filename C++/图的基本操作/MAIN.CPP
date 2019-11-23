#include <iostream>
#include "Graph.h"
using namespace std;

int main(){
	bool visited[10];			//全局变量，访问标志

	printf("图的邻接矩阵存储：\n");
	MGraph G1;					//定义G1
	printf("创建一个有向网！\n");
	CreateDN(G1);				//构造G1
	printf("深度优先遍历：\n");
	DFSTraverse(G1,visited,display);	//深度优先遍历
	printf("\n广度优先遍历：\n");
	BFSTraverse(G1,visited,display);	//广度优先遍历

	printf("\n\n*********************************************************\n\n");

	printf("图的邻接表存储：\n");
	LGraph G2;					//定义G2
	printf("创建一个有向网！\n");
	CreateDN(G2);				//构造G2
	printf("深度优先遍历：\n");
	DFSTraverse(G2,visited,display);	//深度优先遍历
	printf("\n广度优先遍历：\n");
	BFSTraverse(G2,visited,display);	//广度优先遍历
	printf("\n");
	return OK;
}