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
 
/*��ɢ�洢���������㷨*/
//# include<stdio.h>
//# include<malloc.h>
//# include<stdlib.h>
//
//# define bool char
//# define true 1
//# define false 0
//
//typedef struct Node {
//	int data;	/*������*/
//	struct Node* pNext;	/*ָ����*/
//}*PNODE, NODE;
//
//PNODE create_list();
//bool is_empty(PNODE pHead);
//bool append_list(PNODE pHead, int val);
//bool insert_list(PNODE pHead, int val, int pos);
//bool delete_list(PNODE pHead, int* val, int pos);
//void traverse_list(PNODE pHead);
//int length_list(PNODE pHead);
//
//
//
//int main01() {
//	int e;
//	PNODE pHead = NULL;
//	pHead = create_list();
//	traverse_list(pHead);
//	insert_list(pHead, 88, 1);
//	// append_list(pHead, 5);
//	traverse_list(pHead);
//
//	return 0;
//}
//
//PNODE create_list() {
//	int len;
//	int i;
//	int val;	/*������ʱ��Žڵ��ֵ*/
//	/* ������һ���������Ч���ݵ�ͷ�ڵ� */
//	PNODE pHead = (PNODE)malloc(sizeof(NODE));
//	if (pHead == NULL) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	PNODE pTail = pHead;
//	pTail->pNext = NULL;
//
//	printf("����������Ҫ���ɽڵ�ĸ�����len = ");
//	scanf_s("%d", &len);
//
//	for (i = 0; i < len; i++) {
//		printf("������%d���ڵ��ֵ��", i + 1);
//		scanf_s("%d", &val);
//		PNODE pNew = (PNODE)malloc(sizeof(NODE));
//		if (pNew == NULL) {
//			printf("��̬�ڴ����ʧ�ܣ�����\n");
//			exit(-1);
//		}
//		pNew->data = val;
//		pNew->pNext = NULL;
//		pTail->pNext = pNew;
//		pTail = pNew;
//	}
//	return pHead;
//}
//
//bool is_empty(PNODE pHead) {
//	if (pHead->pNext == NULL) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//bool append_list(PNODE pHead, int val) {
//	PNODE pNew = (PNODE)malloc(sizeof(NODE));
//	if (NULL == pNew) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	PNODE p = pHead->pNext, q = NULL;
//	while (p != NULL) {
//		p = p->pNext;
//		if (p != NULL) {
//			q = p;
//		}
//	}
//	pNew->data = val;
//	pNew->pNext = q->pNext;
//	q->pNext = pNew;
//	return true;
//}
//bool insert_list(PNODE pHead, int val, int pos) {
//	int i;
//	PNODE p = pHead;
//	if (pos < 1 || pos > length_list(pHead) + 1) {
//		return false;
//	}
//	/*for (i = 1; i < pos; i++) {
//		p = p->pNext;
//	}*/
//	PNODE pNew = (PNODE)malloc(sizeof(NODE));
//	if (NULL == pNew) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//
//	pNew->data = val;
//	pNew->pNext = p->pNext;
//	p->pNext = pNew;
//	return true;
//}
//bool insert_list(PNODE pHead, int pos, int val) {
//	int i = 0;
//	PNODE p = pHead;
//	while (NULL != p && i < pos - 1) {
//		p = p->pNext;
//		i++;
//	}
//	if (i > pos - 1 || NULL == p)
//		return false;
//	PNODE pNew = (PNODE)malloc(sizeof(NODE));
//	if (NULL == pNew) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	/*pNew->data = val;
//	PNODE q = p->pNext;
//	p->pNext = pNew;
//	pNew->pNext = q;*/
//	// ��д
//	pNew->data = val;
//	pNew->pNext = p->pNext;
//	p->pNext = pNew;
//	return;
//}
//
//bool delete_list(PNODE pHead, int* val, int pos) {
//	if (is_empty(pHead)) {
//		return false;
//	}
//	if (pos < 1 || pos > length_list(pHead)) {
//		return false;
//	}
//	int i;
//	PNODE p = pHead, q;
//	// 1 2 3  2
//	for (i = 0; i < pos - 1; i++) {
//		p = p->pNext;
//	}
//	q = p->pNext;
//	*val = q->data;
//	q = q->pNext;
//	free(p->pNext);
//	//printf("%d!!!!!!\n", p->pNext->data);
//	p->pNext = q;
//	return true;
//}
//void traverse_list(PNODE pHead) {
//	PNODE p = pHead->pNext;
//	while (p != NULL) {
//		printf("%d\t", p->data);
//		p = p->pNext;
//	}
//	printf("\n");
//	return;
//}
//
//int length_list(PNODE pHead) {
//	PNODE p = pHead->pNext;
//	int i = 0;
//
//	while (p != NULL) {
//		i++;
//		p = p->pNext;
//	}
//	return i;
//}
