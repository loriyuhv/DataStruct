/*2023/5/6*/
/*练习不同函数数组传参*/
#include<iostream>
using namespace std;

typedef int Array[10];

void f(Array a) {
	a[0] = 1;
}
void f1(Array* a) {
	(*a)[0] = 99;
}

int main() {
	Array a;
	f(a);
	cout << a[0] << endl;
	f1(&a);
	cout << a[0] << endl;
	return 0;
}

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main() {
//	/*std::vector<std::string> str(1);
//	std::getline(std::cin, str[0]);
//	std::cout << "Hello world!!!\n";
//	std::cout << str[0];*/
//	char str[30] = "Helllo world!!!\n";
//	cout << str[0];
//	return 0;
//}
/* 树形DP */
//#include<iostream>
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//#define N 10	/* 职员最大个数 */
//int h[N];	/* 存储的是员工快乐值 */
//int v[N];
//vector<int> children[N];
//int dp[N][2];
//
//void dfs(int x)
//{
//	// 对于叶子节点来说
//	// 不去为0分
//	dp[x][0] = 0;
//	// 去的话初始化为自己的欢乐指数
//	dp[x][1] = h[x];
//
//	for (int i = 0; i < children[x].size(); ++i) {
//		int y = children[x][i];
//		// 先递归计算孩子的欢乐指数
//		dfs(y);
//		// 加上孩子的欢乐指数
//		// 上司不去，孩子有可能去
//		dp[x][0] += max(dp[y][0], dp[y][1]);
//		// 上司去，孩子不去
//		dp[x][1] += dp[y][0];
//	}
//}
//
//int main() {
//	int n;	/* 职员个数 */
//	scanf_s("%d", &n);
//
//	// 注意下标从1开始，因为题目都是用下标来指定位置的
//	for (int i = 1; i <= n; i++) {
//		scanf_s("%d", &h[i]);
//	}
//
//	for (int i = 1; ; ++i) {
//		int c, p;
//		scanf_s("%d%d", &c, &p); // c是孩子 p是双亲
//		if (!c && !p) break;
//		// 用于判断是否为根节点，只有根结点没有parent
//		v[c] = 1;
//		// 用二维数组记录父子关系
//		children[p].push_back(c);
//	}
//
//	int root;
//	for (int i = 1; i <= n; ++i) {
//		if (!v[i]) {
//			root = i;
//			break;
//		}
//	}
//	// 开始树形递归搜索（线性DP都是迭代搜索）
//	// dfs(root);
//	// printf("%d\n", max(dp[root][0], dp[root][1]));
//	return 0;
//}

/*线索二叉树实现*/
// 二叉树的线索存储结构定义
//#include <stdio.h>
//
//typedef char TElemType;
//typedef enum {Link, Thread} PointerTag;	/* Link == 0 表示指向左右孩子指针 */
//typedef struct BiThrNode {	/* 二叉线索存储结点结构 */
//	TElemType data;	/* 结点数据 */
//	struct BiThrNode* lchild, * rchild;	/* 左右孩子指针 */
//	PointerTag LTag;
//	PointerTag RTag;	/* 左右标志 */
//}BiThrNode, *BiThrTree;

/*二叉树遍历方法，前序、中序、后序及层次遍历*/
//#include<iostream>
//#include<stdio.h>
//using namespace std;
//#define MAXSIZE 10
//
//typedef char TElemType;
//
//typedef struct BiTNode { /*结点结构*/
//	TElemType data;	/*结点数据*/
//	struct BiTNode* lchild, * rchild;	/*左右孩子指针*/
//}BiTNode, *BiTree;
//
//typedef BiTNode QElemType;
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
//// 按前序输入二叉树中结点的值（一个字符）
//// # 表示空树，构造二叉链表表示二叉树
//void CreateBiTree(BiTree* T) {
//	TElemType ch;
//	scanf_s("%c", &ch, 1);
//	if (ch == '#')
//		*T = NULL;
//	else {
//		*T = (BiTree)malloc(sizeof(BiTNode));
//		if (!(*T)) {
//			exit(OVERFLOW);
//		}
//		(*T)->data = ch;	/* 生成根结点 */
//		CreateBiTree(&(*T)->lchild);	/* 生成左子树 */
//		CreateBiTree(&(*T)->rchild);	/* 生成右子树 */
//	}
//}
//// 二叉树的前序遍历递归算法
//void PreOrderTraverse(BiTree T) {
//	if (!T)
//		return;
//	printf("%c\t", T->data);
//	PreOrderTraverse(T->lchild);
//	PreOrderTraverse(T->rchild);
//	return;
//}
//
//// 后序遍历
//void PostOrderTraverse(BiTree T) {
//	if (!T)
//		return;
//	PostOrderTraverse(T->lchild);
//	PostOrderTraverse(T->rchild);
//	printf("%c\t", T->data);
//	return;
//}
//
//// 二叉树的中序遍历递归算法
//void InOrderTraverse(BiTree T) {
//	if (!T)
//		return;
//	InOrderTraverse(T->lchild);
//	printf("%c\t", T->data);
//	InOrderTraverse(T->rchild);
//}
//
//// 二叉树的层序遍历算法
//void LevelOrderTraverse(BiTree T) {
//	SqQueue Q;
//	BiTNode e;
//	InitQueue(&Q);
//	EnQueue(&Q, *T);
//	while (Q.rear != Q.front) {
//		DeQueue(&Q, &e);
//		printf("%c\t", e.data);
//		if (e.lchild)
//			EnQueue(&Q, *e.lchild);
//		if (e.rchild)
//			EnQueue(&Q, *e.rchild);
//	}
//}
//
//int main() {
//	BiTree t;
//	CreateBiTree(&t);
//	PreOrderTraverse(t);
//	printf("\n");
//	InOrderTraverse(t);
//	printf("\n");
//	PostOrderTraverse(t);
//	printf("\n");
//	LevelOrderTraverse(t);
//	return 0;
//}

/*2023/4/30*/
//#include<iostream>
//#include<cstring>
//using namespace std;
//
//int main() {
//	char ch, dh;
//	scanf_s("%c %c", &ch, &dh);
//	//getchar();
//	printf("%c%c", ch, dh);
//	
//	return 0;
//}