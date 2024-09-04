#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;



vector<vector<int>> leerMatriz(ifstream& file, int N) {
    vector<vector<int>> matriz(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> matriz[i][j];
        }
    }
    return matriz;
}



vector<vector<int>> matrizTransp(vector<vector<int>> &B){
    size_t n_filas = B.size();
    size_t n_columnas = B[0].size();

    vector<vector<int>> B_transpuesta(n_columnas, vector<int> (n_filas));
    for(size_t i = 0; i<n_filas; i++){
        for(size_t j = 0; j<n_columnas; j++){
            B_transpuesta[j][i] = B[i][j];
        }
    }

    return B_transpuesta;
}


vector<vector<int>> multMatriz(vector<vector<int>> &A, vector<vector<int>> &B){
    size_t n_filas_a = A.size();
    size_t n_columnas_a = A[0].size();
    size_t n_columnas_b = B[0].size();

    vector<vector<int>> B_transpuesta = matrizTransp(B);
    vector<vector<int>> Resultado(n_filas_a, vector<int> (n_columnas_b, 0));
    for(size_t i = 0; i<n_filas_a; i++){
        for(size_t j = 0; j<n_columnas_b; j++){
            for(size_t x = 0; x<n_columnas_a; x++){
                Resultado[i][j] += A[i][x] * B_transpuesta[j][x];
            }
        }
    }
    return Resultado;
}


int main(){
    string archivo = "matrices_dataset.txt";
    ifstream file(archivo);
    int T;
    file >> T; 
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i<T; i+=2){
        int N1, N2; 
        file >> N1;
        vector<vector<int>> A = leerMatriz(file, N1);
        file >> N2;
        vector<vector<int>> B = leerMatriz(file, N2);

        vector<vector<int>> resultado = multMatriz(A,B);

        for(size_t i = 0; i<resultado.size(); i++){
            for(size_t j = 0; j<resultado[i].size(); j++){
                cout<< resultado[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration <double> duration = end - start;
    cout<<"\nTiempo de ejecucion: " << duration.count() << "segundos"<< endl;
    //tiempo = 75.4874
    file.close();
    return 0;

}
