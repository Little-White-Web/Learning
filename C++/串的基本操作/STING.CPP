#include <iostream>
#include "Sting.h"
using namespace std;

int InitStr(HString &S){		//初始化
	S.ch=(char*)malloc(sizeof(char));
	S.length=0;
	return OK;
}

int StrAssign(HString &T,char * chars){		//赋值
	if(T.ch) free(T.ch);
	int i;char * c;
	for(i=0,c=chars;*c;++i,++c);
	if(!i){
		T.ch=NULL;T.length=0;
	}else{
		if(!(T.ch=(char*)malloc(i*sizeof(char)))) exit(FALSE);
		for(int j=0;j<i;j++){
			T.ch[j]=chars[j];
			T.length=j+1;
		}
	}
	return OK;
}

int StrLength(HString S){		//串长
	return S.length;
}

int StrCompare(HString S,HString T){	 //比较大小
	for(int i=0;i<S.length && i<T.length;++i){
		if(S.ch[i] != T.ch[i]) return S.ch[i]-T.ch[i];
	}
	return S.length-T.length;
}

int ClearString(HString &S){		//清空串
	if(S.ch){
		free(S.ch);
		S.ch=NULL;
	}
	S.length=0;
	return OK;
}

int StrDisplay(HString S){			//打印串
    int len=StrLength(S);
	if(len==0){
		printf("NULL\n");
		return OK;
	}
    for(int i=0;i<len;i++){
        printf("%c",S.ch[i]);
    }
    printf("\n");
    return OK;
}

int index(HString S,HString T,int pos){		//模式匹配算法
    int i=pos,j=1;
    while(i<=StrLength(S) && j<=StrLength(T)){
        if(S.ch[i-1]==T.ch[j-1]){i++;j++;}
        else{i=i-j+2;j=1;}
    }
    if(j>StrLength(T)) return i-StrLength(T);
    else return -1;
}

void get_next(HString S,int *next){			//求next数组
    int i=1,j=0;next[1]=0;
    while(i<StrLength(S)){
        if(j==0 || S.ch[i-1]==S.ch[j-1]){
            i++;j++;
            next[i]=j;
        }
        else j=next[j];
    }
}

int KMP(HString S,HString T,int pos,int *next){		//KMP算法
    int i=pos,j=1;
    while(i<=StrLength(S) && j<=StrLength(T)){
        if(j==0 || S.ch[i-1]==T.ch[j-1]){
            i++;j++;
        }
        else j=next[j];
    }
    if(j>StrLength(T)) return i-StrLength(T);
    else return -1;
}