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

/*二叉树的前序遍历算法*/
//#include<iostream>
//#include<stdlib.h>
//#include <cstdlib>
//using namespace std;
//
//typedef struct BiTNode {
//	char data;	/* 结点数据 */
//	struct BiTNode* lchild;
//	struct BiTNode* rchild; /* 左右孩子指针*/
//}BiTNode, *BiTree;
//
///* 二叉树的前序遍历递归算法 */
//void PreOrderTraverse(BiTree T) {
//	if (T == NULL) {
//		return;
//	}
//	printf("%c ", T->data);
//	PreOrderTraverse(T->lchild);
//	PreOrderTraverse(T->rchild);
//}
//
///* #表示空树，构造二叉链表表示二叉树T */
//void CreateBiTree(BiTree* T) {
//	char ch;
//	printf("请输入结点字符：\n");
//	// scanf_s("%c", &ch, sizeof(ch));
//	cin >> ch;
//	if (ch == '#') {
//		*T = NULL;
//	}
//	else {
//		*T = (BiTree)malloc(sizeof(BiTNode));
//		if (!*T) {
//			exit(OVERFLOW);
//		}
//		(*T)->data = ch; /*生成根结点*/
//		CreateBiTree(&(*T)->lchild);
//		CreateBiTree(&(*T)->rchild);
//	}
//}
//
//int main() {
//	BiTree T;
//	CreateBiTree(&T);
//	PreOrderTraverse(T);
//	return 0;
//}
// ABCEDFGHIJL