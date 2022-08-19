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
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define bool char
#define true 1
#define false 0


typedef struct Node {
	int data;	/*数据域*/
	struct Node* pNext;	/*指针域*/
}*PNODE, NODE; 
/* 
1) NODE = struct Node
2) PNODE = struct Node*
*/

PNODE create_list();

int main() { 
	PNODE pHead = NULL;
	// 创建一个非循环单链表，并将该链表的头结点的地址赋给pHead
	pHead = create_list();

	return 0;
}

PNODE create_list() {
	int len; /* 用来存放节点的个数 */
	int i;
	int val; /* 用来临时存放用户输入结点的值 */

	/* 分配了一个不存放有效数据的头节点 */
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (pHead == NULL) {
		printf("分配失败，程序终止！！！\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;

	printf("请输入您要生成链表节点的个数：len = ");
	scanf_s("%d", &len);
	loop:if (len < 1) {
		printf("输入错误，请输入大于1的整数：");
		scanf_s("%d", &len);
		goto loop;
	}

	for (i = 0; i < len; i++) {
		printf("请输入%d个节点的值：", i + 1);
		scanf_s("%d", &val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (pNew == NULL) {
			printf("分配失败，程序终止！！！\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}

	return pHead;
}