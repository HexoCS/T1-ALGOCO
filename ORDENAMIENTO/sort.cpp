
#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdlib>  
#include "datasets.hpp"
using namespace std;
using namespace std::chrono;




//ORDENAR USANDO LA FUNCION SORT() DE c++
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
    
    
    sort(arr, arr + n);
    
    
    auto fin = high_resolution_clock::now();
	auto duracion = duration_cast<nanoseconds>(fin - inicio);

    
    cout << "Tiempo de ejecución: " << duracion.count() << " ns" << endl;
    return 0;
}
