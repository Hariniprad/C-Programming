#include <stdio.h>
#include <stdlib.h>

void alloMem(int ***image, int m, int n) {
    *image = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        (*image)[i] = (int *)malloc(n * 3 * sizeof(int));
    }
}

void freeMem(int **image, int m) {
    for (int i = 0; i < m; i++) {
        free(image[i]);
    }
    free(image);
}

void applyGS(int **image, int m, int n) {
    printf("Grayscale matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int r = image[i][j * 3];
            int g = image[i][j * 3 + 1];
            int b = image[i][j * 3 + 2];
            int gray = (int)(0.3 * r + 0.59 * g + 0.11 * b);
            printf("%d ", gray);
        }
        printf("\n");
    }
}

int main() {
    int m, n;
    printf("Enter the dimensions of the image (rows and columns): ");
    scanf("%d %d", &m, &n);

    int **image;
    alloMem(&image, m, n);

    printf("Enter the RGB values for each pixel:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Pixel[%d][%d] (R G B): ", i, j);
            scanf("%d %d %d", &image[i][j * 3], &image[i][j * 3 + 1], &image[i][j * 3 + 2]);
        }
    }

    applyGS(image, m, n);
    freeMem(image, m);

    return 0;
}
