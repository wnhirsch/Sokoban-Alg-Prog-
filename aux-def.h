#ifndef AUX_DEF_H
#define AUX_DEF_H

/// PROTOTIPOS, DECLARAÇÕES E BIBLIOTECAS DO PROGRAMA "game-info"
// Bibliotecas utilizadas:
#include <stdio.h>
#include <stdbool.h>
#include <conio2.h>
#include <windows.h>

// Constantes utilizadas:
// * valores destas teclas na Tabela ASCII
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define EXT 224 // 2 byte das teclas de extensao do teclado
#define ENTER 13
#define TAB 9
#define ESC 27
// * valores dos limites da area de impressao de caracteres
#define MIN_X 51
#define MAX_X 70
#define MIN_Y 4
#define MAX_Y 23
#define SIZE_AREA 20 // comprimento e largura da area de impressao
// * valores da dimensao do nivel
#define N_LINHA 10
#define N_COL 25
// * valor do comprimento do prompt
#define TAM_HORIZ 80

// Representa todos os dados do jogador atual
typedef struct{
    char player_name[21];
    int current_level;
    int cubes_ok;
    int levels_ok;
    int num_moves_actual;
    int num_moves_total;
    unsigned int game_time_actual;
    unsigned int game_time_total;
    float last_score;
    float score_total;
}player_st;

// Representa os dados a serem salvos na chamada da funcao PAUSAR
typedef struct{
    char actual_level[N_LINHA+1][N_COL+1];
    player_st actual_player;
}pause_st;

// Representa os dados a serem salvos no arquivo 'highscore.bin' ao fim de cada jogo
typedef struct{
    char player_name[21];
    float player_score;
}score_st;

// Representa a situacao do atual nivel para melhor comunicacao entre as funcoes e clareza de codigo
typedef enum{
normal_game, win_level, win_game, lose_game, new_game, exit_game}situation;

// OBJETIVO: tirar o cursor da tela para não travar a impressão do jogo dentre outros
void hidecursor();

// OBJETIVO: verificar se todos os arquivos necessários estão disponíveis para a inicialização do jogo devolvendo um booleano representando tal estado
bool verify_files();

// OBJETIVO: Exibir mensagem de erro na abertura, leitura ou escrita dos arquivos e encerra o programa
void cant_start();

#endif // AUX_DEF_H
