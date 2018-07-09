#include "quit-game.h"

void quit_game()
{
    // DECLARACOES
    int i; // Variável de contagem da funcao 'for'


    // Muda a cor do texto para branco, a cor do fundo para preto e limpa a tela
    textbackground(BLACK);
    textcolor(WHITE);
    clrscr();

    // Imprime uma mensagem de despedida na posicao (25,4)
    cputsxy(30, 9, "||                  ||");
    cputsxy(30, 10, "|| Ate a proxima!!! ||");
    cputsxy(30, 11, "||                  ||");

    // Imprime varios '=' acima e abaixo da mensagem com a intencao de embeleza-la
    for(i = 0; i < 22; i++)
    {
        cputsxy(i+30, 7, "=");
        cputsxy(i+30, 8, "=");
        cputsxy(i+30, 12, "=");
        cputsxy(i+30, 13, "=");
    }
    printf("\n\n\n\n\n\n\n");
    exit(0);
}

