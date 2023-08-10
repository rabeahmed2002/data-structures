#include <stdio.h>

//Using loop
int hornetTaylorLoop(int x, int n) {
    int s=1;
    for (int i; n > 0; n--)
    {
        s=1+(x/n)*s;
    }
    return s;
}

//Using recursion
int hornetTaylorRec(int x, int n) {
    static int s=1;
    if (n==0)
    {
        return s;
    }   else {
        s=1+x/n*s;
        return hornetTaylorRec(x,n-1);
    }
    
}

int main() {
    printf("%d", hornetTaylorRec(2,4));
}