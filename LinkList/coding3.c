/*链表练习文件*/

/*2025/3/15温故线性表*/
/*
* 1. Java中的浅拷贝和深拷贝学习
* 

*/
/*
* 1. 什么叫数组
*	元素类型相同，大小相等
* 2. 数组的优缺点

*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define bool char
#define true 1
#define false 0

typedef int ElemType;

typedef struct Arr {
	ElemType* pBase; // 存储的是数组的第一个元素的地址
	int len; // 数组所能容纳的最大元素的个数
	int cnt; // 当前数组有效元素的个数
	//int increment; // 自动增长因子
}ArrayList;

void init_arr(ArrayList*, int);
bool append_arr(ArrayList*,ElemType); // 追加
bool insert_arr(ArrayList*, ElemType, int); // 插入
//bool delete_arr();
//int get();
bool is_empty(ArrayList*);
bool is_full(ArrayList*);
//void sort_arr();
void show_arr(ArrayList*);
void inversion_arr(ArrayList*);

int main() {
	ArrayList array;

	init_arr(&array, 10);

	inversion_arr(&array);

	if (append_arr(&array, 1)) {
		printf("追加元素%d成功！！！\n", 1);
	}
	else {
		printf("追加元素失败！！！！\n");
	}
	if (append_arr(&array, 2)) {
		printf("追加元素%d成功！！！\n", 1);
	}
	else {
		printf("追加元素失败！！！！\n");
	}
	if (append_arr(&array, 3)) {
		printf("追加元素%d成功！！！\n", 1);
	}
	else {
		printf("追加元素失败！！！！\n");
	}
	append_arr(&array, 4);
	show_arr(&array);
	if (insert_arr(&array, 6, -1)) {
		printf("向位置%d插入元素%d成功！！！\n", 6, 4);
	}
	else {
		printf("向位置%d插入元素%d失败！！！\n", 6, 4);
	}
	show_arr(&array);
	inversion_arr(&array);
	show_arr(&array);
	return 0;
}

void init_arr(ArrayList* pArray, int len) {
	pArray->pBase = (ElemType*)malloc(sizeof(ElemType) * len);
	if (pArray->pBase == NULL) {
		printf("动态内存分配失败！！！");
		exit(-1);
	}
	pArray->len = len;
	pArray->cnt = 0;
	return;
}

void show_arr(ArrayList* pArray) {
	int i;
	if (is_empty(pArray)) {
		printf("数组为空！！！");
		return;
	}
	for (i = 0; i < pArray->cnt; i++) {
		printf("%d\t", *(pArray->pBase + i));
	}
	printf("\n");
}

bool append_arr(ArrayList* pArray, ElemType elem) {
	if (pArray->cnt == pArray->len) {
		printf("当前数组已满！！！");
		return false;
	}
	*(pArray->pBase + pArray->cnt) = elem;
	pArray->cnt += 1;
	return true;
}

bool insert_arr(ArrayList* pArray, ElemType elem, int index) {
	int i;
	// 插入位置校验
	if (index < 1 || index > pArray->cnt + 1) {
		printf("插入位置不符合要求！！！\n");
		return false;
	}
	// 如果数组已满，不能插入
	if (is_full(pArray)) {
		printf("数组已满，不能插入数据");
		return false;
	}
	// 1 2 3   2 = 1
	for (i = pArray->cnt; i >= index - 1; i--) {
		*(pArray->pBase + i + 1) = *(pArray->pBase + i);
	}
	*(pArray->pBase + index - 1) = elem;
	pArray->cnt += 1;
	return true;
}

void inversion_arr(ArrayList* pArray) {
	int i = 0, j = pArray->cnt - 1;
	// 如果数组为空，不用导致
	if (is_empty(pArray)) {
		printf("数组为空！不能倒置\n");
		return;
	}

	while (i < j) {
		ElemType temp = 0;
		temp = pArray->pBase[i];
		pArray->pBase[i] = pArray->pBase[j];
		pArray->pBase[j] = temp;
		i += 1;
		j -= 1;
	}
	return;
}

bool is_empty(ArrayList* pArray) {
	if (pArray->cnt == 0) {
		return true;
	}
	return false;
}

bool is_full(ArrayList* pArray) {
	if (pArray->cnt == pArray->len) {
		return true;
	}
	return false;
}
//bool append_arr(); // 追加
//bool insert_arr(); // 插入
//bool delete_arr();
//int get();
//bool is_empty();
//bool is_full();
//void sort_arr();
//void show_arr();
//void inversion_arr();

/*2023/4/18复习线性表*/
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//#define MAXSIZE 20	/* 数组长度 */
//
//typedef int ElemType;
//typedef struct Node {
//	ElemType data;
//	struct Node* next;
//}Node, *LinkList;
//
//void InitList(LinkList* L);
//void CreateListHead(LinkList* L);
//void CreateListTail(LinkList* L);
//bool ListEmpty(LinkList L);
//void ListInsert(LinkList* L);
//void ListDelte(LinkList* L);
//int ListLength(LinkList L);
//void ListTraverse(LinkList L);
//
//
//int main() {
//	LinkList L;
//	//InitList(&L);
//	//CreateListHead(&L);
//	CreateListTail(&L);
//	ListTraverse(L);
//	// 取链表长度
//	printf("%d\n", ListLength(L));
//	/*if (ListEmpty(L)) {
//		printf("链表为空！！！\n");
//	}
//	else {
//		printf("链表不为空！！！\n");
//	}*/
//	return 0;
//}
//void InitList(LinkList* L) {
//	
//	LinkList head = (LinkList)malloc(sizeof(Node)); /* 生成头结点head */
//	if (*L == NULL) {
//		printf("动态内存分配失败！！！\n");
//		exit(-1);
//	}
//
//	LinkList tail = head; /* 尾结点 */
//	if (tail == NULL) {
//		printf("动态内存分配失败！！！\n");
//		exit(-1);
//	}
//	tail->next = NULL;
//
//	int i, n, e;
//	printf("请输入要生成结点的个数：");
//	scanf_s("%d", &n);
//	loop: if (n < 0) {
//		printf("输入不是正整数，请重新输入：");
//		scanf_s("%d", &n);
//		goto loop;
//	}
//	for (i = 0; i < n; i++) {
//		printf("请输入第%d个结点的值：", i + 1);
//		scanf_s("%d", &e);
//		LinkList new = (LinkList)malloc(sizeof(Node));	/* 生成新结点 */
//		if (new == NULL) {
//			printf("动态内存分配失败！！！\n");
//			exit(-1);
//		}
//		new->data = e;
//		new->next = NULL;
//		tail->next = new;
//		tail = new;
//	}
//	*L = head;
//	return;
//}
//bool ListEmpty(LinkList L) {
//	return L->next == NULL ? true : false;
//}
//void ListInsert(LinkList* L) {
//
//	return;
//}
//void ListDelte(LinkList* L) {
//
//	return;
//}
//int ListLength(LinkList L) {
//	int n = 0;
//	LinkList p = L->next;
//	while (p) {
//		n++;
//		p = p->next;
//	}
//	return n;
//}
//void ListTraverse(LinkList L) {
//	if (ListEmpty(L)) {
//		printf("链表为空！！！\n");
//		return;
//	}
//	LinkList p = L->next;
//	while (p) {
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	printf("\n");
//	return;
//}
//void CreateListHead(LinkList* L) {
//	int n, i, e;
//
//	*L = (LinkList)malloc(sizeof(Node));
//	if (!*L) {
//		printf("动态内存分配失败！！！\n");
//		exit(-1);
//	}
//	(*L)->next = NULL;
//
//	printf("请输入要创建的结点个数：");
//	scanf_s("%d", &n);
//
//	for (i = 0; i < n; i++) {
//		printf("请输入第%d个结点值：", i + 1);
//		scanf_s("%d", &e);
//		LinkList new = (LinkList)malloc(sizeof(Node));
//		if (!new) {
//			printf("动态内存分配失败！！！\n");
//			exit(-1);
//		}
//		new->data = e;
//		new->next = (*L)->next;
//		(*L)->next = new;
//	}
//	return;
//}
//void CreateListTail(LinkList* L) {
//	int i, e, n;
//	LinkList tail; /* tail为尾结点 */
//	*L = (LinkList)malloc(sizeof(Node));
//	if (!*L) {
//		printf("Failed！！！\n");
//		exit(-1);
//	}
//	tail = *L;
//	if (!tail) {
//		printf("failed!!!\n");
//		exit(-1);
//	}
//	tail->next = NULL;
//
//	printf("请输入结点个数：");
//	scanf_s("%d", &n);
//	for (i = 0; i < n; i++) {
//		printf("请输入第%d个结点值：", i + 1);
//		scanf_s("%d", &e);
//		LinkList newNode = (LinkList)malloc(sizeof(Node));
//		if (!newNode) {
//			printf("failed!!!\n");
//			exit(-1);
//		}
//		newNode->data = e;
//		newNode->next = NULL;
//		tail->next = newNode;
//		tail = newNode;
//	}
//	return;
//}


/*2022/10/19练习*/
//实现一个去重操作
//#include<stdio.h>
//
//#define MAXSIZE 20
//#define bool char
//#define true 1
//#define false 0
//
//typedef int ElemType;
//typedef struct {
//	ElemType data[MAXSIZE];
//	int length;
//}SqList;
//
//void InitList(SqList* L);
//bool ListEmpty(SqList* L);
//bool ListAdd(SqList* L, ElemType e);
//bool TraverseList(SqList* L);
//bool ListInsert(SqList* L, int i, ElemType e);
//void unionL(SqList* La, SqList* Lb);
//void GetElem(SqList* L, int p, ElemType* e);
//bool LocateElem(SqList* L, ElemType e);
//
//int main() {
//	SqList La, Lb;
//	InitList(&La);
//	InitList(&Lb);
//	/*La: 8, 9, 10 */
//	ListAdd(&La, 8);
//	ListAdd(&La, 10);
//	ListAdd(&La, 8);
//	ListAdd(&La, 7);
//	ListAdd(&La, 5);
//	ListAdd(&La, 9);
//	ListAdd(&La, 10);
//	ListAdd(&La, 1);
//	ListAdd(&La, 2);
//	ListAdd(&La, 8);
//	/*Lb: 1 2 3 4 5 6 7*/
//	ListAdd(&Lb, 3);
//	ListAdd(&Lb, 2);
//	ListAdd(&Lb, 3);
//	ListAdd(&Lb, 4);
//	ListAdd(&Lb, 7);
//	ListAdd(&Lb, 6);
//	ListAdd(&Lb, 5);
//	ListAdd(&Lb, 4);
//	ListAdd(&Lb, 2);
//	ListAdd(&Lb, 1);
//	ListAdd(&Lb, 3);
//
//	TraverseList(&Lb);
//	/*ListInsert(&Lb, 13, 88);
//	TraverseList(&Lb);
//	if (ListEmpty(&La))
//		printf("链表为空！！！\n");*/
//	return 0;
//}
//
//void InitList(SqList* L) {
//	L->length = 0;
//	return;
//}
//bool ListEmpty(SqList* L) {
//	if (L->length) {
//		return false;
//	}
//	else {
//		return true;
//	}
//}
//bool ListAdd(SqList* L, ElemType e) {
//	if (L->length == MAXSIZE) {
//		return false;
//	}
//	// printf("%d\n", L->length);
//	L->data[L->length] = e;
//	// printf("%d\n", L->data[L->length]);
//	L->length++;
//	return true;
//}
//bool TraverseList(SqList* L) {
//	if (!L->length) {
//		return false;
//	}
//	else {
//		for (int i = 0; i < L->length; i++) {
//			printf("%d\t", L->data[i]);
//		}
//		printf("\n");
//		return true;
//	}
//}
//bool ListInsert(SqList* L, int p, ElemType e) {
//	if (L->length == MAXSIZE) {
//		return false;
//	}
//	if (p < 1 || p > L->length + 1) {
//		return false;
//	}
//	// 1 2 3 4  2 88
//	for (int i = L->length - 1; i >= p - 1; i--) {
//		L->data[i + 1] = L->data[i];
//	}
//	L->data[p - 1] = e;
//	L->length++;
//	return true;
//}
//void unionL(SqList* La, SqList* Lb) {
//	int La_len, Lb_len, i;
//	SqList Lc;
//	InitList(&Lc);
//	ElemType e;
//	La_len = La->length;
//	Lb_len = Lb->length;
//	for (i = 1; i <= Lb_len; i++) {
//		GetElem(Lb, i, &e);
//		if (!LocateElem(&La, e))
//			ListInsert(&La, ++La_len, e);
//	}
//}
//void GetElem(SqList* L, int p, ElemType* e) {
//	*e = L->data[p - 1];
//	return;
//}
//bool LocateElem(SqList* L, ElemType e) {
//	int i, l = L->length;
//	for (i = 0; i < l; i++) {
//		if (L->data[i] == e) {
//			return true;
//			break;
//		}
//	}
//	return false;
//}
/*2022/10/14练习*/
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define true 1
//#define false 0
//#define MAXSIZE 10
//
//typedef int SElemType;
//typedef struct {
//	SElemType data[MAXSIZE];
//	int top;	/*用于栈顶指针*/
//}SqStack;
//

/*2022/10/13练习*/
//顺序存储
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define true 1
//#define false 0
//#define MAXSIZE 10
//
//typedef int ElemType;
//typedef struct {
//	ElemType data[MAXSIZE];
//	int length;
//}SqList;
//
//void InitList(SqList *L);
//bool ListInsert(SqList* L, int i, ElemType e);
//bool ListDelete(SqList* L, int i, ElemType* e);
//void ListTraverse(SqList* L);
//
//
//int main() {
//	SqList node1, node;
//	InitList(&node);
//	for (int i = 1; i <= 3; i++) {
//		ListInsert(&node, i, i);
//	}
//	ListInsert(&node, 5, 88);
//	ElemType e = 0;
//	ListDelete(&node, 1, &e);
//	printf("%d\n", e);
//	ListTraverse(&node);
//	return 0;
//}
//
//void InitList(SqList* L) {
//	L->length = 0;
//}
//bool ListInsert(SqList* L, int i, ElemType e) {
//	int j;
//	if (i > L->length + 1 || i < 1)
//		return false;
//	if (L->length == MAXSIZE)
//		return false;
//	// 1 2 3 2 88
//	for (j = L->length - 1; j >= i; j--) {
//		L->data[j + 1] = L->data[j];
//	}
//	L->data[i - 1] = e;
//	L->length++;
//	return true;
//}
//bool ListDelete(SqList* L, int i, ElemType* e) {
//	if (i < 1 || i > L->length)
//		return false;
//	if (!L->length)
//		return false;
//	*e = L->data[i - 1];
//	for (int j = i - 1; j < L->length - 1; j++) {
//		L->data[j] = L->data[j + 1];
//	}
//	L->length--;
//	return true;
//}
//void ListTraverse(SqList* L) {
//	if (!L->length)
//		printf("数组为空！！！\n");
//	int i;
//	for (i = 0; i < L->length; i++) {
//		printf("%d\t", L->data[i]);
//	}
//	printf("\n");
//	return;
//}
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef int ElemType;
//typedef struct Node {
//	ElemType data;
//	struct Node* next;
//}Node, *LinkList;
//
//void CreateListHead(LinkList* L, int n);
//void CreateListTail(LinkList* L, int n);
//bool ListTraverse(LinkList* L);
//bool ListInsert(LinkList* L, int i, ElemType e);
//bool ListDelete(LinkList* L, int i, ElemType* e);
//
//int main() {
//	LinkList node;
//	CreateListTail(&node, 3);
//	ListTraverse(&node);
//	// ListInsert(&node, 2, 88);
//	ElemType e;
//	if (ListDelete(&node, 4, &e))
//		printf("成功，删除了元素%d\n", e);
//	ListTraverse(&node);
//	return 0;
//}
//
//void CreateListHead(LinkList* L, int n) {
//	LinkList p;
//	int i;
//	*L = (LinkList)malloc(sizeof(Node));
//	(*L)->next = NULL;
//	for (i = 0; i < n; i++) {
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = i + 1;
//		p->next = (*L)->next;
//		(*L)->next = p;
//	}
//	return;
//}
//void CreateListTail(LinkList* L, int n) {
//	LinkList p, r;
//	int i;
//	(*L) = (LinkList)malloc(sizeof(Node));
//	r = *L;
//	for (i = 0; i < n; i++) {
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = i + 1;
//		r->next = p;
//		r = p;
//	}
//	r->next = NULL;
//	return;
//}
//bool ListTraverse(LinkList* L) {
//	LinkList p = (*L)->next;
//	if (!p) {
//		printf("链表为空！！！");
//		return false;
//	}
//	while (p) {
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	printf("\n");
//	return true;
//}
//bool ListInsert(LinkList* L, int i, ElemType e) {
//	LinkList p = (*L), s;
//	int j = 1;
//	// 1 2 3 4 5  j:2 p:1 i 2
//	while (j < i && p) {
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i) {
//		return false;
//	}
//	s = (LinkList)malloc(sizeof(Node));
//	s->data = e;
//	s->next = p->next;
//	p->next = s;
//	return;
//}
//bool ListDelete(LinkList* L, int i, ElemType* e) {
//	LinkList p = *L, q;
//	int j = 1;
//	// 1 2 3 j:4 p: 3 i:4  q
//	while (j < i && p->next) {
//		p = p->next;
//		++j;
//	}
//	if (!p->next || j > i) {
//		return false;
//	}
//	q = p->next;
//	*e = q->data;
//	p->next = q->next;
//	free(q);
//	return true;
//}
/*2022/10/12练习*/
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define false 0
//#define true 1
//
//typedef struct Node {
//	int data;
//	struct Node* next;
//}Node, *LinkList;
//
//void CreateListTail(LinkList* L, int n);
//void ListTraverse(LinkList* L);
//bool ListInsert(LinkList* L, int i, int e);
//int main() {
//	LinkList node;
//	CreateListTail(&node, 5);
//	ListTraverse(&node);
//	ListInsert(&node, 2, 88);
//	ListTraverse(&node);
//	return 0;
//}
//void CreateListTail(LinkList* L, int n) {
//	LinkList p, r;
//	int i;
//	*L = (LinkList)malloc(sizeof(Node));
//	r = *L;
//	for (i = 0; i < n; i++) {
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = i + 1;
//		r->next = p;
//		r = p;
//	}
//	r->next = NULL;
//	return;
//}
//void ListTraverse(LinkList* L) {
//	LinkList p = (*L)->next;
//	if (!p) {
//		printf("链表为空！！！");
//	}
//	while (p) {
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	printf("\n");
//	return;
//}
//bool ListInsert(LinkList* L, int i, int e) {
//	LinkList p = *L, s;
//	int j = 1;
//	while (j < i && p) {
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i) {
//		return false;
//	}
//	s = (LinkList)malloc(sizeof(Node));
//	s->data = e;
//	s->next = p->next;
//	p->next = s;
//	return true;
//}
/*2022/10/11练习*/
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef int ElemType;
//typedef struct Node {
//	ElemType data;
//	struct Node* next;
//}Node, *LinkList;
//
//void CreateListHead(LinkList* L, int n);
//void CreateListTail(LinkList* L, int n);
//void ListTraverse(LinkList* L);
//
//int main() {
//	LinkList node, node1;
//	CreateListHead(&node, 5);
//	ListTraverse(&node);
//	CreateListTail(&node1, 5);
//	ListTraverse(&node1);
//	return 0;
//}
//
//void CreateListHead(LinkList* L, int n) {
//	LinkList p;
//	int i;
//	(*L) = (LinkList)malloc(sizeof(Node));
//	(*L)->next = NULL;
//	for (i = 0; i < n; i++) {
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = i + 1;
//		p->next = (*L)->next;
//		(*L)->next = p;
//	}
//	return;
//}
//void CreateListTail(LinkList* L, int n) {
//	LinkList p, r;
//	int i;
//	(*L) = (LinkList)malloc(sizeof(Node));
//	r = (*L);
//	for (i = 0; i < n; i++) {
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = i + 1;
//		r->next = p;
//		r = p;
//	}
//	r->next = NULL;
//}
//void ListTraverse(LinkList* L) {
//	LinkList p = (*L)->next;
//	if (p == NULL) {
//		printf("链表为空！！！");
//	}
//	while (p) {
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	printf("\n");
//	return;
//}
/*2022/10/10练习*/
//#include<stdio.h>
//#include<malloc.h>
//
//int main() {
//	int* a = NULL;
//	a = (int*)malloc(sizeof(int));
//	if (!a) {
//		printf("Hello\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define false 0
//#define true 1
//
//typedef int ElemType;
//typedef struct Node {
//	ElemType data;
//	struct Node* next;
//}*LinkList, Node;
//
//void CreateListHead(LinkList* L, int n);
//void TraverseList(LinkList L);
//void CreateListTail(LinkList* L, int n);
//bool ListInsert(LinkList* L, int i, ElemType e);
//bool ListDelete(LinkList* L, int i, ElemType* e);
//
//int main() {
//	LinkList node = NULL, node1 = NULL;
//	CreateListHead(&node, 5);
//	TraverseList(node);
//	CreateListTail(&node1, 5);
//	TraverseList(node1);
//	// ListInsert(&node1, 1, 88);
//	ElemType e;
//	if (ListDelete(&node1, 6, &e)) {
//		printf("删除%d元素成功!!!\n", e);
//	}
//
//	TraverseList(node1);
//	return 0;
//}
//
//void CreateListHead(LinkList* L, int n) {
//	LinkList p;
//	int i;
//	(*L) = (LinkList)malloc(sizeof(Node));
//	(*L)->next = NULL;
//	for (i = 0; i < n; i++) {
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = i + 1;
//		p->next = (*L)->next;
//		(*L)->next = p;
//	}
//	return;
//}
//void TraverseList(LinkList L) {
//	LinkList p = L->next;
//	if (p == NULL) {
//		printf("链表为空！！！\n");
//	}
//	while (p != NULL) {
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	printf("\n");
//	return;
//}
//void CreateListTail(LinkList* L, int n) {
//	LinkList p, r;
//	int i;
//	*L = (LinkList)malloc(sizeof(Node));
//	r = *L;
//	for (i = 0; i < n; i++) {
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = i + 1;
//		r->next = p;
//		r = p;
//	}
//	r->next = NULL;
//	return;
//}
//bool ListInsert(LinkList* L, int i, ElemType e) {
//	LinkList p = *L, s;
//	int j = 1;
//	while (j < i && p) {
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i) {
//		return false;
//	}
//	s = (LinkList)malloc(sizeof(Node));
//	s->data = e;
//	s->next = p->next;
//	p->next = s;
//	return true;
//}
//bool ListDelete(LinkList* L, int i, ElemType* e) {
//	LinkList p = *L, q;
//	int j = 1;
//	while (j < i && p->next) {	/*遍历寻找第i-1个结点*/
//		p = p->next;
//		++j;
//	}
//	if (!p->next || j > i) {
//		return false;	/*第i个结点不存在*/
//	}
//	q = p->next;
//	p->next = q->next;	/*将q的后继赋值给p的后继*/
//	*e = q->data;		/*将q结点中的数据给e*/
//	free(q);			/*让系统回收此结点，释放内存*/
//	return true;
//}
/*2022/10/9练习*/
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define false 0
//#define true 1
//
//typedef int ElemType;
//typedef struct Node {
//	ElemType data;
//	struct Node* next;
//}Node, *LinkList;
//
//void CreateListHead(LinkList* L, int n);
//void CreateListTail(LinkList* L, int n);
//void TraverseList(LinkList L);
//
//int main() {
//	LinkList node = NULL, node1 = NULL;
//	CreateListTail(&node, 6);
//	TraverseList(node);
//	/*if (node->next == NULL) {
//		printf("链表为空！！！\n");
//	}
//	CreateListTail(&node1, 2);
//	if (node1->next == NULL) {
//		printf("链表为空！！！\n");
//	}*/
//	return 0;
//}
//
//void CreateListHead(LinkList* L, int n) {
//	/*1. 声明一指针p和计数器变量i;*/
//	LinkList p;
//	int i;
//	/*2. 初始化一空链表L;*/
//	(*L) = (LinkList)malloc(sizeof(Node));
//	/*3. 让L的头结点的指针指向NULL, 即创建一个带头结点的单链表;*/
//	(*L)->next = NULL;
//	/*4. 循环；*/
//	for (i = 0; i < n; i++) {
//		/*1）生成一新节点指针p;*/
//		p = (LinkList)malloc(sizeof(Node));
//		/*2) 生成一数字赋值给p的数据域p->data*/
//		p->data = i + 1;
//		/*3）将p插入到头结点与前一新结点之间；*/
//		p->next = (*L)->next;
//		(*L)->next = p;
//	}
//	return;
//}
//void TraverseList(LinkList L) {
//	if (L->next == NULL) {
//		printf("链表为空！！！\n");
//	}
//	LinkList p = L->next;
//	while (p != NULL) {
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	printf("\n");
//	return;
//}
//void CreateListTail(LinkList* L, int n) {
//	/*1. 声明指针p,r和计数器变量i;*/
//	LinkList p, r;
//	int i;
//	/*2. 初始化一空链表L*/
//	(*L) = (LinkList)malloc(sizeof(Node));
//	/*3. r为指向尾部的新结点点*/
//	r = *L; 
//	/*4. 循环*/
//	for (i = 0; i < n; i++) {
//		/*1) 生成一新结点p;*/
//		p = (LinkList)malloc(sizeof(Node));
//		/*2) 生成一数字赋值给p的数据域 p->data;*/
//		p->data = i + 1;
//		/*3) 将表尾终端结点的指针指向新结点；*/
//		r->next = p;
//		/*4) 将当前的新结点定义为表尾终端结点；*/
//		r = p;
//	}
//	r->next = NULL; /*表示当前链表结束。*/
//}
//void CreateListTail(LinkList* L, int n) {
//	/*1. 声明指针p, r 和计数器变量i;*/
//	LinkList p, r;
//	int i;
//	/*2. 初始化一链表L;*/
//	(*L) = (LinkList)malloc(sizeof(Node));
//	/*3. r为指向尾部的新结点;*/
//	r = *L;
//	/*4. 循环*/
//	for (i = 0; i < n; i++) {
//		/*1) 生成一新结点p;*/
//		p = (LinkList)malloc(sizeof(Node));
//		/*2) 生成一数字赋值给p的数据域p->data;*/
//		p->data = i + 1;
//		/*3) 将表尾终端结点的指针指向新结点;*/
//		r->next = p;
//		/*4) 将当前的新结点定义为表尾终端结点*/
//		r = p;
//	}
//	/*5. 让r的指针指向NULL, 表示当前链表结束。*/
//	r->next = NULL;
//	return;
//}
/*2022/10/2练习*/
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define false 0
//#define true 1
//
//typedef int ElemType;
//typedef struct Node {
//	ElemType data;
//	struct Node* next;
//}Node, *LinkList;
//
//void CreateListHead(LinkList* L, int n);
//
//int main() {
//
//	return 0;
//}
//
//void CreateListHead(LinkList* L, int n) {
//	/*1. 声明一指针p和计数器变量i*/
//	LinkList p;
//	int i;
//	/*2. 初始化一空链表L*/
//	(*L) = (LinkList)malloc(sizeof(Node));
//	/*3. 让L的头结点的指针指向NULl，即建立一个带头结点的单链表*/
//	(*L)->next = NULL;
//	/*4. 循环 */
//	for (i = 0; i < n; i++) {
//		/*1） 生成一新结点赋值给p */
//		p = (LinkList)malloc(sizeof(Node));
//		/*2） 随机生成一数字赋值给p的数据域p->data */
//		p->data = i + 1;
//		p->next = (*L)->next;
//		(*L)->next = p;
//	}
//	return;
//}
/*2022/9/30练习*/
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define false 0
//#define true 1
//
//typedef int ElemType;
//typedef struct Node {
//	ElemType data;
//	struct Node* next;
//}*LinkList;
//
//void CreateListHead(LinkList* L, int n);
//
//int main() {
//
//
//	return 0;
//}
//
//void CreateListHead(LinkList* L, int n) {
//	/* 1. 声明一指针p和计数器变量i */
//	LinkList p;
//	int i;
//	/* 2. 初始化一空链表L*/
//}
/*2022/9/27练习*/
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef int ElemType;
///*线性表的单链表存储结构*/
//typedef struct Node {
//	ElemType data;
//	struct Node* next;
//} Node, *LinkList;
//
//void CreateListHead(LinkList* L, int n);
//bool ListEmpty(LinkList* L);
//
//int main() {
//	LinkList L = NULL;
//	CreateListHead(&L, 5);
//	// if (ListEmpty(L))
//	//	printf("链表为空！！！\n");
//	return 0;
//}
//
///* 随机产生n个元素的值，建立带表头结点的单链线性表L(头插法) */
//void CreateListHead(LinkList* L, int n) {
//	/////* 1. 声明一指针p和计数器变量i */
//	////LinkList p;
//	////int i;
//	////srand(time(0));		/*初始化随机数种子*/
//	/////* 2. 初始化一空链表 */
//	////*L = (LinkList)malloc(sizeof(Node));
//	/////* 3. 让L的头结点的指针指向NULL，即建立一个带头结点的单链表 */
//	////(*L)->next = NULL;	/*先建立一个带头结点的单链表 */
//	/////* 4. 循环: */
//	////for (i = 0; i < n; i++) {
//	////	/*1) 生成一个新结点赋值给p; */
//	////	p = (LinkList)malloc(sizeof(Node));
//	////	/* 2) 随机生成一个数字赋值给p的数据域p->data; */
//	////	// p->data = rand() % 100 + 1;
//	////	p->data = i + 1;
//	////	/* 3) 将p插入到头结点与前一新结点之间。*/
//	////	p->next = (*L)->next;
//	////	(*L)->next = p;
//	////}
//	/*1. 声明一指针p和计数器变量i */
//	LinkList p;
//	int i;
//	srand(time(0));		/*生成随机数种子*/
//	/*2. 初始化一空链表L*/
//	(*L) = (LinkList)malloc(sizeof(Node));
//	/*3. 让L的头结点的指针指向NULl, 即建立一个带头结点的单链表。*/
//	(*L)->next = NULL;
//	/*4. 循环：*/
//	for (i = 0; i < n; i++) {
//		/*1)生成一新结点赋值给p;*/
//		p = (LinkList)malloc(sizeof(Node));
//		/*2)随机生成一数字赋值给p的数据域p->data;*/
//		// p->data = rand() % 100 + 1;
//		// printf("%d\n", i + 1);
//		p->data = i + 1;
//		/*3)将p插入到头结点与前一新结点之间。*/
//		p->next = (*L)->next;
//		(*L)->next = p;
//	}
//	return;
//}
//bool ListEmpty(LinkList L) {
//	if (L->next == NULL) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
/*2022/9/26练习*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<malloc.h>
//
//#define bool char
//#define false 0
//#define true 1
//#define MAXSIZE 10
//
//typedef int ElemType;
//typedef struct {
//	ElemType data[MAXSIZE];
//	int length;
//}SqList;
//
//void InitList(SqList* L);
//bool ListInsert(SqList* L, int i, ElemType e);
//bool ListDelete(SqList* L, int i, ElemType* e);
//void ListTraverse(SqList* L);
//
//int main() {
//	SqList L;
//	InitList(&L);
//	for (int k = 1; k < 10; k++) {
//		ListInsert(&L, k, k);
//	}
//	ListTraverse(&L);
//	ElemType e;
//	ListDelete(&L, 2, &e);
//	ListDelete(&L, 7, &e);
//	ListTraverse(&L);
//	return 0;
//}
//
//void InitList(SqList* L) {
//	L->length = 0;
//}
//bool ListInsert(SqList* L, int i, ElemType e) {
//	/* 1. 如果插入位置不合理，则抛出异常 */
//	if (i < 1 || i > L->length + 1) {
//		return false;
//	}
//	/* 2. 如果线性表长度大于等于数组长度，则抛出异常或动态增加容量 */
//	if (L->length >= MAXSIZE) {
//		return false;
//	}
//	/* 3. 从最后一个元素开始向前遍历到第i个位置，分别将它们向后移动一个位置 */
//	for (int k = L->length - 1; k > i - 2; k--) {
//		L->data[k + 1] = L->data[k];
//	}
//	/* 4. 把插入元素填入位置i处 */
//	L->data[i - 1] = e;
//	/* 线性表长度加1 */
//	L->length++;
//	return true;
//}
//void ListTraverse(SqList* L) {
//	if (L->length != 0) {
//		for (int k = 0; k < L->length; k++) {
//			printf("%d\t", L->data[k]);
//		}
//		printf("\n");
//	}
//	else {
//		printf("线性表为空！！！");
//	}
//	return;
//}
//bool ListDelete(SqList* L, int i, ElemType* e) {
//	/* 如果删除位置不合理， 则抛出异常 */
//	if (i < 1 || i > L->length) {
//		return false;
//	}
//	/* 取出删除元素 */
//	*e = L->data[i - 1];
//	/* 从删除元素位置开始遍历到最后一个元素位置，分别将它们都向前移动一个位置 */
//	for (int k = i - 1; k < L->length; k++) {
//		L->data[k] = L->data[k + 1];
//	}
//	/* 表长减1 */
//	L->length--;
//	return true;
//}

/*2022/9/25练习*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<assert.h>
//#include<Windows.h>
//
//int main(int argc, char* argv[]) {
//	if (argc != 2) {
//		fprintf(stdout, "usage: cpu<string>\n");
//	}
//	/*stderr：输出到屏幕，stdout：输出到磁盘文件*/
//
//	char* str = argv[1];
//	while (1) {
//		Sleep(1);
//		printf("%s\n", str);
//	}
//	return 0;
//}


/*2022/9/24练习*/
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define true 1
//#define false 0
//#define MAXSIZE 10
//
//typedef int ElemType;
//typedef struct {
//	ElemType data[MAXSIZE];
//	int length;
//}SqList;
//
//void InitList(SqList* L);
//bool ListInsert(SqList* L, int i, ElemType e);
//
//int main() {
//
//	return 0;
//}
//
//void InitList(SqList* L) {
//	L->length = 0;
//	return;
//}
//bool ListInsert(SqList* L, int i, ElemType e) {
//	/* 1. 如果插入位置不合理，则抛出异常 */
//}
/*2022/9/23练习*/
//# include<stdio.h>
//# include<malloc.h>
//# include<stdlib.h>
//
//# define bool char
//# define true 1
//# define false 0
//# define MAXSIZE 10	/*存储空间初始分配量*/
//
//typedef int ElemType;	/**/
//typedef struct {
//	ElemType data[MAXSIZE];	/* 数组存储数据元素，最大值为MAXSIZE */
//	int length;	/*线性表当前长度*/
//}SqList;
//
//void InitList(SqList* L);
//bool ListEmpty(SqList L);
//bool ListInsert(SqList* L, int i, ElemType e);
//bool ListDelete(SqList* L, int i, ElemType* e);
//void ListTraverse(SqList* L);
//
//int main() {
//	SqList L;
//	int e;
//	InitList(&L);
//	/*for (int k = 0; k < 5; k++) {
//		ListInsert(&L, k + 1, k + 1);
//	}*/
//	ListInsert(&L, 1, 1);
//	ListInsert(&L, 2, 2);
//	ListInsert(&L, 2, 88);
//	ListDelete(&L, 2, &e);
//	ListTraverse(&L);
//	// if (ListEmpty(L))
//	//	printf("链表为空！！！\n");
//
//	return 0;
//}
//
//void InitList(SqList* L) {
//	L->length = 0;
//	return;
//}
//bool ListEmpty(SqList L) {
//	if (L.length == 0) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//bool ListInsert(SqList* L, int i, ElemType e) {
//	int k;
//	/* 1. 如果插入位置不合理， 则抛出异常 */
//	if (i < 1 || i > L->length + 1) {
//		return false;
//	}
//	/* 2. 如果线性表长度大于等于数组长度，则抛出异常或动态增加容量 */
//	if (L->length >= MAXSIZE) {
//		return false;
//	}
//	/* 3. 从最后一个元素开始向前遍历到第i个位置，分别将它们都向后移动一个位置*/
//	// k = 1 i = 2
//	for (k = L->length - 1; k >= i - 1; k--) {
//		L->data[k + 1] = L->data[k];
//	}
//	/* 4. 将插入元素填入位置i处 */
//	L->data[i - 1] = e;
//	/* 5. 表长加1 */
//	L->length++;
//	return;
//}
//void ListTraverse(SqList* L) {
//	int k;
//	for (k = 0; k < L->length; k++) {
//		printf("%d\t", L->data[k]);
//	}
//	printf("\n");
//	return;
//}
//bool ListDelete(SqList* L, int i, ElemType* e) {
//	/* 1. 如果删除位置不合理，则抛出异常 */
//	if (i < 1 || i > L->length) {
//		return false;
//	}
//	/* 2. 如果线性表为空，则抛出异常 */
//	if (ListEmpty(*L)) {
//		return false;
//	}
//	/* 3. 将要删除元素填入e */
//	*e = L->data[i - 1];
//	/* 4. 从删除元素位置开始向后遍历到最后一个元素的位置，分别将它们都向前移动一个位置*/
//	for (int k = i - 1; k < L->length; k++) {
//		L->data[k] = L->data[k + 1];
//	}
//	/* 5. 表长减1 */
//	L->length--;
//}

/*2022/9/21练习*/
//# include<stdio.h>
//# include<malloc.h>
//# include<stdlib.h>
//
//# define bool char
//# define true 1
//# define false 0
//# define maxsize 10
//
//typedef int elemtype;
//typedef struct {
//	elemtype data[maxsize];
//	int length;	/*线性表当前长度*/
//
//}sqlist;
//
//void initlist(sqlist* l);
//bool listinsert(sqlist* l, int i, elemtype e);
//bool listinsert01(sqlist* l, int i, elemtype e);
//void listtraverse(sqlist* l);
//
//int main() {
//	sqlist l;
//	initlist(&l);
//	int i = 0;
//	for (i = 0; i < 5; i++) {
//		listinsert(&l, i + 1, i + 1);
//	}
//	listinsert(&l, 6, 88);
//	listtraverse(&l);
//	return 0;
//}
//
//void initlist(sqlist* l) {
//	l->length = 0;
//}
//bool listinsert01(sqlist* l, int i, elemtype e) {
//	int k;
//	/*如果插入位置不合理，抛出异常*/
//	if (i < 1 || i > l->length + 1)
//		return false;
//	/*如果线性表长度大于或等于数组长度，则抛出异常或动态增加容量*/
//	if (l->length >= maxsize) {
//		return false;
//	}
//	/*从最后一个元素开始遍历到第i个位置，分别都将他们向后移动一个位置*/
//	for (k = l->length - 1; k >= i - 1; k--) {
//		l->data[i + 1] = l->data[i];
//	}
//	/*将要插入元素填入位置i处*/
//	l->data[i - 1] = e;
//	/*表长加1*/
//	l->length++;
//	return true;
//}
//
//bool listinsert(sqlist* l, int i, elemtype e) {
//	int k;
//	/*如果插入位置不合理，抛出异常*/
//	if (i < 1 || i > l->length + 1) {
//		return false;
//	}
//	/*如果线性表长度大于等于数组长度，则抛出异常或动态增加容量*/
//	if (l->length >= maxsize) {
//		return false;
//	}
//	/*从最后一个元素开始向前遍历到第i个位置，分别将它们都向后移动一个位置*/
//	for (k = l->length - 1; k >= i - 1; k--) {
//		l->data[k + 1] = l->data[k];
//	}
//	/*将要插入元素填入位置i处*/
//	l->data[i - 1] = e;
//	/*表长加1*/
//	l->length++;
//	return;
//}
//void listtraverse(sqlist* l) {
//	if (l->length == 0) {
//		printf("链表为空！！！\n");
//	}
//	else {
//		int k;
//		for (k = 0; k < l->length; k++) {
//			printf("%d\t", l->data[k]);
//		}
//		printf("\n");
//	}
//	return;
//}

/*练习*/
//#include <stdio.h>
//#include <malloc.h>
//#include <stdlib.h>
//
//struct node {
//	int data;	/*a data item*/
//	struct node* next; /*an address of another node*/
//};
//
//int main() {
//	/*initialize node*/
//	struct node* head = NULL;
//	struct node* one = NULL;
//	struct node* two = NULL;
//	struct node* three = NULL;
//
//	/*Allocate memory*/
//	head = (struct node*)malloc(sizeof(struct node));
//	if (head == NULL) {
//		exit(-1);
//	}
//	one = (struct node*)malloc(sizeof(struct node));
//	if (one == NULL) {
//		exit(-1);
//	}
//	two = (struct node*)malloc(sizeof(struct node));
//	if (two == NULL) {
//		exit(-1);
//	}
//	three = (struct node*)malloc(sizeof(struct node));
//	if (three == NULL) {
//		exit(-1);
//	}
//
//	/*Assign data values*/
//	one->data = 1;
//	two->data = 2;
//	three->data = 3;
//	/*Connect nodes */
//	one->next = two;
//	two->next = three;
//	three->next = NULL;
//
//	/* Save address of first node in head */
//	head->next = one;
//
//	/* If you wanted to put an element 4
//	between 1 and 2, the steps would be:*/
//	
//	/*step1：create a new struct node and 
//	allocate memory to it*/
//	struct node* new_node = (struct node*)malloc(sizeof(struct node));
//	if (new_node == NULL) {
//		exit(-1);
//	}
//	/*step2: Add its data value as 4 */
//	new_node->data = 4;
//	/*step3: Point its next pointer to the struct node containing 2 
//	as the data value*/
//	new_node->next = two;
//	/*step4: Change the next pointer of "1" 
//	to the node we just created*/
//	one->next = new_node;
//
//	/*If you wanted to put an element 88 between 2 and 3, the steps
//	would be:*/
//	/* Step1: Create a new struct node and allocate memory to it*/
//	struct node* new2_node = (struct node*)malloc(sizeof(struct node));
//	if (new2_node == NULL) {
//		exit(-1);
//	}
//	/* Step2: Add its data value as 88*/
//	new2_node->data = 88;
//	/* Step3: Point the(its) next pointer 
//	to the struct node containing 3 as the data value*/
//	new2_node->next = three;
//	/* Step4: Change the next pointer of "2" to the node 
//	we just created*/
//	two->next = new2_node;
//
//	struct node* p;
//	p = head->next;
//	while (p != NULL) {
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef struct arr {
//	int* pBase;
//	int len;
//	int cnt;
//}*pArr, Arr;
//
//void init_arr(pArr p, int len);
//void show_arr(pArr p);
//bool is_empty(pArr p);
//bool is_full(pArr p);
//bool append_arr(pArr p, int val);
//bool insert_arr(pArr p, int pos, int val);
//
//int main() {
//	Arr arr;
//
//	init_arr(&arr, 6);
//	for (int i = 0; i <= 4; i++) {
//		if (append_arr(&arr, i + 1)) {
//			printf("%d元素追加成功！！！\n", i + 1);
//		}
//		else {
//			printf("%d元素追加失败！！！\n", i + 1);
//		}
//	}
//	printf("插入前：");
//	show_arr(&arr);
//	if (insert_arr(&arr, 2, 88)) /*把值88插入位置2*/
//		printf("位置%d插入数值%d成功！！！\n", 2, 88);
//	else
//		printf("位置%d插入数值%d失败！！！\n", 2, 88);
//	printf("插入后：");
//	show_arr(&arr); /*遍历数组所有元素*/
//
//	/*show_arr(&arr);
//	if (is_empty(&arr))
//		printf("元素为空！！！\n");*/
//	return 0;
//}
//
//void init_arr(pArr p, int len) {
//	p->pBase = (pArr)malloc(sizeof(int) * len);
//	if (p->pBase == NULL) {
//		printf("动态内存分配失败！！！");
//		exit(-1);
//	}
//	p->len = len;
//	p->cnt = 0;
//	return;
//}
//void show_arr(pArr p) {
//	int i;
//	if (is_empty(p)) {
//		printf("数组为空！！！\n");
//	}
//	else {
//		for (i = 0; i < p->cnt; i++)
//			printf("%d\t", p->pBase[i]);
//	}
//	printf("\n");
//	return;
//}
//bool is_empty(pArr p) {
//	if (p->cnt == 0)
//		return true;
//	else
//		return false;
//}
//bool is_full(pArr p) {
//	if (p->cnt == p->len)
//		return true;
//	else
//		return false;
//}
//bool append_arr(pArr p, int val) {
//	if (is_full(p)) {
//		printf("链表已满！！！\n");
//		return false;
//	}
//	else {
//		p->pBase[p->cnt] = val;
//		p->cnt++;
//	}
//	return true;
//}
//bool insert_arr(pArr p, int pos, int val) {
//	if (is_full(p)) {
//		printf("数组已满，不可插入！！！\n");
//		return false;
//	}
//	if (pos < 1 || pos > 6) {
//		printf("插入位置错误\n");
//		return false;
//	}
//	// 1 2 3 4 5  88 2
//	int i;
//	for (i = p->cnt - 1; i >= pos - 1; i--) {
//		printf("%d, %d\n", i, p->pBase[i]);
//		p->pBase[i + 1] = p->pBase[i];
//	}
//	p->pBase[pos - 1] = val;
//	p->cnt++;
//	return true;
//}
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef struct arr {
//	int* pBase;
//	int len;
//	int cnt;
//}*pArr, Arr;
//
//void init_arr(pArr p, int len);
//bool append_arr(pArr p, int val);
//bool travese_arr(pArr p);
//bool insert_arr(pArr p, int pos, int val);
//bool delete_arr(pArr p, int pos, int* val);
//bool is_empty(pArr p);
//bool is_full(pArr p);
//
//int main() {
//	Arr arr;
//	init_arr(&arr, 6);
//	// 插入数据
//	for (int i = 0; i <= 3; i++) {
//		if (append_arr(&arr, i + 1)) {
//			printf("添加元素%d成功！！！\n", i + 1);
//		}
//		else
//			printf("添加元素%d失败！！！\n", i + 1);
//	}
//	
//	printf("插入前：\n");
//	travese_arr(&arr);
//	printf("插入后：\n");
//	if (insert_arr(&arr, 2, 88))
//		;
//	else
//		printf("插入失败！！！\n");
//	travese_arr(&arr);
//	
//	int val;
//	printf("删除前：\n");
//	travese_arr(&arr);
//	printf("删除后：\n");
//	if (delete_arr(&arr, 2, &val))
//		printf("成功，删除值是%d\n", val);
//	else
//		printf("删除失败！！！\n");
//	travese_arr(&arr);
//
//	if (is_empty(&arr)) {
//		printf("数组为空！！！\n");
//	}
//	return 0;
//}
//
//void init_arr(pArr p, int len) {
//	p->pBase = (pArr)malloc(sizeof(int) * len);
//	if (p->pBase == NULL) {
//		printf("动态内存分配失败！！！\n");
//		exit(-1);
//	}
//	p->len = len;
//	p->cnt = 0;
//	return;
//}
//bool append_arr(pArr p, int val) {
//	if (is_full(p)) {
//		return false;
//	}
//	p->pBase[p->cnt] = val;
//	p->cnt++;
//	return true;
//}
//bool travese_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("数组为空！！！\n");
//		return false;
//	}
//	for (int i = 0; i < p->cnt; i++) {
//		printf("%d\t", p->pBase[i]);
//	}
//	printf("\n");
//	return true;
//}
//bool insert_arr(pArr p, int pos, int val) {
//	if (is_full(p)) {
//		return false;
//	}
//	if (pos < 1 || pos > p->cnt + 1) {
//		return false;
//	}
//
//	for (int i = p->cnt - 1; i >= pos - 1; i--) {
//		p->pBase[i + 1] = p->pBase[i];
//	}
//	p->pBase[pos - 1] = val;
//	p->cnt++;
//	return true;
//}
//bool delete_arr(pArr p, int pos, int* val) {
//	if (is_empty(p)) {
//		return false;
//	}
//	if (pos < 1 || pos > p->cnt) {
//		return false;
//	}
//	*val = p->pBase[pos - 1];
//	for (int i = pos - 1; i < p->cnt - 1; i++) {
//		p->pBase[i] = p->pBase[i + 1];
//	}
//	p->cnt--;
//	return true;
//}
//bool is_empty(pArr p) {
//	if (p->cnt == 0)
//		return true;
//	else
//		return false;
//}
//bool is_full(pArr p) {
//	if (p->len == p->cnt)
//		return true;
//	else
//		return false;
//}

/*2022/8/19练习*/
//离散存储
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//
//typedef struct Node {
//	int data;	/*数据域*/
//	struct Node* pNext;	/*指针域*/
//}*PNODE, NODE; 
// 
//1) NODE = struct Node
//2) PNODE = struct Node*
//
//
//PNODE create_list();
//bool is_empty(PNODE pHead);
//void traverse_list(PNODE pHead);
//
//int main() { 
//	PNODE pHead = NULL;
//	// 创建一个非循环单链表，并将该链表的头结点的地址赋给pHead
//	pHead = create_list();
//	if (is_empty(pHead)) {
//		printf("链表为空！！！\n");
//	}
//	traverse_list(pHead);
//
//	return 0;
//}
//
//PNODE create_list() {
//	int len; /* 用来存放节点的个数 */
//	int i;
//	int val; /* 用来临时存放用户输入结点的值 */
//
//	/* 分配了一个不存放有效数据的头节点 */
//	PNODE pHead = (PNODE)malloc(sizeof(NODE));
//	if (pHead == NULL) {
//		printf("分配失败，程序终止！！！\n");
//		exit(-1);
//	}
//	PNODE pTail = pHead;
//	pTail->pNext = NULL;
//
//	printf("请输入您要生成链表节点的个数：len = ");
//	scanf_s("%d", &len);
//	loop:if (len < 0) {
//		printf("输入错误，请输入大于1的整数：");
//		scanf_s("%d", &len);
//		goto loop;
//	}
//
//	for (i = 0; i < len; i++) {
//		printf("请输入%d个节点的值：", i + 1);
//		scanf_s("%d", &val);
//
//		PNODE pNew = (PNODE)malloc(sizeof(NODE));
//		if (pNew == NULL) {
//			printf("分配失败，程序终止！！！\n");
//			exit(-1);
//		}
//		pNew->data = val;
//		pTail->pNext = pNew;
//		pNew->pNext = NULL;
//		pTail = pNew;
//	}
//
//	return pHead;
//}
//bool is_empty(PNODE pHead) {
//	if (pHead->pNext == NULL) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//void traverse_list(PNODE pHead) {
//	if (is_empty(pHead))
//		printf("链表为空！！！\n");
//	PNODE p = pHead->pNext;
//
//	while (p != NULL) {
//		printf("%d\t", p->data);
//		p = p->pNext;
//	}
//	return;
//}


/*2022/9/16练习*/
// 连续存储数组
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//// 定义了一个数据类型，该数据类型的名字叫做struct arr
//// 该数据类型含有三个成员，分别是pBase, len, cnt
//typedef struct arr {
//	int* pBase;	// 存储数组第一个元素的地址
//	int len;	// 数据最大长度
//	int cnt;	// 数组当前长度
//}Arr, *pArr;
//
//void init_arr(pArr p, int len);		/*初始化函数声明*/
//void show_arr(pArr p);				/*遍历函数声明*/
//void sort_arr(pArr p);				/*排序函数声明（降序）*/
//bool append_arr(pArr p, int val);	/*追加函数声明*/
//bool insert_arr(pArr p, int val, int pos); /*插入函数声明*/
//bool delete_arr(pArr p, int* val, int pos);	/*删除函数声明*/
//bool is_full(pArr p);				/*是否为满声明*/
//bool is_empty(pArr p);				/*是否为空声明*/
//
//
//int main() {
//	Arr arr;
//	init_arr(&arr, 6);	/*初始化数组，并且长度为6*/
//	//添加元素
//	for (int i = 0; i < 4; i++) {
//		if (append_arr(&arr, i + 1)) {
//			printf("添加元素%d成功！！！\n", i + 1);
//		} 
//		else {
//			printf("添加元素%d失败！！！\n", i + 1);
//		}
//	}
//	
//	show_arr(&arr);
//	/*insert_arr(&arr, 5, 6);*/
//	int e;
//	if (delete_arr(&arr, &e, 0)) {
//		printf("删除位置%d元素%d成功！！！\n", 0, e);
//	}
//	else {
//		printf("删除失败!!!\n");
//	}
//	sort_arr(&arr);
//	show_arr(&arr);
//
//	return 0;
//}
//
//void init_arr(pArr p, int len) {
//	p->pBase = (pArr)malloc(sizeof(int) * len);
//	if (NULL == p->pBase) {
//		printf("动态内存分配失败！！！\n");
//		exit(-1);
//	}
//	p->len = len;
//	p->cnt = 0;
//	return;
//}
//void show_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("数组为空！！！\n");
//	}
//
//	for (int i = 0; i < p->cnt; i++) {
//		printf("%d\t", p->pBase[i]);
//	}
//	printf("\n");
//	return;
//}
//void sort_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("数组为空！！！\n");
//	}
//	// 1 2 3 4
//	int i = 0, j = 0, t;
//	for (i = 0; i < p->cnt - 1; i++) {
//		for (j = i + 1; j < p->cnt; j++) {
//			if (p->pBase[i] < p->pBase[j]) {
//				t = p->pBase[i];
//				p->pBase[i] = p->pBase[j];
//				p->pBase[j] = t;
//			}
//		}
//	}
//}
//bool append_arr(pArr p, int val) {
//	if (is_full(p)) {
//		return false;
//	}
//	p->pBase[p->cnt] = val;
//	p->cnt++;
//	return true;
//}
//bool insert_arr(pArr p, int val, int pos) {
//	if (is_full(p)) {
//		return false;
//	}
//	if (pos < 1 || pos > p->cnt + 1) {
//		return false;
//	}
//	// 1 2 3 4
//	for (int i = p->cnt - 1; i > pos - 2; i--) {
//		p->pBase[i+1] = p->pBase[i];
//	}
//	p->pBase[pos - 1] = val;
//	p->cnt++;
//	return true;
//}
//bool delete_arr(pArr p, int* val, int pos) {
//	if (is_empty(p)) {
//		return false;
//	}
//	if (pos < 1 || pos > p->cnt) {
//		return false;
//	}
//	// 1 2 3 4  2
//	*val = p->pBase[pos - 1];
//	for (int i = pos - 1; i <= p->cnt; i++) {
//		p->pBase[i] = p->pBase[i + 1];
//	}
//	p->cnt--;
//	return true;
//}
//bool is_full(pArr p) {
//	if (p->len == p->cnt) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//bool is_empty(pArr p) {
//	if (0 == p->cnt) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}

/*2022/9/17练习*/
// 连续存储数组
//# include<stdio.h>
//# include<malloc.h>
//# include<stdlib.h>
//
//# define bool char
//# define true 1
//# define false 0
//
//typedef struct arr {
//	int* pBase;
//	int len;
//	int cnt;
//}*pArr, Arr;
//
//void init_arr(pArr p, int len);
//void show_arr(pArr p);
//void sort_arr(pArr p);
//void traverse_arr(pArr p);
//bool append_arr(pArr p, int val);
//bool insert_arr(pArr p, int val, int pos);
//bool delete_arr(pArr p, int* val, int pos);
//bool is_full(pArr p);
//bool is_empty(pArr p);
//
//
//
//int main() {
//	Arr arr;
//	init_arr(&arr, 6);
//	for (int i = 0; i < 5; i++) {
//		if (append_arr(&arr, i + 1)) {
//			printf("添加%d元素成功!!!\n", i + 1);
//		}
//		else {
//			printf("添加%d元素失败！！！\n", i + 1);
//		}
//	}
//	show_arr(&arr);
//	/*insert_arr(&arr, 88, 0);
//	int e;
//	delete_arr(&arr, &e, 0);
//	printf("%d\n", e);
//	sort_arr(&arr);*/
//	traverse_arr(&arr);
//	show_arr(&arr);
//	return 0;
//}
//
//void init_arr(pArr p, int len) {
//	p->pBase = (pArr)malloc(sizeof(int) * len);
//	if (NULL == p->pBase) {
//		printf("动态内存分配失败！！！\n");
//		exit(-1);
//	}
//	p->len = len;
//	p->cnt = 0;
//	return;
//}
//void show_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("数组为空！！！\n");
//	}
//	for (int i = 0; i < p->cnt; i++) {
//		printf("%d\t", p->pBase[i]);
//	}
//	printf("\n");
//	return;
//}
//void sort_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("数组为空！！！\n");
//	}
//	// 1 2 3 4
//	int t;
//	for (int i = 0; i < p->cnt - 1; i++) {
//		for (int j = i + 1; j < p->cnt; j++) {
//			if (p->pBase[i] < p->pBase[j]) {
//				t = p->pBase[i];
//				p->pBase[i] = p->pBase[j];
//				p->pBase[j] = t;
//			}
//		}
//	}
//	return;
//}
//void traverse_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("数组为空！！！\n");
//	}
//	else {
//		// 1 2 3 4
//		int i = 0, j = p->cnt - 1, t;
//		while (i <= j) {
//			t = p->pBase[i];
//			p->pBase[i] = p->pBase[j];
//			p->pBase[j] = t;
//			i++;
//			j--;
//		}
//	}
//	return;
//}
//bool append_arr(pArr p, int val) {
//	if (is_full(p)) {
//		return false;
//	}
//	p->pBase[p->cnt] = val;
//	p->cnt++;
//	return true;
//}
//bool insert_arr(pArr p, int val, int pos) {
//	if (is_full(p) || pos < 1 || pos > p->cnt + 1) {
//		return false;
//	}
//	for (int i = p->cnt - 1; i > pos - 2; i--) {
//		p->pBase[i + 1] = p->pBase[i];
//	}
//	p->pBase[pos - 1] = val;
//	p->cnt++;
//	return true;
//}
//bool delete_arr(pArr p, int* val, int pos) {
//	if (is_empty(p) || pos < 1 || pos > p->cnt) {
//		return false;
//	}
//	*val = p->pBase[pos - 1];
//	for (int i = pos - 1; i < p->cnt; i++) {
//		p->pBase[i] = p->pBase[i + 1];
//	}
//	p->cnt--;
//	return true;
//}
//bool is_full(pArr p) {
//	if (p->cnt == p->len) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//bool is_empty(pArr p) {
//	if (p->cnt == 0) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}

/*2022/9/19练习*/
//# include<stdio.h>
//# include<malloc.h>
//# include<stdlib.h>
//
//# define bool char
//# define true 1
//# define false 0
//
//typedef struct node {
//	int data;
//	struct node* pNext;
//}*PNODE, NODE;
//
//PNODE create_list(PNODE pHead);
//void traverse_list(PNODE pHead);
//
//int main() {
//	PNODE pHead = NULL;
//	pHead = create_list(pHead);
//	traverse_list(pHead);
//	return 0;
//}
//
//PNODE create_list(PNODE pHead) {
//	pHead = (PNODE)malloc(sizeof(NODE));
//	if (NULL == pHead) {
//		printf("动态内存分配地址失败！！！\n");
//		exit(-1);
//	}
//
//	PNODE pTail = pHead;
//	pTail->pNext = NULL;
//
//	int len, val, i;
//	printf("请输入创建单链表的长度：len = ");
//	scanf_s("%d", &len);
//
//	for (i = 0; i < len; i++) {
//		printf("请输入第%d个节点的值：", i + 1);
//		scanf_s("%d", &val);
//		PNODE pNew = (PNODE)malloc(sizeof(NODE));
//		if (NULL == pNew) {
//			printf("动态内存分配失败！！！\n");
//			exit(-1);
//		}
//		pNew->data = val;
//		pNew->pNext = NULL;
//		pTail->pNext = pNew;
//		pTail = pNew;
//	}
//	return pHead;
//}
//void traverse_list(PNODE pHead) {
//	if (pHead->pNext == NULL) {
//		printf("空链表！！！\n");
//	}
//	else {
//		PNODE p = pHead->pNext;
//		while (p != NULL) {
//			printf("%d\t", p->data);
//			p = p->pNext;
//		}
//		printf("\n");
//	}
//	return;
//}

/*2022/9/21练习*/
// 离散存储
//# include<stdio.h>
//# include<malloc.h>
//# include<stdlib.h>
//
//# define bool char
//# define true 1
//# define false 0
//
//typedef struct node {
//	int data;
//	struct node* pNext;
//}*PNODE, NODE;
//
//PNODE create_list();
//bool insert_list(PNODE pHead, int pos, int val);
//bool is_empty(PNODE pHead);
//int length_list(PNODE pHead);
//void traverse_list(PNODE pHead);
//
//int main() {
//	PNODE pHead = NULL;
//	pHead = create_list();
//	traverse_list(pHead);
//	insert_list(pHead, 2, 88);
//	traverse_list(pHead);
//	// printf("%d\n", length_list(pHead));
//	return 0;
//}
//
//PNODE create_list() {
//	int i, len, val;
//	PNODE pHead = (PNODE)malloc(sizeof(NODE));
//	if (NULL == pHead) {
//		printf("动态内存分配失败！！！\n");
//		exit(-1);
//	}
//	PNODE pTail = pHead;
//	pTail->pNext = NULL;
//
//	printf("请输入创建节点个数：len = ");
//	scanf_s("%d", &len);
//
//	for (i = 0; i < len; i++) {
//		printf("请输入第一个节点的值：");
//		scanf_s("%d", &val);
//		PNODE pNew = (PNODE)malloc(sizeof(NODE));
//		if (NULL == pNew) {
//			printf("动态内存分配失败！！！\n");
//			exit(-1);
//		}
//		pNew->data = val;
//		pNew->pNext = NULL;
//		pTail->pNext = pNew;
//		pTail = pNew;
//	}
//	return pHead;
//}
//bool insert_list(PNODE pHead, int pos, int val) {
//	int i = 0, len = length_list(pHead);
//	PNODE p = pHead;
//
//	if (pos < 1 || pos > len + 1) {
//		return false;
//	}
//	// 1 2 3 4 2 88
//	for (i = 0; i < pos - 1; i++) {
//		p = p->pNext;
//	}
//	PNODE pNew = (PNODE)malloc(sizeof(NODE));
//	if (NULL == pNew) {
//		printf("动态内存分配失败！！！\n");
//		exit(-1);
//	}
//	pNew->data = val;
//	pNew->pNext = p->pNext;
//	p->pNext = pNew;
//	return true;
//}
//bool is_empty(PNODE pHead) {
//	if (NULL == pHead->pNext) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//int length_list(PNODE pHead) {
//	PNODE p = pHead->pNext;
//	int i = 0;
//	while (p != NULL) {
//		i++;
//		p = p->pNext;
//	}
//	return i;
//}
//void traverse_list(PNODE pHead) {
//	PNODE p = pHead->pNext;
//	while (p != NULL) {
//		printf("%d\t", p->data);
//		p = p->pNext;
//	}
//	printf("\n");
//	return;
//}
//
//
//bool insert_list(PNODE pHead, int pos, int val) {
//	int i = 0;
//	PNODE p = pHead;
//	while (NULL != p && i < pos - 1) {
//		p = p->pNext;
//		i++;
//	}
//	if (i > pos - 1 || NULL == p)
//		return false;
//	PNODE pNew = (PNODE)malloc(sizeof(NODE));
//	if (NULL == pNew) {
//		printf("动态内存分配失败！！！\n");
//		exit(-1);
//	}
//	pNew->data = val;
//	pNew->pNext = p->pNext;
//	p->pNext = pNew;
//	return;
//}
