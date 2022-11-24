#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <math.h>
#include <pthread.h>
#include <time.h>
#include <sys/resource.h>

void *countA(){
  for(long long int i = 0; i<4294967296; i++){   
  }
}
void *countB(){
  for(long long int i = 0; i<4294967296; i++){
  }
}
void *countC(){
  for(long long int i = 0; i<4294967296; i++){
  }
}


int main(){
	pthread_t THREAD_1, THREAD_2, THREAD_3;
  clock_t S1,S2,S3,S4,S5,S6,S7,S8,S9,E1,E2,E3,E4,E5,E6,E7,E8,E9;
  double F1,F2,F3,F4,F5,F6,F7,F8,F9;
  struct sched_param param;
  
  FILE * filename;
  filename = fopen("Thread_Scheduling_Data.txt","w");
  S1=clock();
  pthread_create(&THREAD_1, NULL, countA, NULL);
  pthread_create(&THREAD_1, NULL, countB, NULL);
  pthread_create(&THREAD_1, NULL, countC, NULL);
  pthread_setschedparam(THREAD_1, SCHED_OTHER, &param);
  pthread_join(THREAD_1, NULL);
  
  E1=clock();
  F1=(double)(E1-S1);
  printf("Time to run THREAD_1: %f\n",F1/3000000);
  fprintf(filename," %f\n",F1/3000000);
  for(int prio_num = 1; prio_num<=4; prio_num++){
    printf("For priority: %d",prio_num);
  
    S2=clock();
    pthread_setschedprio(THREAD_1,prio_num);
    pthread_join(THREAD_1, NULL);
    E2=clock();
    F2=(double)(E2-S2);
    printf("Time to run THREAD_2: %f\n",F2/1000000);
    fprintf(filename," %f\n",F2/1000000);
  }
  S3=clock();
  pthread_create(&THREAD_2, NULL, countA, NULL);
  pthread_create(&THREAD_2, NULL, countB, NULL);
  pthread_create(&THREAD_2, NULL, countC, NULL);
  pthread_setschedparam(THREAD_2, SCHED_RR, &param);
  pthread_join(THREAD_2, NULL);
  E3=clock();
  F3=(double) (E3-S3);
  printf("Time to run THREAD_2: %f\n",F3/3000000);
  fprintf(filename,"%f\n",F3/3000000);

  for(int prio_num = 1; prio_num<=4; prio_num++){
    printf("For priority: %d",prio_num);
    S4=clock();
    pthread_setschedprio(THREAD_2,prio_num);
    pthread_join(THREAD_2, NULL);
    E4=clock();
    F4=(double)(E4-S4);
    printf("Time to run THREAD_2: %f\n",F4/1000000);
    fprintf(filename,"%f\n",F4/1000000);  
  }
  S5=clock();
  pthread_create(&THREAD_3, NULL, countA, NULL);
  pthread_create(&THREAD_3, NULL, countB, NULL);
  pthread_create(&THREAD_3, NULL, countC, NULL);
  pthread_setschedparam(THREAD_3, SCHED_FIFO, &param);
  pthread_join(THREAD_3, NULL);
  E5=clock();
  F5=(double)(E5-S5);
  printf("Time to run THREAD_3: %f\n",F5/3000000);
  fprintf(filename," %f\n",F5/3000000);

  for(int prio_num = 1; prio_num<=4; prio_num++){
    printf("For priority: %d",prio_num);
    S6=clock();
    pthread_setschedprio(THREAD_3,prio_num);
    pthread_join(THREAD_3, NULL);
    E6=clock();
    F6=(double)(E6-S6);
    printf("Time to run THREAD_3: %f\n",F6/1000000);
    fprintf(filename,"%f\n",F6/1000000); 
  }
  fclose(filename);
	exit(0);
}