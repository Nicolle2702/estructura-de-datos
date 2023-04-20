#include <iostream>
#include <vector>
#include <string>
#include "lista.h"

using namespace std;

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
    // PUNTO 4 B
    Lista lista3= list + list2;
    cout << "Contenido de lista3: ";
    for (int i = 1; i <= lista3.longLista(); i++) {
        cout << lista3.infoLista(i) << " ";
    }
    return 0;
}