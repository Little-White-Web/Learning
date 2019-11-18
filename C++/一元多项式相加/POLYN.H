#define TRUE 1
#define FALSE -1
#define OK 1
#define ERROR -1

typedef struct Polyn{							//多项式链表结构
	float coef;									//系数
	int expn;									//指数
	struct Polyn * next;
}Polyn, *List;

int CreatPolyn(List &P);
int AddPolyn(List &A,List &B,List &C);
void PrintPolyn(List P);
