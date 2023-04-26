/*Adjacency List*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define MAX_VEX 10
int visited[MAX_VEX];

typedef int EdgeType;
typedef char VertexType;

/*�߱���*/
typedef struct EdgeNode {
	int adjvex;
	EdgeType weight;
	struct EdgeNode* next;
}EdgeNode;

typedef struct VertexNode {
	VertexType data;
	EdgeNode* firstedge;	// �߱�ͷ���
}VertexNode, AdjList[MAX_VEX];

typedef struct GraphAdjList {
	AdjList adjList;
	int numVertexes, numEdges;
}GraphAdjList;

void CreateGraphAdjList(GraphAdjList* G) {
	int i, j, k, v;
	EdgeNode* e;

	printf("�����붥�����ͱ�����\n");
	scanf_s("%d%d", &G->numVertexes, &G->numEdges);

	for (i = 0; i < G->numVertexes; i++) {
		printf("�������%d��������Ϣ��", i + 1);
		char ch = getchar();
		scanf_s("%c", &G->adjList[i].data, 1);
		G->adjList[i].firstedge = NULL;
	}

	for (k = 0; k < G->numEdges; k++) {
		printf("�������<vi, vj>���±�i���±�j�Լ�Ȩֵ��\n");
		scanf_s("%d%d%d", &i, &j, &v);

		EdgeNode* p;

		p = G->adjList[i].firstedge;
		while (p) {
			p = p->next;
		}
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		if (!e) {
			printf("Failed������\n");
			exit(-1);
		}
		e->adjvex = j;
		e->weight = v;
		e->next = p;
		p = e;

		p = G->adjList[j].firstedge;
		while (p) {
			p = p->next;
		}
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		if (!e) {
			printf("Failed������\n");
			exit(-1);
		}
		e->adjvex = i;
		e->weight = v;
		e->next = p;
		p = e;
	}
}

void TraverseVertexes(GraphAdjList* G) {
	int i;
	for (i = 0; i < G->numVertexes; i++) {
		printf("%c\t", G->adjList[i].data);
	}
	printf("\n");
}

void dfs(GraphAdjList* G, int i) {
	EdgeNode* p;
	visited[i] = 1;
	printf("%c\t", G->adjList[i].data);
	p = G->adjList[i].firstedge;
	while (p) {
		if (!visited[p->adjvex]) {
			dfs(G, p->adjvex);
		}
		p = p->next;
	}
}

void TraverseDfs(GraphAdjList* G) {
	int i;
	for (i = 0; i < G->numVertexes; i++) {
		visited[i] = 0;
	}

	for (i = 0; i < G->numVertexes; i++) {
		if (!visited[i]) {
			dfs(G, i);
		}
	}
}

int main() {
	GraphAdjList G;
	CreateGraphAdjList(&G);
	TraverseDfs(&G);
	return 0;
}
// ��ɢ�洢������
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
//void InitList(LinkList* L); // ������������
//bool ListAdd(LinkList L, int e);	// ��Ӻ�������
//bool ListEmpty(LinkList L);	// �Ƿ�Ϊ�պ�������
//bool ListInsert(LinkList L, int pos, int e); // ���뺯������
//bool ListDelete(LinkList L, int pos, int* element);	// ɾ����������
//void TraverseList(LinkList L);	//������������
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
//	printf("�����봴���б�ĸ�����");
//	scanf_s("%d", &n);
//	
//	for (i = 0; i < n; i++) {
//		printf("�������%d������ֵ��", i + 1);
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
//		printf("����Ϊ�գ�����ʧ�ܣ�����");
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
//		printf("����������\n");
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
//	int i, n, val;	// n:������	val�����ֵ
//	pNode pTail, pHead;
//
//	pHead = (pNode)malloc(sizeof(Node));
//	if (!pHead) {
//		printf("�����ڴ�ռ�ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	pHead->pNext = NULL;
//	pTail = pHead;
//
//	printf("������Ҫ�����Ľ�������");
//	scanf_s("%d", &n);
//	for (i = 0; i < n; ++i) {
//		printf("�������%d������ֵ��", i + 1);
//		scanf_s("%d", &val);
//		pNode pNew = (pNode)malloc(sizeof(Node));
//		if (!pNew) {
//			printf("�����ڴ�ռ�ʧ�ܣ�����\n");
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
//		printf("����Ϊ�գ�����\n");
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
//		printf("��̬�ڴ����ʧ�ܣ���\n");
//		exit(-1);
//	}
//	pNew->data = val;
//	pNew->pNext = p->pNext;
//	p->pNext = pNew;
//	return true;
//}

/*˳��洢�����飩*/
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef struct Arr {
//	int* pBase;	/*������Ԫ�ص�ַ*/
//	int len;	/*������󳤶�*/
//	int cnt;	/*���鵱ǰ����*/
//}Arr, *pArr;
//
//void init_arr(pArr p, int len);				/*��ʼ����������*/
//bool append_arr(pArr p, int val);			/*׷�Ӻ�������*/
//bool insert_arr(pArr p, int pos, int e);	/*���뺯������*/
//bool delete_arr(pArr p, int pos, int* e);	/*ɾ����������*/
//bool is_empty(pArr p);						/*�Ƿ�Ϊ�պ�������*/
//bool is_full(pArr p);						/*�Ƿ�Ϊ����������*/
//void show_arr(pArr p);						/*������������*/
//void inversion_arr(pArr p);					/*���ú�������*/
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
//		printf("ɾ��λ��%dԪ��%d�ɹ�������\n", 2, e);
//	}
//	else {
//		printf("ɾ��λ��%dԪ��ʧ�ܣ�����\n", 2);
//	}
//	show_arr(&arr);
//	if (delete_arr(&arr, 1, &e)) {
//		printf("ɾ��λ��%dԪ��%d�ɹ�������\n", 1, e);
//	}
//	else {
//		printf("ɾ��λ��%dԪ��ʧ�ܣ�����\n", 1);
//	}
//	show_arr(&arr);
//	return 0;
//}
//
//void init_arr(pArr p, int len) {
//	p->pBase = (pArr)malloc(sizeof(int) * len);
//	if (!p->pBase) {
//		printf("�����ڴ�ռ�ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	p->len = len;
//	p->cnt = 0;
//}
//
//bool append_arr(pArr p, int val) {
//	if (is_full(p)) {
//		printf("������������������%dʧ��\n", val);
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
//		printf("����Ϊ�գ�����\n");
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
//		printf("��������������Ԫ��%dʧ�ܣ�����\n", e);
//		return false;
//	}
//	// �жϲ���λ���Ƿ���ȷ
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
//		printf("����Ϊ�գ�ɾ��λ��%dֵʧ�ܣ�����\n", pos);
//		return false;
//	}
//	// ɾ��λ���ж�
//	if (pos < 1 && pos > p->cnt) {
//		return false;
//	}
//	// ȡ��ɾ��Ԫ��
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
//// �߱���
//typedef struct EdgeNode {
//	int adjvex;
//	struct EdgeNode* next;
//}EdgeNode;
//
//// ������
//typedef struct VertexNode {
//	VertexType data;
//	EdgeNode* firstedge;
//}VertexNode, AdjList[MAX_VEX];
//
//// ͼ
//typedef struct {
//	AdjList adjList;
//	int numVertexes, numEdges;
//}GraphAdjList;
//
//void CreateGraphAdjList(GraphAdjList* G) {
//	int i, j, k, v;
//	EdgeNode* e;
//	printf("�����붥�����ͱ�����\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);
//	for (i = 0; i < G->numVertexes; i++) {
//		printf("�������%d��������Ϣ��", i + 1);
//		char ch = getchar();
//		scanf_s("%c", &G->adjList[i].data, 1);
//		G->adjList[i].firstedge = NULL;
//	}
//
//	for (k = 0; k < G->numEdges; ++k) {
//		printf("�������<vi, vj> �±�i���±�j�Լ�Ȩ�أ�");
//		scanf_s("%d%d%d", &i, &j, &v);
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		if (!e) {
//			printf("Failed������\n");
//			exit(-1);
//		}
//		e->adjvex = j;
//		e->next = G->adjList[i].firstedge;
//		G->adjList[i].firstedge = e;
//
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		if (!e) {
//			printf("Failed������\n");
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
//	printf("�����붥�����ͱ�����\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);
//	for (i = 0; i < G->numVertexes; i++) {
//		printf("�������%d��������Ϣ��", i + 1);
//		char ch = getchar();
//		scanf_s("%c", &G->adjList[i].data, 1);
//		G->adjList[i].firstedge = NULL;
//	}
//
//	for (k = 0; k < G->numEdges; ++k) {
//		printf("�������<vi, vj> �±�i���±�j�Լ�Ȩ�أ�");
//		scanf_s("%d%d%d", &i, &j, &v);
//		EdgeNode* p = G->adjList[i].firstedge;
//		while (p != NULL) {
//			p = p->next;
//		}
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		if (!e) {
//			printf("Failed������\n");
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
//// �ڽӱ��������ȵݹ��㷨
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
//// �ڽӱ�ı�������
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
//		printf("�����ڴ�ռ�ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	(*L)->next = NULL;
//
//	printf("�����봴����������");
//	scanf_s("%d", &n);
//	for (i = 0; i < n; i++) {
//		printf("�������%d������ֵ��", i + 1);
//		scanf_s("%d", &e);
//		newNode = (LinkList)malloc(sizeof(Node));
//		if (!newNode) {
//			printf("�����ڴ�ռ�ʧ�ܣ�����\n");
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
//		printf("����Ϊ�գ�����");
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
/*2023/4/25֮ǰ*/
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

/*������ϰ*/
/*����1*/
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
/*����2*/
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


