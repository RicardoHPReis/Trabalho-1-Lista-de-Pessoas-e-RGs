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
#include "structEncadeada.h"
#include "structEncadComp.h"


void inserirListaEncadeadaPrimeiro(Encadeada **enc, Encadeada **primeiro, EncadComp *encadcomp, int *tamanho, char *nome, int rg)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	*enc = (Encadeada*) malloc (sizeof(Encadeada));
	if(!(*enc)) 
	{
		perror("Não há espaço na memória!\n");
		exit(1);
	}
	encadcomp->me++;
	encadcomp->ce++;
	
	printf("\nInserindo em...\n%d| %s,%08d", 1, nome, rg);
	strcpy((*enc)->nome,nome);
	(*enc)->rg = rg;
	(*enc)->proximo = *primeiro;
	*primeiro = *enc;
	(*tamanho)++;
	encadcomp->me=encadcomp->me+5;
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
	printf("\n\nPrimeiro registro incluido na lista.");
}



void inserirListaEncadeadaUltimo(Encadeada **enc, Encadeada **ultimo, EncadComp *encadcomp, int *tamanho, char *nome, int rg)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	*enc = (Encadeada*) malloc (sizeof(Encadeada));
	if(!(*enc)) 
	{
		perror("Não há espaço na memória!\n");
		exit(1);
	}
	(*tamanho)++;
	encadcomp->me=encadcomp->me+2;
	encadcomp->ce++;

	printf("\nInserindo em...\n%d| %s,%08d", (*tamanho), nome, rg);
	strcpy((*enc)->nome,nome);
	(*enc)->rg = rg;
	(*enc)->proximo=NULL;
	(*ultimo)->proximo = *enc;
	(*ultimo) = *enc;
	encadcomp->me=encadcomp->me+5;
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
	printf("\n\nÚltimo registro incluido na lista.");
}



void inserirListaEncadeadaPosicao(Encadeada **enc, Encadeada **primeiro, Encadeada **ultimo, EncadComp *encadcomp, int *tamanho, int posicao, char *nome, int rg)
{
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	int linha=1, encontrou=0;
	Encadeada *atual, *anterior;
	*enc = (Encadeada*) malloc (sizeof(Encadeada));
	if(!enc) 
	{
		perror("Não há espaço na memória!\n");
		exit(1);
	}
	(*tamanho)++;
	encadcomp->me=encadcomp->me+2;
	encadcomp->ce++;
	
	printf("\nInserindo em...\n%d| %s,%08d", posicao, nome, rg);
	if(posicao==1)
	{
		strcpy((*enc)->nome,nome);
		(*enc)->rg = rg;
		(*enc)->proximo = *primeiro;
		*primeiro = *enc;
		encadcomp->me=encadcomp->me+4;
	}
	else if(posicao==(*tamanho))
	{
		strcpy((*enc)->nome,nome);
		(*enc)->rg = rg;
		(*enc)->proximo=NULL;
		(*ultimo)->proximo = *enc;
		(*ultimo) = *enc;
		encadcomp->me=encadcomp->me+5;
	}
	else
	{
		atual = *primeiro;
		encadcomp->me++;
		while(enc!=NULL && encontrou==0)
		{
			
			if(linha==posicao-1)
			{
				strcpy((*enc)->nome,nome);
				(*enc)->rg = rg;
				(*enc)->proximo = atual->proximo;
				atual->proximo = *enc;
				encontrou=1;
				encadcomp->me=encadcomp->me+5;
			}
			else
			{
				atual = atual->proximo;
				linha++;
				encadcomp->me=encadcomp->me+2;
			}
			encadcomp->ce=encadcomp->ce+3;
		}
		if(encontrou==0)
		{
			printf("\nPosição não encontrada.\n");
		}
		encadcomp->ce=encadcomp->ce+2;
	}
	encadcomp->ce=encadcomp->ce+2;
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
	printf("\n\nRegistro incluido na %d° posição.", posicao);
}


	
void deletarListaEncadeadaPrimeiro(Encadeada **enc, Encadeada **primeiro, EncadComp *encadcomp, int *tamanho)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	printf("\nDeletando...\n%d| %s,%08d", 1, (*primeiro)->nome, (*primeiro)->rg);
	*enc = *primeiro;
	*primeiro = (*enc)->proximo;
	*enc = NULL;
	free(*enc);
	(*tamanho)--;
	encadcomp->me=encadcomp->me+4;
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
	printf("\n\nPrimeiro registro excluído.");
}



void deletarListaEncadeadaUltimo(Encadeada **enc, Encadeada *primeiro, Encadeada **ultimo, EncadComp *encadcomp, int *tamanho)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	*enc = primeiro;
	encadcomp->me++;
	while(*enc!=NULL)
	{
		if((*enc)->proximo==(*ultimo))
		{
			*ultimo = *enc;
			*enc = (*ultimo)->proximo;
			(*ultimo)->proximo=NULL;
			encadcomp->me=encadcomp->me+5;
			printf("\nDeletando...\n%d| %s,%08d", (*tamanho), (*enc)->nome, (*enc)->rg);
			*enc = NULL;
			free(*enc);
		}
		else
		{
			*enc = (*enc)->proximo;
			encadcomp->me++;
		}
		encadcomp->ce=encadcomp->ce+3;
	}
	(*tamanho)--;
	encadcomp->me++;
	encadcomp->ce++;
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
	printf("\n\nÚltimo registro excluído.");
}



void deletarListaEncadeadaPosicao(Encadeada **enc, Encadeada **primeiro, Encadeada **ultimo, EncadComp *encadcomp, int *tamanho, int posicao)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	Encadeada *anterior, *atual;
	int linha=1, encontrou=0;
	*enc = *primeiro;
	encadcomp->me++;
	if(posicao==1)
	{
		printf("\nDeletando...\n%d| %s,%08d", 1, (*primeiro)->nome, (*primeiro)->rg);
		*primeiro = (*enc)->proximo;
		*enc = NULL;
		free(*enc);
		(*tamanho)--;
		encadcomp->me=encadcomp->me+3;
	}
	else if(posicao==(*tamanho))
	{
		while(*enc!=NULL)
		{
			if((*enc)->proximo==(*ultimo))
			{
				*ultimo = *enc;
				*enc = (*ultimo)->proximo;
				(*ultimo)->proximo=NULL;
				printf("\nDeletando...\n%d| %s,%08d", posicao, (*enc)->nome, (*enc)->rg);
				*enc = NULL;
				free(*enc);
				encadcomp->me=encadcomp->me+5;
			}
			else
			{
				*enc = (*enc)->proximo;
				encadcomp->me++;
			}
			encadcomp->ce=encadcomp->ce+3;
		}
		(*tamanho)--;
		encadcomp->me++;
		encadcomp->ce++;
	}
	else
	{
		while(enc!=NULL && encontrou==0)
		{
			if(linha==posicao-1)
			{
				anterior = *enc;
				*enc = (*enc)->proximo;
				printf("\nDeletando...\n%d| %s,%08d", posicao, (*enc)->nome, (*enc)->rg);
				atual = (*enc)->proximo;
				free(*enc);
				anterior->proximo = atual;
				encontrou=1;
				encadcomp->me=encadcomp->me+6;
			}
			else
			{
				*enc = (*enc)->proximo;
				linha++;
				encadcomp->me=encadcomp->me+2;
			}
			encadcomp->ce=encadcomp->ce+3;
		}
		(*tamanho)--;
		encadcomp->me++;
		encadcomp->ce++;
	}
	encadcomp->ce=encadcomp->ce+3;
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
	printf("\n\n%d° registro excluído.", posicao);
}



void procurarListaEncadeadaRG(Encadeada *enc, Encadeada *primeiro, Encadeada *ultimo, EncadComp *encadcomp, int rg)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	int linha=1, encontrou=0;
	enc = primeiro;
	encadcomp->me++;
	while(enc!=NULL && encontrou==0)
	{
		if(rg==enc->rg)
		{
			encontrou=1;
			printf("RG encontrado!!\n");
			printf("%d| %s,%08d", linha, enc->nome, enc->rg);
			encadcomp->me++;
		}
		enc = enc->proximo;
		linha++;
		encadcomp->me=encadcomp->me+2;
		encadcomp->ce=encadcomp->ce+2;
	}
	if(encontrou==0)
	{
		printf("RG não encontrado!!\n");
	}
	encadcomp->ce=encadcomp->ce+2;
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
}



void procurarListaEncadeadaPosicao(Encadeada *enc, Encadeada *primeiro, Encadeada *ultimo, EncadComp *encadcomp, int tamanho, int posicao)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	int linha=1, encontrou=0;
	enc = primeiro;
	encadcomp->me++;
	if(posicao==tamanho)
	{
		enc=ultimo;
		linha=posicao;
		encadcomp->me=encadcomp->me+2;
	}
	encadcomp->ce++;
	while(enc!=NULL && encontrou==0)
	{
		if(linha==posicao)
		{
			printf("%d| %s,%08d", linha, enc->nome, enc->rg);
			encontrou=1;
			encadcomp->me++;
			break;
		}
		enc = enc->proximo;
		linha++;
		encadcomp->me=encadcomp->me+2;
		encadcomp->ce=encadcomp->ce+2;
	}
	encadcomp->ce++;
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
}



void mostrarListaEncadeada(Encadeada *enc, Encadeada *primeiro, EncadComp *encadcomp)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	int linha=1;
	if (primeiro==NULL)
	{
	    printf("\n\n--- FIM DA LISTA ---\n\n");
    	return;
	}
	encadcomp->ce++;
	enc=primeiro;
	encadcomp->me++;
	while (enc!=NULL) 
	{
		printf("\n%d| %s,%08d", linha, enc->nome, enc->rg);
	    enc = enc->proximo;
		linha++;
		encadcomp->me=encadcomp->me+2;
		encadcomp->ce++;
	}
	encadcomp->ce++;
	printf("\n\n--- FIM DA LISTA ---\n\n");
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
}



void salvarListaEncadeada(Encadeada *enc, Encadeada *primeiro, EncadComp *encadcomp, char *arqSalvo)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	FILE *arquivo;
	arquivo = fopen(arqSalvo, "w");
	enc = primeiro;
	encadcomp->me=encadcomp->me+2;
	while (enc!=NULL) 
	{
		fprintf(arquivo, "%s,%08d\n", enc->nome, enc->rg);
	    enc = enc->proximo;
		encadcomp->me++;
		encadcomp->ce++;
	}
	encadcomp->ce++;
	fclose(arquivo);
	printf("\n\nArquivo salvo!");
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;	
}



void lerListaEncadeada(Encadeada **enc, Encadeada **primeiro, Encadeada **ultimo, EncadComp *encadcomp, char *nomeArquivo)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	FILE *arquivo;
	int rg, linha=1;
	char *token, buffer[200];
	arquivo = fopen(nomeArquivo, "r");
	encadcomp->me++;

	while(fgets(buffer, 200, arquivo))
	{
		*enc = (Encadeada*) malloc (sizeof(Encadeada));
		if(!(*enc)) 
		{
			perror("Não há espaço na memória!\n");
			exit(1);
		}
		encadcomp->me++;
		encadcomp->ce++;
		token = strtok(buffer, ",");
		rg = atoi(strtok(NULL, "\n"));
		strcpy((*enc)->nome, token);
		(*enc)->rg = rg;
		linha++;
		(*enc)->proximo = NULL;
		encadcomp->me=encadcomp->me+6;
		if (*primeiro==NULL)
		{
			*primeiro = *enc;
			*ultimo = *enc;
			*enc = (*primeiro)->proximo;
			encadcomp->me=encadcomp->me+3;
		}
	    else 
		{
			(*ultimo)->proximo = *enc;
			*ultimo = *enc;
			*enc = (*ultimo)->proximo;
			encadcomp->me=encadcomp->me+3;
		}
		encadcomp->ce=encadcomp->ce+3;
	}
	fclose(arquivo);
	printf("%d nomes e RGs lidos!\n", linha-1);
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
}



void comparacoesListaEncadeada(EncadComp *encomp)
{
	printf("Lista Encadeada\n");
	printf("-----------------------------------------------------\n\n");
	printf("Comparações | Movimentações | Tempo\n\n");
	printf("Inserir no início:     %d | %d | %fs\n", encomp[0].ce, encomp[0].me, encomp[0].tempo);
	printf("Inserir no fim:        %d | %d | %fs\n", encomp[1].ce, encomp[1].me, encomp[1].tempo);
	printf("Inserir na posição N:  %d | %d | %fs\n", encomp[2].ce, encomp[2].me, encomp[2].tempo);
	printf("Deletar no início:     %d | %d | %fs\n", encomp[3].ce, encomp[3].me, encomp[3].tempo);
	printf("Deletar no fim:        %d | %d | %fs\n", encomp[4].ce, encomp[4].me, encomp[4].tempo);
	printf("Deletar na posição N:  %d | %d | %fs\n", encomp[5].ce, encomp[5].me, encomp[5].tempo);
	printf("Procurar pelo RG:      %d | %d | %fs\n", encomp[6].ce, encomp[6].me, encomp[6].tempo);
	printf("Procurar pela posição: %d | %d | %fs\n", encomp[7].ce, encomp[7].me, encomp[7].tempo);
	printf("Mostrar lista:         %d | %d | %fs\n", encomp[8].ce, encomp[8].me, encomp[8].tempo);
	printf("Salvar arquivo:        %d | %d | %fs\n", encomp[9].ce, encomp[9].me, encomp[9].tempo);
	printf("Ler arquivo:           %d | %d | %fs\n", encomp[10].ce, encomp[10].me, encomp[10].tempo);
	printf("Apagar arquivo:        %d | %d | %fs\n", encomp[11].ce, encomp[11].me, encomp[11].tempo);
	printf("-----------------------------------------------------\n\n");
}



void apagarListaEncadeada(Encadeada **enc, Encadeada **primeiro, Encadeada **ultimo, EncadComp *encadcomp)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	*enc = *primeiro;
	encadcomp->me++;
	while(*enc!=NULL)
	{
		*primeiro = (*enc)->proximo;
		*enc = NULL;
		free(*enc);
		*enc = *primeiro;
		encadcomp->me=encadcomp->me+3;
		encadcomp->ce++;
	}
	encadcomp->ce++;
	*enc = NULL;
	*primeiro = NULL;
	*ultimo = NULL;
	encadcomp->me=encadcomp->me+3;
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
}