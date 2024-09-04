#include <iostream>
#include <vector>
#include<chrono>
#include <fstream>
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


vector<vector<int>> multMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B){
    int n_filasA = A.size();
    int n_columnasA = A[0].size();
    int n_columnasB = B[0].size();

    vector<vector<int>> resultado(n_filasA,vector<int>(n_columnasB,0));
    for(int i = 0; i<n_filasA; i++){
        for(int j = 0; j<n_columnasB; j++){
            for(int x = 0; x<n_columnasA; x++){
                resultado[i][j] += A[i][x] * B[x][j];
            }
        }
    }
    return resultado;
}

int main(){

    string archivo = "matrices_dataset.txt";
    ifstream file(archivo);
    int T;
    file >> T;
    auto start = chrono::high_resolution_clock::now();
    for(int i= 0; i<T; i+=2){
        int N1, N2;
        file >> N1;
        vector<vector<int>> A = leerMatriz(file, N1);
        file >> N2;
        vector<vector<int>> B = leerMatriz(file, N2);

        vector<vector<int>> resultado = multMatrices(A, B);

        for (size_t i = 0; i < resultado.size(); i++) {
            for (size_t j = 0; j < resultado[i].size(); j++) {
                cout << resultado[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration <double> duration = end - start;
    cout<<"\nTiempo de ejecucion: " << duration.count() << "segundos"<< endl;
    //tiempo= 76,857
    file.close();
    return 0;
}