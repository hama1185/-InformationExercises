#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct human{
    char* firstName;
    char* lastName;
    struct human* next;
};

void main(){
    struct human* head;
    struct human* laststart;
    struct human* start;
    struct human* lastcurrent;
    struct human* current;
    struct human* p;
    char firstname[256];
    char lastname[256];
    int n = 0;
    int minNum;
    int i,j;
    
    //データ入力および線形リストの作成
    printf("Enter firstname to lastname in order\n");
    while(scanf("%s", firstname) != EOF){
        if(scanf("%s", lastname) == EOF){
            break;
        }
        if(n == 0){
            p = (struct human*)malloc(sizeof(struct human));
            p -> firstName = firstname;
            p -> lastName = lastname;
            p -> next = NULL;
            head = p;
            start = head;
        }
        else{
            p -> next = (struct human*)malloc(sizeof(struct human));
            p = p -> next;
            p -> firstName = firstname;
            p -> lastName = lastname;
            p -> next = NULL;
        }
        n++;
        printf("%s\n", p -> lastName);
        printf("%s\n", p -> firstName);
    }
    // current = head;
    // while(current != NULL){
    //     printf("%f\n", current -> data);
    //     current = current -> next;
    // }
    //昇順にソート
    // for(i = 0; i < n - 1; i++){
    //     current = start;
    //     min = INFINITY;
    //     //最小値の探索
    //     for(j = i; j < n; j++){
    //         if(fabs(current -> data) < min){
    //             min = current -> data;
    //             minNum = j;
    //         }
    //         current = current -> next;
    //     }
    //     printf("min :%f\n", min);
    //     current = head;
    //     lastcurrent = current;
    //     current = head;

    //     //挿入するためのノードの移動
    //     for(j = 0; j < minNum; j++){
    //         lastcurrent = current;
    //         current = current -> next;
    //     }

    //     //挿入
    //     if(current != start){
    //         lastcurrent -> next = current -> next;
    //         current -> next = start;
    //         if(laststart == start){
    //             head = current;
    //         }
    //         else{
    //             laststart -> next = current;
    //         }
    //         laststart = current;
    //     }
    //     else{
    //         laststart = current;
    //         start = current -> next;
    //     }
    // }

    current = head;
    while(current != NULL){
        printf("%s\n", current -> lastName);
        printf("%s\n", current -> firstName);
        current = current -> next;
    }
    free(p);
    free(head);
    free(laststart);
    free(current);
    free(lastcurrent);
}