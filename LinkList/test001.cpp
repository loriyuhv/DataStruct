//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//#define MAXN 1005
//
//typedef struct EdgeNode {
//	int adjvex;
//	int w;
//	struct EdgeNode* next;
//}EdgeNode;
//
//typedef struct VertexNode {
//	EdgeNode* firstedge;
//}AdjList[MAXN];
//
//int T, n, m, u, v, w;
//EdgeNode* e;
//AdjList adjList;
//int dp[MAXN];
//
//int dfs(int i) {
//	EdgeNode* p = adjList[i].firstedge;
//	if (dp[i] >= 0) {
//		return dp[i];
//	}
//	dp[i] = 0;
//	while (p) {
//		dp[i] = max(dp[i], dfs(p->adjvex) + p->w);
//		p = p->next;
//	}
//	return dp[i];
//}
//
//int main() {
//	int i, j;
//	scanf_s("%d", &T);
//	while (T--) {
//		scanf_s("%d%d", &n, &m);
//
//		for (i = 0; i < n; i++) {
//			adjList[i].firstedge = NULL;
//		}
//
//		for (i = 0; i < n; i++)
//			dp[i] = -1;
//
//		for (i = 0; i < m; ++i) {
//			scanf_s("%d%d%d", &u, &v, &w);
//			e = (EdgeNode*)malloc(sizeof(EdgeNode));
//			if (!e) {
//				exit(-1);
//			}
//			e->w = w;
//			e->adjvex = v;
//			e->next = adjList[u].firstedge;
//			adjList[u].firstedge = e;
//		}
//
//		int Max = -9999;
//		for (i = 0; i < n; ++i) {
//			Max = max(dfs(i), Max);
//		}
//		printf("%d\n", Max);
//
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//
//#define MAXN 1005
//#define INF 99999
//
//int road[MAXN][MAXN];
//int dp[MAXN];
//int T, n, m, u, v, w;
//
//int dfs(int i);
//
//
//int main() {
//	int i, j, Max;
//	scanf_s("%d", &T);
//	while (T--) {
//		scanf_s("%d%d", &n, &m);
//		
//		for (i = 0; i < n; i++)
//			for (j = 0; j < n; j++)
//				road[i][j] = INF;
//
//		for (i = 0; i < n; i++)
//			dp[i] = INF;
//
//		for (i = 0; i < m; i++) {
//			scanf_s("%d%d%d", &u, &v, &w);
//			road[u][v] = w;
//		}
//
//		Max = -INF;
//		for (i = 0; i < n; ++i)
//			Max = fmax(Max, dfs(i));
//		printf("%d\n", Max);
//	}
//	return 0;
//}
//
//int dfs(int i) {
//	int j;
//	if (dp[i] != INF) {
//		return dp[i];
//	}
//	dp[i] = 0;
//	for (j = 0; j < n; ++j) {
//		if (road[i][j] != INF)
//			dp[i] = fmax(dp[i], dfs(j) + road[i][j]);
//	}
//	return dp[i];
//}

//#include<stdio.h>
//#include<iostream>
//#include <algorithm>
//#include<vector>
//using namespace std;
//
//#define MAXVEX 1005			/* 最大顶点数 */
//#define INFINITY 9999		/* 用65535代表无穷 */
//
//typedef struct {
//	int arc[MAXVEX][MAXVEX];	/* 邻接矩阵，可看作边 */
//	int numVertexes, numEdges;		/* 图中当前的顶点数和边数 */
//}MGraph;
//
//int visited[MAXVEX];	/* 访问标志的数组 */
//int dp[MAXVEX];
//MGraph G;
//
////建立无向网图的邻接矩阵表示
//void CreateMGraph() {
//	int i, j, k, w;
//	cin >> G.numVertexes >> G.numEdges; /* 输入顶点数和边数 */
//
//	for (i = 0; i < G.numVertexes; ++i)
//		for (j = 0; j < G.numVertexes; ++j)
//			G.arc[i][j] = INFINITY;	/* 邻接矩阵初始化 */
//
//	for (k = 0; k < G.numEdges; k++) {
//		cin >> i >> j >> w;
//		G.arc[i][j] = w;
//	}
//}
//
//
//int DFS(int i) {
//	int j;
//
//	if (dp[i] != INFINITY)
//		return dp[i];
//
//	dp[i] = 0;
//	for (j = 0; j < G.numVertexes; ++j)
//		if (G.arc[i][j] != INFINITY)
//			dp[i] = max(dp[i], DFS(j) + G.arc[i][j]);
//
//	return dp[i];
//}
//
//// 邻接矩阵的深度遍历操作
//void DFSTraverse() {
//	int i;
//
//	for (i = 0; i < G.numVertexes; ++i)
//		visited[i] = 0;		/* 初始所有顶点状态都是未访问的状态 */
//
//	for (i = 0; i < G.numVertexes; ++i)
//		dp[i] = INFINITY;	/* 初始化dp数组 */
//
//	int Max = -INFINITY;
//	for (i = 0; i < G.numVertexes; ++i)
//		Max = max(Max, DFS(i));
//
//	cout << Max << endl;
//}
//
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		CreateMGraph();
//		DFSTraverse();
//	}
//	return 0;
//}

// 题解
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//const int maxn = 1000, INF = 999999999;
//int G[maxn][maxn], dp[maxn];
//int d(int);
//int T, i, j, n, m, a, b, c;
//int main() {
//    //freopen("input.txt","r",stdin);
//    for (scanf_s("%d", &T); T--;) {
//
//        for (i = 0; i < maxn; i++)
//            for (j = 0; j < maxn; j++)
//                G[i][j] = INF;
//
//        for (i = 0; i < maxn; i++) 
//            dp[i] = INF;
//
//        scanf_s("%d%d", &n, &m);
//        for (i = 0; i < m; i++) {
//            scanf_s("%d%d%d", &a, &b, &c);
//            G[a][b] = c;
//        }
//        int Max = -INF;
//        for (i = 0; i < n; i++) 
//            Max = max(Max, d(i));
//
//        printf("%d\n", Max);
//    }
//}
//int d(int x) {
//    if (dp[x] != INF) 
//        return dp[x];
//
//    dp[x] = 0;
//    for (int i = 0; i < n; i++)
//        if (G[x][i] != INF)
//            dp[x] = max(dp[x], d(i) + G[x][i]);
//    return dp[x];
//}//记忆搜索

/* 问题一：没有算法优化的迷宫问题 */
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
//	//for (i = 0; i < G->numVertexes; ++i) {
//	//	printf("输入第%d个顶点信息：", i + 1);
//	//	char ch = getchar();
//	//	scanf_s("%c", &G->vexs[i], 1);	/* 读入顶点信息， 建立顶点表 */
//	//}
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
////int DFS1(MGraph G, int i) {
////	int j;
////
////	visited[i] = TRUE;
////
////	for (j = 0; j < G.numVertexes; j++)
////		if (G.arc[i][j] != INFINITY && dp[i] == -INFINITY) {
////			dp[i] = max(G.arc[i][j], DFS(G, j) + G.arc[i][j]);
////		}
////
////	return dp[i];
////}
//
//int DFS(MGraph G, int i) {
//	int j;
//	int ans;
//
//	if (dp[i] >= 0)
//		return dp[i];
//
//	dp[i] = 0;
//	for (j = 0; j < G.numVertexes; j++)
//		if (G.arc[i][j] != INFINITY) {
//			dp[i] = max(dp[i], DFS(G, j) + G.arc[i][j]);
//		}
//	// dp[i] = dp[i];
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
//	int T;
//	cin >> T;
//	while (T--) {
//		MGraph G;
//		CreateMGraph(&G);
//		DFSTraverse(G);
//		cout << *max_element(dp, dp + G.numVertexes) << endl;
//	}
//	return 0;
//}

 

//#include<stdio.h>
//#include<malloc.h>
//
//typedef struct Node {
//	int data;
//	struct Node* next;
//}Node, *LinkList;
//
//void f(Node L) {
//	printf("%p\n", &L);
//}
//int main() {
//	Node node = {1, NULL};
//	f(node);
//	printf("%p\n", &node);
//	return 0;
//}
//#include<iostream>
//#include<malloc.h>
//using namespace std;
//
//void f(int** b) {
//	*b = (int*)malloc(sizeof(int));
//	printf("fb:%p\n", *b);
//	return;
//}
//
//void f1(int** c) {
//	*c = (int*)malloc(sizeof(int));
//	printf("%p\n", *c);
//	return;
//}
//int main01() {
//	/*int b = 10;
//	int* a;
//	
//	f(&a);
//	printf("afterf:%d %p\n", *a, a);*/
//	int* a = NULL;
//	f1(&a);
//	printf("%p", a);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//int main() {
//	char a[10];
//	scanf_s("%c", &a[0], sizeof(a));
//	fflush(stdin);
//	printf("%c", a[0]);
//	return 0;
//}