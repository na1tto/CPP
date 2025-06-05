#include <stdio.h>
#include <stdlib.h>

typedef struct No No;
typedef struct Fila Fila;
void printQueue(Fila* f);

struct No{
    int dado;
    struct No* prox;
};

struct Fila{
    No* frente;
    No* post;
};

No* criarNo(int novoDado){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = novoDado;
    return novoNo;
}

Fila* criarFila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->frente = f->post = NULL;
    return f;
}

int estaVazia(Fila* f){
    return f->post == NULL;
}

void enqueue(Fila* f, int novoDado){
    No* novoNo = criarNo(novoDado);
    if(estaVazia(f)){
        f->frente = f->post = NULL;
        printQueue(f);
        return;
    }
    f->post->prox = novoNo;
    f->post = novoNo;
    printQueue(f);
}

void dequeue(Fila* f){
    if (estaVazia(f)){
        return;
    }
    No* temp = f->frente;
    f->frente = f->frente->prox;
    if(f->frente == NULL) f->post = NULL;
    free(temp);
    printQueue(f);
}

void printQueue(Fila* f){
    if (estaVazia(f)){
        printf("A sua fila esta vazia\n");
        return;
    }

    No* temp = f->frente;
    printf("Fila Atual:\n");
    while(temp!=NULL){
        printf("%d", temp->dado);
        temp = temp->prox;
    }
    printf("\n");
}

int main(){

    struct Fila* f = criarFila();

    enqueue(f, 10);
    enqueue(f, 20);
    enqueue(f, 30);
    enqueue(f, 40);

    dequeue(f);
    dequeue(f);

    enqueue(f, 50);
    enqueue(f, 60);

    dequeue(f);

    return 0;
}