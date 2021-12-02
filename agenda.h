/*
	Autor: Pedro Igor Martins dos Reis
	Curso: Eng. de Computação - PUC Minas
	Prof.: Kleber Souza
*/

// Bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Estruturas
typedef struct Contato
{
	int codigo;
	char name[32];
	char email[32];
	char telefone[11];
	char nascimento[20];
}
Contato;

typedef struct No
{
	Contato *C;
	short altura;
	struct No* direita;
	struct No *esquerda;
}
No;

// Administração da árvore
No *novoNo(Contato *C);
short alturaNo(No *N);
short maiorAltura(short x, short y);

// Balanceamento
No *balancear(No *N);
short balanceamento(No *N);
No *rotacionarDirEsq(No *N);
No *rotacionarEsqDir(No *N);
No *rotacionarDireita(No *N);
No *rotacionarEsquerda(No *N);

// Manipulação de contatos
void altualizarContato();
No *removerContato(No* N, int codigo);
No *adicionarContato(No *N, Contato *C);

// Impressão de dados
void imprimirContato();

// Pesquisa
void pesquisarContato();

// Menus
void menuPrincipal();
