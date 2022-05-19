#include <stdio.h>

int main() {

    char jmeno[1];
    int věk;

    printf("Jak se jmenuješ?");
    scanf("%s", &jmeno);

    printf("    Kolik ti je?\n");
    scanf("%d", &věk);

    printf("Ahoj, jmenuju se %s\n", jmeno);
    printf("Je mi %d let", věk);


    return 0;
}