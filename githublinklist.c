#include<stdio.h>
#include<stdlib.h>
typedef struct nodetype{
	int info;
	struct nodetype *next;
} node ;
void insertatbeg(node**start,int item ){
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=*start;
	*start=ptr;
}
void insertatend(node **start,int item){
	node *ptr,*last;
	ptr=(node*)malloc(sizeof(node));
	ptr ->info=item;
	ptr ->next=NULL;
	if(*start==NULL){
		*start=ptr;
	}
	else{
		last=*start;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=ptr;
	}
}
void display(node *start){
	if(start==NULL){
		printf("\n ll is empty");
		return;
	}
	while(start!=NULL){
		printf("%d ->",start->info);
		start=start->next;
	}
}
void deleteatbeg(node **start){
	node *ptr;
	if(*start == NULL){
		printf("\n LL is empty");
		return ;
	}
	ptr=*start;
	*start=ptr->next;
	printf("\n deleted valu=%d",ptr->info);
	free(ptr);
}
void deleteatend(node **start){
	node *ptr,*last;
	if(*start== NULL){
		printf("\n LL is empty");
		return;
	}
	if((*start)->next==NULL){
		ptr=*start;
		*start=ptr->next;
	}
	else{
		last=*start;
		while(last->next->next!=NULL){
			last=last->next;
		}
		ptr=last->next;
		last->next=NULL;
	}
	printf("\n deleted valu=%d",ptr->info);
	free(ptr);
}
void displayinrev(node*start){
	if(start->next!=NULL)
	{
		displayinrev(start->next);
		printf("%d ->",start->info);
	}
}
node *search(node *start,int key){
	while(start!=NULL && start->info!=key){
		start=start->next;
	}
	return start;
}
void insertafterloc(node *start,int item ,int after){
	node *ptr,*loc;
//	while(start!=NULL && start->info!=after){
//		start=start->next;
//		loc=start;
//	}
    loc =search(start,after);
	if(loc==NULL){
		printf("loc not found");
		return;
	}
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=loc->next;
	loc->next=ptr;
	
}
int main(){
	int item,choice,after;
	node *head,*loc;
	head=loc=NULL;
	printf("\n  linked list menu   \n");
	printf("\n 1. inseratbeg");
	printf("\n 2. inseratend");
	printf("\n 3. deleteatbeg");
	printf("\n 4. deleteatend");
	printf("\n 5. display");
	printf("\n 6. displayinrev");
	printf("\n 7. Insert after location");
	printf("\n 8. exit");
		
	while(1){
		printf("\n enter your choice");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter item=");
				scanf("%d",&item);
				insertatbeg(&head,item);
				break;
			case 2:
				printf("enter item=");
				scanf("%d",&item);
				insertatend(&head,item);
				break;
			case 3:
				deleteatbeg(&head);
				break;
			case 4:
				deleteatend(&head);
				break;
			case 5:
				display(head);
				break;
			case 6:
				displayinrev(head);
				break;
			case 7:
				printf("enter item=");
				scanf("%d",&item);
				printf("enter the location");
				scanf("%d",&after);
				insertafterloc(head,item,after);
				break;
			default:
				exit(1);
		}
	}
}
