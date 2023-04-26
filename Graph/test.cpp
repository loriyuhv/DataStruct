


//#include<stdio.h>
//
//int main() {
//	char a;
//	a = 65;
//	printf("%c\n", a);
//	return 0;
//}
//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//
//
//
//typedef char VertexType;
//typedef int EdgeType;
//#define MAXVEX 100
//int visited[MAXVEX];
//
//typedef struct EdgeNode {	/* �߱��� */
//	int adjvex;				/* �ڽӵ��򣬴洢�ö����Ӧ���±� */
//	EdgeType weight;		/* ���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ */
//	struct EdgeNode* next;	/* ����ָ����һ���ڽӵ� */
//}EdgeNode;
//
//typedef struct VertexNode {	/* ������� */
//	VertexType data;		/* �����򣬴洢������Ϣ */
//	EdgeNode* firstedge;	/* �߱�ͷָ�� */
//}VertexNode, AdjList[MAXVEX];
//
//typedef struct {
//	AdjList adjList;
//	int numVertexes, numEdges;	/* ͼ�е�ǰ�������ͱ��� */
//}GraphAdjList;
//
//
///* ����ͼ���ڽӱ�ṹ */
//void CreateALGraph(GraphAdjList* G) {
//	int i, j, k, v;
//	EdgeNode* e;
//
//	printf("���붥�����ͱ�����\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);
//
//	for (i = 0; i < G->numVertexes; ++i) {
//		printf("�����%d��������Ϣ��", i + 1);
//		char ch = getchar();
//		scanf_s("%c", &G->adjList[i].data, 1);		/* ���붥����Ϣ */
//		G->adjList[i].firstedge = NULL;	/* ���߱���Ϊ�ձ� */
//	}
//
//	for (k = 0; k < G->numEdges; k++) {
//		printf("����ߣ�vi,vj���ϵĶ�����ţ�\n");
//		scanf_s("%d%d%d", &i, &j, &v); /* ����ߣ�vi, vj���ϵĶ������ */
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));	/*���ڴ�����ռ�*/
//		if (!e) {
//			printf("�ڴ�����ʧ�ܣ�����\n");
//			exit(-1);
//		}
//		/* ���ɱ߱��� */
//		e->adjvex = j;	/*�ڽ����Ϊj */
//		e->weight = v;
//		e->next = G->adjList[i].firstedge;	/* ��eָ��ָ��ǰ����ָ��Ľ�� */
//		G->adjList[i].firstedge = e;	/* ����ǰ�����ָ��ָ��e */
//
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));	/*���ڴ�����ռ䣬 ���ɱ߱��� */
//		if (!e) {
//			printf("�ڴ�����ʧ�ܣ�����\n");
//			exit(-1);
//		}
//		e->adjvex = i;	/* �ڽ����Ϊi */
//		e->weight = v;
//		e->next = G->adjList[j].firstedge;	/* ��e ָ��ָ��ǰ����ָ��Ľ�� */
//		G->adjList[j].firstedge = e;	/* ����ǰ�����ָ��ָ��e */
//	}
//}
//
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
//int main() {
//	GraphAdjList G;
//	CreateALGraph(&G);
//	DFSTraverse(&G);
//	return 0;
//}

//#include<stdio.h>
//# define MAX_VERTEX_NUM 20
//
//typedef char VertexType;
//
//typedef struct ArcNode {
//	int adjvex;	// �û���ָ��Ķ����λ��
//	struct ArcNode* nextarc;	// ָ����һ������ָ��
//	// InfoType* info;	//�û������Ϣ��ָ��
//}ArcNode;
//
//typedef struct VNode {
//	VertexType data;	// ������Ϣ
//	ArcNode* firstarc;	// ָ���һ�������ö���Ļ���ָ��
//}VNode, AdjList[MAX_VERTEX_NUM];
//
//typedef struct {
//	AdjList vertices;
//	int vexnum, arcnum;	// ͼ�ĵ�ǰ�������ͻ���
//	int kind;			// ͼ�������־
//}ALGraph;
//void CreateALGraph(GraphAdjList* G) {
//	int i, j, k;
//	EdgeNode* e;
//	printf("���붥�����ͱ�����\n");
//	scanf("%d,%d", &G->numVertexes, &G->numEdges);
//	for (i = 0; i < G->numVertexes; i++) {
//		scanf(&G->adjList[i].data);		/* ���붥����Ϣ */
//		G->adjList[i].firstedge = NULL;	/* ���߱���Ϊ�ձ� */
//	}
//
//	for (k = 0; k < G->numEdges; k++) {
//		printf("����ߣ�vi,vj���ϵĶ�����ţ�\n");
//		scanf("%d,%d", &i, &j); /* ����ߣ�vi, vj���ϵĶ������ */
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));	/*���ڴ�����ռ�*/
//		/* ���ɱ߱��� */
//		e->adjvex = j;	/*�ڽ����Ϊj */
//		e->next = G->adjList[i].firstedge;	/* ��eָ��ָ��ǰ����ָ��Ľ�� */
//		G->adjList[i].firstedge = e;	/* ����ǰ�����ָ��ָ��e */
//
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));	/*���ڴ�����ռ䣬 ���ɱ߱��� */
//		e->adjvex = i;	/* �ڽ����Ϊi */
//		e->next = G->adjList[j].firstedge;	/* ��e ָ��ָ��ǰ����ָ��Ľ�� */
//		G->adjList[j].firstedge = e;	/* ����ǰ�����ָ��ָ��e */
//	}
//}
//
//int main() {
//
//	return 0;
//}

//#include<stdio.h>
//
//#define MAX 10
//#define INFINITY 9999
//
//typedef struct {
//	char vexs[MAX];
//	int arc[MAX][MAX];
//	int numVertexes, numEdges;
//}MGraph;
//
//void CreateMGraph(MGraph* G) {
//	int i, j, k, e;
//	printf("�����붥�����ͱ�����\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);
//
//	for (i = 0; i < G->numVertexes; i++) {
//		printf("�������%d��������Ϣ��", i + 1);
//		char ch = getchar();
//		scanf_s("%c", &G->vexs[i], 1);
//	}
//
//	for (i = 0; i < G->numVertexes; i++) {
//		for (j = 0; j < G->numVertexes; j++) {
//			if (i == j) {
//				G->arc[i][j] = 0;
//				continue;
//			}
//			G->arc[i][j] = INFINITY;
//		}
//			
//	}
//
//	for (k = 0; k < G->numEdges; k++) {
//		scanf_s("%d%d%d", &i, &j, &e);
//		G->arc[i][j] = e;
//		G->arc[j][i] = G->arc[i][j];
//	}
//}
//
//int main() {
//	MGraph G;
//	CreateMGraph(&G);
//	int i, j;
//	for (i = 0; i < G.numVertexes; i++) {
//		for (j = 0; j < G.numVertexes; j++) {
//			printf("%4d\t", G.arc[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

/*2023/4/25��ϰ*/
//#include<iostream>
//
//#define MAX 10
//#define INFINITY 9999
//
//typedef struct {
//	char vexs[MAX];
//	int arc[MAX][MAX];
//	int numVertexes, numEdges;
//}MGraph;
//
//void CreateMGraph(MGraph* G) {
//	int i, j, k, w;
//	printf("�����붥�����ͱ�����\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);
//
//	for (i = 0; i < G->numVertexes; i++) {
//		printf("�������%d��������Ϣ��", i + 1);
//		char cha = getchar();
//		scanf_s("%c", &G->vexs[i], 1);
//	}
//
//	for (i = 0; i < G->numVertexes; i++) {
//		for (j = 0; j < G->numVertexes; j++) {
//			G->arc[i][j] = INFINITY;
//		}
//	}
//
//	for (k = 0; k < G->numEdges; k++) {
//		printf("����ߣ�vi, vj)�±�i���±�j�Լ�Ȩw��ֵ��\n");
//		scanf_s("%d%d%d", &i, &j, &w);
//		G->arc[i][j] = w;
//	}
//
//	for (i = 0; i < G->numVertexes; i++)
//		printf("%c\t", G->vexs[i]);
//	printf("\n");
//	for (i = 0; i < G->numVertexes; i++) {
//		for (j = 0; j < G->numVertexes; j++)
//			printf("%4d\t", G->arc[i][j]);
//		printf("\n");
//	}
//}
//
//void DFS(MGraph G, int i, int visited[]) {
//	int j;
//	visited[i] = 1;
//	printf("%c\t", G.vexs[i]);
//
//	for (j = 0; j < G.numVertexes; j++) {
//		if (G.arc[i][j] != INFINITY && !visited[j]) {
//			DFS(G, j, visited);
//		}
//	}
//	return;
//}
//
//void TraverseMGraph(MGraph G, int visited[]) {
//	int i;
//
//	for (i = 0; i < MAX; i++) {
//		visited[i] = 0;
//	}
//
//	for (i = 0; i < G.numVertexes; i++) {
//		if (!visited[i]) {
//			DFS(G, i, visited);
//		}
//	}
//}
//
//int main() {
//	MGraph G;
//	int visited[MAX];
//	CreateMGraph(&G);
//	TraverseMGraph(G, visited);
//	return 0;
//}

/*�ڽӾ���Ĵ���*/
//#include<iostream>
//
//#define MAX 10
//#define INFINITY 9999
//
//typedef struct {
//	char vexs[MAX];
//	int arc[MAX][MAX];
//	int numVertexes, numEdges;
//}MGraph;
//
//void CreateMGraph(MGraph* G) {
//	int i, j, k, w;
//	printf("�����붥�����ͱ�����\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);
//
//	for (i = 0; i < G->numVertexes; i++) {
//		printf("�������%d��������Ϣ��", i + 1);
//		char cha = getchar();
//		scanf_s("%c", &G->vexs[i], 1);
//	}
//
//	for (i = 0; i < G->numVertexes; i++) {
//		for (j = 0; j < G->numVertexes; j++) {
//			G->arc[i][j] = INFINITY;
//		}
//	}
//
//	for (k = 0; k < G->numEdges; k++) {
//		printf("����ߣ�vi, vj)�±�i���±�j�Լ�Ȩw��ֵ��\n");
//		scanf_s("%d%d%d", &i, &j, &w);
//		G->arc[i][j] = w;
//	}
//
//	for (i = 0; i < G->numVertexes; i++)
//		printf("%c\t", G->vexs[i]);
//	printf("\n");
//	for (i = 0; i < G->numVertexes; i++) {
//		for (j = 0; j < G->numVertexes; j++)
//			printf("%4d\t", G->arc[i][j]);
//		printf("\n");
//	}		
//}
//
//void DFS(MGraph G, int i, int visited[]) {
//	int j;
//	visited[i] = 1;
//	printf("%c\t", G.vexs[i]);
//
//	for (j = 0; j < G.numVertexes; j++) {
//		if (G.arc[i][j] != INFINITY && !visited[j]) {
//			DFS(G, j, visited);
//		}
//	}
//	return;
//}
//
//void TraverseMGraph(MGraph G, int visited[]) {
//	int i;
//	
//	for (i = 0; i < MAX; i++) {
//		visited[i] = 0;
//	}
//
//	for (i = 0; i < G.numVertexes; i++) {
//		if (!visited[i]) {
//			DFS(G, i, visited);
//		}
//	}
//}
//
//int main() {
//	MGraph G;
//	int visited[MAX];
//	CreateMGraph(&G);
//	TraverseMGraph(G, visited);
//	return 0;
//}

/*��ϰ*/
//#include<stdio.h>
//
//#define MAX 10
//#define INFINITY 9999
//
//typedef struct {
//	char vexs[MAX];
//	int arc[MAX][MAX];
//	int numVertexes, numEdges;
//}MGraph;
//
//void CreateMGraph(MGraph* G) {
//	int i, j, k, w;
//	printf("���봴���Ķ������ͱ�����\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);
//
//	for (i = 0; i < G->numVertexes; i++) {
//		char cha = getchar();
//		printf("�������%d�������ֵ��", i+1);
//		scanf_s("%c", &G->vexs[i], 1);
//	}
//
//	for (i = 0; i < G->numVertexes; i++) {
//		for (j = 0; j < G->numVertexes; j++) {
//			G->arc[i][j] = INFINITY;
//		}
//	}
//
//	for (k = 0; k < G->numEdges; k++) {
//		printf("������ߣ�vi, vj)�±�i���±�j��ֵ��\n");
//		scanf_s("%d%d%d", &i, &j, &w);
//		G->arc[i][j] = w;
//		G->arc[j][i] = G->arc[i][j];
//	}
//
//	for (i = 0; i < G->numVertexes; i++) {
//		printf("%c\t", G->vexs[i]);
//	}
//	printf("\n");
//	for (i = 0; i < G->numVertexes; i++) {
//		for (j = 0; j < G->numVertexes; j++)
//			printf("%4d\t", G->arc[i][j]);
//		printf("\n");
//	}
//}
//
//void DFS(MGraph G, int i, int visited[]) {
//	int j;
//	visited[i] = 1;
//	printf("%c\t", G.vexs[i]);
//	for (j = 0; j < G.numVertexes; j++) {
//		if (G.arc[i][j] != INFINITY && !visited[i]) {
//			DFS(G, j, visited);
//		}
//	}
//
//}
//
//void DFSTraverse(MGraph G, int visited[]) {
//	int i;
//	for (i = 0; i < MAX; i++) {
//		visited[i] = 0;
//	}
//
//	for (i = 0; i < G.numVertexes; i++) {
//		if (!visited[i]) {
//			DFS(G, i, visited);
//		}
//	}
//}
//
//int main() {
//	MGraph G;
//	int visited[MAX];
//	CreateMGraph(&G);
//	DFSTraverse(G, visited);
//
//	return 0;
//}

/*�ڽӾ��󴴽�*/
//#include<iostream>
//using namespace std;
//
//#define MAX 10
//#define INFINITY 9999
//
//typedef struct {
//	char vexs[MAX];
//	int arc[MAX][MAX];
//	int numVertexes, numEdges;
//}MGraph;
//
//int visited[MAX];	//���ʱ�־������
//
//// �ڽӾ���������ȵݹ��㷨
//void DFS(MGraph G, int i) {
//	int j;
//	visited[i] = 1;
//	
//	printf("%c\t", G.vexs[i]);
//	for (j = 0; j < G.numVertexes; j++) {
//		if (G.arc[i][j] != INFINITY && !visited[j])
//			DFS(G, j);
//	}
//}
//
//// �ڽӾ�����ȱ�������
//void DFSTraverse(MGraph G) {
//	int i;
//	for (i = 0; i < G.numVertexes; i++) {
//		visited[i] = 0;
//	}
//	/*for (i = 0; i < G.numVertexes; i++) {
//		printf("%d\t", visited[i]);
//	}*/
//
//	for (i = 0; i < G.numVertexes; i++) {
//		if (!visited[i])
//			DFS(G, i);
//	}
//}
//
//void CreateMGraph(MGraph* G) {
//	int i, j, k, w;
//	// ���붥�����ͱ���
//	printf("�����붥�����ͱ�����\n");
//	scanf_s("%d,%d", &G->numVertexes, &G->numEdges);
//
//	// ���붥�����Ϣ
//	for (i = 0; i < G->numVertexes; i++) {
//		char c = getchar();
//		scanf_s("%c", &G->vexs[i], 1);
//	}
//	
//	// ��ʼ���ڽӾ���
//	for (i = 0; i < G->numVertexes; i++) {
//		for (j = 0; j < G->numVertexes; j++) {
//			G->arc[i][j] = INFINITY;
//		}
//	}
//
//	for (k = 0; k < G->numEdges; k++) {
//		printf("�����<vi,vj>���±�i,�±�j��Ȩ��w��\n");
//		scanf_s("%d,%d,%d", &i, &j, &w);
//		G->arc[i][j] = w;
//	}
//}
//
//int main() {
//	MGraph G;
//	CreateMGraph(&G);
//	DFSTraverse(G);
//	return 0;
//}