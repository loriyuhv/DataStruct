#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

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
	head = (struct node*)malloc(sizeof(struct node));
	if (head == NULL) {
		exit(-1);
	}
	one = (struct node*)malloc(sizeof(struct node));
	if (one == NULL) {
		exit(-1);
	}
	two = (struct node*)malloc(sizeof(struct node));
	if (two == NULL) {
		exit(-1);
	}
	three = (struct node*)malloc(sizeof(struct node));
	if (three == NULL) {
		exit(-1);
	}

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

	/* If you wanted to put an element 4
	between 1 and 2, the steps would be:*/
	
	/*step1£ºcreate a new struct node and 
	allocate memory to it*/
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	if (new_node == NULL) {
		exit(-1);
	}
	/*step2: Add its data value as 4 */
	new_node->data = 4;
	/*step3: Point its next pointer to the struct node containing 2 
	as the data value*/
	new_node->next = two;
	/*step4: Change the next pointer of "1" 
	to the node we just created*/
	one->next = new_node;

	/*If you wanted to put an element 88 between 2 and 3, the steps
	would be:*/
	/* Step1: Create a new struct node and allocate memory to it*/
	struct node* new2_node = (struct node*)malloc(sizeof(struct node));
	if (new2_node == NULL) {
		exit(-1);
	}
	/* Step2: Add its data value as 88*/
	new2_node->data = 88;
	/* Step3: Point the(its) next pointer 
	to the struct node containing 3 as the data value*/
	new2_node->next = three;
	/* Step4: Change the next pointer of "2" to the node 
	we just created*/
	two->next = new2_node;

	struct node* p;
	p = head->next;
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	return 0;
}