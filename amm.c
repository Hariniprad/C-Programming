#include<stdio.h>
int main()
{
    int a[2][2], b[2][2], c[2][2], i, j,k;
    
    // getting input for matrix
    
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            printf("a%d%d = ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            printf("b%d%d = ", i+1, j+1);
            scanf("%d", &b[i][j]);
        }
    }

    // multiplying matrices

    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            c[i][j] = 0;
            for(k = 0; k < 2; k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }


    // printing resultant matrix
    
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            printf("%d ", c[i][j]);}
        printf("\n");
    }
    
    return 0;
}