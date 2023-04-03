/*
NICOLLE RUIZ QUINTERO CODIGO: 8974036

ESTE PROGRAMA LO QUE BUSCA ES COMPARAR EL TAMAÑO DE CADA PALABRA, ENTONCES BUSCA LA PALABRA MAS PEQUEÑA Y 
QUE TENGA LA INICIAL ALFABETICA MAS PEQUEÑA, HE IR COMPARANDO CON LA OTRA QUE TENGA LA INICIAL MAS PEQUEÑA
O CONSIGO MISMA, DEPENDE DEL CASO.

EL PROGRAMA NO FUNCIONA DEL TODO BIEN YA QUE NO ENTRA A ALGUNAS CONDICIONES; PERO SU COMPLEJIDAD PIENSO QUE ES
CUADRADA PORQUE ENCONTRAMOS MUCHOS FOR ANIDADOS EN EL PROGRAMA.
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    string conjunto1[26]={"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    int casos;
    cin >> casos;
    while(casos != 0){
        vector<string>letraFin;
        vector<string>nombre;
        for(int i=0; i<casos;i++){
            string pali;
            cin>>pali;
            nombre.push_back(pali);
        }
        string palaCorta=nombre[0];
        for (int i=1; i<nombre.size(); i++) {
            if (nombre[i].size()<palaCorta.size()) {
                palaCorta=nombre[i];
            }
        }
        vector<string> palaMeno;
        string letraMenor="z";
        vector<string> alfameno1;
        for (int i=0; i<nombre.size(); i++) {
            string palaActual=nombre[i];
            string alfameno=nombre[i];
            if (palaActual.size()==palaCorta.size() && palaActual[0]<letraMenor[0]) { 
                palaMeno.clear(); 
                palaMeno.push_back(palaActual); 
                letraMenor = palaActual[0]; 
            } 
            else if (palaActual.size()==palaCorta.size() && palaActual[0]==letraMenor[0]) {
                palaMeno.push_back(palaActual);
            }
            else if(palaActual[0] == letraMenor[0] && palaActual.size() > palaCorta.size()) {
                alfameno1.push_back(palaActual);
            }
        }
        char letraSiguiente='z';
        if(palaMeno.size()==1 && alfameno1.size()==0){// ENCUENTRA LA LETRA PARA DESPUES BUSCAR LA SIGUENTE
            for(int t=0; t<palaMeno.size(); t++){
                string paliActu=palaMeno[t];
                if(paliActu.size()==palaCorta.size()){
                    char letra=paliActu[0];
                    if(letra<letraSiguiente){
                        letraSiguiente=letra;
                    }
                }
            }
        }
        
        if(palaMeno.size()>1 && alfameno1.size()==0) { // SI HAY 2 O MAS PALABRAS CON LA LETRA INICIAL PEQUEÑA Y DEL MISMO TAMAÑO
            bool letrasIguales = true;
            int i = 0;
            while(letrasIguales && i<palaMeno[0].size()) { 
                char menorLetra=palaMeno[0][i]; 
                for(int j=1;j<palaMeno.size(); j++) {
                    if(palaMeno[j][i]!=palaMeno[0][i]) { 
                        letrasIguales=false;
                        if(palaMeno[j][i]<menorLetra) {
                            menorLetra=palaMeno[j][i];
                        }
                    }
                }
                if(letrasIguales) { 
                    cout << palaMeno[0][i];
                } 
                else { 
                    cout <<char(menorLetra+1)<<endl;
                }
                ++i;
            }
        }
        if (alfameno1.size() > 0 && palaMeno.size() > 0) {//SI HAY UNA PALABRA EN CADA UNO
            bool letrasIguales = true;
            int i = 0;
            while (letrasIguales && i < palaCorta.size() && i < palaMeno[0].size()) {
                char menorLetra = palaMeno[0][i];
                bool letrasDiferentes = false;
                for (int r = 0; r < palaMeno.size(); r++) {
                    if (palaMeno[r][i] != alfameno1[0][i]) {
                        if (palaMeno[r][i] < menorLetra && alfameno1[r][i] > menorLetra) {
                            menorLetra = palaMeno[r][i];
                        }
                        else if(palaMeno[r][i] > menorLetra && alfameno1[r][i] < menorLetra){
                            menorLetra = alfameno1[r][i];
                        }
                        letrasDiferentes = true;
                    }
                }
                if (!letrasDiferentes) { 
                    cout<<palaMeno[0][i];
                }
                else {
                    cout<<char(menorLetra + 1)<<endl;
                    letrasIguales = false;
                }
                ++i;
            }
        }

        
        if(palaMeno.size()==1 && alfameno1.size()==0){//SI SOLO HAY 1 POR LO QUE PASA A LETRA SIGUENTE 
            if(letraSiguiente!='z'){ 
                int posicion=letraSiguiente-'A';
                char letraFinal=conjunto1[posicion+1][0];
                cout<<letraFinal<< endl;
            }
        }
        cout << endl;
        cin >> casos;
    }
    return 0;
}
// FALTA AGREGAR:
//1. SI LA PALABRA SIGUIENTE SON ALFABETICAMENE SIGUIENTE A LA OTRA EN ESE CASO COGE LA ANTERIOR A LA MENOR

