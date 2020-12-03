#include <iostream>
#include <malloc.h>

using namespace std;

//������һ����������
struct ArrayList{
    int *pBase; //�洢���������һ��Ԫ�صĵ�ַ
    int len; //�����������ɵ����Ԫ�صĸ���
    int cnt; //��ǰ������ЧԪ�صĸ���
    //int increment; //�Զ���������
};


void init_arr(struct ArrayList* arr,int len);
bool append_arr(struct ArrayList* arr,int val); //׷��
bool insert_arr(struct ArrayList* arr,int position, int val);
bool delete_arr(struct ArrayList* arr,int position, int *pVal);
int get();
bool is_empty_arr(struct ArrayList* arr);
bool is_full(struct ArrayList* arr);
void sort_arr(struct ArrayList* arr);
void show_arr(struct ArrayList* arr);
void inversion_arr(struct ArrayList* arr); // ����


int main()
{
    int val;
    struct ArrayList arr;
    init_arr(&arr,6);
    append_arr(&arr,1);
    append_arr(&arr,2);
    append_arr(&arr,3);
    append_arr(&arr,4);
    append_arr(&arr,5);
    append_arr(&arr,6);
    insert_arr(&arr,6,100);

    delete_arr(&arr,1,&val);

    inversion_arr(&arr);
    show_arr(&arr);
}

void init_arr(struct ArrayList* arr,int len){
    arr->pBase =(int *)malloc(sizeof(int)*len);
    if(NULL == arr->pBase){
        printf("��̬�ڴ����ʧ��");
        exit(-1);//��ֹ��������
    }else{
        arr->len = len;
        arr->cnt = 0;
    }
    return;
}

void show_arr(struct ArrayList* arr){
    if(is_empty_arr(arr)){
        printf("����Ϊ��");
    }else{
       for (int i =0;i<arr->cnt; i++){
            printf("%d\n",arr->pBase[i]);
        }
    }

}

bool is_empty_arr(struct ArrayList* arr){
    if(arr->cnt == 0)
        return  true;
    else
        return false;

}

bool is_full(struct ArrayList* arr){
    if(arr->cnt == arr->len){
        return true;
    }else{
        return false;
    }
};

bool append_arr(struct ArrayList* arr,int val){
    if(is_full(arr)){
        return false;
    }else{
        (arr->pBase)[arr->cnt]=val;
        (arr->cnt)++;
        return true;
    }
}

bool insert_arr(struct ArrayList* arr,int pos, int val){
     if(pos<1 || pos > arr->cnt+1) return false;
     int i;
     for(i=arr->cnt-1;i>=pos-1;--i){
            if(i+1 < arr->len){
                (arr->pBase)[i+1] = (arr->pBase)[i];
            }else{
                printf("--------\n");
            }

     }

     (arr->pBase)[pos-1]=val;
     if(arr->cnt < arr->len){
        (arr->cnt)++;
     }

     return true;
}

bool delete_arr(struct ArrayList* arr,int pos, int *pVal){
    if(is_empty_arr(arr)){
        return false;
    }
    if(pos<1 || pos>arr->cnt){
        return false;
    }

    *pVal = arr->pBase[pos-1];

    for(int i = pos ; i<arr->cnt ; i++){
        arr->pBase[i-1] = arr->pBase[i];
    }

    arr->cnt--;


}

void inversion_arr(struct ArrayList* arr){
     int i=0;
     int j=arr->cnt-1;
     int t;
     while(i<j){
        t=arr->pBase[i];
        arr->pBase[i]=arr->pBase[j];
        arr->pBase[j]=i;
        j--;
        i++;
     }
}

void sort_arr(struct ArrayList* arr){

};
