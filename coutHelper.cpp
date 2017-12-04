// coutHelper.cpp
// Definição da classe bCh e cHe
// v0.1

#include <iostream>
#include <sys/ioctl.h>
#include "coutHelper.h"

namespace cHe {
	//----------
	// bCh
	// --------
	
	
	bCh::bCh() {
		proxCh = NULL;
		ch = '\0';
		fCor = Frente::Padrao;
		bCor = Fundo::Padrao;
	}

	void bCh::setCh(char tmp) {
		ch = tmp;
	}

	void bCh::setCh(char tmp, Frente ftmp, Fundo btmp) {
		ch = tmp;
		fCor = ftmp;
		bCor = btmp;
	}

	char bCh::getCh() {
		return ch;
	}

	void bCh::setProxCh(bCh * pCh) {
		proxCh = pCh;
	}

	bCh * bCh::getProxCh() {
		return proxCh;
	}

	std::ostream & operator<< (std::ostream & stream, const bCh & caracter) {
		stream << "\033[";
		stream << static_cast<int>(caracter.fCor) << ";" << static_cast<int>(caracter.bCor);
		stream << "m" << caracter.ch << "\033[0m";
		return stream;
	}

	// ---------
	// cHe
	// ---------
	
	cHe::cHe() {
		setTamJanela();
		primeiroChar = new bCh;
	}

	std::ostream & operator<< (std::ostream & stream, const cHe & linha) {
		stream << '\r';

		bCh * ch = linha.primeiroChar;
		while(ch->getCh() != '\0') {
			stream << *ch;
			ch = ch->getProxCh();		
		}

		stream << std::flush;
		return stream;
	}

	void cHe::novaLinha() {
		std::cout << '\n';
		resetB();
	}

	int cHe::altMax() {
		return altJanela;
	}

	int cHe::larMax() {
		return larJanela;
	}

	void cHe::setBEsq(const std::string & str) {
		this->setBEsq(str, Frente::Padrao, Fundo::Padrao);
	}

	void cHe::setBEsq(const std::string & str, Frente fcor, Fundo bcor) {
		if(str.size() <= larMax()) {
			bCh* ch = primeiroChar;
			bTam = str.size();

			for(int i = 0; i < bTam; i ++) {
				ch->setCh(str[i], fcor, bcor);
				ch->setProxCh(new bCh);
				ch = ch->getProxCh();
			}

			ch->setCh('\0');
		}
		else {
			//Erro!
		}

	}

	void cHe::setBDir(const std::string & str) {
		this->setBDir(str, Frente::Padrao, Fundo::Padrao);
	}

	
	void cHe::setBDir(const std::string & str, Frente fcor,Fundo bcor) {
		if(str.size() <= larMax()) {
			bExtend();
			bCh* ch = primeiroChar;

			for(int n = 0; n < (bTam - str.size()); n++) {
				ch = ch->getProxCh();
			}

			for(int i = 0; i < str.size(); i++) {
				ch->setCh(str[i], fcor, bcor);
				ch = ch->getProxCh();
			}

		}
		else {
			//ERRO!
		}
	}

	void cHe::appendB(const std::string & str) {
		this->appendB(str, Frente::Padrao, Fundo::Padrao);
	}
	
	void cHe::appendB(const std::string & str, Frente fcor, Fundo bcor) {
		if (bTam + str.size() <= larMax()) {
			bCh* ch = primeiroChar;
			while(ch->getCh() != '\0') {
				ch = ch->getProxCh();
			}

			for(int i = 0; i < str.size(); i++) {
				ch->setCh(str[i], fcor, bcor);
				ch->setProxCh(new bCh);
				ch = ch->getProxCh();
			}
			ch->setCh('\0');
			bTam = bTam + str.size();
		}
		else {
			
		}
	}
	
	void cHe::setBPonto(const std::string & str, int off) {
		this->setBPonto(str, Frente::Padrao, Fundo::Padrao,off);
	}

	void cHe::setBPonto(const std::string & str, Frente fcor, Fundo bcor, int off) {
		if (off + str.size() <= larMax()) {
			bExtend();
			bCh* ch = primeiroChar;

			for(int n = 0; n < off; n++) {
				ch = ch->getProxCh();
			}

			for(int i=0; i < str.size(); i++) {
				ch->setCh(str[i],fcor,bcor);
				ch = ch->getProxCh();	
			}
		}
		else {
			//ERRO!
		}
	}

	void cHe::bExtend() {
		bCh* ch = primeiroChar;
		while(ch->getCh() != '\0') {
			ch = ch->getProxCh();
		}

		for(int i = 0; i < (larJanela - bTam); i++) {
			ch->setCh(' ');
			ch->setProxCh(new bCh);
			ch = ch->getProxCh();
		}

		ch->setCh('\0');
		bTam = larJanela;
	}

	void cHe::resetB() {
		bCh* ch = primeiroChar;
		primeiroChar = new bCh;
		primeiroChar->setCh('\0');
	}

	void cHe::setTamJanela() {
		winsize w;
		ioctl(0, TIOCGWINSZ, &w);
		larJanela = w.ws_col;
		altJanela = w.ws_row;

	}
}

