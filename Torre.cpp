#include <iostream>
#include "Torre.h"
#include <string>
using namespace std;

/*-----------------------------------------------------------------------------*/

Torre::Torre(char c) : Peca(1, c, false) {}

int Torre::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
    if(linhaOrigem == linhaDestino || colunaOrigem == colunaDestino) //Verifica se esta andando na horizontal ou vertical
        return(1); //Retorna 1 se o movimento foir válido
    else
        return(0);
}

Torre::~Torre()
{
    morte = false; //Destrutor define o estado de vida como morto
}

string Torre::desenha(){
    string retorno;

    if(cor == 'B') //cor for branca
        retorno = "   T   ";
    else
        retorno = "   t   ";

    return(retorno);
}

/*-----------------------------------------------------------------------------*/
