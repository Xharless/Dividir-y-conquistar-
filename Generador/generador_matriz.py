import random

def generar_numero_aleatorio(min_val, max_val):
    return random.randint(min_val, max_val)

def generar_dataset_matrices(archivo, T, tamanos):
    with open(archivo, 'w') as file:
        file.write(f"{T}\n")
        
        for _ in range(T):
            N = random.choice(tamanos)
            file.write(f"{N}\n")
            for _ in range(N):
                fila = " ".join(str(generar_numero_aleatorio(1, 100)) for _ in range(N))
                file.write(f"{fila}\n")

if __name__ == "__main__":
    T = 50  # Numero de matrices
    rango_tamanos = [512]  # Tamaños de las matrices (potencias de 2)
    archivo = "matrices_dataset.txt" # Nombre del archivo que se creara 

    generar_dataset_matrices(archivo, T, rango_tamanos)

