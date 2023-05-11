/*2023/5/11*/
/*邻接表复习*/
#include<iostream>
//#include<stdlib.h>
using namespace std;

#define MAXVEX 10

typedef char VertexType;
typedef int EdgeType;

//// 边表结点
//typedef struct EdgeNode {
//	int adjvex;		/* 邻接点域，存储该顶点对应的下标 */
//	EdgeType weight;	/* 用于存储权值，对于非网图可以不需要 */
//	struct EdgeNode* next;	/* 链域， 指向下一个邻接点 */
//}EdgeNode;
//
//// 顶点表结点
//typedef struct VertexNode {
//	VertexType data;	/* 顶点域，存储顶点信息 */
//	EdgeNode* firstedge;	/* 边表头指针 */
//}VertexNode, AdjList[MAXVEX];
//
//typedef struct {
//	AdjList adjList;	
//	int numVertexes, numEdges;	/* 图中当前顶点数和边数*/
//}GraphAdjList;

// 边表结点
typedef struct EdgeNode {
	int adjvex;			/* 邻接点域，存储该顶点对应的下标 */
	EdgeType weight;	/* 边上的权值，对于非网图可以不需要 */
	struct EdgeNode* next;	/* 链域，指向下一个邻接点 */
}EdgeNode;

// 顶点表结点
typedef struct VertexNode {
	VertexType data;	/* 顶点域，存储顶点信息 */
	EdgeNode* firstedge; /* 边表头指针 */
}VertexNode, AdjList[MAXVEX];

typedef struct {
	AdjList adjList;
	int numVertexes, numEdges;
}GraphAdjList;

// 建立图的邻接表结构(头插法）
void CreateALGraphHead(GraphAdjList* G) {
	int i, j, k, w;
	EdgeNode* e;

	cout << "输入顶点数和边数：\n";
	cin >> G->numVertexes >> G->numEdges;

	// 读入顶点信息，建立顶点表
	for (i = 0; i < G->numVertexes; ++i) {
		cin >> G->adjList[i].data;		/* 输入顶点信息 */
		G->adjList[i].firstedge = NULL;	/* 将边表置为空表 */
	}

	// 建立边表
	for (k = 0; k < G->numEdges; ++k) {
		cout << "输入边（vi,vj）上的顶点序号：\n";
		cin >> i >> j;

		e = (EdgeNode*)malloc(sizeof(EdgeNode));	/* 向内存申请空间，生成边表结点 */
		if (!e)
			exit(-1);
		e->adjvex = j;		/* 邻接序号为j */
		e->next = G->adjList[i].firstedge;	/* 将e指针指向当前顶点指向的结点*/
		G->adjList[i].firstedge = e;	/* 将当前顶点的指针指向e*/
	}
}
// 建立图的邻接表结构(尾插法)
void CreateALGraphTail(GraphAdjList* G) {
	int i, j, k;
	EdgeNode* e, * p;

	cout << "输入顶点数和边数：\n";
	cin >> G->numVertexes >> G->numEdges;

	// 建立顶点表，读入顶点信息
	for (i = 0; i < G->numVertexes; ++i) {
		cin >> G->adjList[i].data;	// 输入顶点信息
		G->adjList[i].firstedge = NULL;	// 将边表置为空表
	}

	for (k = 0; k < G->numEdges; ++k) {
		cout << "输入边（vi,vj)上的值：";
		cin >> i >> j;
		
		p = G->adjList[i].firstedge;

		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		if (!e)
			exit(-1);
		e->adjvex = j;
		e->next = NULL;
		if (!p) {
			G->adjList[i].firstedge = e;
		}
		else {
			while (p->next) {
				p = p->next;
			}
			p->next = e;
		}
	}
}

int visited[MAXVEX] = { 0 };
// 邻接表的深度优先递归算法
void DFS(GraphAdjList GL, int i) {
	EdgeNode* p;

	cout << GL.adjList[i].data << "\t";
	visited[i] = 1;
	p = GL.adjList[i].firstedge;
	while (p) {
		if (!visited[p->adjvex])
			DFS(GL, p->adjvex);
		p = p->next;
	}
}

// 邻接表的深度遍历操作
void DFSTraverse(GraphAdjList GL) {
	int i;
	for (i = 0; i < GL.numVertexes; ++i)
		if (!visited[i])
			DFS(GL, i);
}
int main() {
	GraphAdjList g;
	//CreateALGraphHead(&g);
	CreateALGraphTail(&g);
	//cout << sizeof(g);
	DFSTraverse(g);
	return 0;
}
/*邻接矩阵复习*/
//#include<iostream>
//using namespace std;
//
//#define MAXVEX 10
//#define INFINITY 99
//
//typedef char VertexType;
//typedef int EdgeType;
//typedef struct {
//	VertexType vexs[MAXVEX];
//	EdgeType arc[MAXVEX][MAXVEX];
//	int numVertexes, numEdges;
//}MGraph;
//
//// 建立无向网图的邻接矩阵表示	Adjacency Matrix
//void CreateMGraph(MGraph* G) {
//	int i, j, k, w;
//	cout << "输入顶点数和边数：\n";
//	cin >> G->numVertexes >> G->numEdges;
//
//	// 读入顶点信息，建立顶点表
//	for (i = 0; i < G->numVertexes; ++i) {
//		cin >> G->vexs[i];
//	}
//
//	for (i = 0; i < G->numVertexes; ++i) {
//		for (j = 0; j < G->numVertexes; ++j)
//			G->arc[i][j] = INFINITY;	/* 邻接矩阵初始化 */
//	}
//
//	// 读入numEdges条边，建立邻接矩阵
//	for (k = 0; k < G->numEdges; ++k) {
//		cout << "输入边（vi,vj）上的下标i，下标j及权值w:\n";
//		cin >> i >> j >> w;
//		G->arc[i][j] = w;
//		G->arc[j][i] = G->arc[i][j];	/* 因为是无向图， 矩阵对称 */
//	}
//}
//
//int visited[MAXVEX] = { 0 };
//// 邻接矩阵的深度遍历递归算法
//void DFS(MGraph G, int i) {
//	int j;
//	cout << G.vexs[i] << "\t";
//	visited[i] = 1;
//	for (j = 0; j < G.numVertexes; ++j) {
//		if (G.arc[i][j] != INFINITY && !visited[j])
//			DFS(G, j);
//	}
//}
//
//// 邻接矩阵的深度遍历操作
//void DFSTraverse(MGraph G) {
//	int i;
//	for (i = 0; i < G.numVertexes; ++i)
//		if (!visited[i])
//			DFS(G, i);
//}
//
//int main() {
//	MGraph g;
//	CreateMGraph(&g);
//	cout << sizeof(g) << endl;
//	return 0;
//}

/*2023/5/10*/
/*[USACO 2009 Oct G]Heat Wave*/
/*还是不行，但可以过%90了*/
//#include<iostream>
//using namespace std;
//
//#define MAXVEX 10
//#define INFINITY 99
//
//int arc[MAXVEX][MAXVEX];
//int P[MAXVEX], D[MAXVEX];
//int T, C, Ts, Te;
//
//// Dijkstra算法实现
//typedef int Patharc[MAXVEX];			/* 用于存储最短路径下标的数组 */
//typedef int ShortPathTable[MAXVEX];	/*用于存储到各点最短路径的权值和 */
//
//// Dijkstra算法，求有向网G的V0顶点到其余顶点v最短路径P[v]及带权长度D[v]
//// P[v] 的值为前驱顶点的下标，D[v]表示v0到v的最短路径长度和。
//void ShortestPath_Dijkstra(int v0) {
//	int v, w, k, min;
//	int status[MAXVEX];	/* status[w]=1 表示求得顶点v0至vw的最短路径 */
//
//	// 初始化数据
//	for (v = 0; v < T; ++v) {
//		status[v] = 0;			/* 全部顶点初始化为未知最短路径状态 */
//		D[v] = arc[v0][v]; /* 将与v0点有连线的顶点加上权值 */
//		P[v] = 0;			/* 初始化路径数组P为0 */
//	}
//	D[v0] = 0;	/* v0至v0的路径为0 */
//	status[v0] = 1;	/* v0至v0不需要求路径 */
//
//	// 开始主循环，每次求得v0到某个v顶点的最短路径
//	for (v = 1; v < T; ++v) {
//		min = INFINITY;		/* 当前所知离v0顶点的最近距离 */
//
//		// 寻找离v0最近的顶点
//		for (w = 0; w < T; ++w) {
//			if (!status[w] && D[w] < min) {
//				k = w;
//				min = D[w]; /* w顶点离v0顶点更近 */
//			}
//		}
//		status[k] = 1;	/* 将目前找到的最近的顶点置为1 */
//
//		// 修正当前最短路径及距离
//		for (w = 0; w < T; ++w) {
//			// 如果经过v顶点的路径比现在这条路径的长度短的话
//			if (!status[w] && (min + arc[k][w] < D[w])) {
//				// 说明找到了更短的路径，修改D[w]和P[w]
//				D[w] = min + arc[k][w];	/* 修改当前路径长度 */
//				P[w] = k;
//			}
//		}
//	}
//}
//
//int main() {
//	
//	int i, j, k, w;
//	cin >> T >> C >> Ts >> Te;
//
//	for (i = 0; i < T; ++i)
//		for (j = 0; j < T; ++j)
//			arc[i][j] = INFINITY;
//
//	for (k = 0; k < C; ++k) {
//		cin >> i >> j >> w;
//		arc[i][j] = w;
//		arc[j][i] = w;
//	}
//
//	ShortestPath_Dijkstra(Ts);
//
//	cout << D[Te] << endl;
//	return 0;
//}
/*原先代码 只能过10%*/
//#include<iostream>
//using namespace std;
//
//typedef char VertexType;	/*顶点类型*/
//typedef int EdgeType;		/*边上的权值类型*/
//
//#define MAXVEX 10
//#define INFINITY 99
//
//typedef struct {
//	VertexType vexs[MAXVEX];	/*顶点表*/
//	EdgeType arc[MAXVEX][MAXVEX];	/*边表*/
//	int numVertexes, numEdges;		/*图中当前顶点数和边数*/
//}MGraph;
//
//// 建立无向网图的邻接矩阵表示
//void CreateMGraph(MGraph* G, int T, int C) {
//	int i, j, k, w;
//	//cout << "输入顶点数和边数：\n";
//	//cin >> G->numVertexes >> G->numEdges;
//	G->numVertexes = T;
//	G->numEdges = C;
//
//	// 建立顶点表，读入顶点信息
//	/*for (i = 0; i < G->numVertexes; ++i) {
//		cin >> G->vexs[i];
//	}*/
//
//	// 邻接矩阵初始化
//	for (i = 0; i < G->numVertexes; ++i)
//		for (j = 0; j < G->numVertexes; ++j)
//			G->arc[i][j] = INFINITY;
//
//	// 读入边的信息，建立邻接矩阵
//	for (k = 0; k < G->numEdges; ++k) {
//		//cout << "输入边（vi,vj）上的下标i，下标j及权值w：\n";
//		cin >> i >> j >> w;
//		G->arc[i][j] = w;
//		G->arc[j][i] = G->arc[i][j];
//	}
//}
//
//// Dijkstra算法实现
//typedef int Patharc[MAXVEX];			/* 用于存储最短路径下标的数组 */
//typedef int ShortPathTable[MAXVEX];	/*用于存储到各点最短路径的权值和 */
//
//// Dijkstra算法，求有向网G的V0顶点到其余顶点v最短路径P[v]及带权长度D[v]
//// P[v] 的值为前驱顶点的下标，D[v]表示v0到v的最短路径长度和。
//void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D) {
//	int v, w, k, min;
//	int status[MAXVEX];	/* status[w]=1 表示求得顶点v0至vw的最短路径 */
//
//	// 初始化数据
//	for (v = 0; v < G.numVertexes; ++v) {
//		status[v] = 0;			/* 全部顶点初始化为未知最短路径状态 */
//		(*D)[v] = G.arc[v0][v]; /* 将与v0点有连线的顶点加上权值 */
//		(*P)[v] = 0;			/* 初始化路径数组P为0 */
//	}
//	(*D)[v0] = 0;	/* v0至v0的路径为0 */
//	status[v0] = 1;	/* v0至v0不需要求路径 */
//
//	// 开始主循环，每次求得v0到某个v顶点的最短路径
//	for (v = 1; v < G.numVertexes; ++v) {
//		min = INFINITY;		/* 当前所知离v0顶点的最近距离 */
//
//		// 寻找离v0最近的顶点
//		for (w = 0; w < G.numVertexes; ++w) {
//			if (!status[w] && (*D)[w] < min) {
//				k = w;
//				min = (*D)[w]; /* w顶点离v0顶点更近 */
//			}
//		}
//		status[k] = 1;	/* 将目前找到的最近的顶点置为1 */
//
//		// 修正当前最短路径及距离
//		for (w = 0; w < G.numVertexes; ++w) {
//			// 如果经过v顶点的路径比现在这条路径的长度短的话
//			if (!status[w] && (min + G.arc[k][w] < (*D)[w])) {
//				// 说明找到了更短的路径，修改D[w]和P[w]
//				(*D)[w] = min + G.arc[k][w];	/* 修改当前路径长度 */
//				(*P)[w] = k;
//			}
//		}
//	}
//}
//
//int main() {
//	int T, C, Ts, Te;
//	cin >> T >> C >> Ts >> Te;
//
//	MGraph G;
//	CreateMGraph(&G, T, C);
//
//	Patharc P;
//	ShortPathTable D;
//	ShortestPath_Dijkstra(G, Ts, &P, &D);
//	
//	cout << D[Te] << endl;
//	return 0;
//}


/*2023/5/6*/
/*邻接矩阵*/
//#include<iostream>
//using namespace std;
//
//typedef char VertexType;	/* 顶点类型 */
//typedef int EdgeType;		/* 边上的权值类型 */
//
//#define MAXVEX 10			/* 最大顶点数 */
//#define INFINITY 99			/* 用99来代表∞ */
//
//typedef struct {
//	VertexType vexs[MAXVEX];	/* 顶点表 */
//	EdgeType arc[MAXVEX][MAXVEX];	/* 邻接矩阵，可看作边表 */
//	int numVertexes, numEdges;	/* 图中当前的顶点数和边数 */
//}MGraph;
//
//// 建立无向网图的邻接矩阵表示
//void CreateMGraph(MGraph* G) {
//	int i, j, k, w;
//	printf("输入顶点数和边数：\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges); /* 输入顶点数和边数 */
//	// 读入顶点信息，建立顶点表
//	for (i = 0; i < G->numVertexes; ++i) {
//		char ch = getchar();
//		scanf_s("%c", &G->vexs[i], 1);
//	}
//
//	for (i = 0; i < G->numVertexes; ++i)
//		for (j = 0; j < G->numVertexes; ++j)
//			G->arc[i][j] = INFINITY;	/* 邻接矩阵初始化 */
//	// 读入numEdges条边，建立邻接矩阵
//	for (k = 0; k < G->numEdges; ++k) {
//		printf("输入边（vi,vj）上的下标i，下标j和权w:\n");
//		scanf_s("%d%d%d", &i, &j, &w);	/* 输入边（vi,vj）上的权w */
//		G->arc[i][j] = w;
//		G->arc[j][i] = G->arc[i][j];	/* 因为是无向图，矩阵对称 */
//	}
//}
//
//typedef int Boolean;		/* Boolean是布尔类型，其值是TRUE或FALSE */
//Boolean visited[MAXVEX];	/* 访问数组的标志 */
//#define TRUE 1
//#define FALSE 0
//
//// 邻接矩阵的深度优先递归算法
//void DFS(MGraph G, int i) {
//	int j;
//	visited[i] = TRUE;
//	printf("%c ", G.vexs[i]);	/* 打印顶点，也可进行其他操作 */
//	for (j = 0; j < G.numVertexes; ++j) {
//		if (G.arc[i][j] != INFINITY && !visited[j])
//			DFS(G, j);	/* 对未访问的邻接顶点递归调用 */
//	}
//}
//
//// 邻接矩阵的深度遍历操作
//void DFSTraverse(MGraph G) {
//	int i;
//	for (i = 0; i < G.numVertexes; ++i)
//		visited[i] = 0;	/* 初始化所有顶点状态都是未访问过状态 */
//	for (i = 0; i < G.numVertexes; ++i)
//		if (!visited[i]) /* 对未访问过的顶点调用DFS，若是连通图，只会执行一次 */
//			DFS(G, i);
//
//}
//
//// Dijkstra算法实现
//typedef int Patharc[MAXVEX];			/* 用于存储最短路径下标的数组 */
//typedef int ShortPathTable[MAXVEX];	/*用于存储到各点最短路径的权值和 */
//
//// Dijkstra算法，求有向网G的V0顶点到其余顶点v最短路径P[v]及带权长度D[v]
//// P[v] 的值为前驱顶点的下标，D[v]表示v0到v的最短路径长度和。
////void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D) {
////	int v, w, k, min;
////	int status[MAXVEX];	/* status[w]=1 表示求得顶点v0至vw的最短路径 */
////
////	// 初始化数据
////	for (v = 0; v < G.numVertexes; ++v) {
////		status[v] = 0;			/* 全部顶点初始化为未知最短路径状态 */
////		(*D)[v] = G.arc[v0][v]; /* 将与v0点有连线的顶点加上权值 */
////		(*P)[v] = 0;			/* 初始化路径数组P为0 */
////	}
////	(*D)[v0] = 0;	/* v0至v0的路径为0 */
////	status[v0] = 1;	/* v0至v0不需要求路径 */
////
////	// 开始主循环，每次求得v0到某个v顶点的最短路径
////	for (v = 1; v < G.numVertexes; ++v) {
////		min = INFINITY;		/* 当前所知离v0顶点的最近距离 */
////
////		// 寻找离v0最近的顶点
////		for (w = 0; w < G.numVertexes; ++w) {
////			if (!status[w] && (*D)[w] < min) {
////				k = w;
////				min = (*D)[w]; /* w顶点离v0顶点更近 */
////			}
////		}
////		status[k] = 1;	/* 将目前找到的最近的顶点置为1 */
////
////		// 修正当前最短路径及距离
////		for (w = 0; w < G.numVertexes; ++w) {
////			// 如果经过v顶点的路径比现在这条路径的长度短的话
////			if (!status[w] && (min + G.arc[k][w] < (*D)[w])) {
////				// 说明找到了更短的路径，修改D[w]和P[w]
////				(*D)[w] = min + G.arc[k][w];	/* 修改当前路径长度 */
////				(*P)[w] = k;
////			}
////		}
////	}
////}
//
//void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D) {
//	int i, v, k, w, min;
//	int status[MAXVEX];	/* status[w] = 1 w结点就是最短路径 */
//
//	// 初始化
//	for (w = 0; w < G.numVertexes; ++w) {
//		status[w] = 0;	/* 将所有结点都设置为未找到状态 */
//		(*D)[w] = G.arc[v0][w];	/* 将与0的结点连线*/
//		(*P)[w] = 0;	/* 将路径值设为0 */
//	}
//	(*D)[v0] = 0;	/*v0到v0的权值为0*/
//	status[v0] = 1;
//
//	// 求出v0到v的最短路径
//	for (v = 1; v < G.numVertexes; ++v) {
//		min = INFINITY;
//
//		// 得出与v0最近的顶点
//		for (w = 0; w < G.numVertexes; ++w) {
//			if (!status[w] && (*D)[w] < min) {
//				k = w;
//				min = (*D)[w];
//			}
//		}
//		status[k] = 1;
//
//		// 修改各顶点到v0的最短路径距离
//		for (w = 0; w < G.numVertexes; ++w) {
//			// 如果经过v点比当前路径小的话
//			if (!status[w] && (min + G.arc[k][w]) < (*D)[w]) {
//				(*D)[w] = min + G.arc[k][w];
//				(*P)[w] = k;
//			}
//		}
//	}
//
//}
//
//int main() {
//	MGraph G;
//	CreateMGraph(&G);
//	// DFSTraverse(G);
//
//	Patharc P;
//	ShortPathTable D;
//	ShortestPath_Dijkstra(G, 0, &P, &D);
//	for (int i = 0; i < G.numVertexes; ++i) {
//		cout << D[i] << "\t";
//	}
//	return 0;
//}
/*Dijkstra算法*/
//#include<iostream>
//using namespace std;
//
//#define MAXVEX 5					/* 最大顶点数 */
//#define INFINITY 65535				/* 用65536代表无穷 */
//
//typedef int Patharc[MAXVEX];	/* 用于存储最短路径下标的数组 */
//typedef int ShortPathTable[MAXVEX]; /* 用于存储到各点最短路径的权值和 */
//typedef char VertexType;			/* 顶点类型 */
//typedef int EdgeType;				/* 边上的权值类型 */
//
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
//// Dijkstra算法，求有向网G的v0顶点到其余顶点v最短路径P[v]及带权长度D[v]
//// P[v]的值为前驱顶点下标，D[v]表示v0到v的最短路径长度和。
//void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D) {
//	int v, w, k = 0, min;
//	int finalt[MAXVEX];	/* final[w]=1表示求得顶点v0至vw的最短路径*/
//	// 初始化数据
//	for (v = 0; v < G.numVertexes; v++) {
//		finalt[v] = 0;			/* 全部顶点初始化为未知最短路径状态 */
//		(*D)[v] = G.arc[v0][v];	/* 将与v0点有连线的顶点加上权值 */
//		(*P)[v] = 0;			/* 初始化路径数组P为0 */
//	}
//	(*D)[v0] = 0;	/* V0至v0路径为0 */
//	finalt[v0] = 1;	/* v0至v0不需要求路径 */
//
//	/* 开始主循环，每次求得v0到某个v顶点的最短路径 */
//	for (v = 1; v < G.numVertexes; ++v) {
//		min = INFINITY;	/* 当前所知离v0顶点的最近距离 */
//		// 寻找离v0最近的顶点
//		for (w = 0; w < G.numVertexes; w++) {
//			if (!finalt[w] && (*D)[w] < min) {
//				k = w;
//				min = (*D)[w];	/* w顶点离v0顶点更近 */
//			}
//		}
//		finalt[k] = 1; /* 将目前找到的最近顶点置为1 */
//		// 修正当前最短路径及距离
//		for (w = 0; w < G.numVertexes; ++w) {
//			// 如果经过v顶点的路径比现在这条路径的长度短的话
//			if (!finalt[w] && (min + G.arc[k][w] < (*D)[w])) {
//				// 说明找到了更短的路径，修改D[w]和P[w]
//				(*D)[w] = min + G.arc[k][w]; /* 修改当前路径长度 */
//				(*P)[w] = k;
//			}
//		}
//	}
//}
//
//int main() {
//	MGraph G;
//	Patharc a;
//	ShortPathTable b;
//	CreateMGraph(&G);
//	ShortestPath_Dijkstra(G, 0, &a, &b);
//	cout << b[3] << endl;
//	
//	return 0;
//}
/*邻接表练习*/
//#include<iostream>
//using namespace std;
//
//#define MAXVEX 10	/*最大顶点数*/
//
//typedef char VertexType;	/*顶点类型*/
//typedef int EdgeType;	/*边上的权值类型*/
//
//// 边表结点
//typedef struct EdgeNode {
//	int adjvex;	/*邻接点域，存储该顶点对应的下标*/
//	EdgeType weight;	/*用于存储权值，对于非网图可以不需要*/
//	struct EdgeNode* next;	/*链域，指向下一邻接点*/
//}EdgeNode;
//
//// 顶点表结点
//typedef struct VertexNode {
//	VertexType data;		/*顶点域，存储顶点信息*/
//	EdgeNode* firstedge;	/*边表头指针*/
//}VertexNode, AdjList[MAXVEX];
//
//typedef struct {
//	AdjList adjList;
//	int numVertexes, numEdges;	/*图中当前顶点数和边数*/
//}GraphAdjList;
//
//void CreateALGraph(GraphAdjList* G) {
//	int i, j, k;
//	EdgeNode* e;
//	printf("输入顶点数和边数：\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);
//	//读入顶点信息，建立顶点表
//	for (i = 0; i < G->numVertexes; ++i) {
//		char ch = getchar();
//		scanf_s("%c", &G->adjList[i].data, 1);	/*输入顶点信息*/
//		G->adjList[i].firstedge = NULL;	/*将边表置为空表*/
//	}
//
//	// 建立边表
//	for (k = 0; k < G->numEdges; ++k) {
//		printf("输入边（vi,vj）上的顶点序号：\n");
//		scanf_s("%d%d", &i, &j);
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));	/*向内存申请空间，
//													生成边表结点*/
//		if (!e)
//			exit(OVERFLOW);
//		e->adjvex = j;	/*邻接序号为j*/
//		e->next = G->adjList[i].firstedge;	/*将e的指针指向当前顶点指向的结点*/
//		G->adjList[i].firstedge = e;	/*将当前顶点的指针指向e*/
//	}
//}
//
//int visited[MAXVEX] = { 0 };
//void DFS(GraphAdjList* G, int i) {
//	EdgeNode* p;
//	visited[i] = 1;
//	cout << G->adjList[i].data;
//	p = G->adjList[i].firstedge;
//	while (p) {
//		if (!visited[p->adjvex])
//			DFS(G, p->adjvex);
//		p = p->next;
//	}
//}
//
//void DFSTraverse(GraphAdjList* G) {
//	int i;
//
//	for (i = 0; i < G->numVertexes; ++i) {
//		if (!visited[i]) {
//			DFS(G, i);
//		}
//	}
//}
//
//// 邻接表的广度遍历算法
//typedef VertexNode QElemType;
//// 循环队列的顺序存储结构
//typedef struct {
//	QElemType data[MAXVEX];
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
//	return (Q.rear - Q.front + MAXVEX) % MAXVEX;
//}
//// 若队列未满，则插入元素e为Q新的队尾元素
//int EnQueue(SqQueue* Q, QElemType e) {
//	if ((Q->rear + 1) % MAXVEX == Q->front)	// 队列满的判断
//		return 0;
//	Q->data[Q->rear] = e;	/* 将元素e赋值给队尾 */
//	Q->rear = (Q->rear + 1) % MAXVEX; /* rear指针向后移一位，
//									   若到最后则转到数组头部 */
//	return 1;
//}
//// 若队列不空，则删除Q中队头元素，用e返回其值
//int DeQueue(SqQueue* Q, QElemType* e) {
//	if (Q->front == Q->rear)
//		return 0;
//	*e = Q->data[Q->front];
//	Q->front = (Q->front + 1) % MAXVEX;	/* front 指针后移一位置，
//											若到最后则转到数组头部 */
//	return 1;
//}
//
//void BFSTraverse(GraphAdjList* GL) {
//	int i;
//	EdgeNode* p;
//	SqQueue Q;
//	for (i = 0; i < GL->numVertexes; ++i)
//		visited[i] = 0;
//	InitQueue(&Q);
//	for (i = 0; i < GL->numVertexes; ++i) {
//		if (!visited[i]) {
//			visited[i] = 1;
//			printf("%c\t", GL->adjList[i].data);
//			EnQueue(&Q, GL->adjList[i]);
//			while (!(Q.front == Q.rear)) {
//				DeQueue(&Q, &GL->adjList[i]);
//				p = GL->adjList[i].firstedge;
//				while (p) {
//					if (!visited[p->adjvex]) {
//						visited[p->adjvex] = 1;
//						cout << GL->adjList[p->adjvex].data << "\t";
//						EnQueue(&Q, GL->adjList[p->adjvex]);
//					}
//					p = p->next;
//				}
//			}
//		}
//	}
//}
//
//int main() {
//	GraphAdjList G;
//	CreateALGraph(&G);
//	//DFSTraverse(&G);
//	BFSTraverse(&G);
//	return 0;
//}
/*2023/5/5*/
/*迷宫问题*/
/*改进1错误*/
//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//#define MAXVEX 1005
//
//// 边表结点
//struct EdgeNode {
//	int adjvex, w;
//	EdgeNode(int ad, int w) : adjvex(ad), w(w) {}
//	EdgeNode() {}
//};
//
//vector<EdgeNode> road[MAXVEX];
//int dp[MAXVEX];
//int start[MAXVEX];
//
//int dfs(int i) {
//	EdgeNode* p;
//	if (dp[i] > 0)
//		return dp[i];
//	int ans = 0;
//	for (int n = 0; n < road[i].size(); ++n) {
//		ans = max(ans, dfs(road[i][n].adjvex) + road[i][n].w);
//	}
//	dp[i] = ans;
//	return dp[i];
//}
//
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//
//		int n, m, k, i, u, v, w;
//		cin >> n >> m;
//		memset(dp, 0, sizeof(dp));
//		memset(start, 0, sizeof(start));
//
//		for (k = 0; k < m; ++k) {
//			cin >> u >> v >> w;
//			road[k].push_back(EdgeNode(v, w));
//			start[v] = 1;
//		}
//
//		for (i = 0; i < n; ++i)
//			if (!start[i])
//				dfs(i);
//
//		cout << *max_element(dp, dp + n) << endl;
//		for (k = 0; k < n; ++k) {
//			road[k].clear();
//		}
//	}
//	return 0;
//}
/*他人题解*/
//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//struct node {
//	int next, tre;
//	node(int nn, int tt) :next(nn), tre(tt) {}//参数构造函数
//	node() {}//默认构造函数
//};
//vector<node> road[1005];
//int start[1005];
//int dp[1005];
//int dfs(int n) {
//	if (dp[n] > 0)return dp[n];
//	int ans = 0;
//	for (int i = 0; i < road[n].size(); i++) {
//		ans = max(ans, dfs(road[n][i].next) + road[n][i].tre);
//	}
//	dp[n] = ans;
//	return dp[n];
//}
//int main()
//{
//	int T, n, m;
//	cin >> T;
//	int a, b, c;
//	while (T--) {
//		cin >> n >> m;
//		memset(start, 0, sizeof(start));
//		memset(dp, 0, sizeof(dp));
//		for (int i = 0; i < m; i++) {
//			cin >> a >> b >> c;
//			road[a].push_back(node(b, c));
//			start[b] = 1;
//		}
//		for (int i = 0; i < n; i++) {
//			if (start[i] == 0) {
//				dfs(i);
//			}
//		}
//		cout << *max_element(dp, dp + n) << endl;//返回dp数组中最大值
//		for (int i = 0; i < n; i++)road[i].clear();//将路径清零
//	}
//}
/*我的通过*/
// 缺点：内存占用过大
//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//#define MAXVEX 1005
//
//// 边表结点
//struct EdgeNode {
//	int adjvex, w;
//	EdgeNode* next;
//};
//
//vector<EdgeNode*> road(MAXVEX);
//EdgeNode* e;
//
//int dp[MAXVEX];
//int start[MAXVEX];
//
//int dfs(int i) {
//	EdgeNode* p;
//	if (dp[i] > 0)
//		return dp[i];
//	int ans = 0;
//	p = road[i];
//	while (p) {
//		ans = max(ans, dfs(p->adjvex) + p->w);
//		p = p->next;
//	}
//	dp[i] = ans;
//	return dp[i];
//}
//
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//
//		int n, m, k, i, u, v, w;
//		cin >> n >> m;
//		memset(dp, 0, sizeof(dp));
//		memset(start, 0, sizeof(start));
//
//		for (k = 0; k < m; ++k) {
//			cin >> u >> v >> w;
//			e = (EdgeNode*)malloc(sizeof(EdgeNode));
//
//			e->adjvex = v;
//			e->w = w;
//			e->next = road[u];
//			road[u] = e;
//			start[v] = 1;
//		}
//		for (i = 0; i < n; ++i)
//			if (!start[i])
//				dfs(i);
//		cout << *max_element(dp, dp + n) << endl;
//		vector<EdgeNode*>(MAXVEX).swap(road);
//	}
//	return 0;
//}

/*错误2*/
//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//#define MAXVEX 1005
//
//// 边表结点
//struct EdgeNode {
//	int adjvex;
//	int w;
//	EdgeNode* next;
//};
//
//vector<EdgeNode*> road(MAXVEX);
//EdgeNode* e;
//int dp[MAXVEX];
//
//int dfs(int i) {
//	EdgeNode* p;
//	if (dp[i] > 0)
//		return dp[i];
//	int ans = 0;
//	p = road[i];
//	while (p) {
//		ans = max(ans, dfs(p->adjvex) + p->w);
//		p = p->next;
//	}
//	dp[i] = ans;
//	return dp[i];
//}
//
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		
//		int n, m, k, i, u, v, w;
//		cin >> n >> m;
//		memset(dp, 0, sizeof(dp));
//		for (k = 0; k < n; ++k)
//			road[k] = NULL;
//
//		for (k = 0; k < m; ++k) {
//			cin >> u >> v >> w;
//			e = (EdgeNode*)malloc(sizeof(EdgeNode));
//
//			e->adjvex = v;
//			e->w = w;
//			e->next = NULL;
//			road[u] = e;
//		}
//		for (i = 0; i < n; ++i)
//			dfs(i);
//		cout << *max_element(dp, dp + n) << endl;
//	}
//	return 0;
//}
/*错误1*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//#define MAXVEX 1005
//
//// 边表结点
//struct EdgeNode {
//	int adjvex;
//	int w;
//	EdgeNode* next;
//};
//
//
//EdgeNode* e;
//int dp[MAXVEX] = {0};
//
//vector<EdgeNode*> road(MAXVEX);
//int dfs(int i) {
//	EdgeNode* p;
//	if (dp[i] > 0)
//		return dp[i];
//	int ans = 0;
//	p = road[i];
//	while (p) {
//		ans = max(ans, dfs(p->adjvex) + p->w);
//		p = p->next;
//	}
//	dp[i] = ans;
//	return dp[i];
//}
//
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		
//		int n, m, i, j, k, u, v, w;
//		cin >> n >> m;
//		memset(dp, 0, n);
//		for (k = 0; k < n; ++k)
//			road[k] = NULL;
//
//		for (k = 0; k < m; ++k) {
//			cin >> u >> v >> w;
//			e = (EdgeNode*)malloc(sizeof(EdgeNode));
//			if (!e)
//				exit(OVERFLOW);
//			e->adjvex = v;
//			e->w = w;
//			e->next = NULL;
//			road[u] = e;
//		}
//		int MAX = -9999;
//		for (i = 0; i < n; ++i)
//			MAX = max(MAX, dfs(i));
//		cout << MAX << endl;
//		/*for (i = 0; i < n; ++i)
//			dfs(i);
//		cout << *max_element(dp, dp + n) << endl;*/
//		for (i = 0; i < n; ++i)
//			road[i] 
//	}
//	return 0;
//}
/*邻接表练习2*/
//#include<iostream>
//using namespace std;
//
//#define MAXVEX 10
//typedef char VertexType;
//typedef int EdgeType;
//
//// 边表结点
//typedef struct EdgeNode {
//	int adjvex;
//	EdgeNode* next;
//}EdgeNode;
//
//// 顶点表结点
//typedef struct VertexNode {
//	VertexType data;
//	EdgeNode* firstedge;
//}VertexNode, AdjList[MAXVEX];
//
//typedef struct {
//	AdjList adjList;
//	int numVertexes, numEdges;
//}GraphAdjList;
//
//void CreateALGraph(GraphAdjList* G) {
//	int i, j, k;
//	EdgeNode* p, * e;
//	cin >> G->numVertexes >> G->numEdges;
//	for (i = 0; i < G->numVertexes; ++i) {
//		cin >> G->adjList[i].data;
//		G->adjList[i].firstedge = NULL;
//	}
//	for (k = 0; k < G->numEdges; ++k) {
//		cin >> i >> j;
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		if (!e)
//			exit(OVERFLOW);
//		e->next = NULL;
//		e->adjvex = j;
//		G->adjList[i].firstedge = e;
//	}
//}
//
//int visited[MAXVEX] = {0};
//void DFS(GraphAdjList* GL, int i) {
//	EdgeNode* p;
//	visited[i] = 1;
//	cout << GL->adjList[i].data << "\t";
//	p = GL->adjList[i].firstedge;
//	while (p) {
//		if (!visited[p->adjvex]) {
//			DFS(GL, p->adjvex);
//		}
//		p = p->next;
//	}
//}
//
//void DFSTraverse(GraphAdjList* GL) {
//	int i;
//	for (i = 0; i < GL->numVertexes; ++i)
//		if (!visited[i])
//			DFS(GL, i);
//}
//
//int main() {
//	GraphAdjList G;
//	CreateALGraph(&G);
//	DFSTraverse(&G);
//	return 0;
//}
/*邻接表练习1*/
//#include<iostream>
//using namespace std;
//
//#define MAXVEX 10	/*最大顶点数*/
//
//typedef char VertexType;
//typedef int EdgeType;
//
//// 边表结点
//typedef struct EdgeNode {
//	int adjvex;	/* 邻接点域，存储该顶点的下标 */
//	EdgeType weight; /*存储权值*/
//	EdgeNode* next;
//}EdgeNode;
//
//// 顶点表结点
//typedef struct VertexNode {
//	VertexType data;
//	EdgeNode* firstedge;	/*边表头结点*/
//}VertexNode, AdjList[MAXVEX];
//
//typedef struct {
//	AdjList adjList;
//	int numVertexes, numEdges;
//}GraphAdjList;
//
//void CreateALGraph(GraphAdjList* G) {
//	int i, j, k, w;
//	EdgeNode* e, * p;
//	cout << "输入顶点数和边数：";
//	cin >> G->numVertexes >> G->numEdges;
//	// 读入顶点表信息
//	for (i = 0; i < G->numVertexes; ++i) {
//		cin >> G->adjList[i].data;
//		G->adjList[i].firstedge = NULL;
//	}
//
//	for (k = 0; k < G->numEdges; ++k) {
//		cout << "输入边（vi,vj)上的下标和权值：\n";
//		cin >> i >> j >> w;
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		if (!e)
//			exit(OVERFLOW);
//		e->adjvex = j;
//		e->next = NULL;
//		e->weight = w;
//		p = G->adjList[i].firstedge;
//		if (!p) {
//			G->adjList[i].firstedge = e;
//		}
//		else {
//			while (p->next) {
//				p = p->next;
//			}
//			p->next = e;
//		}
//
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		if (!e)
//			exit(OVERFLOW);
//		e->adjvex = i;
//		e->next = NULL;
//		e->weight = w;
//		p = G->adjList[j].firstedge;
//		if (!p) {
//			G->adjList[j].firstedge = e;
//		}
//		else {
//			while (p->next) {
//				p = p->next;
//			}
//			p->next = e;
//		}
//	}
//}
//
//int visited[MAXVEX];
//
//void DFS(GraphAdjList GL, int i) {
//	EdgeNode* p;
//	visited[i] = 1;
//	cout << GL.adjList[i].data << "\t";
//	p = GL.adjList[i].firstedge;
//	while (p) {
//		if (!visited[p->adjvex])
//			DFS(GL, p->adjvex);
//		p = p->next;
//	}
//}
//
//void DFSTraverse(GraphAdjList GL) {
//	int i;
//	memset(visited, 0, GL.numVertexes);
//	for (i = 0; i < GL.numVertexes; ++i) {
//		if (!visited[i])
//			DFS(GL, i);
//	}
//}
//
//int main() {
//	GraphAdjList G;
//	CreateALGraph(&G);
//	DFSTraverse(G);
//	return 0;
//}

/*邻接表复习*/
// exerciseAdjacencyList
//#include<iostream>
//using namespace std;
//
//#define MAXVEX 10	// 最大顶点个数
//typedef char VertexType;	/*顶点信息类型*/
//typedef int EdgeType;	/*边表上的权值类型*/
//int visited[MAXVEX] = {0};
//
////边表结点
//typedef struct EdgeNode {
//	int adjvex;	/*邻接点域，存储该顶点对应的下标*/
//	EdgeType weigth;	/*用于存储权值*/
//	EdgeNode* next;	/*链域，指向下一邻接点*/
//}EdgeNode;
//// 顶点表结点
//typedef struct VertexNode {
//	VertexType data;	/*顶点域，存放顶点信息*/
//	EdgeNode* firstedge;	/*边表头指针*/
//}VertexNode, AdjList[MAXVEX];
//
//typedef struct {
//	AdjList adjList;
//	int numVertexes, numEdges;
//}GraphAdjList;
//
//void CreateALGraph(GraphAdjList* G) {
//	int i, j, k, w;
//	EdgeNode* e;
//	EdgeNode* p;
//	cout << "输入顶点数和边数：\n";
//	cin >> G->numVertexes >> G->numEdges;
//	// 读入顶点信息，建立顶点表
//	for (i = 0; i < G->numVertexes; ++i) {
//		cin >> G->adjList[i].data;
//		G->adjList[i].firstedge = NULL;	/*将边表置为空表*/
//	}
//	
//	for (k = 0; k < G->numEdges; ++k) {
//		cout << "输入边（vi,vj)上的顶点序号以及权值：\n";
//		cin >> i >> j >> w;
//
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		if (!e) {
//			exit(OVERFLOW);
//		}
//		e->adjvex = j;
//		e->weigth = w;
//		e->next = NULL;
//		p = G->adjList[i].firstedge;
//		if (!p) {
//			G->adjList[i].firstedge = e;
//		}
//		else {
//			while (p->next) {
//				p = p->next;
//			}
//			p->next = e;
//		}
//
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		if (!e) {
//			exit(OVERFLOW);
//		}
//		e->adjvex = i;
//		e->weigth = w;
//		e->next = NULL;
//		p = G->adjList[j].firstedge;
//		if (!p) {
//			G->adjList[j].firstedge = e;
//		}
//		else {
//			while (p->next) {
//				p = p->next;
//			}
//			p->next = e;
//		}
//	}
//}
//
//// 邻接表的深度优先递归算法
//void DFS(GraphAdjList GL, int i) {
//	EdgeNode* p;
//	visited[i] = 1;
//	cout << GL.adjList[i].data << "\t";
//	p = GL.adjList[i].firstedge;
//	while (p) {
//		if (!visited[p->adjvex]) {
//			DFS(GL, p->adjvex);
//		}
//		p = p->next;
//	}
//}
//
//// 邻接表的深度遍历操作
//void DFSTraverse(GraphAdjList GL) {
//	int i;
//	memset(visited, 0, GL.numVertexes);
//	for (i = 0; i < GL.numVertexes; ++i) {
//		cout << visited[i] << endl;
//	}
//	for (i = 0; i < GL.numVertexes; ++i)
//		if (!visited[i])
//			DFS(GL, i);
//}
//int main() {
//	GraphAdjList G;
//	CreateALGraph(&G);
//	DFSTraverse(G);
//	return 0;
//}
// AdjacencyList
//#include<iostream>
//using namespace std;
//
//const int MAXVEX = 10;
//typedef char VertexType;	/*顶点类型*/
//typedef int EdgeType;	/*边上的权值类型*/
//
//// 边表结点
//typedef struct EdgeNode {
//	int adjvex;	/*邻接点域，存储该顶点对应的下标*/
//	EdgeType weight;	/*用于存储权值，对于非网图可以不需要*/
//	EdgeNode* next;	/* 链域，指向下一邻接点 */
//}EdgeNode;
//
//// 顶点表结点
//typedef struct VertexNode {
//	VertexType data;	/*顶点域，存储顶点信息*/
//	EdgeNode* firstedge;	/*边表头指针*/
//}VertexNode, AdjList[MAXVEX];
//
//typedef struct {
//	AdjList adjList;
//	int numVertexes, numEdges;	/*图中当前顶点数和边数*/
//}GraphAdjList;
//
//// 建立图的邻接表结构
//void CreateALGraph(GraphAdjList* G) {
//	int i, j, k;
//	EdgeNode* e;
//	cout << "输入顶点数和边数：\n";
//	cin >> G->numVertexes >> G->numEdges;
//	for (i = 0; i < G->numVertexes; ++i) {
//		// 读入顶点信息，建立顶点表
//		cin >> G->adjList[i].data;	/*输入顶点信息*/
//		G->adjList[i].firstedge = NULL;	/*将边表置为空表*/
//	}
//	// 建立边表
//	for (k = 0; k < G->numEdges; ++k) {
//		cout << "输入边（vi,vj）上的顶点序号：\n";
//		cin >> i >> j;
//		e = (EdgeNode*)malloc(sizeof(EdgeNode)); /*向内存申请空间，生成边表结点*/
//		e->adjvex = j;	/*邻接序号为j*/
//		e->next = G->adjList[i].firstedge;	/*将e指针指向当前顶点指向的结点*/
//		G->adjList[i].firstedge = e;	/*将当前顶点的指针指向e*/
//
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		e->adjvex = i;
//		e->next = G->adjList[j].firstedge; /*将e指针指向当前顶点指向的结点*/
//		G->adjList[j].firstedge = e;/*将当前顶点的指针指向e*/
//	}
//}
//int main() {
//	GraphAdjList G;
//	CreateALGraph(&G);
//	return 0;
//}
/*树的孩子表示法复习*/
//#include<iostream>
//#include<vector>
//using namespace std;
//
//#define MAX_TREE_SIZE 100
//// 孩子结点
//typedef struct CTNode {
//	int child;
//	struct CTNode* next;
//}*ChildPtr;
//// 表头结构
//typedef struct {
//	char data;
//	ChildPtr firstchild;
//}CTBox;
//// 树结构
//typedef struct {
//	CTBox nodes[MAX_TREE_SIZE];
//	int r, n;
//}CTree;
//
//struct node {
//	int adjnext, next;
//	node(int ad, int ne) : adjnext(ad), next(ne) {}
//	node() {}
//};
//vector<node> road[MAX_TREE_SIZE];
//
//int main() {
//
//	return 0;
//}
/*2023/5/5before*/
//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAX = 1005;
//const int INF = 99999;
//
//struct node {
//	int adjvex, next;
//	node(int a, int n) : adjvex(a), next(n) {}
//	node() {}
//};
//vector<node> road[MAX];
//int start[MAX];
//int dp[MAX];
//
//int main() {
//	int T, n, m;
//	
//	cin >> T;
//	int u, v, w;
//	while (T--) {
//		cin >> n >> m;
//		memset(start, 0, sizeof(start));
//		memset(dp, 0, sizeof(dp));
//		for (int i = 0; i < m; ++i) {
//			cin >> u >> v >> w;
//			road[u].push_back(node(v, w));
//			start[v] = 1;
//		}
//	}
//	
//	return 0;
//}
//#include<stdio.h>
//#include<iostream>
//#include <algorithm>
//#include<math.h>
//using namespace std;
//
//#define MAXVEX 10			/* 最大顶点数 */
//#define INFINITY 65535		/* 用65535代表无穷 */
//#define TRUE 1
//#define FALSE 0
//
//typedef char VertexType;	/* 顶点类型 */
//typedef int EdgeType;		/* 边上的值类型 */
//typedef int Boolean;		/* Boolean是布尔类型，其值是TRUE或FALSE */
//typedef struct {
//	VertexType vexs[MAXVEX];	/* 顶点表 */
//	EdgeType arc[MAXVEX][MAXVEX];	/* 邻接矩阵，可看作边 */
//	int numVertexes, numEdges;		/* 图中当前的顶点数和边数 */
//}MGraph;
//
//Boolean visited[MAXVEX];	/* 访问标志的数组 */
//int dp[MAXVEX];
//
////建立无向网图的邻接矩阵表示
//void CreateMGraph(MGraph* G) {
//	int i, j, k, w;
//	printf("输入顶点数和边数：");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);	/* 输入顶点数和边数 */
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
//	for (k = 0; k < G->numEdges; k++) {
//		printf("输入边（vi,vj）上的下标i，下标j和w：");
//		scanf_s("%d%d%d", &i, &j, &w);
//		G->arc[i][j] = w;
//		//G->arc[j][i] = G->arc[i][j];	/* 因为是无向图，矩阵对称 */
//	}
//}
//
//// 邻接矩阵的深度优先递归算法
//int DFS1(MGraph G, int i) {
//	int j;
//
//	visited[i] = TRUE;
//
//	for (j = 0; j < G.numVertexes; j++)
//		if (G.arc[i][j] != INFINITY && dp[i] == -INFINITY) {
//			dp[i] = max(G.arc[i][j], DFS(G, j) + G.arc[i][j]);
//		}
//
//	return dp[i];
//}
//
//int DFS(MGraph G, int i) {
//	int j; 
//	int ans;
//
//	if (dp[i] > 0)
//		return dp[i];
//
//	ans = 0;
//	for (j = 0; j < G.numVertexes; j++)
//		if (G.arc[i][j] != INFINITY) {
//			ans = max(ans, DFS(G, j) + G.arc[i][j]);
//		}
//	dp[i] = ans;
//	return dp[i];
//}
//
//// 邻接矩阵的深度遍历操作
//void DFSTraverse(MGraph G) {
//	int i;
//
//	for (i = 0; i < G.numVertexes; ++i)
//		visited[i] = FALSE;		/* 初始所有顶点状态都是未访问的状态 */
//
//	for (i = 0; i < G.numVertexes; ++i)
//		dp[i] = -INFINITY;	/* 初始化dp数组 */
//
//	for (i = 0; i < G.numVertexes; ++i)
//		if (!visited[i])	/* 对未访问过的顶点调用DFS，若是连通图，只会执行一次 */
//			DFS(G, i);
//}
//
//int main() {
//	MGraph G;
//	CreateMGraph(&G);
//	DFSTraverse(G);
//	for (int i = 0; i < G.numVertexes; i++)
//		printf("%d\t", dp[i]);
//	return 0;
//}
//#include<stdio.h>
//
//typedef char VertexType;			/* 顶点类型 */
//typedef int EdgeType;				/* 边上的值类型 */
//
//#define MAXVEX 10					/* 最大顶点数 */
//#define INFINITY 65535				/* 用65535代表无穷 */
//
//typedef struct {
//	VertexType vexs[MAXVEX];		/* 顶点表 */
//	EdgeType arc[MAXVEX][MAXVEX];	/* 邻接矩阵，可看作边 */
//	int numVertexes, numEdges;		/* 图中最大顶点数和边数 */
//}MGraph;
//
//// 建立无向网图的邻接矩阵表示
//void CreateMGraph(MGraph* G) {
//	int i, j, k, w;
//	printf("输入顶点数和边数：");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);	/* 输入顶点数和边数 */
//
//	for (i = 0; i < G->numVertexes; i++) {
//		printf("输入第%d个顶点信息：", i + 1);
//		char ch = getchar();
//		scanf_s("%c", &G->vexs[i], 1);	/* 读入顶点信息， 建立顶点表 */
//	}
//
//	for (i = 0; i < G->numVertexes; i++)
//		for (j = 0; j < G->numVertexes; ++j)
//			G->arc[i][j] = INFINITY;	/* 邻接矩阵初始化 */
//
//	for (k = 0; k < G->numEdges; ++k) {
//		printf("输入边（vi,vj）上的下标i，下标j和权w：");
//		scanf_s("%d%d%d", &i, &j, &w);
//		G->arc[i][j] = w;
//		G->arc[j][i] = G->arc[i][j];	/* 因为是无向图， 矩阵对称 */
//	}
//}
//int main() {
//	MGraph G;
//	CreateMGraph(&G);
//	return 0;
//}


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