#include <iostream>
#include <vector>
#include <string>
#include "lista.h"

using namespace std;
//NICOLLE RUIZ QUINTERO CODIGO: 8974036

// PUNTO 1

/*LA COMPLEJIDAD ES O(n) LA CUAL ES LA DE LONGLISTA YA QUE TIENE QUE RECORRER TODA LA LISTA PARA ENCONTRAR 
CUANTOS NUMEROS SE REPITEN*/

int contarOcurrencias(Lista& lst, int num) {
    int cont=0;
    for(int i=1;i<=lst.longLista();i++) {
        if(lst.infoLista(i)==num) {
            cont++;
        }
    }
    return cont;
}

// PUNTO 2 

/*LA COMPLEJIDAD ES O(n) LA CUAL ES LA DE LONGLISTA YA QUE TIENE QUE RECORRER TODA LA LISTA PARA ENCONTRAR 
CUANTOS NUMEROS SON MENORES*/

Lista obtenerMenores(Lista& lst, int num){
    Lista numero;
    for(int i=1;i<lst.longLista();i++){
        if(lst.infoLista(i)<num){
            numero.anxLista(lst.infoLista(i));
        }
    }
    cout<<endl;
    return numero;
}

int main() {
    Lista list;
    list.anxLista(1);
    list.anxLista(2);
    list.anxLista(3);
    list.anxLista(5);
    list.anxLista(6);
    int buscado = 3;
    int recibo1=contarOcurrencias(list,buscado);
    Lista recibo2=obtenerMenores(list,buscado);
    cout<<recibo1<<endl;
    for(int i=1;i<=recibo2.longLista();i++){
        cout<<recibo2.infoLista(i)<<" ";
    }
    return 0;
}