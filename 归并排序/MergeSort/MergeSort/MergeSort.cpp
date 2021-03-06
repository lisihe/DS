// MergeSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

void Merge(int *a, int *temp, int low, int mid, int high);
void MSort(int *a, int * temp, int low, int high);
void MergeSort(int *a, int n);

// 将数组a中已排序的两个子序列合并
void Merge(int *a, int *temp, int low, int mid, int high) {
	// 复制两个子序列数组
	int L = low;
	int R = mid + 1;
	int leftEnd = mid;
	int rightEnd = high;
	int p = low;
	while (L <= leftEnd &&  R <= rightEnd) {
		if (a[L] <= a[R])
			temp[p++] = a[L++];
		else
			temp[p++] = a[R++];
	}
	while (L <= leftEnd)
		temp[p++] = a[L++];
	while (R <= rightEnd)
		temp[p++] = a[R++];
	int num = high - low + 1;
	for (int j = low; j <= high; j++)
		a[j] = temp[j];
}


void MSort(int *a, int * temp, int low, int high) {
	int mid = 0;
	if (low < high) {
		mid = (low + high) / 2;
		MSort(a, temp, low, mid);
		MSort(a, temp, mid + 1, high);
		Merge(a, temp, low, mid, high);
	}
}

void MergeSort(int *a, int n) {
	int *temp = (int *)malloc(sizeof(int) * n);
	if (temp) {
		MSort(a, temp, 0, n - 1);
		free(temp);
	}
	else
		printf("no space!\n");
}

int main(void) {
	int a[] = { 7, 6, 5, 4, 3, 2, 1 };
	int n = 7;
	MergeSort(a, n);
	for (int i = 0; i < n; i++)
		printf("%d\n", a[i]);
	return 0;
}