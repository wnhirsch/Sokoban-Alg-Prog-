#ifndef GAME_MODE_H
#define GAME_MODE_H

/// PROTOTIPOS, DECLARAÇÕES E BIBLIOTECAS DO PROGRAMA "single-game"
// Bibliotecas utilizadas:
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio2.h>
#include <ctype.h>
#include <windows.h>
#include <math.h>
#include "aux-def.h" // puxa as estruturas e definicoes do programa

// OBJETIVO: Gerenciar toda a partida de um certo jogador do comeco ao fim
void single_player();

// OBJETIVO: dado um jogador, verifica se ha algum dados seus salvos e, caso o mesmo queira, retorna esses dados para reutiliza-los na partida
bool busca_save(player_st* actual_player, char actual_level[N_LINHA+1][N_COL+1]);

// OBJETIVO: dado um jogador, retorna a sua pontuacao atual no jogo
float calcula_score(player_st* actual_player);

#endif // GAME_MODE_H
