#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int *S;
};

void create(struct Stack *st, int sz) {
    st->size=sz; 
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int)); 
}

void Display(struct Stack st) {
    for (int i = st.top; i >=0; i--)
    {
        printf("%d ", st.S[i]);
    }
    printf("\n");
}

void Push(struct Stack *st, int x) {
    if (st->top==st->size-1)
    {
        printf("Stack overflow\n");
    } else {
        st->top++;
        st->S[st->top]=x;
    } 
}

int Pop(struct Stack *st) {
    int x=-1;
    if (st->top==-1)
    {
        printf("Stack underflow");
    } else { 
        x=st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(struct Stack st, int index) {
    int x=-1;
    if (st.top-index+1<0)
    {
        printf("Invalid index");
    }   else {
        x=st.S[st.top-index+1];
    }
    return x;
}

int isEmpty(struct Stack st) {
    if (st.top==-1)
    {
        return 1;
    }   else {
        return 0;
    }
}

int isFull(struct Stack st) {
    return st.top==st.size-1;
}

int stackTop(struct Stack st) {
    if (!isEmpty(st))
    {
        return st.S[st.top];
    }   else {
        return -1;
    }
}

int main() {
    struct Stack st;

    create(&st, 5);

    Push(&st, 50);
    Push(&st, 20);
    Push(&st, 30);
    Push(&st, 60);

    printf("%d\n\n", stackTop(st));

    Display(st);

    return 0;
}

