
#include <iostream>
#include <vector>
#include <string>
#include<deque>

using namespace std;

//BIGINTEGER.H//
class BigInteger{
    private:
        vector<int> valor;
        bool signopos=true;
    public:
        //CONSTRUCTORAS
        BigInteger(const string& elem);//
        BigInteger(const BigInteger& elem2);//
        //MODIFICADORAS
        void add(BigInteger& elem);//
        void product(BigInteger& elem);//
        void substract(BigInteger& elem);//
        void quotient(BigInteger& elem);
        void remainder(BigInteger& elem);
        void pow(int elem);//
        BigInteger sumarListas(deque<BigInteger> bigg);//
        BigInteger multiplicarListas(deque<BigInteger> bigg);//
        string toString();//
        //ANALIZADORAS
        int tamano();
        void signo();
        //SOBREGARGA DE OPERADORES:
        BigInteger operator+(BigInteger& elem);//
        BigInteger operator-(BigInteger& elem);//
        BigInteger operator*(BigInteger& elem);//
        BigInteger operator/(BigInteger& elem);//
        BigInteger operator%(BigInteger& elem);//
        bool operator==(BigInteger& elem);//
        bool operator<(BigInteger& elem);//
        bool operator<=(BigInteger& elem);//
        bool operator>(BigInteger& elem);//
        bool operator>=(BigInteger& elem);//
        bool operator!=(BigInteger& elem);//
};


//BIGINTEGER.CPP

//constructores//
BigInteger::BigInteger(const string& elem){
    vector<int> vec;
    int num;
    int negativo=0;
    if(elem[0]=='-'){
        negativo=1;
        signopos=false;
    }
    for(int i=negativo;i<elem.size();i++){
        int posi= elem[i]-'0';
        valor.push_back(posi);
    }
};

BigInteger::BigInteger(const BigInteger& elem2){
    valor=elem2.valor;
};


//Sobrecargas//
    //Operador <//
bool BigInteger::operator<(BigInteger& elem) {
    bool resul=true;
    if (elem.valor.size() > this->valor.size()) {
        resul=true;
    } 
    else if (elem.valor.size()<this->valor.size()) {
        resul=false;
    } 
    else if (elem.valor.size()==this->valor.size()) {
        int cont1=0;
        int cont2=0;
        int tam=elem.valor.size();
        for (int i=0; i < tam; i++) {
            if (this->valor[i] > elem.valor[i]) {
            cont1=cont1+1;
            } 
            else if (this->valor[i] < elem.valor[i]) {
            cont2=cont2+1;
            }
        }
        if (cont1>cont2) {
            resul=false;
        } 
        else if (cont1<cont2) {
            resul=true;
        }
    }
    return resul;
};
    //Operador >//
bool BigInteger::operator>( BigInteger& elem) {
    bool bande=false;
    bool resul = true;
    if (valor.size() > elem.valor.size()) {
        resul = true;
    } else if (valor.size() < elem.valor.size()) {
        resul = false;
    } else if (valor.size() == elem.valor.size() && bande==false) {
        int cont1 = 0;
        int cont2 = 0;
        int tam = valor.size();
        for (int i = 0; i < tam; i++) {
            if (valor[i] > elem.valor[i]) {
                cont1 = cont1 + 1;
                if(valor[0]>elem.valor[0]){
                    resul=true;
                    bande=true;
                }
                else if(valor[0]<elem.valor[0]){
                    resul=false;
                    bande=true;
                }
                else if(valor[0]==elem.valor[0]){
                    bande=false;
                }

            } else if (valor[i] < elem.valor[i]) {
                cont2 = cont2 + 1;
            }
        }
        if(bande==false){
            if (cont1 > cont2) {
                resul = true;
            } else if (cont2 > cont1) {
                resul = false;
            }
        }
    }
    return resul;
};
    //Operador ==//
bool BigInteger::operator==(BigInteger& elem){
    bool resul = true;
    if (elem.valor.size() != this->valor.size()) {
        resul = false;
    } else {
        int tam = elem.valor.size();
        for (int i = 0; i < tam; i++) {
            if (this->valor[i] != elem.valor[i] && resul==true) {
                resul = false;
            }
        }
    }
    return resul;
}
    //Operador !=//
bool BigInteger::operator!=(BigInteger& elem){
    return !(operator==(elem));
}


int main(){
    
    string num1;
    string num1par;
    string num1par2;
    string num2par;
    string num2par2;
    bool punto = false;
    bool punto2 = false;
    int j = 1;
    string nuMayor;
    while(getline(cin,nuMayor)) {
        bool pasoo=false;
        bool mayor = false;
        bool iguales = false;
        int tam1 = nuMayor.size();
        num1=nuMayor;
        string acumulado1;
        string acumulado;
        string acumulado2;
        string acumulado0;

        for (int i = 0; i < tam1; i++) {
            if(num1[i]==' '){
                pasoo=true;
            }
            else if(num1[i]!=' ' && pasoo==false){
                if (punto == false) {
                    if (num1[i] == '.') {
                        punto = true;
                    } 
                    else {
                        acumulado += num1[i];
                    }
                } 
                else if (punto == true) {
                    acumulado1 += num1[i];
                }
            }
            if(pasoo==true){
                if(num1[i]!=' '){
                    if (punto2 == false) {
                        if (num1[i] == '.') {
                            punto2 = true;
                        } 
                        else {
                            acumulado0 += num1[i];
                        }
                    } 
                    else if (punto2 == true) {
                        acumulado2 += num1[i];
                    }
                }
                
            }
        }

        num1par = acumulado;
        num1par2 = acumulado1;
        num2par = acumulado0;
        num2par2 = acumulado2;

        BigInteger parte11(num1par);
        BigInteger parte21(num2par);
        BigInteger parte12(num1par2);
        BigInteger parte22(num2par2);

        if (parte11 == parte21) {
            if (parte12 > parte22) {
            mayor = true;
            } else if (parte12 == parte22) {
            iguales = true;
            } else {
            mayor = false;
            }
        } 
        else if (parte11 != parte21) {
            if (parte11 > parte21) {
            mayor = true;
            } 
            else if(parte11<parte21) {
            mayor = false;
            }
        }

        if (mayor == true) {
            cout << "Case " << j << ": Bigger" << endl;
        } else if (mayor == false && iguales == false) {
            cout << "Case " << j << ": Smaller" << endl;
        } else if (iguales == true) {
            cout << "Case " << j << ": SAME" << endl;
        }

        j = j + 1;
        punto = false;
        punto2 = false;
        num1par.clear();
        num1par2.clear();
        num2par.clear();
        num2par2.clear();
        acumulado.clear();
        acumulado1.clear();
        acumulado2.clear();
        acumulado0.clear();
    }

    return 0;
    }

