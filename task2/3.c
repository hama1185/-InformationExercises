#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int returnStackPriority(struct list* plist);
int returnInputCharPriority(char data);

void main(){
    struct list* plist = NULL;
    char inputFormula[30];
    int i;

    printf("input your formula\n");
    scanf("%s", inputFormula);
    for(i = 0;i < strlen(inputFormula); i++){
        if(i == 0){
            plist = initList(inputFormula[i]);
        }
        else{
            while((plist -> head != NULL)&&
            (returnStackPriority(plist) != 4)&&
            (returnInputCharPriority(inputFormula[i]) <= returnStackPriority(plist))){
                pop(plist);
            }
            if(returnInputCharPriority(inputFormula[i]) == 1){
                //出力せずにポップ
                pop(plist);
            }
            else{
                //プッシュ
                push(plist, inputFormula[i]);
            }
        }
    }
    while(plist -> head != NULL){
        pop(plist);
    }    
}

struct node* initNode(char data){
    struct node* p = NULL;
    p = (struct node*)malloc(sizeof(struct node*));
    if(p == NULL){
        printf("init not found\n");
    }
    p -> data = data;
    p -> priority = returnInputCharPriority(p-> data);
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
    if(plist -> head == NULL){
        plist -> head = initNode(data);
        pNode = plist -> head;
    }
    else{
        pNode = plist -> head;
        while(pNode -> next != NULL){
            pNode = pNode -> next;
        }
        pNode ->next = initNode(data);//なんかうまくいかない
    }
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
    if((pNode->data != '(') && (pNode->data != ')')){
        printf("%c",pNode->data);
    }
    free(pNode);
}

int returnStackPriority(struct list* plist){
    struct node* pNode = NULL;
    pNode = plist -> head;
    while(pNode -> next != NULL){
        pNode = pNode -> next;
    }
    return pNode -> priority;
}

int returnInputCharPriority(char data){
    int priority;
    if(data == '*' || data == '/'){
        priority = 3;     
    }
    else if(data == '+' || data == '-'){
        priority = 2;
    }
    else if(data == '('){
        priority = 4;
    }
    else if(data == ')'){
        priority = 1;
    }
    else if(data == '='){
        priority = 0;
    }
    else{
        priority = 5;
    }
    return priority;
}