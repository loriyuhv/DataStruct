#include<iostream>
#include<stdlib.h>
#include <cstdlib>
using namespace std;

typedef struct BiTNode {
	char data;	/* ������� */
	struct BiTNode* lchild;
	struct BiTNode* rchild; /* ���Һ���ָ��*/
}BiTNode, *BiTree;

/* ��������ǰ������ݹ��㷨 */
void PreOrderTraverse(BiTree T) {
	if (T == NULL) {
		return;
	}
	printf("%c ", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

/* #��ʾ������������������ʾ������T */
void CreateBiTree(BiTree* T) {
	char ch;
	printf("���������ַ���\n");
	// scanf_s("%c", &ch, sizeof(ch));
	cin >> ch;
	if (ch == '#') {
		*T = NULL;
	}
	else {
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T) {
			exit(OVERFLOW);
		}
		(*T)->data = ch; /*���ɸ����*/
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

int main() {
	BiTree T;
	CreateBiTree(&T);
	PreOrderTraverse(T);
	return 0;
}
// ABCEDFGHIJL