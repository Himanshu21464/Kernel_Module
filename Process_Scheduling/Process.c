#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sched.h>

pid_t Pid1,Pid2,Pid3,Pid4,Pid5,Pid6,Pid7,Pid8,Pid9,Pid10,Pid11,Pid12;
int status;
struct sched_param param;
double TIME[12];

void PROCESS_1_D(){
  clock_t Start,End;
  Start=clock();
  Pid1=fork();
  if(Pid1==-1){
    printf("Unable to create child process\n");
  }
  else if(Pid1==0){
    sched_setscheduler(Pid1, SCHED_OTHER,&param);
    execlp("make","make",NULL);
  }waitpid(Pid1,&status,0);
  End=clock();
  double Total_Time=(double)(End-Start);
  TIME[0]=Total_Time;
  printf("Time taken by Process-1 with priority[default] : %f\n",Total_Time);
}

void PROCESS_1_P1(){
  clock_t Start,End;
  Start=clock();
  Pid2=fork();
  if(Pid2==-1){
    printf("Unable to create child process\n");
  }
  else if(Pid2==0){
    param.sched_priority=1;
    sched_setscheduler(Pid2, SCHED_OTHER,&param);
    execlp("make","make",NULL);
  }waitpid(Pid2,&status,0);
   End=clock();
   double Total_Time=(double)(End-Start);
   TIME[1]=Total_Time;
  printf("Time taken by Process-1 with priority[1] : %f\n",Total_Time);
}

void PROCESS_1_P2(){
  clock_t Start,End;
  Start=clock();
  Pid3=fork();
  if(Pid3==-1){
    printf("Unable to create child process\n");
  }
  else if(Pid3==0){
    param.sched_priority=2;
    sched_setscheduler(Pid3, SCHED_OTHER,&param);
    execlp("make","make",NULL);
  }waitpid(Pid3,&status,0);
   End=clock();
  double Total_Time=(double)(End-Start);
  TIME[2]=Total_Time;
  printf("Time taken by Process-1 with priority[2] : %f\n",Total_Time);
}

void PROCESS_1_P3(){
  clock_t Start,End;
  Start=clock();
  Pid4=fork();
  if(Pid4==-1){
    printf("Unable to create child process\n");
  }
  else if(Pid4==0){
    param.sched_priority=3;
    sched_setscheduler(Pid4, SCHED_OTHER,&param);
    execlp("make","make",NULL);
  }waitpid(Pid4,&status,0);
   End=clock();
  double Total_Time=(double)(End-Start);
  TIME[3]=Total_Time;
  printf("Time taken by Process-1 with priority[3] : %f\n",Total_Time);
}

void PROCESS_2_D(){
  clock_t Start,End;
  Start=clock();
  Pid5=fork();
  if(Pid5==-1){
    printf("Unable to create child process\n");
  }
  else if(Pid5==0){
    sched_setscheduler(Pid5, SCHED_RR,&param);
    execlp("make","make",NULL);
  }waitpid(Pid5,&status,0);
  End=clock();
  double Total_Time=(double)(End-Start);
  TIME[4]=Total_Time;
  printf("Time taken by Process-2 with priority[default] : %f\n",Total_Time);
}

void PROCESS_2_P1(){
  clock_t Start,End;
  Start=clock();
  Pid6=fork();
  if(Pid6==-1){
    printf("Unable to create child process\n");
  }
  else if(Pid6==0){
    param.sched_priority=1;
    sched_setscheduler(Pid6, SCHED_RR,&param);
    execlp("make","make",NULL);
  }waitpid(Pid6,&status,0);
   End=clock();
  double Total_Time=(double)(End-Start);
  TIME[5]=Total_Time;
  printf("Time taken by Process-2 with priority[1] : %f\n",Total_Time);
}

void PROCESS_2_P2(){
  clock_t Start,End;
  Start=clock();
  Pid7=fork();
  if(Pid7==-1){
    printf("Unable to create child process\n");
  }
  else if(Pid7==0){
    param.sched_priority=2;
    sched_setscheduler(Pid7, SCHED_RR,&param);
    execlp("make","make",NULL);
  }waitpid(Pid7,&status,0);
   End=clock();
  double Total_Time=(double)(End-Start);
  TIME[6]=Total_Time;
  printf("Time taken by Process-2 with priority[2] : %f\n",Total_Time);
}

void PROCESS_2_P3(){
  clock_t Start,End;
  Start=clock();
  Pid8=fork();
  if(Pid8==-1){
    printf("Unable to create child process\n");
  }
  else if(Pid8==0){
    param.sched_priority=3;
    sched_setscheduler(Pid8, SCHED_RR,&param);
    execlp("make","make",NULL);
  }waitpid(Pid8,&status,0);
   End=clock();
  double Total_Time=(double)(End-Start);
  TIME[7]=Total_Time;
  printf("Time taken by Process-2 with priority[3] : %f\n",Total_Time);
}

void PROCESS_3_D(){
  clock_t Start,End;
  Start=clock();
  Pid9=fork();
  if(Pid9==-1){
    printf("Unable to create child process\n");
  }
  else if(Pid9==0){
    sched_setscheduler(Pid9, SCHED_FIFO,&param);
    execlp("make","make",NULL);
  }waitpid(Pid9,&status,0);
   End=clock();
  double Total_Time=(double)(End-Start);
  TIME[8]=Total_Time;
  printf("Time taken by Process-1 with priority[default] : %f\n",Total_Time);
}

void PROCESS_3_P1(){
  clock_t Start,End;
  Start=clock();
  Pid10=fork();
  if(Pid10==-1){
    printf("Unable to create child process\n");
  }
  else if(Pid10==0){
    param.sched_priority=1;
    sched_setscheduler(Pid10, SCHED_FIFO,&param);
    execlp("make","make",NULL);
  }waitpid(Pid10,&status,0);
  End=clock();
  double Total_Time=(double)(End-Start);
  TIME[9]=Total_Time;
  printf("Time taken by Process-1 with priority[1] : %f\n",Total_Time);
}

void PROCESS_3_P2(){
  clock_t Start,End;
  Start=clock();
  Pid11=fork();
  if(Pid11==-1){
    printf("Unable to create child process\n");
  }
  else if(Pid11==0){
    param.sched_priority=2;
    sched_setscheduler(Pid11, SCHED_FIFO,&param);
    execlp("make","make",NULL);
  }waitpid(Pid11,&status,0);
  End=clock();
  double Total_Time=(double)(End-Start);
  TIME[10]=Total_Time;
  printf("Time taken by Process-3 with priority[2] : %f\n",Total_Time);
}

void PROCESS_3_P3(){
  clock_t Start,End;
  Start=clock();
  Pid12=fork();
  if(Pid12==-1){
    printf("Unable to create child process\n");
  }
  else if(Pid12==0){
    param.sched_priority=3;
    sched_setscheduler(Pid12, SCHED_FIFO,&param);
    execlp("make","make",NULL);
  }waitpid(Pid12,&status,0);
  End=clock();
  double Total_Time=(double)(End-Start);
  TIME[11]=Total_Time;
  printf("Time taken by Process-3 with priority[3] : %f\n",Total_Time);
  
}

int main(){


    printf("-----HISTOGRAM FOR PROCESSES WITH DEFAULT PRIORITY------\n");
    for(int i=0;i<TIME[0];i++){
        printf("#");
    }
    printf("%f\n",TIME[0]);
    for(int i=0;i<TIME[4];i++){
        printf("#");
    }
    printf("%f\n",TIME[4]);
    for(int i=0;i<TIME[8];i++){
        printf("#");
    }
    printf("%f\n",TIME[8]);


    printf("---------HISTOGRAM FOR PROCESSES WITH PRIORITY[1]-------\n");
    for(int i=0;i<TIME[1];i++){
        printf("#");
    }
    printf("%f\n",TIME[1]);
    for(int i=0;i<TIME[5];i++){
        printf("#");
    }
    printf("%f\n",TIME[5]);
    for(int i=0;i<TIME[9];i++){
        printf("#");
    }
    printf("%f\n",TIME[9]);


    printf("---------HISTOGRAM FOR PROCESSES WITH PRIORITY[2]-------\n");
    for(int i=0;i<TIME[2];i++){
        printf("#");
    }
    printf("%f\n",TIME[2]);
    for(int i=0;i<TIME[6];i++){
        printf("#");
    }
    printf("%f\n",TIME[6]);
    for(int i=0;i<TIME[10];i++){
        printf("#");
    }
    printf("%f\n",TIME[10]);

    printf("---------HISTOGRAM FOR PROCESSES WITH PRIORITY[3]-------\n");
    for(int i=0;i<TIME[3];i++){
        printf("#");
    }
    printf("%f\n",TIME[3]);
    for(int i=0;i<TIME[7];i++){
        printf("#");
    }
    printf("%f\n",TIME[7]);
    for(int i=0;i<TIME[11];i++){
        printf("#");
    }
    printf("%f\n",TIME[11]);
    return 0;
}