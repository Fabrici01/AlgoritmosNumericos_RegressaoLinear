#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eliminacaoDeGauss.h"


int main()
{
    double idade[48] = {0}, carbono[48] = {0}, somaIdade = 0, somaCarbono =0, quadradoIdade =0, carbonoIdade=0, carbonoLog=0, carbonoLogIdade = 0, resul[2] = {0};
    FILE *arquivo = fopen("carbono14.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo");
        return 1;
    }
    for (int i = 0; i < 48; i++)
    {
        fscanf(arquivo, "%lf %lf", &idade[i], &carbono[i]);
        somaIdade += idade[i];
        somaCarbono += carbono[i];
        quadradoIdade += (idade[i]*idade[i]);
        carbonoIdade += (carbono[i]*idade[i]);
        carbonoLog += log(carbono[i]);
        carbonoLogIdade += log(carbono[i])*idade[i];
    }
    fclose(arquivo);

    double **A = malloc(sizeof(double)), B[2];
    for (int i = 0; i < 2; i++)
    {
     A[i] = malloc(sizeof(double));   
    }
    A[0][0] = 48;
    A[0][1] = somaIdade;
    A[1][0] = somaIdade;
    A[1][1] = quadradoIdade;
    B[0] = carbonoLog;
    B[1] = carbonoLogIdade;

    gaussEliminacaoPivotamento(2, A, B, resul);
    
    double resultado = 0;
    resultado = (log(53307321157) - resul[0])/resul[1];
    printf("\nResultado: %lf\n", resultado);
    return 0;
}