


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
//typedef struct EdgeNode {	/* 边表结点 */
//	int adjvex;				/* 邻接点域，存储该顶点对应的下标 */
//	EdgeType weight;		/* 用于存储权值，对于非网图可以不需要 */
//	struct EdgeNode* next;	/* 链域，指向下一个邻接点 */
//}EdgeNode;
//
//typedef struct VertexNode {	/* 顶点表结点 */
//	VertexType data;		/* 顶点域，存储顶点信息 */
//	EdgeNode* firstedge;	/* 边表头指针 */
//}VertexNode, AdjList[MAXVEX];
//
//typedef struct {
//	AdjList adjList;
//	int numVertexes, numEdges;	/* 图中当前顶点数和边数 */
//}GraphAdjList;
//
//
///* 建立图的邻接表结构 */
//void CreateALGraph(GraphAdjList* G) {
//	int i, j, k, v;
//	EdgeNode* e;
//
//	printf("输入顶点数和边数：\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);
//
//	for (i = 0; i < G->numVertexes; ++i) {
//		printf("输入第%d个顶点信息：", i + 1);
//		char ch = getchar();
//		scanf_s("%c", &G->adjList[i].data, 1);		/* 输入顶点信息 */
//		G->adjList[i].firstedge = NULL;	/* 将边表置为空表 */
//	}
//
//	for (k = 0; k < G->numEdges; k++) {
//		printf("输入边（vi,vj）上的顶点序号：\n");
//		scanf_s("%d%d%d", &i, &j, &v); /* 输入边（vi, vj）上的顶点序号 */
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));	/*向内存申请空间*/
//		if (!e) {
//			printf("内存申请失败！！！\n");
//			exit(-1);
//		}
//		/* 生成边表结点 */
//		e->adjvex = j;	/*邻接序号为j */
//		e->weight = v;
//		e->next = G->adjList[i].firstedge;	/* 将e指针指向当前顶点指向的结点 */
//		G->adjList[i].firstedge = e;	/* 将当前顶点的指针指向e */
//
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));	/*向内存申请空间， 生成边表结点 */
//		if (!e) {
//			printf("内存申请失败！！！\n");
//			exit(-1);
//		}
//		e->adjvex = i;	/* 邻接序号为i */
//		e->weight = v;
//		e->next = G->adjList[j].firstedge;	/* 将e 指针指向当前顶点指向的结点 */
//		G->adjList[j].firstedge = e;	/* 将当前顶点的指针指向e */
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
//	int adjvex;	// 该弧所指向的顶点的位置
//	struct ArcNode* nextarc;	// 指向下一条弧的指针
//	// InfoType* info;	//该弧相关信息的指针
//}ArcNode;
//
//typedef struct VNode {
//	VertexType data;	// 顶点信息
//	ArcNode* firstarc;	// 指向第一条依附该顶点的弧的指针
//}VNode, AdjList[MAX_VERTEX_NUM];
//
//typedef struct {
//	AdjList vertices;
//	int vexnum, arcnum;	// 图的当前顶点数和弧数
//	int kind;			// 图的种类标志
//}ALGraph;
//void CreateALGraph(GraphAdjList* G) {
//	int i, j, k;
//	EdgeNode* e;
//	printf("输入顶点数和边数：\n");
//	scanf("%d,%d", &G->numVertexes, &G->numEdges);
//	for (i = 0; i < G->numVertexes; i++) {
//		scanf(&G->adjList[i].data);		/* 输入顶点信息 */
//		G->adjList[i].firstedge = NULL;	/* 将边表置为空表 */
//	}
//
//	for (k = 0; k < G->numEdges; k++) {
//		printf("输入边（vi,vj）上的顶点序号：\n");
//		scanf("%d,%d", &i, &j); /* 输入边（vi, vj）上的顶点序号 */
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));	/*向内存申请空间*/
//		/* 生成边表结点 */
//		e->adjvex = j;	/*邻接序号为j */
//		e->next = G->adjList[i].firstedge;	/* 将e指针指向当前顶点指向的结点 */
//		G->adjList[i].firstedge = e;	/* 将当前顶点的指针指向e */
//
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));	/*向内存申请空间， 生成边表结点 */
//		e->adjvex = i;	/* 邻接序号为i */
//		e->next = G->adjList[j].firstedge;	/* 将e 指针指向当前顶点指向的结点 */
//		G->adjList[j].firstedge = e;	/* 将当前顶点的指针指向e */
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
//	printf("请输入顶点数和边数：\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);
//
//	for (i = 0; i < G->numVertexes; i++) {
//		printf("请输入第%d个顶点信息：", i + 1);
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

/*2023/4/25练习*/
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
//	printf("请输入顶点数和边数：\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);
//
//	for (i = 0; i < G->numVertexes; i++) {
//		printf("请输入第%d个顶点信息：", i + 1);
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
//		printf("输入边（vi, vj)下标i和下标j以及权w的值：\n");
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

/*邻接矩阵的创建*/
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
//	printf("请输入顶点数和边数：\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);
//
//	for (i = 0; i < G->numVertexes; i++) {
//		printf("请输入第%d个顶点信息：", i + 1);
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
//		printf("输入边（vi, vj)下标i和下标j以及权w的值：\n");
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

/*复习*/
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
//	printf("输入创建的顶点数和边数：\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);
//
//	for (i = 0; i < G->numVertexes; i++) {
//		char cha = getchar();
//		printf("请输入第%d个顶点的值：", i+1);
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
//		printf("请输入边（vi, vj)下标i和下标j的值：\n");
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

/*邻接矩阵创建*/
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
//int visited[MAX];	//访问标志的数组
//
//// 邻接矩阵深度优先递归算法
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
//// 邻接矩阵深度遍历操作
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
//	// 输入顶点数和边数
//	printf("请输入顶点数和边数：\n");
//	scanf_s("%d,%d", &G->numVertexes, &G->numEdges);
//
//	// 输入顶点表信息
//	for (i = 0; i < G->numVertexes; i++) {
//		char c = getchar();
//		scanf_s("%c", &G->vexs[i], 1);
//	}
//	
//	// 初始化邻接矩阵
//	for (i = 0; i < G->numVertexes; i++) {
//		for (j = 0; j < G->numVertexes; j++) {
//			G->arc[i][j] = INFINITY;
//		}
//	}
//
//	for (k = 0; k < G->numEdges; k++) {
//		printf("输入边<vi,vj>的下标i,下标j和权重w：\n");
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