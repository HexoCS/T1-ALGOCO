#include <iostream>
#include "Auxiliary.hpp"
#include "Strassen.hpp"
#include <chrono>

using namespace std;
using namespace std::chrono;
using size= std::size_t;




int main(){

    
    std::srand(static_cast<unsigned>(std::time(0)));

    int n;

    cin >> n;

    Matrix A = createMatrix(n);
    Matrix B= createMatrix(n);
    Matrix C= createMatrix(n);

    randomize(A,n);
    randomize(B,n);

   
    auto inicio = high_resolution_clock::now();
    C = sq_matrix_multiply(A,B,n);

    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<nanoseconds>(fin - inicio);
	
	cout << "Tiempo de ejecución: " << duracion.count() << " ns" << endl;

    return 0;
}