//https://www.geeksforgeeks.org/bubble-sort-in-cpp/
#include <iostream>
#include <chrono>
#include <cstdlib>  
#include "datasets.hpp"
using namespace std;
using namespace std::chrono;


// bubble sort
void bubbleSort(int arr[], int n) 
{ 
	int i, j; 
	for (i = 0; i < n - 1; i++) 

		// los ultimos i elementos ya estan en su lugar
		for (j = 0; j < n - i - 1; j++) 
			if (arr[j] > arr[j + 1]) 
				swap(arr[j], arr[j + 1]); //swap
} 



int main() 
{ 
	int n;
	cin >> n; 
	int arr[n];

	// QUITAR COMENTARIO EN OPCION A TESTEAR
    //generarArregloAleatorio(arr,n,0,1000);
    //generarArregloOrdenado(arr,n,0,1000);
	//generarArregloParcialmenteOrdenado(arr,n,0,1000,50);
	generarArregloOrdenInverso(arr,n,0,1000);
	
	
	auto inicio = high_resolution_clock::now();

	bubbleSort(arr, n); 
	
	auto fin = high_resolution_clock::now();
	auto duracion = duration_cast<nanoseconds>(fin - inicio);
	
	cout << "Tiempo de ejecución: " << duracion.count() << " ns" << endl;
	
	return 0; 
}
