#include <iostream>
#include "Polyn.h"
using namespace std;

int main(){										//主函数测试
	List A,B,C;
	printf("初始化多项式A：\n");
	CreatPolyn(A);
	printf("初始化多项式B：\n");
	CreatPolyn(B);
	printf("初始化多项式C：\n");
	CreatPolyn(C);								//C用来表示A+B，所以要初始化成只有0项

	printf("多项式A：\n");
	PrintPolyn(A);								//展示多项式A、B
	printf("多项式B：\n");
	PrintPolyn(B);
	
	printf("相加前多项式C：\n");
	PrintPolyn(C);								//展示多项式C	
	AddPolyn(A,B,C);							//多项式A、B相加到C	
	printf("相加后多项式C：\n");
	PrintPolyn(C);								//再次展示C
	return OK;
}