/*练习线性表链式存储结构*/
//#include<iostream>
//using namespace std;
//
//typedef int ElemType;
//typedef struct Node {
//	ElemType data;
//	Node* next;
//}Node, *LinkList;
//
//bool InitList(LinkList* L, int n) {
//	LinkList p, r;
//	int i, e;
//	*L = (LinkList)malloc(sizeof(Node));
//	if (!(*L))
//		exit(OVERFLOW);
//	(*L)->next = NULL;
//	r = *L;
//	for (i = 0; i < n; ++i) {
//		cin >> e;
//		p = (LinkList)malloc(sizeof(Node));
//		if (!p)
//			exit(OVERFLOW);
//		p->data = e;
//		r->next = p;
//		p->next = NULL;
//		r = p;
//	}
//	return true;
//}
//
//bool ListInsert(LinkList* L, int i, ElemType e) {
//	// i = 2 88		1 2 3 4 5 p:1
//	int j;
//	LinkList p, s;
//	p = *L;
//	// 寻找第i-1个结点
//	j = 1;
//	while (p && j < i) {
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i)
//		return false;
//
//	s = (LinkList)malloc(sizeof(Node));
//	if (!s)
//		exit(OVERFLOW);
//	s->data = e;
//	s->next = p->next;
//	p->next = s;
//	return true;
//}
//
//bool ListDelete(LinkList* L, int i, ElemType* e) {
//	LinkList p = *L, r;
//	int j;
//	j = 1;
//	// 寻找第i-1个结点
//	while (p && j < i) {
//		p = p->next;
//		++j;
//	}
//	// 第i个结点不存在
//	if (!p || j > i)
//		return false;
//	r = p->next;
//	*e = r->data;
//	p->next = r->next;
//	free(r);
//	return true;
//}
//
//void ListTraverse(LinkList L) {
//	LinkList p = L->next;
//	if (!p) {
//		cout << "LinkList is NULL!!!\n";
//		return;
//	}
//	while (p) {
//		cout << p->data << "\t";
//		p = p->next;
//	}
//	cout << endl;
//	return;
//}
//
//
//int main() {
//	LinkList node = NULL;
//	InitList(&node, 2);
//	ListInsert(&node, 1, 88);
//	ListTraverse(node);
//	cout << sizeof(*node) << endl;
//	ElemType e;
//	ListDelete(&node, 1, &e);
//	ListTraverse(node);
//	return 0;
//}
/*练习线性表的顺序存储结构*/
//#include<iostream>
//using namespace std;
//
//#define MAXSIZE 10
//
//typedef int ElemType;
//typedef struct {
//	ElemType data[MAXSIZE];
//	int length;
//}SqList;
//
//bool InitList(SqList* L) {
//	L->length = 0;
//	return true;
//}
//bool ListEmpty(SqList L) {
//	if (!L.length)
//		return true;
//	else
//		return false;
//}
//bool GetElem(SqList L, int i, ElemType* e) {
//	if (i < 1 || i >= L.length)
//		return false;
//	if (ListEmpty(L))
//		return false;
//	*e = L.data[i - 1];
//	return true;
//}
//bool ListInsert(SqList* L, int i, ElemType e) {
//	if (L->length == MAXSIZE)
//		return false;
//
//	if (i < 1 || i > L->length + 1)
//		return false;
//
//	if (i == L->length + 1) {
//		L->data[i - 1] = e;
//	}
//	else {
//		for (int j = L->length; j >= i; j--) {
//			L->data[j] = L->data[j - 1];
//		}
//		L->data[i - 1] = e;
//	}
//
//	L->length++;
//	return true;
//}
//bool ListDelete(SqList* L, int i, ElemType* e) {
//	if (ListEmpty(*L))
//		return false;
//	if (i < 1 || i >= L->length)
//		return false;
//
//	*e = L->data[i - 1];
//	for (int j = i - 1; j < L->length; j++)
//		L->data[j] = L->data[j + 1];
//	L->length--;
//	return true;
//}
//
//void ListTraverse(SqList L) {
//	if (ListEmpty(L))
//		cout << "List is NULL!!!\n";
//	for (int i = 0; i < L.length; ++i)
//		cout << L.data[i] << "\t";
//	cout << endl;
//}
//
//int main() {
//	SqList l;
//	InitList(&l);
//	for (int i = 1; i < 4; ++i)
//		ListInsert(&l, i, i);
//	ElemType e;
//	//GetElem(l, 2, &e);
//	//cout << e << endl;
//	//cout << ListInsert(&l, 2, 88) << endl;
//	//GetElem(l, 2, &e);
//	//cout << e << endl;
//	//cout << sizeof(l) << endl;
//	ListTraverse(l);
//	ListInsert(&l, 1, 88);
//	ListTraverse(l);
//	ListDelete(&l, 2, &e);
//	ListTraverse(l);
//	return 0;
//}
/*2023/5/11before*/
//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//struct node {
//    int next, tre;
//    node(int nn, int tt) :next(nn), tre(tt) {}//参数构造函数
//    node() {}//默认构造函数
//};
//vector<node> road[1005];
//int start[1005];
//int dp[1005];
//int dfs(int n) {
//    if (dp[n] > 0)return dp[n];
//    int ans = 0;
//
//    for (int i = 0; i < road[n].size(); i++) {
//        ans = max(ans, dfs(road[n][i].next) + road[n][i].tre);
//    }
//    dp[n] = ans;
//    return dp[n];
//}
//int main()
//{
//    int T, n, m;
//    cin >> T;
//    int a, b, c;
//    while (T--) {
//        cin >> n >> m;
//        memset(start, 0, sizeof(start));
//        memset(dp, 0, sizeof(dp));
//        for (int i = 0; i < m; i++) {
//            cin >> a >> b >> c;
//            road[a].push_back(node(b, c));
//            start[b] = 1;
//        }
//        for (int i = 0; i < n; i++) {
//            if (start[i] == 0) {
//                dfs(i);
//            }
//        }
//        cout << *max_element(dp, dp + n) << endl;//返回dp数组中最大值
//        for (int i = 0; i < n; i++)road[i].clear();//将路径清零
//    }
//}