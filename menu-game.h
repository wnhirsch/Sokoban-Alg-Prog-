#ifndef MENU_GAME_H
#define MENU_GAME_H

/// PROTOTIPOS, DECLARAÇÕES E BIBLIOTECAS DO PROGRAMA "menu-game"
// Bibliotecas utilizadas:
#include <stdio.h>
#include <stdbool.h>
#include "aux-def.h" // puxa as estruturas e definicoes do programa

// OBJETIVO: gerenciar o menu superior da partida.
situation menu(player_st* actual_player, char actual_level[N_LINHA+1][N_COL+1]);

// OBJETIVO: gerencia as funções do menu superior sem entrar nele (por meio de letras)
situation menu_control(char keypress, char actual_level[N_LINHA+1][N_COL+1], player_st* actual_player, bool cube_cornered);

// OBJETIVO: pausa o jogo até o jogador pressionar a tecla ENTER
void pause_game(player_st* actual_player);

#endif // MENU_GAME_H
