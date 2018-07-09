#include "start-game.h"
#include "start-game-printf.h"
#include "game-info.h"
#include "single-game.h"
#include "menu-game-printf.h"
#include "save-game.h"
#include "game-score.h"

void single_player()
{
    // DECLARAÇÕES:
    char actual_level[N_LINHA+1][N_COL+1]; // dados do nivel atual
    player_st actual_player; // dados do jogador atual
    score_st actual_player_score;
    situation game_situation; // atual situacao do jogo
    int char_tam; // tamanho do nome do jogador para retirada do '\n' no fgets
    bool tem_pause, rec_game;

    do{
        // limpa a tela, printa o menu e contorno do jogo e define a situacao do jogo como normal
        limpa_espaco_game();
        limpa_espaco_info();
        printa_menu(0);
        game_situation = normal_game;

        // Le o nome do jogador
        cputsxy(13, 10, "Insira o seu nome (1-20):");
        cputsxy(13, 12, "--> ");
        fgets(actual_player.player_name, 20, stdin);
        char_tam = strlen(actual_player.player_name);
        actual_player.player_name[char_tam-1] = '\0';

        // verifica se há algum arquivo de pausa com o nick do jogador atual
        tem_pause = verifica_pause(actual_player.player_name);
        if(tem_pause)
            // caso tenha, leia esse arquivo e inicia o jogo anterior
            read_pause_game(&actual_player, actual_level);
        else
        {
            // procura algum arquivo de partida salva com o nome do jogador e pergunta se ele quer recupera-la
            rec_game = busca_save(&actual_player, actual_level);
            // caso não queira os dados iniciam zerados
            if(!rec_game)
            {
                actual_player.current_level = 1;
                actual_player.cubes_ok = 0;
                actual_player.levels_ok = 0;
                actual_player.num_moves_actual = 0;
                actual_player.num_moves_total = 0;
                actual_player.game_time_total = 0;
                actual_player.game_time_actual = 0;
                actual_player.score_total = 0;
            }
        }
        actual_player.last_score = busca_score(&actual_player);
        // enquanto o jogador não vencer, voltar ao menu ou reiniciar o jogo...
        do{
            // inicia um nivel e ao final dele reconta o escore
            limpa_espaco_game();
            limpa_espaco_info();
            printa_menu(0);
            game_situation = new_level(&actual_player, actual_level);
            actual_player.score_total = calcula_score(&actual_player);
        }while(game_situation != win_game && game_situation != new_game && game_situation != exit_game);

        // Salca o escore final do jogador e o exibe
        strcpy(actual_player_score.player_name, actual_player.player_name);
        actual_player_score.player_score = actual_player.score_total;
        salva_score(actual_player_score);
        printa_score();
    }while(game_situation != exit_game);
}

bool busca_save(player_st* actual_player, char nivel[N_LINHA+1][N_COL+1])
{
    int num_saves, actual_save;
    char option1 = NULL;
    int option2;

    // Procura partidas salvas no nome do jogador
    num_saves = verifica_savegame(actual_player->player_name) - 1;
    // Caso tenha pergunta se o usuario quer reutiliza-las
    if(num_saves != 0)
    {
        limpa_espaco_game();
        cputsxy(8, 10, "Encontramos partidas salvas anteriormente");
        cputsxy(12, 11, " com o seu nick.");
        cputsxy(10, 13, "Deseja reinicia-los? (S/N) --> ");
        do
        {
            gotoxy(41, 13);
            while(!kbhit()){}
            option1 = getche();
        }
        while(toupper(option1) != 'S' && toupper(option1) != 'N');

        // Se sim ele pergunta qual delas
        if(toupper(option1) == 'S')
        {
            limpa_espaco_game();
            cputsxy(8, 10, "Selecione a partida desejada ");
            cputsxy(8, 11, "com as teclas direcionais ");
            actual_save = 1;
            do{
                gotoxy(34, 11);
                printf("< %d >", actual_save);
                do{
                    while(!kbhit()){}
                    option2 = getch();
                }while(option2 != EXT && option2 != ENTER);
                if(option2 != ENTER)
                {
                    if(getch() == RIGHT)
                    {
                        if(actual_save == num_saves)
                            actual_save = 1;
                        else
                            actual_save++;
                    }
                    else if(getch() == LEFT)
                    {
                        if(actual_save == 1)
                            actual_save = num_saves;
                        else
                            actual_save--;
                    }
                }
            }while(option2 != ENTER);

            // Escolhida qual ele busca o save respectivo
            read_save_game(actual_player, nivel, actual_save);
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

float calcula_score(player_st* actual_player)
{
    float score;
    score = (pow(10, 3) * pow(actual_player->levels_ok, 3)) / (actual_player->num_moves_total + (actual_player->game_time_total / 2));
    return score;
}
