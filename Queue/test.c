#include<stdio.h>

void hanoi(int n, char A, char B, char C) {
	if (n == 1) {
		printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
	}
	else {
		//2 A C B 1 A B C
		hanoi(n - 1, A, C, B);
		printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
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
/* 当在一个函数的运行期间调用另一个函数 */
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
/* 模拟计算机出栈压栈 */
//#include<stdio.h>
//void f() {
//	printf("from f\n");
//}
//int main() {
//	printf("%p", f);
//	
//	return 0;
//}
/*测试为什么长度为5的数组下标不能为5*/
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