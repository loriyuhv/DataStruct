/*ѧ�ԡ��±����ݽṹ���š�*/
/*���Խṹ*/
/*�����洢����*/
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//// ������һ���������ͣ����������͵����ֽ���struct Arr
//// ���������ͺ���������Ա���ֱ���pBase, len, cnt
//typedef struct Arr {
//	int* pBase; /*�洢���������һ��Ԫ�صĵ�ַ*/
//	int len;	/*�����������ɵ����Ԫ�ظ���*/
//	int cnt;	/*��ǰ������ЧԪ�ظ���*/
//}*pArr, Arr;
//
//void init_arr(pArr p, int len);				/*��ʼ����������*/
//bool append_arr(pArr p, int val);			/*׷�Ӻ�������*/
//bool insert_arr(pArr p, int pos, int e);	/*���뺯������*/
//bool delete_arr(pArr p, int pos, int* e);	/*ɾ����������*/
//bool is_empty(pArr p);						/*�Ƿ�Ϊ�պ�������*/
//bool is_full(pArr p);						/*�Ƿ�Ϊ����������*/
//void sort_arr(pArr p);						/*����������*/
//void show_arr(pArr p);						/*������������*/
//void inversion_arr(pArr p);					/*���ú�������*/
//
//int main() {
//	Arr arr;
//	init_arr(&arr, 6); /*��ʼ�����飬���ҳ���Ϊ6*/
//	/*for (int i = 0; i < 4; i++) {
//		if (append_arr(&arr, i + 1)) 
//			printf("׷����ֵ%d�ɹ�������\n", i + 1);
//		else
//			printf("׷����ֵ%dʧ�ܣ�����\n", i + 1);
//	}*/
//	/*���Բ���*/
//	//for (int i = 0; i < 4; i++) {
//	//	append_arr(&arr, i + 1);
//	//}
//	//printf("����ǰ��");
//	//show_arr(&arr);
//	//if (insert_arr(&arr, 2, 88)) /*��ֵ88����λ��2*/
//	//	printf("λ��%d������ֵ%d�ɹ�������\n", 2, 88);
//	//else
//	//	printf("λ��%d������ֵ%dʧ�ܣ�����\n", 2, 88);
//	//printf("�����");
//	//show_arr(&arr); /*������������Ԫ��*/
//	/*����ɾ��*/
//	//int e;
//	//for (int i = 0; i < 4; i++) {
//	//	append_arr(&arr, i + 1);
//	//}
//	//printf("ɾ��ǰ��");
//	//show_arr(&arr);
//	//if (delete_arr(&arr, 4, &e)) /*��ֵ88����λ��2*/
//	//printf("λ��%dɾ����ֵ%d�ɹ�������\n", 4, e);
//	//else
//	//printf("λ�����벻���������Ϊ��\n");
//	//printf("ɾ����");
//	//show_arr(&arr); /*������������Ԫ��*/
//	/*���Ե���*/
//	for (int i = 0; i < 5; i++) {
//		append_arr(&arr, i + 1);
//	}
//	printf("����ǰ��");
//	show_arr(&arr);
//	inversion_arr(&arr);
//	printf("���ú�");
//	show_arr(&arr);
//	if (is_empty(&arr)) /*��������arr�Ƿ񴴽��ɹ�*/
//		printf("����Ϊ�գ�����");
//	return 0;
//}
//
//void init_arr(pArr p, int len) {
//	p->pBase = (pArr)malloc(sizeof(int) * len);
//	if (NULL == p->pBase) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	p->len = 6;
//	p->cnt = 0;
//	return;
//}
//bool append_arr(pArr p, int val) {
//	if (is_full(p)) /*�ж������Ƿ�����*/
//		return false;
//	p->pBase[p->cnt] = val;
//	p->cnt++;
//	return true;
//}
//bool is_empty(pArr p) {
//	if (p->cnt == 0)
//		return true;
//	else
//		return false;
//}
//bool is_full(pArr p) {
//	if (p->cnt == p->len)
//		return true;
//	else
//		return false;
//}
//void show_arr(pArr p) {
//	if (is_empty(p))
//		printf("����Ϊ�գ�����\n");
//	else {
//		for (int i = 0; i < p->cnt; i++)
//			printf("%d\t", p->pBase[i]);
//	}
//	printf("\n");
//	return;
//}
//bool insert_arr(pArr p, int pos, int e) {
//	int i;
//	if (is_full(p))	/*�жϺ����Ƿ�����*/
//		return false;
//	if (pos < 1 || pos > p->cnt + 1) /*�жϲ���λ���Ƿ���ȷ*/
//		return false;
//	if (pos != p->cnt + 1) /*�������λ����ĩβ��ֱ�Ӹ�ֵ����*/
//		for (i = p->cnt - 1; i >= pos - 1; i--) /*��Ҫ�����ֵ�ڳ�λ��*/
//			p->pBase[i + 1] = p->pBase[i];
//	p->pBase[pos - 1] = e;
//	p->cnt++;
//	return true;
//}
//bool delete_arr(pArr p, int pos, int* e) {
//	if (is_empty(p)) /*�ж�����Ϊ��*/
//		return false;
//	if (pos < 1 || pos > p->cnt) /*�жϲ���λ���Ƿ����*/
//		return false;
//	*e = p->pBase[pos - 1]; /*��ɾ����ֵ����*e*/
//	if (pos != p->cnt)
//		for (int i = pos - 1; i < p->cnt; i++)
//			p->pBase[i] = p->pBase[i + 1];
//	p->cnt--;
//	return true;
//}
//void inversion_arr(pArr p) {
//	/*����һ*/
//	/*int i = 0, j = p->cnt - 1, t;
//	while (i < j) {
//		t = p->pBase[i];
//		p->pBase[i] = p->pBase[j];
//		p->pBase[j] = t;
//		i++;
//		j--;
//	}
//	return;*/
//	/*������*/
//	int i = 0, n = p->cnt - 1, t;
//	for (; i <= n / 2; i++) {
//		t = p->pBase[i];
//		p->pBase[i] = p->pBase[n - i];
//		p->pBase[n - i] = t;
//	}
//	return;
//}
//void sort_arr(pArr p) {
//	int i, j, t;
//	for (i = 0; i < p->cnt - 1; i++)
//		for(j  = 0; j < p->cnt - i - 1; j++)
//			if (p->pBase[j] < p->pBase[j + 1]) {
//				t = p->pBase[j];
//				p->pBase[j] = p->pBase[j + 1];
//				p->pBase[j + 1] = t;
//			}
//	return;
//}
// typedef
//# include<stdio.h>
//
//typedef int a;	/*Ϊint�����¶�ȡһ�����֣�a�ȼ���int*/
//
//typedef struct Student {
//	int id;
//	char name[100];
//	char sex;
//}ST;	/* ST�ȼ���struct Student */
//
//int main() {
//	int i = 10;	/* �ȼ��� a i = 10 */
//	a j = 10;
//	printf("i = %d, j = %d\n", i, j);
//
//	struct Student st;	/* �ȼ��� ST st */
//	struct Student* ps = &st; /* �ȼ���ST* ps = &st */
//	ST st2;
//	ps->id = 20197360;
//	st2 = st;
//	printf("%d\n", st2.id);
//
//	return 0;
//}
// ����һ��
//# include<stdio.h>
//
//typedef struct Student {
//	int id;
//	char name[100];
//	char sex;
//}* PST, ST; /* PST �ȼ��� struct Student*,ST �ȼ��� struct Student */
//
//int main() {
//	ST st;
//	PST ps = &st;
//	ps->id = 20197360;
//	printf("%d\n", ps->id);
//
//	return 0;
//}
 
/**/


