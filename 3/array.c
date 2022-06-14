#include <stdio.h>

int main(void) {
    int i;
    int numbers[10] = {0};

    i = 0;
    while (i < 10) {
        scanf("%d", &numbers[i]);
        // &numbers[i] = &numbers + i * sizeof(numbers[i])
        // &numbers[i] = &numbers + i * 4
        i++;
    }

    i = 0;
    while (i < 10) {
        printf("%d\n", numbers[i]);
        i++;
    }
}
