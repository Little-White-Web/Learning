#include <iostream>
#include "List.h"
using namespace std;

int InitList(LinkList &L){			//初始化空表
	L=(LinkList)malloc(sizeof(LNode));
	if(!L) exit(FALSE);
	L->data=0;
	L->next=NULL;
	return OK;
}

int InitList(SqList &L){			//初始化空表
	L.data=(int*)malloc(100*sizeof(int));
	if(!L.data) exit(FALSE);
	L.length=0;
	L.listsize=100;					//初始存储容量
	return OK;
}

int ListLength(LinkList L){			//求链表长度
	LinkList p=L->next;
	int length=0;
	while(p){
		length++;
		p=p->next;
	}
	return length;
}

int ListLength(SqList L){			//求顺序表长度
	int * p=L.data;
	int length=0;
	while(p){
		length++;
		p++;
	}
	return length;
}

int ListEmpty(LinkList L){			//链表判空
	if(L->next) return 1;
	else return -1;
}

int ListEmpty(SqList L){			//顺序表判空
	if(L.length) return 1;
	else return -1;
}

int ListInsert(LinkList &L,int i,int e){		//链表插入操作
	LinkList p=L;int j=0;
	while(p&&j < i-1){
		p=p->next;
		++j;
	}
	if(!p || j>i-1) return ERROR;
	LinkList s=(LinkList)malloc(sizeof(LNode));
	if(!s) exit(FALSE);
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}

int ListInsert(SqList &L,int i,int e){			//顺序表插入操作
	if(i<1 || i>L.length+1) return ERROR;
	if(L.length>=L.listsize){
		int* newbase=(int*)realloc(L.data,(L.listsize+10)*sizeof(int));
		if(!newbase) exit(FALSE);
		L.data=newbase;
		L.listsize+=10;
	}
	int* q=&(L.data[i-1]);
	int* p=&(L.data[L.length-1]);
	for(p;p>=q;--p) *(p+1)=*p;
	*q=e;++L.length;
	return OK;
}

int ListDelete(LinkList &L,int i,int &e){		//链表删除操作
	LinkList p=L;int j=0;
	while(p->next && j<i-1){
		p=p->next;
		++j;
	}
	if(!p->next || j>i-1) return ERROR;
	LinkList s=p->next;
	p->next=s->next;
	e=s->data;
	free(s);
	return OK;
}

int ListDelete(SqList &L,int i,int &e){			//顺序表删除操作
	if(i<1 || i>L.length) return ERROR;
	int* p=&(L.data[i-1]);
	e=*p;
	int* q=&L.data[L.length-1];
	for(++p;p<=q;++p) *(p-1)=*p;
	--L.length;
	return OK;
}

int MergeList(LinkList &L1,LinkList &L2,LinkList &L3){		//链表合并
	LinkList p1=L1->next;
	LinkList p2=L2->next;
	LinkList p3=L3=L1;
	while(p1&&p2){				//插入数据
		if(p1->data<p2->data){
			p3->next=p1;p3=p1;p1=p1->next;
		}
		else{
			p3->next=p2;p3=p2;p2=p2->next;
		}
	}
	p3->next=p1?p1:p2;			//插入剩余数据
	free(L2);					//释放表头L2
	return OK;
}

int MergeList(SqList &L1,SqList &L2,SqList &L3){			//顺序表合并
	int* p1=L1.data;
	int* p2=L2.data;
	L3.listsize=L3.length=L1.length+L2.length;
	int* p3=L3.data=(int*)malloc(L3.listsize*sizeof(int));
	if(!L3.data) exit(FALSE);
	int* p1_last=L1.data+L1.length;
	int* p2_last=L2.data+L2.length;
	while(p1 < p1_last && p2 < p2_last){	//插入数据
		if(*p1<*p2){
			*p3=*p1;
			p3++;p1++;
		}
		else{
			*p3=*p2;
			p3++;p2++;
		}
	}
	while(p1<p1_last){		//插入剩余数据
		*p3=*p1;
		p3++;p1++;
	}
	while(p2<p2_last){		//插入剩余数据
		*p3=*p2;
		p3++;p2++;
	}
	return OK;
}

void ListDisplay(LinkList L){			//打印链表
	LinkList p=L->next;
	while(p){
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
}

void ListDisplay(SqList L){				//打印顺序表
	int* p=L.data;
	int* last=p+L.length;
	while(p<last){
		printf("%d\t",*p);
		p++;
	}
	printf("\n");
}