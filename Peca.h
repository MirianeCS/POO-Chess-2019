//CLASSE PEÇA ABSTRATA
#ifndef PECA_H
#define PECA_H

#include <iostream>
#include <string>
using namespace std;

class Peca
{
  protected:
      bool morte;
      char cor;
      int tipo;

  public:
    Peca(int t, char c, bool m);


    // void comer(int, int);
    // int verificaMovimento(int, int, int, int);
    virtual string desenha() = 0;
    virtual int checaMovimento(int, int, int, int) = 0;
    void morreu();

    char getCor();
    int getTipo();

    //virtual ~Peca() = 0; //VAMOS USAR PARA DESALOCAR PECAS

};

#endif
