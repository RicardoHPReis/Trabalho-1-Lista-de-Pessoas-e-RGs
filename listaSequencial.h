#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#ifdef _WIN32
    #include <windows.h>
    #define LIMPA "cls"
#else
    #include <unistd.h>
    #define LIMPA "clear"
#endif
#include "structSequencial.h"
#include "structSeqComp.h"


void inserirListaSequencialPrimeiro(Sequencial **seq, SeqComp *seqcomp, int *tamanho, char *nome, int rg)
{
	seqcomp->ms=0;
	seqcomp->cs=0;
	clock_gettime(CLOCK_REALTIME, &seqcomp->comeco);
	(*tamanho)++;
	*seq = (Sequencial*) realloc (*seq, (*tamanho)*sizeof(Sequencial));
	seqcomp->ms=seqcomp->ms+2;
	printf("\nInserindo em...\n%d| %s,%08d", 1, nome, rg);
	for(int a=(*tamanho)-1; a>=1; a--)
	{
		(*seq)[a]=(*seq)[a-1];
		seqcomp->ms++;
		seqcomp->cs++;
	}
	seqcomp->cs++;
	strcpy((*seq)[0].nome,nome);
	(*seq)[0].rg = rg;
	seqcomp->ms=seqcomp->ms+3;
	printf("\n\nRegistro incluído no início da lista.");
	
    clock_gettime(CLOCK_REALTIME, &seqcomp->fim);
    seqcomp->tempo = (seqcomp->fim.tv_sec-seqcomp->comeco.tv_sec) + (seqcomp->fim.tv_nsec-seqcomp->comeco.tv_nsec)/1000000000.0;
}



void inserirListaSequencialUltimo(Sequencial **seq, SeqComp *seqcomp, int *tamanho, char *nome, int rg)
{
	seqcomp->ms=0;
	seqcomp->cs=0;
	clock_gettime(CLOCK_REALTIME, &seqcomp->comeco);
	(*tamanho)++;
	*seq = (Sequencial*) realloc (*seq, (*tamanho)*sizeof(Sequencial));
	printf("\nInserindo em...\n%d| %s,%08d", (*tamanho), nome, rg);
	strcpy((*seq)[*tamanho-1].nome,nome);
	(*seq)[*tamanho-1].rg = rg;
	seqcomp->ms=seqcomp->ms+4;
	printf("\n\nRegistro incluído no final da lista.");
	
    clock_gettime(CLOCK_REALTIME, &seqcomp->fim);
    seqcomp->tempo = (seqcomp->fim.tv_sec-seqcomp->comeco.tv_sec) + (seqcomp->fim.tv_nsec-seqcomp->comeco.tv_nsec)/1000000000.0;
}


//////// 1°
void inserirListaSequencialPosicao(Sequencial **seq, SeqComp *seqcomp, int *tamanho, int posicao, char *nome, int rg)
{
	seqcomp->ms=0;
	seqcomp->cs=0;
	clock_gettime(CLOCK_REALTIME, &seqcomp->comeco);
	int encontrou=0;
	(*tamanho)++;
	*seq = (Sequencial*) realloc (*seq, (*tamanho)*sizeof(Sequencial));
	seqcomp->ms = seqcomp->ms+3;
	printf("\nInserindo em...\n%d| %s,%08d", posicao, nome, rg);
	if(posicao==1)
	{
		for(int b=(*tamanho)-1; b>=1; b--)
		{
			(*seq)[b]=(*seq)[b-1];
			seqcomp->ms++;
			seqcomp->cs++;
		}
		seqcomp->cs++;
		strcpy((*seq)[0].nome,nome);
		(*seq)[0].rg = rg;
		seqcomp->ms=seqcomp->ms+3;
	}
	else
	{
		for(int b=(*tamanho)-1; encontrou!=1; b--)
		{
			if(b==posicao-1)
			{
				(*seq)[b]=(*seq)[b-1];
				strcpy((*seq)[b].nome,nome);
				(*seq)[b].rg = rg;
				encontrou=1;
				seqcomp->ms=seqcomp->ms+4;
			}
			else if(b>posicao-1)
			{
				(*seq)[b]=(*seq)[b-1];
				seqcomp->ms++;
			}
			seqcomp->cs=seqcomp->cs+3;
		}
		seqcomp->cs++;
	}
	seqcomp->cs=seqcomp->cs+2;
	printf("\n\nRegistro incluído na %d° posição.", posicao);
	
    clock_gettime(CLOCK_REALTIME, &seqcomp->fim);
    seqcomp->tempo = (seqcomp->fim.tv_sec-seqcomp->comeco.tv_sec) + (seqcomp->fim.tv_nsec-seqcomp->comeco.tv_nsec)/1000000000.0;
}



void deletarListaSequencialPrimeiro(Sequencial **seq, SeqComp *seqcomp, int *tamanho)
{
	seqcomp->ms=0;
	seqcomp->cs=0;
	clock_gettime(CLOCK_REALTIME, &seqcomp->comeco);
	char buffer[200];
	(*tamanho)--;
	seqcomp->ms++;
	printf("\nDeletando...\n%d| %s,%08d", 1, (*seq)[0].nome, (*seq)[0].rg);
	for(int c=0; c<(*tamanho); c++)
	{
		(*seq)[c]=(*seq)[c+1];
		seqcomp->ms++;
		seqcomp->cs++;
	}
	seqcomp->cs++;
	seqcomp->ms++;
	*seq = (Sequencial*) realloc (*seq, (*tamanho)*sizeof(Sequencial));
	printf("\n\nPrimeiro registro excluído.");
	
    clock_gettime(CLOCK_REALTIME, &seqcomp->fim);
    seqcomp->tempo = (seqcomp->fim.tv_sec-seqcomp->comeco.tv_sec) + (seqcomp->fim.tv_nsec-seqcomp->comeco.tv_nsec)/1000000000.0;
}



void deletarListaSequencialUltimo(Sequencial **seq, SeqComp *seqcomp, int *tamanho)
{
	clock_gettime(CLOCK_REALTIME, &seqcomp->comeco);
	(*tamanho)--;
	seqcomp->ms++;
	printf("\nDeletando...\n%d| %s,%08d", (*tamanho)+1, (*seq)[(*tamanho)].nome, (*seq)[(*tamanho)].rg);
	*seq = (Sequencial*) realloc (*seq, (*tamanho)*sizeof(Sequencial));
	seqcomp->ms++;
	printf("\n\nÚltimo registro excluído.");
	
    clock_gettime(CLOCK_REALTIME, &seqcomp->fim);
    seqcomp->tempo = (seqcomp->fim.tv_sec-seqcomp->comeco.tv_sec) + (seqcomp->fim.tv_nsec-seqcomp->comeco.tv_nsec)/1000000000.0;
}



void deletarListaSequencialPosicao(Sequencial **seq, SeqComp *seqcomp, int *tamanho, int posicao)
{
	seqcomp->ms=0;
	seqcomp->cs=0;
	clock_gettime(CLOCK_REALTIME, &seqcomp->comeco);
	(*tamanho)--;
	seqcomp->ms++;
	printf("\nDeletando...\n%d| %s,%08d", posicao, (*seq)[posicao-1].nome, (*seq)[posicao-1].rg);
	for(int d=0; d<(*tamanho); d++)
	{
		if(d>=posicao-1)
		{
			(*seq)[d]=(*seq)[d+1];
			seqcomp->ms++;
		}
		seqcomp->cs=seqcomp->cs+2;
	}
	seqcomp->cs++;
	seqcomp->ms++;
	*seq = (Sequencial*) realloc (*seq, (*tamanho)*sizeof(Sequencial));
	printf("\n\n%d° registro excluído.", posicao);
	
    clock_gettime(CLOCK_REALTIME, &seqcomp->fim);
    seqcomp->tempo = (seqcomp->fim.tv_sec-seqcomp->comeco.tv_sec) + (seqcomp->fim.tv_nsec-seqcomp->comeco.tv_nsec)/1000000000.0;
}



void procurarListaSequencialRG(Sequencial *seq, SeqComp *seqcomp, int rg, int tamanho)
{
	seqcomp->ms=0;
	seqcomp->cs=0;
	clock_gettime(CLOCK_REALTIME, &seqcomp->comeco);
	int encontrou=0;
	seqcomp->ms++;
	seqcomp->cs++;
	for(int e=0; e<tamanho && encontrou==0; e++)
	{
		if(seq[e].rg==rg)
		{
			printf("RG encontrado!!\n");
			printf("%d| %s,%08d", e+1, seq[e].nome, seq[e].rg);
			encontrou=1;
			seqcomp->ms++;
			
		}
		seqcomp->cs=seqcomp->cs+2;
	}
	seqcomp->cs++;
	if(encontrou!=1)
		printf("RG não encontrado");
	
    clock_gettime(CLOCK_REALTIME, &seqcomp->fim);
    seqcomp->tempo = (seqcomp->fim.tv_sec-seqcomp->comeco.tv_sec) + (seqcomp->fim.tv_nsec-seqcomp->comeco.tv_nsec)/1000000000.0;
}


void procurarListaSequencialPosicao(Sequencial *seq, SeqComp *seqcomp, int posicao)
{
	seqcomp->ms=0;
	seqcomp->cs=0;
	clock_gettime(CLOCK_REALTIME, &seqcomp->comeco);
	printf("%d| %s,%08d", posicao, seq[posicao-1].nome, seq[posicao-1].rg);
	
    clock_gettime(CLOCK_REALTIME, &seqcomp->fim);
    seqcomp->tempo = (seqcomp->fim.tv_sec-seqcomp->comeco.tv_sec) + (seqcomp->fim.tv_nsec-seqcomp->comeco.tv_nsec)/1000000000.0;
}



void mostrarListaSequencial(Sequencial *seq, SeqComp *seqcomp, int tamanho)
{
	seqcomp->ms=0;
	seqcomp->cs=0;
	clock_gettime(CLOCK_REALTIME, &seqcomp->comeco);
	for(int f=0; f<tamanho; f++)
	{
		printf("\n%d| %s,%08d", f+1, seq[f].nome, seq[f].rg);
		seqcomp->cs++;
	}
	seqcomp->cs++;
	printf("\n\n--- FIM DA LISTA ---\n\n");
    clock_gettime(CLOCK_REALTIME, &seqcomp->fim);
    seqcomp->tempo = (seqcomp->fim.tv_sec-seqcomp->comeco.tv_sec) + (seqcomp->fim.tv_nsec-seqcomp->comeco.tv_nsec)/1000000000.0;
}



void salvarListaSequencial(Sequencial *seq, SeqComp *seqcomp, char *arqSalvo, int tamanho)
{
	seqcomp->ms=0;
	seqcomp->cs=0;
	clock_gettime(CLOCK_REALTIME, &seqcomp->comeco);
	FILE *arquivo;
	arquivo = fopen(arqSalvo, "w");
	seqcomp->ms++;
	for(int g=0; g<tamanho; g++)
	{
		fprintf(arquivo, "%s,%08d\n", seq[g].nome, seq[g].rg);
		seqcomp->cs++;
	}
	seqcomp->cs++;
	fclose(arquivo);
	printf("\nArquivo salvo!");
    clock_gettime(CLOCK_REALTIME, &seqcomp->fim);
    seqcomp->tempo = (seqcomp->fim.tv_sec-seqcomp->comeco.tv_sec) + (seqcomp->fim.tv_nsec-seqcomp->comeco.tv_nsec)/1000000000.0;
}



void lerListaSequencial(Sequencial **seq, SeqComp *seqcomp, char *nomeArquivo, int tamanho)
{
	seqcomp->ms=0;
	seqcomp->cs=0;
	clock_gettime(CLOCK_REALTIME, &seqcomp->comeco);
	FILE *arquivo;
	int linha=0, rg;
	char *token, buffer[200];
	arquivo = fopen(nomeArquivo, "r");
	seqcomp->ms++;
	
	if(!arquivo)
	{
		perror("Não foi possível achar o arquivo");
		exit(1);
	}
	seqcomp->cs++;

	seqcomp->ms++;
	*seq = (Sequencial*) malloc ((tamanho)*sizeof(Sequencial));
	if(!*seq)
	{
		printf("Não há espaço na memória!\n");
		exit(1);
	}
	seqcomp->cs++;
	
	while (fgets(buffer, 200, arquivo)) 
	{	
		token = strtok(buffer, ",");
		rg = atoi(strtok(NULL, "\n"));
		strcpy((*seq)[linha].nome, token);
		(*seq)[linha].rg = rg;
		linha++;
		seqcomp->ms=seqcomp->ms+5;
		seqcomp->cs++;
	}
	fclose(arquivo);
	printf("%d nomes e RGs lidos!\n", linha);
	clock_gettime(CLOCK_REALTIME, &seqcomp->fim);
    seqcomp->tempo = (seqcomp->fim.tv_sec-seqcomp->comeco.tv_sec) + (seqcomp->fim.tv_nsec-seqcomp->comeco.tv_nsec)/1000000000.0;
}



void comparacoesListaSequencial(SeqComp *seqcomp)
{
	printf("Lista Sequencial\n");
	printf("---------------------------------------------\n\n");
	printf("Comparações | Movimentações | Tempo\n\n");
	printf("Inserir no início:     %d | %d | %fs\n", seqcomp[0].cs, seqcomp[0].ms, seqcomp[0].tempo);
	printf("Inserir no fim:        %d | %d | %fs\n", seqcomp[1].cs, seqcomp[1].ms, seqcomp[1].tempo);
	printf("Inserir na posição N:  %d | %d | %fs\n", seqcomp[2].cs, seqcomp[2].ms, seqcomp[2].tempo);
	printf("Deletar no início:     %d | %d | %fs\n", seqcomp[3].cs, seqcomp[3].ms, seqcomp[3].tempo);
	printf("Deletar no fim:        %d | %d | %fs\n", seqcomp[4].cs, seqcomp[4].ms, seqcomp[4].tempo);
	printf("Deletar na posição N:  %d | %d | %fs\n", seqcomp[5].cs, seqcomp[5].ms, seqcomp[5].tempo);
	printf("Procurar pelo RG:      %d | %d | %fs\n", seqcomp[6].cs, seqcomp[6].ms, seqcomp[6].tempo);
	printf("Procurar pela posição: %d | %d | %fs\n", seqcomp[7].cs, seqcomp[7].ms, seqcomp[7].tempo);
	printf("Mostrar lista:         %d | %d | %fs\n", seqcomp[8].cs, seqcomp[8].ms, seqcomp[8].tempo);
	printf("Salvar arquivo:        %d | %d | %fs\n", seqcomp[9].cs, seqcomp[9].ms, seqcomp[9].tempo);
	printf("Ler arquivo:           %d | %d | %fs\n", seqcomp[10].cs, seqcomp[10].ms, seqcomp[10].tempo);
	printf("Apagar arquivo:        %d | %d | %fs\n", seqcomp[11].cs, seqcomp[11].ms, seqcomp[11].tempo);
	printf("---------------------------------------------\n\n");
}


void apagarListaSequencial(Sequencial **seq, SeqComp *seqcomp)
{
	seqcomp->ms=0;
	seqcomp->cs=0;
	clock_gettime(CLOCK_REALTIME, &seqcomp->comeco);
	free((*seq));
	seqcomp->ms++;
	clock_gettime(CLOCK_REALTIME, &seqcomp->fim);
    seqcomp->tempo = (seqcomp->fim.tv_sec-seqcomp->comeco.tv_sec) + (seqcomp->fim.tv_nsec-seqcomp->comeco.tv_nsec)/1000000000.0;
}