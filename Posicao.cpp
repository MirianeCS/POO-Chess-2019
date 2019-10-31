#include <iostream>
#include "Posicao.h"
using namespace std;

/*-----------------------------------------------------------------------------*/
Posicao::Posicao(){//inicializa os ponteiros com NULL
    // p = NULL; //Separa um por linhas pois são de classes diferentes
    // t = NULL;
    // b = NULL;
    // d = NULL;
    // c = NULL;
    // r = NULL;
    peca = NULL;
}

/*-----------------------------------------------------------------------------*/
int Posicao::inserirPeca(Peca *p){//(*)
    if(!peca)//(*)verifica se a posição onde esta inserindo está vazia, insere a peça e retorna 1
        peca = p;//(*)
    else//Se ja possuir peça retorna 0
        return 0;
    return 1;
}

/*-----------------------------------------------------------------------------*/

int Posicao::verificaPeca(){
    if(peca)//(*)verifica se possui um endereço valido (diferente de NULL)
        return 1;
    else
        return 0;
}

/*-----------------------------------------------------------------------------*/

Peca *Posicao::retornaP()
{
  if(peca)
    return(peca);
  return(NULL);
}

/*-----------------------------------------------------------------------------*/

void Posicao::tirarPeca(){
    // p = NULL;
    // t = NULL;
    // b = NULL;
    // d = NULL;
    // c = NULL;
    // r = NULL;
    peca = NULL;
}
