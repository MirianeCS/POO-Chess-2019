#include <iostream>
#include "Cavalo.h"
#include <string>
using namespace std;


/*-----------------------------------------------------------------------------*/

Cavalo::Cavalo(char c) : Peca(2, c, false) {}

int Cavalo::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino)
{
    int diferencaLinhas;
    int diferencaColunas;

    diferencaLinhas = linhaOrigem - linhaDestino; //Atribui a diferença da linhaOrigem e linhaDestino
    diferencaColunas = colunaOrigem - colunaDestino; //Define a diferença entre colunaOrigem e colunaDestino

    if(diferencaLinhas < 0) //Se o valor for negativo, multiplica por (-1)
        diferencaLinhas *= (-1);
    if(diferencaColunas < 0)
        diferencaColunas *= (-1);

    if(diferencaLinhas == 1 && diferencaColunas == 2) //Verificando um movimento em L
        return(1); //Retorna 1 se o movimento for válido

    else if(diferencaLinhas == 2 && diferencaColunas == 1) //Verificando um movimento em L
        return(1); //Retorna 1 se o movimento for válido

    return(0);
}

Cavalo::~Cavalo(){
    morte = true; //Muda o estado de vida para morto
}

string Cavalo::desenha(){
    string retorno;

    if(cor == 'B') //cor for branca
        retorno = "   C   ";
    else
        retorno = "   c   ";

    return(retorno);
}
