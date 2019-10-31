// #ifndef DAMA_H
// #define DAMA_H

#include <iostream>
#include <string>
#include "Peca.h"
using namespace std;

/*-----------------------------------------------------------------------------*/

class Dama : public Peca
{
  private:
    // bool morte; //Verifica o estado de vida da Dama
    // char cor;

  public:
    Dama(char c); //Construtor da classe Dama
    ~Dama(); //Destrutor da classe Dama

    int checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino); //Verifica se o movimento é válido para o tipo de classe
    string desenha(); //Função do tipo string para usar a função de imprimir com cor, e recebe a cor do jogador para definir se a letra é minúscula ou maiúscula
};

/*-----------------------------------------------------------------------------*/

// #endif
