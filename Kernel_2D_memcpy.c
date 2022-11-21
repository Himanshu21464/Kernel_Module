#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>

#define SYS_kernel_2D_memcpy 451

int main() {
   
    float Matrix_A[4][4] = {{0.0,0.0,0.0,0.0},
                            {0.0,0.0,0.0,0.0},
                            {0.0,0.0,0.0,0.0},
                            {0.0,0.0,0.0,0.0}};
    
    float Matrix_B[4][4] = {{1.3,3.5,8.2,2.0},
                            {1.6,4.9,0.6,5.4},
                            {5.0,2.2,7.4,4.1},
                            {7.0,6.1,6.9,8.9}};

    printf("-------Matrix A before syscall----------:\n");

    for (int x = 0; x < 4; x++){
        for (int y = 0; y < 4; y++){
            printf("%lf ", Matrix_A[x][y]);
            }
        printf("\n");
    }

    printf("-------Matrix B before syscall----------:\n");

    for (int x = 0; x < 4; x++){
        for (int y = 0; y < 4; y++){
            printf("%lf ", Matrix_B[x][y]);
            }
        printf("\n");
    }

    int RESULT = syscall(SYS_kernel_2D_memcpy, Matrix_A, Matrix_B, 4, 4);

    if(RESULT < 0){
        printf("ERROR! in performing the SYSTEM CALL.");
        exit(1);
    }

    printf("-------Matrix A after syscall----------:\n");

    for (int x = 0; x < 4; x++){
        for (int y = 0; y < 4; y++){
            printf("%lf ", Matrix_A[x][y]);
            }
        printf("\n");
    }

    printf("-------Matrix B after syscall----------:\n");

    for (int x = 0; x < 4; x++){
        for (int y = 0; y < 4; y++){
            printf("%lf ", Matrix_B[x][y]);
            }
        printf("\n");
    }
    return 0;
}
