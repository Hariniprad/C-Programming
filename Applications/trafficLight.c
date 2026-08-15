#include <stdio.h>
#include <unistd.h>

void cycle(int n, int i){
    if(i>n)
        return;
    
    printf("\nCycle %d:\n", i);

    printf("GreeN light: 2sec\n");
    sleep(2);

    printf("yellow light: 1sec\n");
    sleep(1);

    printf("RED light: 2sec\n");
    sleep(2);

    i++;

    cycle(n,i);
}

int main()
{
    int n, i;
    printf("Enter number of cycles: ");
    scanf("%d", &n);
    while(1){
        if (n <= 0) {
            printf("Please enter positive number of cycles.\n");
            printf("Enter number of cycles: ");
            scanf("%d", &n);
        }
        else
            break;
    }
    

    cycle(n,1);

    printf("\nTraffic light simulation complete.\n");
}