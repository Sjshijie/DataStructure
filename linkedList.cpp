#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct Node{
    int data;
    struct Node *pNext;
}NODE,*PNODE;

PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty_list(PNODE pHead);
int length_list(PNODE pHead);
bool insert_list(PNODE,int, int);
bool delete_list(PNODE,int,int *);
void sort_list(PNODE);

int main(){
    PNODE pHead = NULL;
    pHead = create_list();
    insert_list(pHead,3,100);
    traverse_list(pHead);
    if(is_empty_list(pHead)){
        printf("����Ϊ��");
    }
    int len = length_list(pHead);
    printf("������Ϊ%d",len);
    return 0;
}

PNODE create_list(void){
    int len; // ���������Ч�ڵ�ĸ���
    int i;
    int val; //������ʱ����û�����Ľڵ��ֵ
    //������һ���������Ч���ݵ�ͷ�ڵ�
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    PNODE pTail = pHead;
    pTail->pNext = NULL;
    if(NULL==pHead){
        printf("����ʧ�ܣ�������ֹ\n");

    }
    printf("����������Ҫ���ɵ�����ڵ�ĸ�����len=");
    scanf("%d",&len);
    for (i=0;i<len;i++){
        printf("�������%d���ڵ��ֵ��",i+1);
        scanf("%d",&val);
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL==pNew){
            printf("����ʧ�ܣ�������ֹ\n");
        }
        pNew->data = val;
        pNew->pNext = NULL;
        pTail->pNext = pNew;
        pTail = pNew;

    }
    return pHead;
}

void traverse_list(PNODE pHead){
    PNODE p = pHead->pNext;
    while (NULL!=p){
        printf("%d\n",p->data);
        p=p->pNext;
    }
    return;
}

bool is_empty_list(PNODE pHead){
    if(pHead->pNext == NULL){
        return true;
    }else{
        return false;
    }
}

int length_list(PNODE pHead){
    PNODE p =pHead->pNext;
    int len = 0;
    while(NULL!=p){
        ++len;
        p=p->pNext;
    }
    return len;
}

void sort_list(PNODE pHead){

}

bool insert_list(PNODE pHead,int pos,int val){
    PNODE newNode = (PNODE)malloc(sizeof(NODE));
    newNode->data = val;
    int i =1;
    while (i<pos){
        pHead = pHead->pNext;
        i++;
    }
    PNODE next = pHead->pNext;
    pHead->pNext = newNode;
    newNode->pNext = next;
}

bool delete_list(PNODE,int,int *){

}
