//Valter dos Santos Simao Junior
//Mat: 26.1.4147

#include <stdio.h>
#include <string.h>

#define VERMELHO 1
#define AZUL 2
#define VERDE 3
#define AMARELO 4
#define ROXO 5
#define LARANJA 6

typedef struct {
    char nome[100];
    int dificuldade;
    int sequenciaCorreta[4];
    int numTentativas;
    int tentativas[8][8];

}Jogo; //jogo em uma struct

void salvarJogo(Jogo jogo) { //salvar jogo em um arquivo binario
    char nome[100];
    printf("Insira o nome do arquivo: ");
    scanf("%s", nome);

    strcat(nome, ".cor");

    FILE * arq = fopen(nome, "wb");

    fwrite(&jogo, sizeof(Jogo), 1, arq);
    fclose(arq);
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

void menu() {
    printf("-------------------------\n");
    printf("   JOGO CÓDIGO SECRETO   \n");
    printf("-------------------------\n");
    printf("MENU PRINCIPAL\n");
    printf("E   Sair\n");
    printf("N   Novo Jogo\n");
    printf("C   Carregar Jogo\n");
    printf("R   Ranking\n");
    printf("S   Salvar\n");
    printf("A   Ajuda\n");

    char op;
    printf("\nInsira o comando desejado: ");
    scanf(" %c", &op);

    switch (op)
    {
    case 'E':
        //sair
        break;
    case 'N':
        //novo jogo
        
        break;
    case 'C':
        //carregar jogo
        break;
    case 'R':
        //ranking
        break;
    case 'S':
        //salvar
        break;
    case 'A':
        //ajuda
        break;

    default: //caso insira nenhuma opção válida retorna para o inicio do menu
        printf("\n-------------------------\n");
        printf("Comando Inválido!\nTente novamente!\n");
        menu();
    }

}

int main() {
    menu();
    /*Jogo novo = {
        "Jogo 1",
        1,
        {VERDE, VERDE, VERMELHO, AZUL},
        3,
        {{AMARELO,VERDE,AZUL,AZUL},{VERDE,AZUL,AMARELO,VERMELHO},{AMARELO,VERMELHO,VERDE,AZUL}}
    };*/

    //Jogo novo = carregarJogo();
    //printf("%s\n%d\n", novo.nome, novo.dificuldade);

    /*for (int i = 0; i < novo.numTentativas; i++)
    {
        for (int j = 0; j < novo.dificuldade + 3; j++)
        {
            printf("[%d]", novo.tentativas[i][j]);
        }
        printf("\n");
        
    }*/
    
    //salvarJogo(novo);


    return 0;
}