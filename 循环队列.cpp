#include <stdio.h>
#include <malloc.h>

typedef struct Queue{
    int * pBase;
    int front;
    int rear;
}QUEUE;


void init(QUEUE *);
bool en_queque(QUEUE *,int val);
void traverse_queue(QUEUE *);
bool full_queue(QUEUE *);
bool out_queue(QUEUE *,int *pVal);
bool empty_queue(QUEUE *pQ);
int main(void){

    QUEUE Q;
    init(&Q);
en_queque(&Q,1);
en_queque(&Q,2);
en_queque(&Q,3);
en_queque(&Q,4);
en_queque(&Q,5);
en_queque(&Q,6);
en_queque(&Q,7);
traverse_queue(&Q);

int val=0;

if(out_queue(&Q,&val)){
    printf("%d",val);
};
    return  0;
}
void init(QUEUE *pQ){
    pQ->pBase = (int *)malloc(sizeof(int)*6);
    pQ->front = 0;
    pQ->rear = 0;
}

bool en_queque(QUEUE * pQ,int val){
    if(full_queue(pQ)){
        return false;
    }else{
        pQ->pBase[pQ->rear] = val;
        pQ->rear =(pQ->rear + 1)%6;
        return true;
    }
}

bool full_queue(QUEUE *pQ){
    if((pQ->rear+1)%6==pQ->front){
        return true;
    }else{
        return false;
    }
};

void traverse_queue(QUEUE *pQ){
    int i = pQ->front;
    while(i!=pQ->rear){
        printf("%d",pQ->pBase[i]);
        i=(i+1)%6;
    }
    return;
};

bool out_queue(QUEUE *pQ,int *pVal){
    if(empty_queue(pQ)){
        return false;
    }else{
        *pVal = pQ->pBase[pQ->front];
        pQ->front=(pQ->front+1)%6;
        return true;
    }

}

bool empty_queue(QUEUE *pQ){
    if(pQ->front == pQ->rear){
        return true;
    }else{
        return false;
    }
}

