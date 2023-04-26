/*以下代码来自《大话数据结构与算法》*/
/*测试*/
//#include<stdio.h>
//
//int main() {
//	printf("Hello loriyuhv!!!\n");
//	printf("Hello LinkList!!!\n");
//	return 0;
//}
/*线性表的顺序存储结构*/
//#include<stdio.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//#define MAXSIZE 10
//
//typedef int ElemType;
//typedef struct {
//	ElemType data[MAXSIZE]; /*数组存储元素，最大值为MAXSIZE*/
//	int length;	/*当前线性表的长度*/
//}SqList;
//
//void InitList(SqList* L);	/*初始化线性表*/
//bool ListAppend(SqList* L, ElemType e);	/*向线性表L添加元素e*/
//bool ListEmpty(SqList* L);	/*若线性表为空，返回true，否则返回false*/
//bool ListFull(SqList* L);
//bool TraverseList(SqList* L);
//
//int main() {
//	SqList La;
//	SqList Lb;
//	InitList(&La);
//	InitList(&Lb);
//	TraverseList(&La);
//	TraverseList(&Lb);
//	if (ListEmpty(&La))
//		printf("线性表为空！！！\n");
//	return 0;
//}
//
//void InitList(SqList* L) {
//	L->length = 0;
//	return;
//}
//bool ListAppend(SqList* L, ElemType e) {
//	if (ListFull(L))	/*线性表为满*/
//		return false;
//	L->data[L->length] = e;
//	L->length++;
//	return;
//}
//bool ListEmpty(SqList* L) {
//	if (L->length == 0)
//		return true;
//	else
//		return false;
//}
//bool ListFull(SqList* L) {
//	if (L->length == MAXSIZE)
//		return true;
//	else
//		return false;
//}
//bool TraverseList(SqList* L) {
//	if (ListEmpty(L)) {
//		printf("线性表为空！！！\n");
//		return false;
//	}
//	for (int i = 0; i < L->length; i++)
//		printf("%d\t", L->data[i]);
//	printf("\n");
//	return true;
//}
