#define TRUE 1
#define OK 1
#define ERROR 0
#define FALSE 0
#define INFINITY INT_MAX    //最大值(用来代表无穷大)
#define MAX_VERTEX_NUM 20	//最大顶点数
typedef enum { DG,DN,UDG,UDN } GraphKind;	//{有向图，有向网，无向图，无向网}

typedef struct ArcCell{						//弧（边）的定义
	int adj;								//权值
	char* info;								//弧相关信息的指针
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{								//图的邻接矩阵存储表示
	char vexs[MAX_VERTEX_NUM];				//顶点向量
	AdjMatrix arcs;							//邻接矩阵
	int vexnum,arcnum;						//顶点数，弧数
	GraphKind kind;							//图的种类
}MGraph;

int CreateUDN(MGraph &G);					//邻接矩阵操作
int CreateDN(MGraph &G);
int LocateVex(MGraph G,char v);
int display(MGraph G,int v);
int DFSTraverse(MGraph G,bool visited[],int (*Visit)(MGraph G,int v));
int DFS(MGraph G,int v,bool visited[],int (*Visit)(MGraph G,int v));
int BFSTraverse(MGraph G,bool visited[],int (*Visit)(MGraph G,int v));

//********************************************************************

typedef struct ArcNode{			//弧定义
	int adjvex;					//该弧指向的顶点
	struct ArcNode* nextarc;	//指向下一条弧的指针
	char* info;					//弧相关信息的指针
}ArcNode;
typedef struct VNode{			//顶点定义
	char data;					//顶点信息
	ArcNode* firstarc;			//指向第一条弧的指针
}VNode, AdjList[MAX_VERTEX_NUM];
typedef struct{					//图的邻接表存储表示
	AdjList vertices;
	int vexnum,arcnum;			//顶点数，弧数
	GraphKind kind;				//图的种类
}LGraph;

int CreateDN(LGraph &G);		//邻接表操作
int LocateVex(LGraph G,char v);
int FirstAdjVex(LGraph G,int v);
int NextAdjVex(LGraph G,int v,int w);
char GetVex(LGraph G,int v);
int display(LGraph G,int v);
int DFSTraverse(LGraph G,bool visited[],int (*Visit)(LGraph G,int v));
int DFS(LGraph G,int v,bool visited[],int (*Visit)(LGraph G,int v));
int BFSTraverse(LGraph G,bool visited[],int (*Visit)(LGraph G,int v));