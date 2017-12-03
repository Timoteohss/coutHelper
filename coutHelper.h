//coutHelper.h
//Header para coutHelper
//v0.1

#ifndef COUTHELPER_H
#define COUTHELPER_H

#include <ostream>
#include <string>

namespace cHe {
	enum class Frente {
		Preto = 30,
		Branco = 37,
		Padrao = 39
	};

	enum class Fundo {
		Preto = 40,
		Branco = 47,
		Padrao = 49
	};

	class bCh {
		public:
			bCh();
			void setCh(char);
			void setCh(char, Frente, Fundo);
			void setProxCh(bCh*);
			bCh* getProxCh();
			char getCh();

			friend std::ostream & operator<< (std::ostream &, const bCh &);

		private:
			bCh * proxCh;
			char ch;
			Frente fCor;
			Fundo bCor;
	};

	class cHe {
		public:
			cHe();
			void nova_linha();
			int altMax();
			int larMax();

			void setBEsq(const std::string &);
			void setBEsq(const std::string &,Frente,Fundo);

			void setBDir(const std::string &);
			void setBDir(const std::string &,Frente,Fundo);
			
			void setBPonto(const std::string &,int);
			void setBPonto(const std::string &,Frente,Fundo,int);

			void resetB();

			friend std::ostream & operator<< (std::ostream &, const cHe &);

		private:
			int larJanela;
			int altJanela;
			int bTam;
			void bExtend();
			bCh* primeiroChar;
			void setTamJanela();
	};
}
#endif //!COUTHELPER_H
