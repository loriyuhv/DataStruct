/*pointer����*/
//#include<stdio.h>
//
//int main() {
//	/*
//	* ָ�룺
//	*	ָ����ǵ�ַ����ַ����ָ�룻
//	*	ָ������Ǵ���ڴ浥Ԫ��ַ�ı�����
//	*	ָ��ı�����һ���������޵ķǸ�������
//	* ָ����ࣺ
//	*
//	*
//	*/
//	int* p; // p�Ǹ�ָ�������int * ��ʾ��p����ֻ�ܴ洢int���ͱ����ĵ�ַ
//	int i = 10;
//	int j;
//	p = &i;	// &i��ʾi�����ĵ�ַ����i�ĵ�ַ��ֵ��p
//	j = *p; // *p��ʾpָ����ڴ浥Ԫ��ֵ
//	//printf("%x\n", &j);
//	printf("i = %d, j = %d, *p = %d\n", i, j, *p);
//
//	printf("Hello world!!!");
//	return 0;
//}
/*pointer��ϰ1*/
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

/*pointer��ϰ2*/
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

/*Pointer��ϰ3*/
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
//	p = &x; // xռ8���ֽ� 1���ֽ���8λ��1һ���ֽ�һ����ַ����ŵ����׵�ַ
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

/*���ͨ�������޸�ʵ�ε�ֵ*/
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

/*ʾ��2*/
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

