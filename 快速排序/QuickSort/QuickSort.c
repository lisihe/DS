#include <stdio.h>

/*
分解算法，选取第一个元素为主元素x，将序列分解成2部分，前一部分小于等于x，后一部分大于等于x
a:待分解数数组
p、q:待分解元素的起始位置和结束位置
return:中间主元素的位置
*/
int Partition(int *a, int p, int q) {
    int x = a[p];
    int i = p;
    for(int j = p + 1; j <= q; j++) {
        if(x >= a[j]){
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    a[p] = a[i];
    a[i] = x;
    return i;
}

void QSort(int *a, int p, int q) {
    int i = 0;
    if(p < q) {
        i = Partition(a, p, q);
        QSort(a, p, i - 1);
        QSort(a, i + 1, q);
    }
}

void QucikSort(int *a, int n) {
    QSort(a, 0, n - 1);
}

void main(){
    int a[] = {6, 5, 4, 3, 2, 1};
    int n = 6;
    QucikSort(a, n);
    for(int i = 0; i < n; i++)
        printf("%d\n", a[i]);
}