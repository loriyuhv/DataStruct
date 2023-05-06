/*队列：顺序存储结构实现 */
//#include<stdio.h>
//
//#define MAXSIZE 10
//typedef int QElemType;
//// 循环队列的顺序存储结构
//typedef struct {
//	QElemType data[MAXSIZE];
//	int front;	/* 头指针 */
//	int rear;	/* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
//}SqQueue;
//
//// 初始化一个空队列
//int InitQueue(SqQueue* Q) {
//	Q->front = 0;
//	Q->rear = 0;
//	return 1;
//}
//// 返回Q的元素个数，也就是队列当前长度
//int QueueLength(SqQueue Q) {
//	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
//}
//// 若队列未满，则插入元素e为Q新的队尾元素
//int EnQueue(SqQueue* Q, QElemType e) {
//	if ((Q->rear + 1) % MAXSIZE == Q->front)	// 队列满的判断
//		return 0;
//	Q->data[Q->rear] = e;	/* 将元素e赋值给队尾 */
//	Q->rear = (Q->rear + 1) % MAXSIZE; /* rear指针向后移一位，
//									   若到最后则转到数组头部 */
//	return 1;
//}
//// 若队列不空，则删除Q中队头元素，用e返回其值
//int DeQueue(SqQueue* Q, QElemType* e) {
//	if (Q->front == Q->rear)
//		return 0;
//	*e = Q->data[Q->front];
//	Q->front = (Q->front + 1) % MAXSIZE;	/* front 指针后移一位置，
//											若到最后则转到数组头部 */
//	return 1;
//}
//
//int main() {
//	SqQueue q;
//	QElemType e;
//	InitQueue(&q);
//	EnQueue(&q, 1);
//	if (DeQueue(&q, &e))
//		printf("%d\n", e);
//	printf("%d\n", QueueLength(q));
//	return 0;
//}



/* 汉诺塔 */
//#include<stdio.h>
//
//void hanoi(int, char, char);
//
//int main() {
//	char ch1 = 'A';
//	char ch2 = 'B';
//	char ch3 = 'C';
//	int n;
//	printf("请输入要盘子的个数：");
//	scanf_s("%d", &n);
//
//	hanoi(n, 'A', 'B', 'C');
//
//	return 0;
//}
//void hanoi(int n, char A, char B, char C) {
//	/*
//	// 如果是一个盘子
//		// 直接将X柱子上的盘子从A移到C
//	// 否则
//		// 先将A柱子上的n-1个盘子借助C移到B
//		// 直接将A柱子上的盘子从A移到B
//		// 最后将B柱子上的n-1个盘子借助A移动到C
//	*/
//	if (n == 1) {
//		printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
//	}
//	else {
//		hanoi(n - 1, A, C, B);
//		printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
//		hanoi(n - 1, B, A, C);
//	}
//}

/* A函数调用B函数举例 */
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
/* 求阶乘(factorial) */
// n! = n * (n-1)!
// 假定n的值是1或大于1的值
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
//自己写的
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
/*1+2+3+4+....+100的和*/
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
// 自己写的
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

/* 自己调用自己 */
//#include<stdio.h>
//
//void f(int n) {
//	if (n == 1)
//		printf("哈哈！！！\n");
//	else
//		f(n - 1);
//}
//
//int main() {
//	f(3);
//	return 0;
//}
/* 不同函数之间的相互调用 */
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
/* 队列 */
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
//			printf("插入%d元素成功！！！\n", i + 1);
//		}
//		else {
//			printf("插入%d元素失败！！！\n", i + 1);
//		}
//	}
//	printf("出队前元素：");
//	traverse_queue(&Q);
//	int e;
//	for (int i = 0; i < 7; i++) {
//		if (out_queue(&Q, &e)) {
//			printf("出队元素%d成功！！！\n", e);
//		}
//		else {
//			printf("出队失败！！！\n");
//		}
//	}
//	
//	printf("出队后元素：");
//	traverse_queue(&Q);
//	if (Q.rear == Q.front) {
//		printf("空队列！！！");
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