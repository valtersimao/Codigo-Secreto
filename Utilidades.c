//Valter dos Santos Sinão Júnior
//Mat: 26.1.4147

#include "Utilidades.h"

int verificarExistenciaNoVetor(int num, int vet[], int tam) {
    //caso o numero exista no vetor retorna 1, se nao 0;
    //utilizo em algumas partes do codigo para evitar repetições
    if(tam > 0) { //evita bug, se o tamanho é 0 logo não existe no vetor
        for (int i = 0; i < tam; i++)
        {
            if (vet[i] == num)
                return 1;
        }
    }
    return 0;
    
}