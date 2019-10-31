#include <iostream>
#include "Bispo.h"
#include <string>
using namespace std;

/*-----------------------------------------------------------------------------*/

Bispo::Bispo(char c) : Peca(3, c, false) {}

int Bispo::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
    int diferencaLinhas;
    int diferencaColunas;

    diferencaLinhas = linhaOrigem - linhaDestino; //Recebe valor da diferença entre linhaOrigem e linhaDestino
    diferencaColunas = colunaOrigem - colunaDestino; //Recebe valor da diferença entre colunaOrigem e colunaDestino

    if(diferencaLinhas != 0 && diferencaColunas != 0) //Verifica se a peça fica no mesmo lugar
        if(diferencaLinhas % diferencaColunas == 0) //Para verificar se o movimento é na diagonal, logo o resto entre as diferenças é zero
            return (1); //Retorno 1, movimento válido

    return (0);
}

Bispo::~Bispo(){
    morte = true; //Destrutor de Bispo muda o estado de vida para morto
}

string Bispo::desenha(){
    string retorno;

    if(cor == 'B') //cor for branca
        retorno = "   B   ";
    else
        retorno = "   b   ";

    return(retorno);
}

/*-----------------------------------------------------------------------------*/
