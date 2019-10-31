#include <iostream>
#include "Dama.h"
#include <string>
using namespace std;


/*-----------------------------------------------------------------------------*/

Dama::Dama(char c) : Peca(4, c, false) {}

int Dama::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
    int diferencaLinhas;
    int diferencaColunas;

    diferencaLinhas = linhaOrigem - linhaDestino; //Define a diferença entre linhaOrigem e linhaDestino
    diferencaColunas = colunaOrigem - colunaDestino; //Define a diferença entre colunaOrigem colunaDestino


    if(diferencaLinhas != 0 && diferencaColunas != 0){  //Verifica se a peça não esta ficando no mesmo lugar
        if(diferencaLinhas % diferencaColunas == 0) //Para verificar se o movimento é na diagonal, logo o resto entre as diferenças é zero (Bispo)
            return (1); //Retorna 1 quando o movimento é válido
    }
    else{
        if(linhaOrigem == linhaDestino || colunaOrigem == colunaDestino) //Verificando se o movimento é horinzoltal (Torre)
            return(1); //Retorna 1 se o movimento é válido
    }

    return(0);
}

Dama::~Dama(){
    morte = true; //Destrutor muda o estado de vida da Rainha
}

string Dama::desenha(){
    string retorno;

    if(cor == 'B') //cor for branca
        retorno = "   D   ";
    else
        retorno = "   d   ";

    return(retorno);
}

/*-----------------------------------------------------------------------------*/
