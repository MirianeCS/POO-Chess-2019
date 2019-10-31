#include <iostream>
#include "Jogo.h"

using namespace std;

enum {invalido = 0, valido, validoComeu, xeque, xequeEMOCIONOU};


void Jogo::inicializar (){ //Começa o jogo

    campo.inicializarTabuleiro(); //Inicializa o tabuleiro do jogo
}

/*-----------------------------------------------------------------------------*/

Jogador Jogo::player(int vez){//Verifica de quem é a vez
    if(vez) return j1;// Se 1 então J1
    else return j2; // se 0 j2
}

/*-----------------------------------------------------------------------------*/

void Jogo::jogada(){

    int flag = 1;//Controla se foi efetuada uma jogada
    string frase;//Retorno do inserirPeça das pecas
    int linhaDestino, colunaDestino, linhaOrigem, colunaOrigem; // Guarda valores de linhas e colunas de origem e destino
    int verificou = 0;
    int come;
    int confirmaCome = 0;

    while(flag){ //Enquanto não realiza jogada valida
        cin >> linhaOrigem >> colunaOrigem >> linhaDestino >> colunaDestino; //Recebe valores de linhas e colunas de origem e destino da peça

        Peca *extra = campo.retornaPeca(linhaOrigem, colunaOrigem);
        int tipo = extra->getTipo();

        if(campo.verificaPosicao(linhaOrigem,colunaOrigem)) { //Verifica se existe peca na posição de origem
            int movimento = campo.checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);//Chega movimento da peca

            std::cout << "MOVIMENTO :" << movimento << '\n';

            if(campo.retornaPeca(linhaDestino, colunaDestino))
              confirmaCome = 1;

            if(tipo == 0 && movimento == 0 && confirmaCome) //CHECANDO PEAO
            {
              // char cor = extra->getCor();

              int diferencaL, diferencaC;
              diferencaL = linhaOrigem - linhaDestino;
              diferencaC = colunaOrigem - colunaDestino;

              if(diferencaL < 0)
                diferencaL *= (-1);
              if(diferencaC < 0)
                diferencaC *= (-1);

              if(diferencaL == 1 && diferencaC == 1)
                movimento = 1;
            }

            if(movimento){//Se movimento valido

              come = campo.verificaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);


              if(come)
              {
                //std::cout << "entrou" << '\n';
                std::cout << "VALOR DO COME: " << come << '\n';

                if(come == validoComeu)
                {
                  // std::cout << "NAO ERA PARA ENTRAR " << '\n';

                  campo.comeu(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
                  verificou = 1;
                }
                else
                {
                  // std::cout << "ENTROU NO ELSE " << '\n';

                  verificou = campo.colocaPeca(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);//Coloca peca na posição de destino se a posicao não estiver ocupada



                  // Peca *atual = campo.retornaPeca(linhaOrigem, colunaOrigem);
                  //
                  //
                  //   std::cout << "chegou ELSE" << '\n';
                  //
                  // if(atual)
                  //   std::cout << "existe atual NO ELSE " << '\n';


                  campo.tiraPeca(linhaOrigem, colunaOrigem);
                }
              }

              if(verificou){ //Se a peca "andou"

                  // campo.tiraPeca(linhaOrigem, colunaOrigem);//Atribuindo posicao de origem como vazia
                  frase = "inseriu";
                  flag = 0;
              }
              else
                if(tipo == 0)
                  frase = "MOVIMENTO INVALIDO";
                else if(movimento && !verificou)
                  frase = "OBSTACULOS NO CAMINHO\n";

          }

          else{
              frase = "MOVIMENTO ERRADO";
          }
      }
      else //Não existe peça na posição de origem
          frase =  "NÃO EXISTE PEÇA NESTA POSIÇÃO";

      system("clear");//Limpa tela, para desenhar tabuleiro novamente
      cout << endl << endl << frase << endl << endl;
      campo.desenha();//Desenha tabuleiro
    }

}

/*-----------------------------------------------------------------------------*/

Jogo::Jogo(): j1('B'), j2('P'){//construtor do jogo + construtor jogador ****
    cout << endl <<" ------------------- (*---*) Inicio do jogo (+__+) ------------------- " << endl;
}

/*-----------------------------------------------------------------------------*/

Jogo::~Jogo(){
    cout << "Fim do jogo" << '\n'; //Sinaliza fim do jogo
}
