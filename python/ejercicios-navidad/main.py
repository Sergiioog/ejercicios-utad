''' 1) Sintaxis, bloques e indentación
        1. Escribe un programa que pida un número y muestre si es par o impar. Usa
           indentación correcta.
        2. Escribe un bucle for que imprima los números del 1 al 5, uno por línea.
        3. Crea un bucle while que sume los números del 1 al 100 y muestre el total.'''

userNumber : str = input("Por favor, introduzca un número: ")
def oddOrEven(userNumber:str):
    try:
        if int(userNumber) % 2 == 0:
            return print(f"El número {userNumber} es par")
    except:
        print(f"El número {userNumber} es impar")

oddOrEven(userNumber)

#----------------------------------------------------------------
for i in range(1,6):
    print(i)
#----------------------------------------------------------------
def numberAdd():
    number : int = 0
    finalResult : int = 0
    while(number <= 100):
       finalResult += number
       number += 1

    print(f"El resultado final es {finalResult}")
    return

numberAdd()

#def userNumber(userNumber):
