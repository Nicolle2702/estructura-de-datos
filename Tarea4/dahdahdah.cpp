/*
NICOLLE RUIZ QUINTERO CODIGO: 8974036

ESTE PROGRAMA GUARDA EN UN VECTOR EL MENSAJE QUE SE ESCRIBE EN CODIGO MORSE, LO GUARDA TENIENDO
EN CUENTA LOS EAPACIOS QUE SE COLOQUEN, PARA DESPUES COMPARARLO CON EL ARREGLO QUE TIENE LAS LETRAS EN MORSE, Y ASI
ENCONTRAR LA POSICION EN LA QUE SON IGUALES, Y COLOCAMOS ESA POSICION EN EL ARREGLO CON LAS LETRAS NORMALES, Y ASI
PODER TRADUCIR EL CODIGO

PIENSO QUE EL PROGRAMA TIENE UNA COMPLEJIDAD CUADRATICA YA QUE PODEMOS ENCONTRAR DOS BUCLES ANIDADOS EN ESTE CODIGO,
PARA ENCONTRAR LA COINCIDENCIA ENTRE CADA PALABRA DEL MENSAJE CON EL ARREGLO MORSE.
*/




#include<iostream>
#include<string>    
#include<cstring>
#include<vector>
using namespace std;

int main(){
    int l,casos,k;
    string conts = "";
    string mensaje;
    vector<string> mensajeFin;
    vector<string> printeo;
    string conjunto1[54]={"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5","6", "7", "8", "9", ".", ",", "?","'", "!", "/", "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "@"," "};
    string conjunto[54]={".-", "-...", "-.-.", "-..", ".", "..-.","--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--","-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-.","_"};
    vector<string> conjunto2(conjunto,conjunto+54);
    l=0;
    k=1;
    cin>>casos;
    cin.ignore();
    while(k<=casos){
        mensajeFin.clear();
        printeo.clear();
        conts = "";
        getline(cin,mensaje);
        for(int h=0;h<mensaje.size();h++){
            if(mensaje[h]==' '){
            mensajeFin.push_back(conts);
            conts="";
            }
            else{
                conts+=mensaje[h];
            }
            if(mensaje[h]==' ' && mensaje[h+1]==' '){
                mensajeFin.push_back("_");
            }
        }
        mensajeFin.push_back(conts);
        for(int m=0;m<mensajeFin.size();m++){
            for(int n=0;n<conjunto2.size();n++){
                if(conjunto2[n]==mensajeFin[m]){
                    l=n;
                    printeo.push_back(conjunto1[l]);
                }
            }
        }
        cout <<"Message #"<<k<<endl;
        for(int q=0;q< printeo.size();q++){
            cout<<printeo[q];
        }
        cout<<endl;
        if(k<casos){
            cout<<endl;
        }
        ++k;
    }
    return 0;
}