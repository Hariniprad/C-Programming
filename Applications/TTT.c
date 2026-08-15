#include<stdio.h>
int main(){
    int  i, j, k, n, m;
    char a[3][3], pl1[10], pl2[10], p;
    
    // getting player names
    printf("Player 1 (X) : "); 
    scanf("%s", &pl1[0]);
    printf("Player 2 (O) : "); 
    scanf("%s", &pl2[0]);

    // initial board
    for(i=0;i<3;i++){
        for(j=0; j<3; j++){
            a[i][j] = '-';
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }

    // play
    for(n=0;n<9;n++)
    {
        // move
        i=0, j=0;
        if(n % 2 == 0)
            p = 'X';
        else
            p = 'O';
        printf("Row & Column of %c = ", p);
        scanf("%d%d", &i, &j);
        a[i-1][j-1] = p;

        for(i=0;i<3;i++){
            for(j=0; j<3; j++){
                printf("%c ", a[i][j]);
            }
        printf("\n");
        }
        
        // check winner
        for(i=0;i<3;i++){
            if(a[i][0]==p && a[i][1]==p && a[i][2]==p){
                printf("%c is the Winner!\n", p);
                return 0;
            }
        }
        
        for(j=0;j<3;j++){
            if(a[0][j]==p && a[1][j]==p && a[2][j]==p){
                printf("%c is the Winner!\n", p);
                return 0;
            }
        }

        if(a[0][0]==p && a[1][1]==p && a[2][2]==p){
            printf("%c is the Winner!\n", p);
            return 0;
        }

        else if(a[0][2]==p && a[1][1]==p && a[2][0]==p){
            printf("%c is the Winner!\n", p);
            return 0;
        }
        else
            continue;
    }
// none of the conditions satisfied after 9 moves
    printf("It's a Tie!\n");
    return 0;
}
    





// void print_matrix(char a[3][3])
// {
//     for(int i=0;i<3;i++){
//         for(int j=0; j<3; j++){
//             printf("%c ", a[i][j]);
//         }
//         printf("\n");
//     }
// }






//     // getting input for matrix
//     for(i = 0; i < 2; i++){
//         for(j = 0; j < 2; j++){
//             printf("a%d%d = ", i+1, j+1);
//             scanf("%d", &*ptr++);
//         }
//     }
    
//     // printing as matrix using pointer
//     for(int i=0;i<2;i++){
//         for(j=0; j<2; j++){
//             printf("%d ",*(c++));
//         }
//         printf("\n");
//     }

        
            // for(j=0; j<3; j++){

            // }
