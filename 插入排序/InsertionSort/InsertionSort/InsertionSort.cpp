// InsertionSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void InsertionSort(int *a, int n) {
	/* 将待排序数组分为两部分，前一部分为已排序的序列，后一部分为未排序的序列。
	初始时，将第一个元素视为已排序的前一部分，依次遍历后一部分，将其插入到前一部分以排序序列的合适位置，直至数组末尾。
	*/
	for (int j = 1; j < n; j++) {
		int key = a[j];
		int i = 0;
		for (i = j - 1; i >= 0 && key < a[i]; i--)
			a[i + 1] = a[i];
		a[i + 1] = key;
	}
}

int main()
{
	int a[] = { 5, 4, 3, 2, 1 };
	InsertionSort(a, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d\n", a[i]);
	}
    return 0;
}


