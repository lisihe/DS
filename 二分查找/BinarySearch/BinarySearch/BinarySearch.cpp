// BinarySearch.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// 采用二分法查找数组中元素为x的位序，否则返回-1
// n表示数组长度
int BinarySearch(int *a, int n, int x) {
	int first = 0;
	int last = n;
	int mid = 0;
	// int compareNum = 0;
	while (first <= last) {
		mid = (first + last) / 2;
		// printf("Num Of Compare:%d\t the mid is:%d\n", ++compareNum, mid);
		if (a[mid] > x)
			last = mid - 1;
		else if(a[mid] < x)
			first = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	int x = 0;

	printf("position:%d\n", BinarySearch(a, 11, x));
	return 0;
}

