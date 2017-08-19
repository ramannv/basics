#include <stdio.h>
#include <stdlib.h>
//ASSUMING THE LIST IS NOT EMPTY!
struct node {
	int i;
	struct node *next;
};
struct node* push(struct node *head, int num) {
	//create a node
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->i = num;
	new->next=head;
	head=new;
	return head;
}

struct node* pop(struct node *head) {
	struct node* t = head;
	t=head->next;
	free(head);
	head=t;
	return head;	
}

void print(struct node *head) {
	struct node *t = head;
	if(t){
		printf("%d ", t->i);
		print(t->next);
	}
	else printf("\n");
}
int main() {
	struct node *head = (struct node*)malloc(sizeof(struct node));
	struct node *e1 = (struct node*)malloc(sizeof(struct node));
	struct node *e2 = (struct node*)malloc(sizeof(struct node));
	struct node *e3 = (struct node*)malloc(sizeof(struct node));

	e1->i = 4;
	e2->i = 5;
	e3->i = 6;
	e1->next=e2;
	e2->next=e3;
	head=e1;
	print(head);
	head=push(head, 10);
	print(head);
	head=	pop(head);
	print(head);
	head=push(head, 11);
	head=push(head, 12);
	print(head);
	head=pop(head);;
	print(head);
}

