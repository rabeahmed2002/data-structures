#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int Hash(int key) {
    return key%SIZE;
}

int probe(int H[], int key) {
    int i=0;
    int index=Hash(key);

    while (H[(index+i)%SIZE]!=0)
    {
        i++;
    }
    
    return (index+i)%SIZE;

}

void Insert(int H[], int key) {
    int index=Hash(key);

    if (H[index]!=0)
    {
        index=probe(H,key);
    }
    H[index]=key;

}

int Search(int H[], int key){
    int i=0;
    int index=Hash(key);

    while (H[(index+i)%SIZE]!=key)
    {
        i++;
    }
    return (index+i)%SIZE;

}

int main() {
    int HT[10];

    Insert(HT,12);
    Insert(HT,25);
    Insert(HT,35);
    Insert(HT,26);

    printf("Key found at %d", Search(HT, 35));


    return 0;
}