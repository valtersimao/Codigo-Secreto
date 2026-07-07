//Valter dos Santos Simao Junior
//Mat: 26.1.4147

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> 

#include "Utilidades.h"
#include "Jogo.h"

void comoJogar();

void menu() {
    printf("-------------------------\n");
    printf(BOLD("   JOGO CÓDIGO SECRETO   ") "\n");
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
    op = toupper(op);

    switch (op)
    {
    case 'X': //TODO
        //sair
        break;
    case 'N':
        iniciarNovoJogo();
        break;
    case 'C':
        carregarArquivoJogo();
        //BUG BUG BUG ("")
        break;
    case 'S': //FEITO MAROMENOS
        //salvar
        //Fazer algum jeito de puxar o jogo atual
        break;    
    case 'R': //TODO
        //ranking
        break;
    case 'A': //TODO
        comoJogar();
        break;

    default: //caso insira nenhuma opção válida retorna para o inicio do menu
        printf("\n-------------------------\n");
        printf("Comando Inválido!\nTente novamente!\n");
        menu();
    }

}

void comoJogar() {
    printf("Fingir que ta ensinando a jogar \nbla bla blal \nlorum ispsdldfds lsaajff\n");
}

int main() { //FUNÇÃO ATÉ ENTÃO PARA TESTES
    menu();
    return 0;
}