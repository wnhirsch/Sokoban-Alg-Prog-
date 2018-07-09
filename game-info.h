#ifndef GAME_INFO_H
#define GAME_INFO_H

/// PROTOTIPOS, DECLARA��ES E BIBLIOTECAS DO PROGRAMA "game-info"
// Bibliotecas utilizadas:
#include <stdio.h>
#include <string.h>
#include <conio2.h>
#include "aux-def.h" // puxa as estruturas e definicoes do programa

// OBJETIVO: imprime as informa��es da partida no canto direito da tela
void printa_info(player_st* actual_player, int cubos_total, bool cube_cornered);

// OBJETIVO: limpa o espa�o das informa��es da partida
void limpa_espaco_info();

#endif // GAME_INFO_H
