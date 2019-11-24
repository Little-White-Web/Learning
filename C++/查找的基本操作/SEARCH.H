#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0

typedef struct{				//顺序表
	int* elem;
	int length;
}SSTable;

int CreateSST(SSTable &T);
int Search_Bin(SSTable T,int key);	//折半查找操作

//*****************************************************************

typedef struct BiTNode{			//二叉树
	int data;
	BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

int CreateBST(BiTree &T);		//二叉排序树操作
BiTree SearchBST(BiTree T,int key);
int Insert(BiTree &T,int data);

//*****************************************************************

typedef struct{				//哈希表的数据
	int data;			//数据
	bool state;			//数据状态（用以判断地址空间是否存有数据）
}HashData;

typedef struct{				//哈希表
	HashData* elem;
	int count;			//当前元素个数
	int size;			//当前容量（容量>=元素个数）
}HashTable;

int CreateHash(HashTable &T);		//哈希表操作
int SearchHash(HashTable T,int key);
int NextAddr(HashTable T,int addr,int key);
