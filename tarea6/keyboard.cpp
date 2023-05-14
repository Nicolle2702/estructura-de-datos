//NICOLLE RUIZ QUINTERO CODIGO: 8974036

/* LA COMPLEJIDAD DE ESTE CODIGO ES O(N) YA QUE LO MAS COSTOSO ES RECORRER TODA LA LISTA, MIENTRAS QUE LAS DEMAS 
OPERACIONES COMO  PUSH O CLEAR SON CONSTANTES
*/

#include<iostream>
#include<list>
#include<deque>
#include<string>

using namespace std;

int main(){
    string texto1;
    string acumulado;
    bool corchetes = false;
    bool continu=true;
    deque<string> texto;
    while(getline(cin, texto1) && continu!=false){
        if(texto1=="exit"){
            continu=false;
        }
        for(int i = 0; i < texto1.size(); i++){
            if(texto1[i] == '['){
                corchetes = true;
            } 
            else if(texto1[i] == ']' || texto1.back()=='\n'){
                corchetes = false;
                texto.push_front(acumulado);
                acumulado.clear();
            } 
            else if (corchetes) {
                acumulado += texto1[i];
            }
            else{
                acumulado += texto1[i];
                texto.push_back(acumulado);
                acumulado.clear();
            }
        }
        if(acumulado.size() > 0){
            texto.push_front(acumulado);
        }
        for (deque<string>::iterator it = texto.begin(); it != texto.end(); it++) {
            cout << *it;
        }
        cout<<endl;
        acumulado.clear();
        texto1.clear();
        texto=deque<string>();
        }
    return 0;
}
