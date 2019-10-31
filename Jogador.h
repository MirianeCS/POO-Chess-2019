#include <iostream>
#include <string>

using namespace std;

class Jogador{

    private:
        char cor; //Guarda cor do jogador
        string nome; //Guarda o nome do jogador

    public:
        Jogador(char c); //Construtor da classe Jogador recebendo a cor pré definida
        ~Jogador(); //Deconstrutor da classe Jogador


};
