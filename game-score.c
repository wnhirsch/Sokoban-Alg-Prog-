#include "game-score.h"
#include "intro-menu-printf.h"
#include "start-game.h"

void salva_score(score_st actual_player)
{
    FILE *salvou;
    score_st temp_buffer;
    bool achou = false, ja_existe = false;
    int position_file;

    salvou = fopen("highscore.bin", "rb+");
    if(!salvou)
        cant_start();
    else
    {
        // Procura se ja existe algum escore salvo desse jogador
        while(!feof(salvou) && !ja_existe)
        {
            if(fread(&temp_buffer, sizeof(score_st), 1, salvou) == 1)
            {
                position_file = ftell(salvou) - sizeof(score_st);
                if(strcmp(temp_buffer.player_name, actual_player.player_name) == 0)
                    ja_existe = true;
            }
        }
        // Se existir ele verifica se é maior e atualiza o valor caso não seja
        if(ja_existe)
        {
            if(temp_buffer.player_score <= actual_player.player_score)
            {
                fseek(salvou, position_file, SEEK_SET);
                fwrite(&actual_player, sizeof(score_st), 1, salvou);
            }
        }
        // Caso contrario...
        else
        {
            rewind(salvou);
            // Ele procura algum escore que seja menor ou igual ao dele
            while(!feof(salvou) && !achou)
            {
                if(fread(&temp_buffer, sizeof(score_st), 1, salvou) == 1)
                {
                    position_file = ftell(salvou) - sizeof(score_st);
                    if(temp_buffer.player_score <= actual_player.player_score)
                        achou = true;
                }
            }
            // Se achou o escore desse jogador é salvo nessa posição e os menores são arrastados para trás
            if(achou)
            {
                fseek(salvou, position_file, SEEK_SET);
                while(!feof(salvou))
                {
                    fwrite(&actual_player, sizeof(score_st), 1, salvou);
                    actual_player = temp_buffer;
                    position_file += sizeof(score_st);
                    fseek(salvou, position_file, SEEK_SET);
                    if(fread(&temp_buffer, sizeof(score_st), 1, salvou) == 1)
                        fseek(salvou, position_file, SEEK_SET);
                }
                fwrite(&actual_player, sizeof(score_st), 1, salvou);
            }
            // Se não achou nenhum menor quer dizer que ele é o menor então simplesmente escreve no arquivo
            else
                fwrite(&actual_player, sizeof(score_st), 1, salvou);
        }
        fclose(salvou);
    }
}

void le_score()
{
    FILE *leu_escore;
    score_st buffer;
    int i, j;

    leu_escore = fopen("highscore.bin", "rb");
    if(!leu_escore)
        cant_start();
    else
    {
        // Busca e imprime os escores em duas colunas
        for(j = 1; j <= 2; j++)
        {
            for(i = 0; i < 5; i++)
            {
                // Se ainda tiver um escore dos 10 para ler imprime ele
                if(fread(&buffer, sizeof(score_st), 1, leu_escore) == 1)
                {
                    // Representa a divisão em duas colunas
                    if(j == 1)
                    {
                        gotoxy(8, 13+i*2);
                        printf("%02d", i+1);
                        gotoxy(11, 13+i*2);
                        printf("%s", buffer.player_name);
                        gotoxy(32, 13+i*2);
                        printf("%.2f", buffer.player_score);
                    }
                    // Representa a divisão em duas colunas
                    else
                    {
                        gotoxy(44, 13+i*2);
                        printf("%02d", i+6);
                        gotoxy(48, 13+i*2);
                        printf("%s", buffer.player_name);
                        gotoxy(69, 13+i*2);
                        printf("%.2f", buffer.player_score);
                    }
                }
                // Caso contrario imprime um score NULO
                if(feof(leu_escore))
                {
                    // Representa a divisão em duas colunas
                    if(j == 1)
                    {
                        gotoxy(8, 13+i*2);
                        printf("%02d", i+1);
                        cputsxy(11, 13+i*2, "--- NULO ---");
                        cputsxy(32, 13+i*2, "00.00");
                    }
                    // Representa a divisão em duas colunas
                    else
                    {
                        gotoxy(44, 13+i*2);
                        printf("%02d", i+6);
                        cputsxy(48, 13+i*2, "--- NULO ---");
                        cputsxy(69, 13+i*2, "00.00");
                    }
                }
            }
        }
        fclose(leu_escore);
    }
}

void printa_score()
{
    clock_t start, diference; // representa o inicio e o atual estado da cronometragem (detalhes abaixo \/)
    char keypress;

    clrscr();
    // imprime varios "=" formando o contorno horizontal
    printa_sinaldeigual(1, 1, TAM_HORIZ);
    printa_sinaldeigual(1, 9, TAM_HORIZ);
    printa_sinaldeigual(1, 24, TAM_HORIZ);

    // imprime varios "|" formando o contorno vertical
    printa_sinaldeou(1, 2, 22);
    printa_sinaldeou(TAM_HORIZ, 2, 22);

    start = clock(); // insere atual estado de tempo para a variavel 'start'
    printa_score_letras();
    le_score();
    do{
        while(!kbhit())
        {
            // Gera cores randomicas a cada segundo para personalizar o Escore
            diference = clock();
            if((diference - start) / CLOCKS_PER_SEC == 1)
            {
                start = clock();
                printa_score_letras();
            }
        }
        keypress = getch();
        keypress_audio(keypress);
    }while(keypress != ENTER);

    clrscr();
}

void printa_score_letras()
{
    srand(time(NULL)); // gera semente randomica

    int cor_letra = rand() % 13 + 1; // randomiza todas as cores disponiveis na biblioteca 'conio2.h' (exceto 'BLACK' e 'WHITE')
    textcolor(cor_letra);
    cputsxy(7, 11, "POS");
    cputsxy(43, 11, "POS");
    cputsxy(11, 11, "NOME");
    cputsxy(48, 11, "NOME");
    cputsxy(32, 11, "SCORE");
    cputsxy(69, 11, "SCORE");
    cputsxy(28, 23, "Aperte ENTER para voltar.");

    // Imprime a palavra personalizada ESCORE
    letra_E_grd(23,3);
    letra_S_grd(29,3);
    letra_C_grd(35,3);
    letra_O_grd(41,3);
    letra_R_grd(47,3);
    letra_E_grd(53,3);

    textcolor(WHITE);
}

float busca_score(player_st* actual_player)
{
    FILE *buscou;
    score_st temp_buffer;
    bool achou = false;

    buscou = fopen("highscore.bin", "rb");
    if(!buscou)
        cant_start();
    else
    {
        // Busca o escore do jogador atual nos dados
        while(!feof(buscou) && !achou)
        {
            if(fread(&temp_buffer, sizeof(score_st), 1, buscou) == 1)
            {
                if(strcmp(temp_buffer.player_name, actual_player->player_name) == 0)
                    achou = true;
            }
        }
        fclose(buscou);
    }
    // Caso tenha retorna ele para mostra-lo ao usuario como parametro
    if(achou)
        return temp_buffer.player_score;
    // Caso contrario retorna 0
    else
        return 0;
}
