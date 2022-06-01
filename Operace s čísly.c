#include <stdio.h>

int main(){
    
    char operace;
    double číslo1;
    double číslo2;
    double výsledek;
    
    printf("\nZadej operaci (+ - * /) ");
    scanf("%c", &operace);
    
    printf("Zadej první číslo: ");
    scanf("%lf", &číslo1);    
    
    printf("Zadej druhý číslo: ");
    scanf("%lf", &číslo2);
    
    switch(operace){
        case '+':
            výsledek = číslo1 + číslo2;
            printf("\nVýsledek: %.2lf", výsledek);
            break;
        case '-':
            výsledek = číslo1 - číslo2;
            printf("\nVýsledek: %.2lf", výsledek);
            break;
        case '*':
            výsledek = číslo1 * číslo2;
            printf("\nVýsledek: %.2lf", výsledek);
            break;
        case '/':
            výsledek = číslo1 / číslo2;
            printf("\nVýsledek: %.2lf", výsledek);
            break;
    } 
        return 0;

}