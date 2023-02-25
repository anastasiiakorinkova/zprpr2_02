#include <stdio.h>

void pointer_exchange(int **a_ptr, int **b_ptr) {
    int *temp = *a_ptr;
    *a_ptr = *b_ptr;
    *b_ptr = temp;
}

int main() {
    int num1 = 10;
    int num2 = 20;
    int *ptr1 = &num1;
    int *ptr2 = &num2;

    printf("Before pointer exchange:\n");
    printf("ptr1 points to %d\n", *ptr1);
    printf("ptr2 points to %d\n", *ptr2);

    pointer_exchange(&ptr1, &ptr2);

    printf("After pointer exchange:\n");
    printf("ptr1 points to %d\n", *ptr1);
    printf("ptr2 points to %d\n", *ptr2);

    return 0;
}
