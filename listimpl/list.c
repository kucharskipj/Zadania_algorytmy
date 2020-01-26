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

void destroy_list(List ** list){
clear_list(*list);
free(*list);
}

int count_elements(List * list){
int ele_nr = 0;
Node* ptr = list->head;
while(ptr!=NULL){
ptr=ptr->next;
ele_nr++;
}
return ele_nr;
}

void append_to_list(List * list, int elem){
Node* tmp = (Node *)malloc(sizeof(Node));
Node** ptr = &list->head;
while((*ptr)!=NULL){
ptr=&(*ptr)->next;
}
tmp->val = elem;
tmp->next=NULL;
*ptr=tmp;
}

int get_nth_element(List * list, int index){
Node* ptr = list->head;
int val;
if (index > count_elements(list)){
printf("Element spoza zakresu!\n");
return -1;
}
while (index != 0){
index--;
ptr=ptr->next;
}
val = ptr->val;
return val;
}

void remove_nth_element(List * list, int index){
if (index >= count_elements(list)){
printf("Element spoza zakresu!\n");
return;
}
Node* tmp;
Node** ptr = &list->head;
while (index != 0){
ptr=&(*ptr)->next;
index--;
}
tmp=*ptr;
*ptr=(*ptr)->next;
free(tmp);
}

void clear_list(List * list){
int z = count_elements(list);
for (int i=0;i<z;i++)
{
remove_nth_element(list,0);
}
}

void insert_to_list(List * list, int elem, int index){
if (index >= count_elements(list)){
printf("Element spoza zakresu!\n");
return;
}
Node** ptr = &list->head;
Node* ele = (Node *)malloc(sizeof(Node));
ele->val=elem;
while (index != 0){
ptr=&(*ptr)->next;
index--;
}
ele->next=(*ptr);
*ptr=ele;
}

void sort_list(List * list){
int list_len = count_elements(list);
int tmp;
for (int j=0; j<list_len;j++){
tmp=0;
for(int i=0; i<list_len-j;i++)
{
if (get_nth_element(list,tmp) > get_nth_element(list,i)) tmp = i;
}
append_to_list(list,get_nth_element(list,tmp));
remove_nth_element(list,tmp);
}
}

void reverse_list(List * list){
int list_len = count_elements(list);
for(int i = 1;i<list_len;i++){
insert_to_list(list,get_nth_element(list,i),0);
remove_nth_element(list,i+1);
}
}

