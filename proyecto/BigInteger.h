#ifndef __LISTA_H
#define __LISTA_H

#include <iostream>
#include <vector>
#include <string>

/************************
* ESTRUCTURAS DE DATOS *
************************/

using namespace std;
typedef string Elemento;


class BigInteger{
    private:
        vector<int> valor;

    public:
        BigInteger(Elemento elem);
        BigInteger();

        void add(BigInteger& elem);
        void product(BigInteger& elem);
        void substract(BigInteger& elem);
        void quotient(BigInteger& elem);
        void remainder(BigInteger& elem);
        void pow(BigInteger& elem);
        Elemento toString();

    //SOBREGARGA DE OPERADORES:
        Biginteger operator+(BigInteger elem);
        Biginteger operator-(BigInteger elem);
        Biginteger operator*(BigInteger elem);
        Biginteger operator/(BigInteger elem);
        Biginteger operator%(BigInteger elem);
        bool operator==(BigInteger elem);
        bool operator<(BigInteger elem);
        bool operator<=(BigInteger elem);



};

#endif
