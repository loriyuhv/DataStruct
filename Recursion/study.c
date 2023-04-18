#include<stdio.h>


void hanoi(int n, char A, char B, char C) {
	if (n == 1) {
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����Ƶ�%c����\n", n, A, C);
	}
	else {
		hanoi(n - 1, A, C, B);
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����Ƶ�%c����\n", n, A, C);
		hanoi(n - 1, B, A, C);
	}
}

int main01() {
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;

	printf("������Ҫ�ƶ����ӵĸ�����");
	scanf_s("%d", &n);

	hanoi(n, 'A', 'B', 'C');
	return 0;
}

/*
#include<stdio.h>

void f();
void g();
void k();

void f() {
	printf("FFFF\n");
	g();
	printf("1111\n");
	return;
}

void g() {
	printf("GGGG\n");
	k();
	printf("2222\n");
	return;
}

void k() {
	printf("KKKK\n");
	return;
}

int main() {
	f();
	return 0;
}
*/