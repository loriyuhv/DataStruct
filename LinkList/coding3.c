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
