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

}Jogo;

void salvar(Jogo jogo) {
    char nome[100];
    printf("Insira o nome do arquivo: ");
    scanf("%s", nome);

    strcat(nome, ".cor");

    FILE * arq = fopen(nome, "wb");

    fwrite(&jogo, sizeof(Jogo), 1, arq);
    fclose(arq);


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

    default:
        printf("\n-------------------------\n");
        printf("Comando Inválido!\nTente novamente!\n");
        menu();
    }

}

int main() {
    //menu();
    Jogo novo = {
        "Jogo 1",
        1,
        {VERDE, VERDE, VERMELHO, AZUL},
        1,
        {AMARELO,VERDE,AZUL,AZUL}
    };

    salvar(novo);


    return 0;
}