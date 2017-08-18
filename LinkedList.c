#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void printStructure(struct node *s) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp = s;
	while(temp!=NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");

}
int main() {

	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;

	//allocate	
	head = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	third = (struct node *)malloc(sizeof(struct node));
	
	//specify
	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	//create a temparory variable
	struct node *t = (struct node*)malloc(sizeof(struct node));
	t = head;

	//print
	printf("Initial structure: ");
	printStructure(head);
	//new node
	//insertion at the front
	//create a new node, allocate, put data in, make next as head, make head point to new
	

	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data = 0;

	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp = head;

	new->next= temp;
	head=new;
	printf("Insertion at the front: ");
	printStructure(head);
	
	//insertion at the end
	//reach the end, create the node, make the end's next point to new with new's next as NULL
	
	struct node *new1 = (struct node*) malloc(sizeof(struct node));
	struct node *t1 = (struct node*) malloc(sizeof(struct node));
	t1 = head;
	new1->data = 4;
	new1->next = NULL;

	//reach the end:
	while(t1->next!=NULL) {
		t1=t1->next;
	}

	t1->next=new1;

	printf("Insertion at the end: ");
	printStructure(head);
	
	//insert after a specified element
	struct node *new2 = (struct node*) malloc(sizeof(struct node));
	//add between 2 and 3 a value 6
	new2->data = 6;
	struct node *t2  = (struct node*) malloc(sizeof(struct node));
	t2 = head;
	//increment t2 until it points to node which has 2 as data
	while(t2->data!=2) {
		t2=t2->next;
	}
	//new's next will be t2's next and t2's next will be new2 - inserting in between
	new2->next = t2->next;
	t2->next = new2;

	printStructure(head);
}

