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