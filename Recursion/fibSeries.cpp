#include <stdio.h>

//excessive resucrsion
int fibSeries(int n) {
    if (n<=1) {
        return n;
    }   else {
        return fibSeries(n-2) + fibSeries(n-1);
    }
}

//memoization
int F[10];
int fibSeriesMem(int n) {
    if (n<=1){
        F[n]=n;
        return n;
    }   else{
        if(F[n-2]==-1) {
            F[n-2]=fibSeriesMem(n-2);
        }
        if(F[n-1]==-1) {
            F[n-1]=fibSeriesMem(n-1);
        }
    }
    return F[n-2]+F[n-1];
}


int main() {
    int i;
    for (int i = 0; i < 10; i++)
    {
        F[i]=-1;
    }
    
    printf("%d", fibSeriesMem(100 ));
}