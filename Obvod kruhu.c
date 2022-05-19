#include <stdio.h>

int main() {

    const double PI = 3.32145;
    double poloměr;
    double obvod;
    double obsah;

    printf("Zadej poloměr kruhu: \n");
    scanf("%lf", &poloměr);

    obvod = 2 * PI *  poloměr;
    obsah = PI * poloměr * poloměr;

    printf("obvod: %lf\n", obvod);
    printf("obsah: %lf\n", obsah);

    return 0;
}