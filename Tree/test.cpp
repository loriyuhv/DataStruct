/*2023/5/6*/
/*��ϰ��ͬ�������鴫��*/
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
/* ����DP */
//#include<iostream>
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//#define N 10	/* ְԱ������ */
//int h[N];	/* �洢����Ա������ֵ */
//int v[N];
//vector<int> children[N];
//int dp[N][2];
//
//void dfs(int x)
//{
//	// ����Ҷ�ӽڵ���˵
//	// ��ȥΪ0��
//	dp[x][0] = 0;
//	// ȥ�Ļ���ʼ��Ϊ�Լ��Ļ���ָ��
//	dp[x][1] = h[x];
//
//	for (int i = 0; i < children[x].size(); ++i) {
//		int y = children[x][i];
//		// �ȵݹ���㺢�ӵĻ���ָ��
//		dfs(y);
//		// ���Ϻ��ӵĻ���ָ��
//		// ��˾��ȥ�������п���ȥ
//		dp[x][0] += max(dp[y][0], dp[y][1]);
//		// ��˾ȥ�����Ӳ�ȥ
//		dp[x][1] += dp[y][0];
//	}
//}
//
//int main() {
//	int n;	/* ְԱ���� */
//	scanf_s("%d", &n);
//
//	// ע���±��1��ʼ����Ϊ��Ŀ�������±���ָ��λ�õ�
//	for (int i = 1; i <= n; i++) {
//		scanf_s("%d", &h[i]);
//	}
//
//	for (int i = 1; ; ++i) {
//		int c, p;
//		scanf_s("%d%d", &c, &p); // c�Ǻ��� p��˫��
//		if (!c && !p) break;
//		// �����ж��Ƿ�Ϊ���ڵ㣬ֻ�и����û��parent
//		v[c] = 1;
//		// �ö�ά�����¼���ӹ�ϵ
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
//	// ��ʼ���εݹ�����������DP���ǵ���������
//	// dfs(root);
//	// printf("%d\n", max(dp[root][0], dp[root][1]));
//	return 0;
//}

/*����������ʵ��*/
// �������������洢�ṹ����
//#include <stdio.h>
//
//typedef char TElemType;
//typedef enum {Link, Thread} PointerTag;	/* Link == 0 ��ʾָ�����Һ���ָ�� */
//typedef struct BiThrNode {	/* ���������洢���ṹ */
//	TElemType data;	/* ������� */
//	struct BiThrNode* lchild, * rchild;	/* ���Һ���ָ�� */
//	PointerTag LTag;
//	PointerTag RTag;	/* ���ұ�־ */
//}BiThrNode, *BiThrTree;

/*����������������ǰ�����򡢺��򼰲�α���*/
//#include<iostream>
//#include<stdio.h>
//using namespace std;
//#define MAXSIZE 10
//
//typedef char TElemType;
//
//typedef struct BiTNode { /*���ṹ*/
//	TElemType data;	/*�������*/
//	struct BiTNode* lchild, * rchild;	/*���Һ���ָ��*/
//}BiTNode, *BiTree;
//
//typedef BiTNode QElemType;
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
//// ��ǰ������������н���ֵ��һ���ַ���
//// # ��ʾ������������������ʾ������
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
//		(*T)->data = ch;	/* ���ɸ���� */
//		CreateBiTree(&(*T)->lchild);	/* ���������� */
//		CreateBiTree(&(*T)->rchild);	/* ���������� */
//	}
//}
//// ��������ǰ������ݹ��㷨
//void PreOrderTraverse(BiTree T) {
//	if (!T)
//		return;
//	printf("%c\t", T->data);
//	PreOrderTraverse(T->lchild);
//	PreOrderTraverse(T->rchild);
//	return;
//}
//
//// �������
//void PostOrderTraverse(BiTree T) {
//	if (!T)
//		return;
//	PostOrderTraverse(T->lchild);
//	PostOrderTraverse(T->rchild);
//	printf("%c\t", T->data);
//	return;
//}
//
//// ����������������ݹ��㷨
//void InOrderTraverse(BiTree T) {
//	if (!T)
//		return;
//	InOrderTraverse(T->lchild);
//	printf("%c\t", T->data);
//	InOrderTraverse(T->rchild);
//}
//
//// �������Ĳ�������㷨
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