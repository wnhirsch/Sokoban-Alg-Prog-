#ifndef SAVE_GAME_H
#define SAVE_GAME_H

/// PROTOTIPOS, DECLARAÇÕES E BIBLIOTECAS DO PROGRAMA "save-game"
// Bibliotecas utilizadas:
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "aux-def.h" // puxa as estruturas e definicoes do programa

// OBJETIVO: cria um arquivo "nomedojogador001.txt" com todos os dados da partida atual
void write_save_game(player_st* actual_player, char actual_level[N_LINHA+1][N_COL+1]);

// OBJETIVO: cria um arquivo "pausa.bin" com todos os dados da partida atual
void write_pause_game(player_st* actual_player, char actual_level[N_LINHA+1][N_COL+1]);

// OBJETIVO: le um arquivo com o jogo salvo do jogador baseado no valor da váriavel 'num_save' e retorna os dados para a partida
void read_save_game(player_st* actual_player, char actual_level[N_LINHA+1][N_COL+1], int num_save);

// OBJETIVO: le um arquivo de pausa retornando os dados dele para a partida
void read_pause_game(player_st* actual_player, char actual_level[N_LINHA+1][N_COL+1]);

// OBJETIVO: verifica quantos arquivos de jogo salvo há no nome daquele jogador
int verifica_savegame(char player_name[]);

// OBJETIVO: verifica se o arquivo de pausa existente é do jogador atual
bool verifica_pause(char player_name[]);

#endif // SAVE_GAME_H
