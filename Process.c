#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


pid_t pid1, pid2, pid3;
int status;

void PROCESS_A(){
    clock_t start,end;
    double cpu_time_used;
    start=clock();
    pid1 = fork();
    if(pid1==-1){
        printf("Unable to create child process!!!\n");
    }else if(pid1==0){
        execl("make","all",NULL);
    }waitpid(pid1,&status,0);
    end=clock();
    cpu_time_used=(double)(end-start);
    printf("Time taken by (process A) to compile the LINUX kernel source: %f\n\n\n",cpu_time_used);

} 

void PROCESS_B(){
    clock_t start,end;
    double cpu_time_used;
    start=clock();
    pid2 = fork();
    if(pid2==-1){
        printf("Unable to create child process!!!\n");
    }else if(pid2==0){
        execlp("make","make",NULL);
    }waitpid(pid2,&status,0);
    end=clock();
    cpu_time_used=(double)(end-start);
    printf("Time taken by (process B)to compile the LINUX kernel source: %f\n\n\n",cpu_time_used);
} 

void PROCESS_C(){
    clock_t start,end;
    double cpu_time_used;
    start=clock();
    pid2 = fork();
    if(pid3==-1){
        printf("Unable to create child process!!!\n");
    }else if(pid3==0){
        execlp("make","make",NULL);
    
    }waitpid(pid3,&status,0);
    end=clock();
    cpu_time_used=(double)(end-start);
    printf("Time taken by (process C) to compile the LINUX kernel source: %f\n\n\n",cpu_time_used);
    
} 


int main(){

    printf("--------Program starts here------------\n");   
    PROCESS_A(); 
    PROCESS_B();        
    PROCESS_C();
    printf("------ --Program ends here-------------\n");
    

}
