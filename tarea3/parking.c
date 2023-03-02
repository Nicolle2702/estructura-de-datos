//Nicolle Ruiz Quintero Ing.Biomedica CODIGO: 8974036


#include <stdio.h>

int main(){

    int arreglo[99];
    int casos,min,max,nTiendas,i,j,z,total,dis;
    max=0;
    min=1000;
    scanf("%d",&casos);
    for(i=1; i<=casos; i++){
        scanf("%d",&nTiendas);
        scanf("%d",&arreglo[0]);
        max=arreglo[0];
        min=max;
        for(j=1; j<nTiendas; j++){
            scanf("%d",&arreglo[j]);
            if(arreglo[j]>max){
                max=arreglo[j];
            }
            if(arreglo[j]<min){
                min=arreglo[j];
            }
        }
    printf("%d\n",(max-min)*2);
    }
    return 0;
}

