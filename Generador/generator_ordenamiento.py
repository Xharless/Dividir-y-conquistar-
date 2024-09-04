import random

T = 3000 # Número de arreglos 
N = 3000 # Número de elementos dentro de cada arreglo
number_range = (0, 10000)  # Rango del número

#Nombre del dataset y formato del mismo
with open('dataset.txt', 'w') as file:
    file.write(f"{T}\n")  
    for _ in range(T):
        file.write(f"{N}\n") 
        #Genera el número random dentro del rango
        numbers = [str(random.randint(*number_range)) for _ in range(N)]
        file.write(" ".join(numbers) + "\n")
