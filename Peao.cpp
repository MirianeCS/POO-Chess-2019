#include <iostream>
#include "Peao.h"
#include <string>
using namespace std;


/*-----------------------------------------------------------------------------*/

Peao::Peao(char c) : Peca(0, c, false) {}

string Peao::desenha(){
    string retorno; //String guarda retorno

    if(cor == 'B') //cor for branca
        retorno = "   P   "; //Definindo a letra maiúscula para cor Branca
    else
        retorno = "   p   "; //Definindo a letra minúscula para cor Preto

   return (retorno); //Retorna a string selecionada para usar a função de cor
}

int Peao::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
    int quantidadeLinha; //Verifica quantidade de linhas que ele pode andar
    int distancia = linhaDestino - linhaOrigem; //Diferença entre linhaDestino e linhaOrigem


    if(cor == 'P') //Se a peca for Branca, a diferença na distância seria negativa, então multiplicamos por (-1)
        distancia *= (-1);

    if(!primeiroPasso){  //Se o primeiro passo não tiver acontecido
        quantidadeLinha = 2; //Defini a quantidade de passos que serão dadas como 2
        primeiroPasso = true; //Definindo que o primeiroPaso foi dado
    }
    else
        quantidadeLinha = 1; //Defini a quantidade de passos que serão dados como 1

    if((distancia <= quantidadeLinha) && (distancia > 0)){ //Verifica se ele não tentou andar para trás e não ficou parado e se não excedeu a quantidade de linhas
        if(colunaOrigem == colunaDestino){//Verifica se não mudou de coluna
            return 1; //Retorna 1 se movimento foi válido
        }
        else
            return 0;
    }
        return 0;

}

// Peao::~Peao(){
//     morte = true; //Destrutor do Peao muda estado de vida para morto
// }
