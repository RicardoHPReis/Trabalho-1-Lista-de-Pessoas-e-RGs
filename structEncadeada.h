struct Node
{
	char nome[20];
	int rg;
	struct Node *proximo;
};
typedef struct Node Encadeada;

Encadeada *enc, *primeiro, *ultimo;