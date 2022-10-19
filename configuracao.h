#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#ifdef _WIN32
    #include <Windows.h>
    #define LIMPA "cls"
#else
    #include <unistd.h>
    #define LIMPA "clear"
#endif
#include "structConfig.h"


void aparenciaMenu(void)
{
	system(LIMPA);
	printf("*****************************************************\n");
	printf("                LISTA DE PESSOAS E RGS\n");
	printf("*****************************************************\n\n\n\n");
}



void aparenciaLista(void)
{
	system(LIMPA);
	printf("-------------------------------\n");
	printf(" POSIÇÃO |   NOME   |    RG    \n");
	printf("-------------------------------\n");
}



void aparenciaMenuDescricao(int descricao)
{
	switch(descricao)
	{
		case 1:
		{
			printf("Listas:\n");
			break;
		}
		case 2:
		{
			printf("Ações: \n");
			break;
		}
		case 3:
		{
			printf("Inserir:\n");
			break;
		}
		case 4:
		{
			printf("Deletar:\n");
			break;
		}
		case 5:
		{
			printf("Procurar:\n");
			break;
		}
		case 6:
		{
			printf("Leitura do arquivo:\n");
			break;
		}
		case 7:
		{
			printf("Posição:\n");
			break;
		}
		case 8:
		{
			printf("Registro Geral:\n");
			break;
		}
		case 9:
		{
			printf("Salvar arquivo como:\n");
			break;
		}
		case 10:
		{
			printf("Como funciona o programa:\n");
			break;
		}
	}
	printf("-----------------------------------------------------\n\n");
}



void ler_string(char *resposta)
{
	int tamanho;
    char letra, *string;
	string = (char*) malloc (2*sizeof(char));
    
	scanf(" %c", &letra);

    for (tamanho = 0; letra != '\n'; tamanho++)
    {
        string[tamanho] = letra;
        string = (char*) realloc(string, (tamanho+3)*sizeof(char));

        scanf("%c", &letra);
    }
    string[tamanho+1] = '\0';
	*resposta = string[0];
	free(string);
}


void digiteAlgo()
{
	char continuar;
	printf("\n\nDigite qualquer tecla para continuar:\n");
	ler_string(&continuar);
}
	

void tipoDeErro(int erro)
{
	system(LIMPA);
	aparenciaMenu();
	switch(erro)
	{
		case 1:
		{
			aparenciaMenuDescricao(1);
			printf("Digite o número da lista novamente!!!\n"
			       "O número da lista precisa estar presente no menu "
			       "de seleção!\n");
			break;
		}
		case 2:
		{
			aparenciaMenuDescricao(2);
			printf("Digite o número da ação novamente!!!\n"
			       "O número da ação precisa estar presente no menu "
			       "de seleção!\n");
			break;
		}
		case 3:
		{
			aparenciaMenuDescricao(2);
			printf("Digite o número da ação novamente!!!\n"
			       "É preciso ler uma lista pelo menu de seleção "
			       "antes de escolher outras ações!\n");
			break;
		}
		case 4:
		{
			aparenciaMenuDescricao(6);
			printf("Digite o arquivo novamente!!!\n"
			       "O arquivo precisa existir no sistema!\n");
			break;
		}
		case 5:
		{
			aparenciaMenuDescricao(7);
			printf("Digite a posição novamente!!!\n"
			       "A posição precisa estar entre os limites "
			       "de tamanho!\n");
			break;
		}
		case 6:
		{
			aparenciaMenuDescricao(8);
			printf("Digite a RG novamente!!!\n"
			       "O RG só pode ter no máximo 8 caracteres "
				   "de tamanho!\n");
			break;
		}
	}
	sleep(3);
	system(LIMPA);
}



void menudeSelecaoLista(Config *config)
{
	do
	{	
		system(LIMPA);
		aparenciaMenu();
		aparenciaMenuDescricao(1);
		printf("1) Lista sequencial.\n");
		printf("2) Lista encadeada simples.\n");
		printf("3) Os dois juntos.\n");
		printf("Escolha uma lista: ");
		scanf("%d", &config->lista);
		if (config->lista<1 || config->lista>3)
			tipoDeErro(1);
	}
	while(config->lista<1 || config->lista>3);
}



void menuDeSelecaoAcao(Config *config)
{
	do
	{
		system(LIMPA);
		aparenciaMenu();
		aparenciaMenuDescricao(2);
		printf("1) Inserir um nó no início da lista.\n");
		printf("2) Inserir um nó no fim da lista.\n");
		printf("3) Inserir um nó na posição N.\n");
		printf("4) Deletar um nó no início da lista.\n");
		printf("5) Deletar um nó no fim da lista.\n");
		printf("6) Deletar um nó na posição N.\n");
		printf("7) Procurar um nó pelo RG.\n");
		printf("8) Procurar um nó na posição N.\n");
		printf("9) Mostrar lista.\n");
		printf("10) Salvar lista.\n");
		printf("11) Ler lista.\n");
		printf("12) Comparar resultados.\n");
		printf("13) Como funciona?\n");
		printf("14) Sair do sistema.\n\n");
		printf("Escolha uma ação: ");
		scanf("%d", &config->acao);
		if (config->acao<1 || config->acao>14)
			tipoDeErro(2);
	}
	while(config->acao<1 || config->acao>14);
}



void menudeSelecaoInserir()
{
	system(LIMPA);
	aparenciaMenu();
	aparenciaMenuDescricao(3);
}



void menudeSelecaoDeletar()
{
	system(LIMPA);
	aparenciaMenu();
	aparenciaMenuDescricao(4);
}



void menudeSelecaoProcurar()
{
	system(LIMPA);
	aparenciaMenu();
	aparenciaMenuDescricao(5);
}



void menudeSelecaoLer()
{
	system(LIMPA);
	aparenciaMenu();
	aparenciaMenuDescricao(6);
}



void menudeSelecaoPosicaoInserir(Config *config)
{
	do
	{
		system(LIMPA);
		aparenciaMenu();
		aparenciaMenuDescricao(7);
		switch(config->acao)
		{
			case 3:
			{
				printf("Escolha uma posição da lista para inserir (1 até %d): ", config->tamanho+1);
				break;
			}
		}
		scanf("%d", &config->posicao);	
		if (config->posicao<1 || config->posicao>config->tamanho+1)
			tipoDeErro(5);
	}
	while(config->posicao<1 || config->posicao>config->tamanho+1);
}



void menudeSelecaoPosicao(Config *config)
{
	do
	{
		system(LIMPA);
		aparenciaMenu();
		aparenciaMenuDescricao(7);
		switch(config->acao)
		{
			case 6:
			{
				printf("Escolha uma posição da lista para deletar (1 até %d): ", config->tamanho);
				break;
			}
			case 8:
			{
				printf("Escolha uma posição da lista para procurar (1 até %d): ", config->tamanho);
				break;
			}
		}
		scanf("%d", &config->posicao);	
		if (config->posicao<1 || config->posicao>config->tamanho)
			tipoDeErro(5);
	}
	while(config->posicao<1 || config->posicao>config->tamanho);
}

void menudeSelecaoNomeRG(Config *config)
{
	system(LIMPA);
	aparenciaMenu();
	aparenciaMenuDescricao(7);
	printf("Digite o nome: ");
	scanf("%s", config->nome);
	do
	{
		system(LIMPA);
		aparenciaMenu();
		aparenciaMenuDescricao(7);
		printf("Digite o RG: ");
		scanf("%d", &config->rg);
		if (config->rg<1 || config->rg>99999999)
			tipoDeErro(6);
	}
	while(config->rg<1 || config->rg>99999999);
}

void menudeSelecaoRG(Config *config)
{
	do
	{
		system(LIMPA);
		aparenciaMenu();
		aparenciaMenuDescricao(8);
		printf("Escolha um número de RG da lista para procurar\n(Até 8 dígitos): ");
		scanf("%d", &config->rg);		
		if (config->rg<1 || config->rg>99999999)
			tipoDeErro(6);
	}
	while(config->rg<1 || config->rg>99999999);
}



void menudeSelecaoArquivo(Config *config)
{
	FILE *arquivo;
	char txt[5]= ".txt";
	do
	{
		system(LIMPA);
		aparenciaMenu();
		aparenciaMenuDescricao(6);
		printf("Digite o nome do arquivo aqui: ");
		scanf("%s", config->nomeArquivo);
		strcat(config->nomeArquivo, txt);
		arquivo = fopen(config->nomeArquivo, "r");
		if(!arquivo)
		{
			tipoDeErro(4);
		}
	}
	while(!arquivo);
	fclose(arquivo);
}

void menudeSelecaoSalvar(Config *config)
{
	FILE *arquivo;
	char txt[5]= ".txt";
	system(LIMPA);
	aparenciaMenu();
	aparenciaMenuDescricao(10);
	printf("Digite o nome do arquivo para salvar: ");
	scanf("%s", config->arqSalvo);
	strcat(config->arqSalvo, txt);
}

void contadorLista(Config *config)
{
	FILE *arquivo;
	config->tamanho=0;
	char caracter;
	arquivo = fopen(config->nomeArquivo, "r");
	for (caracter=fgetc(arquivo); caracter!=EOF; caracter=fgetc(arquivo))
	{
		if (caracter == '\n')
            config->tamanho++;
	}
	fclose(arquivo);
}



void explicacaoPrograma(void)
{
	char continuar;
	system(LIMPA);
	aparenciaMenu();
	aparenciaMenuDescricao(11);
	printf("Ideia: Faça um programa que use as duas formas de\n"
		   "armazenar os dados em paralelo e mostre a diferença\n"
		   "de tempo entre cada ação realizada nas duas listas\n"
		   "definidas abaixo:\n\n");
		
	printf("Lista Sequencial: Uma lista sequencial aproveita a\n"
		   "seqüencialidade da memória. Uma lista sequencial ocupa\n"
		   "um espaço consecutivo na memória equivalente ao tamanho\n"
		   "do nó, portanto, a lista sequencial é um vetor.\n\n");
		  
	printf("Lista Encadeada simples: As listas encadeadas permitem\n"
		   "a utilização de estruturas flexíveis em relação à sua\n"
		   "quantidade de elementos. Cada elemento de um nó é\n"
		   "composto por uma parte que armazena dados e outra que\n"
		   "armazena campos de referencia com outros nós. O campo\n"
		   "de referência dos nós contém o endereço de memória onde\n"
		   " o próximo nó está armazenado. Por isso, a os dados\n"
		   "da lista encadeada podem estar em qualquer lugar\n"
		   "na memória.\n\n");
	
	printf("\n\nDigite qualquer tecla para continuar:\n");
	ler_string(&continuar);
}



void fimDoPrograma(void)
{
	system(LIMPA);
	printf("*****************************************************\n");
	printf("                    FIM DO PROGRAMA\n");
	printf("*****************************************************\n");
	sleep(3);
}