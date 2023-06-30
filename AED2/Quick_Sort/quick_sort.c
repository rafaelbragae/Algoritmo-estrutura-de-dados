#include <stdio.h>
#include <stdlib.h>

int particao(int *chave, int primeiro, int ultimo){
  int pivo, i, j, aux;
  pivo = chave[ultimo];
  i = primeiro-1;
  for(j=primeiro; j<ultimo; j++){
    if(chave[j] < pivo){
      aux = chave[i+1];
      chave[i+1] = chave[j];
      chave[j] = aux;
      i++;
    }
  }
  aux = chave[i+1];
  chave[i+1] = chave[ultimo];
  chave[ultimo] = aux;
  return (i+1);
}

int particao_mediana(int *chave, int primeiro, int ultimo){
  int pivo, i, j, aux, b;
  b = (ultimo + primeiro)/2;
  if(chave[primeiro]>chave[b]){
    if(chave[primeiro]<chave[ultimo]){
      pivo = primeiro;
    }
    else if(chave[b]>chave[ultimo]){
      pivo = b;
    }
    else{
      pivo = ultimo;
    }
  }
  else{
    if(chave[b]<chave[ultimo]){
      pivo = b;
    }
    else if(chave[primeiro]>chave[ultimo]){
      pivo = primeiro;
    }
    else{
      pivo = ultimo;
    }
  }
  aux = chave[ultimo];
  chave[ultimo] = chave[pivo];
  chave[pivo] = aux;
  pivo = chave[ultimo];
  i = primeiro-1;
  for(j=primeiro; j<ultimo; j++){
    if(chave[j] < pivo){
      aux = chave[i+1];
      chave[i+1] = chave[j];
      chave[j] = aux;
      i++;
    }
  }
  aux = chave[i+1];
  chave[i+1] = chave[ultimo];
  chave[ultimo] = aux;
  return (i+1);
}

void quicksort(int *chave, int primeiro, int ultimo, int profundidade, int *prof, int tam){
  int pos_pivo, i;
  if(primeiro<ultimo){
    pos_pivo = particao(chave, primeiro, ultimo);
    quicksort(chave, primeiro, pos_pivo-1, profundidade+1, prof, tam);
    quicksort(chave, pos_pivo+1, ultimo, profundidade+1, prof, tam);
  }
  else{
    for(i=0; i<tam; i++){
      if(prof[i] == 0){
        prof[i] = profundidade;
        break;
      }
    }
  }
}

void quicksort_mediana(int *chave, int primeiro, int ultimo, int profundidade, int *prof, int tam){
  int pos_pivo, i;
  if(primeiro<ultimo){
    pos_pivo = particao_mediana(chave, primeiro, ultimo);
    quicksort_mediana(chave, primeiro, pos_pivo-1, profundidade+1, prof, tam);
    quicksort_mediana(chave, pos_pivo+1, ultimo, profundidade+1, prof, tam);
  }
  else{
    for(i=0; i<tam; i++){
      if(prof[i] == 0){
        prof[i] = profundidade;
        break;
      }
    }
  }
}

void analise(int *prof, int n){
  int i, max = prof[0], min = prof[0];
  for(i=1; i<n; i++){
    if(prof[i] != 0){
      if(prof[i]>max){
        max = prof[i];
      }
      else if(prof[i]<min){
        min = prof[i];
      }
    }
    else{
      break;
    }
  }
  printf("%d\n", max-min);
}

int main() {
    int n, i, profundidade=0;
    
    scanf("%d", &n);
    int chave[n];
    int chave2[n];
    int prof[n];
    for (i = 0; i < n; i++) {
      scanf("%d", &chave[i]);
      chave2[i] = chave[i];
      prof[i] = 0;
    }
    quicksort(chave, 0, n-1, profundidade, prof, n);
    analise(prof, n);
    profundidade = 0;
    for (i = 0; i < n; i++) {
      prof[i] = 0;
    }
    quicksort_mediana(chave2, 0, n-1, profundidade, prof, n);
    analise(prof, n);
}
