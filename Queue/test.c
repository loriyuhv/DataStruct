#include<stdio.h>

void hanoi(int n, char A, char B, char C) {
	if (n == 1) {
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����Ƶ�%c����\n", n, A, C);
	}
	else {
		//2 A C B 1 A B C
		hanoi(n - 1, A, C, B);
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����Ƶ�%c����\n", n, A, C);
		//B, A, C1 C A B
		hanoi(n - 1, B, A, C);
		//3 A, B, C
		// 2: B, A, C
		// 1: B, C, A
	}
}
int main() {

	hanoi(3, 'A', 'B', 'C');
	return 0;
}
/* ����һ�������������ڼ������һ������ */
//#include<stdio.h>
//
//void func(char name) {
//	printf("Hello %c!!!\n", name);
//}
//
//int main() {
//	func('A');
//	printf("Hello world\n");
//	return 0;
//}
/* ģ��������ջѹջ */
//#include<stdio.h>
//void f() {
//	printf("from f\n");
//}
//int main() {
//	printf("%p", f);
//	
//	return 0;
//}
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