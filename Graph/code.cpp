#include <iostream>
using namespace std;

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100;
#define INFINITY 65535;

typedef struct {
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges; /* 图中当前的顶点数和边数 */
}MGraph;

int main() {


	return 0;
}