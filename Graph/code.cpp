/*Ajancency List 邻接链表*/
// 把数组与链表相结合的存储方法称为邻接表（Ajancency List)
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
//	cout << "输入顶点数和边数：\n";
//	cin >> G->numVertexes >> G->numEdges;
//	for (i = 0; i < G->numVertexes; ++i) {
//		cin >> G->adjList[i].data;
//		G->adjList[i].firstedge = NULL;
//	}
//
//	for (i = 0; i < G->numEdges; i++) {
//		cout << "输入边（vi,vj）上的下标i，下标j和权w：";
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

/*Ajancency Matrix 邻接矩阵*/
//#include<stdio.h>
//
//typedef char VertexType;			/* 顶点类型 */
//typedef int EdgeType;				/* 边上的权值类型 */
//
//#define MAXVEX 100					/* 最大顶点数 */
//#define INFINITY 65535				/* 用65536代表无穷 */
//
//typedef struct {
//	VertexType vexs[MAXVEX];		/* 顶点表 */
//	EdgeType arc[MAXVEX][MAXVEX];	/* 邻接矩阵，可看作边表 */
//	int numVertexes, numEdges;		/* 图中当前的顶点数和边数 */
//}MGraph;
//
//// 建立无向网图的邻接矩阵表示
//void CreateMGraph(MGraph* G) {
//	int i, j, k, w;
//	printf("输入顶点数和边数：\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);	/* 输入顶点数和边数*/
//
//	for (i = 0; i < G->numVertexes; ++i) {
//		printf("输入第%d个顶点信息：", i + 1);
//		char ch = getchar();
//		scanf_s("%c", &G->vexs[i], 1);	/* 读入顶点信息， 建立顶点表 */
//	}
//
//	for (i = 0; i < G->numVertexes; ++i)
//		for (j = 0; j < G->numVertexes; ++j)
//			G->arc[i][j] = INFINITY;	/* 邻接矩阵初始化 */
//
//	for (k = 0; k < G->numEdges; ++k) {
//		printf("输入边(vi, vj)上的下标i，下标j和权w：\n");
//		scanf_s("%d%d%d", &i, &j, &w);	/* 输入边（vi,vj）上的权w */
//		G->arc[i][j] = w;
//		G->arc[j][i] = G->arc[i][j];	/* 因为是无向图，矩阵对称 */
//	}
//}
//
//int main() {
//	MGraph G;
//	CreateMGraph(&G);
//	return 0;
//}