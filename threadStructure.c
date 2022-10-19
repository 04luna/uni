// Thread - Structures as Parameters
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct parameter_t{
    int data1;
    int data2;
}structure;

void* pthread_func(void* arg){
    struct parameter_t* structure = (struct parameter_t*)arg;
    printf("Data1: %d, Data2: %d",structure->data1,structure->data2);
    return NULL;
}

int main(){
    pthread_t tid;
    struct parameter_t structure = { 1, 2 };

    int error = pthread_create(&tid,NULL,pthread_func,(void*)&structure);
    if(error != 0 ){
        printf("Create thread failed! error: %d",error);
        return -1;
    }
    pthread_join(tid,NULL);
    exit(0);
}