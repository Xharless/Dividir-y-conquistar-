
#include <iostream>
#include <vector>
#include <sstream>
#include <chrono>
#include <fstream>
using namespace std;

void merge(vector<int>&arreglo, int inicio, int mitad, int final){
    int i,j,k;
    int elementosIzq = mitad - inicio +1;
    int elementosDer = final - mitad;
    vector <int> izquierda(elementosIzq);
    vector <int> derecha(elementosDer);
    for(int i = 0; i<elementosIzq; i++){
        izquierda[i] = arreglo[inicio+i];
    }
    for(int j = 0; j<elementosDer; j++ ){
        derecha[j] = arreglo[mitad+1+j];
    }
    i = 0;
    j = 0;
    k = inicio;

    while(i<elementosIzq && j<elementosDer){
        if(izquierda[i] <= derecha[j]){
            arreglo[k] = izquierda[i];
            i++;
        } else {
            arreglo[k] = derecha[j];
            j++;
        }
        k++;
    }
    
    while(j<elementosDer){
        arreglo[k] = derecha[j];
        j++;
        k++;
    }

    while(i<elementosIzq){
        arreglo[k] = izquierda[i];
        i++;
        k++;
    }
}


void mergeSort(vector<int>&arreglo, int inicio, int final){
    if(inicio < final){
        int mitad = inicio + (final-inicio)/2;
        mergeSort(arreglo, inicio, mitad);
        mergeSort(arreglo, mitad+1, final);
        merge(arreglo, inicio, mitad, final);
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

int main() {
    auto start = chrono::high_resolution_clock::now();
    vector<vector<int>> todos_los_datos = leer_TXT("dataset.txt");
    for (auto& datos : todos_los_datos) {
        mergeSort(datos, 0, datos.size() - 1);
        imprimirArreglo(datos);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end-start;
    cout<<"\nTiempo de ejecucion: " << duration.count() << "segundos"<< endl;
    // tiempo = 14,4632
    return 0;
}