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

void salvarJogo(Jogo jogo) { //salvar jogo em um arquivo binario
    char nome[100];
    printf("Insira o nome do arquivo: ");
    scanf("%s", nome);

    strcat(nome, ".cor");

    FILE * arq = fopen(nome, "wb");
    fwrite(&jogo, sizeof(Jogo), 1, arq);
    fclose(arq);
    printf("Jogo salvo com sucesso!\n");
}

Jogo carregarJogo() { //ler um arquivo binario e retorna o jogo
    char nome[100];
    printf("Insira o nome do arquivo: ");
    scanf("%s", nome);

    strcat(nome, ".cor");

    FILE * arq = fopen(nome, "rb");

    if (arq == NULL) {
        printf("Arquivo inválido!");
        //return NULL;
    }

    Jogo jogo;
    fread(&jogo, sizeof(Jogo), 1, arq);
    fclose(arq);
    return jogo;
}

void iniciarNovoJogo() { //TODO
    Jogo jogo;
    srand(time(NULL));

    char nome[100]; //nome
    printf("Insira o nome do jogador: ");
    scanf("%s", nome);
    strcpy(jogo.nome,nome);

    int dificuldade; //dificuldade
    do{
        printf("\n DIFICULDADES: \n");
        printf("1 - Fácil (4 cores, 10 tentativas)\n");
        printf("2 - Médio (5 cores, 12 tentativas)\n");
        printf("3 - Difícil (6 cores, 15 tentativas)\n");
        printf("Escolha a dificuldade: ");
        scanf("%d", &dificuldade);
        if(dificuldade < 1 || dificuldade > 3)
            printf("\nValor inválido!\n");
    } while(dificuldade < 1 || dificuldade > 3);
    jogo.dificuldade = dificuldade;
    
    //alocar sequencia correta
    //Dificuldade varia de 1 a 3 e as cores de 4 a 6, logo cores = dificuldade + 3
    jogo.sequenciaCorreta = malloc((jogo.dificuldade + 3) * sizeof(int)); //PERGUNTAR: Uso (int *) (cast) ou nao?
    
    for (int i = 0; i < jogo.dificuldade + 3; i++)
    {
        jogo.sequenciaCorreta[i] = (rand() % 6) + 1;    
    }

    jogo.numTentativas = 0;

    //todo
    salvarJogo(jogo);

}

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