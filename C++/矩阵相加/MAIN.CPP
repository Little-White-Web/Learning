#include <iostream>
#include <time.h>
#include "Matrix.h"
using namespace std;

int main(){
    srand(time(0));		//给rand()设置随机种子
    Matrix a,b;
    cout << "a=" <<endl; a.display();
    cout << "b=" <<endl; b.display();
    cout << "a+b=" <<endl; (a+b).display();
    return 0;
}
