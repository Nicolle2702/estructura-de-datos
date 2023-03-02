#include <stdio.h>

int main() {
    int i, j, posI1, posA, posI2, posI3, k, z;
    scanf("%d", &posA);
    scanf("%d", &posI1);
    scanf("%d", &posI2);
    scanf("%d", &posI3);
    z = 2;
    while (z == 2) {
        if (posA == 0 && posI1 == 0 && posI2 == 0 && posI3 == 0) {
            z = 0;
        } else {
            int a, b, c;
            a = b = c = 0;
            for (i = 1; i <= 3; i++) {
                if (i == 1) {
                    j = posA - posI1;
                    if (j < 0) {
                        j += 40;
                    }
                    a = j * 9;
                } else if (i == 2) {
                    j = posI2 - posI1;
                    if (j < 0) {
                        j += 40;
                    }
                    b = j * 9;
                } else if (i == 3) {
                    j = posI2 - posI3;
                    if (j < 0) {
                        j += 40;
                    }
                    c = j * 9;
                }
            }
            k = (a + b + c) + 1080;
            printf("%d\n", k);
            scanf("%d", &posA);
            scanf("%d", &posI1);
            scanf("%d", &posI2);
            scanf("%d", &posI3);
        }
    }
    return 0;
}





