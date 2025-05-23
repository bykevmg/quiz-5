//grupo 5
#include <stdio.h>
#include <stdlib.h>

//hacemos que se llene aleatoriamente
void llenar_matriz(int **matrix, int m, int n) {
 int max = 1000;
 int min = 1;
  for (int i = 0; i < m; i++) {
  for (int j = 0; j < n; j++) {
      matrix[i][j] = rand() % (max - min + 1) + min;
     }
    }
}

//redimension de la matriz, hay que hacerlo para las filas y para las columnas, para luego rellenarlas
void redimensionar(int ***matrix, int *m, int *n, int m2, int n2) {
 *matrix = (int **)realloc(*matrix, m2 * sizeof(int *));
for (int i = 0; i < m2; i++) {
        (*matrix)[i] = (int *)realloc((*matrix)[i], n2 * sizeof(int));
 }

*m = m2;
*n = n2;
}

void imprimirmatriz(int **matrix, int m, int n) {
  for (int i = 0; i < m; i++) {
  for (int j = 0; j < n; j++) {
     printf("%d ", matrix[i][j]);
 }
     printf("\n");
  }
}

//hay que reservar la memoria para la matriz
void reservarmemoria(int ***matrix, int m, int n) {
   *matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
(*matrix)[i] = (int *)malloc(n * sizeof(int));
 }
}

void liberar_memoria_matriz(int **matrix, int m) {
  for (int i = 0; i < m; i++) {
   free(matrix[i]); 
 }
   free(matrix); 
}

int main () {
int **matrix = NULL;
 int m, n;

  printf("Numero de filas m: ");
  scanf("%d", &m);
  printf("Numero de columnas n: ");
  scanf("%d", &n);

 reservarmemoria(&matrix, m, n);

int m2, n2;

llenar_matriz(matrix, m, n);
   printf("\nPrimera matriz:\n");
 imprimirmatriz(matrix, m, n);

  printf("ingrese la cantidad de filas nuevas m2: ");
  scanf("%d", &m2);
  printf("Ingrese la cantidad de columnas nuevas n2: ");
  scanf("%d", &n2); 

redimensionar(&matrix, &m, &n, m2, n2);
  printf("nueva matriz redimensionada: ");
imprimirmatriz(matrix, m, n);

liberar_memoria_matriz(matrix, m);

 return 0;
}
