
#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;



void selectionSort(vector<int> &arreglo){
    int indice_menor,aux;
    for(size_t i = 0; i<arreglo.size()-1; i++){
        indice_menor = i;
        for(size_t j = i+1; j < arreglo.size(); j++ ){
            if(arreglo[j] < arreglo[indice_menor]){
                indice_menor = j;
            }
        }
        aux = arreglo[i];
        arreglo[i] = arreglo[indice_menor];
        arreglo[indice_menor] = aux;
    }
}

void imprimirArreglo(const vector<int>& arreglo) {
    for (auto& elem : arreglo) {
        cout << elem << " ";
    }
    cout << endl;
}

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

int main(){
    auto start = chrono::high_resolution_clock::now();
    vector<vector<int>> todos_los_datos = leer_TXT("dataset.txt");
    for (auto& datos : todos_los_datos) {    
        selectionSort(datos);
        imprimirArreglo(datos);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout<<"\nTiempo de ejecucion: " << duration.count() << "segundos"<< endl;
    //tiempo = 117.461 segundos
    return 0;   
}