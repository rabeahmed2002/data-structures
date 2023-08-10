// #include <stdio.h>
// #include <stdlib.h>

// class Array {
//     private:
//         int *A;
//         int size;
//         int length;

//     public:
//         Array(){
//             size=10;
//             length=0;
//             A=new int[10];
//         }

//         Array(int sz){
//             size=sz;
//             length=0;
//             A=new int[size];
//         }
        
//         ~Array() {
//             delete []A;
//         }

//         void Display();
//         void Append(int x);
//         void Insert(int index, int value);
//         int Delete(int index);
//         void Swap(int *x, int *y);
//         int LinearSearch(int key);
//         int BinarySearch(int key);
//         int Max();
//         int Min();
//         int Sum();
//         int Reverse();
//         void InsertSort(int val);
//         int Sort();
//         void Rearrange();
// };

// void Array::Display() {
//     int i;
//     printf("Elements are: \n");
//     for (int i = 0; i < length; i++)
//     {
//         printf("%d ", A[i]);
//     }
// }

// void Array::Append(int x) {
//     if (length<size) 
//     {
//         A[length++]=x;
//     }
// }

// void Array::Insert(int index, int value) {
//     if (index>=0 && index <= length)
//     {
//         for (int i = length; i>index; i--)
//         {
//             A[i]=A[i-1];
//         }
//         A[index]=value;
//         length++;
//     }
// }

// int Array::Delete(int index) {
//     int x=0;
//     if (index>=0 && index < length)
//     {
//         x=A[index];
//         for (int i = index; i < length-1; i++)
//         {
//             A[i]=A[i+1];
//         }
//         length--;
//         return x;
//     }   
//     return 0;
// }

// void Array::Swap(int *x, int *y) {
//     int temp;
//     temp=*x;
//     *x=*y;
//     *y=temp;
// } 

// int Array::LinearSearch(int key) {

//         for (int i = 0; i < length; i++)
//         {
//             if (key==A[i])
//             {
//                 Swap(A[i],[0]);
//                 return i;
//             }
//         }    
//         return-1;
// }

// int Array::BinarySearch(int key) {
//     int l, mid, h;
//     l=0;
//     h=length-1;

//     while (l<=h)
//     {
//         mid=(l+h)/2;
//         if (key==A[mid]) return 
//         mid;
        
//         else if(key < A[mid]) {
//             h=mid-1;
//         }   else {
//             l=mid+1;
//         }
//     return -1;
//     }
// }

// int Array::Max() {
//     int max=A[0];
//     for (int i = 0; i <length; i++)
//     {
//         if (A[i]>max)
//         {
//             max=A[i];
//         }
//     }
//     return max;    
// }

// int Array::Min() {
//     int min=A[0];
//     for (int i = 0; i < length; i++)
//     {
//         if (A[i]<min)
//         {
//             min=A[i];
//         }
//     }
//     return min;    
// }

// int Array::Sum() {
//     int total=0;
//     for (int i = 0; i < length; i++)
//     {
//         total=total+A[i];
//     }
    
//     return total;    
// }

// int Array::Reverse() {
//     int i=0;
//     int j=length-1;
//     for (i=0, j=length-1; i<j; i++, j--)
//     {
//         Swap(A[i], A[j]);
//     }
// }

// void Array::InsertSort(int val) {
//     int i=length-1; 
//     if (length==size) //checking if there is free space in an array
//         return;
//     while (i>=0 && A[i]>val)
//     {
//         A[i+1]==A[i];
//         i--;
//     }
//     A[i+1]=val;
//     length++;
// }

// int Array::Sort() {
//     for (int i = 0; i < length -1; i++)
//     {
//         if (A[i] > A[i+1])
//         {
//             return 0;
//         }
//     }
//     return 1;
// }

// void Array::Rearrange() {
//     int i=0;
//     int j=(length)-1;
//     while (i<j)
//     {
//         while (A[i]<0)
//         {
//             i++;
//         }

//         while (A[i]>=0)
//         {
//             j--;
//         }
        
//         if (i<j)
//         {
//             Swap(A[i], A[j]);
//         }
//     }
// }

// Array* Merge(Array arr2) {
//     int i=0;
//     int j=0;
//     int k=0;
//     Array *arr3=new Array(length+arr2.length);

//     while (i<length && j<length)
//     {
//         if (A[i] < A[j])
//         {
//             A[k++]=A[i++];
//         }
//         else {
//             A[k++]=A[j++];
//         }
        
//     }
    
//     for (; i < arr1->length; i++)
//     {
//         arr3->A[k++]=arr1->A[i];
//     }

//     for (; i < arr2->length; j++)
//     {
//         arr3->A[k++]=arr2->A[j];
//     }
    
//     arr3->length=arr1->length+arr2->length;
//     arr3->size=10;
//     return arr3;
// }

// int main() {
//     // struct Array arr={{1,-2,6,-15,19},10,5};
//     // struct Array arr1={{1,3,5,7,9},10,5};
//     // struct Array arr2={{2,4,6,8,10},10,5};
//     // struct Array *arr3;   

//     struct Array arr1; 
//     int ch;
//     int x, index;

//     printf("Enter size: ");
//     scanf("%d", &arr1.size);
//     arr1.A=(int *)malloc(arr1.size*sizeof(int));

//     while (ch<6) {    
//         printf("Menu\n");
//         printf("1. Insert\n");
//         printf("2. Delete\n");
//         printf("3. Search\n");
//         printf("4. Sum\n");
//         printf("5. Display\n");
//         printf("6. Exit\n");

//         printf("Enter your operation: ");
//         scanf("%d", &ch);

//         switch (ch)
//         {
//         case 1: printf("Enter an element and index: ");
//             scanf("%d, %d", &x, &index);
//             Insert(&arr1, index, x);
//             break;

//         case 2: printf("Enter an index: ");
//             scanf("%d", &index);
//             x=Delete(&arr1, index);
//             printf("Deleted element is %d\n", x);
//             break;
        
//         case 3: printf("Enter an element to search: ");
//             scanf("%d", &x);
//             index=LinearSearch(&arr1, x);
//             printf("Deleted element is %d\n", index);
//             break;

//         case 4: printf("Sum is %d\n", Sum(&arr1));
//             break;

//         case 5: Display(arr1);
//     }
//     return 0;
//     }
// }

#include <iostream>
using namespace std;

template <class T>

class Array {
    private:
        T *A;
        int size;
        int length;

    public:
        Array() {
            size=10;
            A=new T[10];
            length=0;
        }

        Array(int sz) {
            size=sz;
            length=0;
            A=new T[size];
        }

        ~Array() {
            delete []A;
        }

        void Display();
        void Insert(T index, T x);
        int Delete(T index);
};

template <class T>
void Array<T>::Display() {
    for (int i = 0; i < length; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

template <class T>
void Array<T>::Insert(T index, T x) {
    if (index>=0 && index<=length)
    {
        for (int i = length-1; i >= index; i--)
        {
            A[i+1]=A[i];
        }
        A[index]=x;
        length++;
    }   
}

template <class T>
int Array<T>::Delete(T index) {
    T x=0;
    if (index>=0 && index<length)
    {
        x=A[index];
        for (int i = index; i < length-1; i++)
        {
            A[i]=A[i+1];
        }
        length--;
    }
    return x;
}

int main() {

    Array <float> arr(10);
    arr.Insert(0,5.3);
    arr.Insert(1,6.9);
    arr.Insert(2,9.6);
    arr.Display();

    cout<<arr.Delete(0)<<endl;
    arr.Display();

    return 0;
}