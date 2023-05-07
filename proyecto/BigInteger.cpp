
#include "BigInteger.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


BigInteger::BigInteger(Elemento elem){
    vector<int> vec;
    for(int i=0;i<elem.size();i++){
        int posi= elem[i]-'0';
        vec.push_back(posi);
    }
    for(int i=0;i<vec.size();i++){
        cout<<"p"<<i<<endl<<vec[i]<<endl;
    }
}

BigInteger::BigInteger(){

}

void BigInteger::add(BigInteger& elem){
    
}

void BigInteger::product(BigInteger& elem){

}

void substract(BigInteger& elem){

}

void quotient(BigInteger& elem){

}

void remainder(BigInteger& elem){

}

void pow(BigInteger& elem){

}

Elemento BigInteger::toString() {

}
