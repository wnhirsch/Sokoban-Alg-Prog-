#include "game-info.h"

void printa_info(player_st* actual_player, int cubos_total, bool cube_cornered)
{
    textcolor(WHITE);
    int tam_nome = strlen(actual_player->player_name);
    int rest_time = (cubos_total * 20) - actual_player->game_time_actual;

    // Imprime o nome do jogador na região de informações
    cputsxy(MIN_X + ((SIZE_AREA - tam_nome) / 2), MIN_Y + 1, actual_player->player_name);

    // Imprime o nivel do jogador na região de informações
    gotoxy(MIN_X + 6, MIN_Y + 3);
    printf("LEVEL %d", actual_player->current_level);

    // Imprime a quantidade de cubos atual e total no jogo
    cputsxy(MIN_X + 3, MIN_Y + 11, "CUBES");
    gotoxy(MIN_X + 3, MIN_Y + 12);
    printf("%d / %d", actual_player->cubes_ok, cubos_total);

    // Imprime a quantidade de movimentos do jogador
    cputsxy(MIN_X + 12, MIN_Y + 11, "MOVES");
    gotoxy(MIN_X + 13, MIN_Y + 12);
    printf("%2d", actual_player->num_moves_actual);

    // Imprime o tempo restante de partida do jogador
    cputsxy(MIN_X + 3, MIN_Y + 14, "TIME");
    gotoxy(MIN_X + 4, MIN_Y + 15);
    printf("%03d", rest_time);

    // Imprime o escore total e o salvo no arquivo "highscore.bin" do jogador
    cputsxy(MIN_X + 12, MIN_Y + 14, "SCORE");
    gotoxy(MIN_X + 10, MIN_Y + 15);
    printf("%03.1f/%03.1f", actual_player->score_total, actual_player->last_score);

    // Caso um dos cubos esteja trancado em um canto, exibe a opção de reinicia-la
    if(cube_cornered)
        cputsxy(MIN_X + 4, MIN_Y + 17, "[R] RESTART");
}

void limpa_espaco_info()
{
    // Insere um espaço vazio no canto direito do esoaço do jogo
    int i, j;
    textcolor(WHITE);
    textbackground(BLACK);
    for(i = 0; i < SIZE_AREA; i++)
    {
        for(j = 0; j < SIZE_AREA; j++)
            cputsxy(MIN_X+j, MIN_Y+i, " ");
    }
}


