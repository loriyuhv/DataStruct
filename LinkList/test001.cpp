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