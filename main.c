/**
  *
  * UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
  *
  * CURSO: CIENCIA DA COMPUTACAO
  * DICIPLINA: INF01202 - ALGORITMOS E PROGRAMACAO
  * SEMESTRE: 2017/1
  *
  * NOME DO PROGRAMA: CRAZY RANDOM SOKOBAN
  * OBJETIVO: EXECUTAR UMA VARIACAO DO JOGO "SOKOBAN"
  * NOME(S) DO PROGRAMADOR(ES): AUGUSTO DALCIN PEITER, LEONARDO HOLTZ DE OLIVEIRA, WELLINGTON NASCENTE HIRSCH
  * DATA DE CRIACAO: JUNHO/2017
  *
  */

#include "aux-def.h"
#include "intro-menu.h"
#include <windows.h>

int main()
{
    bool can_start = verify_files(); // representa se todos os arquivos necessários estão no mesmo diretório do programa
    if(can_start) // caso estejam inicializa o jogo normalmente
    {
        hidecursor(); // retira o cursor
        intro_menu(); // inicializa o Menu Principal
    }
    else
        cant_start(); // caso contrário exibe mensagem de erro e encerra
    return 0;
}
