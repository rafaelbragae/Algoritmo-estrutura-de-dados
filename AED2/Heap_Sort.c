#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(char **x, char **y) {
  char *temp = *x;
  *x = *y;
  *y = temp;
}

int compare(const char *a, const char *b, const char *alphabet) {
  while (*a != '\0' && *b != '\0') {
    int idx_a = strchr(alphabet, *a) - alphabet;
    int idx_b = strchr(alphabet, *b) - alphabet;
    if (idx_a != idx_b) {
        return idx_a - idx_b;
    }
    a++;
    b++;
  }
  return strlen(a) - strlen(b);
}

// void heapify(char **arr, int n, int i, char *chave) {
//   int largest = i;
//   int l = 2 * i + 1;
//   int r = 2 * i + 2;

//   // Uso do strcmp, caso as strings forem iguais retorna 0, se a primeira for lexicograficamente menor que a segundna retorna valor negativo, e se for maior retorna positivo
//   if (l < n && strcmp(arr[l], arr[largest]) > 0) {
//       largest = l;
//   }

//   // Verifica se o filho da direita é maior que o pai
//   if (r < n && strcmp(arr[r], arr[largest]) > 0) {
//       largest = r;
//   }

//   if (largest != i) {
//       swap(&arr[i], &arr[largest]);
//       heapify(arr, n, largest, chave);
//   }
// }

void heapify_ordem(char **arr, int n, int i, char *chave) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  // Uso do strcmp, caso as strings forem iguais retorna 0, se a primeira for lexicograficamente menor que a segundna retorna valor negativo, e se for maior retorna positivo
  if (l < n && compare(arr[l], arr[largest], chave) > 0) {
      largest = l;
  }

  // Verifica se o filho da direita é maior que o pai
  if (r < n && compare(arr[r], arr[largest], chave) > 0) {
      largest = r;
  }

  if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify_ordem(arr, n, largest, chave);
  }
}

void heapSort(char **arr, int n, char *chave) {
  for (int i = n / 2 - 1; i >= 0; i--)
      heapify_ordem(arr, n, i, chave);

  for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      heapify_ordem(arr, i, 0, chave);
  }
}

int main() {
  int tam_palavras, tam_chave, i, end = 0;

  scanf("%d", &tam_palavras);
  scanf("%d", &tam_chave);
  char chave[tam_chave];
  int chave_ascii[tam_chave];
  for(i=0; i<=tam_chave; i++){
    scanf("%c", &chave[i]);
    chave_ascii[i] = (int)chave[i];
  }
  char *arr[tam_palavras];

  for (int i = 0; i < tam_palavras; i++) {
    char *str = malloc(sizeof(char) * 32);
    scanf("%s", str);
    arr[i] = str;
    for (int j = 0; j < strlen(arr[i]); j++) {
      if (strchr(chave, arr[i][j]) == NULL) {
        printf("A palavra %s eh invalida\n", arr[i]);
        end = 1;
        break;
      }
    }
  }

  if(end == 0){
    heapSort(arr, tam_palavras, chave);
    
    for(i=0; i<tam_palavras; i++){
      printf("%s ", arr[i]);
    }
  }
  return 0;
}