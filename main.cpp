#include <iostream>
#include "Jogo.h"

void imprimirInstrucoes()
{
  std::cout << '\n';
  std::cout << "                            BEM VINDO AO JOGO                           " << '\n';
  std::cout << "  Xadrez e um jogo de estrategia tatica onde dois jogadores movem 32 pecas," << '\n';
  std::cout << "sendo 16 peças para cada um deles, em um tabuleiro de 64 casas." << '\n';
  std::cout << "  As casas sao dividas de forma igual e alternadas em cores claras e escuras." << '\n';
  std::cout << "  O primeiro jogador manipulara as peças com letra maiuscula, enquando o" << '\n';
  std::cout << "segundo jogador manipula as pecas de letra minuscula." << '\n';
  std::cout << "  As jogadas devem ser feitas de modo que o jogador escolhera a peca que" << '\n';
  std::cout << "quer mover definindo primeiro sua posicao de origem (linha e coluna)" << '\n';
  std::cout << "e a posicao de destino (linha e coluna)." << '\n';
  std::cout << "                              Bom jogo! :)                              " << '\n';
  std::cout << '\n';
}

int main(){

    imprimirInstrucoes();

    Jogo xadrez;
    int flag = 1;

    xadrez.inicializar();

    while(1){
        if(flag){
            std::cout << "JOGADOR 1 FACA SUA JOGADA" << '\n' << "('linha coluna' origem e 'linha coluna' destino)" << '\n';
            xadrez.jogada();
            flag = 0;
        }
        else{
            std::cout << "JOGADOR 2 FACA SUA JOGADA" << '\n' << "('linha coluna' origem e 'linha coluna' destino)"<< '\n';
            xadrez.jogada();
            flag = 1;
        }
    }

    return 0;
}
