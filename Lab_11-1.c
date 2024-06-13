#include <stdlib.h>
#include <stdio.h>

void matr(int n, int a[n])
{
    printf("Введіть елементи матриці\n");
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Матриця a\n");
    for (int i = 1; i < n + 1; i++)
    {
        printf("%d\t", a[i]);
    }
}

void sum(int n, int x, int a[n])
{
    int suma = 0;
    for (int i = 1; i < x + 1; i++)
    {
        suma += a[i] * a[i];
    }
    printf("Сума елементів перших %d елементів = %d", x , suma);
}

void menu()
{
    int h, n, x;
    int *a = NULL;
    do
    {
        printf("\n1. Ввести елементи матриці\n");
        printf("2. Обчислення\n");
        printf("0. Вийти\n");
        printf("Виберіть номер опції (0-2): ");

        scanf("%d", &h);
        if (h == 1)
        {
            do
            {
                printf("Введіть кіллькість рядків\n");
                scanf("%d", &n);
                if (n <= 0)
                {
                    printf("Рядки не можуть бути менше 0\n");
                }

            } while (n <= 0);

            do
            {
                printf("Введіть x\n");
                scanf("%d", &x);
                if (x > n)
                {
                    printf("x повинен бути менше кількості рядків\n");
                }

            } while (x > n);

            a = (int *)malloc(n * sizeof(int));
            matr(n, a);
        }
        else if (h == 2)
        {
            if (a == NULL)
            {
                printf("Спочатку задайте елементи матриці");
                return;
            } else {
                sum(n, x, a);
            }
            
        }
        else if (h == 0)
        {
            printf("Вихід з програми\n");
        }
        else
        {
            printf("Неправильний вибір\n");
        }
    } while (h != 0);
    if (a != NULL) {
        free(a);
    }
}

int main(void)
{
    menu();
}