/*��ϰ*/
//#include <stdio.h>
//#include <malloc.h>
//#include <stdlib.h>
//
//struct node {
//	int data;	/*a data item*/
//	struct node* next; /*an address of another node*/
//};
//
//int main() {
//	/*initialize node*/
//	struct node* head = NULL;
//	struct node* one = NULL;
//	struct node* two = NULL;
//	struct node* three = NULL;
//
//	/*Allocate memory*/
//	head = (struct node*)malloc(sizeof(struct node));
//	if (head == NULL) {
//		exit(-1);
//	}
//	one = (struct node*)malloc(sizeof(struct node));
//	if (one == NULL) {
//		exit(-1);
//	}
//	two = (struct node*)malloc(sizeof(struct node));
//	if (two == NULL) {
//		exit(-1);
//	}
//	three = (struct node*)malloc(sizeof(struct node));
//	if (three == NULL) {
//		exit(-1);
//	}
//
//	/*Assign data values*/
//	one->data = 1;
//	two->data = 2;
//	three->data = 3;
//	/*Connect nodes */
//	one->next = two;
//	two->next = three;
//	three->next = NULL;
//
//	/* Save address of first node in head */
//	head->next = one;
//
//	/* If you wanted to put an element 4
//	between 1 and 2, the steps would be:*/
//	
//	/*step1��create a new struct node and 
//	allocate memory to it*/
//	struct node* new_node = (struct node*)malloc(sizeof(struct node));
//	if (new_node == NULL) {
//		exit(-1);
//	}
//	/*step2: Add its data value as 4 */
//	new_node->data = 4;
//	/*step3: Point its next pointer to the struct node containing 2 
//	as the data value*/
//	new_node->next = two;
//	/*step4: Change the next pointer of "1" 
//	to the node we just created*/
//	one->next = new_node;
//
//	/*If you wanted to put an element 88 between 2 and 3, the steps
//	would be:*/
//	/* Step1: Create a new struct node and allocate memory to it*/
//	struct node* new2_node = (struct node*)malloc(sizeof(struct node));
//	if (new2_node == NULL) {
//		exit(-1);
//	}
//	/* Step2: Add its data value as 88*/
//	new2_node->data = 88;
//	/* Step3: Point the(its) next pointer 
//	to the struct node containing 3 as the data value*/
//	new2_node->next = three;
//	/* Step4: Change the next pointer of "2" to the node 
//	we just created*/
//	two->next = new2_node;
//
//	struct node* p;
//	p = head->next;
//	while (p != NULL) {
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef struct arr {
//	int* pBase;
//	int len;
//	int cnt;
//}*pArr, Arr;
//
//void init_arr(pArr p, int len);
//void show_arr(pArr p);
//bool is_empty(pArr p);
//bool is_full(pArr p);
//bool append_arr(pArr p, int val);
//bool insert_arr(pArr p, int pos, int val);
//
//int main() {
//	Arr arr;
//
//	init_arr(&arr, 6);
//	for (int i = 0; i <= 4; i++) {
//		if (append_arr(&arr, i + 1)) {
//			printf("%dԪ��׷�ӳɹ�������\n", i + 1);
//		}
//		else {
//			printf("%dԪ��׷��ʧ�ܣ�����\n", i + 1);
//		}
//	}
//	printf("����ǰ��");
//	show_arr(&arr);
//	if (insert_arr(&arr, 2, 88)) /*��ֵ88����λ��2*/
//		printf("λ��%d������ֵ%d�ɹ�������\n", 2, 88);
//	else
//		printf("λ��%d������ֵ%dʧ�ܣ�����\n", 2, 88);
//	printf("�����");
//	show_arr(&arr); /*������������Ԫ��*/
//
//	/*show_arr(&arr);
//	if (is_empty(&arr))
//		printf("Ԫ��Ϊ�գ�����\n");*/
//	return 0;
//}
//
//void init_arr(pArr p, int len) {
//	p->pBase = (pArr)malloc(sizeof(int) * len);
//	if (p->pBase == NULL) {
//		printf("��̬�ڴ����ʧ�ܣ�����");
//		exit(-1);
//	}
//	p->len = len;
//	p->cnt = 0;
//	return;
//}
//void show_arr(pArr p) {
//	int i;
//	if (is_empty(p)) {
//		printf("����Ϊ�գ�����\n");
//	}
//	else {
//		for (i = 0; i < p->cnt; i++)
//			printf("%d\t", p->pBase[i]);
//	}
//	printf("\n");
//	return;
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
//bool append_arr(pArr p, int val) {
//	if (is_full(p)) {
//		printf("��������������\n");
//		return false;
//	}
//	else {
//		p->pBase[p->cnt] = val;
//		p->cnt++;
//	}
//	return true;
//}
//bool insert_arr(pArr p, int pos, int val) {
//	if (is_full(p)) {
//		printf("�������������ɲ��룡����\n");
//		return false;
//	}
//	if (pos < 1 || pos > 6) {
//		printf("����λ�ô���\n");
//		return false;
//	}
//	// 1 2 3 4 5  88 2
//	int i;
//	for (i = p->cnt - 1; i >= pos - 1; i--) {
//		printf("%d, %d\n", i, p->pBase[i]);
//		p->pBase[i + 1] = p->pBase[i];
//	}
//	p->pBase[pos - 1] = val;
//	p->cnt++;
//	return true;
//}
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//typedef struct arr {
//	int* pBase;
//	int len;
//	int cnt;
//}*pArr, Arr;
//
//void init_arr(pArr p, int len);
//bool append_arr(pArr p, int val);
//bool travese_arr(pArr p);
//bool insert_arr(pArr p, int pos, int val);
//bool delete_arr(pArr p, int pos, int* val);
//bool is_empty(pArr p);
//bool is_full(pArr p);
//
//int main() {
//	Arr arr;
//	init_arr(&arr, 6);
//	// ��������
//	for (int i = 0; i <= 3; i++) {
//		if (append_arr(&arr, i + 1)) {
//			printf("���Ԫ��%d�ɹ�������\n", i + 1);
//		}
//		else
//			printf("���Ԫ��%dʧ�ܣ�����\n", i + 1);
//	}
//	
//	printf("����ǰ��\n");
//	travese_arr(&arr);
//	printf("�����\n");
//	if (insert_arr(&arr, 2, 88))
//		;
//	else
//		printf("����ʧ�ܣ�����\n");
//	travese_arr(&arr);
//	
//	int val;
//	printf("ɾ��ǰ��\n");
//	travese_arr(&arr);
//	printf("ɾ����\n");
//	if (delete_arr(&arr, 2, &val))
//		printf("�ɹ���ɾ��ֵ��%d\n", val);
//	else
//		printf("ɾ��ʧ�ܣ�����\n");
//	travese_arr(&arr);
//
//	if (is_empty(&arr)) {
//		printf("����Ϊ�գ�����\n");
//	}
//	return 0;
//}
//
//void init_arr(pArr p, int len) {
//	p->pBase = (pArr)malloc(sizeof(int) * len);
//	if (p->pBase == NULL) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	p->len = len;
//	p->cnt = 0;
//	return;
//}
//bool append_arr(pArr p, int val) {
//	if (is_full(p)) {
//		return false;
//	}
//	p->pBase[p->cnt] = val;
//	p->cnt++;
//	return true;
//}
//bool travese_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("����Ϊ�գ�����\n");
//		return false;
//	}
//	for (int i = 0; i < p->cnt; i++) {
//		printf("%d\t", p->pBase[i]);
//	}
//	printf("\n");
//	return true;
//}
//bool insert_arr(pArr p, int pos, int val) {
//	if (is_full(p)) {
//		return false;
//	}
//	if (pos < 1 || pos > p->cnt + 1) {
//		return false;
//	}
//
//	for (int i = p->cnt - 1; i >= pos - 1; i--) {
//		p->pBase[i + 1] = p->pBase[i];
//	}
//	p->pBase[pos - 1] = val;
//	p->cnt++;
//	return true;
//}
//bool delete_arr(pArr p, int pos, int* val) {
//	if (is_empty(p)) {
//		return false;
//	}
//	if (pos < 1 || pos > p->cnt) {
//		return false;
//	}
//	*val = p->pBase[pos - 1];
//	for (int i = pos - 1; i < p->cnt - 1; i++) {
//		p->pBase[i] = p->pBase[i + 1];
//	}
//	p->cnt--;
//	return true;
//}
//bool is_empty(pArr p) {
//	if (p->cnt == 0)
//		return true;
//	else
//		return false;
//}
//bool is_full(pArr p) {
//	if (p->len == p->cnt)
//		return true;
//	else
//		return false;
//}

/*2022/8/19��ϰ*/
//��ɢ�洢
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//
//typedef struct Node {
//	int data;	/*������*/
//	struct Node* pNext;	/*ָ����*/
//}*PNODE, NODE; 
// 
//1) NODE = struct Node
//2) PNODE = struct Node*
//
//
//PNODE create_list();
//bool is_empty(PNODE pHead);
//void traverse_list(PNODE pHead);
//
//int main() { 
//	PNODE pHead = NULL;
//	// ����һ����ѭ�������������������ͷ���ĵ�ַ����pHead
//	pHead = create_list();
//	if (is_empty(pHead)) {
//		printf("����Ϊ�գ�����\n");
//	}
//	traverse_list(pHead);
//
//	return 0;
//}
//
//PNODE create_list() {
//	int len; /* ������Žڵ�ĸ��� */
//	int i;
//	int val; /* ������ʱ����û��������ֵ */
//
//	/* ������һ���������Ч���ݵ�ͷ�ڵ� */
//	PNODE pHead = (PNODE)malloc(sizeof(NODE));
//	if (pHead == NULL) {
//		printf("����ʧ�ܣ�������ֹ������\n");
//		exit(-1);
//	}
//	PNODE pTail = pHead;
//	pTail->pNext = NULL;
//
//	printf("��������Ҫ��������ڵ�ĸ�����len = ");
//	scanf_s("%d", &len);
//	loop:if (len < 0) {
//		printf("����������������1��������");
//		scanf_s("%d", &len);
//		goto loop;
//	}
//
//	for (i = 0; i < len; i++) {
//		printf("������%d���ڵ��ֵ��", i + 1);
//		scanf_s("%d", &val);
//
//		PNODE pNew = (PNODE)malloc(sizeof(NODE));
//		if (pNew == NULL) {
//			printf("����ʧ�ܣ�������ֹ������\n");
//			exit(-1);
//		}
//		pNew->data = val;
//		pTail->pNext = pNew;
//		pNew->pNext = NULL;
//		pTail = pNew;
//	}
//
//	return pHead;
//}
//bool is_empty(PNODE pHead) {
//	if (pHead->pNext == NULL) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//void traverse_list(PNODE pHead) {
//	if (is_empty(pHead))
//		printf("����Ϊ�գ�����\n");
//	PNODE p = pHead->pNext;
//
//	while (p != NULL) {
//		printf("%d\t", p->data);
//		p = p->pNext;
//	}
//	return;
//}


/*2022/9/16��ϰ*/
// �����洢����
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//#define bool char
//#define true 1
//#define false 0
//
//// ������һ���������ͣ����������͵����ֽ���struct arr
//// ���������ͺ���������Ա���ֱ���pBase, len, cnt
//typedef struct arr {
//	int* pBase;	// �洢�����һ��Ԫ�صĵ�ַ
//	int len;	// ������󳤶�
//	int cnt;	// ���鵱ǰ����
//}Arr, *pArr;
//
//void init_arr(pArr p, int len);		/*��ʼ����������*/
//void show_arr(pArr p);				/*������������*/
//void sort_arr(pArr p);				/*����������������*/
//bool append_arr(pArr p, int val);	/*׷�Ӻ�������*/
//bool insert_arr(pArr p, int val, int pos); /*���뺯������*/
//bool delete_arr(pArr p, int* val, int pos);	/*ɾ����������*/
//bool is_full(pArr p);				/*�Ƿ�Ϊ������*/
//bool is_empty(pArr p);				/*�Ƿ�Ϊ������*/
//
//
//int main() {
//	Arr arr;
//	init_arr(&arr, 6);	/*��ʼ�����飬���ҳ���Ϊ6*/
//	//���Ԫ��
//	for (int i = 0; i < 4; i++) {
//		if (append_arr(&arr, i + 1)) {
//			printf("���Ԫ��%d�ɹ�������\n", i + 1);
//		} 
//		else {
//			printf("���Ԫ��%dʧ�ܣ�����\n", i + 1);
//		}
//	}
//	
//	show_arr(&arr);
//	/*insert_arr(&arr, 5, 6);*/
//	int e;
//	if (delete_arr(&arr, &e, 0)) {
//		printf("ɾ��λ��%dԪ��%d�ɹ�������\n", 0, e);
//	}
//	else {
//		printf("ɾ��ʧ��!!!\n");
//	}
//	sort_arr(&arr);
//	show_arr(&arr);
//
//	return 0;
//}
//
//void init_arr(pArr p, int len) {
//	p->pBase = (pArr)malloc(sizeof(int) * len);
//	if (NULL == p->pBase) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	p->len = len;
//	p->cnt = 0;
//	return;
//}
//void show_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("����Ϊ�գ�����\n");
//	}
//
//	for (int i = 0; i < p->cnt; i++) {
//		printf("%d\t", p->pBase[i]);
//	}
//	printf("\n");
//	return;
//}
//void sort_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("����Ϊ�գ�����\n");
//	}
//	// 1 2 3 4
//	int i = 0, j = 0, t;
//	for (i = 0; i < p->cnt - 1; i++) {
//		for (j = i + 1; j < p->cnt; j++) {
//			if (p->pBase[i] < p->pBase[j]) {
//				t = p->pBase[i];
//				p->pBase[i] = p->pBase[j];
//				p->pBase[j] = t;
//			}
//		}
//	}
//}
//bool append_arr(pArr p, int val) {
//	if (is_full(p)) {
//		return false;
//	}
//	p->pBase[p->cnt] = val;
//	p->cnt++;
//	return true;
//}
//bool insert_arr(pArr p, int val, int pos) {
//	if (is_full(p)) {
//		return false;
//	}
//	if (pos < 1 || pos > p->cnt + 1) {
//		return false;
//	}
//	// 1 2 3 4
//	for (int i = p->cnt - 1; i > pos - 2; i--) {
//		p->pBase[i+1] = p->pBase[i];
//	}
//	p->pBase[pos - 1] = val;
//	p->cnt++;
//	return true;
//}
//bool delete_arr(pArr p, int* val, int pos) {
//	if (is_empty(p)) {
//		return false;
//	}
//	if (pos < 1 || pos > p->cnt) {
//		return false;
//	}
//	// 1 2 3 4  2
//	*val = p->pBase[pos - 1];
//	for (int i = pos - 1; i <= p->cnt; i++) {
//		p->pBase[i] = p->pBase[i + 1];
//	}
//	p->cnt--;
//	return true;
//}
//bool is_full(pArr p) {
//	if (p->len == p->cnt) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//bool is_empty(pArr p) {
//	if (0 == p->cnt) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}

/*2022/9/17��ϰ*/
// �����洢����
//# include<stdio.h>
//# include<malloc.h>
//# include<stdlib.h>
//
//# define bool char
//# define true 1
//# define false 0
//
//typedef struct arr {
//	int* pBase;
//	int len;
//	int cnt;
//}*pArr, Arr;
//
//void init_arr(pArr p, int len);
//void show_arr(pArr p);
//void sort_arr(pArr p);
//void traverse_arr(pArr p);
//bool append_arr(pArr p, int val);
//bool insert_arr(pArr p, int val, int pos);
//bool delete_arr(pArr p, int* val, int pos);
//bool is_full(pArr p);
//bool is_empty(pArr p);
//
//
//
//int main() {
//	Arr arr;
//	init_arr(&arr, 6);
//	for (int i = 0; i < 5; i++) {
//		if (append_arr(&arr, i + 1)) {
//			printf("���%dԪ�سɹ�!!!\n", i + 1);
//		}
//		else {
//			printf("���%dԪ��ʧ�ܣ�����\n", i + 1);
//		}
//	}
//	show_arr(&arr);
//	/*insert_arr(&arr, 88, 0);
//	int e;
//	delete_arr(&arr, &e, 0);
//	printf("%d\n", e);
//	sort_arr(&arr);*/
//	traverse_arr(&arr);
//	show_arr(&arr);
//	return 0;
//}
//
//void init_arr(pArr p, int len) {
//	p->pBase = (pArr)malloc(sizeof(int) * len);
//	if (NULL == p->pBase) {
//		printf("��̬�ڴ����ʧ�ܣ�����\n");
//		exit(-1);
//	}
//	p->len = len;
//	p->cnt = 0;
//	return;
//}
//void show_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("����Ϊ�գ�����\n");
//	}
//	for (int i = 0; i < p->cnt; i++) {
//		printf("%d\t", p->pBase[i]);
//	}
//	printf("\n");
//	return;
//}
//void sort_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("����Ϊ�գ�����\n");
//	}
//	// 1 2 3 4
//	int t;
//	for (int i = 0; i < p->cnt - 1; i++) {
//		for (int j = i + 1; j < p->cnt; j++) {
//			if (p->pBase[i] < p->pBase[j]) {
//				t = p->pBase[i];
//				p->pBase[i] = p->pBase[j];
//				p->pBase[j] = t;
//			}
//		}
//	}
//	return;
//}
//void traverse_arr(pArr p) {
//	if (is_empty(p)) {
//		printf("����Ϊ�գ�����\n");
//	}
//	else {
//		// 1 2 3 4
//		int i = 0, j = p->cnt - 1, t;
//		while (i <= j) {
//			t = p->pBase[i];
//			p->pBase[i] = p->pBase[j];
//			p->pBase[j] = t;
//			i++;
//			j--;
//		}
//	}
//	return;
//}
//bool append_arr(pArr p, int val) {
//	if (is_full(p)) {
//		return false;
//	}
//	p->pBase[p->cnt] = val;
//	p->cnt++;
//	return true;
//}
//bool insert_arr(pArr p, int val, int pos) {
//	if (is_full(p) || pos < 1 || pos > p->cnt + 1) {
//		return false;
//	}
//	for (int i = p->cnt - 1; i > pos - 2; i--) {
//		p->pBase[i + 1] = p->pBase[i];
//	}
//	p->pBase[pos - 1] = val;
//	p->cnt++;
//	return true;
//}
//bool delete_arr(pArr p, int* val, int pos) {
//	if (is_empty(p) || pos < 1 || pos > p->cnt) {
//		return false;
//	}
//	*val = p->pBase[pos - 1];
//	for (int i = pos - 1; i < p->cnt; i++) {
//		p->pBase[i] = p->pBase[i + 1];
//	}
//	p->cnt--;
//	return true;
//}
//bool is_full(pArr p) {
//	if (p->cnt == p->len) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//bool is_empty(pArr p) {
//	if (p->cnt == 0) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}

/*2022/9/19��ϰ*/
//# include<stdio.h>
//# include<malloc.h>
//# include<stdlib.h>
//
//# define bool char
//# define true 1
//# define false 0
//
//typedef struct node {
//	int data;
//	struct node* pNext;
//}*PNODE, NODE;
//
//PNODE create_list(PNODE pHead);
//void traverse_list(PNODE pHead);
//
//int main() {
//	PNODE pHead = NULL;
//	pHead = create_list(pHead);
//	traverse_list(pHead);
//	return 0;
//}
//
//PNODE create_list(PNODE pHead) {
//	pHead = (PNODE)malloc(sizeof(NODE));
//	if (NULL == pHead) {
//		printf("��̬�ڴ�����ַʧ�ܣ�����\n");
//		exit(-1);
//	}
//
//	PNODE pTail = pHead;
//	pTail->pNext = NULL;
//
//	int len, val, i;
//	printf("�����봴��������ĳ��ȣ�len = ");
//	scanf_s("%d", &len);
//
//	for (i = 0; i < len; i++) {
//		printf("�������%d���ڵ��ֵ��", i + 1);
//		scanf_s("%d", &val);
//		PNODE pNew = (PNODE)malloc(sizeof(NODE));
//		if (NULL == pNew) {
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
//void traverse_list(PNODE pHead) {
//	if (pHead->pNext == NULL) {
//		printf("����������\n");
//	}
//	else {
//		PNODE p = pHead->pNext;
//		while (p != NULL) {
//			printf("%d\t", p->data);
//			p = p->pNext;
//		}
//		printf("\n");
//	}
//	return;
//}
