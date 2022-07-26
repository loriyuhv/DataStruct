/*学自《郝斌数据结构入门》*/
/*线性结构*/
/*连续存储数组*/
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//// 定义了一个数据类型，该数据类型的名字叫做struct Arr
//// 该数据类型含有三个成员，分别是pBase, len, cnt
//typedef struct Arr {
//	int* pBase; /*存储的是数组第一个元素的地址*/
//	int len;	/*数组所能容纳的最大元素个数*/
//	int cnt;	/*当前数组有效元素个数*/
//}*pArr, Arr;
//
//void init_arr(pArr p, int len);				/*初始化函数声明*/
//bool append_arr(pArr p, int val);			/*追加函数声明*/
//bool insert_arr(pArr p, int pos, int e);	/*插入函数声明*/
//bool delete_arr(pArr p, int pos, int* e);	/*删除函数声明*/
//bool is_empty(pArr p);						/*是否为空函数声明*/
//bool is_full(pArr p);						/*是否为满函数声明*/
//void sort_arr(pArr p);						/*排序函数声明*/
//void show_arr(pArr p);						/*遍历函数声明*/
//void inversion_arr(pArr p);					/*倒置函数声明*/
//
//int main() {
//	Arr arr;
//	init_arr(&arr, 6); /*初始化数组，并且长度为6*/
//	/*for (int i = 0; i < 4; i++) {
//		if (append_arr(&arr, i + 1)) 
//			printf("追加数值%d成功！！！\n", i + 1);
//		else
//			printf("追加数值%d失败！！！\n", i + 1);
//	}*/
//	/*测试插入*/
//	//for (int i = 0; i < 4; i++) {
//	//	append_arr(&arr, i + 1);
//	//}
//	//printf("插入前：");
//	//show_arr(&arr);
//	//if (insert_arr(&arr, 2, 88)) /*把值88插入位置2*/
//	//	printf("位置%d插入数值%d成功！！！\n", 2, 88);
//	//else
//	//	printf("位置%d插入数值%d失败！！！\n", 2, 88);
//	//printf("插入后：");
//	//show_arr(&arr); /*遍历数组所有元素*/
//	/*测试删除*/
//	//int e;
//	//for (int i = 0; i < 4; i++) {
//	//	append_arr(&arr, i + 1);
//	//}
//	//printf("删除前：");
//	//show_arr(&arr);
//	//if (delete_arr(&arr, 4, &e)) /*把值88插入位置2*/
//	//printf("位置%d删除数值%d成功！！！\n", 4, e);
//	//else
//	//printf("位置输入不合理或数组为空\n");
//	//printf("删除后：");
//	//show_arr(&arr); /*遍历数组所有元素*/
//	/*测试倒置*/
//	for (int i = 0; i < 5; i++) {
//		append_arr(&arr, i + 1);
//	}
//	printf("倒置前：");
//	show_arr(&arr);
//	inversion_arr(&arr);
//	printf("倒置后：");
//	show_arr(&arr);
//	if (is_empty(&arr)) /*测试数组arr是否创建成功*/
//		printf("数组为空！！！");
//	return 0;
//}
//
//void init_arr(pArr p, int len) {
//	p->pBase = (pArr)malloc(sizeof(int) * len);
//	if (NULL == p->pBase) {
//		printf("动态内存分配失败！！！\n");
//		exit(-1);
//	}
//	p->len = 6;
//	p->cnt = 0;
//	return;
//}
//bool append_arr(pArr p, int val) {
//	if (is_full(p)) /*判断数组是否已满*/
//		return false;
//	p->pBase[p->cnt] = val;
//	p->cnt++;
//	return true;
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
//void show_arr(pArr p) {
//	if (is_empty(p))
//		printf("数组为空！！！\n");
//	else {
//		for (int i = 0; i < p->cnt; i++)
//			printf("%d\t", p->pBase[i]);
//	}
//	printf("\n");
//	return;
//}
//bool insert_arr(pArr p, int pos, int e) {
//	int i;
//	if (is_full(p))	/*判断函数是否已满*/
//		return false;
//	if (pos < 1 || pos > p->cnt + 1) /*判断插入位置是否正确*/
//		return false;
//	if (pos != p->cnt + 1) /*如果插入位置是末尾，直接赋值即可*/
//		for (i = p->cnt - 1; i >= pos - 1; i--) /*给要插入的值腾出位置*/
//			p->pBase[i + 1] = p->pBase[i];
//	p->pBase[pos - 1] = e;
//	p->cnt++;
//	return true;
//}
//bool delete_arr(pArr p, int pos, int* e) {
//	if (is_empty(p)) /*判断数组为空*/
//		return false;
//	if (pos < 1 || pos > p->cnt) /*判断插入位置是否合理*/
//		return false;
//	*e = p->pBase[pos - 1]; /*将删除的值赋给*e*/
//	if (pos != p->cnt)
//		for (int i = pos - 1; i < p->cnt; i++)
//			p->pBase[i] = p->pBase[i + 1];
//	p->cnt--;
//	return true;
//}
//void inversion_arr(pArr p) {
//	/*方法一*/
//	/*int i = 0, j = p->cnt - 1, t;
//	while (i < j) {
//		t = p->pBase[i];
//		p->pBase[i] = p->pBase[j];
//		p->pBase[j] = t;
//		i++;
//		j--;
//	}
//	return;*/
//	/*方法二*/
//	int i = 0, n = p->cnt - 1, t;
//	for (; i <= n / 2; i++) {
//		t = p->pBase[i];
//		p->pBase[i] = p->pBase[n - i];
//		p->pBase[n - i] = t;
//	}
//	return;
//}
//void sort_arr(pArr p) {
//	int i, j, t;
//	for (i = 0; i < p->cnt - 1; i++)
//		for(j  = 0; j < p->cnt - i - 1; j++)
//			if (p->pBase[j] < p->pBase[j + 1]) {
//				t = p->pBase[j];
//				p->pBase[j] = p->pBase[j + 1];
//				p->pBase[j + 1] = t;
//			}
//	return;
//}
// typedef
//# include<stdio.h>
//
//typedef int a;	/*为int再重新多取一个名字，a等价于int*/
//
//typedef struct Student {
//	int id;
//	char name[100];
//	char sex;
//}ST;	/* ST等价于struct Student */
//
//int main() {
//	int i = 10;	/* 等价于 a i = 10 */
//	a j = 10;
//	printf("i = %d, j = %d\n", i, j);
//
//	struct Student st;	/* 等价于 ST st */
//	struct Student* ps = &st; /* 等价于ST* ps = &st */
//	ST st2;
//	ps->id = 20197360;
//	st2 = st;
//	printf("%d\n", st2.id);
//
//	return 0;
//}
// 复杂一点
//# include<stdio.h>
//
//typedef struct Student {
//	int id;
//	char name[100];
//	char sex;
//}* PST, ST; /* PST 等价于 struct Student*,ST 等价于 struct Student */
//
//int main() {
//	ST st;
//	PST ps = &st;
//	ps->id = 20197360;
//	printf("%d\n", ps->id);
//
//	return 0;
//}
 
/*离散存储（单链表）算法*/
//# include<stdio.h>
//# include<malloc.h>
//# include<stdlib.h>
//
//# define bool char
//# define true 1
//# define false 0
//
//typedef struct Node {
//	int data;	/*数据域*/
//	struct Node* pNext;	/*指针域*/
//}*PNODE, NODE;
//
//PNODE create_list();
//bool is_empty(PNODE pHead);
//bool append_list(PNODE pHead, int val);
//bool insert_list(PNODE pHead, int val, int pos);
//bool delete_list(PNODE pHead, int* val, int pos);
//void traverse_list(PNODE pHead);
//int length_list(PNODE pHead);
//
//
//
//int main01() {
//	int e;
//	PNODE pHead = NULL;
//	pHead = create_list();
//	traverse_list(pHead);
//	insert_list(pHead, 88, 1);
//	// append_list(pHead, 5);
//	traverse_list(pHead);
//
//	return 0;
//}
//
//PNODE create_list() {
//	int len;
//	int i;
//	int val;	/*用来临时存放节点的值*/
//	/* 分配了一个不存放有效数据的头节点 */
//	PNODE pHead = (PNODE)malloc(sizeof(NODE));
//	if (pHead == NULL) {
//		printf("动态内存分配失败！！！\n");
//		exit(-1);
//	}
//	PNODE pTail = pHead;
//	pTail->pNext = NULL;
//
//	printf("请输入链表要生成节点的个数：len = ");
//	scanf_s("%d", &len);
//
//	for (i = 0; i < len; i++) {
//		printf("请输入%d个节点的值：", i + 1);
//		scanf_s("%d", &val);
//		PNODE pNew = (PNODE)malloc(sizeof(NODE));
//		if (pNew == NULL) {
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
//
//bool is_empty(PNODE pHead) {
//	if (pHead->pNext == NULL) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//bool append_list(PNODE pHead, int val) {
//	PNODE pNew = (PNODE)malloc(sizeof(NODE));
//	if (NULL == pNew) {
//		printf("动态内存分配失败！！！\n");
//		exit(-1);
//	}
//	PNODE p = pHead->pNext, q = NULL;
//	while (p != NULL) {
//		p = p->pNext;
//		if (p != NULL) {
//			q = p;
//		}
//	}
//	pNew->data = val;
//	pNew->pNext = q->pNext;
//	q->pNext = pNew;
//	return true;
//}
//bool insert_list(PNODE pHead, int val, int pos) {
//	int i;
//	PNODE p = pHead;
//	if (pos < 1 || pos > length_list(pHead) + 1) {
//		return false;
//	}
//	/*for (i = 1; i < pos; i++) {
//		p = p->pNext;
//	}*/
//	PNODE pNew = (PNODE)malloc(sizeof(NODE));
//	if (NULL == pNew) {
//		printf("动态内存分配失败！！！\n");
//		exit(-1);
//	}
//
//	pNew->data = val;
//	pNew->pNext = p->pNext;
//	p->pNext = pNew;
//	return true;
//}
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
//	/*pNew->data = val;
//	PNODE q = p->pNext;
//	p->pNext = pNew;
//	pNew->pNext = q;*/
//	// 改写
//	pNew->data = val;
//	pNew->pNext = p->pNext;
//	p->pNext = pNew;
//	return;
//}
//
//bool delete_list(PNODE pHead, int* val, int pos) {
//	if (is_empty(pHead)) {
//		return false;
//	}
//	if (pos < 1 || pos > length_list(pHead)) {
//		return false;
//	}
//	int i;
//	PNODE p = pHead, q;
//	// 1 2 3  2
//	for (i = 0; i < pos - 1; i++) {
//		p = p->pNext;
//	}
//	q = p->pNext;
//	*val = q->data;
//	q = q->pNext;
//	free(p->pNext);
//	//printf("%d!!!!!!\n", p->pNext->data);
//	p->pNext = q;
//	return true;
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
//int length_list(PNODE pHead) {
//	PNODE p = pHead->pNext;
//	int i = 0;
//
//	while (p != NULL) {
//		i++;
//		p = p->pNext;
//	}
//	return i;
//}
