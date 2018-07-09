/// FUNÇÕES DO PROGRAMA "intro-menu"
/// OBJETIVO: INTRODUZIR O PROGRAMA COM OS MODOS DE JOGO, INTRUCOES E ESCORES
#include "intro-menu.h" // chama a biblioteca de prototipos do programa "intro-menu"
#include "intro-menu-printf.h" // chama a biblioteca de prototipos do programa "intro-menu-printf"
#include "quit-game.h"
#include "single-game.h"
#include "game-score.h"
#include "start-game.h"
#include "start-game-printf.h"
#include "aux-def.h"

void intro_menu()
{
    char keypress; // representa a tecla pressionada pelo usuario
    int option = 1; // representa a opcao do menu escolhida (a opcao 1 e' predefinida)
    clock_t start, diference; // representa o inicio e o atual estado da cronometragem (detalhes abaixo \/)

    start = clock(); // insere atual estado de tempo para a variavel 'start'
    printa_intro(); // imprime o menu introdutorio
    do{
        while(!kbhit())                                   // ==
        {                                                 //   |
            diference = clock();                          //   | > Enquanto o usuario nao pressionar uma tecla a variavel 'diference' sera atualizada
            if((diference - start) / CLOCKS_PER_SEC == 1) //   | com o tempo atual do PC. Caso a diferenca entre essa variavel e a 'start'
            {                                             //   | em segundos seja igual a '1', a variavel 'start' sera atualizada com o tempo atual do PC
                start = clock();                          //   | e sera chamada a funcao 'printa_letras' para reimprimir o titulo na tela. O objetivo disso
                printa_title_letras();                    //   | e' para que a cada segundo, as cores do titulo sejam atualizadas de forma randomica,
            }                                             //   | reforcando o real significado do jogo.
        }                                                 // ==
        keypress = getch(); // recebe a tecla pressionada pelo usuario
        keypress_audio(keypress);

        // Leva o usuario para a funcao certa desejada dependendo do que ele pressionou
        switch (keypress)
        {
            // Se foi a tecla TAB ele o mudou de opcao
            case TAB:
                if(option != 4)
                    option++;
                else
                    option = 1;
                break;
            // Se foi a tecla ENTER ele escolheu alguma opcao
            case ENTER:
                // Opcao da qual sera analizada aqui
                switch(option)
                {
                    case 1:
                        clrscr();
                        single_player();
                        clrscr();
                        start = clock();
                        printa_intro();
                        break;
                    case 2:
                        printa_score();
                        start = clock();
                        printa_intro();
                        break;
                    case 3:
                        instructions_game();
                        start = clock();
                        printa_intro();
                        break;
                    case 4:
                        quit_game();
                        break;
                }
                break;
        }
        printa_options(option); // imprime as opcoes do menu dada uma opcao selecionada
    }while(1);
}

void instructions_game()
{
    char keypress;
    int cor_letra;
    clock_t start, diference;

    clrscr();

    // imprime varios "=" formando o contorno horizontal
    printa_sinaldeigual(1, 1, TAM_HORIZ);
    printa_sinaldeigual(1, 24, TAM_HORIZ);

    // imprime varios "|" formando o contorno vertical
    printa_sinaldeou(1, 2, 22);
    printa_sinaldeou(TAM_HORIZ, 2, 22);

    // Imprime algumas informações sobre o jogo
    cputsxy(8, 3, "O jogo CRAZY RANDOM SOKOBAN consiste no jogador arrastar todos os");
    cputsxy(3, 4, "cubos de cada nivel para posições ocultas geradas randomicamente.");
    cputsxy(8, 5, "A referencia grafica de cada item e':");

    // Imprime os itens graficos que o jogo possui
    printa_bloco(10,7);
    printa_chao(25,7);
    printa_player(40,7);
    printa_cubo(55,7);
    printa_cubo_certo(70,7);
    textbackground(WHITE);
    textcolor(BLACK);
    cputsxy(8, 10, "Parede");
    cputsxy(20, 10, "Espaco Vazio");
    cputsxy(38, 10, "Jogador");
    cputsxy(54, 10, "Cubo");
    cputsxy(66, 10, "Cubo(CERTO)");
    textbackground(BLACK);
    textcolor(WHITE);

    // Imprime algumas informações sobre o jogo
    cputsxy(8, 12, "Para mover o jogador e' usado as teclas direcionais UP, DOWN, RIGHT");
    cputsxy(3, 13, "e LEFT.");

    // Imprime algumas informações sobre o jogo
    cputsxy(8, 15, "Para acessar grande parte dos menus e' usada a tecla TAB, alternando");
    cputsxy(3, 16, "entre as opcoes, e a tecla ENTER, acessando a opcao em realce.");

    // Imprime algumas informações sobre o jogo
    cputsxy(8, 18, "O jogador deve atravessar todos os 3 niveis para completar o jogo");
    cputsxy(3, 19, " antes de terminar o tempo referente ao seu nivel. E´dado 20s para cada cubo");
    cputsxy(3, 20, " dentro do nivel respectivo.");

    // Enquanto o jogador não pressionar a tecla enter...
    start = clock();
    cor_letra = rand() % 13 + 1;
    textcolor(cor_letra);
    // ... essas duas sentenças serão reimpressas com alguma cor randomica
    cputsxy(15, 3, "CRAZY RANDOM SOKOBAN");
    cputsxy(28, 23, "Aperte ENTER para voltar.");
    do{
        while(!kbhit())
        {
            diference = clock();
            if((diference - start) / CLOCKS_PER_SEC == 1)
            {
                start = clock();
                cor_letra = rand() % 13 + 1;
                textcolor(cor_letra);
                cputsxy(15, 3, "CRAZY RANDOM SOKOBAN");
                cputsxy(28, 23, "Aperte ENTER para voltar.");
            }
        }
        keypress = getch();
        keypress_audio(keypress);
    }while(keypress != ENTER);

    clrscr();
}
