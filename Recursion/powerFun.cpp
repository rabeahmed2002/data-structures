#include<stdio.h>
#include<stdlib.h>

int sum(int m, int n) {
    if (n==0) {
        return 1;
    }   else if (n%2==0) {
        return sum(m*m,n/2);
    }   else {
        return m* sum(m*m,(n-1)/2);
    }
}

int main()
{
    int y=sum(2,6);
    printf("%d", y);
    return 0;
}