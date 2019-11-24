#include <iostream>
#include "Sting.h"
using namespace std;

int main(){
	HString S1,S2;
	InitStr(S1);InitStr(S2);			//初始化S1，S2
	StrAssign(S1,"ABCDEFG");StrAssign(S2,"CDE");	//S1，S2赋值
	printf("S1=");StrDisplay(S1);			//打印S1
	printf("S2=");StrDisplay(S2);			//打印S2
	printf("len(S1)=%d\n",StrLength(S1));		//打印S1长度
	printf("len(S2)=%d\n",StrLength(S2));		//打印S2长度

	if(StrCompare(S1,S2)<0) printf("S1<S2\n");	//比较S1，S2
	else if(StrCompare(S1,S2)>0) printf("S1>S2\n");
	else printf("S1=S2\n");

	if(index(S1,S2,1)!=-1) printf("S2匹配于S1,从下标%d开始,长度%d\n",index(S1,S2,1),StrLength(S2));
        else printf("S2不匹配于S1!\n");		//调用匹配算法

	int next[225];					//next数组
        get_next(S2,next);				//获得S2的next数组
        if(KMP(S1,S2,1,next)!=-1) printf("S2匹配于S1,从下标%d开始,长度%d\n",KMP(S1,S2,1,next),StrLength(S2));
        else printf("S2不匹配于S1!\n");		//调用KMP算法

	printf("清空后:\n");
	ClearString(S1);ClearString(S2);		//清空S1，S2
	printf("S1=");StrDisplay(S1);			/*    打印    */
	printf("S2=");StrDisplay(S2);			/*   S1，S2   */
	printf("len(S1)=%d\n",StrLength(S1));		/*    及其    */
	printf("len(S2)=%d\n",StrLength(S2));		/*    长度    */
	return OK;
}
