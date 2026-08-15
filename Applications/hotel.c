#include<stdio.h>
#include<string.h>

typedef struct Dish{
    char name[20];
    float price;
}Dish;

typedef struct Order{
    char name[20];
    int qty;
}Order;

int i = 0;
void displayMenu(Dish dish[i], int d){
    printf("\n\tMENU\n");
    for(i=0; i<d; i++){
        printf("%-10s - Rupees%.2f\n", dish[i].name, dish[i].price);
    }
    printf("\n");
}

int n = 0;
void orderFood(Order order[n]){
    printf("Dish: ");
    fgets(order[n].name, sizeof(order[i].name), stdin);
    order[n].name[strcspn(order[n].name, "\n")] = 0;

    // if(){
        
    // }

    printf("Quantity: ");
    scanf("%d", &order[n].qty);
    getchar();

    n++;
}

void bill(Dish dish[i], Order order[n], int d){
    printf("\nBILL:\n");
    for(int k=0; k<=n; k++){
        for(i=0; i<d; i++){
            if(strcmp(order[k].name, dish[i].name) == 0){
                printf("%-10s\t%-5d\tRupees%.2f\n", order[k].name, order[k].qty, order[k].qty * dish[i].price);
            }
        }
    }
    printf("\n");

}

void delete(Dish dish[i], int d){
    char temp[10];
    int k;
    printf("Enter dish to delete from menu: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp,"\n")] = 0;
    for(i=0; i<d; i++){
        if(strcmp(dish[i].name, temp) == 0){
            for(k = i; k<d-1; k++){
                strcpy(dish[k+1].name, dish[k].name);
                dish[k+1].price = dish[k].price;
            }
            if(k = d-1){
                    continue;
            }
            d--;
            printf("Dish deleted successfully.\n");
            return;
        }
    }
    printf("Dish not found.\n");
}

int main()
{
    Order order[10];

    Dish dish[10] = {{"Dosa", 20}, {"Idly", 15}, {"Poori", 25}};
    int d = 3;

    displayMenu(dish, d);
    orderFood(order);
    bill(dish,order,d);
    delete(dish, d);
    displayMenu(dish, d);

    return 0;
}