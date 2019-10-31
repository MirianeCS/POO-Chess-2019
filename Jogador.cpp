#include <iostream>
#include <string>
#include "Jogador.h"

using namespace std;


/*-----------------------------------------------------------------------------*/

Jogador::Jogador(char c){
    cor = c;
    int jogador = 1;
    cout << "Digite o nome do jogador: " << endl; //Pede nome do jogador
    if(cor == 'P')
      jogador = 2;

    cin >> nome; //Recebe nome do jogador
    cout << endl <<"                                                                                         "<<nome << " voce e o JOGADOR " << jogador << endl << endl;

}

/*-----------------------------------------------------------------------------*/

Jogador::~Jogador(){
}
