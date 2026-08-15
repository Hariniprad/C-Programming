#include<stdio.h>
int main(){
    int n, i, j, triangle[10][10];
    printf("Enter required no. of rows: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        for(j=0; j<=i; j++){
            if(j == 0 || j == i)
                triangle[i][j] = 1;  
            else {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];  
            }
        }
    }
    for(i=0; i<n; i++){
        for(int k=0; k<n-i; k++){
            printf(" ");
        }
        for (int j = 0; j <= i; j++){            
            printf("%d ", triangle[i][j]);
        }
    printf("\n");
    }
    return 0;
}