#include <iostream>
#include <string>
#include "Peca.h"
using namespace std;

/*-----------------------------------------------------------------------------*/

class Rei : public Peca
{
  private:
    // bool morte; //Verifica o estado de vida do Rei
    // char cor;

  public:
    Rei(char c); //Construtor da classe Rei
    ~Rei(); //Destrutor da classe Rei

    int checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino); //Verifica se o movimento é válido para o tipo de classe
    string desenha(); //Função do tipo string para usar a função de imprimir com cor, e recebe a cor do jogador para definir se a letra é minúscula ou maiúscula
};

/*-----------------------------------------------------------------------------*/
