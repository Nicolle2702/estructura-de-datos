#include <iostream>
#include <vector>
#include <string>
#include "lista.h"

using namespace std;

//NICOLLE RUIZ QUINTERO CODIGO: 8974036

/*SU COMPLEJIDAD ES O(n) YA QUE ESTA TIENE QUE RECORRER TODA LA LISTA2 PARA AGREGAR CADA ELEMENTO, 
ADEMAS EL FOR NO AFECTA YA QUE ESTE SUCEDE 1 VEZ POR CICLO*/

// PUNTO 4 A

void concatenarListas(Lista* lst,Lista* lst2){
    for(int k=1;k<=lst2->longLista();k++){
        lst->anxLista(lst2->infoLista(k));
    }
}

int main() {
    Lista list;
    Lista list2;
    list2.anxLista(4);
    list2.anxLista(6);
    list2.anxLista(7);
    list2.anxLista(8);
    list2.anxLista(9);
    list.anxLista(1);
    list.anxLista(2);
    list.anxLista(3);
    list.anxLista(5);
    list.anxLista(6);
    concatenarListas(&list,&list2);
    // PUNTO 4 B
    Lista lista3= list + list2;
    cout << "Contenido de lista1: ";
    for (int i = 1; i <= list.longLista(); i++) {
        cout << list.infoLista(i) << " ";
    }
    return 0;
}