/// FUNÇÕES DO PROGRAMA "menu-game-printf"
/// OBJETIVO: IMPRIMIR TODA A BASE DE UM JOGO, COMO CONTORNO, MENU SUPERIOR E INFORMACOES DA PARTIDA
#include "menu-game-printf.h" // chama a biblioteca de prototipos do programa "menu-game-printf"

void printa_menu(int selec_option)
{
    // chama a funcao para imprimir o contorno do jogo
    printa_contorno();

    // A variavel 'op' representa a opcao do menu que esta selecionada.
    // Dependendo da opcao o menu e impresso de forma diferente.
    switch(selec_option)
    {
        // A opcao "NOVO JOGO" ficara destacada perante as outras
        case 1:
            printa_N(true);
            printa_S(false);
            printa_P(false);
            printa_E(false);
            printa_Q(false);
            break;
        // A opcao "SALVAR" ficara destacada perante as outras
        case 2:
            printa_N(false);
            printa_S(true);
            printa_P(false);
            printa_E(false);
            printa_Q(false);
            break;
        // A opcao "PAUSAR" ficara destacada perante as outras
        case 3:
            printa_N(false);
            printa_S(false);
            printa_P(true);
            printa_E(false);
            printa_Q(false);
            break;
        // A opcao "ESCORE" ficara destacada perante as outras
        case 4:
            printa_N(false);
            printa_S(false);
            printa_P(false);
            printa_E(true);
            printa_Q(false);
            break;
        // A opcao "QUIT" ficara destacada perante as outras
        case 5:
            printa_N(false);
            printa_S(false);
            printa_P(false);
            printa_E(false);
            printa_Q(true);
            break;
        // Nenhuma cor ficara destacada
        default:
            printa_N(false);
            printa_S(false);
            printa_P(false);
            printa_E(false);
            printa_Q(false);
            break;
    }
}

void printa_N(bool tem_cor)
{
    // Se a opcao estiver selecionada muda a cor padrao
    if(tem_cor)
    {
        textbackground(WHITE);
        textcolor(BLACK);
    }
    // Caso contrario mantem
    else
    {
        textbackground(BLACK);
        textcolor(WHITE);
    }

    // Imprime a opcao
    cputsxy(1, 1, "=================");
    cputsxy(1, 2, "| [N] NOVO JOGO |");
    cputsxy(1, 3, "=================");

}

void printa_S(bool tem_cor)
{
    // Se a opcao estiver selecionada muda a cor padrao
    if(tem_cor)
    {
        textbackground(WHITE);
        textcolor(BLACK);
    }
    // Caso contrario mantem
    else
    {
        textbackground(BLACK);
        textcolor(WHITE);
    }

    // Imprime a opcao
    cputsxy(18, 1, "==============");
    cputsxy(18, 2, "| [S] SALVAR |");
    cputsxy(18, 3, "==============");

}

void printa_P(bool tem_cor)
{
    // Se a opcao estiver selecionada muda a cor padrao
    if(tem_cor)
    {
        textbackground(WHITE);
        textcolor(BLACK);
    }
    // Caso contrario mantem
    else
    {
        textbackground(BLACK);
        textcolor(WHITE);
    }

    // Imprime a opcao
    cputsxy(32, 1, "==============");
    cputsxy(32, 2, "| [P] PAUSAR |");
    cputsxy(32, 3, "==============");

}

void printa_E(bool tem_cor)
{
    // Se a opcao estiver selecionada muda a cor padrao
    if(tem_cor)
    {
        textbackground(WHITE);
        textcolor(BLACK);
    }
    // Caso contrario mantem
    else
    {
        textbackground(BLACK);
        textcolor(WHITE);
    }

    // Imprime a opcao
    cputsxy(46, 1, "==============");
    cputsxy(46, 2, "| [E] ESCORE |");
    cputsxy(46, 3, "==============");

}

void printa_Q(bool tem_cor)
{
    // Se a opcao estiver selecionada muda a cor padrao
    if(tem_cor)
    {
        textbackground(WHITE);
        textcolor(BLACK);
    }
    // Caso contrario mantem
    else
    {
        textbackground(BLACK);
        textcolor(WHITE);
    }

    // Imprime a opcao
    cputsxy(60, 1, "============");
    cputsxy(60, 2, "| [Q] QUIT |");
    cputsxy(60, 3, "============");

}

void printa_contorno()
{
    int i; // variavel de controle da funcao 'for'

    // define cor padrao
    textbackground(BLACK);
    textcolor(WHITE);

    // imprime um '|' nos contornos verticais
    for(i = 1; i <= 20; i++)
    {
        cputsxy(1, i+3, "|");
        cputsxy(50, i+3, "|");
        cputsxy(71, i+3, "|");
    }

    // imprime um '+' nos contornos horizontais
    for(i = 1; i <= 71; i++)
        cputsxy(i, 24, "=");
}
