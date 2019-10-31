#include <iostream>
#include "Rei.h"
#include <string>
using namespace std;

/*-----------------------------------------------------------------------------*/

Rei::Rei(char c) : Peca(5, c, false) {}

int Rei::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
    int distanciaLinha = linhaDestino - linhaOrigem; //Guarda a diferença de linhaDestino e linhaOrigem
    int distanciaColuna = colunaDestino - colunaOrigem; //Guarda a diferença de colunaDestino e colunaOrigem
    int flag = 1; //Verifica se o movimento é válido

    if(distanciaLinha == 0 && distanciaColuna == 0) //Tentou permanecer no mesmo lugar
        flag = 0; //Definindo flag como 0 para não entrar no próximo caso

    if((distanciaLinha == 1 || distanciaLinha == -1 || distanciaLinha == 0) && flag){ //Verifica diferença da linha
        cout <<"testando"<<endl;
        if(distanciaColuna == 1 || distanciaColuna == -1 || distanciaColuna == 0) //Verifica diferença da coluna
             return 1; //Retorna 1 se o movimento for válido
        else
            return 0;
    }
    else
        return 0;
}

Rei::~Rei(){
    morte = true; //Destrutor do Rei muda o estado de vida para morto
}

string Rei::desenha(){
    string retorno;

    if(cor == 'B') //cor for branca
        retorno = "   R   ";
    else
        retorno = "   r   ";

    return(retorno);
}

/*-----------------------------------------------------------------------------*/
