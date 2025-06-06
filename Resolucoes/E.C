#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calcularMDC(int a, int b) {
    if (b == 0) {
        return a;
    }
    return calcularMDC(b, a % b);
}

int main(){
    int x = 1;
    int y;
    int k;
    scanf("%d", &y);	
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        int mdc = calcularMDC(x,y);
        x = x + mdc; 
    }
    printf("%d\n", x);
    return 0;
}