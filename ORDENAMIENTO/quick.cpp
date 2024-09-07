//fuente principal: https://favtutor.com/blogs/quick-sort-cpp

#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <chrono>
#include <vector>
#include "datasets.hpp"
using namespace std;
using namespace std::chrono;



void swap(int arr[] , int pos1, int pos2){
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(int arr[], int low, int high, int pivot){
	int i = low;
	int j = low;
	while( i <= high){
		if(arr[i] > pivot){
			i++;
		}
		else{
			swap(arr,i,j);
			i++;
			j++;
		}
	}
	return j-1;
}

void quickSort(int arr[], int low, int high){
	if(low < high){
	int pivot = arr[high];
	int pos = partition(arr, low, high, pivot);
	
	quickSort(arr, low, pos-1);
	quickSort(arr, pos+1, high);
	}
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
	quickSort(arr, 0 , n-1);
	auto fin = high_resolution_clock::now();
	auto duracion = duration_cast<nanoseconds>(fin - inicio);




	cout << "Tiempo de ejecución: " << duracion.count() << " ns" << endl;
}