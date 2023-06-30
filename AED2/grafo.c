#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef enum { branco, cinza, preto } Cor;

typedef struct {
  int num_vertices;
  int** adj_matrix;
  Cor* cor;
  int* dist;
  int* pred;
} Grafo;

Grafo* inicializa_grafo(int vertices) {
  Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
  grafo->num_vertices = vertices;

  // Aloca memória para a matriz de adjacência
  grafo->adj_matrix = (int**)malloc(vertices * sizeof(int*));
  for (int i = 0; i < vertices; i++) {
      grafo->adj_matrix[i] = (int*)malloc(vertices * sizeof(int));
      for (int j = 0; j < vertices; j++) {
          grafo->adj_matrix[i][j] = 0;
      }
  }

  grafo->cor = (Cor*)malloc(vertices * sizeof(Cor));
  grafo->dist = (int*)malloc(vertices * sizeof(int));
  grafo->pred = (int*)malloc(vertices * sizeof(int));
  

  return grafo;
}

void add_a(Grafo* grafo, int vert1, int vert2){
  grafo->adj_matrix[vert1][vert2] = 1;
}

void busca_largura(Grafo* grafo, int inicio, int n){
  int i, vert_atual, posicao;
  int fila[MAX];

  int comeco = 0, fim = 0;

  for(i=0; i<n; i++){
    grafo->cor[i] = branco;
    grafo->dist[i] = MAX;
    grafo->pred[i] = -1;
  }

  grafo->cor[inicio] = cinza;
  grafo->dist[inicio] = 0;
  grafo->pred[inicio] = -1;
  fila[fim] = inicio;
  fim++;

  while(fim != comeco){
    vert_atual = fila[comeco];
    printf("%d ", vert_atual);
    posicao = comeco;
    comeco++;
    for(i=0; i<n; i++){
      if(grafo->adj_matrix[fila[posicao]][i] == 1){
        if(grafo->cor[i] == branco){
          grafo->cor[i] = cinza;
          grafo->dist[i] = grafo->dist[vert_atual];
          grafo->pred[i] = vert_atual;
          fila[fim] = i;
          fim++;
        }
      }
    }
    grafo->cor[vert_atual] = preto;
  }
}

void visit(Grafo* grafo, int posicao, int n){
  int i;
  
  printf("%d ", posicao);
  grafo->cor[posicao] = cinza;

  for(i=0; i<n; i++){
    if(grafo->adj_matrix[posicao][i] == 1){
      if(grafo->cor[i] == branco){
        grafo->pred[i] = posicao;
        visit(grafo, i, n);
      }
    }
  }
  grafo->cor[posicao] = preto;
}

void busca_profundidade(Grafo* grafo, int inicio, int n){
  int i, vert_atual, tempo;
  int pilha[MAX];

  int comeco = 0, fim = 0;

  for(i=0; i<n; i++){
    grafo->cor[i] = branco;
    grafo->dist[i] = MAX;
    grafo->pred[i] = -1;
  }

  tempo = 0;

  printf("\n");
  visit(grafo, inicio, n);

  for(i=0; i<n; i++){
    if(grafo->cor[i] == branco){
      visit(grafo, i, n);
    }
  }
}

// void printAdjMatrix(Grafo* graph) {
//     for (int i = 0; i < graph->num_vertices; i++) {
//         for (int j = 0; j < graph->num_vertices; j++) {
//             printf("%d ", graph->adj_matrix[i][j]);
//         }
//         printf("\n");
//     }
// }

int main(void) {
  int inicio, n, m, i, vert1, vert2;

  scanf("%d", &inicio);
  scanf("%d %d", &n, &m);

  Grafo* grafo = inicializa_grafo(n);

  for(i=0; i<m; i++){
    scanf("%d %d", &vert1, &vert2);
    add_a(grafo, vert1, vert2);
  }

  busca_largura(grafo, inicio, n);

  busca_profundidade(grafo, inicio, n);

  // printAdjMatrix(grafo);

  for (int i = 0; i < grafo->num_vertices; i++) {
        free(grafo->adj_matrix[i]);
    }
    free(grafo->adj_matrix);
    free(grafo);
}
