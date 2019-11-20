#define TRUE 1
#define FALSE -1
#define OK 1
#define ERROR -1

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild, *rchild;	//×óÓÒº¢×ÓÖ¸Õë
}BiTNode, *BiTree;

int CreateBiTree(Bitree &T);			//²Ù×÷
int PreOrderTraverse(BiTree T,int (*Visit)(int e));
int InOrderTraverse(BiTree T,int (*Visit)(int e));
int PrintElement(int e);