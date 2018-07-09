/// FUNÇÕES DO PROGRAMA "start-game"
/// OBJETIVO: DADO UM NIVEL, ADMINISTRAR OS MOVIMENTOS E GRAFICOS DO JOGO NESSE NIVEL.
#include "start-game.h" // chama a biblioteca de prototipos do programa "start-game"
#include "start-game-printf.h" // chama a biblioteca de prototipos do programa "start-game-printf"
#include "menu-game.h" // chama a biblioteca de prototipos do programa "menu-game"
#include "save-game.h"
#include "game-info.h"

situation new_level(player_st* actual_player, char actual_level[N_LINHA+1][N_COL+1])
{
    // DECLARACOES:
    int player_x, player_y; // posicao do jogador nos eixos X e Y
    int keypress; // caractere funcional ou de movimento
    situation game_situation = normal_game; // controla o estado atual do jogo
    int cubos_total; // representa a quantidade de cubos maxima e atual e os movimentos
    clock_t start_time, diference_time; // controla o tempo da partida
    bool cube_cornered = false;
    int max_time; // representa o tempo atual e o tempo maximo do nivel

    cubos_total = count_cubes(actual_level);
    if(actual_player->num_moves_actual == 0)
        read_level(actual_player->current_level, actual_level);
    cubos_total = count_cubes(actual_level);
    if(actual_player->num_moves_actual == 0)
        random_cubes(actual_level, cubos_total);

    max_time = cubos_total * 20;
    anuncia_level(actual_player->current_level);
    start_time = clock();

    printa_nivel(actual_level, &player_x, &player_y);
    // Enquanto...
    //      * o jogador não sair ou iniciar nova partida
    //      * o jogador não colocar todos os cubos no lugar certo(ganhar)
    //      * o jogador não exceder o tempo maximo de partida(perder), faça...
    do{
        while (!kbhit() && game_situation != lose_game)
        {
            diference_time = clock();
            printa_info(actual_player, cubos_total, cube_cornered);
            if((diference_time - start_time) / CLOCKS_PER_SEC == 1)
            {
                cube_cornered = cube_in_corner(actual_level);
                actual_player->game_time_actual++;
                start_time = clock();
                if(max_time < actual_player->game_time_actual)
                    game_situation = lose_game;
            }
        }
        if(game_situation != lose_game)
        {
            keypress = getch();
            if(keypress == EXT)
            {
                game_movement(getch(), actual_level, player_x, player_y, &actual_player->cubes_ok);
                actual_player->num_moves_actual++;
            }
            else
            {
                keypress_audio(keypress);
                game_situation = menu_control(keypress, actual_level, actual_player, cube_cornered);
                start_time = clock();
            }
        }
        printa_nivel(actual_level, &player_x, &player_y);
        if(actual_player->cubes_ok == cubos_total)
            game_situation = win_level;
        setbuf(stdin, NULL);
    }while(game_situation != win_level && game_situation != lose_game && game_situation != new_game && game_situation != exit_game);

    Sleep(250);

    actual_player->game_time_total += actual_player->game_time_actual;
    actual_player->num_moves_total += actual_player->num_moves_actual;
    actual_player->cubes_ok = 0;
    actual_player->game_time_actual = 0;
    actual_player->num_moves_actual = 0;
    if(game_situation == win_level)
    {
        actual_player->levels_ok++;
        actual_player->current_level++;
        if(actual_player->current_level >= 4)
        {
            anuncia_vitoria();
            game_situation = win_game;
        }
    }

    return game_situation;
}

void game_movement(int keypress, char actual_level[N_LINHA+1][N_COL+1], int x, int y, int* cubos_ptr)
{
    // Realiza a verificacao do caractere inserido no teclado da funcao 'new_game'.
    // Se foi a tecla para cima, para baixo, para a esquerda ou para a direita, a localizacao
    // do jogador na matriz 'nivel' sera trocada dependendo do que havia na sua frente, porém
    // caso tenha sido a tecla TAB, o jogo pausa e o jogador vai para o menu na parte superior da tela.
    switch (keypress)
    {
    case LEFT:
        // Se na esquerda do jogador estiver vazio, troca
        if(actual_level[x][y-1] == '0')
        {
            actual_level[x][y] = '0';
            actual_level[x][y-1] = '1';
        }
        // Se na esquerda do jogador for o lugar certo do cubo, troca
        else if(actual_level[x][y-1] == '3')
        {
            actual_level[x][y] = '3';
            actual_level[x][y-1] = '1';
        }
        // Se na esquerda do jogador tiver um cubo...
        else if(actual_level[x][y-1] == '2')
        {
            // ... e na esquerda do cubo estiver vazio, troca
            if(actual_level[x][y-2] == '0')
            {
                actual_level[x][y] = '0';
                actual_level[x][y-1] = '1';
                actual_level[x][y-2] = '2';
            }
            // ... e na esquerda do cubo for o lugar certo, salva como cubo fixo e aumenta um cubo na quantidade do jogador
            else if(actual_level[x][y-2] == '3')
            {
                actual_level[x][y] = '0';
                actual_level[x][y-1] = '1';
                actual_level[x][y-2] = '#';
                *cubos_ptr += 1;
            }
        }
        break;
    case RIGHT:
        // Se na direita do jogador estiver vazio, troca
        if(actual_level[x][y+1] == '0')
        {
            actual_level[x][y] = '0';
            actual_level[x][y+1] = '1';
        }
        // Se na direita do jogador for o lugar certo do cubo, troca
        else if(actual_level[x][y+1] == '3')
        {
            actual_level[x][y] = '3';
            actual_level[x][y+1] = '1';
        }
        // Se na direita do jogador tiver um cubo...
        else if(actual_level[x][y+1] == '2')
        {
            // ... e na direita do cubo estiver vazio, troca
            if(actual_level[x][y+2] == '0')
            {
                actual_level[x][y] = '0';
                actual_level[x][y+1] = '1';
                actual_level[x][y+2] = '2';
            }
            // ... e na direita do cubo for o lugar certo, salva como cubo fixo e aumenta um cubo na quantidade do jogador
            else if(actual_level[x][y+2] == '3')
            {
                actual_level[x][y] = '0';
                actual_level[x][y+1] = '1';
                actual_level[x][y+2] = '#';
                *cubos_ptr += 1;
            }
        }
        break;
    case UP:
        // Se acima do jogador estiver vazio, troca
        if(actual_level[x-1][y] == '0')
        {
            actual_level[x][y] = '0';
            actual_level[x-1][y] = '1';
        }
        // Se acima do jogador for o lugar certo do cubo, troca
        else if(actual_level[x-1][y] == '3')
        {
            actual_level[x][y] = '3';
            actual_level[x-1][y] = '1';
        }
        // Se acima do jogador tiver um cubo...
        else if(actual_level[x-1][y] == '2')
        {
            // ... e acima do cubo estiver vazio, troca
            if(actual_level[x-2][y] == '0')
            {
                actual_level[x][y] = '0';
                actual_level[x-1][y] = '1';
                actual_level[x-2][y] = '2';
            }
            // ... e acima do cubo for o lugar certo, salva como cubo fixo e aumenta um cubo na quantidade do jogador
            else if(actual_level[x-2][y] == '3')
            {
                actual_level[x][y] = '0';
                actual_level[x-1][y] = '1';
                actual_level[x-2][y] = '#';
                *cubos_ptr += 1;
            }
        }
        break;
    case DOWN:
        // Se abaixo do jogador estiver vazio, troca
        if(actual_level[x+1][y] == '0')
        {
            actual_level[x][y] = '0';
            actual_level[x+1][y] = '1';
        }
        // Se abaixo do jogador for o lugar certo do cubo, troca
        else if(actual_level[x+1][y] == '3')
        {
            actual_level[x][y] = '3';
            actual_level[x+1][y] = '1';
        }
        // Se abaixo do jogador tiver um cubo...
        else if(actual_level[x+1][y] == '2')
        {
            // ... e abaixo do cubo estiver vazio, troca
            if(actual_level[x+2][y] == '0')
            {
                actual_level[x][y] = '0';
                actual_level[x+1][y] = '1';
                actual_level[x+2][y] = '2';
            }
            // ... e abaixo do cubo for o lugar certo, salva como cubo fixo e aumenta um cubo na quantidade do jogador
            if(actual_level[x+2][y] == '3')
            {
                actual_level[x][y] = '0';
                actual_level[x+1][y] = '1';
                actual_level[x+2][y] = '#';
                *cubos_ptr += 1;
            }
        }
        break;
    }
}

void read_level(int nivel_number, char actual_level[N_LINHA+1][N_COL+1])
{
    FILE *ptr; // ponteiro do arquivo com os dados do nivel
    int i; // variavel de controle da funcao 'for'
    char namen[] = "nivelX.txt"; // nome do arquivo com os dados do nivel
    char string_nnumber = nivel_number+48; // numero do nivel

    // Troca o caractere 'X' da string namen pelo nivel
    namen[5] = string_nnumber;

    // Abre o arquivo em modo de leitura, se der erro ...
    ptr = fopen(namen, "r");
    if(!ptr)
        cant_start();
    // caso contrario le os dados do nivel
    else
    {
        for(i = 0; i < N_LINHA; i++)
            fgets(actual_level[i], N_COL+1, ptr);
        fclose(ptr);
    }
}

void random_cubes(char nivel[N_LINHA+1][N_COL+1], int cubos_total)
{
    int i; // variaveis de controle do comando 'for'
    int x, y; // posicao da matriz onde sera a posicao randomica

    // Gera semente randomica
    srand(time(NULL));

    // Executa o loop até achar todas as posicoes necessarias
    for(i = 0; i < cubos_total; i++)
    {
        // Enquanto nao achar uma posicao em que ela mesma e os blocos ao seu redor sejam espacos vazios, reinicia
        do
        {
            y = rand() % N_COL;
            x = rand() % N_LINHA;
        }
        while(!(nivel[x][y] == '0' && nivel[x+1][y] == '0' && nivel[x-1][y] == '0' && nivel[x][y+1] == '0' && nivel[x][y-1] == '0'));
        nivel[x][y] = '3'; // Quando encontrar insere o caractere '3' para as funcoes de movimento e impressao reconhecerem
    }
}

int count_cubes(char nivel[N_LINHA+1][N_COL+1])
{
    int i, j;
    int cubes = 0;

    for(i = 0; i < N_LINHA; i++)
    {
        for(j = 0; j < N_COL; j++)
        {
            // Se ao ler a matriz encontrar um cubo livre ou um fixo, incrementa um
            if(nivel[i][j] == '2' || nivel[i][j] == '#')
                cubes++;
        }
    }

    return cubes;
}

bool cube_in_corner(char actual_level[N_LINHA+1][N_COL+1])
{
    int i, j;
    int cubes = 0;

    for(i = 0; i < N_LINHA; i++)
    {
        for(j = 0; j < N_COL; j++)
        {
            if(actual_level[i][j] == '2')
            {
                // Se encontrar um cubo na beira de uma das extremidades do nivel incrementa um
                if(i+1 == N_LINHA-1 || i-1 == 0 || j+1 == N_COL-2 || j-1 == 0)
                    cubes++;
            }
        }
    }

    // Se nao for 0 retorna true para o jogador ter a chance de reiniciar o jogo
    if(cubes != 0)
        return true;
    else
        return false;
}
