/// FUNÇÕES DO PROGRAMA "start-game-printf"
/// OBJETIVO: GERENCIAR A PARTE GRAFICA DO NIVEL IMPRIMINDO BLOCOS, CUBOS E O PERSONAGEM.
#include "start-game-printf.h" // chama a biblioteca de prototipos do programa "start-game-printf"

void printa_nivel(char actual_level[N_LINHA+1][N_COL+1], int* x, int* y)
{
    int i, j; // variaveis de controle da funcao 'for'

    // Percorre toda a matriz 'nivel' verificando todos os
    // seus caracteres.
    for(i = 0; i < N_LINHA; i++)
    {
        for(j = 0; j < N_COL; j++)
        {
            switch(actual_level[i][j])
            {
                // Para 'x' imprime um bloco
                case 'x':
                    printa_bloco(j*2+2, i*2+4);
                    break;
                // Para '0' ou '3' (posicao randomica) imprime um espaco vazio
                case '3':
                case '0':
                    printa_chao(j*2+2, i*2+4);
                    break;
                // Para '1' imprime o jogador
                case '1':
                    printa_player(j*2+2, i*2+4);
                    *x = i;
                    *y = j;
                    break;
                // Para '2' imprime um cubo
                case '2':
                    printa_cubo(j*2+2, i*2+4);
                    break;
                // Para '#' imprime um cubo posicionado no lugar randomico certo
                case '#':
                    printa_cubo_certo(j*2+2, i*2+4);
                    break;
            }
        }
    }
    // Retorna para as cores padroes
    textcolor(LIGHTGRAY);
    textbackground(BLACK);
}

// Limpa a região central onde ocorre o jogo inserindo um espaço vazio nela
void limpa_espaco_game()
{
    int i, j;
    textcolor(WHITE);
    textbackground(BLACK);
    for(i = 0; i < N_LINHA*2; i++)
    {
        for(j = 0; j < N_COL*2-2; j++)
            cputsxy(j+2, i+4, " ");
    }
}

void anuncia_level(int num_level)
{
    limpa_espaco_game();
    cputsxy(18, 9, "***************");
    cputsxy(18, 10, "***************");
    cputsxy(18, 11, "**           **");
    gotoxy(18, 12);
    printf("**  NIVEL %d  **", num_level);
    cputsxy(18, 13, "**           **");
    cputsxy(18, 14, "***************");
    cputsxy(18, 15, "***************");
    Sleep(2000);
    limpa_espaco_game();
}

void anuncia_vitoria()
{
    limpa_espaco_game();
    cputsxy(18, 9, "***************");
    cputsxy(18, 10, "***************");
    cputsxy(18, 11, "**           **");
    cputsxy(18, 12, "**  YOU WIN! **");
    cputsxy(18, 13, "**           **");
    cputsxy(18, 14, "***************");
    cputsxy(18, 15, "***************");
    Sleep(2000);
    limpa_espaco_game();
}

void printa_bloco(int x, int y)
{
    // Cores de um bloco
    textcolor(WHITE);
    textbackground(RED);
    // Imprime o caractere que representa um bloco na posicao x e y
    cputsxy(x, y, "*");
    cputsxy(x, y+1, "*");
    cputsxy(x+1, y, "*");
    cputsxy(x+1, y+1, "*");
}

void printa_chao(int x, int y)
{
    // Cores de um espaco vazio
    textcolor(WHITE);
    textbackground(WHITE);
    // Imprime o caractere que representa um espacio vazio na posicao x e y
    cputsxy(x, y, " ");
    cputsxy(x, y+1, " ");
    cputsxy(x+1, y, " ");
    cputsxy(x+1, y+1, " ");
}

void printa_player(int x, int y)
{
    // Cores do jogador
    textcolor(DARKGRAY);
    textbackground(LIGHTGRAY);
    // Imprime o caractere que representa o jogador na posicao x e y
    cputsxy(x, y, "+");
    cputsxy(x, y+1, "+");
    cputsxy(x+1, y, "+");
    cputsxy(x+1, y+1, "+");
}

void printa_cubo(int x, int y)
{
    // Cores de um cubo
    textcolor(YELLOW);
    textbackground(BROWN);
    // Imprime o caractere que representa um cubo na posicao x e y
    cputsxy(x, y, "/");
    cputsxy(x, y+1, "\\");
    cputsxy(x+1, y, "\\");
    cputsxy(x+1, y+1, "/");
}

void printa_cubo_certo(int x, int y)
{
    // Cores de um cubo posicionado no lugar randomico certo
    textcolor(LIGHTGREEN);
    textbackground(GREEN);
    // Imprime o caractere que representa um cubo posicionado no lugar randomico certo na posicao x e y
    cputsxy(x, y, "#");
    cputsxy(x, y+1, "#");
    cputsxy(x+1, y, "#");
    cputsxy(x+1, y+1, "#");
}
