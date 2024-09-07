
#ifndef DATASETS_H
#define DATASETS_H

#include <iostream>
#include <algorithm>  
#include <cstdlib> 
#include <ctime>   
using namespace std;



void printArray(int * arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void generarArregloAleatorio(int* arreglo, int n, int min, int max) {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < n; ++i) {
        arreglo[i] = min + rand() % ((max - min) + 1);
    }
}


void generarArregloOrdenado(int* arreglo, int n, int min, int max) {
    generarArregloAleatorio(arreglo, n, min, max);
    sort(arreglo, arreglo + n); 
}


void generarArregloOrdenInverso(int* arreglo, int n, int min, int max) {
    generarArregloOrdenado(arreglo, n, min, max);
    reverse(arreglo, arreglo + n);  
}


void generarArregloParcialmenteOrdenado(int* arreglo, int n, int min, int max, int porcentajeOrdenado) {
    generarArregloAleatorio(arreglo, n, min, max);
    int limiteOrdenado = (n * porcentajeOrdenado) / 100;
    sort(arreglo, arreglo + limiteOrdenado);  
}

#endif // DATASETS_H