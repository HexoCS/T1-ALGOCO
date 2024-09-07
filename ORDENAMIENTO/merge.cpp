#include <iostream>
#include <chrono>
#include <cstdlib>  
#include "datasets.hpp"
using namespace std;
using namespace std::chrono;


// funcion para unir los 2 sub-arreglos
void merge(int * arr, int low, int mid, int high) {
    int i, j, k;
    int lengthLeft = mid - low + 1;
    int lengthRight = high - mid;

    //crear dos arreglos temporales para guardar los sub arreglos izquierdo y derecho
    int arrLeft[lengthLeft], arrRight[lengthRight];

    // copiar datos del arreglo principal a sub-arreglos
    for (int a = 0; a < lengthLeft; a++) {
        arrLeft[a] = arr[low + a];
    }
    for (int a = 0; a < lengthRight; a++) {
        arrRight[a] = arr[mid + 1 + a];
    }

    // juntar sub-arreglos en arreglo final
    i = 0; // indice de arrleft
    j = 0; // indice de arrright
    k = low; // indice de arreglo unido

    while (i < lengthLeft && j < lengthRight) {
        // chequear y colocar el numero mas pequeño de ambos sub arreglos en arreglo principal
        if (arrLeft[i] <= arrRight[j]) {
            arr[k] = arrLeft[i];
            i++;
        } else {
            arr[k] = arrRight[j];
            j++;
        }
        k++;
    }

    //copiar elementos de arreglo izquierdo si es que quedan
    while (i < lengthLeft) {
        arr[k] = arrLeft[i];
        k++;
        i++;
    }

    // copiar elementos de arreglo derecho si es que quedan
    while (j < lengthRight) {
        arr[k] = arrRight[j];
        k++;
        j++;
    }
}


void mergeSort(int * arr, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;

        // llamada recursiva
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // union de sub-arreglos
        merge(arr, low, mid, high);
    }
}

int main() {
    
    int n;
	cin >> n; 
	int arr[n];

    // QUITAR COMENTARIO EN OPCION A TESTEAR
    //generarArregloAleatorio(arr,n,0,1000);
    //generarArregloOrdenado(arr,n,0,1000);
	//generarArregloParcialmenteOrdenado(arr,n,0,1000,50);
	//generarArregloOrdenInverso(arr,n,0,1000);



    // Calculating the length of the array.
    int length = sizeof(arr) / sizeof(int);

    
    
    
    auto inicio = high_resolution_clock::now();
    mergeSort(arr, 0, length - 1);
    auto fin = high_resolution_clock::now();
	auto duracion = duration_cast<nanoseconds>(fin - inicio);
    
    
    cout << "Tiempo de ejecución: " << duracion.count() << " ns" << endl;
    return 0;
}

