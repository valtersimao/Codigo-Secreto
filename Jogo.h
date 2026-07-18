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
    char nome[51];
    int dificuldade;
    int tamSequencia;
    int * sequenciaCorreta;
    int tentativasMax;
    int numTentativas;
    int ** tentativas;
    Acertos *historicoAcertos;
} Jogo; //jogo em uma struct

int menu(Jogo *);

void verificaJogoEmAndamento(Jogo *);

void comoJogar();

void salvarJogo(Jogo);

void carregarJogo();

void iniciarNovoJogo();

Acertos verificaSequencia(Jogo, int i);

bool verificaVitoria(Jogo);

bool verificaDerrota(Jogo);

void imprimeCor(int);

void imprimeHistorico(Jogo);

void jogar(Jogo);

void finalizarJogo(Jogo);

void jogarNovamente();

#endif
