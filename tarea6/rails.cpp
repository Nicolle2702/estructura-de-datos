
//NICOLLE RUIZ QUINTERO CODIGO: 8974036

/* LA COMPLEJIDAD DE ESTE CODIGO ES DE O(N) YA QUE EN EL PEOR DE LOS CASOS TIENE QUE RECORRER SOLO 1 VEZ TODO EL CICLO 
*/


#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main() {
    stack<int> de1aN; // guarda de 1 a N
    stack<int> acomodo; // Guarda lo que el usuario coloca
    queue<int> predeterminado; // guarda otra vez lo que el usuario coloca
    stack<int> transicion; // guarda los elementos para transicion
    stack<int> fin; // lista final
    int veces;
    bool continuo=true;
    bool iguales;
    int num;
    int contiwhi=true;
    cin>>veces;
    while(continuo) {
        if(veces==0) {
            cin>>veces;
            if(veces==0) {
                continuo=false;
            } else {
                de1aN=stack<int>();
                acomodo=stack<int>();
                predeterminado=queue<int>();
                transicion=stack<int>();
                fin=stack<int>();
            }
        }
        else if(veces!=0){
            for(int i=1;i<=veces;i++) {
                int num;
                cin >> num;
                de1aN.push(i);
                acomodo.push(num);
                predeterminado.push(num);
            }
            for(int i = 1; i <= veces; i++){
                if(!acomodo.empty() && !de1aN.empty() && de1aN.top() == acomodo.top()) {
                    fin.push(acomodo.top());
                    de1aN.pop();
                    acomodo.pop();
                } else if (!acomodo.empty() && !de1aN.empty() && de1aN.top() != acomodo.top()) {
                    transicion.push(de1aN.top());
                    de1aN.pop();
                    acomodo.pop();
                } if(!acomodo.empty() && !transicion.empty() && acomodo.top() == transicion.top()) {
                    fin.push(transicion.top());
                    transicion.pop();
                    acomodo.pop();
                } else if(!acomodo.empty() && !transicion.empty() && acomodo.top() != transicion.top()) {
                    fin.push(transicion.top());
                    transicion.pop();
                    acomodo.pop();
                }
            }
            iguales=true;
            while(!fin.empty() && !predeterminado.empty() && contiwhi==true) {
                if(fin.top()==predeterminado.front()) {
                    fin.pop();
                    predeterminado.pop();
                    iguales=true;
                    contiwhi=true;
                } else {
                    iguales =false;
                    contiwhi=false;
                    fin.pop();
                    predeterminado.pop();
                }
            }
            if(iguales) {
                cout<<"Yes"<<endl;
            } else {
                cout<<"No"<<endl;
            }
            cin>>veces;
        }
        de1aN=stack<int>();
        acomodo=stack<int>();
        predeterminado=queue<int>();
        transicion=stack<int>();
        fin=stack<int>();
    }
    return 0;
}
