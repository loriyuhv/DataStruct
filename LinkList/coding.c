/*���´������ԡ������ݽṹ���㷨��*/
/*����*/
//#include<stdio.h>
//
//int main() {
//	printf("Hello loriyuhv!!!\n");
//	printf("Hello LinkList!!!\n");
//	return 0;
//}
/*���Ա��˳��洢�ṹ*/
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
//	ElemType data[MAXSIZE]; /*����洢Ԫ�أ����ֵΪMAXSIZE*/
//	int length;	/*��ǰ���Ա�ĳ���*/
//}SqList;
//
//void InitList(SqList* L);	/*��ʼ�����Ա�*/
//bool ListAppend(SqList* L, ElemType e);	/*�����Ա�L���Ԫ��e*/
//bool ListEmpty(SqList* L);	/*�����Ա�Ϊ�գ�����true�����򷵻�false*/
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
//		printf("���Ա�Ϊ�գ�����\n");
//	return 0;
//}
//
//void InitList(SqList* L) {
//	L->length = 0;
//	return;
//}
//bool ListAppend(SqList* L, ElemType e) {
//	if (ListFull(L))	/*���Ա�Ϊ��*/
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
//		printf("���Ա�Ϊ�գ�����\n");
//		return false;
//	}
//	for (int i = 0; i < L->length; i++)
//		printf("%d\t", L->data[i]);
//	printf("\n");
//	return true;
//}
