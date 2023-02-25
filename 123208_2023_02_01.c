#include <stdio.h>

int *maximum(int *a, int *b) {
    if (*a > *b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int num1, num2;
    int *result;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    result = maximum(&num1, &num2);

    printf("The maximum number is: %d\n", *result);

    return 0;
}
