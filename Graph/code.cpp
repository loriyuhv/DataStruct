/*Ajancency List �ڽ�����*/
// ���������������ϵĴ洢������Ϊ�ڽӱ�Ajancency List)
//#include<stdio.h>
//#include<iostream>
//#include<algorithm>
//#include<stdlib.h>
//using namespace std;
//
//#define MAXN 1005
//
//struct EdgeNode {
//	int adjvex;
//	int w;
//	EdgeNode* next;
//};
//
//typedef struct VertexNode {
//	int data;
//	EdgeNode* firstedge;
//}AdjList[MAXN];
//
//struct MGraph {
//	AdjList adjList;
//	int numVertexes, numEdges;
//};
//
//void CreateMGraph(MGraph* G) {
//	int i, j, w;
//	EdgeNode* e;
//
//	cout << "���붥�����ͱ�����\n";
//	cin >> G->numVertexes >> G->numEdges;
//	for (i = 0; i < G->numVertexes; ++i) {
//		cin >> G->adjList[i].data;
//		G->adjList[i].firstedge = NULL;
//	}
//
//	for (i = 0; i < G->numEdges; i++) {
//		cout << "����ߣ�vi,vj���ϵ��±�i���±�j��Ȩw��";
//		cin >> i >> j >> w;
//
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		if (!e) {
//			exit(-1);
//		}
//		e->adjvex = j;
//		e->w = w;
//		e->next = G->adjList[i].firstedge;
//		G->adjList[i].firstedge = e;
//	}
//	
//
//	
//}
//
//int main01() {
//	MGraph g;
//	
//	return 0;
//}

/*Ajancency Matrix �ڽӾ���*/
//#include<stdio.h>
//
//typedef char VertexType;			/* �������� */
//typedef int EdgeType;				/* ���ϵ�Ȩֵ���� */
//
//#define MAXVEX 100					/* ��󶥵��� */
//#define INFINITY 65535				/* ��65536�������� */
//
//typedef struct {
//	VertexType vexs[MAXVEX];		/* ����� */
//	EdgeType arc[MAXVEX][MAXVEX];	/* �ڽӾ��󣬿ɿ����߱� */
//	int numVertexes, numEdges;		/* ͼ�е�ǰ�Ķ������ͱ��� */
//}MGraph;
//
//// ����������ͼ���ڽӾ����ʾ
//void CreateMGraph(MGraph* G) {
//	int i, j, k, w;
//	printf("���붥�����ͱ�����\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);	/* ���붥�����ͱ���*/
//
//	for (i = 0; i < G->numVertexes; ++i) {
//		printf("�����%d��������Ϣ��", i + 1);
//		char ch = getchar();
//		scanf_s("%c", &G->vexs[i], 1);	/* ���붥����Ϣ�� ��������� */
//	}
//
//	for (i = 0; i < G->numVertexes; ++i)
//		for (j = 0; j < G->numVertexes; ++j)
//			G->arc[i][j] = INFINITY;	/* �ڽӾ����ʼ�� */
//
//	for (k = 0; k < G->numEdges; ++k) {
//		printf("�����(vi, vj)�ϵ��±�i���±�j��Ȩw��\n");
//		scanf_s("%d%d%d", &i, &j, &w);	/* ����ߣ�vi,vj���ϵ�Ȩw */
//		G->arc[i][j] = w;
//		G->arc[j][i] = G->arc[i][j];	/* ��Ϊ������ͼ������Գ� */
//	}
//}
//
//int main() {
//	MGraph G;
//	CreateMGraph(&G);
//	return 0;
//}