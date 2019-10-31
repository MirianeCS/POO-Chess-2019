//DEFININDO AS FUNCIONALIDADES DO XADREZ
#include <iostream>
#include "Posicao.h"

/*-----------------------------------------------------------------------------*/

class Tabuleiro
{
  private:
    Posicao **tabuleiro; //Definimos tabuleiro como Posicao, alocamos a matriz dinamicamente e guarda as peças no tabuleiro
    Peca *pecas[32];

    int reis[2][2];

  public:

    Tabuleiro(); //Construtor da classe Tabuleiro
    ~Tabuleiro(); //Destrutor da classe Tabuleiro

    void inicializarTabuleiro(); //Inicializa o tabuleiro com todos os espaços com valores NULL
    void desenha(); //Desenha o tabuleiro
    int verificaPosicao(int, int); // Acessa posição[x][y] (encapsulamento)
    int checaMovimento(int, int, int, int);//Verifica se a posição de origem e destino é valida
    int colocaPeca(int, int, int, int);//Acessa posição[linha][coluna] e então esta posição chama o seu metodo inserir peca
    void tiraPeca(int, int);//Acessa uma posição tabuleiro[linha][coluna] e tal chama seu metodo tirarPeca
    string desenhaPeca(Peca *p);//Acessa a peça do tabuleiro e tal chama seu metodo desenha
    int pegaUltimo(int, int, int, int);

    void comeu(int, int, int, int);

    void atualizaRei(int, int, char);

    Peca *retornaPeca(int linha, int coluna);

    int verificaMovimento(int, int, int, int);




};


/*-----------------------------------------------------------------------------*/
