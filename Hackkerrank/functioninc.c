#include <stdio.h>

int max_of_four(int a, int b, int c, int d) {
    int max = a;    
    if (b > max) {
        max = b;
    }
    else if (c > max) {
        max = c;
    }
    else if (d > max) {
        max = d;
    }
    
    return max;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int result = max_of_four(a, b, c, d);
    printf("%d\n", result);
    
    return 0;
}
