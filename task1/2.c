#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct human{
    char firstName[256];
    char lastName[256];
    struct human* next;
};

void main(){
    struct human* head;
    struct human* laststart;
    struct human* start;
    struct human* lastcurrent;
    struct human* current;
    struct human* end;
    struct human* lastend;
    struct human* copyList;
    
    int n = 0;
    int minNum;
    int i,j,judge;

    char min[256];
    
    //データ入力および線形リストの作成
    printf("Enter firstname to lastname in order\n");
    do{
        if(n == 0){
            end = (struct human*)malloc(sizeof(struct human));
            printf("firstname\n");
            scanf("%s", end -> firstName);
            printf("lastname\n");
            scanf("%s", end -> lastName);
            end -> next = NULL;
            head = end;
            start = head;
            laststart = head;
            current = head;
            lastcurrent = head;
            lastend = head;
        }
        else{
            end -> next = (struct human*)malloc(sizeof(struct human));
            lastend = end;
            end = end -> next;
            printf("firstname\n");
            scanf("%s", end -> firstName);
            printf("lastname\n");
            scanf("%s", end -> lastName);
            end -> next = NULL;
            //lastnameでソート
            current = head;
            lastcurrent = head;
            while(current != NULL){
                if(strcmp(current -> lastName, end -> lastName) > 0){
                    if(current == head){
                        end -> next = head;
                        head = end;
                    }
                    else{
                        lastcurrent -> next = end;
                        end -> next = current;
                    }
                    lastend -> next = NULL;
                    end = lastend;
                }
                lastcurrent = current;
                current =  current -> next;
            }       
        }
        n++;
        // printf("%s\n", end -> lastName);
        // printf("%s\n", end -> firstName);

        printf("Enter 0 when you want to quit\n");
        scanf("%d", &judge);
    }while(judge != 0);

    current = head;
    n = 0;
    //出力と同時にデータを別の線形リストに複写
    printf("lastname sort\n");
    while(current != NULL){
        printf("lastname %s ", current -> lastName);
        printf("fistname %s\n", current -> firstName);
        printf("\n");
        if(n == 0){
            copyList = (struct human*)malloc(sizeof(struct human));
            strcpy(copyList -> firstName, current -> firstName);
            strcpy(copyList -> lastName, current -> lastName);
            copyList -> next = NULL;
            head = copyList;
        }
        else{
            copyList -> next = (struct human*)malloc(sizeof(struct human));
            copyList = copyList -> next;
            strcpy(copyList -> firstName, current -> firstName);
            strcpy(copyList -> lastName, current -> lastName);
            copyList -> next = NULL;
        }
        current = current -> next;
        n++;
    }
    current = head;
    start = head;
    lastcurrent = head;
    laststart = head;
    //firstname順にソート
    for(i = 0; i < n - 1; i++){
        current = start;
        strcpy(min, start -> firstName);
        //最小値の探索
        for(j = i; j < n; j++){
            if(strcmp(min, current -> firstName) > 0){
                strcpy(min, current -> firstName);
                minNum = j;
            }
            current = current -> next;
        }
        
        current = head;
        lastcurrent = current;
        current = head;

        //挿入するためのノードの移動
        for(j = 0; j < minNum; j++){
            lastcurrent = current;
            current = current -> next;
        }

        //挿入
        if(current != start){
            lastcurrent -> next = current -> next;
            current -> next = start;
            if(laststart == start){
                head = current;
            }
            else{
                laststart -> next = current;
            }
            laststart = current;
        }
        else{
            laststart = current;
            start = current -> next;
        }
    }
    current = head;
    printf("firstname sort\n");
    while(current != NULL){
        printf("lastname %s ", current -> lastName);
        printf("firstname %s\n", current -> firstName);
        printf("\n");
        current = current -> next;
    }
    free(end);
    free(lastend);
    free(head);
    free(laststart);
    free(current);
    free(lastcurrent);
    free(start);
    free(copyList);
}