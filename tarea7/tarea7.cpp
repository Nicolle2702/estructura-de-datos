#include<iostream>
#include<stack>
#include<deque>
#include<algorithm>
#include<queue>

using namespace std;


//PUNTO 1
void eliminarPosicionesPila(stack<int>& pil,deque<int>& l){
    stack<int> paso;
    int c=pil.size();
    sort(l.begin(),l.end());
    int j=0;
    for(int i=0; i<c;i++){
        if(!l.empty()&& l.front()==i){
            cout<<"elimino la posi "<<l.front()<<endl;
            pil.pop();
            l.erase(l.begin());
        }
        else{
            cout<<"agrego el elemento "<<pil.top()<<endl;
            paso.push(pil.top());
            pil.pop();
        }
    }
    int k=paso.size();
    for(int j=0; j<k;j++){
        pil.push(paso.top());
        paso.pop();
    }
}


//PUNTO 3
bool verificarOrdenadoCola(queue<int>& colita){
    bool ascendente=true;
    bool descendente=true;
    int c=colita.size();
    int prev;
    int sig;
    prev=colita.front();
    colita.pop();
    for(int i=0; i<c;i++){
        sig=colita.front();
        colita.pop();
        if(prev>sig){
            ascendente=false;
        }
        else if(prev<sig){
            descendente=false;
        }
        prev=sig;
    }
    return ascendente || descendente;
}


//PUNTO 4

int obtenerMenorCosto(deque<int>& l){
    sort(l.begin(),l.end());
    int n=0;
    int z=l.front();
    l.erase(l.begin());
    int j=l.front();
    l.erase(l.begin());
    n=z+j;
    int k=n;
    int c=l.size();
    for(int i=0;i<c;i++){
        n=n+l.front();
        l.erase(l.begin());
        k=k+n;
    }
    return k;
}

//PUNTO 5

void evaluarExpresion(deque<string>& carac){
    bool mas=false;
    bool menos=false;
    bool multi=false;
    int c=carac.size();
    for(int i=1;i<=c;i++){
        if(carac.front()=="(" ||carac.front()==")"){
            carac.erase(carac.begin());
        }
        else if(carac.front()=="+"){
            mas=true;
        }
        else if(carac.front()=="-"){
            menos=true;
        }
        else if(carac.front()=="*"){
            multi=true;
        }

    }

}
