//
// Created by msi on 4/15/2022.
//
#include <malloc.h>
#include <stdio.h>
#ifndef CLION_PROJECTS_LINKEDLIST_H
#define CLION_PROJECTS_LINKEDLIST_H
#endif //CLION_PROJECTS_LINKEDLIST_H
typedef struct node* node_ptr; // define new datatype struct node*
typedef node_ptr List;
struct  node{
    int data;
    node_ptr  next;
};
void Insert(int Int_data , List  L , node_ptr  Pos){// Adding node to the list after position P
    struct node*temp;  // pointer to the node
    temp = (struct  node*) malloc(sizeof(struct  node));
    if(temp != NULL){
        temp->data=Int_data;
        temp->next = Pos->next;
        Pos->next = temp;
    }
}
int isExist(List L){
    return L != NULL;
}
int isEmpty( List l) {
    if (isExist(l)) {
        return l->next == NULL;
    } else {
        printf("your List is not Exist !");
        return 0;
    }
    //only head in it

}
int  isLast( List l , node_ptr P){
    return  P->next == NULL;

}

void  printList( List l ) {
    struct node *p;
    p = l;
    if (isEmpty(l)) {
        printf("Empty list !");
    } else {
        do {
            p = p->next;
            printf("%d ", p->data);
        } while (!isLast(l, p));
        printf("\n");
    }

}
int sizeOfLinkedList( List l ){
    node_ptr  p ;
    p = l->next;
    int  counter=0;
    while (p != NULL){
        counter++;
        p= p->next;
    }
    return  counter;
}
void  delete_all_List( List l){// all elements
    node_ptr p,temp;
    p = l->next;
    l->next = NULL;
    while ( p != NULL){
        temp = p->next;
        free(p);
        p = temp;
    }
}
node_ptr  find(int x, List l){// Search on data in the nodes
    if(!isExist(l)){
        return  NULL;
    }
    node_ptr  p;
    p = l->next;
    while (p!= NULL && p->data != x){
        p = p->next;
    }
    return  p;
}
node_ptr  findPrevious(int x,  List l){
    node_ptr  p;
    p = l;
    if(!isExist(l)){
        return  NULL;
    }
    while (p->next != NULL && p->next->data !=x){
        p = p->next;
    }
    return  p;
}
void  deleteNode(int  x, List l){
    node_ptr p,temp;
    p = findPrevious(x,l);
    if(!isLast(l,p)){
        temp = p->next;
        p->next=temp->next;
        free(temp);
    }
}
