#ifndef __LISTA_H
#define __LISTA_H

#include<iostream>
#include<vector>
#include<string>
#include<deque>

/************************
* ESTRUCTURAS DE DATOS *
************************/

using namespace std;

class BigInteger{
    private:
        vector<int> valor;
        bool signopos=true;
    public:
        //CONSTRUCTORAS
        BigInteger(const string& elem);
        BigInteger(const BigInteger& elem2);
        //MODIFICADORAS
        void add(BigInteger& elem);
        void product(BigInteger& elem);
        void substract(BigInteger& elem);
        void quotient(BigInteger& elem);
        void remainder(BigInteger& elem);
        void pow(int elem);
        static BigInteger sumarListaValores(deque<BigInteger> bigg);
        static BigInteger multiplicarListaValores(deque<BigInteger> bigg);
        string toString();
        //ANALIZADORAS
        int tamano();
        void signo();
        //SOBREGARGA DE OPERADORES:
        BigInteger operator+(BigInteger& elem);
        BigInteger operator-(BigInteger& elem);
        BigInteger operator*(BigInteger& elem);
        BigInteger operator/(BigInteger& elem);
        BigInteger operator%(BigInteger& elem);
        bool operator==(BigInteger& elem);
        bool operator<(BigInteger& elem);
        bool operator<=(BigInteger& elem);
        bool operator>(BigInteger& elem);
        bool operator>=(BigInteger& elem);
        bool operator!=(BigInteger& elem);



};

#endif