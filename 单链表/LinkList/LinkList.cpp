/*
单链表
作者：lisihe
日期：2018年8月10日
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

/*
头插法创建单链表
L: 单链表头指针
时间复杂度：O(n)
*/
LinkList CreateList1(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));    // 创建头结点
    L->next = NULL; // 初始化为空表
    LNode *temp; int x;
    scanf("%d", &x);
    while(x != 9999) {
        temp = (LNode*)malloc(sizeof(LNode));
        temp->data = x;
        temp->next = L->next;
        L->next=temp;
        scanf("%d",&x);
    } 
    return L;
}

/*
尾插法
L：单链表头指针
时间复杂度：O(n)
*/
LinkList CreateList2(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode)); // 创建头结点
    LNode *temp, *r = L;    // r为指向表尾结点的指针
    int x;
    scanf("%d", &x);
    while(x != 9999) {
        temp = (LNode*)malloc(sizeof(LNode));
        temp->data = x;
        r->next = temp;
        r=temp;
        scanf("%d", &x);
    }
    r = NULL;
    return L;
}

/*
查找第i个结点
L：待查找结点
i：结点位置
时间复杂度：O(n吗，。)
*/
LNode* GetElem(LinkList &L, int i) {
    int j = 1;
    LNode* p = L->next; // 指向头结点的下一结点，即链表中的第一个结点
    if(i == 0)
        return L;
    else if (i < 1)
        return NULL;
    while(p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

/*
按值查找
*/
LNode* LocaeteElem(LinkList &L, int e) {
    LNode *p = L->next;
    while(p!=NULL && p->data != e)
        p = p->next;
    return p;
}

/*
插入操作
*/
bool InsertList(LinkList &L, int i, LNode *e) {
    if(i < 1)
        return false;
    LNode *p = GetElem(L, i - 1);
    e->next = p->next;
    p->next = e;
    return true;
}

/*
删除操作
*/
bool Delete(LinkList &L, int i) {
    if(i < 1)
        return false;
    LNode *p = GetElem(L, i - 1);
    LNode *q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

/*
删除操作，通过删除后继实现
*/
bool Delete2(LinkList &L, int i) {
    if(i < 1)
        return false;
    LNode *p = GetElem(L, i - 1);
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}

