#include <stdio.h>
#include <stdlib.h>

int qvd(int a) {
    return a * a;
}

void mas(int a, int* b) {
    for (int i = 0; i < a; i++) {
        b[i] = qvd(b[i]);
    }
    printf("Масив b\n");
    for (int i = 0; i < a; i++) {
        printf("%d\t", b[i]);
    }
    printf("\n");
}

void menu() {
    int h, a = 0;
    int* b = NULL;

    do {
        printf("\n1. Введіть число a\n");
        printf("2. Ввести елементи масиву\n");
        printf("3. Обчислити масив\n");
        printf("0. Вийти\n");
        printf("Виберіть номер опції (0-3): ");
        scanf("%d", &h);

        if (h == 1) {
            printf("Введіть число a: ");
            scanf("%d", &a);
            
            if (b != NULL) {
                free(b);
            }
            b = (int*)malloc(a * sizeof(int));
            if (b == NULL) {
                printf("Помилка виділення пам'яті\n");
                exit(1);
            }
        } else if (h == 2) {
            if (a <= 0) {
                printf("Спочатку введіть число a\n");
            } else {
                printf("Введіть елементи масиву:\n");
                for (int i = 0; i < a; i++) {
                    scanf("%d", &b[i]);
                }
            }
        } else if (h == 3) {
            if (a <= 0 || b == NULL) {
                printf("Спочатку введіть число a та елементи масиву\n");
            } else {
                mas(a, b);
            }
        } else if (h == 0) {
            printf("Вихід з програми\n");
        } else {
            printf("Неправильний вибір опції\n");
        }
    } while (h != 0);

    if (b != NULL) {
        free(b);
    }
}

int main(void) {
    menu();
    return 0;
}
