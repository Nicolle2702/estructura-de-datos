
//NICOLLE RUIZ QUINTERO CODIGO: 8974036

/* LA COMPLEJIDAD DE ESTE CODIGO ES DE O(N*3) YA QUE TIENE UN CICLO TRIPLE LO CUAL ES LO MAS COSTOSO EN ESTE ALGORITMO
*/

#include <iostream>
#include <deque>
#include <string>
#include<algorithm>

using namespace std;

int main(){
    int resultado = 0;
    deque<deque<string>> diccionario;
    deque<string> compa;
    string palabras;
    string letras;
    bool continuo=true;
    bool marca=true;
    while (getline(cin,palabras) && continuo==true){
        if(palabras=="#"){
            continuo=false;
        }
        else{
            sort(palabras.begin(),palabras.end(),less<char>());
            deque<string> temp;
            temp.push_back(palabras);
            diccionario.push_back(temp);
        }
    }
    while(getline(cin,letras) && marca==true){
        if(letras=="#"){
            marca=false;
        }
        else{
            sort(letras.begin(),letras.end());
            compa.push_back(letras);
        }
    }
    for(int i=0; i<diccionario.size();i++){
        for(int j=0; j<diccionario[i].size();j++){
            for(int k=0; k<compa.size();k++){
                if(compa[k][i]==diccionario[i][j][k]){
                    resultado=resultado+1;
                }
            }
        }  
    }
    cout << resultado << endl;
    return 0;
}

