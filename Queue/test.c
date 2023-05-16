/*���и�ϰ*/
/*����˳��洢*/
#include<stdio.h>

#define MAXSIZE 5
#define bool char
#define true 1
#define false 0

typedef int QElemType;

/* ѭ�����е�˳��洢�ṹ */
typedef struct {
	QElemType data[MAXSIZE];
	int front;	/* ͷָ�� */
	int rear;	/* βָ�� */
}SqQueue;

// ��ʼ��һ���ն���Q
bool InitQueue(SqQueue* Q) {
	Q->front = 0;
	Q->rear = 0;
	return true;
}

// ����Q��Ԫ�ظ�����Ҳ���ǵ�ǰ���еĳ���
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

// ������δ���������Ԫ��eΪQ�µĶ�βԪ��
bool EnQueue(SqQueue* Q, QElemType e) {
	// ���������ж�
	if ((Q->rear + 1) % MAXSIZE == Q->front) {
		return false;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;	/* rearָ�������һλ�ã����������ת������ͷ��*/
	return true;
}
// �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ
bool DeQueue(SqQueue* Q, QElemType* e) {
	// ���пյ��ж�
	if (Q->front == Q->rear)
		return false;

	*e = Q->data[Q->front];	/* ����ͷԪ�ظ�ֵ��e */
	Q->front = (Q->front + 1) % MAXSIZE; /* frontָ�������һλ�ã����������ת������ͷ��*/
	return true;
}

int main() {
	SqQueue Q;
	InitQueue(&Q);
	for (int i = 0; i < 7; i++) {
		if (EnQueue(&Q, i + 1))
			printf("�����%d��Ԫ�سɹ�������\n", i + 1);
	}
	for (int j = 0; j < 2; j++) {
		QElemType e;
		if (DeQueue(&Q, &e)) {
			printf("%d\t", e);
		}
	}
	printf("%d\n", QueueLength(Q));

	return 0;
}
/*ѭ�����е�˳��洢�ṹ��ϰ*/
//#include<stdio.h>
//
//#define MAXSIZE 10
//
//typedef int QElemType;
//// ѭ�����е�˳��洢�ṹ
//typedef struct {
//	QElemType data[MAXSIZE];
//	int front;	/* ͷָ�� */
//	int rear;
//}SqQueue;
//
//
//
//int main() {
//
//
//	return 0;
//}

/* ö������Ӧ�� */
//#include <stdio.h>
//
//typedef enum {Link, Thread, Sun} PointerTag;
//
//int main() {
//	PointerTag LTag = Sun;
//	printf("%d", LTag);
//	return 0;
//}

//#include<stdio.h>
//
//#define MAX_SIZE 10
//
//typedef int ElemType;
//typedef struct {
//	ElemType data[MAX_SIZE];
//	int length;
//}Queue;
//
//void InitQueue(Queue* Q) {
//	Q->length = 0;
//}
//int GetHead(Queue* Q, int* e) {
//	if (!Q->length)
//		return 0;
//	*e = Q->data[0];
//	for (int i = 0; i < Q->length; ++i) {
//		Q->data[i] = Q->data[i + 1];
//	}
//	return 1;
//}
//
//int EnQueue(Queue* Q, int e) {
//	if (Q->length == MAX_SIZE) {
//		printf("��������������");
//		return 0;
//	}
//	Q->data[Q->length] = e;
//	Q->length++;
//	return 1;
//}
//
//int main() {
//	Queue a;
//	int e;
//	InitQueue(&a);
//	for (int i = 0; i < 5; i++) {
//		EnQueue(&a, i + 1);
//	}
//	for (int i = 0; i < 2; i++) {
//		if (GetHead(&a, &e))
//			printf("���ӳɹ���ֵ��%d\n", e);
//	}
//	if (GetHead(&a, &e))
//		printf("���ӳɹ���ֵ��%d\n", e);
//
//	return 0;
//}

//#include<stdio.h>
//
//int main() {
//	int a = 10;
//	//printf("%d\n", sizeof(int));
//	return 0;
//}

//#include<stdio.h>
//
//void hanoi(int n, char A, char B, char C) {
//	if (n == 1) {
//		printf("�����Ϊ%d������ֱ�Ӵ�%c�����Ƶ�%c����\n", n, A, C);
//	}
//	else {
//		//2 A C B 1 A B C
//		hanoi(n - 1, A, C, B);
//		printf("�����Ϊ%d������ֱ�Ӵ�%c�����Ƶ�%c����\n", n, A, C);
//		//B, A, C1 C A B
//		hanoi(n - 1, B, A, C);
//		//3 A, B, C
//		// 2: B, A, C
//		// 1: B, C, A
//	}
//}
//int main() {
//
//	hanoi(3, 'A', 'B', 'C');
//	return 0;
//}
/* ����һ�������������ڼ������һ������ */
//#include<stdio.h>
//
//void func(char name) {
//	printf("Hello %c!!!\n", name);
//}
//
//int main() {
//	func('A');
//	printf("Hello world\n");
//	return 0;
//}
/* ģ��������ջѹջ */
//#include<stdio.h>
//void f() {
//	printf("from f\n");
//}
//int main() {
//	printf("%p", f);
//	
//	return 0;
//}
/*����Ϊʲô����Ϊ5�������±겻��Ϊ5*/
//#include<stdio.h>
//#include<malloc.h>
//
//int main() {
//	int* a = (int*)malloc(sizeof(int) * 3);
//	a[0] = 1;
//	a[1] = 2;
//	a[2] = 3;
//	// a[3] = 4;
//	for (int i = 0; i < 3; i++)
//		printf("%d\t", a[i]);
//
//	printf("\n");
//
//	return 0;
//}