#include<iostream>
#include<stdlib.h>
#include <cstdlib>
using namespace std;

typedef struct BiTNode {
	char data;	/* 结点数据 */
	struct BiTNode* lchild;
	struct BiTNode* rchild; /* 左右孩子指针*/
}BiTNode, *BiTree;

/* 二叉树的前序遍历递归算法 */
void PreOrderTraverse(BiTree T) {
	if (T == NULL) {
		return;
	}
	printf("%c ", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

/* #表示空树，构造二叉链表表示二叉树T */
void CreateBiTree(BiTree* T) {
	char ch;
	printf("请输入结点字符：\n");
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
		(*T)->data = ch; /*生成根结点*/
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