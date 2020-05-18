#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct branch{
    double data;
    int flag;
    struct branch* left;
    struct branch* right;
};

struct tree{
    struct branch* head;
};

struct tree* initTree(double data);
struct branch* initBranch(double data);
void addBranch(struct tree* ptree, double data);
double returnSumsElement(struct tree* ptree);

void main(){
    struct tree* ptree = NULL;
    int i = 0;
    int n = 0;
    double data;
    double sum = 0;
    double element;
    printf("if finish input data,you input ctrl+z\n");
    while(scanf("%lf", &data) != EOF){
        if(n == 0){
            ptree = initTree(data);
        }
        else{
            addBranch(ptree, data);
        }
        n++;
    }
    printf("make tree");
    //計算していく
    for(i = 0;i < n; i++){
        element = returnSumsElement(ptree);
        sum += element;
        printf("%f\n", sum);
    }
}

struct branch* initBranch(double data){
    struct branch* p = NULL;
    p = (struct branch*)malloc(sizeof(struct branch));
    if(p == NULL){
        printf("init not found\n");
    }
    p -> data = data;
    p -> flag = 0;//計算済みか判断するflag
    p -> right = NULL;
    p -> left = NULL;
    return p;
}

struct tree* initTree(double data){
    struct tree* plist = NULL;
    plist = (struct tree*)malloc(sizeof(struct tree));
    plist -> head = initBranch(data);
    return plist;
}

void addBranch(struct tree* ptree, double data){
    struct branch* pbranch = ptree -> head;
    while(1){
        if(fabs(data) <= fabs(pbranch -> data)){
            //左に
            if(pbranch -> left == NULL){
                pbranch -> left = initBranch(data);
                break;
            }
            else{
                pbranch  = pbranch -> left;
            }
        }
        else{
            //右に
            if(pbranch -> right == NULL){
                pbranch -> right = initBranch(data);
                break;
            }
            else{
                pbranch  = pbranch -> right;
            }
        }
    }
}

double returnSumsElement(struct tree* ptree){
    double element;
    struct branch* pbranch = ptree -> head;
    while(1){
        if((pbranch -> left != NULL) && (pbranch -> left -> flag == 0)){
            pbranch = pbranch -> left;
        }
        else if((pbranch -> left -> flag == 1) && (pbranch -> flag == 1) && (pbranch -> right != NULL)){
            pbranch = pbranch -> right;
        }
        else{
            element = pbranch -> data;
            printf("%f\n", pbranch -> data);
            pbranch -> flag = 1;
            break;
        }
    }
    return element;
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