#ifndef GAME_SCORE_H
#define GAME_SCORE_H

/// PROTOTIPOS, DECLARAÇÕES E BIBLIOTECAS DO PROGRAMA "game-info"
// Bibliotecas utilizadas:
#include <stdio.h>
#include <stdbool.h>
#include <conio2.h>
#include <time.h>
#include <stdlib.h>
#include "aux-def.h" // puxa as estruturas e definicoes do programa

// OBJETIVO: dado uma estrutura com o nome do jogador e seu escore, a função salva o escore no arquivo caso não existe um outro escore maior que esse do mesmo jogador
void salva_score(score_st actual_player);

// OBJETIVO: le e imprime os 10 melhores escores salvos no arquivo, caso não tenha todos os 10 é impresso uma linha NULA.
void le_score();

// OBJETIVO: gerencia e imprime as informações da seção de escore do jogo.
void printa_score();

// OBJETIVO: imprime as letras personalizadas com a palavra ESCORE
void printa_score_letras();

// OBJETIVO: procura o escore de algum jogador para ser reutilizado como parametro para o usuario
float busca_score(player_st* actual_player);

#endif // GAME_SCORE_H

