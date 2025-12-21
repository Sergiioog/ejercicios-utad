''' 3) Funciones: parámetros posicionales, con nombre y por defecto
        1. Define la función area_rect(base, altura=1) y prueba a hacer llamadas
           posicionales y con nombre.
        2. Escribe una función presentar(nombre, edad) que devuelva "Hola, Ana. Tienes 20 años." usando f-string y argumentos con nombre.
        3. Crea la función aplicar(f, x) que reciba una función y un valor y devuelva f(x).
'''

def area_rect(base, altura=1):
    try:
        return print(f"El area del rectángulo es: {int(base) * altura}")
    except:
        print("La base o la altura no son ints")

def presentar(nombre, edad):
    try:
        return print(f"Hola, {nombre}. Tienes {int(edad)} años.")
    except:
        print("El nombre o la edad no son válidos")

def aplicar(f, x):
    return print(f(x))

def cuadrado(n):
    return n*n

area_rect(4, 10)
presentar("Sergio",22)
aplicar(cuadrado,3)