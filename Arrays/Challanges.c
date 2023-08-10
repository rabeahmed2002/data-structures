#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[10];
    int size;
    int length;
};

void missingEle(struct Array arr) { //missing element in a sorted list, n starting from 1
    int sum=0,s,n=0;
    for (int i = 0; i < arr.length; i++)
    {
        sum=sum+arr.A[i];
    }
    n=arr.length * (arr.length + 1)/2;
    printf("The missing element is %d", n-sum);
}

void missingElement(struct Array arr) {
    int n,diff,l,i=0;
    l=arr.A[0];
    n=arr.length;
    diff=arr.A[1]-1;
    for (int i = 0; i < n; i++)
    {
        if (arr.A[i]-i != diff)
        {
            printf("The missing element is: %d", i+diff);
        }
    }
}

void multipleMissing(struct Array arr) {
    int n, diff, l;
    diff=arr.A[0];

    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i]-i != diff)
        {
            while (diff < arr.A[i]-i)
            {
                printf("The element is %d \n", i+diff);
                diff++;
            } 
        }
    }
}

void findDuplicate(struct Array arr) {
    int lastDuplicate=0, count=0;

    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i]==arr.A[i+1])
        {
            lastDuplicate=arr.A[i];
            count++;
            printf("Duplicate element is %d\nThe number of duplicate elements are %d", lastDuplicate, count);
        }
        
    }
}

void unsortedDuplicate(struct Array arr){
    for (int i = 0; i < arr.length - 1; i++)
    {
        int count=1;
        if (arr.A[i] != -1)
        {
            for (int j = i+1; j < arr.length - 1; j++)
            {
                if (arr.A[i]==arr.A[j])
                {
                    count++;
                    arr.A[j]=-1;
                }
                
            }
        }
        
        if (count > 1)
        {
            printf("The element  %d and it is repeated %d times\n", arr.A[i], count);
        } 
    }
} 

void pairOfSum(struct Array arr, int k) {
    for (int i = 0; i < arr.length - 1; i++)
    {
        for (int j = i+1; j < arr.length - 1; j++)
        {
            if (arr.A[i] + arr.A[j]==k)
            {
                printf("The pair of numbers is %d and %d\n", arr.A[i], arr.A[j]);
            }
        }
    }
}

void sortedPairOfSum(struct Array arr, int k) {
    int i=0, j=arr.length-1;
    while (i<j)
    {
        if (arr.A[i]+arr.A[j]==k)
        {
            printf("The pair of numbers is %d and %d\n", arr.A[i], arr.A[j]);
            i++;
            j--;
        }

        else if (arr.A[i]+arr.A[j] > k) {
            j--;
        }

        else if (arr.A[i]+arr.A[j] < k) {
            i++;
        }
    }
}

void maxMin(struct Array arr) {
    int min=arr.A[0], max=arr.A[0];

    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i]<min)
        {
            min=arr.A[i];
        }

        else if (arr.A[i]>max) {
            max=arr.A[i];
        }
    }

    printf("Min=%d\nMax=%d", min, max);

}

int main() {
    struct Array arr={{1,3,5,10,4,6,7,16,0,8},10,10};

    maxMin(arr);

    return 0;

}