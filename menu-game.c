/// FUNÇÕES DO PROGRAMA "menu-game"
/// OBJETIVO: GERENCIAR O MENU SUPERIOR DA PARTIDA
#include "menu-game.h" // chama a biblioteca de prototipos do programa "menu-game"
#include "menu-game-printf.h" // chama a biblioteca de prototipos do programa "menu-game-printf"
#include "start-game.h" // chama a biblioteca de prototipos do programa "start-game"
#include "save-game.h"
#include "game-score.h"

situation menu(player_st* actual_player, char actual_level[N_LINHA+1][N_COL+1])
{
    char keypress; // caractere funcional
    int option = 1; // opcao selecionada padrao = "NOVO JOGO"
    bool return_game = false; // variavel de controle
    situation game_situation = normal_game;

    printa_menu(option); // imprime o menu com a opcao selecionada
    do{
        // aguarda alguma tecla ser pressionada
        while(!kbhit()){}
        keypress = getch();
        keypress_audio(keypress);

        // Faz a verificacao da tecla e destina para a respectiva funcao
        switch (keypress)
        {
            // Se for TAB, troca a opcao selecionada
            case TAB:
                if(option != 5)
                    option++;
                else
                    option = 1;
                break;
            // Se for ENTER vai para a funcao que estava selecionada
            case ENTER:
                switch(option)
                {
                // Inicia um novo jogo
                case 1:
                    option = 0;
                    write_save_game(actual_player, actual_level);
                    game_situation = new_game;
                    return_game = true;
                    break;
                // Salva o jogo
                case 2:
                    option = 0;
                    write_save_game(actual_player, actual_level);
                    return_game = true;
                    break;
                // Pausa o jogo
                case 3:
                    write_pause_game(actual_player, actual_level);
                    printa_menu(3);
                    pause_game(actual_player);
                    read_pause_game(actual_player, actual_level);
                    return_game = true;
                    option = 0;
                    break;
                // Exibe o Escore
                case 4:
                    option = 0;
                    printa_score();
                    return_game = true;
                    break;
                // Retorna para o Menu Principal
                case 5:
                    option = 0;
                    write_save_game(actual_player, actual_level);
                    game_situation = exit_game;
                    break;
                }
            // Retorna para o jogo
            case ESC:
                option = 0;
                return_game = true;
                break;
        }
        printa_menu(option); // imprime o menu com a opcao selecionada
    }while(!return_game);

    return game_situation;
}

situation menu_control(char keypress, char actual_level[N_LINHA+1][N_COL+1], player_st* actual_player, bool cube_cornered)
{
    situation game_situation = normal_game;

    switch(keypress)
    {
        // Vai para o Menu Superior do jogo
        case TAB:
            game_situation = menu(actual_player, actual_level);
            break;
        // Inicia um novo jogo
        case 'n':
        case 'N':
            write_save_game(actual_player, actual_level);
            game_situation = new_game;
            break;
        // Salva o jogo
        case 's':
        case 'S':
            write_save_game(actual_player, actual_level);
            break;
        // Exibe o Escore
        case 'e':
        case 'E':
            printa_score();
            printa_menu(0);
            break;
        // Pausa o Jogo
        case 'p':
        case 'P':
            write_pause_game(actual_player, actual_level);
            printa_menu(3);
            pause_game(actual_player);
            printa_menu(0);
            read_pause_game(actual_player, actual_level);
            break;
        // Reinicia o jogo caso algum dos cubos esteja no canto
        case 'r':
        case 'R':
            if(cube_cornered)
                game_situation = lose_game;
            break;
        // Volta para o Menu Principal
        case 'q':
        case 'Q':
            write_save_game(actual_player, actual_level);
            game_situation = exit_game;
            break;
    }

    return game_situation;
}

void pause_game(player_st* actual_player)
{
    char keypress;
    // O jogo fica parado até o usuário pressionar a tecla ENTER
    do{
        while(!kbhit()){}
        keypress = getch();
        keypress_audio(keypress);
    }while(keypress != ENTER);
}
