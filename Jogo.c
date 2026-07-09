//Valter dos Santos Sinão Júnior
//Mat: 26.1.4147

#include "Jogo.h"
#include "Utilidades.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int menu(Jogo * jogo) {
    /*A função vai retornar 1 quando for continuar algum jogo em andamento
     e 0 quando for parar o jogo em andamento*/
    printf("\n=================================================\n");
    printf(BOLD("                  CÓDIGO SECRETO") "\n");//
    printf("=================================================\n\n");

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
    case 'X':
        verificaJogoEmAndamento(jogo);
        printf("Tchau!\n");
        return 0;
        break;
    case 'N':
        verificaJogoEmAndamento(jogo);
        iniciarNovoJogo();
        return 0;
        break;
    case 'C':
        verificaJogoEmAndamento(jogo);
        carregarJogo();
        break;
    case 'S':
        if(jogo != NULL) {
            salvarJogo(*jogo);
            return 1;
        } else
            printf("Não existe jogo a ser salvo!");
        break;    
    case 'R': //TODO
        //ranking
        break;
    case 'A':
        comoJogar();
        return 1;
        break;

    default: //caso insira nenhuma opção válida retorna para o inicio do menu
        printf("\n-------------------------\n");
        printf("Comando Inválido!\nTente novamente!\n");
        return menu(jogo);
    }

}

void comoJogar() {
    printf("\n-------------------------------------------------\n");
    printf(BOLD("                 COMO JOGAR") "\n");
    printf("-------------------------------------------------\n\n");

    printf("OBJETIVO\n");
    printf("Descobrir a sequência secreta de cores antes que\n");
    printf("o número máximo de tentativas seja atingido.\n\n");

    printf("CORES DISPONÍVEIS\n");
    printf(BG_RED(" 1 - Vermelho ") "\n");
    printf(BG_BLUE(" 2 - Azul     ") "\n");
    printf(BG_GREEN(" 3 - Verde    ") "\n");
    printf(BG_YELLOW(" 4 - Amarelo  ") "\n");
    printf(BG_MAGENTA(" 5 - Roxo     ") "\n");
    printf(BG_ORANGE(" 6 - Laranja  ") "\n\n");

    printf("DIFICULDADES\n");
    printf("Fácil   : 4 cores e 10 tentativas.\n");
    printf("Médio   : 5 cores e 12 tentativas.\n");
    printf("Difícil : 6 cores e 15 tentativas.\n\n");

    printf("COMO JOGAR\n");
    printf("- Digite apenas os números correspondentes às cores.\n");
    printf("- Não existem cores repetidas na sequência secreta.\n");
    printf("- Após cada tentativa você receberá um resultado.\n\n");

    printf("SIGNIFICADO DOS RESULTADOS\n");
    printf(BG_GREEN(" C ") " = Cor correta na posição correta.\n");
    printf(BG_YELLOW(" E ") " = Cor correta na posição errada.\n");
    printf(BG_RED(" - ") " = Cor inexistente na sequência.\n\n");

    printf("EXEMPLO\n");
    printf("Sequência secreta: ");
    printf(BG_RED(" 1 "));
    printf(BG_GREEN(" 3 "));
    printf(BG_MAGENTA(" 5 "));
    printf(BG_BLUE(" 2 "));


    printf("\nSua tentativa    : ");
    printf(BG_RED(" 1 "));
    printf(BG_MAGENTA(" 5 "));
    printf(BG_YELLOW(" 4 "));
    printf(BG_BLUE(" 2 "));

    printf("\nResultado        : ");
    printf(BG_GREEN(" C "));
    printf(BG_GREEN(" C "));
    printf(BG_YELLOW(" E "));
    printf(BG_RED(" - "));
    printf("\n\n");

    printf("Nesse exemplo:\n");
    printf(BG_RED(" 1 ") " - está correto.\n");
    printf(BG_BLUE(" 2 ") " - está correto.\n");
    printf(BG_MAGENTA(" 5 ") " - existe, mas está na posição errada.\n");
    printf(BG_YELLOW(" 4 ") " - não pertence à sequência.\n\n");

    printf("DICA\n");
    printf("Durante uma partida digite ");
    printf(BG_BLACK(" -1 "));
    printf(" para abrir o menu.\n");

    printf("\nBoa sorte!\n");
    printf("-------------------------------------------------\n");
}

void verificaJogoEmAndamento(Jogo * jogo) {
    char op;
    if(jogo != NULL) {
        do{
            printf("Existe um jogo em andamento!\nVocê deseja salvar? (s/n) ");
            scanf(" %c", &op);
            op = toupper(op);
            if(op != 'S' && op != 'N')
                printf("Resposta Inválida!\n");
        } while (op != 'S' && op != 'N');      
            
        switch (op)
        {
            case 'S':
                salvarJogo(*jogo);
            case 'N':
                finalizarJogo(*jogo);
        }
    }
}

void salvarJogo(Jogo jogo) { //salvar jogo em um arquivo texto
    char nome[100];
    printf("Insira o nome do arquivo que deseja salvar: ");
    scanf("%s", nome);

    strcat(nome, ".cor");

    FILE * arq = fopen(nome, "w");

    fprintf(arq, "%s\n", jogo.nome);

    char dif;
    switch (jogo.dificuldade)
    {
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
    fprintf(arq, "%c\n", dif);

    for(int i = 0; i < jogo.tamSequencia; i++) {
        fprintf(arq, "%d ", jogo.sequenciaCorreta[i]);
    }


    fprintf(arq, "\n%d\n", jogo.numTentativas);
    for (int i = 0; i < jogo.numTentativas; i++)
    {
        for(int j = 0; j < jogo.tamSequencia; j++) {
            fprintf(arq, "%d ", jogo.tentativas[i][j]);
        }
        fprintf(arq,"\n");
    }
    
    fclose(arq);
    printf("Arquivo de jogo salvo com sucesso!\n");
}

void carregarJogo() { //ler um arquivo binario e retorna o jogo 
    //ta bugando em algo
    char nome[100];
    FILE * arq;

    do{
        printf("Insira o nome do arquivo do jogo: ");
        scanf("%s", nome);

        strcat(nome, ".cor");

        arq = fopen(nome, "r");

        if (arq == NULL) 
            printf("Arquivo inválido!");
    }while(arq == NULL);

    //realocar jogo
    Jogo jogo;
    fscanf(arq, "%s", jogo.nome);
    char dif;
    fscanf(arq, " %c", &dif);
    switch (dif)
    {
        case 'F':
            jogo.tentativasMax = 10;
            jogo.dificuldade = 1;
            break;
        case 'M':
            jogo.tentativasMax = 12;
            jogo.dificuldade = 2;
            break;
        case 'D':
            jogo.tentativasMax = 15;
            jogo.dificuldade = 3;
            break;
    }
    jogo.tamSequencia = jogo.dificuldade + 3; ///Dificuldade varia de 1 a 3 e as cores de 4 a 6, logo cores = dificuldade + 3
    
    jogo.tentativas = criaMatriz(jogo.tentativasMax, jogo.tamSequencia);
    //alocar dinamicamente a sequencia correta e o historico
    jogo.sequenciaCorreta = malloc((jogo.tamSequencia) * sizeof(int)); //PERGUNTAR: Uso (int *) (cast) ou nao?
    jogo.historicoAcertos = malloc((jogo.tentativasMax) * sizeof(Acertos));

    for (int i = 0; i < jogo.tamSequencia; i++) //preenche a sequencia
    {
        fscanf(arq, "%d", &jogo.sequenciaCorreta[i]);        
    }

    fscanf(arq, "%d", &jogo.numTentativas);
    for (int i = 0; i < jogo.numTentativas; i++) //preenchendo as tentativas e os acertos antigos
    {
        for (int j = 0; j < jogo.tamSequencia; j++)
        {
            fscanf(arq, "%d", &jogo.tentativas[i][j]);
        }
        jogo.historicoAcertos[i] = verificaSequencia(jogo, i);        
    }
    

    fclose(arq);
    printf("Arquivo carregado com sucesso!\n");
    imprimeHistorico(jogo);
    jogar(jogo);
}

void iniciarNovoJogo() {
    Jogo jogo;
    srand(time(NULL));

    printf("\n" BOLD("NOVO JOGO") "\n");

    char nome[100]; //nome
    printf("Insira o nome do jogador: ");
    scanf("%s", nome);
    strcpy(jogo.nome,nome);

    int dificuldade; //dificuldade
    do{
        printf("\n" BOLD("DIFICULDADE") "\n");
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

    switch (dificuldade) {
        case 1:
            jogo.tentativasMax = 10;
            break;
        case 2:
            jogo.tentativasMax = 12;
            break;
        case 3:
            jogo.tentativasMax = 15;
            break;
    }
    jogo.tentativas = criaMatriz(jogo.tentativasMax, jogo.tamSequencia);
    
    //alocar dinamicamente a sequencia correta e o historico
    jogo.sequenciaCorreta = malloc((jogo.tamSequencia) * sizeof(int)); //PERGUNTAR: Uso (int *) (cast) ou nao?
    jogo.historicoAcertos = malloc((jogo.tentativasMax) * sizeof(Acertos));

    for (int i = 0; i < jogo.tamSequencia; i++) //sorteia a sequencia
    {
        do{
            jogo.sequenciaCorreta[i] = (rand() % 6) + 1;
        } while (verificarExistenciaNoVetor(jogo.sequenciaCorreta[i], jogo.sequenciaCorreta, i) == 1);
        
    }

    jogo.numTentativas = 0;

    printf("\nNovo jogo criado! ");
    char op;
    do{
        printf("Você deseja salvá-lo em um arquivo antes de inicar? (s/n) ");
        scanf(" %c", &op);
        op = toupper(op);
        if(op != 'S' && op != 'N')
            printf("Resposta Inválida!\n");
    } while (op != 'S' && op != 'N');

    switch (op)
    {
        case 'S':
            salvarJogo(jogo);
        case 'N':
            jogar(jogo);
            break;
    }
}

Acertos verificaSequencia(Jogo jogo, int iTentativa) {
    Acertos acertos;
    acertos.tamanho = jogo.tamSequencia;
    acertos.posicaoCerta = 0;
    acertos.posicaoErrada = 0;

    for (int i = 0; i < (jogo.tamSequencia); i++)
    {
        //jogo.tentativas[jogo.numTentativas - 1] é a ultima tentativa tentada
        if(jogo.sequenciaCorreta[i] == jogo.tentativas[iTentativa][i]) {
            acertos.posicaoCerta++;
        } else if(verificarExistenciaNoVetor(jogo.sequenciaCorreta[i],
             jogo.tentativas[iTentativa], jogo.tamSequencia) == 1){
            acertos.posicaoErrada++;
        }
    }
    
    acertos.erros = acertos.tamanho - (acertos.posicaoCerta + acertos.posicaoErrada);

    return acertos;

}

bool verificaVitoria(Jogo jogo) {
    //se na ultima tentativa realizada do jogador tiver o tamanho maximo, entao ele acertou tudo e ganhou
    if(jogo.historicoAcertos[jogo.numTentativas - 1].posicaoCerta == jogo.tamSequencia)
        return true;
    else
        return false; //ainda na ganhou o jogo
}
bool verificaDerrota(Jogo jogo) {

    if (jogo.numTentativas >= jogo.tentativasMax)
        return true; //perdeu playboy
    else
        return false;
    
}

void imprimeCor(int cor) {
    switch (cor)
    {
        case VERMELHO:
            printf(" " BG_RED(" 1 ") " ");
            break;
        case AZUL:
            printf(" " BG_BLUE(" 2 ") " ");
            break;
        case VERDE:
            printf(" " BG_GREEN(" 3 ") " ");
            break;
        case AMARELO:
            printf(" " BG_YELLOW(" 4 ") " ");
            break;
        case ROXO:
            printf(" " BG_MAGENTA(" 5 ") " ");
            break;
        case LARANJA:
            printf(" " BG_ORANGE(" 6 ") " ");
            break;    
        default:
            break;
    }

}

void imprimeHistorico(Jogo jogo) {
    if(jogo.numTentativas > 0) {
        printf("\n" BOLD("Resultados:") "\n");
        for (int i = 0; i < jogo.numTentativas; i++)
        {
            printf("Rodada %2d: ", i+1);
            for (int j = 0; j < jogo.tamSequencia; j++)
                imprimeCor(jogo.tentativas[i][j]);

            printf(" -> (");
            for (int j = 0; j < jogo.historicoAcertos[i].posicaoCerta; j++) {
                printf(BG_GREEN(" C "));
            }

            for (int j = 0; j < jogo.historicoAcertos[i].posicaoErrada; j++) {
                printf(BG_YELLOW(" E "));
            }

            for (int j = 0; j < jogo.historicoAcertos[i].erros; j++) {
                printf(BG_RED(" - "));
            }
                
            printf(")\n");
        }
    }

}

void jogar(Jogo jogo) {
    printf("\nOlá %s! Vamos jogar!\n", jogo.nome);
    printf(BOLD("CORES DISPONÍVEIS:") "\n");

    printf(BG_RED(" 1 - Vermelho  ") "\n");
    printf(BG_BLUE(" 2 - Azul      ") "\n");
    printf(BG_GREEN(" 3 - Verde     ") "\n");
    printf(BG_YELLOW(" 4 - Amarelo   ") "\n");
    printf(BG_MAGENTA(" 5 - Roxo      ") "\n");
    printf(BG_ORANGE(" 6 - Laranja   ") "\n");
    printf(BG_BLACK("-1 - Menu      ") "\n");

    do{
        jogo.numTentativas++;

        printf("\nTentativa %d de %d\n", jogo.numTentativas, jogo.tentativasMax);
        printf("Digite %d cores: ", jogo.tamSequencia);

        for (int i = 0; i < jogo.tamSequencia; i++)
        {
            do {
                scanf("%d", &jogo.tentativas[jogo.numTentativas - 1][i]);
                if(jogo.tentativas[jogo.numTentativas - 1][i] == -1) { //abrir menu
                    jogo.numTentativas--;
                    printf("\n");
                    int op = menu(&jogo);
                    if (op == 1) { // continuar jogo
                        printf("\nVoltando para o jogo...\n");

                        imprimeHistorico(jogo);
                        jogo.numTentativas++;
                        
                        //repete o trem para voltar a opção do menu
                        printf("\nTentativa %d de %d\n", jogo.numTentativas, jogo.tentativasMax);
                        printf("Digite %d cores: ", jogo.tamSequencia);
                        scanf("%d", &jogo.tentativas[jogo.numTentativas - 1][i]);

                        if(jogo.tentativas[jogo.numTentativas - 1][i] > 6 || jogo.tentativas[jogo.numTentativas - 1][i] < 1)
                            printf("%d é um número inválido! Digite outra cor: ", jogo.tentativas[jogo.numTentativas - 1][i]);

                    } else if (op == 0) {
                        return;
                    }
                }
                else {
                    if(jogo.tentativas[jogo.numTentativas - 1][i] > 6 || jogo.tentativas[jogo.numTentativas - 1][i] < 1)
                        printf("%d é um número inválido!Digite outra cor: \n", jogo.tentativas[jogo.numTentativas - 1][i]);
                }
            } while(jogo.tentativas[jogo.numTentativas - 1][i] > 6 ||
                    jogo.tentativas[jogo.numTentativas - 1][i] < 1);
        }

        jogo.historicoAcertos[jogo.numTentativas - 1] = verificaSequencia(jogo, jogo.numTentativas - 1);
        
        imprimeHistorico(jogo);
    
        if(verificaVitoria(jogo)) {
            printf("Parabéns, %s! Você ganhou!\n",jogo.nome);
            return;
        }

    }while(!verificaDerrota(jogo));

    printf("Você excedeu o limite de tentativas!\nFim de jogo!\n");
    //mais algo pra fazer?
    return;


}

void finalizarJogo(Jogo jogo) { //desalocar vetores dinamicos
    free(jogo.sequenciaCorreta);
    free(jogo.historicoAcertos);
    limpaMatriz(jogo.tentativas, jogo.tentativasMax);
}