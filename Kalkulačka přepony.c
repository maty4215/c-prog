#include <stdio.h>
#include <math.h>

int main() {

    double A;
    double B;
    double C;

    printf("Zadej stranu A: \n");
    scanf("%lf", &A);

    printf("Zadej stranu B: \n");
    scanf("%lf", &B);

    C = sqrt(A*A + B*B);

    printf("Strana C: %lf\n", C);

    return 0;
}