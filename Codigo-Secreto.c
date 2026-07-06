//Valter dos Santos Simao Junior
//Mat: 26.1.4147

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "Jogo.h"

#define VERMELHO 1
#define AZUL 2
#define VERDE 3
#define AMARELO 4
#define ROXO 5
#define LARANJA 6

void menu() {
    printf("-------------------------\n");
    printf("   JOGO CÓDIGO SECRETO   \n");
    printf("-------------------------\n");
    printf("MENU PRINCIPAL\n");
    printf("X   Sair\n");
    printf("N   Novo Jogo\n");
    printf("C   Carregar Jogo\n");
    printf("S   Salvar\n");
    printf("R   Ranking\n");
    printf("A   Ajuda\n");

    char op;
    printf("\nInsira o comando desejado: ");
    scanf(" %c", &op);

    switch (op)
    {
    case 'X': //TODO
        //sair
        break;
    case 'N': //DOING
        iniciarNovoJogo();
        break;
    case 'C': //FEITO PELA METADE
        //carregar jogo
        //criar a struct do Jogo com o arquivo carregado e continuar de onde parou
        break;
    case 'S': //FEITO MAROMENOS
        //salvar
        //Fazer algum jeito de puxar o jogo atual
        break;    
    case 'R': //TODO
        //ranking
        break;
    case 'A': //TODO
        //ajuda
        break;

    default: //caso insira nenhuma opção válida retorna para o inicio do menu
        printf("\n-------------------------\n");
        printf("Comando Inválido!\nTente novamente!\n");
        menu();
    }

}

int main() { //FUNÇÃO ATÉ ENTÃO PARA TESTES
    //menu();
    /*Jogo novo = {
        "Jogo 1",
        1,
        {VERDE, VERDE, VERMELHO, AZUL},
        3,
        {{AMARELO,VERDE,AZUL,AZUL},{VERDE,AZUL,AMARELO,VERMELHO},{AMARELO,VERMELHO,VERDE,AZUL}}
    };*/
    iniciarNovoJogo();

    Jogo novo = carregarJogo();
    printf("%s\n%d\n", novo.nome, novo.dificuldade);

    for (int i = 0; i < novo.dificuldade + 3; i++)
    {
        printf("[%d]", novo.sequenciaCorreta[i]);        
    }
    printf("\n");
    
    //salvarJogo(novo);


    return 0;
}