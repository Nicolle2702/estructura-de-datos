/*
NICOLLE RUIZ QUINTERO CODIGO: 8974036

ESTE PROGRAMA LO QUE TENIA QUE HACER ERA GUARDAR LOS NUMEROS Y LAS PISTAS EN UN VECTOR, PERO GUARDABAMOS ESTAS PISTAS
EN OTRO VECTOR SI N/N ERA DISTINTO DE 0, DESPUES COMPARABAMOS LOS GUARDADOS ENTRE SI PARA VER SI HABIA ALGUN SIMILAR,
SI SE ENCONTRABAN LOS SIMILARES IGUALES AL NUMERO DIGITADO EN /N ENTONCES LOS OTROS SE DESCARTABAN, ELIMINANDOLO DE
DESCARTE, PARA ASI AL FINAL VER CUANTOS NUMEROS QUEDAN Y CON N/ DETERMINAR SU ORDEN Y SI ES POSIBLE SABER LA CONTRASEÑA

PIENSO QUE EL PROGRAMA TIENE UNA COMPLEJIDAD CUADRATICA YA QUE PODEMOS ENCONTRAR MUCHOS BUCLES ANIDADOS EN ESTE CODIGO.

*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int casos;
    cin>>casos;
    int i=0;
    while (i<casos) {
        int pistas;
        cin >> pistas;
        int descarte[10]={0,1,2,3,4,5,6,7,8,9};
        vector<vector<int>> numPis;
        vector<vector<int>> guardopis;
        vector<int>guardeiguales;
        for (int j=0;j<pistas;j++) {
            numPis.push_back(vector<int>());
            for (int m=0;m<1;m++) {
                int pis;
                cin >> pis;
                numPis[j].push_back(pis);
            }
            string posiCorYNo;
            cin>>posiCorYNo;
            string primernum=posiCorYNo.substr(0, 1);
            string segunnum=posiCorYNo.substr(2, 2);
            int convito1=stoi(primernum);
            int convito2=stoi(segunnum);
            numPis[j].push_back(convito1);
            numPis[j].push_back(convito2);
        }
        for (int o=0;o<numPis.size();o++) {
            for (int q=0;q<numPis[o].size();q++) {
                cout<<"Los numeros son de la pista "<<o+1<<": "<<numPis[o][q]<<endl;
            }
        }
        for(int k=0;k<numPis.size();k++){
            guardopis.push_back(vector<int>());
            if(numPis[k][2]!=0){
                for(int w=0;w<1;w++){
                cout<<"guardo los numeros en la posi incorreta: "<<numPis[k][w]<<endl;
                guardopis[k].push_back(numPis[k][w]);
                }
            }
            else if(numPis[k][1]!=0){
                for(int n=0;n<1;n++){
                cout<<"guardo los numeros en la posi correcta: "<<numPis[k][n]<<endl;
                guardopis[k].push_back(numPis[k][n]);
                }
            }
        }
        for (int o=0;o<guardopis.size();o++) {
            for (int q=0;q<guardopis[o].size();q++) {
                cout<<"Los numeros son de la pista "<<o+1<<": "<<guardopis[o][q]<<endl;
            }
        }
        for (int i = 0; i < guardopis.size(); i++) {
            for (int j = i + 1; j < guardopis.size(); j++) {
                for (int k = 0; k < guardopis[i].size(); k++) {
                    for (int l = 0; l < guardopis[j].size(); l++) {
                        cout<<"sientreperonopase"<<endl;
                        if (guardopis[i][k] == guardopis[j][l]) {
                            cout << "El número " << guardopis[i][k]<<endl;
                            guardeiguales.push_back(guardopis[k][j]);
                        }
                    }
                }
            }
        }

    
        i++;
    }
    return 0;
}

