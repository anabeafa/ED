#include <stdio.h>
#include <ctype.h>
#include "../ed/fila.h" 
#include "../ed/pilha.h" 

int main(void) {
    char s[256];
    Fila F = fila(256);
    Pilha P = pilha(256);

    printf("\nFrase? ");
    gets(s);

    for (int i = 0; s[i]; i++) {
        if (isalpha(s[i])) {
            enfileira(toupper(s[i]), &F);
            empilha(toupper(s[i]), &P);
        }
    }

    while (!vaziaf(&F) && desenfileira(&F) == desempilha(&P));

    if (vaziaf(&F)) {
        puts("A frase é palíndroma");
    } else {
        puts("A frase não é palíndroma");
    }

    destroif(&F);
    destroip(&P);
    return 0;
}