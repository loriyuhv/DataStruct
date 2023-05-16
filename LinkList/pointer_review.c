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
/*pointer练习*/

#include<stdio.h>

void f(int *i) {
	*i = 100;
}

int main() {
	int i = 9;
	f(&i);
	printf("i = %d\n", i);
	return 0;
}