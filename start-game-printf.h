#ifndef START_GAME_PRINTF_H
#define START_GAME_PRINTF_H

/// PROTOTIPOS, DECLARAÇÕES E BIBLIOTECAS DO PROGRAMA "start-game-printf"
// Bibliotecas utilizadas:
#include <stdio.h>
#include <conio2.h>
#include <stdbool.h>
#include <windows.h>
#include "aux-def.h" // puxa as estruturas e definicoes do programa

// OBJETIVO: dada uma matriz representando um nivel, imprime todos os seus dados graficamente formatados.
//              A funcao tambem recebe o endereco de duas variaveis para controlar a atual do jogador na matriz.
void printa_nivel(char actual_level[N_LINHA+1][N_COL+1], int* x, int* y);

// OBJETIVO: limpa a região dedicada a exibição do nivel
void limpa_espaco_game();

// OBJETIVO: exibe uma mensagem mostrando o nivel atual do jogador
void anuncia_level(int num_level);

// OBJETIVO: exibe uma mensagem mostrando que o jogador venceu o jogo
void anuncia_vitoria();

// OBJETIVO: imprime um bloco formatado em uma dada posicao x e y
void printa_bloco(int x, int y);

// OBJETIVO: imprime um espaco vazio formatado em uma dada posicao x e y
void printa_chao(int x, int y);

// OBJETIVO: imprime o jogador formatado em uma dada posicao x e y
void printa_player(int x, int y);

// OBJETIVO: imprime um cubo formatado em uma dada posicao x e y
void printa_cubo(int x, int y);

// OBJETIVO: imprime um cubo posicionado no lugar randomico certo formatado em uma dada posicao x e y
void printa_cubo_certo(int x, int y);

#endif // START_GAME_PRINTF_H
