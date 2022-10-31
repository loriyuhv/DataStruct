/* ��ŵ�� */
#include<stdio.h>

void hanoi(int, char, char);

int main() {
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;
	printf("������Ҫ���ӵĸ�����");
	scanf_s("%d", &n);

	hanoi(n, 'A', 'B', 'C');

	return 0;
}
void hanoi(int n, char A, char B, char C) {
	/*
	// �����һ������
		// ֱ�ӽ�X�����ϵ����Ӵ�A�Ƶ�C
	// ����
		// �Ƚ�A�����ϵ�n-1�����ӽ���C�Ƶ�B
		// ֱ�ӽ�A�����ϵ����Ӵ�A�Ƶ�B
		// ���B�����ϵ�n-1�����ӽ���A�ƶ���C
	*/
	if (n == 1) {
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����Ƶ�%c����\n", n, A, C);
	}
	else {
		hanoi(n - 1, A, C, B);
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����Ƶ�%c����\n", n, A, C);
		hanoi(n - 1, B, A, C);
	}
}

/* A��������B�������� */
//#include<stdio.h>
//
//int f(int n) {
//	n = g(n);
//	return n;
//}
//
//int g(int m) {
//	m = m * 2;
//	return m;
//}
//
//int main() {
//	int val;
//	val = f(5);
//	printf("val = %d\n", val);
//	return 0;
//}

//# include<stdio.h>
//
//int f(int n) {
//	n += 2;
//	return n;
//}
//
//int main() {
//	int val;
//	val = f(5);
//	printf("%d\n", val);
//}
/* ��׳�(factorial) */
// n! = n * (n-1)!
// �ٶ�n��ֵ��1�����1��ֵ
//#include<stdio.h>
//
//// n:3
//// n:3 ?*3 => 2*3
//// n:2 ?*2 => 1*2
//// n:1 1
//long f(long n) {
//	if (1 == n)
//		return 1;
//	else
//		return f(n - 1) * n;
//}
//int main() {
//	printf("%d \n", f(2));
//	return 0;
//}
//�Լ�д��
//#include<stdio.h>
//
//int sum(int n, int c, int a) { // n: 3 c: 3  a: 6
//	if (n == c) {
//		return a * n;
//	}
//	else {
//		sum(n + 1, c, a * n);
//	}
//}
//
//int main() {
//	printf("%d\n", sum(1, 3, 4));
//	return 0;
//}
/*1+2+3+4+....+100�ĺ�*/
//#include<stdio.h>
//
//int sum(int n) {
//	if (n == 1) {
//		return 1;
//	}
//	else {
//		return sum(n - 1) + n;
//	}
//}
//
//int main() {
//	printf("%d\n", sum(100));
//	return 0;
//}
// �Լ�д��
//#include<stdio.h>
//
//int sum(int n, int a) { // n: 1  a: 14
//	if (n == 1) {
//		return a + 1;
//	}
//	else {
//		sum(n - 1, a + n);
//	}
//}
//
//int main() {
//	printf("%d\n", sum(100, 0));
//	return 0;
//}

/* �Լ������Լ� */
//#include<stdio.h>
//
//void f(int n) {
//	if (n == 1)
//		printf("����������\n");
//	else
//		f(n - 1);
//}
//
//int main() {
//	f(3);
//	return 0;
//}
/* ��ͬ����֮����໥���� */
//#include<stdio.h>
//void f();
//void g();
//void k();
//
//int main() {
//	f();
//	return 0;
//}
//void f() {
//	printf("from f\n");
//	g();
//	printf("1111\n");
//	return;
//}
//
//void g() {
//	printf("from g\n");
//	k();
//	printf("2222\n");
//	return;
//}
//
//void k() {
//	printf("fome k\n");
//}
/* ���� */
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define false 0
//#define true 1
//
//typedef struct Queue {
//	int* pBase;
//	int front;
//	int rear;
//}QUEUE;
//
//void init(QUEUE*);
//bool en_queue(QUEUE*, int);
//bool full_queue(QUEUE*);
//bool empty_queue(QUEUE*);
//void traverse_queue(QUEUE*);
//bool out_queue(QUEUE*, int*);
//
//int main() {
//	QUEUE Q;
//	init(&Q);
//	for (int i = 0; i < 8; i++) {
//		if (en_queue(&Q, i + 1)) {
//			printf("����%dԪ�سɹ�������\n", i + 1);
//		}
//		else {
//			printf("����%dԪ��ʧ�ܣ�����\n", i + 1);
//		}
//	}
//	printf("����ǰԪ�أ�");
//	traverse_queue(&Q);
//	int e;
//	for (int i = 0; i < 7; i++) {
//		if (out_queue(&Q, &e)) {
//			printf("����Ԫ��%d�ɹ�������\n", e);
//		}
//		else {
//			printf("����ʧ�ܣ�����\n");
//		}
//	}
//	
//	printf("���Ӻ�Ԫ�أ�");
//	traverse_queue(&Q);
//	if (Q.rear == Q.front) {
//		printf("�ն��У�����");
//	}
//	return 0;
//}
//
//void init(QUEUE* pQ) {
//	pQ->pBase = (int*)malloc(sizeof(int) * 6);
//	pQ->front = 0;
//	pQ->rear = 0;
//	return;
//}
//bool en_queue(QUEUE* pQ, int val) {
//	if (full_queue(pQ)) {
//		return false;
//	}
//	else {
//		pQ->pBase[pQ->rear] = val;
//		pQ->rear = (pQ->rear + 1) % 6;
//		return true;
//	}
//}
//bool full_queue(QUEUE* pQ) {
//	if ((pQ->rear + 1) % 6 == pQ->front)
//		return true;
//	else
//		return false;
//}
//bool empty_queue(QUEUE* pQ) {
//	if (pQ->rear == pQ->front) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//void traverse_queue(QUEUE* pQ) {
//	int i = pQ->front;
//	while (i != pQ->rear) {
//		printf("%d\t", pQ->pBase[i]);
//		i = (i + 1) % 6;
//	}
//	printf("\n");
//	return;
//}
//bool out_queue(QUEUE* pQ, int* pVal) {
//	if (empty_queue(pQ)) {
//		return false;
//	}
//	else {
//		*pVal = pQ->pBase[pQ->front];
//		pQ->front = (pQ->front + 1) % 6;
//		return true;
//	}
//}

//#include<stdio.h>
//
//int main() {
//	printf("Hello Queue!!!\n");
//	return 0;
//}