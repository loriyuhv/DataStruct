/*�ṹ�帴ϰ*/
// 1. Ϊʲô��Ҫ�ṹ��
// ���綨��һ��ѧ����ѧ����ѧ�ţ����������䡣
// Ϊ�˱�ʾһЩ���ӵ����ݣ�����ͨ�Ļ������ͱ����޷�����Ҫ��
// 2.���ʹ�ýṹ��
// ���ַ�ʽ��
// struct Student st = {1000, "Jerry", 18};
// struct Student * pst = &st;
// 1. st.s_id = 99;
// 2. pst->s_id = 199;
// 3. (*pst).s_id = 99;
// 

// 3. ע�����
// �ṹ��������ܼӼ��˳����������໥��ֵ��
// ��ͨ�ṹ������ͽṹ��ָ�������Ϊ�������ε�����


//#include<stdio.h>
//#include<string.h>
//
//struct Student {
//	int s_id;
//	char name[10];
//	int age;
//}; // �ֺŲ���ʡ��
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
//	//jerry.s_id = 99; // ��һ�ַ�ʽ
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
//// ���ַ�ʽ���ڴ棬��ʱ�䲻�Ƽ�
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

/*��̬�ڴ����*/
//#include<stdio.h>
//#include<malloc.h>
//
//int main() {
//	int a[5] = { 4, 10, 2, 8, 6 }; // ��̬����
//	int len;
//	printf("����������Ҫ��������鳤�ȣ�len = ");
//	scanf_s("%d", &len);
//	int* pArr = (int*)malloc(sizeof(int) * len);
//	if (pArr == NULL) {
//		printf("��̬�ڴ����ʧ�ܣ�����");
//		return -1;
//	}
//	*(pArr + 1) = 5;
//	printf("%d\n", *(pArr + 1));
//	//free(pArr);
//	printf("%d", len);
//	return 0;
//}


/*��ϰ1*/
//#include<stdio.h>
//
//int f();
//
//int main() {
//	int i = 10;
//	i = f();
//	printf("%d\n", i);
//	return 0;
//}
//
//int f() {
//	int j = 20;
//	return j;
//}


/*��ϰ2*/
//#include<stdio.h>
//#include<malloc.h>
//
//int fun(int** q);
//
//int main() {
//	int* p;
//	fun(&p);
//	*(p + 0) = 1;
//	printf("%d\n", *(p + 0));
//
//	return 0;
//}
//
//int fun(int** q) {
//	*q = (int*)malloc(sizeof(int) * 2);
//	if (*q == NULL) {
//		return -1;
//	}
//	return 1;
//}

/*��ϰ3*/
//#include<stdio.h>
//#include<malloc.h>
//
//struct Student {
//	int s_id;
//	int age;
//};
//
//int CreateStudent(struct Student** qst) {
//	*qst = (struct Student*)malloc(sizeof(struct Student));
//	if (*qst == NULL) {
//		return -1;
//	}
//	return 1;
//}
//
//void ShowStudent(struct Student* pst) {
//	printf("s_id = %d, age = %d\n", (*pst).s_id, pst->age);
//}
//
//int main() {
//	struct Student* pst;
//	CreateStudent(&pst);
//	pst->age = 18;
//	pst->s_id = 20197360;
//	ShowStudent(pst);
//	return 0;
//}