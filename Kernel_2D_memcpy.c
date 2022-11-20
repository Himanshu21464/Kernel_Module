#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>

#define kernel_2d_memcpy 449

int main() {
    float matrix[4][3] = {{4.3,2.5,6.2},
                       {3.3,2.8,1.1},
                       {4.7,6.5,3.0},
                       {4.9,8.1,7.4}};
    //float MAT2[4][3] = {{1.0,1.0,1.0},{1.0,1.0,1.0},{1.0,1.0,1.0},{1.0,1.0,1.0}};

    printf("The input Matrix is:\n");

    for (int x = 0; x < 4; x++){
        for (int y = 0; y < 3; y++){
            printf("%lf ", matrix[x][y]);
            }
        printf("\n");
    }
    printf("\n");

    // printf("This is the initial matrix2 is:\n");

    // for (int x = 0; x < 4; x++){
    //     for (int y = 0; y < 3; y++){
    //         printf("%lf ", MAT2[x][y]);
    //         }
    //     printf("\n");
    // }
    // printf("\n");

    int Result = syscall(kernel_2d_memcpy, matrix,4, 3);

    if(Result < 0){
        printf("ERROR! Could not perform system call.");
        exit(1);
    }

    printf("The Matrix after syscall 'kernel_2d_memcpy':\n");

    for (int x = 0; x < 4; x++){
        for (int y = 0; y < 3; y++){
            printf("%lf ", matrix[x][y]);
            }
        printf("\n");
    }
    printf("\n");

    // printf("This is the final matrix2 is:\n");

    // for (int x = 0; x < 4; x++){
    //     for (int y = 0; y < 3; y++){
    //         printf("%lf ", MAT2[x][y]);
    //         }
    //     printf("\n");
    // }
    // printf("\n");

    return 0;
}