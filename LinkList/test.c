/*倒置练习*/
/*方法1*/
//#include<stdio.h>
//int main() {
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int i, n = 5, t;
//	for (i = 0; i < n / 2; i++)
//		t = a[i], a[i] = a[n - i - 1], a[n - i - 1] = t;
//	for (i = 0; i < n; i++)
//		printf("%d\t", a[i]);
//	return 0;
//}
/*方法2*/
//#include<stdio.h>
//int main() {
//	int a[6] = { 1, 2, 3, 4, 5, 6 };
//	int i = 0, j = 5, t;
//	while (i <= j) {
//		t = a[i];
//		a[i] = a[j];
//		a[j] = t;
//		i++;
//		j--;
//	}
//	for (i = 0; i < 5; i++)
//		printf("%d\t", a[i]);
//	return 0;
//}

/*Dereferencing NULL pointer <name> */
//#include <stdio.h>
//#include <malloc.h>
//
////* This following code generates this warning. */
//void f()
//{
//	char* p = (char*)malloc(10);
//	*p = '\0';
//
//	// code ...
//	free(p);
//}
//
////* To correct this warning, examine the pointer 
//	for a null value as shown the following code: */
//void f2()
//{
//	char* p = (char*)malloc(10);
//
//	if (p) {
//		*p = '\0';
//		// code...
//		free(p);
//	}
//}
//
//int main() {
//	f();
//	f2();
//	return 0;
//}


