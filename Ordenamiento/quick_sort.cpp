/*
seleccionamos un elemento de un arreglo llamado pivote (primer elemento, a la mitad o el ultimo elemento)
escogemos el primer elemento como povote, a la izquieda colocamos los elementos menores al pivote y al lado derecho los mayores
luego escogemos los pivotes de cada elemento separado

*/
#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>
using namespace std;


int particion(vector<int>&arreglo, int inicio, int final){
    int pivote = arreglo[inicio];
    int i = inicio+1;
    for(int j = i; j<= final; j++){
        if(arreglo[j]<pivote){
            swap(arreglo[i], arreglo[j]);
            i++;
        }
    }
    swap(arreglo[inicio], arreglo[i-1]);
    return i-1;
}


void quicksort(vector<int>&array, int inicio, int final){
    if(inicio<final){
        int pivote = particion(array , inicio, final);
        quicksort(array, inicio, pivote-1);
        quicksort(array, pivote+1, final);
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
        quicksort(datos,0,datos.size()-1);
        imprimirArreglo(datos);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout<<"\nTiempo de ejecucion: " << duration.count() << "segundos"<< endl;
    //tiempo = 14,5333
    return 0;
}