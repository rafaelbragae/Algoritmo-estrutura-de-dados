#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qtd, i;
    int *N, *G;
    int max=100;
    int qtd_F[max],qtd_M[max];
    int numUSA_M[max],numUSA_F[max];

    scanf("%d", &qtd);
    if(qtd>=100){
        return 0;
    }

    /*N = (int *)malloc(qtd * sizeof(int));
    G = (int *)malloc(qtd * sizeof(int));*/
    for (i = 0; i < qtd; ++i) {
         scanf("%i %d", &N, &G);
         N[i] = N;
         G[i] = G;

    }
    for (i = 0; i < qtd; ++i) {
        printf("%i ", N[i]);
        printf("%d ", G[i]);
    }
    printf("\n");
    free(N);

    /*if(G==0){
        numUSA_M[max];
    }else{
        if(G==1)
            numUSA_F[max];
        else
            return 0;}

    printf("F %.1f-(%d) %.1f-(%d) %.1f-(%d) %.1f-(%d)\n", numUSA_F[0], qtd_F[0],numUSA_F[1], qtd_F[1], numUSA_F[2], qtd_F[2], numUSA_F[3], qtd_F[3]);
    printf("M %.1f-(%d) %.1f-(%d) %.1f-(%d) %.1f-(%d)", numUSA_M[0], qtd_M[0], numUSA_M[1],qtd_M[1], numUSA_M[2], qtd_M[2], numUSA_M[3], qtd_M[3]);*/
    return 0;
}
