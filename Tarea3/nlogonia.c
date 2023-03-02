#include <stdio.h>

int main(){

    int x,y,k,i,n,m;
    scanf("%d",&k);
    while (k!=0){
        scanf("%d",&n);
        scanf("%d",&m);
        for(i=0;i<k;i++){
            scanf("%d",&x);
            scanf("%d",&y);
            
            if (x==n || y==m ){
                printf("divisa\n");
            }
            else if(x>n && y>m ){
                printf("NE\n");
            }
            else if(x>n && y<m){
                printf("SE\n");
            }
            else if(x<n && y>m){
                printf("NO\n");
            }
            else {
                printf("SO\n");
            }
        }
            

    scanf("%d",&k);
    }
    return 0;
}