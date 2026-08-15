// #include<stdio.h>
// int main(int argc, char* argv[])
// {
//     int a[2][2], b[2][2], i, j;
//     int *ptr=&a[0][0];
    
//     // getting input for matrix
//     for(i = 0; i < 2; i++){
//         for(j = 0; j < 2; j++){
//             printf("a%d%d = ", i+1, j+1);
//             scanf("%d", &a[i][j]);
//         }
//     }
    
//     // printing as matrix using pointer
//     for(int i=0;i<2;i++){
//         for(j=0; j<2; j++){
//             printf("%d ",*(ptr++));
//         }
//         printf("\n");
//     }

//     //printing command-line arguments
//     printf("No. of Arguments in the given program = %d\n", argc);

//     for(i = 0; i < argc; i++){
//         printf("%s\n", argv[i]);
//     }

//     return 0;
// }

#include<stdio.h>
int main(int argc, char* argv[])
{
    int a[2][2], arv[argc], i, j, n = 1;
    int *ptr=&a[0][0];
    argv[argc] = arv[argc];
    
    // getting input for matrix
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            a[i][j] = arv[n];
            n++;
        }
    }
    
    // printing as matrix using pointer
    for(int i=0;i<2;i++){
        for(j=0; j<2; j++){
            printf("%d ",*(ptr++));
        }
        printf("\n");
    }

    //printing command-line arguments
    printf("No. of Arguments in the given program = %d\n", argc);

    for(i = 0; i < argc; i++){
        printf("%d\n", argv[i]);
    }

    return 0;
}