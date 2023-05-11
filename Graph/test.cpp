/*2023/5/11*/
/*�ڽӱ�ϰ*/
#include<iostream>
//#include<stdlib.h>
using namespace std;

#define MAXVEX 10

typedef char VertexType;
typedef int EdgeType;

//// �߱���
//typedef struct EdgeNode {
//	int adjvex;		/* �ڽӵ��򣬴洢�ö����Ӧ���±� */
//	EdgeType weight;	/* ���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ */
//	struct EdgeNode* next;	/* ���� ָ����һ���ڽӵ� */
//}EdgeNode;
//
//// �������
//typedef struct VertexNode {
//	VertexType data;	/* �����򣬴洢������Ϣ */
//	EdgeNode* firstedge;	/* �߱�ͷָ�� */
//}VertexNode, AdjList[MAXVEX];
//
//typedef struct {
//	AdjList adjList;	
//	int numVertexes, numEdges;	/* ͼ�е�ǰ�������ͱ���*/
//}GraphAdjList;

// �߱���
typedef struct EdgeNode {
	int adjvex;			/* �ڽӵ��򣬴洢�ö����Ӧ���±� */
	EdgeType weight;	/* ���ϵ�Ȩֵ�����ڷ���ͼ���Բ���Ҫ */
	struct EdgeNode* next;	/* ����ָ����һ���ڽӵ� */
}EdgeNode;

// �������
typedef struct VertexNode {
	VertexType data;	/* �����򣬴洢������Ϣ */
	EdgeNode* firstedge; /* �߱�ͷָ�� */
}VertexNode, AdjList[MAXVEX];

typedef struct {
	AdjList adjList;
	int numVertexes, numEdges;
}GraphAdjList;

// ����ͼ���ڽӱ�ṹ(ͷ�巨��
void CreateALGraphHead(GraphAdjList* G) {
	int i, j, k, w;
	EdgeNode* e;

	cout << "���붥�����ͱ�����\n";
	cin >> G->numVertexes >> G->numEdges;

	// ���붥����Ϣ�����������
	for (i = 0; i < G->numVertexes; ++i) {
		cin >> G->adjList[i].data;		/* ���붥����Ϣ */
		G->adjList[i].firstedge = NULL;	/* ���߱���Ϊ�ձ� */
	}

	// �����߱�
	for (k = 0; k < G->numEdges; ++k) {
		cout << "����ߣ�vi,vj���ϵĶ�����ţ�\n";
		cin >> i >> j;

		e = (EdgeNode*)malloc(sizeof(EdgeNode));	/* ���ڴ�����ռ䣬���ɱ߱��� */
		if (!e)
			exit(-1);
		e->adjvex = j;		/* �ڽ����Ϊj */
		e->next = G->adjList[i].firstedge;	/* ��eָ��ָ��ǰ����ָ��Ľ��*/
		G->adjList[i].firstedge = e;	/* ����ǰ�����ָ��ָ��e*/
	}
}
// ����ͼ���ڽӱ�ṹ(β�巨)
void CreateALGraphTail(GraphAdjList* G) {
	int i, j, k;
	EdgeNode* e, * p;

	cout << "���붥�����ͱ�����\n";
	cin >> G->numVertexes >> G->numEdges;

	// ������������붥����Ϣ
	for (i = 0; i < G->numVertexes; ++i) {
		cin >> G->adjList[i].data;	// ���붥����Ϣ
		G->adjList[i].firstedge = NULL;	// ���߱���Ϊ�ձ�
	}

	for (k = 0; k < G->numEdges; ++k) {
		cout << "����ߣ�vi,vj)�ϵ�ֵ��";
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
// �ڽӱ��������ȵݹ��㷨
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

// �ڽӱ����ȱ�������
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
/*�ڽӾ���ϰ*/
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
//// ����������ͼ���ڽӾ����ʾ	Adjacency Matrix
//void CreateMGraph(MGraph* G) {
//	int i, j, k, w;
//	cout << "���붥�����ͱ�����\n";
//	cin >> G->numVertexes >> G->numEdges;
//
//	// ���붥����Ϣ�����������
//	for (i = 0; i < G->numVertexes; ++i) {
//		cin >> G->vexs[i];
//	}
//
//	for (i = 0; i < G->numVertexes; ++i) {
//		for (j = 0; j < G->numVertexes; ++j)
//			G->arc[i][j] = INFINITY;	/* �ڽӾ����ʼ�� */
//	}
//
//	// ����numEdges���ߣ������ڽӾ���
//	for (k = 0; k < G->numEdges; ++k) {
//		cout << "����ߣ�vi,vj���ϵ��±�i���±�j��Ȩֵw:\n";
//		cin >> i >> j >> w;
//		G->arc[i][j] = w;
//		G->arc[j][i] = G->arc[i][j];	/* ��Ϊ������ͼ�� ����Գ� */
//	}
//}
//
//int visited[MAXVEX] = { 0 };
//// �ڽӾ������ȱ����ݹ��㷨
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
//// �ڽӾ������ȱ�������
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
/*���ǲ��У������Թ�%90��*/
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
//// Dijkstra�㷨ʵ��
//typedef int Patharc[MAXVEX];			/* ���ڴ洢���·���±������ */
//typedef int ShortPathTable[MAXVEX];	/*���ڴ洢���������·����Ȩֵ�� */
//
//// Dijkstra�㷨����������G��V0���㵽���ඥ��v���·��P[v]����Ȩ����D[v]
//// P[v] ��ֵΪǰ��������±꣬D[v]��ʾv0��v�����·�����Ⱥ͡�
//void ShortestPath_Dijkstra(int v0) {
//	int v, w, k, min;
//	int status[MAXVEX];	/* status[w]=1 ��ʾ��ö���v0��vw�����·�� */
//
//	// ��ʼ������
//	for (v = 0; v < T; ++v) {
//		status[v] = 0;			/* ȫ�������ʼ��Ϊδ֪���·��״̬ */
//		D[v] = arc[v0][v]; /* ����v0�������ߵĶ������Ȩֵ */
//		P[v] = 0;			/* ��ʼ��·������PΪ0 */
//	}
//	D[v0] = 0;	/* v0��v0��·��Ϊ0 */
//	status[v0] = 1;	/* v0��v0����Ҫ��·�� */
//
//	// ��ʼ��ѭ����ÿ�����v0��ĳ��v��������·��
//	for (v = 1; v < T; ++v) {
//		min = INFINITY;		/* ��ǰ��֪��v0������������ */
//
//		// Ѱ����v0����Ķ���
//		for (w = 0; w < T; ++w) {
//			if (!status[w] && D[w] < min) {
//				k = w;
//				min = D[w]; /* w������v0������� */
//			}
//		}
//		status[k] = 1;	/* ��Ŀǰ�ҵ�������Ķ�����Ϊ1 */
//
//		// ������ǰ���·��������
//		for (w = 0; w < T; ++w) {
//			// �������v�����·������������·���ĳ��ȶ̵Ļ�
//			if (!status[w] && (min + arc[k][w] < D[w])) {
//				// ˵���ҵ��˸��̵�·�����޸�D[w]��P[w]
//				D[w] = min + arc[k][w];	/* �޸ĵ�ǰ·������ */
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
/*ԭ�ȴ��� ֻ�ܹ�10%*/
//#include<iostream>
//using namespace std;
//
//typedef char VertexType;	/*��������*/
//typedef int EdgeType;		/*���ϵ�Ȩֵ����*/
//
//#define MAXVEX 10
//#define INFINITY 99
//
//typedef struct {
//	VertexType vexs[MAXVEX];	/*�����*/
//	EdgeType arc[MAXVEX][MAXVEX];	/*�߱�*/
//	int numVertexes, numEdges;		/*ͼ�е�ǰ�������ͱ���*/
//}MGraph;
//
//// ����������ͼ���ڽӾ����ʾ
//void CreateMGraph(MGraph* G, int T, int C) {
//	int i, j, k, w;
//	//cout << "���붥�����ͱ�����\n";
//	//cin >> G->numVertexes >> G->numEdges;
//	G->numVertexes = T;
//	G->numEdges = C;
//
//	// ������������붥����Ϣ
//	/*for (i = 0; i < G->numVertexes; ++i) {
//		cin >> G->vexs[i];
//	}*/
//
//	// �ڽӾ����ʼ��
//	for (i = 0; i < G->numVertexes; ++i)
//		for (j = 0; j < G->numVertexes; ++j)
//			G->arc[i][j] = INFINITY;
//
//	// ����ߵ���Ϣ�������ڽӾ���
//	for (k = 0; k < G->numEdges; ++k) {
//		//cout << "����ߣ�vi,vj���ϵ��±�i���±�j��Ȩֵw��\n";
//		cin >> i >> j >> w;
//		G->arc[i][j] = w;
//		G->arc[j][i] = G->arc[i][j];
//	}
//}
//
//// Dijkstra�㷨ʵ��
//typedef int Patharc[MAXVEX];			/* ���ڴ洢���·���±������ */
//typedef int ShortPathTable[MAXVEX];	/*���ڴ洢���������·����Ȩֵ�� */
//
//// Dijkstra�㷨����������G��V0���㵽���ඥ��v���·��P[v]����Ȩ����D[v]
//// P[v] ��ֵΪǰ��������±꣬D[v]��ʾv0��v�����·�����Ⱥ͡�
//void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D) {
//	int v, w, k, min;
//	int status[MAXVEX];	/* status[w]=1 ��ʾ��ö���v0��vw�����·�� */
//
//	// ��ʼ������
//	for (v = 0; v < G.numVertexes; ++v) {
//		status[v] = 0;			/* ȫ�������ʼ��Ϊδ֪���·��״̬ */
//		(*D)[v] = G.arc[v0][v]; /* ����v0�������ߵĶ������Ȩֵ */
//		(*P)[v] = 0;			/* ��ʼ��·������PΪ0 */
//	}
//	(*D)[v0] = 0;	/* v0��v0��·��Ϊ0 */
//	status[v0] = 1;	/* v0��v0����Ҫ��·�� */
//
//	// ��ʼ��ѭ����ÿ�����v0��ĳ��v��������·��
//	for (v = 1; v < G.numVertexes; ++v) {
//		min = INFINITY;		/* ��ǰ��֪��v0������������ */
//
//		// Ѱ����v0����Ķ���
//		for (w = 0; w < G.numVertexes; ++w) {
//			if (!status[w] && (*D)[w] < min) {
//				k = w;
//				min = (*D)[w]; /* w������v0������� */
//			}
//		}
//		status[k] = 1;	/* ��Ŀǰ�ҵ�������Ķ�����Ϊ1 */
//
//		// ������ǰ���·��������
//		for (w = 0; w < G.numVertexes; ++w) {
//			// �������v�����·������������·���ĳ��ȶ̵Ļ�
//			if (!status[w] && (min + G.arc[k][w] < (*D)[w])) {
//				// ˵���ҵ��˸��̵�·�����޸�D[w]��P[w]
//				(*D)[w] = min + G.arc[k][w];	/* �޸ĵ�ǰ·������ */
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
/*�ڽӾ���*/
//#include<iostream>
//using namespace std;
//
//typedef char VertexType;	/* �������� */
//typedef int EdgeType;		/* ���ϵ�Ȩֵ���� */
//
//#define MAXVEX 10			/* ��󶥵��� */
//#define INFINITY 99			/* ��99������� */
//
//typedef struct {
//	VertexType vexs[MAXVEX];	/* ����� */
//	EdgeType arc[MAXVEX][MAXVEX];	/* �ڽӾ��󣬿ɿ����߱� */
//	int numVertexes, numEdges;	/* ͼ�е�ǰ�Ķ������ͱ��� */
//}MGraph;
//
//// ����������ͼ���ڽӾ����ʾ
//void CreateMGraph(MGraph* G) {
//	int i, j, k, w;
//	printf("���붥�����ͱ�����\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges); /* ���붥�����ͱ��� */
//	// ���붥����Ϣ�����������
//	for (i = 0; i < G->numVertexes; ++i) {
//		char ch = getchar();
//		scanf_s("%c", &G->vexs[i], 1);
//	}
//
//	for (i = 0; i < G->numVertexes; ++i)
//		for (j = 0; j < G->numVertexes; ++j)
//			G->arc[i][j] = INFINITY;	/* �ڽӾ����ʼ�� */
//	// ����numEdges���ߣ������ڽӾ���
//	for (k = 0; k < G->numEdges; ++k) {
//		printf("����ߣ�vi,vj���ϵ��±�i���±�j��Ȩw:\n");
//		scanf_s("%d%d%d", &i, &j, &w);	/* ����ߣ�vi,vj���ϵ�Ȩw */
//		G->arc[i][j] = w;
//		G->arc[j][i] = G->arc[i][j];	/* ��Ϊ������ͼ������Գ� */
//	}
//}
//
//typedef int Boolean;		/* Boolean�ǲ������ͣ���ֵ��TRUE��FALSE */
//Boolean visited[MAXVEX];	/* ��������ı�־ */
//#define TRUE 1
//#define FALSE 0
//
//// �ڽӾ����������ȵݹ��㷨
//void DFS(MGraph G, int i) {
//	int j;
//	visited[i] = TRUE;
//	printf("%c ", G.vexs[i]);	/* ��ӡ���㣬Ҳ�ɽ����������� */
//	for (j = 0; j < G.numVertexes; ++j) {
//		if (G.arc[i][j] != INFINITY && !visited[j])
//			DFS(G, j);	/* ��δ���ʵ��ڽӶ���ݹ���� */
//	}
//}
//
//// �ڽӾ������ȱ�������
//void DFSTraverse(MGraph G) {
//	int i;
//	for (i = 0; i < G.numVertexes; ++i)
//		visited[i] = 0;	/* ��ʼ�����ж���״̬����δ���ʹ�״̬ */
//	for (i = 0; i < G.numVertexes; ++i)
//		if (!visited[i]) /* ��δ���ʹ��Ķ������DFS��������ͨͼ��ֻ��ִ��һ�� */
//			DFS(G, i);
//
//}
//
//// Dijkstra�㷨ʵ��
//typedef int Patharc[MAXVEX];			/* ���ڴ洢���·���±������ */
//typedef int ShortPathTable[MAXVEX];	/*���ڴ洢���������·����Ȩֵ�� */
//
//// Dijkstra�㷨����������G��V0���㵽���ඥ��v���·��P[v]����Ȩ����D[v]
//// P[v] ��ֵΪǰ��������±꣬D[v]��ʾv0��v�����·�����Ⱥ͡�
////void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D) {
////	int v, w, k, min;
////	int status[MAXVEX];	/* status[w]=1 ��ʾ��ö���v0��vw�����·�� */
////
////	// ��ʼ������
////	for (v = 0; v < G.numVertexes; ++v) {
////		status[v] = 0;			/* ȫ�������ʼ��Ϊδ֪���·��״̬ */
////		(*D)[v] = G.arc[v0][v]; /* ����v0�������ߵĶ������Ȩֵ */
////		(*P)[v] = 0;			/* ��ʼ��·������PΪ0 */
////	}
////	(*D)[v0] = 0;	/* v0��v0��·��Ϊ0 */
////	status[v0] = 1;	/* v0��v0����Ҫ��·�� */
////
////	// ��ʼ��ѭ����ÿ�����v0��ĳ��v��������·��
////	for (v = 1; v < G.numVertexes; ++v) {
////		min = INFINITY;		/* ��ǰ��֪��v0������������ */
////
////		// Ѱ����v0����Ķ���
////		for (w = 0; w < G.numVertexes; ++w) {
////			if (!status[w] && (*D)[w] < min) {
////				k = w;
////				min = (*D)[w]; /* w������v0������� */
////			}
////		}
////		status[k] = 1;	/* ��Ŀǰ�ҵ�������Ķ�����Ϊ1 */
////
////		// ������ǰ���·��������
////		for (w = 0; w < G.numVertexes; ++w) {
////			// �������v�����·������������·���ĳ��ȶ̵Ļ�
////			if (!status[w] && (min + G.arc[k][w] < (*D)[w])) {
////				// ˵���ҵ��˸��̵�·�����޸�D[w]��P[w]
////				(*D)[w] = min + G.arc[k][w];	/* �޸ĵ�ǰ·������ */
////				(*P)[w] = k;
////			}
////		}
////	}
////}
//
//void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D) {
//	int i, v, k, w, min;
//	int status[MAXVEX];	/* status[w] = 1 w���������·�� */
//
//	// ��ʼ��
//	for (w = 0; w < G.numVertexes; ++w) {
//		status[w] = 0;	/* �����н�㶼����Ϊδ�ҵ�״̬ */
//		(*D)[w] = G.arc[v0][w];	/* ����0�Ľ������*/
//		(*P)[w] = 0;	/* ��·��ֵ��Ϊ0 */
//	}
//	(*D)[v0] = 0;	/*v0��v0��ȨֵΪ0*/
//	status[v0] = 1;
//
//	// ���v0��v�����·��
//	for (v = 1; v < G.numVertexes; ++v) {
//		min = INFINITY;
//
//		// �ó���v0����Ķ���
//		for (w = 0; w < G.numVertexes; ++w) {
//			if (!status[w] && (*D)[w] < min) {
//				k = w;
//				min = (*D)[w];
//			}
//		}
//		status[k] = 1;
//
//		// �޸ĸ����㵽v0�����·������
//		for (w = 0; w < G.numVertexes; ++w) {
//			// �������v��ȵ�ǰ·��С�Ļ�
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
/*Dijkstra�㷨*/
//#include<iostream>
//using namespace std;
//
//#define MAXVEX 5					/* ��󶥵��� */
//#define INFINITY 65535				/* ��65536�������� */
//
//typedef int Patharc[MAXVEX];	/* ���ڴ洢���·���±������ */
//typedef int ShortPathTable[MAXVEX]; /* ���ڴ洢���������·����Ȩֵ�� */
//typedef char VertexType;			/* �������� */
//typedef int EdgeType;				/* ���ϵ�Ȩֵ���� */
//
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
//// Dijkstra�㷨����������G��v0���㵽���ඥ��v���·��P[v]����Ȩ����D[v]
//// P[v]��ֵΪǰ�������±꣬D[v]��ʾv0��v�����·�����Ⱥ͡�
//void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D) {
//	int v, w, k = 0, min;
//	int finalt[MAXVEX];	/* final[w]=1��ʾ��ö���v0��vw�����·��*/
//	// ��ʼ������
//	for (v = 0; v < G.numVertexes; v++) {
//		finalt[v] = 0;			/* ȫ�������ʼ��Ϊδ֪���·��״̬ */
//		(*D)[v] = G.arc[v0][v];	/* ����v0�������ߵĶ������Ȩֵ */
//		(*P)[v] = 0;			/* ��ʼ��·������PΪ0 */
//	}
//	(*D)[v0] = 0;	/* V0��v0·��Ϊ0 */
//	finalt[v0] = 1;	/* v0��v0����Ҫ��·�� */
//
//	/* ��ʼ��ѭ����ÿ�����v0��ĳ��v��������·�� */
//	for (v = 1; v < G.numVertexes; ++v) {
//		min = INFINITY;	/* ��ǰ��֪��v0������������ */
//		// Ѱ����v0����Ķ���
//		for (w = 0; w < G.numVertexes; w++) {
//			if (!finalt[w] && (*D)[w] < min) {
//				k = w;
//				min = (*D)[w];	/* w������v0������� */
//			}
//		}
//		finalt[k] = 1; /* ��Ŀǰ�ҵ������������Ϊ1 */
//		// ������ǰ���·��������
//		for (w = 0; w < G.numVertexes; ++w) {
//			// �������v�����·������������·���ĳ��ȶ̵Ļ�
//			if (!finalt[w] && (min + G.arc[k][w] < (*D)[w])) {
//				// ˵���ҵ��˸��̵�·�����޸�D[w]��P[w]
//				(*D)[w] = min + G.arc[k][w]; /* �޸ĵ�ǰ·������ */
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
/*�ڽӱ���ϰ*/
//#include<iostream>
//using namespace std;
//
//#define MAXVEX 10	/*��󶥵���*/
//
//typedef char VertexType;	/*��������*/
//typedef int EdgeType;	/*���ϵ�Ȩֵ����*/
//
//// �߱���
//typedef struct EdgeNode {
//	int adjvex;	/*�ڽӵ��򣬴洢�ö����Ӧ���±�*/
//	EdgeType weight;	/*���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ*/
//	struct EdgeNode* next;	/*����ָ����һ�ڽӵ�*/
//}EdgeNode;
//
//// �������
//typedef struct VertexNode {
//	VertexType data;		/*�����򣬴洢������Ϣ*/
//	EdgeNode* firstedge;	/*�߱�ͷָ��*/
//}VertexNode, AdjList[MAXVEX];
//
//typedef struct {
//	AdjList adjList;
//	int numVertexes, numEdges;	/*ͼ�е�ǰ�������ͱ���*/
//}GraphAdjList;
//
//void CreateALGraph(GraphAdjList* G) {
//	int i, j, k;
//	EdgeNode* e;
//	printf("���붥�����ͱ�����\n");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);
//	//���붥����Ϣ�����������
//	for (i = 0; i < G->numVertexes; ++i) {
//		char ch = getchar();
//		scanf_s("%c", &G->adjList[i].data, 1);	/*���붥����Ϣ*/
//		G->adjList[i].firstedge = NULL;	/*���߱���Ϊ�ձ�*/
//	}
//
//	// �����߱�
//	for (k = 0; k < G->numEdges; ++k) {
//		printf("����ߣ�vi,vj���ϵĶ�����ţ�\n");
//		scanf_s("%d%d", &i, &j);
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));	/*���ڴ�����ռ䣬
//													���ɱ߱���*/
//		if (!e)
//			exit(OVERFLOW);
//		e->adjvex = j;	/*�ڽ����Ϊj*/
//		e->next = G->adjList[i].firstedge;	/*��e��ָ��ָ��ǰ����ָ��Ľ��*/
//		G->adjList[i].firstedge = e;	/*����ǰ�����ָ��ָ��e*/
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
//// �ڽӱ�Ĺ�ȱ����㷨
//typedef VertexNode QElemType;
//// ѭ�����е�˳��洢�ṹ
//typedef struct {
//	QElemType data[MAXVEX];
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
//	return (Q.rear - Q.front + MAXVEX) % MAXVEX;
//}
//// ������δ���������Ԫ��eΪQ�µĶ�βԪ��
//int EnQueue(SqQueue* Q, QElemType e) {
//	if ((Q->rear + 1) % MAXVEX == Q->front)	// ���������ж�
//		return 0;
//	Q->data[Q->rear] = e;	/* ��Ԫ��e��ֵ����β */
//	Q->rear = (Q->rear + 1) % MAXVEX; /* rearָ�������һλ��
//									   ���������ת������ͷ�� */
//	return 1;
//}
//// �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ
//int DeQueue(SqQueue* Q, QElemType* e) {
//	if (Q->front == Q->rear)
//		return 0;
//	*e = Q->data[Q->front];
//	Q->front = (Q->front + 1) % MAXVEX;	/* front ָ�����һλ�ã�
//											���������ת������ͷ�� */
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
/*�Թ�����*/
/*�Ľ�1����*/
//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//#define MAXVEX 1005
//
//// �߱���
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
/*�������*/
//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//struct node {
//	int next, tre;
//	node(int nn, int tt) :next(nn), tre(tt) {}//�������캯��
//	node() {}//Ĭ�Ϲ��캯��
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
//		cout << *max_element(dp, dp + n) << endl;//����dp���������ֵ
//		for (int i = 0; i < n; i++)road[i].clear();//��·������
//	}
//}
/*�ҵ�ͨ��*/
// ȱ�㣺�ڴ�ռ�ù���
//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//#define MAXVEX 1005
//
//// �߱���
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

/*����2*/
//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//#define MAXVEX 1005
//
//// �߱���
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
/*����1*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//#define MAXVEX 1005
//
//// �߱���
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
/*�ڽӱ���ϰ2*/
//#include<iostream>
//using namespace std;
//
//#define MAXVEX 10
//typedef char VertexType;
//typedef int EdgeType;
//
//// �߱���
//typedef struct EdgeNode {
//	int adjvex;
//	EdgeNode* next;
//}EdgeNode;
//
//// �������
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
/*�ڽӱ���ϰ1*/
//#include<iostream>
//using namespace std;
//
//#define MAXVEX 10	/*��󶥵���*/
//
//typedef char VertexType;
//typedef int EdgeType;
//
//// �߱���
//typedef struct EdgeNode {
//	int adjvex;	/* �ڽӵ��򣬴洢�ö�����±� */
//	EdgeType weight; /*�洢Ȩֵ*/
//	EdgeNode* next;
//}EdgeNode;
//
//// �������
//typedef struct VertexNode {
//	VertexType data;
//	EdgeNode* firstedge;	/*�߱�ͷ���*/
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
//	cout << "���붥�����ͱ�����";
//	cin >> G->numVertexes >> G->numEdges;
//	// ���붥�����Ϣ
//	for (i = 0; i < G->numVertexes; ++i) {
//		cin >> G->adjList[i].data;
//		G->adjList[i].firstedge = NULL;
//	}
//
//	for (k = 0; k < G->numEdges; ++k) {
//		cout << "����ߣ�vi,vj)�ϵ��±��Ȩֵ��\n";
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

/*�ڽӱ�ϰ*/
// exerciseAdjacencyList
//#include<iostream>
//using namespace std;
//
//#define MAXVEX 10	// ��󶥵����
//typedef char VertexType;	/*������Ϣ����*/
//typedef int EdgeType;	/*�߱��ϵ�Ȩֵ����*/
//int visited[MAXVEX] = {0};
//
////�߱���
//typedef struct EdgeNode {
//	int adjvex;	/*�ڽӵ��򣬴洢�ö����Ӧ���±�*/
//	EdgeType weigth;	/*���ڴ洢Ȩֵ*/
//	EdgeNode* next;	/*����ָ����һ�ڽӵ�*/
//}EdgeNode;
//// �������
//typedef struct VertexNode {
//	VertexType data;	/*�����򣬴�Ŷ�����Ϣ*/
//	EdgeNode* firstedge;	/*�߱�ͷָ��*/
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
//	cout << "���붥�����ͱ�����\n";
//	cin >> G->numVertexes >> G->numEdges;
//	// ���붥����Ϣ�����������
//	for (i = 0; i < G->numVertexes; ++i) {
//		cin >> G->adjList[i].data;
//		G->adjList[i].firstedge = NULL;	/*���߱���Ϊ�ձ�*/
//	}
//	
//	for (k = 0; k < G->numEdges; ++k) {
//		cout << "����ߣ�vi,vj)�ϵĶ�������Լ�Ȩֵ��\n";
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
//// �ڽӱ��������ȵݹ��㷨
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
//// �ڽӱ����ȱ�������
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
//typedef char VertexType;	/*��������*/
//typedef int EdgeType;	/*���ϵ�Ȩֵ����*/
//
//// �߱���
//typedef struct EdgeNode {
//	int adjvex;	/*�ڽӵ��򣬴洢�ö����Ӧ���±�*/
//	EdgeType weight;	/*���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ*/
//	EdgeNode* next;	/* ����ָ����һ�ڽӵ� */
//}EdgeNode;
//
//// �������
//typedef struct VertexNode {
//	VertexType data;	/*�����򣬴洢������Ϣ*/
//	EdgeNode* firstedge;	/*�߱�ͷָ��*/
//}VertexNode, AdjList[MAXVEX];
//
//typedef struct {
//	AdjList adjList;
//	int numVertexes, numEdges;	/*ͼ�е�ǰ�������ͱ���*/
//}GraphAdjList;
//
//// ����ͼ���ڽӱ�ṹ
//void CreateALGraph(GraphAdjList* G) {
//	int i, j, k;
//	EdgeNode* e;
//	cout << "���붥�����ͱ�����\n";
//	cin >> G->numVertexes >> G->numEdges;
//	for (i = 0; i < G->numVertexes; ++i) {
//		// ���붥����Ϣ�����������
//		cin >> G->adjList[i].data;	/*���붥����Ϣ*/
//		G->adjList[i].firstedge = NULL;	/*���߱���Ϊ�ձ�*/
//	}
//	// �����߱�
//	for (k = 0; k < G->numEdges; ++k) {
//		cout << "����ߣ�vi,vj���ϵĶ�����ţ�\n";
//		cin >> i >> j;
//		e = (EdgeNode*)malloc(sizeof(EdgeNode)); /*���ڴ�����ռ䣬���ɱ߱���*/
//		e->adjvex = j;	/*�ڽ����Ϊj*/
//		e->next = G->adjList[i].firstedge;	/*��eָ��ָ��ǰ����ָ��Ľ��*/
//		G->adjList[i].firstedge = e;	/*����ǰ�����ָ��ָ��e*/
//
//		e = (EdgeNode*)malloc(sizeof(EdgeNode));
//		e->adjvex = i;
//		e->next = G->adjList[j].firstedge; /*��eָ��ָ��ǰ����ָ��Ľ��*/
//		G->adjList[j].firstedge = e;/*����ǰ�����ָ��ָ��e*/
//	}
//}
//int main() {
//	GraphAdjList G;
//	CreateALGraph(&G);
//	return 0;
//}
/*���ĺ��ӱ�ʾ����ϰ*/
//#include<iostream>
//#include<vector>
//using namespace std;
//
//#define MAX_TREE_SIZE 100
//// ���ӽ��
//typedef struct CTNode {
//	int child;
//	struct CTNode* next;
//}*ChildPtr;
//// ��ͷ�ṹ
//typedef struct {
//	char data;
//	ChildPtr firstchild;
//}CTBox;
//// ���ṹ
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
//#define MAXVEX 10			/* ��󶥵��� */
//#define INFINITY 65535		/* ��65535�������� */
//#define TRUE 1
//#define FALSE 0
//
//typedef char VertexType;	/* �������� */
//typedef int EdgeType;		/* ���ϵ�ֵ���� */
//typedef int Boolean;		/* Boolean�ǲ������ͣ���ֵ��TRUE��FALSE */
//typedef struct {
//	VertexType vexs[MAXVEX];	/* ����� */
//	EdgeType arc[MAXVEX][MAXVEX];	/* �ڽӾ��󣬿ɿ����� */
//	int numVertexes, numEdges;		/* ͼ�е�ǰ�Ķ������ͱ��� */
//}MGraph;
//
//Boolean visited[MAXVEX];	/* ���ʱ�־������ */
//int dp[MAXVEX];
//
////����������ͼ���ڽӾ����ʾ
//void CreateMGraph(MGraph* G) {
//	int i, j, k, w;
//	printf("���붥�����ͱ�����");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);	/* ���붥�����ͱ��� */
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
//	for (k = 0; k < G->numEdges; k++) {
//		printf("����ߣ�vi,vj���ϵ��±�i���±�j��w��");
//		scanf_s("%d%d%d", &i, &j, &w);
//		G->arc[i][j] = w;
//		//G->arc[j][i] = G->arc[i][j];	/* ��Ϊ������ͼ������Գ� */
//	}
//}
//
//// �ڽӾ����������ȵݹ��㷨
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
//// �ڽӾ������ȱ�������
//void DFSTraverse(MGraph G) {
//	int i;
//
//	for (i = 0; i < G.numVertexes; ++i)
//		visited[i] = FALSE;		/* ��ʼ���ж���״̬����δ���ʵ�״̬ */
//
//	for (i = 0; i < G.numVertexes; ++i)
//		dp[i] = -INFINITY;	/* ��ʼ��dp���� */
//
//	for (i = 0; i < G.numVertexes; ++i)
//		if (!visited[i])	/* ��δ���ʹ��Ķ������DFS��������ͨͼ��ֻ��ִ��һ�� */
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
//typedef char VertexType;			/* �������� */
//typedef int EdgeType;				/* ���ϵ�ֵ���� */
//
//#define MAXVEX 10					/* ��󶥵��� */
//#define INFINITY 65535				/* ��65535�������� */
//
//typedef struct {
//	VertexType vexs[MAXVEX];		/* ����� */
//	EdgeType arc[MAXVEX][MAXVEX];	/* �ڽӾ��󣬿ɿ����� */
//	int numVertexes, numEdges;		/* ͼ����󶥵����ͱ��� */
//}MGraph;
//
//// ����������ͼ���ڽӾ����ʾ
//void CreateMGraph(MGraph* G) {
//	int i, j, k, w;
//	printf("���붥�����ͱ�����");
//	scanf_s("%d%d", &G->numVertexes, &G->numEdges);	/* ���붥�����ͱ��� */
//
//	for (i = 0; i < G->numVertexes; i++) {
//		printf("�����%d��������Ϣ��", i + 1);
//		char ch = getchar();
//		scanf_s("%c", &G->vexs[i], 1);	/* ���붥����Ϣ�� ��������� */
//	}
//
//	for (i = 0; i < G->numVertexes; i++)
//		for (j = 0; j < G->numVertexes; ++j)
//			G->arc[i][j] = INFINITY;	/* �ڽӾ����ʼ�� */
//
//	for (k = 0; k < G->numEdges; ++k) {
//		printf("����ߣ�vi,vj���ϵ��±�i���±�j��Ȩw��");
//		scanf_s("%d%d%d", &i, &j, &w);
//		G->arc[i][j] = w;
//		G->arc[j][i] = G->arc[i][j];	/* ��Ϊ������ͼ�� ����Գ� */
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