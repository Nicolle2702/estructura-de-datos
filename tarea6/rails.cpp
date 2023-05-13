#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<deque>

using namespace std;

int main(){
    stack<int> de1aN; // guarda de 1 a N
    stack<int> acomodo; // Guarda lo que el usuario coloca
    stack<int> predeterminado; // guarda otra vez lo que el usuario coloca
    stack<int> transicion; // guarda los elementos para transicion
    stack<int>fin; // lista final
    int veces;
    bool continuo=true;
    bool iguales;
    int num;
    while(continuo){
        cin>>veces;
        if(veces == 0 && num== 0) {
            continuo=false;
        }
        else{
            for(int i=1; i<=veces;i++){
                int num;
                cin>>num;
                de1aN.push(i);
                acomodo.push(num);
                predeterminado.push(num);
                if(!acomodo.empty() && !de1aN.empty() && de1aN.top()==acomodo.top()){
                    fin.push(acomodo.top());
                    de1aN.pop();
                    acomodo.pop();
                }
                else if (!acomodo.empty() && !de1aN.empty() && de1aN.top()!=acomodo.top()){
                    transicion.push(de1aN.top());
                    de1aN.pop();
                    acomodo.pop();
                }
                else if(!acomodo.empty() && !transicion.empty()&& acomodo.top()==transicion.top()){
                    fin.push(transicion.top());
                    de1aN.pop();
                    acomodo.pop();
                }
                else if(!acomodo.empty() && !transicion.empty()&& acomodo.top()!=transicion.top()){
                    fin.push(transicion.top());
                    de1aN.pop();
                    acomodo.pop();
                }
            }
            iguales=true;
            for(int j=1;j<=fin.size();j++){
                if(fin.top()==predeterminado.top()){
                    fin.pop();
                    predeterminado.pop();
                    iguales=true;
                }
                else if(fin.top()!=predeterminado.top()){
                    fin.pop();
                    predeterminado.pop();
                    iguales=false;
                }
            }
            if(iguales==true){
                cout<<"Yes"<<endl;
            }
            else if(iguales==false){
                cout<<"No"<<endl;
            }
        }

        de1aN=stack<int>();
        acomodo=stack<int>();
        predeterminado=stack<int>();
        transicion=stack<int>();
        fin=stack<int>();
    }
    return 0;
}