//#include<stdio.h>
//
//#define MAXSIZE 10
//typedef int QElemType;
//// ѭ�����е�˳��洢�ṹ
//typedef struct {
//	QElemType data[MAXSIZE];
//	int front;	/* ͷָ�� */
//	int rear;	/* βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� */
//}SqQueue;
//
//// ��ʼ��һ���ն���
//int InitQueue(SqQueue* Q) {
//	Q->front = 0;
//	Q->rear = 0;
//	return 1;
//}
//// ����Q��Ԫ�ظ�����Ҳ���Ƕ��е�ǰ����
//int QueueLength(SqQueue Q) {
//	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
//}
//// ������δ���������Ԫ��eΪQ�µĶ�βԪ��
//int EnQueue(SqQueue* Q, QElemType e) {
//	if ((Q->rear + 1) % MAXSIZE == Q->front)	// ���������ж�
//		return 0;
//	Q->data[Q->rear] = e;	/* ��Ԫ��e��ֵ����β */
//	Q->rear = (Q->rear + 1) % MAXSIZE; /* rearָ�������һλ��
//									   ���������ת������ͷ�� */
//	return 1;
//}
//// �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ
//int DeQueue(SqQueue* Q, QElemType* e) {
//	if (Q->front == Q->rear)
//		return 0;
//	*e = Q->data[Q->front];
//	Q->front = (Q->front + 1) % MAXSIZE;	/* front ָ�����һλ�ã�
//											���������ת������ͷ�� */
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

/*��������ǰ������㷨*/
//#include<iostream>
//#include<stdlib.h>
//#include <cstdlib>
//using namespace std;
//
//typedef struct BiTNode {
//	char data;	/* ������� */
//	struct BiTNode* lchild;
//	struct BiTNode* rchild; /* ���Һ���ָ��*/
//}BiTNode, *BiTree;
//
///* ��������ǰ������ݹ��㷨 */
//void PreOrderTraverse(BiTree T) {
//	if (T == NULL) {
//		return;
//	}
//	printf("%c ", T->data);
//	PreOrderTraverse(T->lchild);
//	PreOrderTraverse(T->rchild);
//}
//
///* #��ʾ������������������ʾ������T */
//void CreateBiTree(BiTree* T) {
//	char ch;
//	printf("���������ַ���\n");
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
//		(*T)->data = ch; /*���ɸ����*/
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