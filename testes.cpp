#include <iostream>
#include <string>
#include <unistd.h>
#include "coutHelper/coutHelper.h"

using namespace std;

using cHe::Frente;
using cHe::Fundo;

int main() {
	cHe::cHe impressora;
	impressora.setBEsq("Carregando[", Frente::Preto, Fundo::Branco);
	impressora.setBDir("]",Frente::Preto, Fundo::Branco);

	//cout << impressora << endl;

	for(int x = 0; x < (impressora.larMax() -12); x++) {
		impressora.setBPonto("#", Frente::Vermelho, Fundo::Branco, 11+x);
		usleep(10000);
		cout << impressora;
	}

	impressora.novaLinha();
	impressora.setBEsq("Pronto!",Frente::Vermelho,Fundo::Branco);
	cout << impressora << endl;


	return 0;
}
