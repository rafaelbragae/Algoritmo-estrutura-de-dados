#include <stdio.h>
#include <stdlib.h>


//lista ordanada
void order(int *vet, int tam){
  int aux, i, j;
  for(i=0; i<tam; i++){
    for(j=0; j<tam; j++){
      if (vet[i] < vet[j]){
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
      }
    }
  }
}

//Busca Binária recursiva
// int busca_merge(int *vet, int inicio, int fim, int tam, int find, int count){
//   int i, meio_num=0;
//   tam = fim-inicio;
//   int meio = (tam/2);
  
//   if (meio%2 == 0 && meio!=0){
//     meio_num = vet[meio-1];
//   }
//   else{
//     meio_num = vet[meio];
//   }
//   tam = tam/2;
  
//   if (meio_num == find){
//     printf("%d", count);
//     return 0;
//   }
//   if(tam == 1){
//     if (inicio!=find || fim!=find){
//       printf("%d nao foi encontrado", find);
//       return 0;
//     }
//   }
//   if(inicio == fim){
//     printf("%d nao foi encontrado", find);
//     return 0;
//   }
//   if (find > meio_num) {
//     for(i=0; i<tam; i++){
//       meio++;
//       vet[i] = vet[meio];
//     }
//     count++;
//     busca_merge(vet, vet[tam+2], fim, tam, find, count);
//   }
//   else{
//     count++;
//     busca_merge(vet, inicio, vet[tam-2], tam, find, count);
//   }
//   return 0;
// }

int busca(int *vet, int inicio, int fim, int find, int count){
  int meio;
  if(inicio > fim){
    return -1;
  }

  meio = (inicio+fim)/2;

  if(vet[meio] == find){
    return printf("%d", count);
  }
  else if(find > vet[meio]){
    count++;
    return busca(vet, meio+1, fim, find, count);
  }
  else{
    count++;
    return busca(vet, inicio, meio-1, find, count);
  }
}



int main(void) {
  int i, tam, find, *vet, count=0;
  
  scanf("%d", &tam);
  vet = (int *) malloc(tam * sizeof(int));
  for(i=0; i<tam; i++){
    scanf("%d", &vet[i]);
  }
  scanf("%d", &find);
  order(vet, tam);
  int value = busca(vet, 0, tam-1, find, count);
  if (value == -1){
    printf("%d nao foi encontrado", find);
  }
  free(vet);
  return 0;
}
