/*静态链表*/
#include <stdio.h>

#define MAXSIZE 10
typedef int ElemType;

typedef struct node {
	ElemType data;
	int cur;	/*游标（Cursor），为0时表示无指向 */
}Component, StaticLinkList[MAXSIZE];

int InitList(StaticLinkList space) {
	int i;
	for (i = 0; i < MAXSIZE; ++i) {
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0; /*目前静态链表为空，最后一个元素的cur为0 */
	return 1;
}
int Listlength(StaticLinkList L) {
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i) {
		i = L[i].cur;
		j++;
	}
	return j;
}
int Malloc_SLL(StaticLinkList space) {
	int i = space[0].cur;	/* 当前数组第一个元素的cur存的值，就是
							返回的第一个备用空闲的下标 */
	if (space[0].cur)
		space[0].cur = space[i].cur;	/* 由于要拿出一个分量来使用了，所以我们
										就得把它的下一个分量用来备用*/
	return i;
}

void Free_SSL(StaticLinkList space, int k) {
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

/* 在L中第i个元素之前插入新的数据元素 */
int ListInsert(StaticLinkList L, int i, ElemType e) {
	int j, k, l;
	k = MAXSIZE - 1;	/*注意k首先是最后一个元素的下标 */
	if (i < 1 || i > Listlength(L) + 1)
		return 0;

	j = Malloc_SLL(L);	/* 获得空闲分量的下标 */
	if (j) {
		L[j].data = e;
		for (l = 1; l <= i - 1; ++l)
			k = L[k].cur;	/*找到第i个元素之前的位置 */
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return 1;
	}
	return 0;
}

/* 删除在L中第i个数据元素e */
int ListDelete(StaticLinkList L, int i) {
	int j, k;
	if (i < 1 || i > Listlength(L))
		return 0;
	k = MAXSIZE - 1;
	for (j = 1; j <= i - 1; j++)
		k = L[k].cur;
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SLL(L, j);
	return 1;
}
void ListTraverse(StaticLinkList L) {
	if (!L[MAXSIZE - 1].cur) {
		printf("链表为空！！！\n");
		return;
	}
	int cursor = L[MAXSIZE - 1].cur;
	while (cursor) {
		printf("%d\t", L[cursor].data);
		cursor = L[cursor].cur;
	}
	printf("\n");
	return;
}
int main() {
	StaticLinkList space;
	InitList(space);
	for (int i = 0; i < 5; ++i)
		ListInsert(space, i+1, i);
	ListTraverse(space);
	ListInsert(space, 2, 88);
	ListTraverse(space);
	return 0;
}
/*顺序存储结构实现存储学生信息*/
//#include<stdio.h>
//
//#define MAXSIZE 10	/* 存储空间初始分配量 */
//#define TRUE 1
//#define FALSE 0
//
//typedef int Boolean;	/* Boolean类型，其值是TRUE和FALSE */
//struct students {
//	char name;
//	char sex;
//	int age;
//};
//typedef struct students ElemType;
//typedef struct {
//	ElemType data[MAXSIZE];	/* 数组存储数据元素， 最大值为MAXSIZE*/
//	int length;	/* 线性表当前长度 */
//}SqList;	/* Sequence List*/
//
//void InitList(SqList* L) {
//	L->length = 0;
//	return;
//}
//Boolean ListEmpty(SqList L) {
//	return L.length ? FALSE : TRUE;
//}
//Boolean GetElem(SqList L, int i, ElemType* e) {
//	if (!L.length || i < 1 || i > L.length)
//		return FALSE;
//	*e = L.data[i - 1];
//	return TRUE;
//}
//Boolean ListInsert(SqList* L, int i, ElemType e) {
//	if (L->length == MAXSIZE || i < 1 || i > L->length + 1)
//		return FALSE;
//
//	if (i < L->length) {
//		for (int k = L->length; k >= i - 1; k--) {
//			L->data[k + 1] = L->data[k];
//		}
//	}
//	L->data[i - 1] = e;
//	L->length++;
//	return TRUE;
//}
//void ListTraverse(SqList L) {
//	if (!L.length)
//		printf("线性表为空！！！\n");
//	for (int k = L.length - 1; k >= 0; --k)
//		printf("Name:%c Age：%d Sex：%c\n", L.data[k].name, L.data[k].age, L.data[k].sex);
//	return;
//}
//
//
//int main() {
//	SqList a;
//	char name, sex;
//	int age;
//	InitList(&a);
//	struct students student;
//	for (int i = 0; i < 3; i++) {
//		scanf_s("%c", &name, 1);
//		scanf_s("%c", &sex, 1);
//		scanf_s("%d", &age);
//		char ch = getchar();
//		student.name = name;
//		student.sex = sex;
//		student.age = age;
//		if (ListInsert(&a, i + 1, student))
//			printf("插入%d值成功！！！\n", i + 1);
//		else
//			printf("插入%d值失败！！！\n", i + 1);
//	}
//	
//	if (ListEmpty(a)) {
//		printf("数组为空！！！\n");
//	}
//
//	ListTraverse(a);
//	return 0;
//}

//#include<stdio.h>
//
//int main() {
//	float weight, price;	/* weight：货物的重量 price:快递费*/
//	printf("请输入货物的重量：");
//	scanf_s("%f", &weight);
//
//	if (weight <= 5) {
//		price = weight * 3;
//	}
//	else if (weight > 5 && weight <= 10) {
//		price = 5 * 3 + (weight - 5) * 3.5;
//	}
//	else if (weight > 10 && weight <= 20) {
//		price = 5 * 3 + 5 * 3.5 + (weight - 10) * 4;
//	}
//	else if (weight > 20 && weight <= 30) {
//		price = 5 * 3 + 5 * 3.5 + 10 * 4 + (weight - 20) * 4.5;
//	}
//	else if (weight > 30 && weight <= 50) {
//		price = 5 * 3 + 5 * 3.5 + 10 * 4 + 10 * 4.5 + (weight - 30) * 5;
//	}
//	else {
//		printf("货物重量>50kg，拒收！！！\n");
//		return 0;
//	}
//	printf("快递费是%.2f元\n", price);
//
//	return 0;
//}

// 实现Boolean类型
//#include<stdio.h>
//
//typedef int Boolean;
//
//#define TRUE 1
//#define FALSE 0
//
//int main() {
//	Boolean a = TRUE;
//	if (a) {
//		printf("Hello world!!!\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//
//typedef struct Classes {
//	char name[10];
//}Classes;
//int main() {
//	Classes num1;
//	int i;
//	for (i = 0; i < 2; i++) {
//		scanf_s("%c",  &num1.name[i], 1);
//		char ch = getchar();
//	}
//
//	for (i = 0; i < 2; i++) {
//		printf("%c\t", num1.name[i]);
//	}
//	return 0;
//}

/*Adjacency List*/
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define MAX_VEX 10
//int visited[MAX_VEX];
//
//typedef int EdgeType;
//typedef char VertexType;
//
//边表结点
//typedef struct EdgeNode {
//	int adjvex;
//	EdgeType weight;
//	struct EdgeNode* next;
//}EdgeNode;
//
//typedef struct VertexNode {
//	VertexType data;
//	EdgeNode* firstedge;	// 边表头结点
//}VertexNode, AdjList[MAX_VEX];
//
//typedef struct GraphAdjList {
//	AdjList adjList;
//	int numVertexes, numEdges;
//}GraphAdjList;
//
//void CreateGraphAdjList(GraphAdjList* G) {
//	int i, j, k, v;
//	EdgeNode* e;
//
//	printf("请输入顶点数和边数：\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);
//
//	for (i = 0; i < G->numVertexes; i++) {
//		printf("请输入第%d个顶点信息：", i + 1);
//		char ch = getchar();
//		scanf_s("%c", &G->adjList[i].data, 1);
//		G->adjList[i].firstedge = NULL;
//	}
//
//	for (k = 0; k < G->numEdges; k++) {
//		printf("请输入边<vi, vj>，下标i和下标j以及权值：\n");
//		scanf_s("%d%d%d", &i, &j, &v);
//
//		EdgeNode* p;
//
//		p = G->adjList[i].firstedge;
//		while (p) {
//			p = p->next;
//		}
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		if (!e) {
//			printf("Failed！！！\n");
//			exit(-1);
//		}
//		e->adjvex = j;
//		e->weight = v;
//		e->next = p;
//		p = e;
//
//		p = G->adjList[j].firstedge;
//		while (p) {
//			p = p->next;
//		}
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		if (!e) {
//			printf("Failed！！！\n");
//			exit(-1);
//		}
//		e->adjvex = i;
//		e->weight = v;
//		e->next = p;
//		p = e;
//	}
//}
//
//void TraverseVertexes(GraphAdjList* G) {
//	int i;
//	for (i = 0; i < G->numVertexes; i++) {
//		printf("%c\t", G->adjList[i].data);
//	}
//	printf("\n");
//}
//
//void dfs(GraphAdjList* G, int i) {
//	EdgeNode* p;
//	visited[i] = 1;
//	printf("%c\t", G->adjList[i].data);
//	p = G->adjList[i].firstedge;
//	while (p) {
//		if (!visited[p->adjvex]) {
//			dfs(G, p->adjvex);
//		}
//		p = p->next;
//	}
//}
//
//void TraverseDfs(GraphAdjList* G) {
//	int i;
//	for (i = 0; i < G->numVertexes; i++) {
//		visited[i] = 0;
//	}
//
//	for (i = 0; i < G->numVertexes; i++) {
//		if (!visited[i]) {
//			dfs(G, i);
//		}
//	}
//}
//
//int main() {
//	GraphAdjList G;
//	CreateGraphAdjList(&G);
//	TraverseDfs(&G);
//	return 0;
//}
// 离散存储（链表）
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef struct Node {
//	int data;
//	struct Node* next;
//}Node, *LinkList;
//void InitList(LinkList* L); // 创建链表声明
//bool ListAdd(LinkList L, int e);	// 添加函数声明
//bool ListEmpty(LinkList L);	// 是否为空函数声明
//bool ListInsert(LinkList L, int pos, int e); // 插入函数声明
//bool ListDelete(LinkList L, int pos, int* element);	// 删除函数声明
//void TraverseList(LinkList L);	//遍历函数声明
//
//int main() {
//	int e;
//	LinkList L = NULL;
//	InitList(&L);
//	TraverseList(L);
//	//ListAdd(L, 5);
//	//ListInsert(L, 5, 5);
//	ListDelete(L, 1, &e);
//	TraverseList(L);
//
//	return 0;
//}
//
//void InitList(LinkList* L) {
//	int i, n, e;
//	LinkList r;
//
//	*L = (LinkList)malloc(sizeof(Node));
//	if (!(*L)) {
//		printf("Failed!!!\n");
//		exit(-1);
//	}
//	(*L)->next = NULL;
//	r = *L;
//	if (!r) {
//		printf("Failed!!!\n");
//		exit(-1);
//	}
//	
//	printf("请输入创建列表的个数：");
//	scanf_s("%d", &n);
//	
//	for (i = 0; i < n; i++) {
//		printf("请输入第%d个结点的值：", i + 1);
//		scanf_s("%d", &e);
//		LinkList p = (LinkList)malloc(sizeof(Node));
//		if (!p) {
//			printf("Failed!!!\n");
//			exit(-1);
//		}
//		p->data = e;
//		p->next = r->next;
//		r->next = p;
//		r = p;
//	}	
//	return;
//}
//bool ListAdd(LinkList L, int e) {
//	LinkList p = L;
//	if (!p) {
//		printf("Failed!!!\n");
//		exit(-1);
//	}
//	
//	while (p->next) {
//		p = p->next;
//	}
//	LinkList node = (LinkList)malloc(sizeof(Node));
//	if (!node) {
//		printf("Failed!!!\n");
//		exit(-1);
//	}
//	node->data = e;
//	node->next = p->next;
//	p->next = node;
//	return true;
//}
//bool ListEmpty(LinkList L) {
//	return L->next ? false : true;
//}
//bool ListInsert(LinkList L, int pos, int e) {
//	int i = 0;
//	LinkList p = L;
//	while (p && i < pos - 1) {
//		p = p->next;
//		i++;
//	}
//	if (i > pos - 1 || !p) {
//		return false;
//	}
//	LinkList node = (LinkList)malloc(sizeof(Node));
//	if (!node) {
//		printf("Failed!!!\n");
//		exit(-1);
//	}
//	node->data = e;
//	node->next = p->next;
//	p->next = node;
//	return true;
//}
//bool ListDelete(LinkList L, int pos, int* element) {
//	if (ListEmpty(L)) {
//		printf("链表为空！插入失败！！！");
//		return false;
//	}
//
//	int i = 1;
//	LinkList p = L;
//	while (p->next && i < pos) {
//		p = p->next;
//		i++;
//	}
//
//	if (!p->next || i > pos) {
//		return false;
//	}
//
//	LinkList r = p->next;
//
//	p->next = r->next;
//	free(r);
//	return true;
//}
//void TraverseList(LinkList L) {
//	LinkList p = L->next;
//	if (ListEmpty(L)) {
//		printf("空链表！！！\n");
//		return;
//	}
//
//	while (p) {
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	printf("\n");
//	return;
//}
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef struct Node {
//	int data;
//	struct Node* pNext;
//}Node, *pNode;
//
//pNode create_list();
//bool is_empty(pNode p);
//void traverse_list(pNode p);
//bool insert_list(pNode pHead, int pos, int val);
//
//int main() {
//	pNode node = create_list();
//	traverse_list(node);
//	insert_list(node, 5, 88);
//	traverse_list(node);
//	return 0;
//}
//
//pNode create_list() {
//	int i, n, val;	// n:结点个数	val：结点值
//	pNode pTail, pHead;
//
//	pHead = (pNode)malloc(sizeof(Node));
//	if (!pHead) {
//		printf("申请内存空间失败！！！\n");
//		exit(-1);
//	}
//	pHead->pNext = NULL;
//	pTail = pHead;
//
//	printf("请输入要创建的结点个数：");
//	scanf_s("%d", &n);
//	for (i = 0; i < n; ++i) {
//		printf("请输入第%d个结点的值：", i + 1);
//		scanf_s("%d", &val);
//		pNode pNew = (pNode)malloc(sizeof(Node));
//		if (!pNew) {
//			printf("申请内存空间失败！！！\n");
//			exit(-1);
//		}
//		pNew->data = val;
//		pNew->pNext = pTail->pNext;
//		pTail->pNext = pNew;
//		pTail = pNew;
//	}
//	return pHead;
//}
//void traverse_list(pNode p) {
//	pNode pL = p->pNext;
//	if (is_empty(p)) {
//		printf("链表为空！！！\n");
//		return;
//	}
//	while (pL) {
//		printf("%d\t", pL->data);
//		pL = pL->pNext;
//	}
//	printf("\n");
//	return;
//}
//bool is_empty(pNode p) {
//	return p->pNext ? false : true;
//}
//
//bool insert_list(pNode pHead, int pos, int val) {
//	pNode p = pHead;
//	if (!p) {
//		exit(-1);
//	}
//
//	pNode pNew;
//	int i = 0;
//	
//	while (p && i < pos - 1) {
//		p = p->pNext;
//		i++;
//	}
//
//	if (i > pos - 1 || !p)
//		return false;
//	pNew = (pNode)malloc(sizeof(Node));
//	if (!pNew) {
//		printf("动态内存分配失败！！\n");
//		exit(-1);
//	}
//	pNew->data = val;
//	pNew->pNext = p->pNext;
//	p->pNext = pNew;
//	return true;
//}

/*顺序存储（数组）*/
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef struct Arr {
//	int* pBase;	/*数组首元素地址*/
//	int len;	/*数组最大长度*/
//	int cnt;	/*数组当前长度*/
//}Arr, *pArr;
//
//void init_arr(pArr p, int len);				/*初始化函数声明*/
//bool append_arr(pArr p, int val);			/*追加函数声明*/
//bool insert_arr(pArr p, int pos, int e);	/*插入函数声明*/
//bool delete_arr(pArr p, int pos, int* e);	/*删除函数声明*/
//bool is_empty(pArr p);						/*是否为空函数声明*/
//bool is_full(pArr p);						/*是否为满函数声明*/
//void show_arr(pArr p);						/*遍历函数声明*/
//void inversion_arr(pArr p);					/*倒置函数声明*/
//
//int main() {
//	Arr arr; 
//	int e;
//	init_arr(&arr, 4);
//	append_arr(&arr, 1);
//	append_arr(&arr, 2);
//	append_arr(&arr, 3);
//	show_arr(&arr);
//	//insert_arr(&arr, 4, 4);
//	// insert_arr(&arr, 5, 5);
//	insert_arr(&arr,2, 88);
//	show_arr(&arr);
//	if (delete_arr(&arr, 2, &e)) {
//		printf("删除位置%d元素%d成功！！！\n", 2, e);
//	}
//	else {
//		printf("删除位置%d元素失败！！！\n", 2);
//	}
//	show_arr(&arr);
//	if (delete_arr(&arr, 1, &e)) {
//		printf("删除位置%d元素%d成功！！！\n", 1, e);
//	}
//	else {
//		printf("删除位置%d元素失败！！！\n", 1);
//	}
//	show_arr(&arr);
//	return 0;
//}
//
//void init_arr(pArr p, int len) {
//	p->pBase = (pArr)malloc(sizeof(int) * len);
//	if (!p->pBase) {
//		printf("申请内存空间失败！！！\n");
//		exit(-1);
//	}
//	p->len = len;
//	p->cnt = 0;
//}
//
//bool append_arr(pArr p, int val) {
//	if (is_full(p)) {
//		printf("数组已满！！！插入%d失败\n", val);
//		return false;
//	}
//	p->pBase[p->cnt] = val;
//	p->cnt++;
//	return true;
//}
//
//bool is_empty(pArr p) {
//	return p->cnt == 0 ? true : false;
//}
//
//bool is_full(pArr p) {
//	return p->cnt == p->len ? true : false;
//}
//void show_arr(pArr p) {
//	int i;
//	if (is_empty(p)) {
//		printf("数组为空！！！\n");
//		return;
//	}
//	for (i = 0; i < p->cnt; i++) {
//		printf("%d\t", p->pBase[i]);
//	}
//	printf("\n");
//	return;
//}
//bool insert_arr(pArr p, int pos, int e) {
//	int i;
//	if (is_full(p)) {
//		printf("数组已满，插入元素%d失败！！！\n", e);
//		return false;
//	}
//	// 判断插入位置是否正确
//	if (pos < 1 && pos > p->cnt + 2) {
//		return false;
//	}
//	if (pos != p->cnt + 1)
//		for (i = p->cnt; i >= pos - 1; --i) {
//			p->pBase[i] = p->pBase[i - 1];
//		}
//	p->pBase[pos - 1] = e;
//	p->cnt++;
//	return;
//}
//
//bool delete_arr(pArr p, int pos, int* e) {
//	if (is_empty(p)) {
//		printf("数组为空，删除位置%d值失败！！！\n", pos);
//		return false;
//	}
//	// 删除位置判断
//	if (pos < 1 && pos > p->cnt) {
//		return false;
//	}
//	// 取出删除元素
//	*e = p->pBase[pos - 1];
//	for (int i = pos - 1; i < p->cnt; i++) {
//		p->pBase[i] = p->pBase[i + 1];
//	}
//	p->cnt--;
//	return true;
//}

/*2023/4/25*/
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define MAX_VEX 100
//int visited[MAX_VEX];
//
//typedef int EdgeType;
//typedef char VertexType;
//
//// 边表结点
//typedef struct EdgeNode {
//	int adjvex;
//	struct EdgeNode* next;
//}EdgeNode;
//
//// 顶点域
//typedef struct VertexNode {
//	VertexType data;
//	EdgeNode* firstedge;
//}VertexNode, AdjList[MAX_VEX];
//
//// 图
//typedef struct {
//	AdjList adjList;
//	int numVertexes, numEdges;
//}GraphAdjList;
//
//void CreateGraphAdjList(GraphAdjList* G) {
//	int i, j, k, v;
//	EdgeNode* e;
//	printf("请输入顶点数和边数：\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);
//	for (i = 0; i < G->numVertexes; i++) {
//		printf("请输入第%d个顶点信息：", i + 1);
//		char ch = getchar();
//		scanf_s("%c", &G->adjList[i].data, 1);
//		G->adjList[i].firstedge = NULL;
//	}
//
//	for (k = 0; k < G->numEdges; ++k) {
//		printf("请输入边<vi, vj> 下标i，下标j以及权重：");
//		scanf_s("%d%d%d", &i, &j, &v);
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		if (!e) {
//			printf("Failed！！！\n");
//			exit(-1);
//		}
//		e->adjvex = j;
//		e->next = G->adjList[i].firstedge;
//		G->adjList[i].firstedge = e;
//
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		if (!e) {
//			printf("Failed！！！\n");
//			exit(-1);
//		}
//		e->adjvex = i;
//		e->next = G->adjList[j].firstedge;
//		G->adjList[j].firstedge = e;
//	}
//	
//}
//
//void CreateGraphAdjListTail(GraphAdjList* G) {
//	int i, j, k, v;
//	EdgeNode* e;
//	
//	printf("请输入顶点数和边数：\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);
//	for (i = 0; i < G->numVertexes; i++) {
//		printf("请输入第%d个顶点信息：", i + 1);
//		char ch = getchar();
//		scanf_s("%c", &G->adjList[i].data, 1);
//		G->adjList[i].firstedge = NULL;
//	}
//
//	for (k = 0; k < G->numEdges; ++k) {
//		printf("请输入边<vi, vj> 下标i，下标j以及权重：");
//		scanf_s("%d%d%d", &i, &j, &v);
//		EdgeNode* p = G->adjList[i].firstedge;
//		while (p != NULL) {
//			p = p->next;
//		}
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		if (!e) {
//			printf("Failed！！！\n");
//			exit(-1);
//		}
//		
//		e->adjvex = j;
//		e->next = p;
//		p = e;
//	}
//
//}
//void TraverseALGraph(GraphAdjList G) {
//	int i, j, k;
//	printf("display the information of the vertexes:\n");
//	for (i = 0; i < G.numVertexes; i++) {
//		printf("%c\t", G.adjList[i].data);
//	}
//}
//
//// 邻接表的深度优先递归算法
//void DFS(GraphAdjList* GL, int i) {
//	EdgeNode* p;
//	visited[i] = 1;
//	printf("%c\t", GL->adjList[i].data);
//	p = GL->adjList[i].firstedge;
//	while (p) {
//		if (!visited[p->adjvex])
//			DFS(GL, p->adjvex);
//		p = p->next;
//	}
//}
//
//// 邻接表的遍历操作
//void DFSTraverse(GraphAdjList* GL) {
//	int i;
//	for (i = 0; i < GL->numVertexes; i++) {
//		visited[i] = 0;
//	}
//	for (i = 0; i < GL->numVertexes; i++) {
//		if (!visited[i]) {
//			DFS(GL, i);
//		}
//	}
//}
//
//
//int main() {
//	GraphAdjList G;
//	CreateGraphAdjListTail(&G);
//	DFSTraverse(&G);
//	return 0;
//}
//#include <stdio.h>
//#include <malloc.h>
//
//void f(int** a) {
//	**a = 5;
//}
//
//int main() {
//	int a = 10;
//	int* b = &a;
//	f(&b);
//	printf("%d\n", a);
//	return 0;
//}
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//typedef struct Node {
//	int data;
//	struct Node* next;
//}Node, *LinkList;
//
//// Node*
//
//void CreateLinkListHead(LinkList* L) {
//	int i, n, e;
//	LinkList newNode;
//	*L = (LinkList)malloc(sizeof(Node));
//	printf("%p\n", *L);
//
//	if (!*L) {
//		printf("申请内存空间失败！！！\n");
//		exit(-1);
//	}
//	(*L)->next = NULL;
//
//	printf("请输入创建结点个数：");
//	scanf_s("%d", &n);
//	for (i = 0; i < n; i++) {
//		printf("请输入第%d个结点的值：", i + 1);
//		scanf_s("%d", &e);
//		newNode = (LinkList)malloc(sizeof(Node));
//		if (!newNode) {
//			printf("申请内存空间失败！！！\n");
//			exit(-1);
//		}
//		newNode->data = e;
//		newNode->next = (*L)->next;
//		(*L)->next = newNode;
//	}
//}
//
//void TraverseLinkList(Node L) {
//	printf("%p\n", &L);
//	if (!L.next) {
//		printf("链表为空！！！");
//		return;
//	}
//	LinkList p = L.next;
//	while (p) {
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	printf("\n");
//	return;
//}
//
//int main01() {
//	LinkList L = NULL;
//	CreateLinkListHead(&L);
//	TraverseLinkList(*L);
//	return 0;
//}
/*2023/4/25之前*/
//#include<stdio.h>
//
//typedef char VertexType;
//#define MAX 20
//
//typedef struct {
//	VertexType a[MAX];
//}GM;
//
//void Create(GM* G) {
//	int n;
//	scanf_s("%d", &n);
//	for (int i = 0; i < n; i++) {
//		char c = getchar();
//		scanf_s("%c", & G->a[i], 1);
//		
//		printf("%c\n", G->a[i]);
//	}
//}
//
//int main() {
//	GM g;
//	Create(&g);
//	return 0;
//}

/*倒置练习*/
/*方法1*/
//#include<stdio.h>
//int main() {
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int i, n = 5, t;
//	for (i = 0; i < n / 2; i++)
//		t = a[i], a[i] = a[n - i - 1], a[n - i - 1] = t;
//	for (i = 0; i < n; i++)
//		printf("%d\t", a[i]);
//	return 0;
//}
/*方法2*/
//#include<stdio.h>
//int main() {
//	int a[6] = { 1, 2, 3, 4, 5, 6 };
//	int i = 0, j = 5, t;
//	while (i <= j) {
//		t = a[i];
//		a[i] = a[j];
//		a[j] = t;
//		i++;
//		j--;
//	}
//	for (i = 0; i < 5; i++)
//		printf("%d\t", a[i]);
//	return 0;
//}

/*Dereferencing NULL pointer <name> */
//#include <stdio.h>
//#include <malloc.h>
//
////* This following code generates this warning. */
//void f()
//{
//	char* p = (char*)malloc(10);
//	*p = '\0';
//
//	// code ...
//	free(p);
//}
//
////* To correct this warning, examine the pointer 
//	for a null value as shown the following code: */
//void f2()
//{
//	char* p = (char*)malloc(10);
//
//	if (p) {
//		*p = '\0';
//		// code...
//		free(p);
//	}
//}
//
//int main() {
//	f();
//	f2();
//	return 0;
//}


