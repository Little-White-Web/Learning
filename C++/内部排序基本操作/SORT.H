#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0

int Partition(int *L,int low,int high); //快速排序
void QuickSort(int *L,int low,int high);

void HeapAdjust(int *L,int s,int m);
void HeapSort(int *L,int n);            //堆排序
