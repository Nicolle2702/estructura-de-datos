//Nicolle Ruiz Quintero Ing.Biomedica CODIGO: 8974036

#include <stdio.h>
#include <stdlib.h>

int main(){
    int cantNum, i, dife, esJolly;
    while(scanf("%d",&cantNum)!=EOF){
        int numeros[3000];
        int resta[3000] = {0};
        scanf("%d", &numeros[0]); 
        esJolly = 1;
        for(i=1;i<cantNum; i++){
            scanf("%d",&numeros[i]);
            dife = abs(numeros[i] - numeros[i-1]);
            if (dife < 1 || dife >= cantNum || resta[dife-1] == 1) {
                esJolly = 0;
            } else {
                resta[dife-1] = 1;
            }
        }
        if(esJolly){
            printf("Jolly\n");
        } else {
            printf("Not jolly\n");
        }
    }
    return 0;
}