#include <stdio.h>

int fact(int n)
{
    if(n==0)
    return 1;
    return fact(n-1)*n;
}

//normal function
int nCr(int n, int r) {
    int t1,t2,t3;
    t1=fact(n);
    t2=fact(r);
    t3=fact(n-r);
    return t1/(t2*t3);
}

//recursive function
int nCrRecursive(int n, int r) {
    if (n==r || r==0)
    {
        return 1;
    }   else {
        return nCrRecursive(n-1,r-1)+nCrRecursive(n-1,r);
    }
    
}

int main() {
    printf("%d", nCrRecursive(5,3));
    return 0;
}