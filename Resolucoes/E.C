#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b)
{
    // Find Minimum of a and b
    int result = ((a < b) ? a : b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }

    // Return gcd of a and b
    return result;
}

int main(){
    int x = 1;
    int y = 0;
    int k = 0;
    scanf("%d", &y);	
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        int mdc = gcd(x,y);
        x = x + mdc; 
    }
    printf("%d\n", x);
    return 0;
}