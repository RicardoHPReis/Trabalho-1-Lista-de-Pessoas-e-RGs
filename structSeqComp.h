#include <time.h>

typedef struct
{
	int ms, cs; //movimentacoes, comparacoes
	struct timespec comeco, fim;
	double tempo;
}SeqComp;

SeqComp seqcomp[12];