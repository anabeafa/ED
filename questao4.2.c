/*4.2 Qual a saida exibida pelo programa a seguir?
include <stdio.h>
#include "../ed/fila.h" // fila de char

int main(void) {
    Fila F = fila(5);
    
    for (int i = 0; i <= 3; i++)
        enfileira('A' + i, &F);

    while (!vaziaf(&F))
        printf("%c\n", desenfileira(&F));

    destroif(&F);
    return 0;
}

O código criará uma fila de tamanho 5, enfileirará os caracteres de 'A' a 'D' e, em seguida, 
desenfileirará esses caracteres, imprimindo-os na tela.
*/
