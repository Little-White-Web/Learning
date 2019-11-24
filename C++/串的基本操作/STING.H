#define TRUE 1
#define FALSE -1
#define OK 1
#define ERROR -1

typedef struct{			//串的堆分配存储表示
	char* ch;
	int length;
}HString;

int InitStr(HString &S);	//串的操作

int StrAssign(HString &T,char * chars);

int StrLength(HString S);

int StrCompare(HString S,HString T);

int ClearString(HString &S);

int StrDisplay(HString S);

int index(HString S,HString T,int pos);

void get_next(HString S,int *next);

int KMP(HString S,HString T,int pos,int *next);
