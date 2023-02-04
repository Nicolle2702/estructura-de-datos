#Nicolle Ruiz Quintero / Ing Biomedica

#PUNTO 1

print("PUNTO 1")

def verificarDiagonal(mat):

    diag_principal = [mat[i][i] for i in range(len(mat))]
    diag_secundaria = [mat[i][len(mat)-i-1] for i in range(len(mat))]

    if diag_principal == diag_secundaria:
        print(True)
    else:
        print(False)

mat = [[11, 23, 76, 34, 11],
[14, 30, 92, 30, 101],
[12, 45, 58, 92, 22],
[74, 56, 49, 56, 100],
[99, 5, 28, 47, 99]]

verificarDiagonal(mat)

#PUNTO 2
print(" ")
print("PUNTO 2")


def esCapicua(lista):
    for i in range(len(lista) // 2):
        if lista[i] != lista[len(lista) - i - 1]:
            return False
    return True
    
lista=[42, 12, 90, 90, 12, 42]

print(esCapicua(lista))

# PUNTO 3 A

print(" ")
print("PUNTO 3 A")


def diferenciaDeListas(listaA,listaB):
    
    diferenciaA_B=[]

    for i in listaA:
        if  i not in listaB:
                diferenciaA_B.append(i)
    return diferenciaA_B

lista1=[40, 10, 22, 12, 33, 33, 33]
    
lista2=[41, 22, 31, 15, 13, 12, 33, 19]

print(diferenciaDeListas(lista1,lista2))
print(diferenciaDeListas(lista2,lista1))

#PUNTO 3 B

print(" ")
print("PUNTO 3 B")

def leerDatos(numEjecucion):
    def contarElementos(listaA):
        cantidad=len(listaA)
        return cantidad
    for i in range(len(numEjecucion)):
        listaA=input().split()
        listaB=input().split()
        listaA1 = [int(x) for x in listaA]
        listaB1 = [int(x) for x in listaB]

        print(contarElementos(listaA1),listaA1)
        print(contarElementos(listaB1),listaB1)

    print(diferenciaDeListas(listaA1,listaB1))   
numEjecucion=input()
#leerDatos(numEjecucion)

#PUNTO 4 

print(" ")
print("PUNTO 4")

def mostrarPrimos(n):
    lista2=[]
    lista3=[]
    def esPrimo(num):
        contador=0
        for i in range(2,num):
            if num%i==0:
                contador+=1
        if contador==0:
            return True

    for num in range(2,n+1):
        if esPrimo(num):
            lista2.append(num)

    print("Numeros primos entre 1 y",n)
    for i,j in enumerate(lista2):
        if i==len(lista2)-1:
            print("-->",j)
        elif i<len(lista2)-1:
            print("-->",j,",")

    def sumaDigitos(n):
        return sum([int(d) for d in str(n)])

    for m, l in enumerate(lista2):
        suma=sumaDigitos(l)
        if esPrimo(suma):
            lista3.append(l)
            if m==len(lista2)-1:
                print(l, end=" ")
            elif m<len(lista2)-1:
                print(l,",",end=" ")
        
n = int(input())

mostrarPrimos(n)


#PUNTO 5

print(" ")
print("PUNTO 5") 


def SumarValoresMatriz(elementoEnMatriz):

    lista4=[]
    for clave,item in disp.items():
        for posi in item:
            if posi in elementoEnMatriz:
                lista4.append(clave)
    print(lista4)
    sumaDeNumeros=0
    for lista4 in lista4:
        sumaDeNumeros+=lista4
    return sumaDeNumeros

elementoEnMatriz= [(0, 0), (8, 3), (3, 5), (7, 2), (4, 3), (4,6)]
disp = {0 : [(0, 1), (5, 4), (7, 5)],
1 : [(6, 4), (7, 7)],
2 : [(0, 2), (1, 2), (4, 9), (6, 1)],
4 : [(2, 8), (3, 1), (5, 7)],
6 : [(0, 3), (5, 6), (7, 2)],
7 : [(0, 4), (1, 4), (2, 7)],
8 : [(1, 9), (3, 8), (5, 7), (7, 6)]}
SumarValoresMatriz(elementoEnMatriz)

