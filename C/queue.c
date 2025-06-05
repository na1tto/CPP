#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct Fila {
    No* frente;
    No* post;
} Fila;

No* criarNo(int novoDado);
Fila* criarFila();
int estaVazia(Fila* f);
void enqueue(Fila* f, int novoDado);
void dequeue(Fila* f);
void printQueue(Fila* f);

No* criarNo(int novoDado){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = novoDado;
    novoNo->prox = NULL;
    return novoNo;
}

Fila* criarFila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->frente = f->post = NULL;
    return f;
}

int estaVazia(Fila* f){
    return f->frente == NULL;
}

void enqueue(Fila* f, int novoDado){
    No* novoNo = criarNo(novoDado);
    if (estaVazia(f)) {
        f->frente = f->post = novoNo;
    } else {
        f->post->prox = novoNo;
        f->post = novoNo;
    }
    printQueue(f);
}

void dequeue(Fila* f){
    if (estaVazia(f)){
        return;
    }
    No* temp = f->frente;
    f->frente = f->frente->prox;
    if (f->frente == NULL) {
        f->post = NULL;
    }
    free(temp);
    printQueue(f);
}

void printQueue(Fila* f){
    if (estaVazia(f)){
        printf("A sua fila está vazia\n");
        return;
    }

    No* temp = f->frente;
    printf("Fila Atual:\n");
    while (temp != NULL) {
        printf("%d ", temp->dado);
        temp = temp->prox;
    }
    printf("\n");
}

int main(){
    Fila* f = criarFila();

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
