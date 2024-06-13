#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void matrA(int n, int m, int **a)
{
    srand(time(0));
    *a = (int *)malloc(n * m * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            (*a)[i * m + j] = rand() % 201 - 100;
        }
    }

    printf("Масив A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t", (*a)[i * m + j]);
        }
        printf("\n");
    }
}

void matrB(int n, int m, int *a) {
    int *b = (int *)malloc(n * 2 * sizeof(int));

    int min_indices[n];
    int max_indices[n];

    for (int i = 0; i < n; i++) {
        int min = INT_MAX;
        int max = INT_MIN;
        int min_index = 0;
        int max_index = 0;

        for (int j = 0; j < m; j++) {
            if (a[i * m + j] < min) {
                min = a[i * m + j];
                min_index = j;
            }
            if (a[i * m + j] > max) {
                max = a[i * m + j];
                max_index = j;
            }
        }

        min_indices[i] = min_index;
        max_indices[i] = max_index;
    }

    for (int i = 0; i < n; i++) {
        int min_product = 1;
        int max_product = 1;

        for (int j = 0; j < n; j++) {
            min_product *= a[j * m + min_indices[i]];
            max_product *= a[j * m + max_indices[i]];
        }

        b[i] = min_product;
        b[i + n] = max_product;
    }

    printf("Матриця b:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", b[i], b[i + n]);
    }
    free(b);
}


void menu()
{
    int m, n, x, h;
    int *a = NULL;
    int f = 0;

    printf("Введіть кількість рядків: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Кількість рядків повинно бути більше 0\n");
        return;
    }

    printf("Введіть кількість стовпців: ");
    scanf("%d", &m);
    if (m <= 0)
    {
        printf("Кількість стовпців повинна бути більше 0\n");
        return;
    }



    do
    {
        printf("\n1. Згенерувати матрицю\n");
        printf("2. Вивести матрицю b\n");
        printf("0. Вийти\n");
        printf("Виберіть номер опції (0-2): ");

        scanf("%d", &h);
        if (h == 1)
        {
            matrA(n, m, &a);
            f = 1;
        }
        else if (h == 2)
        {
            if (f == 1)
            {
                matrB(n, m, a);
            }
            else
            {
                printf("Спочатку заповніть матрицю\n");
            }
        }
        else if (h == 0)
        {
            printf("Вихід з програми\n");
        }
        else
        {
            printf("Неправильний вибір опції\n");
        }
    } while (h != 0);

    if (a != NULL)
    {
        free(a);
    }
}

int main(void)
{
    menu();
    return 0;
}
