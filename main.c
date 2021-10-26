#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct nodo {
    int data;
    struct nodo* sig;
};

struct nodo* crearNodo (int data){
    struct nodo* nuevo = (struct nodo*) malloc(sizeof(struct nodo));
    
    nuevo->data=data;
    nuevo->sig = NULL;
    
    return nuevo;
}

void push (int data,struct nodo** pila){
    struct nodo* nuevo = crearNodo(data);
    nuevo->sig = *pila;
    *pila = nuevo;
}

int pop(struct nodo** pila){
    if(!(*pila))return INT_MIN;
    
    struct nodo* primero = *pila;
    int data = primero->data;
    
    *pila = (*pila)->sig;
    free(primero);
    
    return data;
}

void mostrar(struct nodo** pila){
    struct nodo* temp = *pila;
    while (temp){
        printf("%d ",temp->data);
        temp = temp ->sig;
    }
    printf("\n");
}
int main(int argc, char** argv) {
    struct nodo* pila = crearNodo(15);
    push(2, &pila);
    push(-67, &pila);
    push(1, &pila);
    
    for (int i = 0;i<5;i++){
        printf("Eliminamos %d\n", pop(&pila));
        mostrar(&pila);
    }
    
    
    return (EXIT_SUCCESS);
}

