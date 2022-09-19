#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
  int quantidade;
  int qtdF[MAX], qtdM[MAX];
  int Masculino;
  int Feminino;
  int Tamanho[MAX], Genero[MAX];
} Sapatos;

// Função para arredondamento do tamanho do sapato;
float Arredondamento(float valor, int quantidade) {
  int j;
  for (j = 0; j < quantidade; j++) {
    if ((valor - (int)valor) < 0.4) {
      valor = (int)valor;
    } else if ((valor - (int)valor) >= 0.4 && (valor - (int)valor) < 0.8) {
      valor = (int)valor + 0.5;
    } else if ((valor - (int)valor) >= 0.8) {
      valor = (int)valor + 1;
    }
  }
  return valor;
}

// Funções para converter o tamanho brasileiro para americano;
float ConversaoMasculina(int valor, int quantidade) {
  float conversao = 0, resultado;
  conversao = ((((valor * 6.67) + 19) / 25.4) * 3) - 24;
  resultado = Arredondamento(conversao, quantidade);
  return resultado;
}

float ConversaoFeminina(int valor, int quantidade) {
  float conversao = 0, resultado;
  conversao = ((((valor * 6.67) + 19) / 25.4) * 3) - 23;
  resultado = Arredondamento(conversao, quantidade);

  return resultado;
}

// Eliminação dos números repetidos;
float Eliminacao(int tam,float vetor[]){
  int i, j, k;
  for( i = 0; i < tam; i++ ){
    for( j = i + 1; j < tam; ){
      if( vetor[j] == vetor[i] ){
        for( k = j; k < tam; k++ )
          vetor[k] = vetor[k + 1];
            tam--;
          }
      else{
        j++;
      }}}}

// Código Principal;
int main(){
  float resultadoMasculino[MAX], resultadoFeminino[MAX];
  Sapatos sapato;
  int aux = 1;
  sapato.Masculino = 0;
  sapato.Feminino = 0;
  scanf("%d", &sapato.quantidade);

  int j = 0;
  while (j != sapato.quantidade) {
    scanf("%d", &sapato.Tamanho[j]);
    scanf("%d", &sapato.Genero[j]);
    j++;
  }
  
// Conversão dos tamanhos dos sapatos femininos;
  j = 0;
  int i = 0;
  while (j != sapato.quantidade) {
    if (sapato.Genero[j] == 1) {
      resultadoFeminino[i] = ConversaoFeminina(sapato.Tamanho[j], sapato.quantidade);
      i++;
      sapato.Feminino = sapato.Feminino+1;
    }
    j++;
  }
// Ordenação dos tamanhos dos sapatos femininos;
  float F[MAX];
  int maior, menor;
  maior = 0;
  for(i=0; i<sapato.Feminino; i++){
    if (resultadoFeminino[i] > resultadoFeminino[maior]){
      maior = i;
    }
  }
  for(j=0; j<sapato.Feminino;j++){
  menor = 0;
    for(i=0; i<sapato.Feminino; i++){
      if (resultadoFeminino[i] < resultadoFeminino[menor]){
        menor = i;
      }
    F[j]= resultadoFeminino[menor];
    }
  resultadoFeminino[menor] = resultadoFeminino[maior];
  }
// Eliminação dos sapatos femininos iguais;
  int k;
  for( k = 0; k < sapato.Feminino; k++){
      sapato.qtdF[k] = aux;
  }
  for( i = 0; i < sapato.Feminino ; i++ ){
    for( j = i + 1; j < sapato.Feminino; ){
      if( F[j] == F[i] ){
        for( k = j; k < sapato.Feminino; k++ )
          F[k] = F[k + 1];
          sapato.qtdF[k-2] = aux+1;
          sapato.Feminino--;
          }
      else{
        j++;
  }}}
// Print dos sapatos femininos;
  j = 0;
  while (j != sapato.quantidade) {
    if (sapato.Genero[j] == 1) {
      printf("F ");
      break;
    }
    j++;
  }
  for (k=0; k < sapato.Feminino; k++){
      printf("%.1f-(%i) ", F[k], sapato.qtdF[k]);
  }
  printf("\n");
// Conversão dos tamanhos dos sapatos masculinos;
  j = 0;
  i = 0;
  while (j != sapato.quantidade) {
    if (sapato.Genero[j] == 0) {
      resultadoMasculino[i] = ConversaoMasculina(sapato.Tamanho[j], sapato.quantidade);
      i++;
      sapato.Masculino = sapato.Masculino+1;
    }
    j++;
  }
// Ordenação dos tamanhos dos sapatos masculinos;
  float M[MAX];
  maior = 0;
    for(i=0; i<sapato.Masculino; i++){
      if (resultadoMasculino[i] > resultadoMasculino[maior]){
            maior = i;
      }
    }
    for(j=0; j<sapato.Masculino;j++){
    menor = 0;
      for(i=0; i<sapato.Masculino; i++){
        if (resultadoMasculino[i] < resultadoMasculino[menor]){
            menor = i;
        }
    M[j]= resultadoMasculino[menor];
      }
    resultadoMasculino[menor] = resultadoMasculino[maior];
    }
// Eliminação dos sapatos masculinos iguais;
  for( k = 0; k < sapato.Masculino; k++){
      sapato.qtdM[k] = aux;
  }
  for( i = 0; i < sapato.Masculino ; i++ ){
    for( j = i + 1; j < sapato.Masculino; ){
      if( M[j] == M[i] ){
        for( k = j; k < sapato.Masculino; k++ )
          M[k] = M[k + 1];
          sapato.qtdM[k-2] = aux+1;
          sapato.Masculino--;
        }
      else{
        j++;
  }}}
// Print dos sapatos masculinos;
  j = 0;
  while (j != sapato.quantidade) {
    if (sapato.Genero[j] == 0) {
      printf("M ");
      break;
    }
    j++;
  }
  for (k=0; k < sapato.Masculino; k++){
        printf("%.1f-(%i) ", M[k], sapato.qtdM[k]);
  }
}