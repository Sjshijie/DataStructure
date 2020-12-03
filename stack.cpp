#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct Node{
    int data;
    struct Node * pNext;
}NODE,* PNODE;

typedef struct Stack{
    PNODE pTop;
    PNODE pBottom;
}STACK, * PSTACK;

void init(PSTACK);

void push(PSTACK,int);

void traverse(PSTACK);

bool pop(PSTACK,int *);

int main(){
    int val;

    STACK S;

    init(&S);

    push(&S,-1);

    push(&S,88);

    push(&S,8);

    pop(&S,&val);

    traverse(&S);

    return 0;
}

void init(PSTACK pS){
    pS->pTop=(PNODE)malloc(sizeof(NODE));
    if(NULL == pS->pTop){
        printf("¶¯Ì¬·ÖÅäÄÚ´æÊ§°Ü!\n");
        exit(-1);
    }else{
        pS->pBottom=pS->pTop;
        pS->pTop->pNext = NULL;
    }
};

void push(PSTACK pS,int val){
    PNODE node = (PNODE)malloc(sizeof(NODE));
    node->data = val;
    node->pNext = pS->pTop;
    pS->pTop = node;
};

void traverse(PSTACK pS){
    PNODE p = pS->pTop;
    while(p != pS->pBottom){
        printf("%d\n",p->data);
        p=p->pNext;

    }
    return;
};

bool pop(PSTACK pS,int * pVal){

};

