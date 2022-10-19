#include <time.h>

typedef struct
{
	int me, ce; //movimentacoes, comparacoes
	struct timespec comeco, fim;
	double tempo;
}EncadComp;

EncadComp encadcomp[12];