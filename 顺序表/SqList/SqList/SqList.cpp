// SqList.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 100		// 线性表最大长度
#define INCREMENT 10	// 线性表每次增加的长度
typedef int ElemType;

// 线性表顺序存储结构
typedef struct SqList {
	ElemType *data;
	int length;
	int listsize;	// 存储空间大小
}SqList;

// 初始化线性表。构造一个空的线性表
bool InitList(SqList &L) {
	L.data = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));	// 给顺序存储空间分配基址
	if (!L.data)
		return false;	// 存储空间分配失败，返回false
	L.length = 0;	// 初始化表长为0
	L.listsize = MAXSIZE;
	return true;
}

// 求表长
int ListLength(SqList L) {
	return L.length;
}

// 按值查找,返回位序
int LocateElem(SqList L, ElemType e) {
	if (L.data) {
		for (int i = 0; i < L.length; i++) {
			if (L.data[i] == e)
				return i + 1;
		}
	}
	return 0;
}

// 插入操作，在线性表中第i个位置插入元素e
bool ListInsert(SqList &L, int i, ElemType e) {
	if (i < 1 || i > L.length + 1) // 判断插入位置i是否合法
		return false;
	if (L.length >= L.listsize) {	// 如果存储空间已满，增加分配存储空间
		ElemType *newBase = (ElemType *)realloc(L.data, (L.length + INCREMENT) * sizeof(ElemType));
		if (newBase) {
			L.data = newBase;
			L.listsize += INCREMENT;
		}
		else {
			return false;	// 增加存储空间失败
		}
	}
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return true;
}

// 删除操作，删除线性表中第i个元素
bool ListDelete(SqList &L, int i) {
	if (i < 1 || i > L.length) // 判断删除位序i是否合法
		return false;
	for (int j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}

// 输出操作，按前后顺序输出线性表L中的所有元素
void PrintList(SqList L) {
	for (int i = 0; i < L.length; i++)
		printf("%d\n", L.data[i]);
}

// 判空操作。若线性表L为空返回ture,否则返回False
bool isEmpty(SqList L) {
	return L.length == 0;
}

// 销毁操作。销毁线性表并释放所占用的内存空间
void ListDestory(SqList &L) {
	if (L.data)
		free(L.data);
	L.length = 0;
	L.listsize = 0;
}

// 删除现行表L中所有x
void Del_x_1(SqList &L, ElemType x) {
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] != x) {
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;
}

void Test_Del_x_1(){
	SqList L;
	InitList(L);
	for (int i = 0; i < 9; i++) {
		ElemType in;
		scanf_s("%d", &in);
		ListInsert(L, i+1, in);
		printf("in:%d\n", in);
	}
	printf("-----------------------------");
	PrintList(L);
	printf("Length:%d\n", L.length);
	Del_x_1(L, 7);
	PrintList(L);
	printf("Length:%d\n", L.length);
}

int main()
{
	Test_Del_x_1();
    return 0;
}

