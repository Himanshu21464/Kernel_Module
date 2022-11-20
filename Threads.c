#include<stdio.h>
#include<sched.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>

pthread_attr_t tattr;

void Count_A(){
    int z=1;
    for(long long int i=1;i<=4294967296;i++){
        z++;
    }
}

void Count_B(){
    int z=1;
    for(long long int i=1;i<=4294967296;i++){
        z++;
    }
}
void Count_C(){
    int z=1;
    for(long long int i=1;i<=4294967296;i++){
        z++;
    }
}

void *THREAD_A(void *ptr){   
    clock_t start,end;
    double cpu_time_used;
    start=clock();
    Count_A();
    Count_B();
    Count_C();
    end=clock();
    cpu_time_used=(double)(end-start);
    printf("Time taken by OTHER scheduling: %f\n",cpu_time_used);
    
}

void *THREAD_B(void *ptr){
    
    clock_t start,end;
    double cpu_time_used;
    start=clock();
    Count_A();
    Count_B();
    Count_C();
    end=clock();
    cpu_time_used=(double)(end-start);
    printf("Time taken by FIFO scheduling: %f\n",cpu_time_used);
   
}

void *THREAD_C(void *ptr){
    clock_t start,end;
    double cpu_time_used;
    start=clock();
    Count_A();
    Count_B();
    Count_C();
    end=clock();
    cpu_time_used=(double)(end-start);
    printf("Time taken by RR scheduling: %f\n",cpu_time_used);
}
int main(){

    pthread_t thread1, thread2, thread3;
    int t1,t2,t3,r1,r2,r3;
    //struct sched_param *params;
    
    
    
    char *temp="thread";
    printf("-------Program starts here--------\n\n");
    t1=pthread_create(&thread1,NULL,THREAD_A,(void*) temp);
    //r1= pthread_setschedparam(thread1,0,SCHED_OTHER);
    pthread_join(thread1,NULL);
   
    t2=pthread_create(&thread2,NULL,THREAD_B,(void*) temp);
    //r2=pthread_setschedparam(thread2,0,SCHED_FIFO);
    pthread_join(thread2,NULL);
    
    t3=pthread_create(&thread3,NULL,THREAD_C,(void*) temp);
    //r3=pthread_setschedparam(thread3,0,SCHED_RR);
    pthread_join(thread3,NULL);
    

    printf("---------Program ends here-----------\n");
    return 0;
}