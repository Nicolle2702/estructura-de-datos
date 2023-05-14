
//NICOLLE RUIZ QUINTERO CODIGO: 8974036

//LA COMPLEJIDAD DE ESTE PROGRAMA ES DE O(N*2) EN EL PEOR DE LOS CASOS YA QUE TIENE QUE RECORRER TODA LA LISTA 2 VECES,
// PERO EN EL MEJOR DE LOS CASOS ES O(N) YA QUE ESTE SOLO TENDRIA QUE INSERTAR UN ELEMENTO AL PRINCIPIO Y FINAL DE LA LISTA.

#include<iostream>
#include<list>
#include<deque>

using namespace std;

int buscaNum(deque<int>& lista, int pos){
    int i = 0;
    int c = -1;
    for (deque<int>::iterator it=lista.begin();it!=lista.end();it++){
        i++;
        if (*it==pos){
            c=i;
        }
    }
    return c;
}

int main(){
    int numpaci; 
    int numacci;
    cin>>numpaci;
    cin>>numacci;
    int j=1;
    while(numpaci!=0 && numacci!=0){
        deque<int> pacien;
        deque<int> fin;
        int veces;
        if(numacci>numpaci){
            veces=numpaci;
        }
        else if(numacci<numpaci){
            veces=numacci;
        }
        else if(numacci==numpaci){
            veces=numpaci;
        }
        for (int i=1;i<=veces;i++) {
            pacien.push_back(i);
        }
        for (int o=1;o<=numacci;o++) {
            char que;
            cin>>que;
            if (que=='N') {
                pacien.push_back(pacien.front());
                fin.push_back(pacien.front());
                pacien.pop_front();
            } 
            else if(que=='E') {
                int numm;
                cin>>numm;
                if(numm>numacci){
                    pacien.push_front(numm);
                }
                else{
                    int c=buscaNum(pacien,numm);
                    pacien.erase(pacien.begin() + c - 1);
                    pacien.push_front(numm);
                }
            }
        }
        cout<<"Case "<<j<<":"<< endl;
        for (deque<int>::iterator it=fin.begin();it!=fin.end();it++) {
            cout <<*it << endl;
        }
        cin>>numpaci;
        cin>>numacci;
        j=j+1;
    }
    return 0;
}

