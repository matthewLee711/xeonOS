#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Individual nodes in linked list
struct node {
	struct node *next;
	int key;
	int data;
};

//Linked list itself
//point to first node of ll
struct node *head = NULL;
struct node *tail = NULL;
struct node *current = NULL;


//Last in first out add
void LIFOadd(int data){
	//Create a link for linked list
	struct node *link = (struct node*)malloc(sizeof(struct node));

	//store data in new link
	link->data = data;

	//Set new link to point to first node
	link->next = head;

	//point head back to first node
	head = link;
}
//First in First out add -- insert at tail
void FIFOadd(int data){
	//Create a link for linked list
	struct node *link = (struct node*)malloc(sizeof(struct node));
	//start at head
	struct node *current = head;

	//iterate through nodes
	while(current->next != NULL) {
		//if node is not NULL, move to next
		current = current->next;
	}
	//store data in new link
	link->data = data;
	//set the last node to point to new link
	current->next = link;

	//Set new link to point to first node (circular)
	//link->next = head;
}

void delete(int data){
	//start at head
	struct node *current = head;

	//create temp node to point to nextnext node
	struct node* previous = NULL;

	while(current->data != data){
		//catch reach end of linked list
		if(current->next == NULL) {
			previous->next = current->next;
			break;
		} 
		else{
			current = current->next;
		}
	}

	//delete node
}

void print(){
	//get head of linked list
	struct node* ptr = head;

	while(ptr->next != NULL){
		printf("(%d)", ptr->data);
		//move to next node
		ptr = ptr->next;
	}

}


int main(){
	int table[] = {0,1,2,3,4,5};
	int length = sizeof(table) / sizeof(int);

	//Add elements to linked list
	for(int i =0; i < length; i++){
		FIFOadd(table[i]);
	}

	//print();

	return 0;
}