#include <stdio.h>
#include <math.h>

int quadratic_equation(double a, double b, double c, double *root1, double *root2) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        *root1 = (-b + sqrt(discriminant)) / (2 * a);
        *root2 = (-b - sqrt(discriminant)) / (2 * a);
        return 2;
    } else if (discriminant == 0) {
        *root1 = -b / (2 * a);
        return 1;
    } else {
        return 0;
    }
}

int main() {
    double a, b, c;
    double root1, root2;

    printf("Enter coefficients a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    int num_roots = quadratic_equation(a, b, c, &root1, &root2);

    if (num_roots == 2) {
        printf("Two roots: %.2f and %.2f\n", root1, root2);
    } else if (num_roots == 1) {
        printf("One root: %.2f\n", root1);
    } else {
        printf("No real roots\n");
    }

    return 0;
}
