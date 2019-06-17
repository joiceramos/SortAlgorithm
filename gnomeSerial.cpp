// Programa em C ++ para implementar o Gnome Sort otimizado
#include <iostream> 
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define TAM 1000
using namespace std; 
  
// Função para ordenar o algoritmo com gnome sort
void gnomeSort(int arr[]) 
{
  {
    int i = 0; 
    while (i < TAM) { 
      if (i == 0) 
	i++; 
      if (arr[i] >= arr[i - 1]) 
	i++; 
      else { 
	swap(arr[i], arr[i - 1]); 
	i--; 
      } 
    }
  }
    return; 
} 
  
void gerarAleatorio(int vet[]){
  for (int i = 0; i < TAM; i++) {
    vet[i] = rand() % 1000;
  }
}

void gerarInverso(int vet[]){
  for (int i = TAM - 1; i >= 0; i--) {
    vet[i] = TAM - i;
  }
}

// Função para imprimir uma matriz de tamanho n
void printArray(int arr[]) 
{ 
    cout << "Sequência ordenada após a classificação do Gnome: "; 
    for (int i = 0; i < TAM; i++) 
        cout << arr[i] << " "; 
        cout << "\n"; 
} 
  
// Matriz desordenada para testar a funçao acima. 
int main (int numargs, char *arg[]){ 
  double start, end, tempo;
  double segundosTotal;
  int *a = (int*) calloc(TAM, sizeof(int));
  //int logn = 10, n = 1 << logn;
  int escolha=atoi (arg[1]);

  srand(time(NULL));

  if (escolha == 0){
    gerarAleatorio(a);
  } else {
    gerarInverso(a);
  }
  printArray(a);

  clock_t startTime = clock();
  start = omp_get_wtime();

  gnomeSort(a);
  end = omp_get_wtime();
  printArray(a);
  segundosTotal = (clock() - startTime)/(double)(CLOCKS_PER_SEC);
  
  tempo=end-start;
  cout << "%f s lib ctime\n";
  cout << segundosTotal;
  cout << "\n%f s lib openmp\n";
  cout << tempo;
  cout << "\n";

  return 0;
}

