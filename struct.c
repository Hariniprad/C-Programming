#include <stdio.h>
#include <string.h>
// #include <ctype.h>

// int main(){
//     char b[50] = {"Hello World"};
//     char a[50] = {"Hello World"};

//     printf("%d\n",strcmp(b,a));
//     return 0;
// }

// int main(){
//     char *str;
//     fgets(str, 500, stdin);
//     for (int i = 0; str[i]; i++) {
//         str[i] = tolower(str[i]);
//     }
//     printf("%s",str);
// }

typedef struct Book{
    int no;
    char author[50];
    float price;
}Book;

int main()
{
    int n;
    Book hp[50];

    printf("Number of books : ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("No. %d : ", i+1);
        scanf("%d", &hp[i].no);
        printf("Price %d : ", i+1);
        scanf("%f", &hp[i].price);
        printf("Author %d : ", i+1);
        getchar();
        fgets(hp[i].author, sizeof(hp[i].author), stdin);
    }

    for(int i=0; i<n; i++){
        printf("%d\n", hp[i].no);
        printf("%f\n", hp[i].price);
        printf("%s\n", hp[i].author);
    }

    hp[0] = hp[1];
    printf("%d\n", hp[0].no);
    printf("%f\n", hp[0].price);
    printf("%s\n", hp[0].author);



    // struct Book hp = {1, "JK Rowling", 100.25};
    // hp.no = 10;
    // Book hp[0] = {{1, "JK Rowling", 100.25}};
    // // struct Book hp[50];
    // // hp[0].no = 1;
    // // hp[0].price = 100.50;
    // // strcpy(hp[0].author, "JK Rowling");

    // // hp[1].no = 2;
    // // hp[1].price = 105.50;
    // // strcpy(hp[1].author, "JK Rowling");

    // // for(int i=0; i<2; i++){
    // //     printf("%d\n", hp[i].no);
    // //     printf("%f\n", hp[i].price);
    // //     printf("%s\n", hp[i].author);
    // // }

    // printf("%d\n%f\n%s\n", hp.no, hp.price, hp.author);
    // // printf("%f\n", hp.price);
    // // printf("%s\n", hp.author);

    // // struct Book hp = {2, "JK Rowling", 105.25};

    return 0;


}
