/*结构体复习*/
// 1. 为什么需要结构体
// 比如定义一个学生，学生有学号，姓名，年龄。
// 为了表示一些复杂的数据，而普通的基本类型变量无法满足要求
// 2.如何使用结构体
// 两种方式：
// struct Student st = {1000, "Jerry", 18};
// struct Student * pst = &st;
// 1. st.s_id = 99;
// 2. pst->s_id = 199;
// 3. (*pst).s_id = 99;
// 

// 3. 注意事项：
// 结构体变量不能加减乘除，但可以相互赋值。
// 普通结构体变量和结构体指针变量作为函数传参的问题


//#include<stdio.h>
//#include<string.h>
//
//struct Student {
//	int s_id;
//	char name[10];
//	int age;
//}; // 分号不能省略
//
//int main() {
//	struct Student jerry = { 20197360, "Jerry", 20 };
//	printf("%d, %s, %d\n", jerry.s_id, jerry.name, jerry.age);
//
//	jerry.s_id = 7360;
//	jerry.age = 18;
//	strcpy_s(jerry.name, "Jack");
//	printf("%d, %s, %d\n", jerry.s_id, jerry.name, jerry.age);
//	return 0;
//}

/*struct 2*/
//#include<stdio.h>
//#include<string.h>
//
//struct Student {
//	int s_id;
//	char name[10];
//	int age;
//};
//int main() {
//	struct Student jerry = { 1000, "Jerry", 20 };
//	//jerry.s_id = 99; // 第一种方式
//	struct Student* student;
//	student = &jerry;
//	student->s_id = 99;
//	(*student).age = 18;
//	printf("s_id = %d, name = %s, age = %d\n", student->s_id, (*student).name, student->age);
//	//printf("%d\n", sizeof(struct Student));
//	return 0;
//}


/*struct 3*/
//#include<stdio.h>
//
//struct Student {
//	int s_id;
//	char name[10];
//	int age;
//};
//
//void f(struct Student* pst) {
//	pst->age = 32;
//	pst->s_id = 2000;
//}
//// 这种方式耗内存，耗时间不推荐
//void g(struct Student st) {
//	st.s_id = 200;
//}
//
//int main() {
//	struct Student st = { 100, "Jerry", 18 };
//	//f(&st);
//	g(st);
//	printf("%d, %s, %d\n", st.s_id, st.name, st.age);
//	return 0;
//}

/*动态内存分配*/
#include<stdio.h>
#include<malloc.h>

int main() {
	int a[5] = { 4, 10, 2, 8, 6 }; // 静态分配
	int len;
	printf("请输入你需要分配的数组长度：len = ");
	scanf_s("%d", &len);
	int* pArr = (int*)malloc(sizeof(int) * len);
	if (pArr == NULL) {
		printf("动态内存分配失败！！！");
		return -1;
	}
	*(pArr + 1) = 5;
	printf("%d\n", *(pArr + 1));
	//free(pArr);
	printf("%d", len);
	return 0;
}