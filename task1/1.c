#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct list{
    double data;
    struct list* next;
};

void sumA();
void sumB();

//入力するデータはデータセットの例と同じものを使用
void main(){

    sumA();
    sumB();
}

void sumA(){
    double* p;
    int n;
    int i;
    double sum = 0;
    printf("function a\n");
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
    printf("A is sum : %f", sum);
    free(p);
    printf("\n");
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
    double sum = 0;
    //データ入力および線形リストの作成
    printf("function b\n");
    printf("if finish input data,you input ctrl+z\n");
    while(scanf("%lf", &data) != EOF){
        if(n == 0){
            p = (struct list*)malloc(sizeof(struct list));
            p -> data = data;
            p -> next = NULL;
            head = p;
            start = head;
            laststart = start;
        }
        else{
            p -> next = (struct list*)malloc(sizeof(struct list));
            p = p -> next;
            p -> data = data;
            p -> next = NULL;
        }
        n++;
    }
    
    // 昇順にソート
    for(i = 0; i < n - 1; i++){
        current = start;
        min = INFINITY;
        //最小値の探索
        for(j = i; j < n; j++){
            if(fabs(current -> data) < fabs(min)){
                min = current -> data;
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
    while(current != NULL){

        printf("%f\n", sum += current -> data);
        current = current -> next;
    }
    printf("B is sum : %f", sum);
    free(p);
    free(head);
    free(laststart);
    free(current);
    free(lastcurrent);
}
// データセット
// 1.0e16
// -1.0e2
// 23
// -6.4
// 3.6e2
// -0.01
// 8.0
// -70
// 5.0e3
// 1.2e-2
// -3.0e3
// 46
// -1.7e3
// 10
// -5.0e2
// 7.0
// -2.0e-3
// 0.3
// -30
// 3.1
// -1.0e16