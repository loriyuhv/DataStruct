#include <stdio.h>
#include <malloc.h>

struct node {
	int data;	/*a data item*/
	struct node* next; /*an address of another node*/
};

int main() {
	/*initialize node*/
	struct node* head = NULL;
	struct node* one = NULL;
	struct node* two = NULL;
	struct node* three = NULL;

	/*Allocate memory*/
	head = malloc(sizeof(struct node));
	one = malloc(sizeof(struct node));
	two = malloc(sizeof(struct node));
	three = malloc(sizeof(struct node));

	/*Assign data values*/
	one->data = 1;
	two->data = 2;
	three->data = 3;
	/*Connect nodes */
	one->next = two;
	two->next = three;
	three->next = NULL;

	/* Save address of first node in head */
	head->next = one;
	
	struct node* p;
	p = head->next;
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	return 0;
}