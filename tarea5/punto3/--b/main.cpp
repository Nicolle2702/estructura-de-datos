#include <iostream>
#include <vector>
#include <string>
#include "lista.h"

using namespace std;

// PUNTO 3B

//NICOLLE RUIZ QUINTERO CODIGO: 8974036
//ESTE CODIGO ES O(n) YA QUE TENEMOS UN SOLO CICLO EL CUAL RECORRE HASTA QUE TEMP SEA NULL ES DECIR HASTA EL FINAL DE LA LISTA

int main() {
    Lista list;
    list.insListaOrdenada(5);
    list.insListaOrdenada(1);
    list.insListaOrdenada(2);
    list.insListaOrdenada(6);
    list.insListaOrdenada(3);
    for(int i=1;i<=list.longLista();i++){
        cout<<list.infoLista(i)<<" ";
    }
}