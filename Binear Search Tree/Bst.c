#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void Insert(int key) {
    struct Node *t=root;
    struct Node *r, *p;

    if (root==NULL)
    {
        p=(struct node *)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }

    while (t!=NULL)
    {
        r=t;
        if (key < t->data)
        {
            t=t->lchild;
        } else if (key > t->data) {
            t=t->rchild;
        }   else {
            return;
        }
    }

    p=(struct node *)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;
        
    if (key < r->data)
    {
        r->lchild=p;
    } else {
        r->rchild=p;
    }
}

struct Node * Search(int key) {
    struct Node *t=root;

    while (t!=NULL)
    {   
        if (key==t->data)
        {
            return t;
        } else if (key < t->data) {
            t=t->lchild;
        } else if (key > t->data) {
            t=t->rchild;
        }
    }
    return NULL;
} 

int Height (struct Node *p) {
    int x,y;
    if (p==NULL)
    {
        return 0;
    } else {
        x=Height(p->lchild);
        y=Height(p->rchild);
        return x>y?x+1:y+1;
    }
}

struct Node *InPre(struct Node *p, int key) {
    while (p && p->rchild!=NULL)
    {
        p=p->rchild;
    }
    return p;
}

struct Node *InSucc(struct Node *p, int key) {
    while (p && p->lchild!=NULL)
    {
        p=p->lchild;
    }
    return p;
}

struct Node *Delete (struct Node *p, int key) {
    struct Node *q;

    if (p==NULL)
    {
        return NULL;
    } 

    if (p->lchild==NULL && p->rchild==NULL)
    {
        if (p==root)
        {
            root=NULL;
        }
        free(p);
        return NULL;
    }
    
    if (key < p->data)
    {
        p->lchild=Delete(p->lchild, key);
    }   else if (key > p->data) {
        p->rchild=Delete(p->rchild, key);
    } else {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q=InPre(p->lchild, key);
            p->data=q->data;
            p->lchild=Delete(p->lchild, q->data);
        } else {
            q=InSucc(p->rchild, key);
            p->data=q->data;
            p->rchild=Delete(p->rchild, q->data);
        }
        
    }
    return p;
}

void Inorder(struct Node *p) {
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}



int main(){

    struct Node *temp;

    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);
    printf("\n");
    printf("\n");

    // temp=Search(540);

    // if (temp!=NULL)
    // {
    //     printf("Element %d is found", temp->data);
    // } else {
    //     printf("Element not found");
    // }

    Inorder(root);
    

    return 0;
}