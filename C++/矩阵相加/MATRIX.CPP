#include <iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(){
	h=sizeof(m)/sizeof(m[0]);		//获取矩阵行数
	l=sizeof(m[0])/sizeof(m[0][0]);		//获取矩阵列数
        for(int i=0;i<h;i++){
		for(int j=0;j<l;j++){
			m[i][j]=rand()%100;	//rand()函数随机取0到99的整数
		}
	}
}

void Matrix::display(){				//打印矩阵
	for(int i=0;i<h;i++){
		for(int j=0;j<l;j++){
			cout << "\t" << m[i][j];
		}
		cout << endl;
	}
}

Matrix Matrix::operator+(Matrix a){		//重载 '+' 运算符
	Matrix b;
	for(int i=0;i<h;i++){
		for(int j=0;j<l;j++){
			b.m[i][j]=m[i][j]+a.m[i][j];
		}
	}
	return b;
}
