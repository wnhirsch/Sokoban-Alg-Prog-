#include "aux-def.h"

// Eu tentei utilizar a função de esconder o cursor da propria 'conio2.h' porém não obtive exito
// então utilizei essa que encontrei no site Stack Overflow que só depende da 'windows.h'
void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

bool verify_files()
{
    FILE *test_score, *test_level1, *test_level2, *test_level3;
    bool score_exist, level_exist;

    // Verifica a existencia do arquivo "highscore.bin" caso contrario cria
    test_score = fopen("highscore.bin", "rb");
    if(!test_score)
    {
        test_score = fopen("highscore.bin", "wb");
        if(!test_score)
            score_exist = false;
        else
        {
            fclose(test_score);
            score_exist = true;
        }
    }
    else
    {
        fclose(test_score);
        score_exist = true;
    }

    // Tenta abrir os 3 arquivos de niveis para comprovar a existencia deles no diretorio
    test_level1 = fopen("nivel1.txt", "r");
    test_level2 = fopen("nivel2.txt", "r");
    test_level3 = fopen("nivel3.txt", "r");
    if(test_level1 && test_level2 && test_level3)
    {
        fclose(test_level1);
        fclose(test_level2);
        fclose(test_level3);
        level_exist = true;
    }
    else
        level_exist = false;

    // Se todos existirem retorna true, caso contrario retorna false e consequentemente encerra o programa
    if(score_exist && level_exist)
        return true;
    else
        return false;
}

// Exibe mensagem de erro nos arquivos e encerra
void cant_start()
{
    int i;

    clrscr();

    textbackground(RED);
    textcolor(WHITE);
    for(i = 0; i < 33; i++)
    {
        cputsxy(i+25, 6, "=");
        cputsxy(i+25, 7, "=");
        cputsxy(i+25, 10, "=");
        cputsxy(i+25, 11, "=");
    }

    cputsxy(25, 8, "|| Houve algum erro na leitura ||");
    cputsxy(25, 9, "||   dos arquivos principais.  ||");

    textbackground(BLACK);
    textcolor(YELLOW);
    cputsxy(19, 15, "Verifique se o local onde o executavel esta");
    cputsxy(15, 16, "inserido tem permissao de leitura e escrita de dados");
    cputsxy(19, 17, "ou se ha niveis disponiveis para a leitura!");

    textcolor(WHITE);
    printf("\n\n\n");

    while(!kbhit()){}

    exit(0);
}
