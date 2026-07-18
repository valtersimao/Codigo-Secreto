//Valter dos Santos Sinão Júnior
//Mat: 26.1.4147
#include <stdio.h>
#include <stdlib.h>

#include "Ranking.h"
#include "Utilidades.h"

Ranking * carregarRanking() {
    FILE * arq = fopen(ARQ_RANKING, "rb");

    if(arq == NULL) {
        criarRankingNovo();
        arq = fopen(ARQ_RANKING, "rb");
    }

    Ranking * ranking = malloc(sizeof(Ranking) * TAM);
    for (int i = 0; i < TAM; i++) {
        fread(&ranking[i], sizeof(Ranking),1, arq);
    }
    fclose(arq);
    return ranking;
}

void criarRankingNovo() { //caso não exista o ranking ele cria do 0
    FILE * arq = fopen(ARQ_RANKING,"wb");
    Ranking r;
    r.tentativas = -1;
    for (int i = 0; i < TAM; i++) {
        fwrite(&r, sizeof(Ranking), 1, arq);
    }
    
    fclose(arq);
}

void salvarRanking(Ranking * r) {
    FILE * arq = fopen(ARQ_RANKING,"wb");

    for (int i = 0; i < TAM; i++) {
        fwrite(&r[i],sizeof(Ranking),1,arq);
    }
    fclose(arq);
}

void exibirRanking(Ranking *r) {
    printf("\n-------------------------------------------------\n");
    printf(BOLD("                   RANKING") "\n");
    printf("-------------------------------------------------\n\n");
    printf(BOLD("Pos.\t%10s\tTent.\tDif.") "\n", "Nome");
    //printf("%s\t%2d\t%c\n", "valter", 2, 'f');
    for (int i = 0; i < TAM; i++) {
        printf("%2d\t", i+1);
        if(r[i].tentativas != -1) {
            printf("%10s\t%2d\t", r[i].nome, r[i].tentativas);
            char dif;
            switch (r[i].nivel) {
                case 1:
                    dif = 'F';
                    break;
                case 2:
                    dif = 'M';
                    break;
                case 3:
                    dif = 'D';
                    break;
            }
            printf("%c\n", dif);
        } else {
            printf("-----------------------------\n");
        }
    }
    
}

int atualizarRanking(Ranking *r, Ranking novo) {
    for(int i = 0; i < TAM; i++) {
        if (r[i].tentativas != -1) {
            if ((novo.tentativas < r[i].tentativas) //se for igual o numero de tentativas, o mais dificil fica a frente
             || (novo.tentativas == r[i].tentativas && novo.nivel > r[i].nivel)) {
                Ranking aux = r[i];
                r[i] = novo;
                atualizarRanking(r, aux); //ele realoca o item movido no ranking
                return (i+1);
            }
            
        } else {
            r[i] = novo;
            return (i+1);
        }
        
    }
    return -1;
    //caso não seja alocado em momento algum, significa que não está entre os 10 do ranking
}
