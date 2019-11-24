#define TRUE 1
#define FALSE -1
#define OK 1
#define ERROR -1

typedef struct LNode{		//链表结构
	int data;
	struct LNode * next;
}LNode, *LinkList;

typedef struct{			//顺序表结构
	int * data;
	int length;
	int listsize;
}SqList;

int InitList(LinkList &L);	//表的基本操作，重载函数，同一个函数名可以分别对两种表操作
int InitList(SqList &L);

int ListLength(LinkList L);
int ListLength(SqList L);

int ListEmpty(LinkList L);
int ListEmpty(SqList L);

int ListInsert(LinkList &L,int i,int e);
int ListInsert(SqList &L,int i,int e);

int ListDelete(LinkList &L,int i,int &e);
int ListDelete(SqList &L,int i,int &e);

int MergeList(LinkList &L1,LinkList &L2,LinkList &L3);
int MergeList(SqList &L1,SqList &L2,SqList &L3);

void ListDisplay(LinkList L);
void ListDisplay(SqList L);
