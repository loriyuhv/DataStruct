/* ����ѧ�Ժ±����ݽṹ */
//#include<stdio.h>
//#include<malloc.h>
//
//void f(int k) {
//	int m;
//	double* q = (double*)malloc(200);
//}
//
//int main() {
//	int i = 10;
//	int* p = (int*)malloc(sizeof(int));
//
//	return 0;
//}

/* ջʵ���㷨 */
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef struct Node {
//	int data;
//	struct Node* pNext;
//}NODE, *PNODE;
//
//typedef struct Stack {
//	PNODE pTop;
//	PNODE pBottom;
//}STACK, *PSTACK;
//
//void init(PSTACK);
//void push(PSTACK);
//void traverse(PSTACK);
//bool pop(PSTACK, int*);
//void clear(PSTACK);
//
//int main01() {
//	STACK S;
//	int e;
//	init(&S);	/* Ŀ�������һ����ջ */
//	push(&S, 1);	/* ѹջ */
//	push(&S, 2);
//	traverse(&S);	/* ���� */
//	if (pop(&S, &e)) {
//		printf("��ջ�ɹ���������ջԪ����%d\n", e);
//	}
//	traverse(&S);
//	push(&S, 2);
//	traverse(&S);
//	clear(&S);
//	traverse(&S);
//	/*��������Ƿ�ɹ�����*/
//	/*
//	for (int i = 0; i < 99999999; i++) {
//		push(&S, i + 1);
//	}
//	clear(&S);
//	traverse(&S);
//	for (int i = 0; i < 9999999; i++) {
//		push(&S, i + 1);
//	}
//	traverse(&S);
//	*/
//	return 0;
//}
//
//void init(PSTACK pS) {
//	pS->pTop = (PNODE)malloc(sizeof(NODE)); /* ͷ��� */
//	if (NULL == pS->pTop) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	else {
//		pS->pBottom = pS->pTop;
//		pS->pTop->pNext = NULL;	/* pS->pBottom->pNext = NULL; */
//	}
//	return;
//}
//void push(PSTACK pS, int e) {
//	PNODE pNew = (PNODE)malloc(sizeof(NODE));
//	pNew->data = e;
//	pNew->pNext = pS->pTop;	/* pS->pTop���ܸĳ�pS->Bottom */
//	pS->pTop = pNew;
//	return;
//}
//void traverse(PSTACK pS) {
//	PNODE p = pS->pTop;
//	if (!p->pNext) {
//		printf("��ջ������\n");
//	}
//	while (p != pS->pBottom) {
//		printf("%d\t", p->data);
//		p = p->pNext;
//	}
//	printf("\n");
//	return;
//}
//bool pop(PSTACK pS, int* e) {
//	PNODE r = pS->pTop;
//	if (!r->pNext) {
//		return false;
//	}
//	*e = r->data;
//	pS->pTop = r->pNext;
//	free(r);
//	return true;
//}
//void clear(PSTACK pS) {
//	PNODE r, q;
//	// pS->pTop = pS->pBottom;
//	while (pS->pTop != pS->pBottom) {
//		r = pS->pTop;
//		pS->pTop = r->pNext;
//		free(r);
//	}
//	return;
//}