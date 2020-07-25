#include<stdio.h>
#include<stdlib.h>

//Linked List Startup Deletion

struct node{
	int data;
	struct node* next;
};

struct node* q=NULL;
struct node* start=NULL;
struct node* temp=NULL;

void printNode();
void addStart(int data);
void addedNode(int data,int f_data);
void deleteEnd();

void deleteEnd(){
	
	
	q=start;
	
	while(q->next->next!=NULL){
		q=q->next;
	}
	
	free(q->next);
	q->next=NULL;
	
	
	
	
	
}
void addStart(int data){
	
	struct node* addednode=(struct node*)malloc(sizeof(struct node));
	addednode->data=data;
	addednode->next=start;
	start=addednode;
	
	
	
}
void addedNode(int data,int f_data){
	
	struct node* addednode=(struct node*)malloc(sizeof(struct node));
	addednode->data=data;
	
	q=start;
	
	while(q->next->data!=f_data){
		q=q->next;
	}
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp=q->next;
	q->next=addednode;
	addednode->next=temp;
	

}

void printNode(){
	
	
	q=start;

	while(q->next!=NULL){
		printf("%d=>",q->data);
		q=q->next;
	}
	
	printf("%d",q->data);
	
	
}

void startupDelete(){
	
	struct node* secondnode=NULL;
	secondnode=start->next;
	free(start);
	start=secondnode;
	
	
}
int main(){
	
	int addedData;
	int f_data;
	int n;
	
	
	

	while(1){
		
		printf("\nPress 1 to add an element to the beginning, or 2 to add an element before another element,\nor 3 it deletes the last element\nor 4 it deleted startup:");
	    scanf("%d",&n);
		switch(n){
			case 1:
				printf("\nEnter the value to be added at the start:");
	            scanf("%d",&addedData);
	            addStart(addedData);
	            printNode();
	            break;
	            
	            
	            
	         case 2:
			    printf("\nEnter the value to be added:");
	        	scanf("%d",&addedData);
	        	printf("Which number should be added before:");
	        	scanf("%d",&f_data);
	        	addedNode(addedData,f_data);
		        printNode();  
		        break;
		        
		     case 3:
		     	
			    deleteEnd();
				printNode();  
		        break;  
			
			case 4:
			    
				startupDelete();
				printNode();
				break;	 
		}
		
		
	}
	
	return 0;
}
