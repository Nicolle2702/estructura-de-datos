
#include "BigInteger.h"
#include <iostream>
#include <vector>
#include <string>
#include<deque>

using namespace std;

//CONSTRUCTORAS//

/*FUNCION:BigInteger
  ENTRADA: UN STRING
  SALIDA: UN BIGINTEGER
  DESCRIPCIÓN: RECIBE UN STRING Y LO CONVIERTE A NUMERO GUARDANDOLO EN UN VECTOR, 
  Y EL VECTOR HACE PARTE DE LA PROPIEDAD DE LOS BIGINTEGER */
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
}

/*FUNCION:BigInteger
  ENTRADA: UN BIGINTEGER
  SALIDA: UN BIGINTEGER
  DESCRIPCIÓN: RECIBE UN BIGINTEGER Y COPIA LO QUE ESTA GUARDADO EN EL VECTOR, 
  Y LO GUARDA EN SU VECTOR DE BIGINTEGER */
BigInteger::BigInteger(const BigInteger& elem2){
    valor=elem2.valor;
}

//MODIFICADORAS//

/*FUNCION:add
  ENTRADA: DOS OBJETOS BIGINTEGER
  SALIDA: AFECTA AL BIGINTEGER ACTUAL
  DESCRIPCIÓN: RECIBE UN BIGINTEGER Y UTILIZA EL - PARA SUMARLO CON EL ACTUAL, EL ACTUAL 
  SE MODIFICA CON LA SUMA QUE SE HIZO */
void BigInteger::add(BigInteger& elem){
    *this=*this+elem;
}

/*FUNCION:product
  ENTRADA: DOS OBJETOS BIGINTEGER
  SALIDA: AFECTA AL BIGINTEGER ACTUAL
  DESCRIPCIÓN: RECIBE UN BIGINTEGER Y UTILIZA EL - PARA MULTIPLICARLO CON EL ACTUAL, EL ACTUAL 
  SE MODIFICA CON LA MULTIPLICACION QUE SE HIZO */
void BigInteger::product(BigInteger& elem) {
    *this=*this*elem;
}

/*FUNCION:substract
  ENTRADA: DOS OBJETOS BIGINTEGER
  SALIDA: AFECTA AL BIGINTEGER ACTUAL
  DESCRIPCIÓN: RECIBE UN BIGINTEGER Y UTILIZA EL - PARA RESTARLO CON EL ACTUAL, EL ACTUAL 
  SE MODIFICA CON LA RESTA QUE SE HIZO */
void BigInteger::substract(BigInteger& elem){
    *this=*this-elem;
}

/*FUNCION:quotient
  ENTRADA: DOS OBJETOS BIGINTEGER
  SALIDA: AFECTA AL BIGINTEGER ACTUAL
  DESCRIPCIÓN: RECIBE UN BIGINTEGER Y UTILIZA EL / PARA DIVIDIRLO CON EL ACTUAL, EL ACTUAL 
  SE MODIFICA CON LA DIVISION QUE SE HIZO, CONVIERTIENOSE EN EL COCIENTE */
void BigInteger::quotient(BigInteger& elem) {
    *this=*this/elem;
}

/*FUNCION:remainder
  ENTRADA: DOS OBJETOS BIGINTEGER
  SALIDA: AFECTA AL BIGINTEGER ACTUAL
  DESCRIPCIÓN: RECIBE UN BIGINTEGER Y  UTILIZA EL / PARA DIVIDIRLO CON EL ACTUAL, EL ACTUAL 
  SE MODIFICA CON LA DIVISION QUE SE HIZO, CONVIERTIENOSE EN EL MODULO */
void BigInteger::remainder(BigInteger& elem){
    *this=*this%elem;
}

/*FUNCION:pow
  ENTRADA: UN NUMERO ENTERO
  SALIDA: AFECTA AL BIGINTEGER ACTUAL
  DESCRIPCIÓN: RECIBE UN NUMERO ENTERO Y LO ELEVA EL BIGINTEGER A ESE ENTERO, EL 
  RESULTADO DEBE SER EL BIGINTEGER YA ELEVADO */
void BigInteger::pow(int expo) {
    if (expo == 0) {
        this->valor = {1};
    }
    else if(expo>=2){
        vector<int> res = {1};
        for (int i=0;i<expo;i++) {
            vector<int>temp(res.size()+this->valor.size(),0);
            int carry=0;
            for (int j=this->valor.size()-1;j>=0;j--) {
                for (int k=res.size()-1;k>=0;k--) {
                    int product =this->valor[j]*res[k]+carry;
                    temp[j + k + 1]+=product%10;
                    carry=product/10;
                }
                if (carry > 0) {
                    temp[j]+=carry;
                    carry=0;
                }
            }
            res = temp;
        }
        
        while (!res.empty() && res.front() == 0) {
            res.erase(res.begin());
        }
    
    this->valor = res;
    }
}

/*FUNCION:sumarListaValores
  ENTRADA: UNA LISTA DE BIGINTEGER
  SALIDA: UN BIGINTEGER QUE ES EL RESULTADO DE TODA ESA SUMA
  DESCRIPCIÓN: RECIBE UNA LISTA DE BIGINTEGER Y SUMA(PUEDE RESTAR SI HAY ELEMENTOS 
  NEGATIVOS CON POSITIVOS) CADA UNO DE SUS ELEMENTOS POSICION A POSICION, PARA DAR UN 
  BIGINTEGER QUE SEA EL RESULTADO DE LA SUMA*/
BigInteger BigInteger::sumarListaValores(deque<BigInteger> bigg){
    BigInteger resultado("");
    deque<BigInteger>::iterator it;
    for (it = bigg.begin(); it != bigg.end(); ++it) {
        resultado = resultado + *it;
    }
    return resultado;
}

/*FUNCION:multiplicarListaValores
  ENTRADA: UNA LISTA DE BIGINTEGER
  SALIDA: UN BIGINTEGER PUEDE SER POSITIVO 
  DESCRIPCIÓN: RECIBE UNA LISTA DE BIGINTEGER Y MULTIPLICA
  CADA UNO DE SUS ELEMENTOS POSICION A POSICION, PARA DAR UN 
  BIGINTEGER QUE SEA EL RESULTADO DE LA MULTIPLICACION*/
BigInteger BigInteger::multiplicarListaValores(deque<BigInteger> bigg){
    BigInteger resultado("");
    deque<BigInteger>::iterator it;
    for (it = bigg.begin(); it != bigg.end(); ++it) {
        resultado = resultado * *it;
    }
    return resultado;
}

/*FUNCION:toString
  ENTRADA: UN OBJETO BIGINTEGER
  SALIDA: UN STRING
  DESCRIPCIÓN: RECIBE UN BIGINTEGER Y UTILIZA LA FUNCION TO_STRING Y LA CONCATENA PARA OBTENER
  UN STRING CON TODOS LOS NUMEROS*/
string BigInteger::toString() {
    string cadena;
    for (int i=0;i<valor.size();i++) {
            cadena+=to_string(valor[i]);
        }
        return cadena;
}


//ANALIZADORAS//

/*FUNCION:tamano
  ENTRADA: UN OBJETO BIGINTEGER
  SALIDA: UN ENTERO POSITIVO
  DESCRIPCIÓN: RETORNA LA CANTIDAD DE DIGITOS QUE TIENE EL BIGINTEGER*/
int BigInteger::tamano(){
    return valor.size();
}

/*FUNCION:signo
  ENTRADA: UN OBJETO BIGINTEGER
  SALIDA: LA MODIFICACION DEL SIGNO
  DESCRIPCIÓN:COLOCA EL SIGNO CONTRARIO DEL SIGNO QUE TIENE MULTIPLICANDOLO CON -1 */
void BigInteger::signo() {
    if (valor[0] != 0) {
        valor[0] = valor[0]*-1;

        if(this->signopos==false){
        this->signopos=true;
        }
        else if(this->signopos==true){
            this->signopos=false;
        }
    }
}


//SOBRECARGA DE OPERADOR

/*FUNCION:operator+
  ENTRADA: DOS OBJETOS BIGINTEGER
  SALIDA: UN BIGINTEGER 
  DESCRIPCIÓN: RETORNA LA SUMA DE DOS BIGINTEGER SIN AFECTAR A NINGUNO DE LOS DOS*/
BigInteger BigInteger::operator+(BigInteger& elem) {
    int tam;
    int mas = 0;
    bool signoResultado = true;
    if (elem.tamano() >= valor.size()) {
        tam = elem.tamano();
        valor.insert(valor.begin(), elem.tamano() - valor.size(), 0);
    } else {
        tam = valor.size();
        elem.valor.insert(elem.valor.begin(), valor.size() - elem.valor.size(), 0);
    }
    vector<int> sum(tam, 0);
    for (int i = tam - 1; i >= 0; i--) {
        int conti;
        if (this->signopos && elem.signopos) {
            conti = valor[i] + elem.valor[i] + mas;
            if (conti >= 10 && i!=0) {
            mas = 1;
            sum[i] = conti % 10;
            } 
            else if(i==0){
                mas = 0;
                sum[i] = conti;
            }
            else {
            mas = 0;
            sum[i] = conti;
            }
            signoResultado = true;
        } 
        else if (!this->signopos && elem.signopos) {
            conti = elem.valor[i] - valor[i] + mas;
            if (conti >= 0) {
            mas = 0;
            sum[i] = conti;
            } else {
            mas = -1;
            sum[i] = conti + 10;
            }
            if (*this > elem) {
            signoResultado = false;
            } else {
            signoResultado = true;
            }
        } 
        else if (this->signopos && !elem.signopos) {
            conti = valor[i] - elem.valor[i] + mas;
            if (conti >= 0) {
            mas = 0;
            sum[i] = conti;
            } 
            else if(conti>=10){
            mas = -1;
            sum[i] = conti + 10;
            }
            else{
                sum[i] = conti;
            }
            if (*this < elem) {
            signoResultado = false;
            } else {
            signoResultado = true;
            }
        } 
        else if (!this->signopos && !elem.signopos) {
            conti = -valor[i] - elem.valor[i] + mas;
            if (conti >= 0) {
            mas = 0;
            sum[i] = conti;
            } else {
            mas = -1;
            sum[i] = conti + 10;
            }
            signoResultado = false;
        }
    }
    if (mas == -1) {
        sum.insert(sum.begin(), 1); // Insert 1 at the beginning
    }
    for (int j = 0; j < sum.size(); j++) {
        if (sum[j] < 0) {
            sum[j] *= -1;
        }
    }
    BigInteger c("");
    c.valor = sum;
    if (signoResultado == false) {
        c.signo();
    }
    c.signopos = signoResultado;
    return c;
    }

/*FUNCION:operator-
  ENTRADA: DOS OBJETOS BIGINTEGER
  SALIDA: UN BIGINTEGER 
  DESCRIPCIÓN: RETORNA LA RESTA DE DOS BIGINTEGER SIN AFECTAR A NINGUNO DE LOS DOS*/
BigInteger BigInteger::operator-(BigInteger& elem) {
    BigInteger devuelvo("");

    // Asegurarse de que los dos BigInteger tengan la misma cantidad de dígitos
    if (elem.tamano() > valor.size()) {
        int diff = elem.tamano() - valor.size();
        valor.insert(valor.begin(), diff, 0);
    } else if (elem.tamano() < valor.size()) {
        int diff = valor.size() - elem.tamano();
        elem.valor.insert(elem.valor.begin(), diff, 0);
    }

    vector<int> res(valor.size(), 0);
    int carry = 0;
    bool signoResultado = true;

    if (*this > elem) {
        for (int i = valor.size() - 1; i >= 0; i--) {
            int diff = valor[i] - elem.valor[i] - carry;
            if (diff < 0) {
                carry = 1;
                res[i] = diff + 10;
            } else {
                carry = 0;
                res[i] = diff;
            }
        }
        signoResultado = true;
    } else if (*this < elem) {
        for (int i = valor.size() - 1; i >= 0; i--) {
            int diff = elem.valor[i] - valor[i] - carry;
            if (diff < 0) {
                carry = 1;
                res[i] = diff + 10;
            } else {
                carry = 0;
                res[i] = diff;
            }
        }
        signoResultado = false;
    } 
    else {
        devuelvo.valor = { 0 };
        devuelvo.signopos = true;
    }

    devuelvo.valor = res;

    if (signoResultado == false) {
        devuelvo.signo();
    }
    devuelvo.signopos = signoResultado;
    return devuelvo;
}

/*FUNCION:operator*
  ENTRADA: DOS OBJETOS BIGINTEGER
  SALIDA: UN BIGINTEGER 
  DESCRIPCIÓN: RETORNA LA MULTIPLICACION DE DOS BIGINTEGER SIN AFECTAR A NINGUNO DE LOS DOS*/
BigInteger BigInteger::operator*(BigInteger& elem) {
    int tam = valor.size() + elem.valor.size();
    vector<int> sum(tam, 0);

    for (int i = valor.size() - 1; i >= 0; i--) {
        int carry = 0;

        for (int j = elem.valor.size() - 1; j >= 0; j--) {
            int conti = valor[i] * elem.valor[j] + carry + sum[i + j + 1];
            carry = conti / 10;
            sum[i + j + 1] = conti % 10;
        }

        sum[i] += carry;
    }

    bool signoPositivo = (signopos == elem.signopos);
    if (!signoPositivo) {
        sum[0] = -sum[0];
    }

    BigInteger c("");
    c.valor = sum;
    c.signopos = signoPositivo;
    return c;
}

/*FUNCION:operator<
  ENTRADA: DOS OBJETOS BIGINTEGER
  SALIDA: UN BOOL 
  DESCRIPCIÓN: DETERMINA SI ENTRE DOS BIGINTEGER SI ES MENOR*/
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
}

/*FUNCION:operator>=
  ENTRADA: DOS OBJETOS BIGINTEGER
  SALIDA: UN BOOL 
  DESCRIPCIÓN: DETERMINA SI ENTRE DOS BIGINTEGER SI ES MAYOR O IGUAL*/
bool BigInteger::operator>=(BigInteger& elem) {
    return !(operator<=(elem));
}

/*FUNCION:operator<=
  ENTRADA: DOS OBJETOS BIGINTEGER
  SALIDA: UN BOOL 
  DESCRIPCIÓN: DETERMINA SI ENTRE DOS BIGINTEGER SI ES MENOR O IGUAL*/
bool BigInteger::operator<=(BigInteger& elem) {
    bool resul = true;
    
    if (valor.size() < elem.valor.size()) {
        resul = true;
    } else if (valor.size() > elem.valor.size()) {
        resul = false;
    } else {
        int i = 0;
        while (i < valor.size() && valor[i] == elem.valor[i]) {
            i++;
        }
        
        if (i < valor.size()) {
            resul = valor[i] < elem.valor[i];
        }
    }
    
    return resul;
}

/*FUNCION:operator>
  ENTRADA: DOS OBJETOS BIGINTEGER
  SALIDA: UN BOOL 
  DESCRIPCIÓN: DETERMINA SI ENTRE DOS BIGINTEGER SI ES MAYOR */
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
}

/*FUNCION:operator==
  ENTRADA: DOS OBJETOS BIGINTEGER
  SALIDA: UN BOOL 
  DESCRIPCIÓN: DETERMINA SI ENTRE DOS BIGINTEGER SI ES IGUAL*/
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

/*FUNCION:operator!=
  ENTRADA: DOS OBJETOS BIGINTEGER
  SALIDA: UN BOOL 
  DESCRIPCIÓN: DETERMINA SI ENTRE DOS BIGINTEGER SI ES DISTINTO*/
bool BigInteger::operator!=(BigInteger& elem){
    return !(operator==(elem));
}

/*FUNCION:operator/
  ENTRADA: DOS OBJETOS BIGINTEGER
  SALIDA: UN BIGINTEGER
  DESCRIPCIÓN:SOBRECARGA EL / PARA QUE PUEDA REALIZAR LA DIVISION DE DOS BIGINTEGER;
  RETORNA UN BIGINTEGER RESULTADO DEL COCIENTE */
BigInteger BigInteger::operator/(BigInteger& elem) {
    int conti=0;
    BigInteger dividendo(*this);
    BigInteger divisor(elem);
    BigInteger aux(dividendo);
    BigInteger cero("0");
    bool sigo = false;

    while (aux >= divisor) {
        aux = aux - divisor;
        conti = conti + 1;
    }
    string cont1;
    cont1=to_string(conti);
    BigInteger conta(cont1);

    return conta;
}

/*FUNCION:operator%
  ENTRADA: DOS OBJETOS BIGINTEGER
  SALIDA: UN BIGINTEGER
  DESCRIPCIÓN:SOBRECARGA EL % PARA QUE PUEDA REALIZAR LA DIVISION DE DOS BIGINTEGER;
  RETORNA UN BIGINTEGER CON EL RESULTADO DEL RESIDUO */
BigInteger BigInteger::operator%(BigInteger& elem) {
    int conti=0;
    BigInteger dividendo(*this);
    BigInteger divisor(elem);
    BigInteger aux(dividendo);
    BigInteger cero("0");
    bool sigo = false;

    while (aux >= divisor) {
        aux = aux - divisor;
        conti = conti + 1;
    }

    return aux;
}




