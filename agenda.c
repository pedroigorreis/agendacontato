/*
	Autor: Pedro Igor Martins dos Reis
	Curso: Eng. de Computação - PUC Minas
	Prof.: Kleber Souza
*/

#include "agenda.h"

No *novoNo(Contato *C) // Construção da árvore
{
	No *novo = malloc(sizeof(No));

	if(novo)
	{
		novo->C = C;
		novo->direita = NULL;
		novo->esquerda = NULL;
		novo->altura = 0;
	}
	else
	{
		printf("\tNão foi possível alocar memória para o novo Nó.\n");
	}
	return novo;
}

short alturaNo(No *N) // Retorna a altura do nó.
{
	if(N == NULL)
	{
		return -1;
	}
	else
	{
		return N->altura;
	}
}

short maiorAltura (short x, short y) // Retorna a maior altura entre dois nós.
{
	return (x > y) ? x: y;
}

short balanceamento (No *N) // Cálculo de balanceamento 'aNE - aND'.
{
	if(N)
	{
		return (alturaNo (N->esquerda) - alturaNo(N->direita));
	}
	else
	{
		return 0;
	}
}

No *rotacionarDireita(No *N)
{
	No *x;
	No *y;

	x = N->esquerda;
	y = x->direita;

	x->direita = N;
	N->esquerda = y;

	N->altura = maiorAltura(alturaNo(N->esquerda), alturaNo(N->direita)) + 1;
	x->altura = maiorAltura(alturaNo(x->esquerda), alturaNo(x->direita)) + 1;
	return x;
}

No *rotacionarEsquerda(No *N)
{
	No *x;
	No *y;

	x = N->direita;
	y = x->esquerda;

	x->esquerda = N;
	N->direita = y;

	N->altura = maiorAltura(alturaNo(N->esquerda), alturaNo(N->direita)) + 1;
	x->altura = maiorAltura(alturaNo(x->esquerda), alturaNo(x->direita)) + 1;
	return x;
}

No *rotacionarDirEsq(No *N)
{
	N->direita = rotacionarDireita(N->direita);
	return rotacionarEsquerda(N);
}
No *rotacionarEsqDir(No *N)
{
	N->esquerda = rotacionarEsquerda(N->esquerda);
	return rotacionarEsquerda(N);
}

No *balancear(No *N)
{
	short fb = balanceamento(N); // 'fb' = Fator de balanceamento.
	if(fb < - 1 && balanceamento(N->direita) <= 0)
	{
		N = rotacionarEsquerda(N);
	}
	else if(fb > 1 && balanceamento(N->esquerda) >= 0)
	{
		N = rotacionarDireita(N);
	}
	else if(fb > 1 && balanceamento(N->esquerda) < 0)
	{
		N = rotacionarEsqDir(N);
	}
	else if(fb < - 1 && balanceamento(N->direita) < 0)
	{
		N = rotacionarDirEsq(N);
	}
	return N;
}

No *adicionarContato(No *N, Contato *C)
{
	if(N == NULL) // Árvore vazia / nova.
	{
		return novoNo(C);
	}
	else
	{
		if(C->codigo < N->C->codigo)
		{
			N->esquerda = adicionarContato(N->esquerda, C);
		}
		else if(C->codigo > N->C->codigo)
		{
			N->direita = adicionarContato(N->direita, C);
		}
		else
		{
			printf("\tErro, elemento já existente.\n");
		}
	}
	N->altura = maiorAltura(alturaNo(N->esquerda),alturaNo(N->direita)) + 1;
	N = balancear(N);
	return N;
}

No *removerContato(No* N, int codigo)
{
	if(N == NULL)
	{
		printf("\tValor não encontrado.\n");
		return NULL;
	}
	else
	{
		if(N->C->codigo == codigo)
		{
			if(N->esquerda == NULL && N->direita == NULL)
			{
				free(N);
				printf("\tElemento encontrado e removido.\n");
				return NULL;
			}
			else
			{
				if(N->esquerda != NULL && N->direita != NULL)
				{
					No* auxiliar = N->esquerda;
					while(auxiliar->direita != NULL)
					{
						auxiliar = auxiliar->direita;
						N->C->codigo = auxiliar->C->codigo;
						auxiliar->C->codigo = chave;
						N->esquerda = removerContato(N->esquerda, codigo);
						return N;
					}
				}
				else
				{
					No *auxiliar;
					if(N->esquerda != NULL)
					{
						auxiliar = N->esquerda;
					}
					else
					{
						auxiliar = N->direita;
					}
					free(auxiliar);
					printf("Contato com código %d removido.\n", codigo);
					return auxiliar;
				}
			}
		}
		else
		{
			if(codigo < N->C->codigo)
			{
				N->esquerda = removerContato(N->esquerda, codigo);
			}
			else
			{
				N->direita = removerContato(N->direita, codigo);
			}
		}
	}
	N->altura = maiorAltura(alturaNo(N->esquerda),alturaNo(N->direita)) + 1;
	N = balancear(N);
	return N;
}

// Impressão de dados
void imprimirContato();

// Pesquisa
void pesquisarContato();

// Menus
void menuPrincipal()
{
	printf("\n");
	printf("\t\t.--------.\n");
	printf("\t\t| Agenda |\n");
	printf("\t\t'--------'\n");
	printf("\n");
	printf("\t.--------------------------.\n");
	printf("\t| Escolha a opção desejada |\n");
	printf("\t'--------------------------'\n");
	printf("\t| 0 - Sair do programa     |\n");
	printf("\t| 1 - Adicionar contato    |\n");
	printf("\t| 2 - Atualizar contato    |\n");
	printf("\t| 3 - Remover contato      |\n");
	printf("\t| 4 - Imprimir contatos    |\n");
	printf("\t| 5 - Pesquisar contato    |\n");
	printf("\t'--------------------------'\n");
	printf("\n");
}
