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
/*pointer��ϰ*/

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