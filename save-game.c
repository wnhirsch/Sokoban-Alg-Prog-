#include "save-game.h"

void write_save_game(player_st* actual_player, char actual_level[N_LINHA+1][N_COL+1])
{
    FILE *salvou;
    int i; // variavel de controle da funcao 'for'
    int num_saves;
    char save_name[30], num_save_name[5];

    // Cria uma string baseado em "nomedojogador000.txt"
    num_saves = verifica_savegame(actual_player->player_name);
    strcpy(save_name, actual_player->player_name);
    itoa(num_saves, num_save_name, 10);
    strcat(save_name, num_save_name);
    strcat(save_name, ".txt");

    // Abre o arquivo em modo de leitura, se der erro ...
    salvou = fopen(save_name, "w");
    if(!salvou)
        cant_start();
    // caso contrario le os dados do nivel
    else
    {
        // Salva os dados
        for(i = 0; i < N_LINHA; i++)
            fprintf(salvou, "%s", actual_level[i]);
        fprintf(salvou, "\n%s ", actual_player->player_name);
        fprintf(salvou, "%d  ", actual_player->current_level);
        fprintf(salvou, "%d  ", actual_player->cubes_ok);
        fprintf(salvou, "%d  ", actual_player->num_moves_actual);
        fprintf(salvou, "%u  ", actual_player->game_time_actual);
        fprintf(salvou, "%d  ", actual_player->levels_ok);
        fprintf(salvou, "%d  ", actual_player->num_moves_total);
        fprintf(salvou, "%u  ", actual_player->game_time_total);
        fprintf(salvou, "%f", actual_player->score_total);
        fclose(salvou);
    }
}

void write_pause_game(player_st* actual_player, char actual_level[N_LINHA+1][N_COL+1])
{
    FILE *pausou;
    int i; // variavel de controle da funcao 'for'
    pause_st buffer;

    // Abre o arquivo em modo de leitura, se der erro ...
    pausou = fopen("pausa.bin", "wb");
    if(!pausou)
        cant_start();
    // caso contrario le os dados do nivel
    else
    {
        // Salva os dados
        buffer.actual_player = *actual_player;
        for(i = 0; i < N_LINHA; i++)
            strcpy(buffer.actual_level[i], actual_level[i]);
        fwrite(&buffer, sizeof(pause_st), 1, pausou);
        fclose(pausou);
    }
}

void read_save_game(player_st* actual_player, char actual_level[N_LINHA+1][N_COL+1], int num_save)
{
    FILE *leu_save;
    int i; // variavel de controle da funcao 'for'
    char save_name[30], num_save_name[5];

    // Cria uma string baseado em "nomedojogador000.txt"
    strcpy(save_name, actual_player->player_name);
    itoa(num_save, num_save_name, 10);
    strcat(save_name, num_save_name);
    strcat(save_name, ".txt");

    // Abre o arquivo em modo de leitura, se der erro ...
    leu_save = fopen(save_name, "r");
    if(!leu_save)
        cant_start();
    // caso contrario le os dados do nivel
    else
    {
        // Le os dados
        for(i = 0; i < N_LINHA; i++)
            fgets(actual_level[i], N_COL+1, leu_save);
        fscanf(leu_save, "\n%s ", actual_player->player_name);
        fscanf(leu_save, "%d  ", &actual_player->current_level);
        fscanf(leu_save, "%d  ", &actual_player->cubes_ok);
        fscanf(leu_save, "%d  ", &actual_player->num_moves_actual);
        fscanf(leu_save, "%u  ", &actual_player->game_time_actual);
        fscanf(leu_save, "%d  ", &actual_player->levels_ok);
        fscanf(leu_save, "%d  ", &actual_player->num_moves_total);
        fscanf(leu_save, "%u  ", &actual_player->game_time_total);
        fscanf(leu_save, "%f", &actual_player->score_total);
        fclose(leu_save);
    }
}

void read_pause_game(player_st* actual_player, char actual_level[N_LINHA+1][N_COL+1])
{
    FILE *leu_pause;
    int i; // variavel de controle da funcao 'for'
    pause_st buffer;

    // Abre o arquivo em modo de leitura, se der erro ...
    leu_pause = fopen("pausa.bin", "rb");
    if(!leu_pause)
        cant_start();
    // caso contrario le os dados do nivel
    else
    {
        // Le os dados
        fread(&buffer, sizeof(pause_st), 1, leu_pause);
        *actual_player = buffer.actual_player;
        for(i = 0; i < N_LINHA; i++)
            strcpy(actual_level[i], buffer.actual_level[i]);
        fclose(leu_pause);
        remove("pausa.bin");
    }
}

int verifica_savegame(char player_name[])
{
    FILE *ja_salvou;
    int num_saves = 0;
    char save_name[25], num_save_name[5];

    do
    {
        // Cria uma string baseado em "nomedojogador000.txt"
        save_name[0] = '\0';
        num_save_name[0] = '\0';
        // onde o "000" vai crescendo até dar erro
        num_saves++;
        strcpy(save_name, player_name);
        itoa(num_saves, num_save_name, 10);
        strcat(save_name, num_save_name);
        strcat(save_name, ".txt");
        ja_salvou = fopen(save_name, "r");
    }
    while(ja_salvou);

    // E com isso retorna quantas vezes não deu erro, que é o mesmo que a quantidade de saves
    return num_saves;
}

bool verifica_pause(char player_name[])
{
    FILE *tem_pause;
    pause_st buffer;
    tem_pause = fopen("pausa.bin", "rb");
    if(!tem_pause)
        return false;
    else
    {
        // Verifica se o jogo salvo é do jogador atual
        fread(&buffer, sizeof(pause_st), 1, tem_pause);
        if(strcmp(player_name, buffer.actual_player.player_name) == 0)
            return true;
        else
            return false;
    }
}

void keypress_audio(int keypress, bool is_extension)
{
    // Cada BEEP é um som pra uma tecla digitada
    switch(keypress)
    {
        case ESC:
            Beep(120,100);
            break;
        case ENTER:
            Beep(200,200);
            break;
        case TAB:
            Beep(370,250);
            break;
        case 'n':
        case 'N':
            Beep(350, 250);
            break;
        case 's':
        case 'S':
            Beep(400,350);
            break;
        case 'q':
        case 'Q':
            Beep(430,100);
            Beep(300,100);
            break;
        case 'P':
        case 'p':
            Beep(262,100);
            Beep(310,100);
            break;
        case 'E':
        case 'e':
            Beep(175,100);
            Beep(196, 100);
            break;
    }
}
