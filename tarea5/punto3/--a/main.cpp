#include <iostream>
#include <vector>
#include <string>
#include "lista.h"

using namespace std;

//NICOLLE RUIZ QUINTERO CODIGO: 8974036

/*ESTE TIENE UNA COMPLEJIDAD DE O(n˄3) ya que primero tenemos el for y este invoca a longlista que ya tiene 
una complejidad de O(n) multiplicado pro el for es o(n˄2)mas el insLista que tiene una complejidad de O(n)*/

//Punto 3A

void insertarEnListaOrdenada(Lista& lst, int num){
    for(int t=1;t<=lst.longLista();t++){
        if(lst.infoLista(t)<num && lst.infoLista(t+1)>=num){
            lst.insLista(num,t+1);
        }
    }
}

int main() {
    Lista list;
    list.anxLista(1);
    list.anxLista(2);
    list.anxLista(3);
    list.anxLista(5);
    list.anxLista(6);
    int buscado=3;
    insertarEnListaOrdenada(list,buscado);
    for(int i=1;i<=list.longLista();i++){
        cout<<list.infoLista(i)<<" ";
    }
}