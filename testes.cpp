#include <iostream>
#include <string>
#include "coutHelper.h"

using namespace std;

using cHe::Frente;
using cHe::Fundo;

int main() {
	cHe::cHe impressora;
	impressora.setBEsq("Carregando:", Frente::Preto, Fundo::Branco);

	cout << impressora << endl;

	return 0;
}
