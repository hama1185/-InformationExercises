#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    int priority;
    struct node* next;
};

struct list{
    struct node* head;
};

struct node* initNode(char data);
struct list* initList(char data);
void push(struct list* plist, char data);
void pop(struct list* plist);

void main(){
    struct list* plist = NULL;
    plist = initList('A');
    push(plist,'B');
    push(plist,'C');
    pop(plist);
}

struct node* initNode(char data){
    struct node* p = NULL;
    p = (struct node*)malloc(sizeof(struct node*));
    p -> data = data;
    if(data == '*' || data == '/'){
        p -> priority = 3;
        
    }
    else if(data == '+' || data == '-'){
        p -> priority = 2;
    }
    else if(data == '('){
        p -> priority = 4;
    }
    else if(data == ')'){
        p -> priority = 1;
    }
    else if(data == '='){
        p -> priority = 0;
    }
    else{
        p -> priority = 5;
    }
    p -> next = NULL;
    return p;
}

struct list* initList(char data){
    struct list* plist = NULL;
    plist = (struct list*)malloc(sizeof(struct list*));
    plist -> head = initNode(data);
    return plist;
}

void push(struct list* plist, char data){
    struct node* pNode = NULL;
    pNode = plist -> head;
    while(pNode -> next != NULL){
        pNode = pNode -> next;
    }
    pNode ->next = initNode(data);
    printf("push is %c \n",pNode->next->data); 
}

void pop(struct list* plist){
    struct node* previousNode = NULL;
    struct node* pNode = NULL;
    previousNode = plist -> head;
    pNode = plist -> head;
    while(pNode -> next != NULL){
        previousNode = pNode;
        pNode = pNode -> next;
    }
    previousNode -> next = NULL;
    if(pNode == plist -> head){
        plist -> head = NULL;
    }
    printf("pop is %c \n",pNode->data);
    free(pNode);
}