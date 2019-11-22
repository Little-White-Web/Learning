#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild, *rchild;	//左右孩子指针
}BiTNode, *BiTree;

int CreateBiTree(BiTree &T);			//二叉树操作函数声明
int PreOrderTraverse(BiTree T,int (*Visit)(char e));
int InOrderTraverse(BiTree T,int (*Visit)(char e));
int PrintElement(char e);
