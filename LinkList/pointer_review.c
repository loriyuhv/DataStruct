/*pointer概念*/
//#include<stdio.h>
//
//int main() {
//	/*
//	* 指针：
//	*	指针就是地址，地址就是指针；
//	*	指针变量是存放内存单元地址的变量；
//	*	指针的本质是一个操作受限的非负整数。
//	* 指针分类：
//	*
//	*
//	*/
//	int* p; // p是个指针变量，int * 表示该p变量只能存储int类型变量的地址
//	int i = 10;
//	int j;
//	p = &i;	// &i表示i变量的地址，将i的地址赋值给p
//	j = *p; // *p表示p指向的内存单元的值
//	//printf("%x\n", &j);
//	printf("i = %d, j = %d, *p = %d\n", i, j, *p);
//
//	printf("Hello world!!!");
//	return 0;
//}
/*pointer练习1*/
//#include<stdio.h>
//
//void f(int * i) {
//	*i = 100;
//}
//
//int main() {
//	int i = 9;
//	f(&i);
//	printf("i = %d\n", i);
//	return 0;
//}

/*pointer练习2*/
//#include<stdio.h>
//
//int main() {
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	printf("%d\n", sizeof(int*));
//	printf("%p\n", arr + 1);
//	printf("%p\n", arr + 2);
//	printf("%p\n", arr + 3);
//	return 0;
//}

/*Pointer练习3*/
//#include<stdio.h> 
//
//void show_array(int* a, int len) {
//	int i;
//
//	for (i = 0; i < len; i++) {
//		printf("%d\t", *(a + i));
//	}
//}
//
//int main() {
//
//	int a[5] = { 1, 2, 3, 4, 5 };
//	show_array(a, 5);
//	return 0;
//}

/*Pointer review*/
//#include<stdio.h>
//
//int main() {
//	double* p;
//	double x = 66.6;
//	p = &x; // x占8个字节 1个字节是8位，1一个字节一个地址，存放的是首地址
//
//	double arr[3] = { 1.1, 2.2, 3.3 };
//	double* q;
//
//	q = &arr[0];
//	printf("%p\n", q);
//	q = &arr[1];
//	printf("%p\n", q);
//
//
//	return 0;
//}

/*如何通过函数修改实参的值*/
//#include<stdio.h>
//
//void f(int* x);
//
//int main() {
//	int i = 10;
//	f(&i);
//	printf("i = %d\n", i);
//	return 0;
//}
//
//void f(int* x) {
//	*x = 100;
//}

/*示例2*/
//#include<stdio.h>
//
//void f(int** q, int* j) {
//	**q = 99;
//	*q = j;
//	return 0;
//}
//
//void x(int* q) {
//	*q = 999;
//}
//
//int main() {
//	int i = 9;
//	int j = 10;
//	int* p = &i;
//	f(&p, &j);
//	printf("*p = %d\n", *p);
//	printf("i = %d\n", i);
//
//	x(p);
//	printf("*p=%d\n", *p);
//	return 0;
//}

