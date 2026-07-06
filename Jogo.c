//Valter dos Santos Sinão Júnior
//Mat: 26.1.4147

#include "Jogo.h"
#include "Utilidades.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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
    jogo.tamSequencia = jogo.dificuldade + 3; ///Dificuldade varia de 1 a 3 e as cores de 4 a 6, logo cores = dificuldade + 3
    
    //alocar dinamicamente a sequencia correta e o historico
    jogo.sequenciaCorreta = malloc((jogo.tamSequencia) * sizeof(int)); //PERGUNTAR: Uso (int *) (cast) ou nao?
    jogo.historicoAcertos = malloc((jogo.tamSequencia) * sizeof(Acertos));

    for (int i = 0; i < jogo.tamSequencia; i++) //sorteia a sequencia
    {
        do{
            jogo.sequenciaCorreta[i] = (rand() % 6) + 1;
        } while (verificarExistenciaNoVetor(jogo.sequenciaCorreta[i], jogo.sequenciaCorreta, i) == 1);
        
    }

    jogo.numTentativas = 0;

    //todo
    salvarJogo(jogo);

}

Acertos verificaSequencia(Jogo jogo) {
    Acertos acertos;
    acertos.tamanho = jogo.tamSequencia;
    acertos.posicaoCerta = 0;
    acertos.posicaoErrada = 0;

    for (int i = 0; i < (jogo.tamSequencia); i++)
    {
        //jogo.tentativas[jogo.numTentativas - 1] é a ultima tentativa tentada
        if(jogo.sequenciaCorreta[i] == jogo.tentativas[jogo.numTentativas - 1][i]) {
            acertos.posicaoCerta++;
        } else if(verificarExistenciaNoVetor(jogo.sequenciaCorreta[i],
             jogo.tentativas[jogo.numTentativas - 1], jogo.tamSequencia) == 1){
            acertos.posicaoErrada++;
        }
    }
    
    acertos.erros = acertos.tamanho - (acertos.posicaoCerta + acertos.posicaoErrada);

    return acertos;

}
