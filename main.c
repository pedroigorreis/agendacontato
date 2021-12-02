/*
	Autor: Pedro Igor Martins dos Reis
	Curso: Eng. de Computação - PUC Minas
	Prof.: Kleber Souza
*/

#include "agenda.h"

int main (void)
{
	int esc = -1;
	do
	{
		menuPrincipal();
		scanf("%d", &esc);
		switch(esc)
		{
			case 0:
			{
				system("clear");
				printf("\n\tFim.\n");
				exit(0);
				break;
			}
			case 1:
			{
				break;
			}
			case 2:
			{
				break;
			}
			case 3:
			{
				break;
			}
			case 4:
			{
				break;
			}
			case 5:
			{
				break;
			}
			default:
			{
				break;
			}
		}
	}
	while(esc != 0);
	return 0;
}