#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


pid_t pid1, pid2, pid3;
int status1,status2,status3;

void PROCESS_A(){
    FILE * filename;
    filename = fopen("Process_Scheduling_Data.txt","a");


    clock_t start,end;
    double cpu_time_used;
    start=clock();
    pid1 = fork();
    if(pid1==-1){
        printf("Unable to create child process!!!\n");
    }else if(pid1==0){
        execl("make","all",NULL);
    }waitpid(pid1,&status1,0);
    end=clock();
    cpu_time_used=(double)(end-start);
    printf("\n\n--------------------------------------------------------------------------------\n");
    printf("Time taken by [process A] to compile the LINUX kernel source: %f\n",cpu_time_used);
    printf("----------------------------------------------------------------------------------\n\n");
    fprintf(filename,"%f\n",cpu_time_used);
    fclose(filename);
} 

void PROCESS_B(){
    FILE * filename;
    filename = fopen("Process_Scheduling_Data.txt","a");
   

    clock_t start,end;
    double cpu_time_used;
    start=clock();
    pid2 = fork();
    if(pid2==-1){
        printf("Unable to create child process!!!\n");
    }else if(pid2==0){
        execlp("make","make",NULL);
    }waitpid(pid2,&status2,0);
    end=clock();
    cpu_time_used=(double)(end-start);
    printf("\n\n--------------------------------------------------------------------------------\n");
    printf("Time taken by [process B] to compile the LINUX kernel source: %f\n",cpu_time_used);
    printf("----------------------------------------------------------------------------------\n\n");
    fprintf(filename,"%f\n",cpu_time_used);
    fclose(filename);
} 

void PROCESS_C(){
    FILE * filename;
    filename = fopen("Process_Scheduling_Data.txt","a");
    

    clock_t start,end;
    double cpu_time_used;
    start=clock();
    pid3 = fork();
    if(pid3==-1){
        printf("Unable to create child process!!!\n");
    }else if(pid3==0){
        execlp("make","make",NULL);
    
    }waitpid(pid3,&status3,0);
    end=clock();
    cpu_time_used=(double)(end-start);
    printf("\n\n--------------------------------------------------------------------------------\n");
    printf("Time taken by [process C] to compile the LINUX kernel source: %f\n",cpu_time_used);
    printf("----------------------------------------------------------------------------------\n\n");
    fprintf(filename,"%f\n",cpu_time_used);
    fclose(filename);
} 


int main(){
    FILE * filename;
    filename = fopen("Process_Scheduling_Data.txt","w");
    fclose(filename);

    printf("--------Program starts here------------\n");   
    PROCESS_A(); 
    PROCESS_B();        
    PROCESS_C();
    printf("------ --Program ends here-------------\n");
    

}