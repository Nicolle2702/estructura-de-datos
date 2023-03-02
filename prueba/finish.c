//Nicolle Ruiz Quintero Ing.Biomedica CODIGO: 8974036

#include <stdio.h>

int main() {
    int casos, numGasoli, i, j, tanqueGas, primerEstacion;

    scanf("%d", &casos);
    int arreglo2[100001];
    int arreglo1[100001];
    for (i = 1; i <= casos; i++) {
        scanf("%d", &numGasoli);
        for (j = 1; j <= numGasoli; j++) {
            scanf("%d", &arreglo1[j]);    
        }
        for (j = 1; j <= numGasoli; j++) {
            scanf("%d", &arreglo2[j]);    
        }

        primerEstacion = 1;
        j = 1;
        int posible = 0;
        while (j <= numGasoli) {
            tanqueGas = 0;
            int k = 0;
            while (k < numGasoli && tanqueGas >= 0) {
                int pos = (j + k - 1) % numGasoli + 1;
                tanqueGas += arreglo1[pos] - arreglo2[pos];
                k++;
            }
            if (tanqueGas < 0) {
                primerEstacion = j + k;
                j = primerEstacion;
            } else {
                printf("Case %d: Possible from station %d\n", i, j);
                posible = 1;
                j = numGasoli + 1; 
            }
        }
        if (!posible) {
            printf("Case %d: Not possible\n", i);
        }
    }
    return 0;
}






