// TO DO: tentar aplicar a inserção do usuário, fixar melhor os algoritmos, criar uma função para visualizar toda a pilha

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct No{ // node
    int dado;
    struct No* next;
}No;
No* criarNo(int novo_dado){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = novo_dado;
    novoNo->next = NULL;
    return novoNo;
}

typedef struct Pilha{
    No* topo; // head
} Pilha;

void initiPilha(Pilha* pilha) {pilha->topo = NULL;}

int estaVazia(Pilha* pilha){

    return pilha->topo == NULL;
}

void push(Pilha* pilha, int novoDado){

    // criamos um nó com o dado desejado
    No* novoNo = criarNo(novoDado);

    // checamos se a alocação de memória ocorreu com sucesso
    if (!novoNo){
        printf("\nPilha Sobrecarregada");
        return;
    }

    // ligamos o nosso novo nó com o atual nó do topo
    novoNo->next = pilha->topo;

    // atualiza o topo para o nosso novo nó
    pilha->topo = novoNo;
}

void pop(Pilha* pilha){

    // vamos checar se a nossa pilha está vazia antes
    if (estaVazia(pilha)){
        printf("A sua lista está vazia, impossivel remover elemento");
        return;
    } else {

        // colocamos o nosso topo atual para uma variável temporária

        No* temp = pilha->topo;

        // atualizamos o topo para o próximo elemento
        pilha->topo = pilha->topo->next;

        // agora nos desalocamos a memória do topo a ser removido
        free(temp);
    }
}

int peek(Pilha* pilha){

    // vamos retornar o elemento do topo apenas se a lista não estiver vazia
    if(!estaVazia((pilha))){
        return pilha->topo->dado;
    } else{
        printf("\nA sua pilha esta vazia.");
        return INT_MIN;
    }
}

int main(){

    // vamos criar nossa pilha!
    Pilha pilha;
    initiPilha(&pilha);

    // vamos inserir elementos na pilha
    push(&pilha, 11);
    push(&pilha, 22);
    push(&pilha, 33);
    push(&pilha, 44);

    // vamos printar o elemento do topo da pilha (deve ser o ultimo que inserimos, seguindo a lógica)
    printf("O elemento do topo da sua pilha eh %d\n", peek(&pilha));

    // agora vamos remover dois elementos do topo
    printf("Removendo dois elementos...\n");
    pop(&pilha);
    pop(&pilha);

    // vamos conferir o elemento que ficou no topo
    printf("O novo elemento do topo da sua pilha eh %d\n", peek(&pilha));

    return 0;
}