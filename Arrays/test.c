// #include <stdio.h>
// #include <stdlib.h>

// struct Array {
//     int *A;
//     int size;
//     int length;
// };

// void Display(struct Array arr) {
//     int i;
//     printf("Elements are: \n");
//     for (int i = 0; i < arr.length; i++)
//     {
//         printf("%d ", arr.A[i]);
//     }
// }

// void Append(struct Array *arr, int x) {
//     if (arr->length<arr->size) 
//     {
//         arr->A[arr->length++]=x;
//     }
// }

// void Insert(struct Array *arr, int index, int value) {
//     if (index>=0 && index <= arr->length)
//     {
//         for (int i = arr->length; i>index; i--)
//         {
//             arr->A[i]=arr->A[i-1];
//         }
//         arr->A[index]=value;
//         arr->length++;
//     }
// }

// int Delete(struct Array *arr, int index) {
//     int x=0;
//     if (index>=0 && index < arr->length)
//     {
//         x=arr->A[index];
//         for (int i = index; i < arr->length-1; i++)
//         {
//             arr->A[i]=arr->A[i+1];
//         }
//         arr->length--;
//         return x;
//     }   
//     return 0;
// }

// void Swap(int *x, int *y) {
//     int temp;
//     temp=*x;
//     *x=*y;
//     *y=temp;
// } 

// int LinearSearch(struct Array *arr,int key) {

//         for (int i = 0; i < arr->length; i++)
//         {
//             if (key==arr->A[i])
//             {
//                 Swap(&arr->A[i], &arr->A[0]);
//                 return i;
//             }
//         }    
//         return-1;
// }

// int BinarySearch(struct Array arr, int key) {
//     int l, mid, h;
//     l=0;
//     h=arr.length-1;

//     while (l<=h)
//     {
//         mid=(l+h)/2;
//         if (key==arr.A[mid]) {
//             return mid;
//         }
        
//         else if(key < arr.A[mid]) {
//             h=mid-1;
//         }   else {
//             l=mid+1;
//         }
//     return -1;
//     }
// }

// int Max(struct Array *arr) {
//     int max=arr->A[0];
//     for (int i = 0; i < arr->length; i++)
//     {
//         if (arr->A[i]>max)
//         {
//             max=arr->A[i];
//         }
//     }
//     return max;    
// }

// int Min(struct Array *arr) {
//     int min=arr->A[0];
//     for (int i = 0; i < arr->length; i++)
//     {
//         if (arr->A[i]<min)
//         {
//             min=arr->A[i];
//         }
//     }
//     return min;    
// }

// int Sum(struct Array *arr) {
//     int total=0;
//     for (int i = 0; i < arr->length; i++)
//     {
//         total=total+arr->A[i];
//     }
    
//     return total;    
// }

// int Reverse(struct Array *arr) {
//     int i=0;
//     int j=arr->length-1;
//     for (i=0, j=arr->length-1; i<j; i++, j--)
//     {
//         Swap(&arr->A[i], &arr->A[j]);
//     }
// }

// void InsertSort(struct Array *arr, int val) {
//     int i=arr->length-1; 
//     if (arr->length==arr->size) //checking if there is free space in an array
//         return;
//     while (i>=0 && arr->A[i]>val)
//     {
//         arr->A[i+1]==arr->A[i];
//         i--;
//     }
//     arr->A[i+1]=val;
//     arr->length++;
// }

// int isSorted(struct Array arr) {
//     for (int i = 0; i < arr.length -1; i++)
//     {
//         if (arr.A[i] > arr.A[i+1])
//         {
//             return 0;
//         }
//     }
//     return 1;
// }

// void Rearrange(struct Array *arr) {
//     int i=0;
//     int j=(arr->length)-1;
//     while (i<j)
//     {
//         while (arr->A[i]<0)
//         {
//             i++;
//         }

//         while (arr->A[i]>=0)
//         {
//             j--;
//         }
        
//         if (i<j)
//         {
//             Swap(&arr->A[i], &arr->A[j]);
//         }
//     }
// }

// struct Array* Merge(struct Array *arr1, struct Array *arr2) {
//     int i=0;
//     int j=0;
//     int k=0;
//     struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

//     while (i<arr1->length && j<arr2->length)
//     {
//         if (arr1->A[i] < arr2->A[j])
//         {
//             arr3->A[k++]=arr1->A[i++];
//         }
//         else {
//             arr3->A[k++]=arr2->A[j++];
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
//     // int x, index;

//     printf("Enter size: ");
//     scanf("%d", &arr1.size);
//     arr1.A=(int *)malloc(arr1.size*sizeof(int));


//     // while (ch<6) {    
//     //     printf("Menu\n");
//     //     printf("1. Insert\n");
//     //     printf("2. Delete\n");
//     //     printf("3. Search\n");
//     //     printf("4. Sum\n");
//     //     printf("5. Display\n");
//     //     printf("6. Exit\n");

//     //     printf("Enter your operation: ");
//     //     scanf("%d", &ch);

//     //     switch (ch)
//     //     {
//     //     case 1: printf("Enter an element and index: ");
//     //         scanf("%d, %d", &x, &index);
//     //         Insert(&arr1, index, x);
//     //         break;

//     //     case 2: printf("Enter an index: ");
//     //        kf scanf("%d", &index);
//     //         x=Delete(&arr1, index);
//     //         printf("Deleted element is %d\n", x);
//     //         break;
        
//     //     case 3: printf("Enter an element to search: ");
//     //         scanf("%d", &x);
//     //         index=LinearSearch(&arr1, x);
//     //         printf("Deleted element is %d\n", index);
//     //         break;

//     //     case 4: printf("Sum is %d\n", Sum(&arr1));
//     //         break;

//     //     case 5: Display(arr1);
//     // }s
//     return 0;

// }

