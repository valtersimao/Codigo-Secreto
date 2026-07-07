//Valter dos Santos Sinão Júnior
//Mat: 26.1.4147

#ifndef UTILIDADES_H
#define UTILIDADES_H

#define VERMELHO 1
#define AZUL 2
#define VERDE 3
#define AMARELO 4
#define ROXO 5
#define LARANJA 6

//CODIGO DISPONIBILIZADO PELOS PROFESSORES PARA CORES: -->
#define ANSI_RESET            "\x1b[0m"  
#define ANSI_BOLD             "\x1b[1m"  
#define ANSI_BG_COLOR_RED     "\x1b[41m"
#define ANSI_BG_COLOR_GREEN   "\x1b[42m"
#define ANSI_BG_COLOR_YELLOW  "\x1b[43m"
#define ANSI_BG_COLOR_BLUE    "\x1b[44m"
#define ANSI_BG_COLOR_MAGENTA "\x1b[45m"
#define ANSI_BG_COLOR_ORANGE "\x1B[48;2;255;128;0m"

#define BOLD(string)       ANSI_BOLD             string ANSI_RESET
#define BG_RED(string)     ANSI_BG_COLOR_RED     string ANSI_RESET
#define BG_GREEN(string)   ANSI_BG_COLOR_GREEN   string ANSI_RESET
#define BG_YELLOW(string)  ANSI_BG_COLOR_YELLOW  string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_MAGENTA(string) ANSI_BG_COLOR_MAGENTA string ANSI_RESET
#define BG_ORANGE(string)  ANSI_BG_COLOR_ORANGE  string ANSI_RESET
//<--

int verificarExistenciaNoVetor(int num, int vet[], int tam);

int ** criaMatriz(int n, int m);

int ** limpaMatriz(int **matriz, int n, int m);

#endif