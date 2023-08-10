#include <stdio.h>

void Insert(int H[], int n) {
    int i=n, temp;
    temp=H[n];

    while (i>1 && temp>H[i/2])
    {
        H[i]=H[i/2];
        i=i/2;
    }
    H[i]=temp;

}

int Delete(int A[], int n) {
    int i,j,x;
    x=A[n];
    A[1]=A[n];
}

int main(){
    int H[]={0,1,2,3,4,5,6,7,8,9,10};

    for (int i = 0; i < 15; i++)
    {
        printf("%d ", H[i]);
    }

    printf("\n\n\n");

    // Insert(H,2);
    // Insert(H,3);
    // Insert(H,4);

    // for (int i = 0; i < 12; i++)
    // {
    //     printf("%d ", H[i]);
    // }
    

    return 0;
}