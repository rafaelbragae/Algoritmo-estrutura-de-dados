#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lower(char *a, int max){
  int i;
  if(max<strlen(a)){
    max = strlen(a);
  }
  for(i=0; i<20; i++){
    if(a[i]>64 && a[i]<91){
      a[i] = a[i]+32;
    }
    else if(a[i]<97 && a[i]>122){
      printf("Caracter não pertence a chave.");
    }
  }
  return max;
}

void space(char *a){
  int i;
  for(i=0; i<20; i++){
    if(a[i] == '\0'){
      a[i] = ' ';
    }
  }
}

void no_space(char *a){
  int i;
  for(i=0; i<20; i++){
    if(a[i] == ' '){
      a[i] = '\0';
    }
  }
}

// Função auxiliar para contar a frequência dos caracteres em uma determinada posição
void countSort(char **a, int n, int pos, char *chave) {
  int k=27;

  char **B = malloc(n * sizeof(char*));
  // Array de contagem para os caracteres
  int C[27] = {0};
  // Contando a frequência dos caracteres
  for (int i = 0; i < n; i++) {
    if(a[i][pos] == ' '){
      C[0]++;
    }
    else{
      int idx = strchr(chave, a[i][pos]) - chave;
      C[idx]++;
    }
  }

  // Transformando o array de contagem em um array de posição
  for (int i = 1; i < k; i++) {
    C[i] += C[i-1];
  }

  for (int i = 0; i < k; i++) {
    if(i == k-1 && pos != 0){
      printf("%d\n", C[i]);
    }
    else{
      printf("%d", C[i]);    
    }
  }

  // Ordenando as strings usando o array de posição
  for (int i = n-1; i >= 0; i--) {
    if(a[i][pos] == ' '){
      B[C[0]-1] = a[i];
      C[0]--;
    }
    else{
      int idx = strchr(chave, a[i][pos]) - chave;
      B[C[idx]-1] = a[i];
      C[idx]--;
    }
  }

    // Copiando o array ordenado de volta para o array original
  for (int i = 0; i < n; i++) {
    a[i] = B[i];
  }
  // Liberando a memória do array auxiliar
  free(B);
}

// Função principal para ordenação de strings com radix sort
void radixSortStrings(char **a, int n, int max, char *chave) {
  // Ordenando as strings começando pela posição mais à direita
  for (int pos = max-1; pos >= 0; pos--) {
    countSort(a, n, pos, chave);
  }
}

// Função de impressão de um array de strings
void printStringArray(char **a, int n) {
  for (int i = 0; i < n; i++) {
      printf("\n%s", a[i]);
  }
  printf("\n");
}

int main() {
  int num, i, max=0;
  char letras[26];
  
  scanf("%d", &num);

  for(i=0; i<=26; i++){
    scanf("%c", &letras[i]);
  }
  
  char **palavras = malloc(num * sizeof(char*));

  for (i = 0; i < num; i++) {
    palavras[i] = malloc(20 * sizeof(char));
    scanf("%s", palavras[i]);
    max = lower(palavras[i], max);
    printf("%s.\n", palavras[i]);
    space(palavras[i]);
  }
  
  printf("%d\n", max);
  
  radixSortStrings(palavras, num, max, letras);

  // for(i=0; i<num; i++){
  //   no_space(palavras[i]);
  // }

  printStringArray(palavras, num);

  return 0;
}
