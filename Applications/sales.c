#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STORES 50
#define MAX_PRODUCTS 100
#define MAX_MONTHS 12

typedef struct {
    char name[50];
    float daily_sales[MAX_MONTHS][30];
    float monthly_sales[MAX_MONTHS];
} Product;

typedef struct {
    char store_name[50];
    Product products[MAX_PRODUCTS];
    int product_count;
} Store;

void inputSalesData(Store *store) {
    printf("Enter store name: ");
    scanf(" %[^\n]", store->store_name);
    
    printf("Enter number of products in store: ");
    scanf("%d", &store->product_count);
    
    for (int i = 0; i < store->product_count; i++) {
        printf("Enter product name: ");
        scanf(" %[^\n]", store->products[i].name);
        
        for (int month = 0; month < MAX_MONTHS; month++) {
            printf("Enter sales for %s for month %d (30 days):\n", store->products[i].name, month + 1);
            store->products[i].monthly_sales[month] = 0; // Reset monthly sales
            for (int day = 0; day < 30; day++) {
                printf("Day %d: ", day + 1);
                scanf("%f", &store->products[i].daily_sales[month][day]);
                store->products[i].monthly_sales[month] += store->products[i].daily_sales[month][day];
            }
        }
    }
}

void generateReports(Store stores[], int store_count) {
    printf("\nSales Reports:\n");

    float overall_product_sales[MAX_PRODUCTS] = {0};
    char best_selling_product[50];
    float best_sales = 0;
    
    for (int i = 0; i < store_count; i++) {
        printf("\nStore: %s\n", stores[i].store_name);
        float highest_sales = 0;
        
        for (int j = 0; j < stores[i].product_count; j++) {
            printf("Product: %s, Monthly Sales: ", stores[i].products[j].name);
            for (int month = 0; month < MAX_MONTHS; month++) {
                printf("%.2f ", stores[i].products[j].monthly_sales[month]);
                overall_product_sales[j] += stores[i].products[j].monthly_sales[month];
                if (overall_product_sales[j] > best_sales) {
                    best_sales = overall_product_sales[j];
                    strcpy(best_selling_product, stores[i].products[j].name);
                }
            }
            printf("\n");
            if (stores[i].products[j].monthly_sales[0] > highest_sales) {
                highest_sales = stores[i].products[j].monthly_sales[0];
            }
        }
        
        printf("Highest Earning Product for %s: %s (Sales: %.2f)\n", stores[i].store_name, stores[i].products[0].name, highest_sales);
    }

    printf("\nBest Selling Product Overall: %s (Total Sales: %.2f)\n", best_selling_product, best_sales);
}

void identifyLowPerformers(Store stores[], int store_count) {
    printf("\nLow-Performing Products or Stores:\n");
    
    for (int i = 0; i < store_count; i++) {
        float store_total_sales = 0;
        for (int j = 0; j < stores[i].product_count; j++) {
            if (stores[i].products[j].monthly_sales[0] < 100) { // Arbitrary threshold for low performance
                printf("Low-performing product in %s: %s (Monthly Sales: %.2f)\n", stores[i].store_name, stores[i].products[j].name, stores[i].products[j].monthly_sales[0]);
            }
            store_total_sales += stores[i].products[j].monthly_sales[0];
        }
        if (store_total_sales < 500) { // Arbitrary threshold for low-performing store
            printf("Store needs improvement: %s (Total Sales: %.2f)\n", stores[i].store_name, store_total_sales);
        }
    }
}
int main() {
    Store stores[MAX_STORES];
    int store_count = 0;
    
    char continue_input;
    do {
        inputSalesData(&stores[store_count]);
        store_count++;
        printf("Do you want to enter another store? (y/n): ");
        scanf(" %c", &continue_input);
    } while (continue_input == 'y' && store_count < MAX_STORES);
    
    generateReports(stores, store_count);
    identifyLowPerformers(stores, store_count);
    
    return 0;
}
