#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL, *second=NULL, *third=NULL; //self referential

void createLinkedList(int A[], int n) {
    int i;
    struct Node *t, *last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for (int i = 1; i < n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void createLinkedList2(int A[], int n) {
    int i;
    struct Node *t, *last;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;

    for (int i = 1; i < n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p) {
    while (p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

int count(struct Node *p) {
    int l=0;
    while (p)
    {
        l++;
        p=p->next;
    }
    return l;
}

int sum(struct Node *p) {
    int s=0;
    while (p)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}

int maximum(struct Node *p) {
    int m=-32768;
    while (p)
    {
        if (p->data > m)
        {
            m=p->data;
        }
        p=p->next;
    }
    return m;
}

int minimum(struct Node *p) {
    int m=p->data;
    while (p)
    {
        if (p->data < m)
        {
            m=p->data;
        }
        p=p->next;
    }
    return m;
}

int search(struct Node *p, int key) {
    while (p)
    {
        if (key==p->data)
        {
            return p->data;
        }
        
        p=p->next;
    }
    return -1;
}

int isSorted(struct Node *p) {
    int x=-32768;
    for (int i = 0; i < count(p); i++)
    {
        if (p->data < x)
        {
            return 0;
        }
        else {
            x=p->data;
            p=p->next;
        }
    }
    return 1;
}

void Insert(struct Node *p, int index, int x) {

    struct Node *temp;

    if (index < 0 || index >count(p))
    {
        return;
    }
    
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=x;

    if (index == 0)
    {
        temp->next=first;
        first=temp;
    }   

    else {
        for (int i = 0; i < index - 1; i++)
        {
            p=p->next;
        }

        temp->next=p->next;
        p->next=temp;
        
    }    

}

void insertSort(struct Node *p, int x) { 
    struct Node *t, *q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if (first==NULL)
    {
        first=t;
    }

    else {
        while (p && p->data < x)
        {
            q=p;
            p=p->next;
        }
        if (p==first)
        {
            t->next=first;
            first=t;
        }
        else {
            t->next=q->next;
            q->next=t;
        }
    }
}

int Delete(struct Node *p, int index) {
    struct Node *q=NULL;
    int x=-1;

    if (index < 1 || index>count(p))
    {
        return -1;
    }

    if (index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else {
        for (int i = 0; i < index-1; i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}

int remDuplicates(struct Node *p) {
    struct Node *q=p->next;

    while (q!=NULL)
    {
        if (p->data!=q->data)
        {
            p=q;
            q=q->next; 
        }
        else {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

void Reverse1(struct Node *p) {
    int *A, i=0;
    struct Node *q;
    A=(int *)malloc(sizeof(int)*count(p));

    while (q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    
    q=p;
    i--;

    while (q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}

void Reverse2(struct Node *p) {
    struct Node *q=NULL, *r=NULL;
    while (p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void Concat(struct Node *p, struct Node *q) {

    third=p;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
}

void Merge(struct Node *p, struct Node *q) {
    struct Node *last;
    if (p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    } else {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next =NULL;
        }
        else 
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }

    if (p)
    {
        last->next=p;
    } else {
        last->next=q;
    }
}

int main() {
    int A[]={1,3,5,7,9};

    createLinkedList(A,5);


    Insert(first, 0,123);

    Display(first);

    return 0;   
}
 
