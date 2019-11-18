#include <iostream>
#include "Polyn.h"
using namespace std;

int CreatPolyn(List &P){						//创建多项式（初始化）
	P=(List)malloc(sizeof(Polyn));
	if(!P) exit(FALSE);
	P->next=NULL;
	P->coef=0.0;
	P->expn=-1;
	List q;
	q=P;

	int m;
	printf("请输入多项式的项数：");
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		List s;
		s=(List)malloc(sizeof(Polyn));
		if(!s) exit(FALSE);
		s->next=NULL;
		printf("请输入第%d项的系数与指数：",i);
		scanf("%f,%d",&s->coef,&s->expn);
		q->next=s;
		q=s;
	}
	printf("\n");								//换行，为了输入时，界面直观、不混乱
	return OK;
}

int AddPolyn(List &A,List &B,List &C){			//多项式相加
	List pa,pb,pc;
	pa=A->next;pb=B->next;pc=C;
	while(pa&&pb){
		if(pa->expn<pb->expn){					//表A指数小，将其插入和多项式的末尾
			pc->next=pa;pc=pa;pa=pa->next;
		}
		else if(pa->expn>pb->expn){				//表B指数小，将其插入和多项式的末尾
			pc->next=pb;pc=pb;pb=pb->next;
		}
		else{									//指数相等，系数相加并插入或删除两节点
			float sum=pa->coef + pb->coef;
			if(sum){
				pa->coef=sum;pc->next=pa;
				pc=pa;
				pa=pa->next;
				List b;b=pb;					//临时指针b指向多余节点
				pb=pb->next;
				free(b);						//释放多余节点
			}
			else{
				List a,b;a=pa;b=pb;				//临时指针变量a，b指向要删除的节点
				pa=pa->next;pb=pb->next;
				free(a);free(b);				//释放两个系数和为0的节点
			}
		}
	}
	pc->next=pa?pa:pb;							//插入剩余数据
	free(A);free(B);							//释放表头A、B
	return OK;
}

void PrintPolyn(List P){						//打印多项式
	List q;q=P->next;
	if(q){
		printf("P(X) = %.2fX^%d",q->coef,q->expn);	//打印第一项
		q=q->next;
	}
	else printf("P(X) = 0");
	while(q){
		printf(" + %.2fX^%d",q->coef,q->expn);
		q=q->next;
	}
	printf("\n\n");								//换行，为了输出时，界面直观、不混乱
}
