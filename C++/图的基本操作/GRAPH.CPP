#include <iostream>
#include <queue>
#include "Graph.h"
using namespace std;

//邻接矩阵操作
int CreateUDN(MGraph &G){		//构造无向网
	G.kind=UDN;
	int adj,info;			//临时权值，弧信息
	char v1,v2;			//临时顶点
	printf("输入顶点数、弧数、弧信息标志（0或!0），请用空格隔开：");
	scanf("%d %d %d",&G.vexnum,&G.arcnum,&info);
	getchar();					//抵消回车符
	for(int i=0;i<G.vexnum;i++){
		printf("输入第%d个顶点：",i+1);
		scanf("%c",&G.vexs[i]);			//输入顶点
		getchar();				//抵消回车符
	}
	for(i=0;i<G.vexnum;i++){
		for(int j=0;j<G.vexnum;j++){
			G.arcs[i][j].adj=INFINITY;	//初始化邻接矩阵
			G.arcs[i][j].info=NULL;		//弧的权值为无穷，信息为空
		}
	}
	for(int k=0;k<G.arcnum;k++){
		printf("输入第%d条边的两个顶点及权值：",k+1);
		scanf("%c %c %d",&v1,&v2,&adj);		//输入弧的权值及其两个端点
		getchar();				//抵消回车符
		i=LocateVex(G,v1);			//定位端点1在图中的位置
		int j=LocateVex(G,v2);			//定位端点2
		if(i!=-1 && j!=-1){			//判断定位是否正确（图中是否有v1,v2）
			G.arcs[i][j].adj=adj;		//给弧<v1,v1>赋权值
			if(info){
				G.arcs[i][j].info=(char*)malloc(30*sizeof(char));
				if(!G.arcs[i][j].info) exit(FALSE);
				printf("输入弧信息：");
				gets(G.arcs[i][j].info);//输入弧信息
			}
		}
		G.arcs[j][i].adj=G.arcs[i][j].adj;	//无向网，弧权值对称
		G.arcs[j][i].info=G.arcs[i][j].info;	//弧信息对称
	}
	return OK;
}

int CreateDN(MGraph &G){				//构造有向网
	G.kind=DN;
	int adj,info;					//临时权值，弧信息
	char v1,v2;					//临时顶点
	printf("输入顶点数、弧数、弧信息标志（0或!0），请用空格隔开：");
	scanf("%d %d %d",&G.vexnum,&G.arcnum,&info);
	getchar();					//抵消回车符
	for(int i=0;i<G.vexnum;i++){
		printf("输入第%d个顶点：",i+1);
		scanf("%c",&G.vexs[i]);			//输入顶点
		getchar();				//抵消回车符
	}
	for(i=0;i<G.vexnum;i++){
		for(int j=0;j<G.vexnum;j++){
			G.arcs[i][j].adj=INFINITY;	//初始化邻接矩阵
			G.arcs[i][j].info=NULL;		//弧的权值为无穷，信息为空
		}
	}
	for(int k=0;k<G.arcnum;k++){
		printf("输入第%d条边的两个顶点及权值：",k+1);
		scanf("%c %c %d",&v1,&v2,&adj);		//输入弧的权值及其两个端点
		getchar();				//抵消回车符
		i=LocateVex(G,v1);			//定位端点1在图中的位置
		int j=LocateVex(G,v2);			//定位端点2
		if(i!=-1 && j!=-1){			//判断定位是否正确（图中是否有v1,v2）
			G.arcs[i][j].adj=adj;		//给弧<v1,v1>赋权值
			if(info){
				G.arcs[i][j].info=(char*)malloc(30*sizeof(char));
				if(!G.arcs[i][j].info) exit(FALSE);
				printf("输入弧信息：");
				gets(G.arcs[i][j].info);//输入弧信息
			}
		}
	}
	return OK;
}

int LocateVex(MGraph G,char v){				//定位顶点v在图中的位置
	for(int i=0;i<G.vexnum;i++){
		if(v==G.vexs[i]) return i;
	}
	return -1;
}

int display(MGraph G,int v){				//打印顶点
	printf("%c\t",G.vexs[v]);
	return OK;
}

int DFSTraverse(MGraph G,bool visited[],int (*Visit)(MGraph G,int v)){//深度优先遍历
	for(int i=0;i<G.vexnum;i++){
		visited[i]=false;			//初始化访问标志
	}
	for(i=0;i<G.vexnum;i++){
		if(!visited[i]) DFS(G,i,visited,Visit);	//对未访问的节点调用DFS
	}
	return OK;
}

int DFS(MGraph G,int v,bool visited[],int (*Visit)(MGraph G,int v)){//递归深度遍历
	visited[v]=true;				//标志置true
	Visit(G,v);					//访问节点
	for(int i=0;i<G.vexnum;i++){
		if(G.arcs[v][i].adj!=INFINITY && !visited[i]){//获得已访问节点的邻接点
			DFS(G,i,visited,Visit);		//对该节点调用DFS
		}
	}
	return OK;
}

int BFSTraverse(MGraph G,bool visited[],int (*Visit)(MGraph G,int v)){//广度优先遍历
	queue<int> Q;					//定义一个int型队列Q
	for(int i=0;i<G.vexnum;i++){
		visited[i]=false;			//初始化访问标志为false
	}
	for(i=0;i<G.vexnum;i++){
		if(!visited[i]){			//若标志为false
			visited[i]=true;		//则标志置true
			Visit(G,i);			//然后访问该顶点
			Q.push(i);			//顶点入队
			while(!Q.empty()){
				int j=Q.front();	//获取队头顶点
				Q.pop();		//弹出该顶点
				for(int k=0;k<G.vexnum;k++){
					if(G.arcs[j][k].adj!=INFINITY && !visited[k]){//获取该顶点的邻接点
						if(!visited[k]){
							visited[k]=true;	//操作同上
							Visit(G,k);
							Q.push(k);		//该邻接点入队，用以继续循环
						}
					}
				}
			}
		}
	}
	return OK;
}

//*********************************************************************************

//邻接表操作
int CreateDN(LGraph &G){				//构造有向网
	G.kind=DN;
	char info[10];					//临时弧信息(权值)
	char v1,v2;					//临时顶点
	printf("输入顶点数、弧数，请用空格隔开：");
	scanf("%d %d",&G.vexnum,&G.arcnum);
	getchar();					//抵消回车符
	for(int i=0;i<G.vexnum;i++){
		printf("输入第%d个顶点：",i+1);
		scanf("%c",&G.vertices[i].data);	//输入顶点
		getchar();				//抵消回车符
		G.vertices[i].firstarc=NULL;
	}
	for(int k=0;k<G.arcnum;k++){
		printf("输入第%d条弧的两个顶点及权值：",k+1);
		scanf("%c %c %s",&v1,&v2,info);		//输入弧的权值及其两个端点
		getchar();				//抵消回车符
		i=LocateVex(G,v1);			//定位端点1在图中的位置
		int j=LocateVex(G,v2);			//定位端点2
		if(i!=-1 && j!=-1){			//判断定位是否正确（图中是否有v1,v2）
			ArcNode* p=(ArcNode*)malloc(sizeof(ArcNode));	//分配一条弧p
			if(!p) exit(FALSE);
			p->nextarc=G.vertices[i].firstarc;		//将p的下一条弧指向v1的第一条弧
			p->adjvex=j;					//p指向v2
			G.vertices[i].firstarc=p;			//v1的第一条弧指向p（即指向v2）
			G.vertices[i].firstarc->info=(char*)malloc(30*sizeof(char));//分配v1的第一条弧信息（即<v1，,2>权值）
			G.vertices[i].firstarc->info=info;		//赋值
		}
	}
	return OK;
}

int LocateVex(LGraph G,char v){				//定位v的位置
	for(int i=0;i<G.vexnum;i++){
		if(v==G.vertices[i].data) return i;
	}
	return -1;
}

int FirstAdjVex(LGraph G,int v){			//返回第v个节点的第一个邻接点
	if(NULL != G.vertices[v].firstarc)		//若存在该节点
		return G.vertices[v].firstarc->adjvex;	//则将其返回
	else return -1;					//否则（不存在）返回-1
}

int NextAdjVex(LGraph G,int v,int w){			//返回第v个节点相对于w的下一个邻接点
	ArcNode* p=G.vertices[v].firstarc;		//弧指针
	while(p){
		if(p->adjvex==w){			//若w是v的邻接点			
			p=p->nextarc;			//得到相对于w的下一个邻接点
			if(NULL != p) return p->adjvex;	//若存在则返回该邻接点
			else return -1;			//否则返回-1
		}
		else p=p->nextarc;			//若还未找到w，则继续找下一个
	}
}

char GetVex(LGraph G,int v){				//返回第v个节点的信息
	return G.vertices[v].data;
}

int display(LGraph G,int v){				//打印顶点
	printf("%c\t",G.vertices[v].data);
	return OK;
}

int DFSTraverse(LGraph G,bool visited[],int (*Visit)(LGraph G,int v)){//深度优先遍历
	for(int i=0;i<G.vexnum;i++){
		visited[i]=false;			//初始化访问标志
	}
	for(i=0;i<G.vexnum;i++){
		if(!visited[i]) DFS(G,i,visited,Visit);	//对未访问的节点调用DFS
	}
	return OK;
}

int DFS(LGraph G,int v,bool visited[],int (*Visit)(LGraph G,int v)){//递归深度遍历
	visited[v]=true;				//标志置true
	Visit(G,v);					//访问节点
	for(int i=FirstAdjVex(G,v);i>=0;i=NextAdjVex(G,v,i)){//获得已访问节点的邻接点
		if(!visited[i]){			//若未访问
			DFS(G,i,visited,Visit);		//则调用DFS进行访问
		}
	}
	return OK;
}

int BFSTraverse(LGraph G,bool visited[],int (*Visit)(LGraph G,int v)){	//广度优先遍历
	queue<int> Q;					//定义一个int型队列Q
	for(int i=0;i<G.vexnum;i++){
		visited[i]=false;			//初始化访问标志为false
	}
	for(i=0;i<G.vexnum;i++){
		if(!visited[i]){			//若标志为false
			visited[i]=true;		//则标志置true
			Visit(G,i);			//然后访问该顶点
			Q.push(i);			//顶点入队
			while(!Q.empty()){
				int j=Q.front();	//获取队头顶点
				Q.pop();		//弹出该顶点
				for(int k=FirstAdjVex(G,j);k>=0;k=NextAdjVex(G,j,k)){//获取该顶点的邻接点
					if(!visited[k]){
						visited[k]=true;	//操作同上
						Visit(G,k);
						Q.push(k);		//该邻接点入队，用以继续循环
					}
				}
			}
		}
	}
	return OK;
}
