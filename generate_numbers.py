import random

# Generar una lista de números del 1 al 500
numbers = list(range(1, 500))

# Desorganizar la lista
random.shuffle(numbers)

# Escribir la lista desorganizada en el archivo numbers.txt
with open('numbers.txt', 'w') as file:
    for number in numbers:
        file.write(f"{number}\n")