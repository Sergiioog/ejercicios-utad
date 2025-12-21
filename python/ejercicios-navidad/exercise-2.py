'''2) Tipado dinámico y conversiones
    1. Convierte la cadena "123.45" a float y súmale 10.
'''

def convertType(numberString:str):
    try:
        return print(float(numberString) + 10)
    except:
        print("El número introducido no es un string")

convertType("123.45")
