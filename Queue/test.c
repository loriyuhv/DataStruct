/* ģ��������ջѹջ */
#include<stdio.h>
void f() {
	printf("from f\n");
}
int main() {
	printf("%p", f);
	
	return 0;
}
/*����Ϊʲô����Ϊ5�������±겻��Ϊ5*/
//#include<stdio.h>
//#include<malloc.h>
//
//int main() {
//	int* a = (int*)malloc(sizeof(int) * 3);
//	a[0] = 1;
//	a[1] = 2;
//	a[2] = 3;
//	// a[3] = 4;
//	for (int i = 0; i < 3; i++)
//		printf("%d\t", a[i]);
//
//	printf("\n");
//
//	return 0;
//}