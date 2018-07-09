#ifndef MENU_GAME_PRINTF_H
#define MENU_GAME_PRINTF_H

/// PROTOTIPOS, DECLARAÇÕES E BIBLIOTECAS DO PROGRAMA "menu-game-printf"
// Bibliotecas utilizadas:
#include <stdio.h>
#include <conio2.h>
#include <stdbool.h>
#include "aux-def.h" // puxa as estruturas e definicoes do programa

// OBJETIVO: imprime o contorno do espaco do jogo e o menu superior dada uma opcao seleciona (option)
void printa_menu(int selec_option);

// OBJETIVO: imprime a opcao "NOVO JOGO" com mudanca na cor dependendo do booleano'tem_cor'
void printa_N(bool tem_cor);

// OBJETIVO: imprime a opcao "SALVAR" com mudanca na cor dependendo do booleano 'tem_cor'
void printa_S(bool tem_cor);

// OBJETIVO: imprime a opcao "PAUSAR" com mudanca na cor dependendo do booleano 'tem_cor'
void printa_P(bool tem_cor);

// OBJETIVO: imprime a opcao "ESCORE" com mudanca na cor dependendo do booleano 'tem_cor'
void printa_E(bool tem_cor);

// OBJETIVO: imprime a opcao "QUIT" com mudanca na cor dependendo do booleano 'tem_cor'
void printa_Q(bool tem_cor);

// OBJETIVO: imprime o contorno do espaco do jogo
void printa_contorno();

#endif // MENU_GAME_PRINTF_H
