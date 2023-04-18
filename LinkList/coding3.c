

#include<stdio.h>
#include<string.h>
int maxn = 1005, INF = 999999999;
int G[1005][1005], dp[1005];
int d(int);
int T, i, j, n, m, a, b, c;
int main() {
    for (scanf("%d", &T); T--;) {
        for (i = 0; i < maxn; i++)
            for (j = 0; j < maxn; j++) G[i][j] = INF;
        for (i = 0; i < maxn; i++) dp[i] = INF;
        for (scanf("%d%d", &n, &m), i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            G[a][b] = c;
        }
        int Max = -INF;
        for (i = 0; i < n; i++) Max = max(Max, d(i));
        printf("%d\n", Max);
    }
}
int d(int x) {
    if (dp[x] != INF) return dp[x];
    dp[x] = 0;
    for (int i = 0; i < n; i++)
        if (G[x][i] != INF)
            dp[x] = max(dp[x], d(i) + G[x][i]);
    return dp[x];
}
/*

#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 10000007;

int t;
int n;
unsigned int x, y, z;
unsigned long long num[maxn];

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    unsigned long long c;
    c = a % b;
    while (c)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

unsigned int solve()
{
    unsigned int tt;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    tt = x;
    x = y;
    y = z;
    z = tt ^ x ^ y;
    return z;
}

bool cmp(unsigned long long a, unsigned long long b)
{
    return a > b;
}

int main()
{
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        scanf("%d%u%u%u", &n, &x, &y, &z);
        for (int i = 0; i < n; i++)
        {
            num[i] = solve();
        }
        int k = min(100, n);   ///ȡǰ100��
        nth_element(num, num + k, num + n, cmp);
        unsigned long long ans;
        ans = 0;
        for (int i = 0; i < k; i++)
        {
            //            printf("%llu\n" , num[i]);
            for (int j = i + 1; j < k; j++)
            {
                ans = max(ans, num[i] * num[j] / gcd(num[i], num[j]));
                //                 printf("%d..%d..%llu..%llu..%llu..%llu..\n" , i , j , num[i] , num[j] , num[i]*num[j]/gcd(num[i],num[j]) , ans);
            }
        }
        printf("Case #%d: %llu\n", cas, ans);

    }


    return 0;
}
*/

/*
337929
608269
1351708
64488027082
85984357633

405514
675854
1351708
1384776332
2769433858

0..1..405514..675854..137034129478..137034129478..
0..2..405514..1351708..274068258956..274068258956..
0..3..405514..1384776332..280773094747324..280773094747324..
0..4..405514..2769433858..561522100746506..561522100746506..
1..2..675854..1351708..1351708..561522100746506..
1..3..675854..1384776332..467953311543764..561522100746506..
1..4..675854..2769433858..935866475332366..935866475332366..
2..3..1351708..1384776332..467953311543764..935866475332366..
2..4..1351708..2769433858..1871732950664732..1871732950664732..
3..4..1384776332..2769433858..1917523229798924428..1917523229798924428..
*/
/*2023/3/22��ϰ�����洢����*/
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef struct Arr {
//	int* pBase;
//	int len;
//	int cnt;
//}*pArr, Arr;
//
//void init_arr(pArr p, int len);
//bool append_arr(pArr p, int val);
//bool insert_arr(pArr p, int pos, int e);
//bool is_empty(pArr p);
//bool is_full(pArr p);
//void show_arr(pArr p);
//
//int main() {
//	Arr arr;
//	init_arr(&arr, 6);
//	for (int i = 0; i <= 4; i++) {
//		append_arr(&arr, i + 1);
//	}
//	if (insert_arr(&arr, 6, 6)) {
//		printf("����Ԫ��%d�ɹ�������\n", 6);
//	}
//	else {
//		printf("����Ԫ��%dʧ�ܣ�����\n", 6);
//	}
//	
//	show_arr(&arr);
//	if (is_empty(&arr)) {
//		printf("����Ϊ�գ�����\n");
//	}
//	return 0;
//}
//
//void init_arr(pArr p, int len) {
//	p->pBase = (pArr)malloc(sizeof(int) * len);
//	if (NULL == p->pBase) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	p->len = len;
//	p->cnt = 0;
//	return;
//}
//bool insert_arr(pArr p, int pos, int e) {
//	int i;
//	if (is_full(p)) {
//		return false;
//	}
//	if (pos < 1 || pos > p->cnt + 1) {
//		return false;
//	}
//	if (pos != p->cnt + 1) {
//		for (i = p->cnt - 1; i >= pos - 1; i--) {
//			p->pBase[i + 1] = p->pBase[i];
//		}
//	}
//	p->pBase[pos - 1] = e;
//	p->cnt++;
//	return true;
//}
//bool is_empty(pArr p) {
//	if (p->cnt) {
//		return false;
//	}
//	else {
//		return true;
//	}
//}
//bool is_full(pArr p) {
//	if (p->cnt == p->len) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//bool append_arr(pArr p, int val) {
//	if (is_full(p)) {
//		printf("��������, ����ʧ�ܣ�����\n");
//		return false;
//	}
//	p->pBase[p->cnt] = val;
//	p->cnt++;
//	return true;
//}
//void show_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("����Ϊ��!!!\n");
//	}
//	else {
//		int i = 0;
//		printf("����Ԫ���ǣ�");
//		for (i = 0; i < p->cnt; i++) {
//			printf("%d\t", p->pBase[i]);
//		}
//	}
//	return;
//}


/*2023/3/15before*/
//#include<stdio.h>
//void func(int a[2]);
//void func2(PNode);
//
//typedef struct node {
//	int m;
//	int n;
//}Node, *PNode;
//
//int main() {
//	int a[2] = { 1, 2 };
//	printf("a[0] = %d, a[1] = %d\n", a[0], a[1]);
//	func(a);
//	printf("a[0] = %d, a[1] = %d\n", a[0], a[1]);
//	Node m;
//	m.m = 10;
//	m.n = 20;
//	printf("m: %d, n: %d\n", m.m, m.n);
//	func2(&m);
//	printf("m: %d, n: %d\n", m.m, m.n);
//
//	return 0;
//}
//
//void func(int a[2]) {
//	int t;
//	t = a[0];
//	a[0] = a[1];
//	a[1] = t;
//	return;
//}
//
//void func2(PNode m) {
//	int t = 0;
//	t = m->m;
//	m->m = m->n;
//	m->n = t;
//}
/*2022/11/19��ϰ*/
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef struct Arr {
//	int* pBase;
//	int len;
//	int cnt;
//}*pArr, Arr;
//
//void init_arr(pArr p, int length);
//bool append_arr(pArr p, int val);
//void show_arr(pArr p);
//
//int main() {
//	Arr arr;
//	init_arr(&arr, 6);
//	if (arr.cnt == 0) {
//		printf("����Ϊ�գ�����\n");
//	}
//	for (int i = 0; i < 7; i++) {
//		if (append_arr(&arr, i + 1)) {
//			printf("���Ԫ��%d�ɹ�������\n", i + 1);
//		}
//		else {
//			printf("���Ԫ��%dʧ�ܣ�����\n", i + 1);
//		}
//	}
//	show_arr(&arr);
//	return 0;
//}
//
//void init_arr(pArr p, int length) {
//	p->pBase = (pArr)malloc(sizeof(int) * length);
//	if (NULL == p->pBase) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	p->len = length;
//	p->cnt = 0;
//}
//bool append_arr(pArr p, int val) {
//	if (p->len > p->cnt) {
//		p->pBase[p->cnt] = val;
//		p->cnt++;
//		return true;
//	}
//	else
//		return false;
//	
//}
//void show_arr(pArr p) {
//	if (p->cnt == 0) {
//		printf("����Ϊ�գ�����\n");
//	}
//	else {
//		for (int i = 0; i < p->cnt; i++) {
//			printf("%d\t", p->pBase[i]);
//		}
//	}
//	return;
//}

/*����*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<malloc.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef struct Arr {
//	int* next;
//	int len;
//	int cnt;
//}*PList, List;
//
//void init_arr(PList p, int length);
//
//int main() {
//	// PList arr; /*����ط�*/
//	List arr; /*����*/
//	// printf("%p", arr);
//	init_arr(&arr, 5);
//	// printf("%p", *arr);
//	
//	if (arr.cnt == 0) {
//		printf("����Ϊ�գ�����\n");
//	}
//	return 0;
//}
//
//void init_arr(PList p, int length) {
//	p->next = (int*)malloc(sizeof(int) * length);
//	if (NULL == p->next) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	p->len = length;
//	p->cnt = 0;
//}
/*2022/10/19��ϰ*/
/*ʵ��һ��ȥ�ز���*/
//#include<stdio.h>
//
//#define MAXSIZE 20
//#define bool char
//#define true 1
//#define false 0
//
//typedef int ElemType;
//typedef struct {
//	ElemType data[MAXSIZE];
//	int length;
//}SqList;
//
//void InitList(SqList* L);
//bool ListEmpty(SqList* L);
//bool ListAdd(SqList* L, ElemType e);
//bool TraverseList(SqList* L);
//bool ListInsert(SqList* L, int i, ElemType e);
//void unionL(SqList* La, SqList* Lb);
//void GetElem(SqList* L, int p, ElemType* e);
//bool LocateElem(SqList* L, ElemType e);
//
//int main() {
//	SqList La, Lb;
//	InitList(&La);
//	InitList(&Lb);
//	/*La: 8, 9, 10 */
//	ListAdd(&La, 8);
//	ListAdd(&La, 10);
//	ListAdd(&La, 8);
//	ListAdd(&La, 7);
//	ListAdd(&La, 5);
//	ListAdd(&La, 9);
//	ListAdd(&La, 10);
//	ListAdd(&La, 1);
//	ListAdd(&La, 2);
//	ListAdd(&La, 8);
//	/*Lb: 1 2 3 4 5 6 7*/
//	ListAdd(&Lb, 3);
//	ListAdd(&Lb, 2);
//	ListAdd(&Lb, 3);
//	ListAdd(&Lb, 4);
//	ListAdd(&Lb, 7);
//	ListAdd(&Lb, 6);
//	ListAdd(&Lb, 5);
//	ListAdd(&Lb, 4);
//	ListAdd(&Lb, 2);
//	ListAdd(&Lb, 1);
//	ListAdd(&Lb, 3);
//
//	TraverseList(&Lb);
//	/*ListInsert(&Lb, 13, 88);
//	TraverseList(&Lb);
//	if (ListEmpty(&La))
//		printf("����Ϊ�գ�����\n");*/
//	return 0;
//}
//
//void InitList(SqList* L) {
//	L->length = 0;
//	return;
//}
//bool ListEmpty(SqList* L) {
//	if (L->length) {
//		return false;
//	}
//	else {
//		return true;
//	}
//}
//bool ListAdd(SqList* L, ElemType e) {
//	if (L->length == MAXSIZE) {
//		return false;
//	}
//	// printf("%d\n", L->length);
//	L->data[L->length] = e;
//	// printf("%d\n", L->data[L->length]);
//	L->length++;
//	return true;
//}
//bool TraverseList(SqList* L) {
//	if (!L->length) {
//		return false;
//	}
//	else {
//		for (int i = 0; i < L->length; i++) {
//			printf("%d\t", L->data[i]);
//		}
//		printf("\n");
//		return true;
//	}
//}
//bool ListInsert(SqList* L, int p, ElemType e) {
//	if (L->length == MAXSIZE) {
//		return false;
//	}
//	if (p < 1 || p > L->length + 1) {
//		return false;
//	}
//	// 1 2 3 4  2 88
//	for (int i = L->length - 1; i >= p - 1; i--) {
//		L->data[i + 1] = L->data[i];
//	}
//	L->data[p - 1] = e;
//	L->length++;
//	return true;
//}
//void unionL(SqList* La, SqList* Lb) {
//	int La_len, Lb_len, i;
//	SqList Lc;
//	InitList(&Lc);
//	ElemType e;
//	La_len = La->length;
//	Lb_len = Lb->length;
//	for (i = 1; i <= Lb_len; i++) {
//		GetElem(Lb, i, &e);
//		if (!LocateElem(&La, e))
//			ListInsert(&La, ++La_len, e);
//	}
//}
//void GetElem(SqList* L, int p, ElemType* e) {
//	*e = L->data[p - 1];
//	return;
//}
//bool LocateElem(SqList* L, ElemType e) {
//	int i, l = L->length;
//	for (i = 0; i < l; i++) {
//		if (L->data[i] == e) {
//			return true;
//			break;
//		}
//	}
//	return false;
//}
/*2022/10/14��ϰ*/
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define true 1
//#define false 0
//#define MAXSIZE 10
//
//typedef int SElemType;
//typedef struct {
//	SElemType data[MAXSIZE];
//	int top;	/*����ջ��ָ��*/
//}SqStack;
//

/*2022/10/13��ϰ*/
//˳��洢
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define true 1
//#define false 0
//#define MAXSIZE 10
//
//typedef int ElemType;
//typedef struct {
//	ElemType data[MAXSIZE];
//	int length;
//}SqList;
//
//void InitList(SqList *L);
//bool ListInsert(SqList* L, int i, ElemType e);
//bool ListDelete(SqList* L, int i, ElemType* e);
//void ListTraverse(SqList* L);
//
//
//int main() {
//	SqList node1, node;
//	InitList(&node);
//	for (int i = 1; i <= 3; i++) {
//		ListInsert(&node, i, i);
//	}
//	ListInsert(&node, 5, 88);
//	ElemType e = 0;
//	ListDelete(&node, 1, &e);
//	printf("%d\n", e);
//	ListTraverse(&node);
//	return 0;
//}
//
//void InitList(SqList* L) {
//	L->length = 0;
//}
//bool ListInsert(SqList* L, int i, ElemType e) {
//	int j;
//	if (i > L->length + 1 || i < 1)
//		return false;
//	if (L->length == MAXSIZE)
//		return false;
//	// 1 2 3 2 88
//	for (j = L->length - 1; j >= i; j--) {
//		L->data[j + 1] = L->data[j];
//	}
//	L->data[i - 1] = e;
//	L->length++;
//	return true;
//}
//bool ListDelete(SqList* L, int i, ElemType* e) {
//	if (i < 1 || i > L->length)
//		return false;
//	if (!L->length)
//		return false;
//	*e = L->data[i - 1];
//	for (int j = i - 1; j < L->length - 1; j++) {
//		L->data[j] = L->data[j + 1];
//	}
//	L->length--;
//	return true;
//}
//void ListTraverse(SqList* L) {
//	if (!L->length)
//		printf("����Ϊ�գ�����\n");
//	int i;
//	for (i = 0; i < L->length; i++) {
//		printf("%d\t", L->data[i]);
//	}
//	printf("\n");
//	return;
//}
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef int ElemType;
//typedef struct Node {
//	ElemType data;
//	struct Node* next;
//}Node, *LinkList;
//
//void CreateListHead(LinkList* L, int n);
//void CreateListTail(LinkList* L, int n);
//bool ListTraverse(LinkList* L);
//bool ListInsert(LinkList* L, int i, ElemType e);
//bool ListDelete(LinkList* L, int i, ElemType* e);
//
//int main() {
//	LinkList node;
//	CreateListTail(&node, 3);
//	ListTraverse(&node);
//	// ListInsert(&node, 2, 88);
//	ElemType e;
//	if (ListDelete(&node, 4, &e))
//		printf("�ɹ���ɾ����Ԫ��%d\n", e);
//	ListTraverse(&node);
//	return 0;
//}
//
//void CreateListHead(LinkList* L, int n) {
//	LinkList p;
//	int i;
//	*L = (LinkList)malloc(sizeof(Node));
//	(*L)->next = NULL;
//	for (i = 0; i < n; i++) {
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = i + 1;
//		p->next = (*L)->next;
//		(*L)->next = p;
//	}
//	return;
//}
//void CreateListTail(LinkList* L, int n) {
//	LinkList p, r;
//	int i;
//	(*L) = (LinkList)malloc(sizeof(Node));
//	r = *L;
//	for (i = 0; i < n; i++) {
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = i + 1;
//		r->next = p;
//		r = p;
//	}
//	r->next = NULL;
//	return;
//}
//bool ListTraverse(LinkList* L) {
//	LinkList p = (*L)->next;
//	if (!p) {
//		printf("����Ϊ�գ�����");
//		return false;
//	}
//	while (p) {
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	printf("\n");
//	return true;
//}
//bool ListInsert(LinkList* L, int i, ElemType e) {
//	LinkList p = (*L), s;
//	int j = 1;
//	// 1 2 3 4 5  j:2 p:1 i 2
//	while (j < i && p) {
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i) {
//		return false;
//	}
//	s = (LinkList)malloc(sizeof(Node));
//	s->data = e;
//	s->next = p->next;
//	p->next = s;
//	return;
//}
//bool ListDelete(LinkList* L, int i, ElemType* e) {
//	LinkList p = *L, q;
//	int j = 1;
//	// 1 2 3 j:4 p: 3 i:4  q
//	while (j < i && p->next) {
//		p = p->next;
//		++j;
//	}
//	if (!p->next || j > i) {
//		return false;
//	}
//	q = p->next;
//	*e = q->data;
//	p->next = q->next;
//	free(q);
//	return true;
//}
/*2022/10/12��ϰ*/
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define false 0
//#define true 1
//
//typedef struct Node {
//	int data;
//	struct Node* next;
//}Node, *LinkList;
//
//void CreateListTail(LinkList* L, int n);
//void ListTraverse(LinkList* L);
//bool ListInsert(LinkList* L, int i, int e);
//int main() {
//	LinkList node;
//	CreateListTail(&node, 5);
//	ListTraverse(&node);
//	ListInsert(&node, 2, 88);
//	ListTraverse(&node);
//	return 0;
//}
//void CreateListTail(LinkList* L, int n) {
//	LinkList p, r;
//	int i;
//	*L = (LinkList)malloc(sizeof(Node));
//	r = *L;
//	for (i = 0; i < n; i++) {
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = i + 1;
//		r->next = p;
//		r = p;
//	}
//	r->next = NULL;
//	return;
//}
//void ListTraverse(LinkList* L) {
//	LinkList p = (*L)->next;
//	if (!p) {
//		printf("����Ϊ�գ�����");
//	}
//	while (p) {
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	printf("\n");
//	return;
//}
//bool ListInsert(LinkList* L, int i, int e) {
//	LinkList p = *L, s;
//	int j = 1;
//	while (j < i && p) {
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i) {
//		return false;
//	}
//	s = (LinkList)malloc(sizeof(Node));
//	s->data = e;
//	s->next = p->next;
//	p->next = s;
//	return true;
//}
/*2022/10/11��ϰ*/
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef int ElemType;
//typedef struct Node {
//	ElemType data;
//	struct Node* next;
//}Node, *LinkList;
//
//void CreateListHead(LinkList* L, int n);
//void CreateListTail(LinkList* L, int n);
//void ListTraverse(LinkList* L);
//
//int main() {
//	LinkList node, node1;
//	CreateListHead(&node, 5);
//	ListTraverse(&node);
//	CreateListTail(&node1, 5);
//	ListTraverse(&node1);
//	return 0;
//}
//
//void CreateListHead(LinkList* L, int n) {
//	LinkList p;
//	int i;
//	(*L) = (LinkList)malloc(sizeof(Node));
//	(*L)->next = NULL;
//	for (i = 0; i < n; i++) {
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = i + 1;
//		p->next = (*L)->next;
//		(*L)->next = p;
//	}
//	return;
//}
//void CreateListTail(LinkList* L, int n) {
//	LinkList p, r;
//	int i;
//	(*L) = (LinkList)malloc(sizeof(Node));
//	r = (*L);
//	for (i = 0; i < n; i++) {
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = i + 1;
//		r->next = p;
//		r = p;
//	}
//	r->next = NULL;
//}
//void ListTraverse(LinkList* L) {
//	LinkList p = (*L)->next;
//	if (p == NULL) {
//		printf("����Ϊ�գ�����");
//	}
//	while (p) {
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	printf("\n");
//	return;
//}
/*2022/10/10��ϰ*/
//#include<stdio.h>
//#include<malloc.h>
//
//int main() {
//	int* a = NULL;
//	a = (int*)malloc(sizeof(int));
//	if (!a) {
//		printf("Hello\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define false 0
//#define true 1
//
//typedef int ElemType;
//typedef struct Node {
//	ElemType data;
//	struct Node* next;
//}*LinkList, Node;
//
//void CreateListHead(LinkList* L, int n);
//void TraverseList(LinkList L);
//void CreateListTail(LinkList* L, int n);
//bool ListInsert(LinkList* L, int i, ElemType e);
//bool ListDelete(LinkList* L, int i, ElemType* e);
//
//int main() {
//	LinkList node = NULL, node1 = NULL;
//	CreateListHead(&node, 5);
//	TraverseList(node);
//	CreateListTail(&node1, 5);
//	TraverseList(node1);
//	// ListInsert(&node1, 1, 88);
//	ElemType e;
//	if (ListDelete(&node1, 6, &e)) {
//		printf("ɾ��%dԪ�سɹ�!!!\n", e);
//	}
//
//	TraverseList(node1);
//	return 0;
//}
//
//void CreateListHead(LinkList* L, int n) {
//	LinkList p;
//	int i;
//	(*L) = (LinkList)malloc(sizeof(Node));
//	(*L)->next = NULL;
//	for (i = 0; i < n; i++) {
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = i + 1;
//		p->next = (*L)->next;
//		(*L)->next = p;
//	}
//	return;
//}
//void TraverseList(LinkList L) {
//	LinkList p = L->next;
//	if (p == NULL) {
//		printf("����Ϊ�գ�����\n");
//	}
//	while (p != NULL) {
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	printf("\n");
//	return;
//}
//void CreateListTail(LinkList* L, int n) {
//	LinkList p, r;
//	int i;
//	*L = (LinkList)malloc(sizeof(Node));
//	r = *L;
//	for (i = 0; i < n; i++) {
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = i + 1;
//		r->next = p;
//		r = p;
//	}
//	r->next = NULL;
//	return;
//}
//bool ListInsert(LinkList* L, int i, ElemType e) {
//	LinkList p = *L, s;
//	int j = 1;
//	while (j < i && p) {
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i) {
//		return false;
//	}
//	s = (LinkList)malloc(sizeof(Node));
//	s->data = e;
//	s->next = p->next;
//	p->next = s;
//	return true;
//}
//bool ListDelete(LinkList* L, int i, ElemType* e) {
//	LinkList p = *L, q;
//	int j = 1;
//	while (j < i && p->next) {	/*����Ѱ�ҵ�i-1�����*/
//		p = p->next;
//		++j;
//	}
//	if (!p->next || j > i) {
//		return false;	/*��i����㲻����*/
//	}
//	q = p->next;
//	p->next = q->next;	/*��q�ĺ�̸�ֵ��p�ĺ��*/
//	*e = q->data;		/*��q����е����ݸ�e*/
//	free(q);			/*��ϵͳ���մ˽�㣬�ͷ��ڴ�*/
//	return true;
//}
/*2022/10/9��ϰ*/
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define false 0
//#define true 1
//
//typedef int ElemType;
//typedef struct Node {
//	ElemType data;
//	struct Node* next;
//}Node, *LinkList;
//
//void CreateListHead(LinkList* L, int n);
//void CreateListTail(LinkList* L, int n);
//void TraverseList(LinkList L);
//
//int main() {
//	LinkList node = NULL, node1 = NULL;
//	CreateListTail(&node, 6);
//	TraverseList(node);
//	/*if (node->next == NULL) {
//		printf("����Ϊ�գ�����\n");
//	}
//	CreateListTail(&node1, 2);
//	if (node1->next == NULL) {
//		printf("����Ϊ�գ�����\n");
//	}*/
//	return 0;
//}
//
//void CreateListHead(LinkList* L, int n) {
//	/*1. ����һָ��p�ͼ���������i;*/
//	LinkList p;
//	int i;
//	/*2. ��ʼ��һ������L;*/
//	(*L) = (LinkList)malloc(sizeof(Node));
//	/*3. ��L��ͷ����ָ��ָ��NULL, ������һ����ͷ���ĵ�����;*/
//	(*L)->next = NULL;
//	/*4. ѭ����*/
//	for (i = 0; i < n; i++) {
//		/*1������һ�½ڵ�ָ��p;*/
//		p = (LinkList)malloc(sizeof(Node));
//		/*2) ����һ���ָ�ֵ��p��������p->data*/
//		p->data = i + 1;
//		/*3����p���뵽ͷ�����ǰһ�½��֮�䣻*/
//		p->next = (*L)->next;
//		(*L)->next = p;
//	}
//	return;
//}
//void TraverseList(LinkList L) {
//	if (L->next == NULL) {
//		printf("����Ϊ�գ�����\n");
//	}
//	LinkList p = L->next;
//	while (p != NULL) {
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	printf("\n");
//	return;
//}
//void CreateListTail(LinkList* L, int n) {
//	/*1. ����ָ��p,r�ͼ���������i;*/
//	LinkList p, r;
//	int i;
//	/*2. ��ʼ��һ������L*/
//	(*L) = (LinkList)malloc(sizeof(Node));
//	/*3. rΪָ��β�����½���*/
//	r = *L; 
//	/*4. ѭ��*/
//	for (i = 0; i < n; i++) {
//		/*1) ����һ�½��p;*/
//		p = (LinkList)malloc(sizeof(Node));
//		/*2) ����һ���ָ�ֵ��p�������� p->data;*/
//		p->data = i + 1;
//		/*3) ����β�ն˽���ָ��ָ���½�㣻*/
//		r->next = p;
//		/*4) ����ǰ���½�㶨��Ϊ��β�ն˽�㣻*/
//		r = p;
//	}
//	r->next = NULL; /*��ʾ��ǰ���������*/
//}
//void CreateListTail(LinkList* L, int n) {
//	/*1. ����ָ��p, r �ͼ���������i;*/
//	LinkList p, r;
//	int i;
//	/*2. ��ʼ��һ����L;*/
//	(*L) = (LinkList)malloc(sizeof(Node));
//	/*3. rΪָ��β�����½��;*/
//	r = *L;
//	/*4. ѭ��*/
//	for (i = 0; i < n; i++) {
//		/*1) ����һ�½��p;*/
//		p = (LinkList)malloc(sizeof(Node));
//		/*2) ����һ���ָ�ֵ��p��������p->data;*/
//		p->data = i + 1;
//		/*3) ����β�ն˽���ָ��ָ���½��;*/
//		r->next = p;
//		/*4) ����ǰ���½�㶨��Ϊ��β�ն˽��*/
//		r = p;
//	}
//	/*5. ��r��ָ��ָ��NULL, ��ʾ��ǰ���������*/
//	r->next = NULL;
//	return;
//}
/*2022/10/2��ϰ*/
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define false 0
//#define true 1
//
//typedef int ElemType;
//typedef struct Node {
//	ElemType data;
//	struct Node* next;
//}Node, *LinkList;
//
//void CreateListHead(LinkList* L, int n);
//
//int main() {
//
//	return 0;
//}
//
//void CreateListHead(LinkList* L, int n) {
//	/*1. ����һָ��p�ͼ���������i*/
//	LinkList p;
//	int i;
//	/*2. ��ʼ��һ������L*/
//	(*L) = (LinkList)malloc(sizeof(Node));
//	/*3. ��L��ͷ����ָ��ָ��NULl��������һ����ͷ���ĵ�����*/
//	(*L)->next = NULL;
//	/*4. ѭ�� */
//	for (i = 0; i < n; i++) {
//		/*1�� ����һ�½�㸳ֵ��p */
//		p = (LinkList)malloc(sizeof(Node));
//		/*2�� �������һ���ָ�ֵ��p��������p->data */
//		p->data = i + 1;
//		p->next = (*L)->next;
//		(*L)->next = p;
//	}
//	return;
//}
/*2022/9/30��ϰ*/
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define false 0
//#define true 1
//
//typedef int ElemType;
//typedef struct Node {
//	ElemType data;
//	struct Node* next;
//}*LinkList;
//
//void CreateListHead(LinkList* L, int n);
//
//int main() {
//
//
//	return 0;
//}
//
//void CreateListHead(LinkList* L, int n) {
//	/* 1. ����һָ��p�ͼ���������i */
//	LinkList p;
//	int i;
//	/* 2. ��ʼ��һ������L*/
//}
/*2022/9/27��ϰ*/
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef int ElemType;
///*���Ա�ĵ�����洢�ṹ*/
//typedef struct Node {
//	ElemType data;
//	struct Node* next;
//} Node, *LinkList;
//
//void CreateListHead(LinkList* L, int n);
//bool ListEmpty(LinkList* L);
//
//int main() {
//	LinkList L = NULL;
//	CreateListHead(&L, 5);
//	// if (ListEmpty(L))
//	//	printf("����Ϊ�գ�����\n");
//	return 0;
//}
//
///* �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L(ͷ�巨) */
//void CreateListHead(LinkList* L, int n) {
//	/////* 1. ����һָ��p�ͼ���������i */
//	////LinkList p;
//	////int i;
//	////srand(time(0));		/*��ʼ�����������*/
//	/////* 2. ��ʼ��һ������ */
//	////*L = (LinkList)malloc(sizeof(Node));
//	/////* 3. ��L��ͷ����ָ��ָ��NULL��������һ����ͷ���ĵ����� */
//	////(*L)->next = NULL;	/*�Ƚ���һ����ͷ���ĵ����� */
//	/////* 4. ѭ��: */
//	////for (i = 0; i < n; i++) {
//	////	/*1) ����һ���½�㸳ֵ��p; */
//	////	p = (LinkList)malloc(sizeof(Node));
//	////	/* 2) �������һ�����ָ�ֵ��p��������p->data; */
//	////	// p->data = rand() % 100 + 1;
//	////	p->data = i + 1;
//	////	/* 3) ��p���뵽ͷ�����ǰһ�½��֮�䡣*/
//	////	p->next = (*L)->next;
//	////	(*L)->next = p;
//	////}
//	/*1. ����һָ��p�ͼ���������i */
//	LinkList p;
//	int i;
//	srand(time(0));		/*�������������*/
//	/*2. ��ʼ��һ������L*/
//	(*L) = (LinkList)malloc(sizeof(Node));
//	/*3. ��L��ͷ����ָ��ָ��NULl, ������һ����ͷ���ĵ�����*/
//	(*L)->next = NULL;
//	/*4. ѭ����*/
//	for (i = 0; i < n; i++) {
//		/*1)����һ�½�㸳ֵ��p;*/
//		p = (LinkList)malloc(sizeof(Node));
//		/*2)�������һ���ָ�ֵ��p��������p->data;*/
//		// p->data = rand() % 100 + 1;
//		// printf("%d\n", i + 1);
//		p->data = i + 1;
//		/*3)��p���뵽ͷ�����ǰһ�½��֮�䡣*/
//		p->next = (*L)->next;
//		(*L)->next = p;
//	}
//	return;
//}
//bool ListEmpty(LinkList L) {
//	if (L->next == NULL) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
/*2022/9/26��ϰ*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<malloc.h>
//
//#define bool char
//#define false 0
//#define true 1
//#define MAXSIZE 10
//
//typedef int ElemType;
//typedef struct {
//	ElemType data[MAXSIZE];
//	int length;
//}SqList;
//
//void InitList(SqList* L);
//bool ListInsert(SqList* L, int i, ElemType e);
//bool ListDelete(SqList* L, int i, ElemType* e);
//void ListTraverse(SqList* L);
//
//int main() {
//	SqList L;
//	InitList(&L);
//	for (int k = 1; k < 10; k++) {
//		ListInsert(&L, k, k);
//	}
//	ListTraverse(&L);
//	ElemType e;
//	ListDelete(&L, 2, &e);
//	ListDelete(&L, 7, &e);
//	ListTraverse(&L);
//	return 0;
//}
//
//void InitList(SqList* L) {
//	L->length = 0;
//}
//bool ListInsert(SqList* L, int i, ElemType e) {
//	/* 1. �������λ�ò��������׳��쳣 */
//	if (i < 1 || i > L->length + 1) {
//		return false;
//	}
//	/* 2. ������Ա��ȴ��ڵ������鳤�ȣ����׳��쳣��̬�������� */
//	if (L->length >= MAXSIZE) {
//		return false;
//	}
//	/* 3. �����һ��Ԫ�ؿ�ʼ��ǰ��������i��λ�ã��ֱ���������ƶ�һ��λ�� */
//	for (int k = L->length - 1; k > i - 2; k--) {
//		L->data[k + 1] = L->data[k];
//	}
//	/* 4. �Ѳ���Ԫ������λ��i�� */
//	L->data[i - 1] = e;
//	/* ���Ա��ȼ�1 */
//	L->length++;
//	return true;
//}
//void ListTraverse(SqList* L) {
//	if (L->length != 0) {
//		for (int k = 0; k < L->length; k++) {
//			printf("%d\t", L->data[k]);
//		}
//		printf("\n");
//	}
//	else {
//		printf("���Ա�Ϊ�գ�����");
//	}
//	return;
//}
//bool ListDelete(SqList* L, int i, ElemType* e) {
//	/* ���ɾ��λ�ò����� ���׳��쳣 */
//	if (i < 1 || i > L->length) {
//		return false;
//	}
//	/* ȡ��ɾ��Ԫ�� */
//	*e = L->data[i - 1];
//	/* ��ɾ��Ԫ��λ�ÿ�ʼ���������һ��Ԫ��λ�ã��ֱ����Ƕ���ǰ�ƶ�һ��λ�� */
//	for (int k = i - 1; k < L->length; k++) {
//		L->data[k] = L->data[k + 1];
//	}
//	/* ����1 */
//	L->length--;
//	return true;
//}

/*2022/9/25��ϰ*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<assert.h>
//#include<Windows.h>
//
//int main(int argc, char* argv[]) {
//	if (argc != 2) {
//		fprintf(stdout, "usage: cpu<string>\n");
//	}
//	/*stderr���������Ļ��stdout������������ļ�*/
//
//	char* str = argv[1];
//	while (1) {
//		Sleep(1);
//		printf("%s\n", str);
//	}
//	return 0;
//}


/*2022/9/24��ϰ*/
//#include<stdio.h>
//#include<malloc.h>
//
//#define bool char
//#define true 1
//#define false 0
//#define MAXSIZE 10
//
//typedef int ElemType;
//typedef struct {
//	ElemType data[MAXSIZE];
//	int length;
//}SqList;
//
//void InitList(SqList* L);
//bool ListInsert(SqList* L, int i, ElemType e);
//
//int main() {
//
//	return 0;
//}
//
//void InitList(SqList* L) {
//	L->length = 0;
//	return;
//}
//bool ListInsert(SqList* L, int i, ElemType e) {
//	/* 1. �������λ�ò��������׳��쳣 */
//}
/*2022/9/23��ϰ*/
//# include<stdio.h>
//# include<malloc.h>
//# include<stdlib.h>
//
//# define bool char
//# define true 1
//# define false 0
//# define MAXSIZE 10	/*�洢�ռ��ʼ������*/
//
//typedef int ElemType;	/**/
//typedef struct {
//	ElemType data[MAXSIZE];	/* ����洢����Ԫ�أ����ֵΪMAXSIZE */
//	int length;	/*���Ա�ǰ����*/
//}SqList;
//
//void InitList(SqList* L);
//bool ListEmpty(SqList L);
//bool ListInsert(SqList* L, int i, ElemType e);
//bool ListDelete(SqList* L, int i, ElemType* e);
//void ListTraverse(SqList* L);
//
//int main() {
//	SqList L;
//	int e;
//	InitList(&L);
//	/*for (int k = 0; k < 5; k++) {
//		ListInsert(&L, k + 1, k + 1);
//	}*/
//	ListInsert(&L, 1, 1);
//	ListInsert(&L, 2, 2);
//	ListInsert(&L, 2, 88);
//	ListDelete(&L, 2, &e);
//	ListTraverse(&L);
//	// if (ListEmpty(L))
//	//	printf("����Ϊ�գ�����\n");
//
//	return 0;
//}
//
//void InitList(SqList* L) {
//	L->length = 0;
//	return;
//}
//bool ListEmpty(SqList L) {
//	if (L.length == 0) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//bool ListInsert(SqList* L, int i, ElemType e) {
//	int k;
//	/* 1. �������λ�ò����� ���׳��쳣 */
//	if (i < 1 || i > L->length + 1) {
//		return false;
//	}
//	/* 2. ������Ա��ȴ��ڵ������鳤�ȣ����׳��쳣��̬�������� */
//	if (L->length >= MAXSIZE) {
//		return false;
//	}
//	/* 3. �����һ��Ԫ�ؿ�ʼ��ǰ��������i��λ�ã��ֱ����Ƕ�����ƶ�һ��λ��*/
//	// k = 1 i = 2
//	for (k = L->length - 1; k >= i - 1; k--) {
//		L->data[k + 1] = L->data[k];
//	}
//	/* 4. ������Ԫ������λ��i�� */
//	L->data[i - 1] = e;
//	/* 5. ����1 */
//	L->length++;
//	return;
//}
//void ListTraverse(SqList* L) {
//	int k;
//	for (k = 0; k < L->length; k++) {
//		printf("%d\t", L->data[k]);
//	}
//	printf("\n");
//	return;
//}
//bool ListDelete(SqList* L, int i, ElemType* e) {
//	/* 1. ���ɾ��λ�ò��������׳��쳣 */
//	if (i < 1 || i > L->length) {
//		return false;
//	}
//	/* 2. ������Ա�Ϊ�գ����׳��쳣 */
//	if (ListEmpty(*L)) {
//		return false;
//	}
//	/* 3. ��Ҫɾ��Ԫ������e */
//	*e = L->data[i - 1];
//	/* 4. ��ɾ��Ԫ��λ�ÿ�ʼ�����������һ��Ԫ�ص�λ�ã��ֱ����Ƕ���ǰ�ƶ�һ��λ��*/
//	for (int k = i - 1; k < L->length; k++) {
//		L->data[k] = L->data[k + 1];
//	}
//	/* 5. ����1 */
//	L->length--;
//}

/*2022/9/21��ϰ*/
//# include<stdio.h>
//# include<malloc.h>
//# include<stdlib.h>
//
//# define bool char
//# define true 1
//# define false 0
//# define maxsize 10
//
//typedef int elemtype;
//typedef struct {
//	elemtype data[maxsize];
//	int length;	/*���Ա�ǰ����*/
//
//}sqlist;
//
//void initlist(sqlist* l);
//bool listinsert(sqlist* l, int i, elemtype e);
//bool listinsert01(sqlist* l, int i, elemtype e);
//void listtraverse(sqlist* l);
//
//int main() {
//	sqlist l;
//	initlist(&l);
//	int i = 0;
//	for (i = 0; i < 5; i++) {
//		listinsert(&l, i + 1, i + 1);
//	}
//	listinsert(&l, 6, 88);
//	listtraverse(&l);
//	return 0;
//}
//
//void initlist(sqlist* l) {
//	l->length = 0;
//}
//bool listinsert01(sqlist* l, int i, elemtype e) {
//	int k;
//	/*�������λ�ò������׳��쳣*/
//	if (i < 1 || i > l->length + 1)
//		return false;
//	/*������Ա��ȴ��ڻ�������鳤�ȣ����׳��쳣��̬��������*/
//	if (l->length >= maxsize) {
//		return false;
//	}
//	/*�����һ��Ԫ�ؿ�ʼ��������i��λ�ã��ֱ𶼽���������ƶ�һ��λ��*/
//	for (k = l->length - 1; k >= i - 1; k--) {
//		l->data[i + 1] = l->data[i];
//	}
//	/*��Ҫ����Ԫ������λ��i��*/
//	l->data[i - 1] = e;
//	/*����1*/
//	l->length++;
//	return true;
//}
//
//bool listinsert(sqlist* l, int i, elemtype e) {
//	int k;
//	/*�������λ�ò������׳��쳣*/
//	if (i < 1 || i > l->length + 1) {
//		return false;
//	}
//	/*������Ա��ȴ��ڵ������鳤�ȣ����׳��쳣��̬��������*/
//	if (l->length >= maxsize) {
//		return false;
//	}
//	/*�����һ��Ԫ�ؿ�ʼ��ǰ��������i��λ�ã��ֱ����Ƕ�����ƶ�һ��λ��*/
//	for (k = l->length - 1; k >= i - 1; k--) {
//		l->data[k + 1] = l->data[k];
//	}
//	/*��Ҫ����Ԫ������λ��i��*/
//	l->data[i - 1] = e;
//	/*����1*/
//	l->length++;
//	return;
//}
//void listtraverse(sqlist* l) {
//	if (l->length == 0) {
//		printf("����Ϊ�գ�����\n");
//	}
//	else {
//		int k;
//		for (k = 0; k < l->length; k++) {
//			printf("%d\t", l->data[k]);
//		}
//		printf("\n");
//	}
//	return;
//}

/*��ϰ*/
//#include <stdio.h>
//#include <malloc.h>
//#include <stdlib.h>
//
//struct node {
//	int data;	/*a data item*/
//	struct node* next; /*an address of another node*/
//};
//
//int main() {
//	/*initialize node*/
//	struct node* head = NULL;
//	struct node* one = NULL;
//	struct node* two = NULL;
//	struct node* three = NULL;
//
//	/*Allocate memory*/
//	head = (struct node*)malloc(sizeof(struct node));
//	if (head == NULL) {
//		exit(-1);
//	}
//	one = (struct node*)malloc(sizeof(struct node));
//	if (one == NULL) {
//		exit(-1);
//	}
//	two = (struct node*)malloc(sizeof(struct node));
//	if (two == NULL) {
//		exit(-1);
//	}
//	three = (struct node*)malloc(sizeof(struct node));
//	if (three == NULL) {
//		exit(-1);
//	}
//
//	/*Assign data values*/
//	one->data = 1;
//	two->data = 2;
//	three->data = 3;
//	/*Connect nodes */
//	one->next = two;
//	two->next = three;
//	three->next = NULL;
//
//	/* Save address of first node in head */
//	head->next = one;
//
//	/* If you wanted to put an element 4
//	between 1 and 2, the steps would be:*/
//	
//	/*step1��create a new struct node and 
//	allocate memory to it*/
//	struct node* new_node = (struct node*)malloc(sizeof(struct node));
//	if (new_node == NULL) {
//		exit(-1);
//	}
//	/*step2: Add its data value as 4 */
//	new_node->data = 4;
//	/*step3: Point its next pointer to the struct node containing 2 
//	as the data value*/
//	new_node->next = two;
//	/*step4: Change the next pointer of "1" 
//	to the node we just created*/
//	one->next = new_node;
//
//	/*If you wanted to put an element 88 between 2 and 3, the steps
//	would be:*/
//	/* Step1: Create a new struct node and allocate memory to it*/
//	struct node* new2_node = (struct node*)malloc(sizeof(struct node));
//	if (new2_node == NULL) {
//		exit(-1);
//	}
//	/* Step2: Add its data value as 88*/
//	new2_node->data = 88;
//	/* Step3: Point the(its) next pointer 
//	to the struct node containing 3 as the data value*/
//	new2_node->next = three;
//	/* Step4: Change the next pointer of "2" to the node 
//	we just created*/
//	two->next = new2_node;
//
//	struct node* p;
//	p = head->next;
//	while (p != NULL) {
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef struct arr {
//	int* pBase;
//	int len;
//	int cnt;
//}*pArr, Arr;
//
//void init_arr(pArr p, int len);
//void show_arr(pArr p);
//bool is_empty(pArr p);
//bool is_full(pArr p);
//bool append_arr(pArr p, int val);
//bool insert_arr(pArr p, int pos, int val);
//
//int main() {
//	Arr arr;
//
//	init_arr(&arr, 6);
//	for (int i = 0; i <= 4; i++) {
//		if (append_arr(&arr, i + 1)) {
//			printf("%dԪ��׷�ӳɹ�������\n", i + 1);
//		}
//		else {
//			printf("%dԪ��׷��ʧ�ܣ�����\n", i + 1);
//		}
//	}
//	printf("����ǰ��");
//	show_arr(&arr);
//	if (insert_arr(&arr, 2, 88)) /*��ֵ88����λ��2*/
//		printf("λ��%d������ֵ%d�ɹ�������\n", 2, 88);
//	else
//		printf("λ��%d������ֵ%dʧ�ܣ�����\n", 2, 88);
//	printf("�����");
//	show_arr(&arr); /*������������Ԫ��*/
//
//	/*show_arr(&arr);
//	if (is_empty(&arr))
//		printf("Ԫ��Ϊ�գ�����\n");*/
//	return 0;
//}
//
//void init_arr(pArr p, int len) {
//	p->pBase = (pArr)malloc(sizeof(int) * len);
//	if (p->pBase == NULL) {
//		printf("��̬�ڴ����ʧ�ܣ�����");
//		exit(-1);
//	}
//	p->len = len;
//	p->cnt = 0;
//	return;
//}
//void show_arr(pArr p) {
//	int i;
//	if (is_empty(p)) {
//		printf("����Ϊ�գ�����\n");
//	}
//	else {
//		for (i = 0; i < p->cnt; i++)
//			printf("%d\t", p->pBase[i]);
//	}
//	printf("\n");
//	return;
//}
//bool is_empty(pArr p) {
//	if (p->cnt == 0)
//		return true;
//	else
//		return false;
//}
//bool is_full(pArr p) {
//	if (p->cnt == p->len)
//		return true;
//	else
//		return false;
//}
//bool append_arr(pArr p, int val) {
//	if (is_full(p)) {
//		printf("��������������\n");
//		return false;
//	}
//	else {
//		p->pBase[p->cnt] = val;
//		p->cnt++;
//	}
//	return true;
//}
//bool insert_arr(pArr p, int pos, int val) {
//	if (is_full(p)) {
//		printf("�������������ɲ��룡����\n");
//		return false;
//	}
//	if (pos < 1 || pos > 6) {
//		printf("����λ�ô���\n");
//		return false;
//	}
//	// 1 2 3 4 5  88 2
//	int i;
//	for (i = p->cnt - 1; i >= pos - 1; i--) {
//		printf("%d, %d\n", i, p->pBase[i]);
//		p->pBase[i + 1] = p->pBase[i];
//	}
//	p->pBase[pos - 1] = val;
//	p->cnt++;
//	return true;
//}
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef struct arr {
//	int* pBase;
//	int len;
//	int cnt;
//}*pArr, Arr;
//
//void init_arr(pArr p, int len);
//bool append_arr(pArr p, int val);
//bool travese_arr(pArr p);
//bool insert_arr(pArr p, int pos, int val);
//bool delete_arr(pArr p, int pos, int* val);
//bool is_empty(pArr p);
//bool is_full(pArr p);
//
//int main() {
//	Arr arr;
//	init_arr(&arr, 6);
//	// ��������
//	for (int i = 0; i <= 3; i++) {
//		if (append_arr(&arr, i + 1)) {
//			printf("���Ԫ��%d�ɹ�������\n", i + 1);
//		}
//		else
//			printf("���Ԫ��%dʧ�ܣ�����\n", i + 1);
//	}
//	
//	printf("����ǰ��\n");
//	travese_arr(&arr);
//	printf("�����\n");
//	if (insert_arr(&arr, 2, 88))
//		;
//	else
//		printf("����ʧ�ܣ�����\n");
//	travese_arr(&arr);
//	
//	int val;
//	printf("ɾ��ǰ��\n");
//	travese_arr(&arr);
//	printf("ɾ����\n");
//	if (delete_arr(&arr, 2, &val))
//		printf("�ɹ���ɾ��ֵ��%d\n", val);
//	else
//		printf("ɾ��ʧ�ܣ�����\n");
//	travese_arr(&arr);
//
//	if (is_empty(&arr)) {
//		printf("����Ϊ�գ�����\n");
//	}
//	return 0;
//}
//
//void init_arr(pArr p, int len) {
//	p->pBase = (pArr)malloc(sizeof(int) * len);
//	if (p->pBase == NULL) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	p->len = len;
//	p->cnt = 0;
//	return;
//}
//bool append_arr(pArr p, int val) {
//	if (is_full(p)) {
//		return false;
//	}
//	p->pBase[p->cnt] = val;
//	p->cnt++;
//	return true;
//}
//bool travese_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("����Ϊ�գ�����\n");
//		return false;
//	}
//	for (int i = 0; i < p->cnt; i++) {
//		printf("%d\t", p->pBase[i]);
//	}
//	printf("\n");
//	return true;
//}
//bool insert_arr(pArr p, int pos, int val) {
//	if (is_full(p)) {
//		return false;
//	}
//	if (pos < 1 || pos > p->cnt + 1) {
//		return false;
//	}
//
//	for (int i = p->cnt - 1; i >= pos - 1; i--) {
//		p->pBase[i + 1] = p->pBase[i];
//	}
//	p->pBase[pos - 1] = val;
//	p->cnt++;
//	return true;
//}
//bool delete_arr(pArr p, int pos, int* val) {
//	if (is_empty(p)) {
//		return false;
//	}
//	if (pos < 1 || pos > p->cnt) {
//		return false;
//	}
//	*val = p->pBase[pos - 1];
//	for (int i = pos - 1; i < p->cnt - 1; i++) {
//		p->pBase[i] = p->pBase[i + 1];
//	}
//	p->cnt--;
//	return true;
//}
//bool is_empty(pArr p) {
//	if (p->cnt == 0)
//		return true;
//	else
//		return false;
//}
//bool is_full(pArr p) {
//	if (p->len == p->cnt)
//		return true;
//	else
//		return false;
//}

/*2022/8/19��ϰ*/
//��ɢ�洢
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//
//typedef struct Node {
//	int data;	/*������*/
//	struct Node* pNext;	/*ָ����*/
//}*PNODE, NODE; 
// 
//1) NODE = struct Node
//2) PNODE = struct Node*
//
//
//PNODE create_list();
//bool is_empty(PNODE pHead);
//void traverse_list(PNODE pHead);
//
//int main() { 
//	PNODE pHead = NULL;
//	// ����һ����ѭ�������������������ͷ���ĵ�ַ����pHead
//	pHead = create_list();
//	if (is_empty(pHead)) {
//		printf("����Ϊ�գ�����\n");
//	}
//	traverse_list(pHead);
//
//	return 0;
//}
//
//PNODE create_list() {
//	int len; /* ������Žڵ�ĸ��� */
//	int i;
//	int val; /* ������ʱ����û��������ֵ */
//
//	/* ������һ���������Ч���ݵ�ͷ�ڵ� */
//	PNODE pHead = (PNODE)malloc(sizeof(NODE));
//	if (pHead == NULL) {
//		printf("����ʧ�ܣ�������ֹ������\n");
//		exit(-1);
//	}
//	PNODE pTail = pHead;
//	pTail->pNext = NULL;
//
//	printf("��������Ҫ��������ڵ�ĸ�����len = ");
//	scanf_s("%d", &len);
//	loop:if (len < 0) {
//		printf("����������������1��������");
//		scanf_s("%d", &len);
//		goto loop;
//	}
//
//	for (i = 0; i < len; i++) {
//		printf("������%d���ڵ��ֵ��", i + 1);
//		scanf_s("%d", &val);
//
//		PNODE pNew = (PNODE)malloc(sizeof(NODE));
//		if (pNew == NULL) {
//			printf("����ʧ�ܣ�������ֹ������\n");
//			exit(-1);
//		}
//		pNew->data = val;
//		pTail->pNext = pNew;
//		pNew->pNext = NULL;
//		pTail = pNew;
//	}
//
//	return pHead;
//}
//bool is_empty(PNODE pHead) {
//	if (pHead->pNext == NULL) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//void traverse_list(PNODE pHead) {
//	if (is_empty(pHead))
//		printf("����Ϊ�գ�����\n");
//	PNODE p = pHead->pNext;
//
//	while (p != NULL) {
//		printf("%d\t", p->data);
//		p = p->pNext;
//	}
//	return;
//}


/*2022/9/16��ϰ*/
// �����洢����
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//// ������һ���������ͣ����������͵����ֽ���struct arr
//// ���������ͺ���������Ա���ֱ���pBase, len, cnt
//typedef struct arr {
//	int* pBase;	// �洢�����һ��Ԫ�صĵ�ַ
//	int len;	// ������󳤶�
//	int cnt;	// ���鵱ǰ����
//}Arr, *pArr;
//
//void init_arr(pArr p, int len);		/*��ʼ����������*/
//void show_arr(pArr p);				/*������������*/
//void sort_arr(pArr p);				/*����������������*/
//bool append_arr(pArr p, int val);	/*׷�Ӻ�������*/
//bool insert_arr(pArr p, int val, int pos); /*���뺯������*/
//bool delete_arr(pArr p, int* val, int pos);	/*ɾ����������*/
//bool is_full(pArr p);				/*�Ƿ�Ϊ������*/
//bool is_empty(pArr p);				/*�Ƿ�Ϊ������*/
//
//
//int main() {
//	Arr arr;
//	init_arr(&arr, 6);	/*��ʼ�����飬���ҳ���Ϊ6*/
//	//���Ԫ��
//	for (int i = 0; i < 4; i++) {
//		if (append_arr(&arr, i + 1)) {
//			printf("���Ԫ��%d�ɹ�������\n", i + 1);
//		} 
//		else {
//			printf("���Ԫ��%dʧ�ܣ�����\n", i + 1);
//		}
//	}
//	
//	show_arr(&arr);
//	/*insert_arr(&arr, 5, 6);*/
//	int e;
//	if (delete_arr(&arr, &e, 0)) {
//		printf("ɾ��λ��%dԪ��%d�ɹ�������\n", 0, e);
//	}
//	else {
//		printf("ɾ��ʧ��!!!\n");
//	}
//	sort_arr(&arr);
//	show_arr(&arr);
//
//	return 0;
//}
//
//void init_arr(pArr p, int len) {
//	p->pBase = (pArr)malloc(sizeof(int) * len);
//	if (NULL == p->pBase) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	p->len = len;
//	p->cnt = 0;
//	return;
//}
//void show_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("����Ϊ�գ�����\n");
//	}
//
//	for (int i = 0; i < p->cnt; i++) {
//		printf("%d\t", p->pBase[i]);
//	}
//	printf("\n");
//	return;
//}
//void sort_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("����Ϊ�գ�����\n");
//	}
//	// 1 2 3 4
//	int i = 0, j = 0, t;
//	for (i = 0; i < p->cnt - 1; i++) {
//		for (j = i + 1; j < p->cnt; j++) {
//			if (p->pBase[i] < p->pBase[j]) {
//				t = p->pBase[i];
//				p->pBase[i] = p->pBase[j];
//				p->pBase[j] = t;
//			}
//		}
//	}
//}
//bool append_arr(pArr p, int val) {
//	if (is_full(p)) {
//		return false;
//	}
//	p->pBase[p->cnt] = val;
//	p->cnt++;
//	return true;
//}
//bool insert_arr(pArr p, int val, int pos) {
//	if (is_full(p)) {
//		return false;
//	}
//	if (pos < 1 || pos > p->cnt + 1) {
//		return false;
//	}
//	// 1 2 3 4
//	for (int i = p->cnt - 1; i > pos - 2; i--) {
//		p->pBase[i+1] = p->pBase[i];
//	}
//	p->pBase[pos - 1] = val;
//	p->cnt++;
//	return true;
//}
//bool delete_arr(pArr p, int* val, int pos) {
//	if (is_empty(p)) {
//		return false;
//	}
//	if (pos < 1 || pos > p->cnt) {
//		return false;
//	}
//	// 1 2 3 4  2
//	*val = p->pBase[pos - 1];
//	for (int i = pos - 1; i <= p->cnt; i++) {
//		p->pBase[i] = p->pBase[i + 1];
//	}
//	p->cnt--;
//	return true;
//}
//bool is_full(pArr p) {
//	if (p->len == p->cnt) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//bool is_empty(pArr p) {
//	if (0 == p->cnt) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}

/*2022/9/17��ϰ*/
// �����洢����
//# include<stdio.h>
//# include<malloc.h>
//# include<stdlib.h>
//
//# define bool char
//# define true 1
//# define false 0
//
//typedef struct arr {
//	int* pBase;
//	int len;
//	int cnt;
//}*pArr, Arr;
//
//void init_arr(pArr p, int len);
//void show_arr(pArr p);
//void sort_arr(pArr p);
//void traverse_arr(pArr p);
//bool append_arr(pArr p, int val);
//bool insert_arr(pArr p, int val, int pos);
//bool delete_arr(pArr p, int* val, int pos);
//bool is_full(pArr p);
//bool is_empty(pArr p);
//
//
//
//int main() {
//	Arr arr;
//	init_arr(&arr, 6);
//	for (int i = 0; i < 5; i++) {
//		if (append_arr(&arr, i + 1)) {
//			printf("���%dԪ�سɹ�!!!\n", i + 1);
//		}
//		else {
//			printf("���%dԪ��ʧ�ܣ�����\n", i + 1);
//		}
//	}
//	show_arr(&arr);
//	/*insert_arr(&arr, 88, 0);
//	int e;
//	delete_arr(&arr, &e, 0);
//	printf("%d\n", e);
//	sort_arr(&arr);*/
//	traverse_arr(&arr);
//	show_arr(&arr);
//	return 0;
//}
//
//void init_arr(pArr p, int len) {
//	p->pBase = (pArr)malloc(sizeof(int) * len);
//	if (NULL == p->pBase) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	p->len = len;
//	p->cnt = 0;
//	return;
//}
//void show_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("����Ϊ�գ�����\n");
//	}
//	for (int i = 0; i < p->cnt; i++) {
//		printf("%d\t", p->pBase[i]);
//	}
//	printf("\n");
//	return;
//}
//void sort_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("����Ϊ�գ�����\n");
//	}
//	// 1 2 3 4
//	int t;
//	for (int i = 0; i < p->cnt - 1; i++) {
//		for (int j = i + 1; j < p->cnt; j++) {
//			if (p->pBase[i] < p->pBase[j]) {
//				t = p->pBase[i];
//				p->pBase[i] = p->pBase[j];
//				p->pBase[j] = t;
//			}
//		}
//	}
//	return;
//}
//void traverse_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("����Ϊ�գ�����\n");
//	}
//	else {
//		// 1 2 3 4
//		int i = 0, j = p->cnt - 1, t;
//		while (i <= j) {
//			t = p->pBase[i];
//			p->pBase[i] = p->pBase[j];
//			p->pBase[j] = t;
//			i++;
//			j--;
//		}
//	}
//	return;
//}
//bool append_arr(pArr p, int val) {
//	if (is_full(p)) {
//		return false;
//	}
//	p->pBase[p->cnt] = val;
//	p->cnt++;
//	return true;
//}
//bool insert_arr(pArr p, int val, int pos) {
//	if (is_full(p) || pos < 1 || pos > p->cnt + 1) {
//		return false;
//	}
//	for (int i = p->cnt - 1; i > pos - 2; i--) {
//		p->pBase[i + 1] = p->pBase[i];
//	}
//	p->pBase[pos - 1] = val;
//	p->cnt++;
//	return true;
//}
//bool delete_arr(pArr p, int* val, int pos) {
//	if (is_empty(p) || pos < 1 || pos > p->cnt) {
//		return false;
//	}
//	*val = p->pBase[pos - 1];
//	for (int i = pos - 1; i < p->cnt; i++) {
//		p->pBase[i] = p->pBase[i + 1];
//	}
//	p->cnt--;
//	return true;
//}
//bool is_full(pArr p) {
//	if (p->cnt == p->len) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//bool is_empty(pArr p) {
//	if (p->cnt == 0) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}

/*2022/9/19��ϰ*/
//# include<stdio.h>
//# include<malloc.h>
//# include<stdlib.h>
//
//# define bool char
//# define true 1
//# define false 0
//
//typedef struct node {
//	int data;
//	struct node* pNext;
//}*PNODE, NODE;
//
//PNODE create_list(PNODE pHead);
//void traverse_list(PNODE pHead);
//
//int main() {
//	PNODE pHead = NULL;
//	pHead = create_list(pHead);
//	traverse_list(pHead);
//	return 0;
//}
//
//PNODE create_list(PNODE pHead) {
//	pHead = (PNODE)malloc(sizeof(NODE));
//	if (NULL == pHead) {
//		printf("��̬�ڴ�����ַʧ�ܣ�����\n");
//		exit(-1);
//	}
//
//	PNODE pTail = pHead;
//	pTail->pNext = NULL;
//
//	int len, val, i;
//	printf("�����봴��������ĳ��ȣ�len = ");
//	scanf_s("%d", &len);
//
//	for (i = 0; i < len; i++) {
//		printf("�������%d���ڵ��ֵ��", i + 1);
//		scanf_s("%d", &val);
//		PNODE pNew = (PNODE)malloc(sizeof(NODE));
//		if (NULL == pNew) {
//			printf("��̬�ڴ����ʧ�ܣ�����\n");
//			exit(-1);
//		}
//		pNew->data = val;
//		pNew->pNext = NULL;
//		pTail->pNext = pNew;
//		pTail = pNew;
//	}
//	return pHead;
//}
//void traverse_list(PNODE pHead) {
//	if (pHead->pNext == NULL) {
//		printf("����������\n");
//	}
//	else {
//		PNODE p = pHead->pNext;
//		while (p != NULL) {
//			printf("%d\t", p->data);
//			p = p->pNext;
//		}
//		printf("\n");
//	}
//	return;
//}

/*2022/9/21��ϰ*/
// ��ɢ�洢
//# include<stdio.h>
//# include<malloc.h>
//# include<stdlib.h>
//
//# define bool char
//# define true 1
//# define false 0
//
//typedef struct node {
//	int data;
//	struct node* pNext;
//}*PNODE, NODE;
//
//PNODE create_list();
//bool insert_list(PNODE pHead, int pos, int val);
//bool is_empty(PNODE pHead);
//int length_list(PNODE pHead);
//void traverse_list(PNODE pHead);
//
//int main() {
//	PNODE pHead = NULL;
//	pHead = create_list();
//	traverse_list(pHead);
//	insert_list(pHead, 2, 88);
//	traverse_list(pHead);
//	// printf("%d\n", length_list(pHead));
//	return 0;
//}
//
//PNODE create_list() {
//	int i, len, val;
//	PNODE pHead = (PNODE)malloc(sizeof(NODE));
//	if (NULL == pHead) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	PNODE pTail = pHead;
//	pTail->pNext = NULL;
//
//	printf("�����봴���ڵ������len = ");
//	scanf_s("%d", &len);
//
//	for (i = 0; i < len; i++) {
//		printf("�������һ���ڵ��ֵ��");
//		scanf_s("%d", &val);
//		PNODE pNew = (PNODE)malloc(sizeof(NODE));
//		if (NULL == pNew) {
//			printf("��̬�ڴ����ʧ�ܣ�����\n");
//			exit(-1);
//		}
//		pNew->data = val;
//		pNew->pNext = NULL;
//		pTail->pNext = pNew;
//		pTail = pNew;
//	}
//	return pHead;
//}
//bool insert_list(PNODE pHead, int pos, int val) {
//	int i = 0, len = length_list(pHead);
//	PNODE p = pHead;
//
//	if (pos < 1 || pos > len + 1) {
//		return false;
//	}
//	// 1 2 3 4 2 88
//	for (i = 0; i < pos - 1; i++) {
//		p = p->pNext;
//	}
//	PNODE pNew = (PNODE)malloc(sizeof(NODE));
//	if (NULL == pNew) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	pNew->data = val;
//	pNew->pNext = p->pNext;
//	p->pNext = pNew;
//	return true;
//}
//bool is_empty(PNODE pHead) {
//	if (NULL == pHead->pNext) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//int length_list(PNODE pHead) {
//	PNODE p = pHead->pNext;
//	int i = 0;
//	while (p != NULL) {
//		i++;
//		p = p->pNext;
//	}
//	return i;
//}
//void traverse_list(PNODE pHead) {
//	PNODE p = pHead->pNext;
//	while (p != NULL) {
//		printf("%d\t", p->data);
//		p = p->pNext;
//	}
//	printf("\n");
//	return;
//}
//
//
//bool insert_list(PNODE pHead, int pos, int val) {
//	int i = 0;
//	PNODE p = pHead;
//	while (NULL != p && i < pos - 1) {
//		p = p->pNext;
//		i++;
//	}
//	if (i > pos - 1 || NULL == p)
//		return false;
//	PNODE pNew = (PNODE)malloc(sizeof(NODE));
//	if (NULL == pNew) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	pNew->data = val;
//	pNew->pNext = p->pNext;
//	p->pNext = pNew;
//	return;
//}
