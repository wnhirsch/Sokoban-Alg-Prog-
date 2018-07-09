/// FUNÇÕES DO PROGRAMA "intro-menu-printf"
/// OBJETIVO: IMPRIMIR O MENU INTRODUTORIO DO JOGO
#include "intro-menu-printf.h"

void printa_intro()
{
    clrscr(); // apaga tudo que esta na tela

    // imprime varios "=" formando o contorno horizontal
    printa_sinaldeigual(1, 1, TAM_HORIZ);
    printa_sinaldeigual(1, 14, TAM_HORIZ);
    printa_sinaldeigual(1, 24, TAM_HORIZ);

    // imprime varios "|" formando o contorno vertical
    printa_sinaldeou(1, 2, 12);
    printa_sinaldeou(1, 15, 9);
    printa_sinaldeou(TAM_HORIZ, 15, 9);
    printa_sinaldeou(TAM_HORIZ, 2, 12);

    // imprime as letras representando o titulo do jogo
    printa_title_letras();

    // imprime as opcoes do menu, declarando a opcao '1' como a primeira em destaque
    printa_options(1);
}

void printa_options(int now_option)
{
    // imprime instrucao ao usuario
    cputsxy(22, 15, "Selecione uma opcao para continuar:");

    // gerencia qual cor estara em destaque dada a variavel 'now_option'
    switch(now_option)
    {
        // destaca a opcao 1
        case 1:
            textbackground(WHITE);
            textcolor(BLACK);
            cputsxy(25, 18, "[START GAME]");
            textbackground(BLACK);
            textcolor(WHITE);
            cputsxy(27, 21, "[ESCORES]");
            cputsxy(40, 18, "[INSTRUCOES]");
            cputsxy(43, 21, "[QUIT]");
            break;
        // destaca a opcao 2
        case 2:
            cputsxy(25, 18, "[START GAME]");
            textbackground(WHITE);
            textcolor(BLACK);
            cputsxy(27, 21, "[ESCORES]");
            textbackground(BLACK);
            textcolor(WHITE);
            cputsxy(40, 18, "[INSTRUCOES]");
            cputsxy(43, 21, "[QUIT]");
            break;
        // destaca a opcao 3
        case 3:
            cputsxy(25, 18, "[START GAME]");
            cputsxy(27, 21, "[ESCORES]");
            textbackground(WHITE);
            textcolor(BLACK);
            cputsxy(40, 18, "[INSTRUCOES]");
            textbackground(BLACK);
            textcolor(WHITE);
            cputsxy(43, 21, "[QUIT]");
            break;
        // destaca a opcao 4
        case 4:
            cputsxy(25, 18, "[START GAME]");
            cputsxy(27, 21, "[ESCORES]");
            cputsxy(40, 18, "[INSTRUCOES]");
            textbackground(WHITE);
            textcolor(BLACK);
            cputsxy(43, 21, "[QUIT]");
            textbackground(BLACK);
            textcolor(WHITE);
            break;
    }
}

void printa_title_letras()
{
    srand(time(NULL)); // gera semente randomica

    // Imprime a palavra "CRAZY" nas posicoes pre-definidas
    letra_C_peq(12,3);
    letra_R_peq(17,3);
    letra_A_peq(22,3);
    letra_Z_peq(27,3);
    letra_Y_peq(32,3);

    // Imprime a palavra "RANDOM" nas posicoes pre-definidas
    letra_R_peq(39,3);
    letra_A_peq(44,3);
    letra_N_peq(49,3);
    letra_D_peq(54,3);
    letra_O_peq(59,3);
    letra_M_peq(64,3);

    // Imprime a palavra "SOKOBAN" nas posicoes pre-definidas
    letra_S_grd(20,8);
    letra_O_grd(26,8);
    letra_K_grd(32,8);
    letra_O_grd(38,8);
    letra_B_grd(44,8);
    letra_A_grd(50,8);
    letra_N_grd(56,8);

    // retorna para a cor padrao devido as grandes alteracoes
    textcolor(WHITE);
}

void letra_A_peq(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, "AAAA"); // ==
    cputsxy(x, y+1, "A  A"); //   | > Imprime a letra 'A' em tamanho pequeno
    cputsxy(x, y+2, "AAAA"); //   |
    cputsxy(x, y+3, "A  A"); // ==
}

void letra_C_peq(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, "CCCC"); // ==
    cputsxy(x, y+1, "C   "); //   | > Imprime a letra 'C' em tamanho pequeno
    cputsxy(x, y+2, "C   "); //   |
    cputsxy(x, y+3, "CCCC"); // ==
}

void letra_D_peq(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, "DDD "); // ==
    cputsxy(x, y+1, "D  D"); //   | > Imprime a letra 'D' em tamanho pequeno
    cputsxy(x, y+2, "D  D"); //   |
    cputsxy(x, y+3, "DDD "); // ==
}


void letra_M_peq(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, "M   M"); // ==
    cputsxy(x, y+1, "MM MM"); //   | > Imprime a letra 'M' em tamanho pequeno
    cputsxy(x, y+2, "M M M"); //   |
    cputsxy(x, y+3, "M   M"); // ==
}

void letra_N_peq(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, "N  N"); // ==
    cputsxy(x, y+1, "NN N"); //   | > Imprime a letra 'N' em tamanho pequeno
    cputsxy(x, y+2, "N NN"); //   |
    cputsxy(x, y+3, "N  N"); // ==
}

void letra_O_peq(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, " OO "); // ==
    cputsxy(x, y+1, "O  O"); //   | > Imprime a letra 'O' em tamanho pequeno
    cputsxy(x, y+2, "O  O"); //   |
    cputsxy(x, y+3, " OO "); // ==
}

void letra_R_peq(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, "RRRR"); // ==
    cputsxy(x, y+1, "R  R"); //   | > Imprime a letra 'R' em tamanho pequeno
    cputsxy(x, y+2, "R R "); //   |
    cputsxy(x, y+3, "R  R"); // ==
}

void letra_Y_peq(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, "Y  Y"); // ==
    cputsxy(x, y+1, "Y  Y"); //   | > Imprime a letra 'Y' em tamanho pequeno
    cputsxy(x, y+2, " YY "); //   |
    cputsxy(x, y+3, " YY "); // ==
}

void letra_Z_peq(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, "ZZZZ"); // ==
    cputsxy(x, y+1, "  Z "); //   | > Imprime a letra 'Z' em tamanho pequeno
    cputsxy(x, y+2, " Z  "); //   |
    cputsxy(x, y+3, "ZZZZ"); // ==
}

void letra_A_grd(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, "AAAAA"); // ==
    cputsxy(x, y+1, "A   A"); //   |
    cputsxy(x, y+2, "AAAAA"); //   | > Imprime a letra 'A' em tamanho grande
    cputsxy(x, y+3, "A   A"); //   |
    cputsxy(x, y+4, "A   A"); // ==
}

void letra_B_grd(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, "BBBB "); // ==
    cputsxy(x, y+1, "B   B"); //   |
    cputsxy(x, y+2, "BBBB "); //   | > Imprime a letra 'B' em tamanho grande
    cputsxy(x, y+3, "B   B"); //   |
    cputsxy(x, y+4, "BBBB "); // ==
}

void letra_C_grd(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, "CCCCC"); // ==
    cputsxy(x, y+1, "C    "); //   |
    cputsxy(x, y+2, "C    "); //   | > Imprime a letra 'B' em tamanho grande
    cputsxy(x, y+3, "C    "); //   |
    cputsxy(x, y+4, "CCCCC"); // ==
}

void letra_E_grd(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, "EEEEE"); // ==
    cputsxy(x, y+1, "E    "); //   |
    cputsxy(x, y+2, "EEEEE"); //   | > Imprime a letra 'B' em tamanho grande
    cputsxy(x, y+3, "E    "); //   |
    cputsxy(x, y+4, "EEEEE"); // ==
}

void letra_K_grd(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, "K   K"); // ==
    cputsxy(x, y+1, "K  K "); //   |
    cputsxy(x, y+2, "KKK  "); //   | > Imprime a letra 'K' em tamanho grande
    cputsxy(x, y+3, "K  K "); //   |
    cputsxy(x, y+4, "K   K"); // ==
}

void letra_O_grd(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, " OOO "); // ==
    cputsxy(x, y+1, "O   O"); //   |
    cputsxy(x, y+2, "O   O"); //   | > Imprime a letra 'O' em tamanho grande
    cputsxy(x, y+3, "O   O"); //   |
    cputsxy(x, y+4, " OOO "); // ==
}

void letra_N_grd(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, "N   N"); // ==
    cputsxy(x, y+1, "NN  N"); //   |
    cputsxy(x, y+2, "N N N"); //   | > Imprime a letra 'N' em tamanho grande
    cputsxy(x, y+3, "N  NN"); //   |
    cputsxy(x, y+4, "N   N"); // ==
}

void letra_R_grd(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, "RRRR "); // ==
    cputsxy(x, y+1, "R   R"); //   |
    cputsxy(x, y+2, "RRRR "); //   | > Imprime a letra 'S' em tamanho grande
    cputsxy(x, y+3, "R  R "); //   |
    cputsxy(x, y+4, "R   R"); // ==
}

void letra_S_grd(int x, int y)
{
    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(x, y+0, " SSSS"); // ==
    cputsxy(x, y+1, "S    "); //   |
    cputsxy(x, y+2, " SSS "); //   | > Imprime a letra 'S' em tamanho grande
    cputsxy(x, y+3, "    S"); //   |
    cputsxy(x, y+4, "SSSS "); // ==
}

void printa_sinaldeigual(int x, int y, int intervalo)
{
    int i; // variavel de controle do 'for'
    // define a cor padrao
    textcolor(WHITE);
    textbackground(BLACK);
    // insere "=" horizontalmente
    for(i = 0; i < intervalo; i++)
        cputsxy(x+i, y, "=");
}

void printa_sinaldeou(int x, int y, int intervalo)
{
    int i; // variavel de controle do 'for'
    // define a cor padrao
    textcolor(WHITE);
    textbackground(BLACK);
    // insere "|" verticalmente
    for(i = 0; i < intervalo; i++)
        cputsxy(x, y+i, "|");
}
