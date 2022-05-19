#include <stdio.h>

int main() {

    int věk;

    printf("Zadej svůj věk: ");
    scanf("%dL", &věk);

    if(věk >= 18){
        printf("Jste zapojeni do soutěže");
    }
    else{
        printf("Jsi moc mladý pro zapojení do soutěže");
    }
    
    return 0;
}