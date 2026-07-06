//Valter dos Santos Sinão Júnior
//Mat: 26.1.4147
#include <stdbool.h>

#ifndef JOGO_H 
#define JOGO_H

typedef struct { //Salvar a quantidade de acertos e erros numa unica struct para facilitar a manipulação e no histórico
    int tamanho;
    int posicaoCerta;
    int posicaoErrada;
    int erros;
} Acertos;

typedef struct {
    char nome[100];
    int dificuldade;
    int tamSequencia;
    int * sequenciaCorreta;
    int tentativasMax;
    int numTentativas;
    int tentativas[100][100]; //TODO -> Alocar dinamicamente
    Acertos *historicoAcertos;
} Jogo; //jogo em uma struct

void salvarArquivoJogo(Jogo);

Jogo carregarArquivoJogo();

void iniciarNovoJogo();

Acertos verificaSequencia(Jogo);

bool verificaVitoria(Jogo);

bool verificaDerrota(Jogo);

//TODO criar funcao pra jogar de verdade

#endif
