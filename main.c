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
#include "listaEncadeada.h"
#include "listaSequencial.h"
#include "configuracao.h"

int main(void)
{
	config.acao = 0;
	config.leuLista = 0;
	menudeSelecaoLista(&config);
	while(config.acao!=14)
	{
		menuDeSelecaoAcao(&config);
		switch(config.acao)
		{
			case 1:
			{
				if(config.leuLista!=1)
				{
					tipoDeErro(3);
					break;
				}

				menudeSelecaoNomeRG(&config);
				menudeSelecaoInserir();
				if(config.lista==1)
					inserirListaSequencialPrimeiro(&seq, &seqcomp[0], &config.tamanho, config.nome, config.rg);
				else if(config.lista==2)
					inserirListaEncadeadaPrimeiro(&enc, &primeiro, &encadcomp[0], &config.tamanho, config.nome, config.rg);
				else
				{
					printf("Sequencial:\n");
					inserirListaSequencialPrimeiro(&seq, &seqcomp[0], &config.tamanho, config.nome, config.rg);
					config.tamanho--;
					printf("\n\n\nEncadeada:\n");
					inserirListaEncadeadaPrimeiro(&enc, &primeiro, &encadcomp[0], &config.tamanho, config.nome, config.rg);
				}
				digiteAlgo();
				break;
			}
			case 2:
			{
				if(config.leuLista!=1)
				{
					tipoDeErro(3);
					break;
				}

				menudeSelecaoNomeRG(&config);
				menudeSelecaoInserir();
				if(config.lista==1)
					inserirListaSequencialUltimo(&seq, &seqcomp[1], &config.tamanho, config.nome, config.rg);
				else if(config.lista==2)
					inserirListaEncadeadaUltimo(&enc, &ultimo, &encadcomp[1], &config.tamanho, config.nome, config.rg);
				else
				{
					printf("Sequencial:\n");
					inserirListaSequencialUltimo(&seq, &seqcomp[1], &config.tamanho, config.nome, config.rg);
					config.tamanho--;
					printf("\n\n\nEncadeada:\n");
					inserirListaEncadeadaUltimo(&enc, &ultimo, &encadcomp[1], &config.tamanho, config.nome, config.rg);
				}
				digiteAlgo();
				break;
			}
			case 3:
			{
				if(config.leuLista!=1)
				{
					tipoDeErro(3);
					break;
				}
				
				menudeSelecaoPosicaoInserir(&config);
				menudeSelecaoNomeRG(&config);
				menudeSelecaoInserir();
				if(config.lista==1)
					inserirListaSequencialPosicao(&seq, &seqcomp[2], &config.tamanho, config.posicao, config.nome, config.rg);
				else if(config.lista==2)
					inserirListaEncadeadaPosicao(&enc, &primeiro, &ultimo, &encadcomp[2], &config.tamanho, config.posicao, config.nome, config.rg);
				else
				{
					printf("Sequencial:\n");
					inserirListaSequencialPosicao(&seq, &seqcomp[2], &config.tamanho, config.posicao, config.nome, config.rg);
					config.tamanho--;
					printf("\n\n\nEncadeada:\n");
					inserirListaEncadeadaPosicao(&enc, &primeiro, &ultimo, &encadcomp[2], &config.tamanho, config.posicao, config.nome, config.rg);
				}
				digiteAlgo();
				break;
			}
			case 4:
			{
				if(config.leuLista!=1)
				{
					tipoDeErro(3);
					break;
				}

				menudeSelecaoDeletar();
				if(config.lista==1)
					deletarListaSequencialPrimeiro(&seq, &seqcomp[3], &config.tamanho);
				else if(config.lista==2)
					deletarListaEncadeadaPrimeiro(&enc, &primeiro, &encadcomp[3], &config.tamanho);
				else
				{
					printf("Sequencial:\n");
					deletarListaSequencialPrimeiro(&seq, &seqcomp[3], &config.tamanho);
					config.tamanho++;
					printf("\n\n\nEncadeada:\n");
					deletarListaEncadeadaPrimeiro(&enc, &primeiro, &encadcomp[3], &config.tamanho);
				}
				digiteAlgo();
				break;
			}
			case 5:
			{
				if(config.leuLista!=1)
				{
					tipoDeErro(3);
					break;
				}

				menudeSelecaoDeletar();
				if(config.lista==1)
					deletarListaSequencialUltimo(&seq, &seqcomp[4], &config.tamanho);
				else if(config.lista==2)
					deletarListaEncadeadaUltimo(&enc, primeiro, &ultimo, &encadcomp[4], &config.tamanho);
				else
				{
					printf("Sequencial:\n");
					deletarListaSequencialUltimo(&seq, &seqcomp[4], &config.tamanho);
					config.tamanho++;
					printf("\n\n\nEncadeada:\n");
					deletarListaEncadeadaUltimo(&enc, primeiro, &ultimo, &encadcomp[4], &config.tamanho);
				}
				digiteAlgo();
				break;
			}
			case 6:
			{
				if(config.leuLista!=1)
				{
					tipoDeErro(3);
					break;
				}
				
				menudeSelecaoPosicao(&config);
				menudeSelecaoDeletar();
				if(config.lista==1)
					deletarListaSequencialPosicao(&seq, &seqcomp[5], &config.tamanho, config.posicao);
				else if(config.lista==2)
					deletarListaEncadeadaPosicao(&enc, &primeiro, &ultimo, &encadcomp[5], &config.tamanho, config.posicao);
				else
				{
					printf("Sequencial:\n");
					deletarListaSequencialPosicao(&seq, &seqcomp[5], &config.tamanho, config.posicao);
					config.tamanho++;
					printf("\n\n\nEncadeada:\n");
					deletarListaEncadeadaPosicao(&enc, &primeiro, &ultimo, &encadcomp[5], &config.tamanho, config.posicao);
				}
				digiteAlgo();
				break;
			}
			case 7:
			{
				if(config.leuLista!=1)
				{
					tipoDeErro(3);
					break;
				}
				
				menudeSelecaoRG(&config);
				menudeSelecaoProcurar();
				if(config.lista==1)
					procurarListaSequencialRG(seq, &seqcomp[6], config.rg, config.tamanho);
				else if(config.lista==2)
					procurarListaEncadeadaRG(enc, primeiro, ultimo, &encadcomp[6], config.rg);
				else
				{
					printf("Sequencial:\n");
					procurarListaSequencialRG(seq, &seqcomp[6], config.rg, config.tamanho);
					printf("\n\n\nEncadeada:\n");
					procurarListaEncadeadaRG(enc, primeiro, ultimo, &encadcomp[6], config.rg);
				}
				digiteAlgo();
				break;
			}
			case 8:
			{
				if(config.leuLista!=1)
				{
					tipoDeErro(3);
					break;
				}
				
				menudeSelecaoPosicao(&config);
				menudeSelecaoProcurar();
				if(config.lista==1)
					procurarListaSequencialPosicao(seq, &seqcomp[7], config.posicao);
				else if(config.lista==2)
					procurarListaEncadeadaPosicao(enc, primeiro, ultimo, &encadcomp[7], config.tamanho, config.posicao);
				else
				{
					printf("Sequencial:\n");
					procurarListaSequencialPosicao(seq, &seqcomp[7], config.posicao);
					printf("\n\n\nEncadeada:\n");
					procurarListaEncadeadaPosicao(enc, primeiro, ultimo, &encadcomp[7], config.tamanho, config.posicao);
				}
				digiteAlgo();
				break;
			}	
			case 9:
			{
				if(config.leuLista!=1)
				{
					tipoDeErro(3);
					break;
				}
				
				aparenciaLista();
				if(config.lista==1)
					mostrarListaSequencial(seq, &seqcomp[8], config.tamanho);
				else if(config.lista==2)
					mostrarListaEncadeada(enc, primeiro, &encadcomp[8]);
				else
				{
					mostrarListaSequencial(seq, &seqcomp[8], config.tamanho);
					printf("\n\n\nEncadeada:\n");
					mostrarListaEncadeada(enc, primeiro, &encadcomp[8]);
				}
				digiteAlgo();
				break;
			}
			case 10:
			{
				if(config.leuLista!=1)
				{
					tipoDeErro(3);
					break;
				}
				
				menudeSelecaoSalvar(&config);
				if(config.lista==1)
					salvarListaSequencial(seq, &seqcomp[9], config.arqSalvo, config.tamanho);
				else if(config.lista==2)
					salvarListaEncadeada(enc, primeiro, &encadcomp[9], config.arqSalvo);
				else
				{
					printf("Sequencial:\n");
					strcpy(config.arqSalvo, "sequencial.txt");
					salvarListaSequencial(seq, &seqcomp[9], config.arqSalvo, config.tamanho);
					printf("\n\n\nEncadeada:\n");
					strcpy(config.arqSalvo, "encadeada.txt");
					salvarListaEncadeada(enc, primeiro, &encadcomp[9], config.arqSalvo);
				}
				digiteAlgo();
				break;
			}
			case 11:
			{
				menudeSelecaoArquivo(&config);
				contadorLista(&config);
				menudeSelecaoLer();
				if(config.leuLista==1)
				{
					if(config.lista==1)
						apagarListaSequencial(&seq, &seqcomp[11]);
					else if(config.lista==2)
						apagarListaEncadeada(&enc, &primeiro, &ultimo, &encadcomp[11]);
					else
					{
						apagarListaSequencial(&seq, &seqcomp[11]);
						apagarListaEncadeada(&enc, &primeiro, &ultimo, &encadcomp[11]);
					}
				}
				
				if(config.lista==1)
					lerListaSequencial(&seq, &seqcomp[10], config.nomeArquivo, config.tamanho);
				else if(config.lista==2)
					lerListaEncadeada(&enc, &primeiro, &ultimo, &encadcomp[10], config.nomeArquivo);
				else
				{
					printf("Sequencial:\n");
					lerListaSequencial(&seq, &seqcomp[10], config.nomeArquivo, config.tamanho);
					printf("\n\nEncadeada:\n");
					lerListaEncadeada(&enc, &primeiro, &ultimo, &encadcomp[10], config.nomeArquivo);
				}
				config.leuLista=1;
				digiteAlgo();
				break;
			}
			case 12:
			{
				aparenciaMenu();
				if(config.lista==1)
					comparacoesListaSequencial(seqcomp);
				else if(config.lista==2)
					comparacoesListaEncadeada(encadcomp);
				else
				{
					comparacoesListaSequencial(seqcomp);
					printf("\n\n\n");
					comparacoesListaEncadeada(encadcomp);
				}
				digiteAlgo();
				break;
			}
			case 13:
			{
				explicacaoPrograma();
				break;
			}
			case 14:
			{
				if(config.lista==1)
					apagarListaSequencial(&seq, &seqcomp[11]);
				else if(config.lista==2)
					apagarListaEncadeada(&enc, &primeiro, &ultimo, &encadcomp[11]);
				else
				{
					apagarListaSequencial(&seq, &seqcomp[11]);
					apagarListaEncadeada(&enc, &primeiro, &ultimo, &encadcomp[11]);
				}
				fimDoPrograma();
				break;
			}
		}
	}
	system(LIMPA);
}