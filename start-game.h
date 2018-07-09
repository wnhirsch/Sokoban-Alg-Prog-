#ifndef START_GAME_H
#define START_GAME_H

/// PROTOTIPOS, DECLARAÇÕES E BIBLIOTECAS DO PROGRAMA "start-game"
// Bibliotecas utilizadas:
#include <stdio.h>
#include <string.h>
#include <conio2.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "aux-def.h" // puxa as estruturas e definicoes do programa

// OBJETIVO: inicia um novo nivel baseado na matriz com os dados do nivel inseridas nela mas principalmente da estrutura jogador onde exibe tempo, movimentos, cubos, escore, nivel, etc.
situation new_level(player_st* actual_player, char actual_level[N_LINHA+1][N_COL+1]);

// OBJETIVO: dado um inteiro representando o nome do nivel e uma matriz com as dimensões padrores de um nivel retorna a mesma matriz preenchida com o nivel respectivo
void read_level(int nivel_number, char actual_level[N_LINHA+1][N_COL+1]);

// OBJETIVO: dado uma tecla direcional, a matriz representando os dados do nivel e a posição do jogador(x,y) a função modifica o valor da matriz baseado no que havia na frente do jogador ao se mover
void game_movement(int keypress, char actual_level[N_LINHA+1][N_COL+1], int x, int y, int* cubos_ptr);

// OBJETIVO: devolver a matriz nivel com as posicoes randomizadas de onde o cubo deve ser posto
void random_cubes(char actual_level[N_LINHA+1][N_COL+1], int cubos_total);

// OBJETIVO: conta quantos cubos tem no nivel
int count_cubes(char actual_level[N_LINHA+1][N_COL+1]);

// OBJETIVO: conta quantos cubos tem trancados na parede e devolve um booleano caso tenha
bool cube_in_corner(char actual_level[N_LINHA+1][N_COL+1]);

// OBJETIVO: gerencia o som de algumas teclas ao serem pressionadas na partida
void keypress_audio(int keypress);

#endif // START_GAME_H
