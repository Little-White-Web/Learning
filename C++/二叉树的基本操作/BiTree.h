#define TRUE 1
#define FALSE -1
#define OK 1
#define ERROR -1

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild, *rchild;	//左右孩子指针
}BiTNode, *BiTree;

int CreateBiTree(Bitree &T);			//操作函数的声明
int PreOrderTraverse(BiTree T,int (*Visit)(int e));
int InOrderTraverse(BiTree T,int (*Visit)(int e));
int PrintElement(int e);
