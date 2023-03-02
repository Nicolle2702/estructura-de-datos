#include <stdio.h>

int main() {
    int casos, numGasoli, i, j, z, l, sigo,k;

    scanf("%d", &casos);
    int arreglo2[100001];
    int arreglo1[100001];
    for (i = 1; i <= casos; i++) {
        scanf("%d", &numGasoli);
        for (j = 1; j <= numGasoli; j++) {
            scanf("%d", &arreglo1[j]);    
        }
        for (z = 1; z <= numGasoli; z++) {
            scanf("%d", &arreglo2[z]);
        }
        int pos = 1;
        int tank = 0;
        int estaVisitadas = 0;
        sigo = 1;
        while (sigo && estaVisitadas < numGasoli) {
            tank += arreglo1[pos] - arreglo2[pos - 1];
            if (tank < 0) {
                tank = 0;
                estaVisitadas = 0;
                pos++;
                if (pos > numGasoli) {
                    pos = 1;
                }
            } else {
                estaVisitadas++;
                pos++;
                if (pos > numGasoli) {
                    pos = 1;
                }
                if (arreglo2[pos] >= arreglo2[pos - 1]) {
                    sigo = 1;
                } else {
                    sigo = 0;
                }
                if (pos == 1) {
                    l = numGasoli;
                } else {
                    l = pos - 1;
                }
            }
        }
        if (estaVisitadas == numGasoli) {
            printf("Case %d: Possible from station %d\n", i, l);
        } else {
            printf("Case %d: Not possible\n", i);
        }
    }
    return 0;
}





