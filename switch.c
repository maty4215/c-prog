#include <stdio.h>

int main() {

    char známka;

    printf("Zadej známku: ");
    scanf("%c", &známka);

    switch(známka){
        case '1':
            printf("Výborný\n");
            break;
        case '2':
            printf("Chvalitebný\n");
            break;
        case '3':
            printf("Dobrý\n");
            break;
        case '4':
            printf("Dostatečný\n");
            break;
        case '5':
            printf("Nedostatečný\n");
            
    }

    return 0;
}