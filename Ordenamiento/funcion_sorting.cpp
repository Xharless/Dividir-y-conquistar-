
#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <fstream>
using namespace std;

vector<vector<int>> leer_TXT(const string& archivo) {
    vector<vector<int>> todos_los_datos;
    ifstream file(archivo);
    if (file.is_open()) {
        int T, N;
        file >> T; 
        while (T--) {
            file >> N;
            vector<int> datos(N);
            for (int i = 0; i < N; i++) {
                file >> datos[i];
            }
            todos_los_datos.push_back(datos);
        }
        file.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << archivo << endl;
    }
    return todos_los_datos;
}

void imprimirArreglo(const vector<int>& arreglo) {
    for (auto& elem : arreglo) {
        cout << elem << " ";
    }
    cout << endl;
}

int main(){
    auto start = chrono::high_resolution_clock::now();
    vector< vector<int>> todos_los_datos = leer_TXT("dataset.txt");
    for (auto& datos : todos_los_datos) {  
        sort(datos.begin(), datos.end());  
        imprimirArreglo(datos);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end-start;
    cout<<"\nTiempo de ejecucion: " << duration.count() << "segundos"<< endl;
    // tiempo = 14,6485
    return 0;
}