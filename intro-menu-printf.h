#ifndef INTRO_MENU_PRINTF_H
#define INTRO_MENU_PRINTF_H

/// PROTOTIPOS, DECLARAÇÕES E BIBLIOTECAS DO PROGRAMA "intro-menu-printf"
// Bibliotecas utilizadas:
#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <time.h>
#include "aux-def.h" // puxa as estruturas e definicoes do programa

void letra_A_peq(int x, int y); // ==
void letra_C_peq(int x, int y); //   |
void letra_D_peq(int x, int y); //   |
void letra_M_peq(int x, int y); //   | OBJETIVO: dada uma posicao x e y a funcao imprime a letra correspondente no nome
void letra_N_peq(int x, int y); //   |              da funcao de tamanho 4x4 (pequeno) com cor randomica.
void letra_O_peq(int x, int y); //   |
void letra_R_peq(int x, int y); //   |
void letra_Y_peq(int x, int y); //   |
void letra_Z_peq(int x, int y); // ==

void letra_A_grd(int x, int y); // ==
void letra_B_grd(int x, int y); //   |
void letra_C_grd(int x, int y); //   |
void letra_E_grd(int x, int y); //   |
void letra_K_grd(int x, int y); //   | OBJETIVO: dada uma posicao x e y a funcao imprime a letra correspondente no nome
void letra_N_grd(int x, int y); //   |              da funcao de tamanho 5x5 (grande) com cor randomica.
void letra_O_grd(int x, int y); //   |
void letra_R_grd(int x, int y); //   |
void letra_S_grd(int x, int y); // ==

// OBJETIVO: dada uma posicao inicial x e y e uma quantidade a funcao imprime varios "=" horizontalmente
void printa_sinaldeigual(int x, int y, int intervalo);

// OBJETIVO: dada uma posicao inicial x e y e uma quantidade a funcao imprime varios "|" verticalmente
void printa_sinaldeou(int x, int y, int intervalo);

// OBJETIVO: a funcao imprime as opcoes do menu introdutorio e, dependendo do valor da variavel 'now_option' (1-6), ela colore
//              o nome da opcao para deixa-la em destaque
void printa_options(int now_option);

// OBJETIVO: dada todas as letras ja declaradas, a funcao printa elas em ordem formando o titulo do jogo ("CRAZY RANDOM SOKOBAN")
void printa_title_letras();

// OBJETIVO: dada todas as funcoes anteriores, a funcao imprime o menu introdutorio completo.
void printa_intro();

#endif // INTRO_MENU_PRINTF_H
