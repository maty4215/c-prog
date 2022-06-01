#include <stdio.h>
#include <ctype.h>

int main() {

    char jednotka;
    float teplota;

    printf("\nJakou jednotku chcete převést ? (C) nebo (F)?: ");
    scanf("%c", &jednotka);
    
    jednotka = toupper(jednotka);

    if(jednotka == 'C'){
        printf("\nZadejte teplotu ve stupních Celsia: ");
        scanf("%f", &teplota);
        teplota = (teplota * 9 / 5) + 32;
        printf("Teplota ve stupních Fahrenheit je: %.1f", teplota);
    }
    else if(jednotka == 'F'){
        printf("\nZadej teplotu ve stupních Fahrenheit: ");
        scanf("%f", &teplota);
        teplota = ((teplota - 32) * 5) / 9;
        printf("\nTeplota je ve stupních Celsia je: %.1f", teplota);
    }
    return 0;
}