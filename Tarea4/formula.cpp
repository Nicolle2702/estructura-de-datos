/*
NICOLLE RUIZ QUINTERO CODIGO: 8974036

ESTE PROGRAMA LO QUE HACE ES METER DENTRO DE UN VECTOR DE VECTORES CADA PUESTO DE PILOTO SEGUN LA CARRERA,
ENTRAMOS AL OTRO VECTOR DE VECTORES QUE GUARDA LOS SISTEMAS DE CALIFICACION, CON EL NUMERO QUE HAY EN EL DE PILOTOS
LO BUSCAMOS EN EL SISTEMA Y ASI SE ASIGNAN LOS PUNTOS.

PIENSO QUE EL PROGRAMA TIENE UNA COMPLEJIDAD CUADRATICA YA QUE PODEMOS ENCONTRAR VARIOS CICLOS ANIDADOS EN ESTE CODIGO.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int pilotos;
    int carreras;
    cin>>carreras;
    cin>>pilotos;
    while (carreras!=0 && pilotos!=0) {
        vector<vector<int>> posi;
        vector<int> puntos;
        posi.clear();
        for (int j=0; j<carreras; j++) {
            posi.push_back(vector<int>());
            for (int i=0; i<pilotos; i++) {
                int pos;
                cin >> pos;
                posi[j].push_back(pos);
            }
        }
        int numCalifi;
        cin>>numCalifi;
        vector<vector<int>> puntajess;
        for (int k=0; k<numCalifi; k++) {
            int numPuntos;
            cin>>numPuntos;
            puntajess.push_back(vector<int>());
            for (int o=0; o<numPuntos; o++){
                int a;
                cin>>a;
                puntajess[k].push_back(a);
            }
        }
        for(int sistema=0; sistema<numCalifi; sistema++) {
            vector<int> totalPuntos(pilotos, 0);
            for(int carrera=0; carrera<carreras; carrera++) {
                for(int piloto=0; piloto<pilotos; piloto++) {
                    int posicion=posi[carrera][piloto];
                    if (posicion<=puntajess[sistema].size()) {
                        int punto=puntajess[sistema][posicion - 1];
                        totalPuntos[piloto]+=punto;
                    }
                }
            }
            vector<int> printpilotomayo;
            int pilotomayor=totalPuntos[0];
            for (int t =0; t<totalPuntos.size(); t++) {
                if (totalPuntos[t]>pilotomayor) {
                    pilotomayor=totalPuntos[t];
                    printpilotomayo.clear();
                    printpilotomayo.push_back(t);
                } else if (totalPuntos[t]==pilotomayor) {
                    printpilotomayo.push_back(t);
                }
            }
            for (int i =0; i<printpilotomayo.size(); i++) {
                cout <<printpilotomayo[i]+1<< " ";
            }
            cout<<endl;
            totalPuntos.clear();
        }

        cin>>carreras;
        cin>>pilotos;
    }
    return 0;
}

