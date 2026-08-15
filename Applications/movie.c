#include <stdio.h>
#include <stdlib.h>

void initializeTheater(int **theater, int rows, int *seatsPerRow) {
    for (int i = 0; i < rows; i++) {
        printf("Enter the number of seats in row %d: ", i + 1);
        scanf("%d", &seatsPerRow[i]);

        theater[i] = (int *)malloc(seatsPerRow[i] * sizeof(int));

        for (int j = 0; j < seatsPerRow[i]; j++) {
            theater[i][j] = 0;
        }
    }
}

void displayTheater(int **theater, int rows, int *seatsPerRow) {
    printf("\nSeating Arrangement:\n");
    for (int i = 0; i < rows; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < seatsPerRow[i]; j++) {
            printf("%d ", theater[i][j]);
        }
        printf("\n");
    }
}

void bookSeat(int **theater, int row, int seat, int *seatsPerRow) {
    if (row >= 0 && seat >= 0 && row < seatsPerRow[row]) {
        if (theater[row][seat] == 0) {
            theater[row][seat] = 1;
            printf("Seat successfully booked!\n");
        } else {
            printf("Seat already booked!\n");
        }
    } else {
        printf("Invalid row or seat number!\n");
    }
}

void cancelBooking(int **theater, int row, int seat, int *seatsPerRow) {
    if (row >= 0 && seat >= 0 && row < seatsPerRow[row]) {
        if (theater[row][seat] == 1) {
            theater[row][seat] = 0;
            printf("Booking successfully canceled!\n");
        } else {
            printf("Seat is not booked!\n");
        }
    } else {
        printf("Invalid row or seat number!\n");
    }
}

void freeMemory(int **theater, int rows) {
    for (int i = 0; i < rows; i++) {
        free(theater[i]);
    }
    free(theater);
}

int main()
{
    int rows, i, choice, row, seat;
    
    printf("Enter the number of rows in the theater: ");
    scanf("%d", &rows);

    int **theater = (int **)malloc(rows * sizeof(int *));
    int *seatsPerRow = (int *)malloc(rows * sizeof(int));

    initializeTheater(theater, rows, seatsPerRow);

    do {
        printf("\nMovie Theater Booking System:\n");
        printf("1. Display seating arrangement\n");
        printf("2. Book a seat\n");
        printf("3. Cancel a booking\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTheater(theater, rows, seatsPerRow);
                break;
            case 2:
                printf("Enter row number (1 to %d): ", rows);
                scanf("%d", &row);
                printf("Enter seat number: ");
                scanf("%d", &seat);
                bookSeat(theater, row - 1, seat - 1, seatsPerRow);
                break;
            case 3:
                printf("Enter row number (1 to %d): ", rows);
                scanf("%d", &row);
                printf("Enter seat number: ");
                scanf("%d", &seat);
                cancelBooking(theater, row - 1, seat - 1, seatsPerRow);
                break;
            case 4:
                printf("Bye bye... Thank you for using Harini Bookings!!!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    freeMemory(theater, rows);
    free(seatsPerRow);

    return 0;
}