//DEFININDO JOGADORES, JOGADAS
#include <iostream>
#include <string>
#include "Tabuleiro.h"
#include "Jogador.h"

class Jogo{

    private:
    
        Jogador j1, j2; //Define cor para cada um dos jogadores, j1 Branco, j2 Preto 
        Tabuleiro campo; //Inserir tabuleiro no jogo
        int estado;
        
    public:

        Jogo(); //Construtor da classe Jogo
        ~Jogo(); //Desconstrutor da classe Jogo  

        void inicializar();//inicializa campo 
        void jogada(); //Controla o turno de cada jogador e recebe jogada
        Jogador player(int);//Retorna jogador 

};

