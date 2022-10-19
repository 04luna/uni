// Creating Threads - Passing integer parameters
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void* thread_function(void* arg){

    int id = (int)arg;
    switch(id){
        case 1: sleep(1); break;
        case 2: sleep(2); break;
        case 3: sleep(3); break;
        case 4: sleep(4); break;
    }
    static int s = 0;
    ++s;
    //Function for the thread
    printf("From the thread of id: %d, and value of s is: %d\n",id,s);
    return NULL;
}

int main(){
    int i=0;
    pthread_t tid[5];
    for(i=0;i<5;++i){
        pthread_create(&tid[i],NULL,thread_function,(void*)i);
    }
    for(i=0;i<5;++i){
        pthread_join(tid[i],NULL);
    }
    exit(0);
}