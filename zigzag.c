    #include<stdio.h>

    int main(){
    int arr[10][10] = {0};
    int n = 20;
    int count = 0;
    int i = 0, j = 0;
    arr[i][j] = count;
    i++;
    count++;

    while(count < n){
        if(i != 0 && j == 0){
            while(i >= 0){
                arr[i][j] = count;
                count++;
                i--;
                j++;
            }
            i = 0;
        }
        else if(i == 0 && j != 0){
            while(j >= 0){
                arr[i][j] = count;
                count++;
                i++;
                j--;
            }
            j = 0;
        }
    }

    for(int x = 0; x < 6; x++){
        for(int y = 0; y < 6; y++){
            if(arr[x][y] != 0 || (x == 0 && y == 0)){
                if(arr[x][y] < 10){
                printf(" 0%d", arr[x][y]);
                }
                else{
                printf(" %d", arr[x][y]);
                }
            }
        }
        printf("\n");
    }

    return 0;
    }