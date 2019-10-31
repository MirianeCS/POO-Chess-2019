#include <iostream>
#include <string>
#include "Peca.h"
using namespace std;

/*-----------------------------------------------------------------------------*/

class Peao : public Peca
{
  private:
    bool primeiroPasso; //Verifica se é a primeiro movimento do Peão
    // bool morte; //Verifica o estado de vida do Peão
    // char cor;


  public:
    Peao(char c); //Construtor da classe Peão
    //~Peao(); //Destrutor da classe Peão

    int checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino); //Verifica se o movimento é válido para o tipo de classe
    string desenha(); //Função do tipo string para usar a função de imprimir com cor, e recebe a cor do jogador para definir se a letra é minúscula ou maiúscula
};
