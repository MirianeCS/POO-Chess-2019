#include <iostream>
#include "Peca.h"
// #include "Tabuleiro.h"

using namespace std;

/*-----------------------------------------------------------------------------*/

Peca::Peca(int t, char c, bool m) : tipo(t), cor(c), morte(m) {}

void Peca::morreu()
{
    morte = true;
}

char Peca::getCor()
{
  return(cor);
}

int Peca::getTipo()
{
  return(tipo);
}
