//Valter dos Santos Sinão Júnior
//Mat: 26.1.4147

#ifndef RANKING_H 
#define RANKING_H

#define TAM 10
#define ARQ_RANKING "ranking.rnk"

typedef struct {
    char nome[51];
    int nivel;
    int tentativas; //caso seja -1 significa que não há valor;
} Ranking;

Ranking * carregarRanking();

void criarRankingNovo();

void salvarRanking(Ranking *r);

void exibirRanking(Ranking *r);

int atualizarRanking(Ranking *r, Ranking novo);

#endif