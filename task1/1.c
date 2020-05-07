#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct list{
    double data;
    struct list *next;
};

void sumA();
void sumB();

//入力するデータはデータセットの例と同じものを使用
void main(){
    // sumA();
    sumB();
}

void sumA(){
    double* p;
    int n;
    int i;
    double sum = 0;

    printf("How many data:\n");
    scanf("%d", &n);

    p = (double*)malloc(sizeof(double) * n);
    
    printf("Input your data\n");
    for(i = 0; i < n; i++){
        scanf("%lf", &p[i]);
        printf("data%d : %f\n", i+1, p[i]);
    }
    for(i = 0; i < n; i++){
        sum += p[i];
        printf("%f\n", sum);
    }
    printf("sum : %f", sum);
    free(p);
}

void sumB(){
    //単純挿入ソート
    struct list* head;
    struct list* laststart;
    struct list* start;
    struct list* lastcurrent;
    struct list* current;
    struct list* p;
    double data;
    int n = 0;
    int minNum;
    int i,j;
    double min;
    //データ入力および線形リストの作成
    while(scanf("%lf", &data) != EOF){
        if(n == 0){
            p = (struct list*)malloc(sizeof(struct list));
            p -> data = data;
            head = p;
            start = head;
            laststart = start;
        }
        else{
            p -> next = (struct list*)malloc(sizeof(struct list));
            p = p -> next;
            p -> data = data;
        }
        n++;
    }
    //昇順にソート
    for(i = 0; i < n - 1; i++){
        current = start;
        min = INFINITY;
        //最小値の探索
        for(j = i; j < n; j++){
            if(fabs(current -> data) < min){
                min = current -> data;
                minNum = j;
            }
            current = current -> next;
        }
        printf("min :%f\n", min);
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
    while(current != NULL){
        printf("%f\n", current -> data);
        current = current -> next;
    }
    free(p);
    free(head);
    free(laststart);
    free(current);
    free(lastcurrent);
}