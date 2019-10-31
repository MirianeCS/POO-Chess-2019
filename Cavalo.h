// #ifndef CAVALO_H
// #define BISPO_H

#include <iostream>
#include <string>
#include "Peca.h"
using namespace std;

/*-----------------------------------------------------------------------------*/

class Cavalo : public Peca
{
  private:
    // char cor;
    // bool morte; //Verifica o estado de vida da Cavalo

  public:
    Cavalo(char c); //Construtor da classe Cavalo
    ~Cavalo(); //Destrutor da classe Cavalo

    int checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino); //Verifica se o movimento é válido para o tipo de classe
    string desenha(); //Função do tipo string para usar a função de imprimir com cor, e recebe a cor do jogador para definir se a letra é minúscula ou maiúscula
};

/*-----------------------------------------------------------------------------*/

// #endif
