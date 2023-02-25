#include <stdio.h>
#include <ctype.h>

void loading(int *a, int *b)
{
    printf("Enter two integers: ");
    scanf("%d %d", a, b);
}

int count(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if (b == 0)
    {
        printf("Error: Division by zero\n");
        return 0;
    }
    else
    {
        return a / b;
    }
}

void list(int (*func)(int, int), int *a, int *b)
{
    int result = func(*a, *b);
    printf("The result is: %d\n", result);
}

void find(char c, int *n_small, int *n_capital, int *n_number, int *n_char)
{
    if (islower(c))
    {
        (*n_small)++;
    }
    else if (isupper(c))
    {
        (*n_capital)++;
    }
    else if (isdigit(c))
    {
        (*n_number)++;
    }
    else if (isspace(c) || c == '\n' || c == '-')
    {
        (*n_char)++;
    }
}

int main()
{
    char choice;
    int a, b;
    int n_small = 0, n_capital = 0, n_number = 0, n_char = 0;
    FILE *fp;

    while (1)
    {
        printf("MENU\n");
        printf("c - loading numbers\n");
        printf("s - counting numbers\n");
        printf("o - subtracting numbers\n");
        printf("n - multiplying numbers\n");
        printf("d - dividing numbers\n");
        printf("p - working with the file\n");
        printf("e - exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'c':
            loading(&a, &b);
            break;
        case 's':
            list(count, &a, &b);
            break;
        case 'o':
            list(subtract, &a, &b);
            break;
        case 'n':
            list(multiply, &a, &b);
            break;
        case 'd':
            list(divide, &a, &b);
            break;
        case 'p':
            fp = fopen("vstup.txt", "r");
            if (fp == NULL)
            {
                printf("Error: Cannot open file\n");
                break;
            }
            char c;
            while ((c = fgetc(fp)) != EOF)
            {
                find(c, &n_small, &n_capital, &n_number, &n_char);
            }
            fclose(fp);
            printf("Small letters: %d\n", n_small);
            printf("Capital letters: %d\n", n_capital);
            printf("Numbers: %d\n", n_number);
            printf("Characters: %d\n", n_char);
            break;
        case 'e':
            printf("Exiting program\n");
            return 0;
        default:
            printf("Operation is not supported\n");
        }
    }

    return 0;
}
