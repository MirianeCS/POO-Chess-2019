#include <iostream>
#include <string>
#include "Tabuleiro.h"
#include "rainbow.hpp"

#include "Peao.h"
#include "Dama.h"
#include "Rei.h"
#include "Bispo.h"
#include "Torre.h"
#include "Cavalo.h"

using namespace std;

//INVALIDO = 0 ; VALIDO = 1 ; VALIDOCOMEU = 2 ; XEQUE = 3 ; xequeEMOCIONOU = 4

Peca *pExtra;
enum {invalido = 0, valido, validoComeu, xeque, xequeEMOCIONOU};

/*-----------------------------------------------------------------------------*/

Tabuleiro::Tabuleiro (){ //Alocação matriz dinamica
    tabuleiro = new Posicao*[8]; //Aloca vetor do tipo ponteiro Posição
    for(int i = 0; i < 8; i++){
        tabuleiro[i] = new Posicao[8]; //Aloca um vetor pra cada indice do vetor de ponteiro Posição
    }


  // PEAO
  for(int i = 0, j = 0 ; i < 16 ; i++, j++)
  {
    if(i < 8){
    pecas[i] = new Peao('B');
    tabuleiro[1][j].inserirPeca(pecas[i]);//coloca peça no tabuleiro

    if(j == 7)
      j = -1;
    }
    else{
      pecas[i] = new Peao('P');
      tabuleiro[6][j].inserirPeca(pecas[i]);//coloca peça no tabuleiro
    }
  }

  for(int i = 16 ; i < 28 ; i += 3)
  {
    pecas[i] = new Torre('B');
    pecas[i+1] = new Cavalo('B');
    pecas[i+2] = new Bispo('B');

    if(i > 21)
    {
      pecas[i] = new Torre('P');
      pecas[i+1] = new Cavalo('P');
      pecas[i+2] = new Bispo('P');
    }
  }

  //INSERINDO NO TABULEIRO  TORRE CAVALO BISPO
  for(int i = 0, j = 16 ; i < 8 ; i += 7, j+= 6)
  {
    tabuleiro[i][0].inserirPeca(pecas[j]);
    tabuleiro[i][1].inserirPeca(pecas[j+1]);
    tabuleiro[i][2].inserirPeca(pecas[j+2]);
  }

  for(int i = 0, j = 19 ; i < 8 ; i += 7, j+= 6)
  {
    tabuleiro[i][7].inserirPeca(pecas[j]);
    tabuleiro[i][6].inserirPeca(pecas[j+1]);
    tabuleiro[i][5].inserirPeca(pecas[j+2]);
  }

  //REI E RAINHA
  pecas[28] = new Rei('B');
  tabuleiro[0][3].inserirPeca(pecas[28]);
  reis[0][0] = 0;
  reis[0][1] = 3;

  pecas[29] = new Dama('B');
  tabuleiro[0][4].inserirPeca(pecas[29]);

  pecas[30] = new Rei('P');
  tabuleiro[7][3].inserirPeca(pecas[30]);
  reis[1][0] = 7;
  reis[1][1] = 3;

  pecas[31] = new Dama('P');
  tabuleiro[7][4].inserirPeca(pecas[31]);
}

/*-----------------------------------------------------------------------------*/
void atualizaRei(int linha, int coluna, char cor){

  int l = cor == 'B' ? 0 : 1;

  reis[l][0] = linha;
  reis[l][1] = coluna;

}
/*-----------------------------------------------------------------------------*/

void Tabuleiro::inicializarTabuleiro(){
    desenha();//desenha tabuleiro
}

int Tabuleiro::colocaPeca(int linhaO, int colunaO, int linhaD, int colunaD){//Acessa posição[linha][coluna] e então esta posição chama o seu metodo inserir peca
  pExtra = retornaPeca(linhaO, colunaO);
  return tabuleiro[linhaD][colunaD].inserirPeca(pExtra);

}

void Tabuleiro::tiraPeca(int linha, int coluna){//Tira peça da posição (deixa como vazia)
    tabuleiro[linha][coluna].tirarPeca();
}
/*-----------------------------------------------------------------------------*/

void Tabuleiro::desenha(){

    std::cout << std::endl;

    for(int i = 0; i < 8; i++){//Numero de linhas compartilhado com o desenho e com a matriz tabuleiro (primeira indice)
        if(i == 0) cout <<"            0      1      2      3      4      5      6      7"<< endl << endl;
        for(int k = 0; k < 3; k++){ //Para cada linha temos 3 linhas, para personalizar o campo posição do tabuleiro
            for(int j = 0; j < 8; j++){//Numero de colunas compartilhado com o desenho e com a matriz tabuleiro (segunda indice)
                if(k != 1){//as linhas e colunas estão sem peças (personalização do campo posição do tabuleiro)
                    if(j == 0)
                        cout <<"         " ;
                    if(i%2 == 0){//Alternancia dos campos Branco e Preto
                        if(j%2 == 0)
                            print_colored("       ", BLACK, BG_WHITE); // Metodo da biblioteca rainbow para printar com as cores, letra preta e fundo branco
                        else
                            print_colored("       ", WHITE, BG_CYAN);// Metodo da biblioteca rainbow para printar com as cores, letra branca e fundo preto

                    }
                    else{
                        if(j%2 != 0)
                            print_colored("       ", BLACK, BG_WHITE);// Metodo da biblioteca rainbow para printar com as cores, letra preta e fundo branco
                        else
                            print_colored("       ", WHITE, BG_CYAN);// Metodo da biblioteca rainbow para printar com as cores, letra branca e fundo preto
                    }
                }
                else{//Existe peça no tabuleiro
                    if(j == 0 && k == 1)
                        cout <<"    "<<i<<"    " ;
                    string retorno;
                    if(tabuleiro[i][j].verificaPeca())//Verifica existencia de peça
                    {
                      pExtra = retornaPeca(i, j);
                        retorno = desenhaPeca(pExtra);//string com o desenho da peça
                    }
                    else
                        retorno = "       ";//Sem peça presente na tabuleiro[i][j], então desenho em "branco"
                    if(i%2 == 0){//Alternancia das linhas Branco e Preto
                        if(j%2 == 0)
                            print_colored(retorno, BLACK, BG_WHITE);// Metodo da biblioteca rainbow para printar com as cores, letra preta e fundo branco
                        else
                            print_colored(retorno, WHITE, BG_CYAN);// Metodo da biblioteca rainbow para printar com as cores, letra branca e fundo preto
                    }
                    else{
                        if(j%2 != 0)
                            print_colored(retorno, BLACK, BG_WHITE);// Metodo da biblioteca rainbow para printar com as cores, letra preta e fundo branco
                        else
                            print_colored(retorno , WHITE, BG_CYAN);// Metodo da biblioteca rainbow para printar com as cores, letra branca e fundo preto
                    }
                }
            }
            cout <<'\n';//Quebra linha, depois de printas todas as colunas
        }
    }

    cout << endl;//Divisão entre o tabuleiro e a linha de comandos


}

/*-----------------------------------------------------------------------------*/

Tabuleiro::~Tabuleiro(){
    for(int i = 0; i < 8; i++){//Desaloca Matriz
        delete[] tabuleiro[i];
    }
    delete[] tabuleiro;
}

int Tabuleiro::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
    if((linhaOrigem >= 0 && linhaOrigem <= 7) && (colunaOrigem >= 0 && colunaOrigem <= 7) && (linhaDestino >= 0 && linhaDestino <= 7) && (colunaDestino >= 0 && colunaDestino <= 7))
    {
      pExtra = retornaPeca(linhaOrigem, colunaOrigem);
      return pExtra->checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
    }
    return(0);
}

/*-----------------------------------------------------------------------------*/

int Tabuleiro::verificaPosicao(int x, int y) {
    return (tabuleiro[x][y].verificaPeca());
}

string Tabuleiro::desenhaPeca(Peca *p){ //Acessa a peça do tabuleiro e tal chama seu metodo desenha
    return p->desenha();
}

int Tabuleiro::verificaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
  int diferencaLinhas, diferencaColunas;
  int extra, tipo;

  Peca *atual = retornaPeca(linhaOrigem, colunaOrigem);

  tipo = atual->getTipo();

  if(tipo != 2){

    if(linhaDestino < linhaOrigem)
    {
      diferencaLinhas = linhaOrigem - linhaDestino;
    }
    else
    {
      diferencaLinhas = linhaDestino - linhaOrigem;
    }
    if(colunaDestino < colunaOrigem)
    {
      diferencaColunas = colunaOrigem - colunaDestino;
    }
    else
    {
      diferencaColunas = colunaDestino - colunaOrigem;
    }
}

  if(diferencaLinhas == 0)
  {
    for(int i = colunaOrigem + 1; i < colunaDestino ; i++)
      if(tabuleiro[linhaOrigem][i].verificaPeca())
        return 0;

    // if((pExtra = retornaPeca(linhaDestino, colunaDestino)))
    // {
    //   Peca *atual = retornaPeca(linhaOrigem, colunaOrigem);
    //
    //   if(pExtra->getCor() == atual->getCor())
    //     return(0);
    //
    //   else
    //     return(validoComeu);
    // }

    return((pegaUltimo(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)));

    // return 1;
  }

  else if(diferencaColunas == 0)
  {
    int vai;
    for(int i = linhaOrigem + 1; i < linhaDestino ; i++)
      if(tabuleiro[i][colunaOrigem].verificaPeca())
        return 0;
    //std::cout << "passou" << '\n';

    vai = pegaUltimo(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);

    //std::cout << vai << '\n';

    return(vai);
  }

  else if (tipo == 2){
    return (pegaUltimo(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino));

    //}
  }

  else
  {
    // std::cout << "nao chegou aqui" << '\n';
    for(int i = linhaOrigem + 1, j = colunaOrigem + 1 ; i < linhaDestino && j < colunaDestino; i++, j++)
        if(tabuleiro[i][j].verificaPeca())
          return 0;
    return((pegaUltimo(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)));
  }


}


int Tabuleiro::pegaUltimo(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino)
{
  if((pExtra = (retornaPeca(linhaDestino, colunaDestino))))
  {
    std::cout << linhaOrigem << colunaOrigem << '\n';
    Peca *atual = retornaPeca(linhaOrigem, colunaOrigem);

    if(((pExtra->getCor()) == (atual->getCor())))
    {
      // std::cout << "entrouPECA COR" << '\n';
      return(0);
    }
    else
    {
      // std::cout << "entrouCOMEUPECA" << '\n';
      // std::cout << validoComeu << '\n';
      return(2);
    }
  }


  //
  // Peca *atual = retornaPeca(linhaOrigem, colunaOrigem);
  //
  //
  // std::cout << "chegou aqui 1 SEGUJNDA AAAAA" << '\n';
  //
  // if(atual)
  //   std::cout << "existe atual SEGUHNDA AAA " << '\n';




  return(valido);
}

//VERIFICAÇÃO SE A PEÇA COMEU OUTRA PEÇA
void Tabuleiro::comeu(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino)
{
  // std::cout << "ENTROU NO COMEU PORRA" << '\n';

  tiraPeca(linhaDestino, colunaDestino);

  colocaPeca(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);

  tiraPeca(linhaOrigem, colunaOrigem);

}

Peca *Tabuleiro::retornaPeca(int linha, int coluna)
{
  return(tabuleiro[linha][coluna].retornaP());
}
