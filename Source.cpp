#include <iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int n, m;
    printf("n = ");
    cin >> n;
    //scanf_s("%d", &n);
    printf("m = ");
    cin >> m;
    //scanf_s("%d", &m);

    int* dim1 = (int*)malloc(n * m * sizeof(int));
    int** dim2 = (int**)malloc(n * sizeof(int*));

    printf("2 dimensional array:\n");
    for (int i = 0; i < n; i++) {
        dim2[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            dim2[i][j] = rand() % 21 - 10;
            printf("%4d", dim2[i][j]);
        }
        printf("\n");
    }

    printf("\n1 dimensional array:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dim1[i * m + j] = dim2[i][j]; // 2dm -> 1dm
            printf("%4d", dim1[i * m + j]);
        }
    }


    printf("\n\nnew 2 dimensional array:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dim2[i][j] = dim1[i * m + j]; // 1dm -> 2dm
            printf("%4d", dim2[i][j]);
        }
        printf("\n");
    }


    free(dim1);
    for (int i = 0; i < n; i++) free(dim2[i]);
    free(dim2);
}