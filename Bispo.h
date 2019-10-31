#ifndef BISPO_H
#define BISPO_H

#include <iostream>
#include <string>
using namespace std;
#include "Peca.h"

/*-----------------------------------------------------------------------------*/

class Bispo : public Peca
{
  private:
    // bool morte; //Verifica o estado de vida do Bispo
    // char cor;

  public:
    Bispo(char c); //Construtor da classe Bispo
    ~Bispo(); //Destrutor da classe Bispo

    int checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino); //Verifica se o movimento é válido para o tipo de classe
    string desenha(); //Função do tipo string para usar a função de imprimir com cor, e recebe a cor do jogador para definir se a letra é minúscula ou maiúscula
};

/*-----------------------------------------------------------------------------*/

#endif
