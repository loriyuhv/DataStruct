/*队列复习*/
/*队列顺序存储*/
#include<stdio.h>

#define MAXSIZE 5
#define bool char
#define true 1
#define false 0

typedef int QElemType;

/* 循环队列的顺序存储结构 */
typedef struct {
	QElemType data[MAXSIZE];
	int front;	/* 头指针 */
	int rear;	/* 尾指针 */
}SqQueue;

// 初始化一个空队列Q
bool InitQueue(SqQueue* Q) {
	Q->front = 0;
	Q->rear = 0;
	return true;
}

// 返回Q的元素个数，也就是当前队列的长度
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

// 若队列未满，则插入元素e为Q新的队尾元素
bool EnQueue(SqQueue* Q, QElemType e) {
	// 队列满的判断
	if ((Q->rear + 1) % MAXSIZE == Q->front) {
		return false;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;	/* rear指针向后移一位置，若到最后则转到数组头部*/
	return true;
}
// 若队列不空，则删除Q中对头元素，用e返回其值
bool DeQueue(SqQueue* Q, QElemType* e) {
	// 队列空的判断
	if (Q->front == Q->rear)
		return false;

	*e = Q->data[Q->front];	/* 将队头元素赋值给e */
	Q->front = (Q->front + 1) % MAXSIZE; /* front指针向后移一位置，若到最后则转到数组头部*/
	return true;
}

int main() {
	SqQueue Q;
	InitQueue(&Q);
	for (int i = 0; i < 7; i++) {
		if (EnQueue(&Q, i + 1))
			printf("插入第%d个元素成功！！！\n", i + 1);
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
/*循环队列的顺序存储结构练习*/
//#include<stdio.h>
//
//#define MAXSIZE 10
//
//typedef int QElemType;
//// 循环队列的顺序存储结构
//typedef struct {
//	QElemType data[MAXSIZE];
//	int front;	/* 头指针 */
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

/* 枚举类型应用 */
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
//		printf("队列已满！！！");
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
//			printf("出队成功，值是%d\n", e);
//	}
//	if (GetHead(&a, &e))
//		printf("出队成功，值是%d\n", e);
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
//		printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
//	}
//	else {
//		//2 A C B 1 A B C
//		hanoi(n - 1, A, C, B);
//		printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
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
/* 当在一个函数的运行期间调用另一个函数 */
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
/* 模拟计算机出栈压栈 */
//#include<stdio.h>
//void f() {
//	printf("from f\n");
//}
//int main() {
//	printf("%p", f);
//	
//	return 0;
//}
/*测试为什么长度为5的数组下标不能为5*/
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