
/*2022/10/25*/
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
//void push(PSTACK, int);
//void traverse(PSTACK);
//bool pop(PSTACK, int*);
//void clear(PSTACK);
//
//int main() {
//	STACK S;
//	init(&S);
//	for (int i = 0; i < 5; i++) {
//		push(&S, i + 1);
//	}
//	printf("���ǰԪ�أ�");
//	traverse(&S);
//	clear(&S);
//	printf("��պ�Ԫ�أ�");
//	traverse(&S);
//
//	/*printf("��ջǰԪ�أ�");
//	traverse(&S);
//	int e;
//	if (pop(&S, &e))
//		printf("��ջ�ɹ�������Ԫ����%d\n", e);
//	printf("��ջ��Ԫ�أ�");
//	traverse(&S);*/
//
//	/*push(&S, 1);
//	push(&S, 2);
//	traverse(&S);
//	if (S.pTop == S.pBottom) {
//		printf("��ջ������\n");
//	}*/
//	return 0;
//}
//
//void init(PSTACK pS) {
//	pS->pTop = (PNODE)malloc(sizeof(NODE));
//	if (!pS->pTop) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	else {
//		pS->pBottom = pS->pTop;
//		pS->pTop->pNext = NULL;
//	}
//	return;
//}
//void push(PSTACK pS, int e) {
//	PNODE pNew = (PNODE)malloc(sizeof(NODE));
//	pNew->data = e;
//	pNew->pNext = pS->pTop;
//	pS->pTop = pNew;
//	return;
//}
//void traverse(PSTACK pS) {
//	PNODE p = pS->pTop;
//	if (p == pS->pBottom) {
//		printf("��ջ������\n");
//	}
//	else {
//		while (p != pS->pBottom) {
//			printf("%d\t", p->data);
//			p = p->pNext;
//		}
//	}
//	printf("\n");
//	return;
//}
//bool pop(PSTACK pS, int* e) {
//	PNODE r = pS->pTop;
//	if (!r->pNext) {
//		return false;
//	}
//	else {
//		*e = r->data;
//		pS->pTop = r->pNext;
//		free(r);
//		return true;
//	}
//}
//void clear(PSTACK pS) {
//	PNODE r;
//	while (pS->pTop->pNext) {
//		r = pS->pTop;
//		pS->pTop = r->pNext;
//		free(r);
//	}
//	return;
//}