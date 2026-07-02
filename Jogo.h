#ifndef JOGO_H 
#define JOGO_H

typedef struct {
    char nome[100];
    int dificuldade;
    int * sequenciaCorreta;
    int numTentativas;
    int tentativas[8][8];

}Jogo; //jogo em uma struct

#endif
