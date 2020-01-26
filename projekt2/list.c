#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct Node Node;

struct Node{
	int val;
	Node* next;
};

struct List{
	Node* head;
};

List * create_list(void){
List *L = (List *)malloc(sizeof(List));
L->head=NULL;
return L;
}

void clear_list(List * list)
{
Node* tmp;
Node* hd=list->head;
while(hd!=NULL)
{
tmp=hd;
hd=hd->next;
free(tmp);
}
}

void destroy_list(List ** list){
clear_list(*list);
free(*list);
}

void append_to_list(List * list, int elem)
{
Node* tmp = (Node *)malloc(sizeof(Node));
Node* ptr = &list->head;
printf("%p\n",list->head);
printf("tmp: %p\n",tmp);
printf("tmp next: %p\n",tmp->next);
printf("ptr: %p\n",ptr);
printf("ptr next: %p\n",ptr->next);

tmp->val = elem;
while(ptr->next!=NULL) ptr=ptr->next;
ptr->next=tmp;
tmp->next=NULL;
printf("tmp: %p\n",tmp);
printf("tmp next: %p\n",tmp->next);
printf("ptr: %p\n",ptr);
printf("ptr next: %p\n",ptr->next);
}

void test_1(void){
List *a=create_list();
destroy_list(&a);
}

int main(){
List* a = create_list();
printf("Printed!");
append_to_list(a,5);
//append_to_list(a,15);
//append_to_list(a,123);
destroy_list(&a);
return 0;
}
