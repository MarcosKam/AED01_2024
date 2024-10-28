#include <stdio.h>

int sudoku[9][9];

int verificaLinha(int linha) {
    int numeros[10] = {0};

    for (int coluna = 0; coluna < 9; ++coluna) {
        int valor = sudoku[linha][coluna];
        if (numeros[valor]) {
            return 0;
        }
        numeros[valor] = 1;
    }

    return 1;
}

int verificaColuna(int coluna) {
    int numeros[10] = {0};

    for (int linha = 0; linha < 9; ++linha) {
        int valor = sudoku[linha][coluna];
        if (numeros[valor]) {
            return 0;
        }
        numeros[valor] = 1;
    }
    
    return 1;
}

int verificaQuadrado(int indiceQuadrado) {
    int numeros[10] = {0};
    int linhaInicial = 3 * (indiceQuadrado / 3);
    int colunaInicial = 3 * (indiceQuadrado % 3);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int valor = sudoku[linhaInicial + i][colunaInicial + j];
            if (numeros[valor]) {
                return 0;
            }
            numeros[valor] = 1;
        }
    }

    return 1;  // Quadrado válido
}

int main() {
    int numInstancias;
    scanf("%d", &numInstancias);

    for (int instancia = 1; instancia <= numInstancias; ++instancia) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        printf("Instancia %d\n", instancia);

        char* resposta = "SIM";
        for (int i = 0; i < 9; ++i) {
            if (!verificaLinha(i) || !verificaColuna(i) || !verificaQuadrado(i)) {
                resposta = "NAO";
                break;
            }
        }

        printf("%s\n\n", resposta);
    }

    return 0;
}