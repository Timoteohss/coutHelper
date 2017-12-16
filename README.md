# coutHelper

Uma biblioteca c++ para imprimir em qualquer lugar de uma linha, possui tamanho de janela iterativo e cores!

![Exemplo](https://raw.githubusercontent.com/timoteohss/coutHelper/master/exemplo.gif "Exemplo")
## Utilizando

O arquivo testes.cpp exemplifica a utilização da biblioteca de forma simples, algumas coisas a serem notadas a seguir:

Importe as cores caso deseje utilizá-las: 
```c++
using cHe::Frente;
using cHe::Fundo;

```

Criando uma nova impressora:
```c++
cHe::cHe impressora;
```

Métodos da impressora:
```c++
//Adiciona ao Buffer na esquerda
setBEsq(string);
setBEsq(string,Frente,Fundo);

//Adiciona ao Buffer na direita
setBDir(string);
setBDir(string,Frente,Fundo);

//Adiciona ao Buffer no último caracter disponível a esquerda
appendB(string);
appendB(string,Frente,Fundo);

//Adiciona ao Buffer no último caracter disponível a esquerda
appendB(string);
appendB(string,Frente,Fundo);

//Adiciona ao Buffer a cada iteração, do offset dado ao final da iteração, não faz parte do Buffer por si só
setBPonto(string,int);
setBPonto(string,Frente,Fundo,int);

//Gera uma nova linha no Buffer
novaLinha();

//Altura e Largura da janela
altMax();
larMax();

//Reseta o Buffer
resetB();
```

Após escrever algo, apenas envie ao cout como uma variável para ser impressa:

```c++
cout << impressora << endl;
```

## Licença

coutHelper (c) 2017 Timoteohss

Protegido pela licença GNU!

Esse software é **livre** como em **liberdade**, modifique e distribua como bem entender!


