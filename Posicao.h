#include <iostream>
// #include "Peao.h"
// #include "Dama.h"
// #include "Rei.h"
// #include "Bispo.h"
// #include "Torre.h"
// #include "Cavalo.h"
#include "Peca.h"




/*-----------------------------------------------------------------------------*/

class Posicao{

private:
    // char cor; //Guarda a cor da peça
    // Peao *p; //Define a peça Peão
    // Torre *t; //Define a peça Torre
    // Bispo *b; //Define a peça Bispo
    // Dama *d; //Define a peça Rainha
    // Cavalo *c; //Define a peça Cavalo
    // Rei *r; //Define a peça Rei
    Peca *peca;

  public:

    Posicao(); //Construtor da classe Posicao
   // ~Posicao(); //Destrutor da classe Posicao

    int inserirPeca(Peca *p); //(*)Testando a inserção de cada peça no tabuleiro
    int verificaPeca(); //Verifica a existência da peça no tabuleiro
    void tirarPeca();//Tira peça da posição (deixa como vazia)

    Peca *retornaP();
};
