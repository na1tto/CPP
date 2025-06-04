#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Hoje vamos aprender como a estrutura de dados Pilha funciona, na linguagem C!

typedef struct No{ // node
    char nome[30];
    int idade;
    struct No* next;
}No;
No* criarNo(char* novoNome, int novaIdade){
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->nome, novoNome);
    novoNo->idade = novaIdade;
    novoNo->next = NULL;

    return novoNo;
}

typedef struct Pilha{
    No* topo; // head
} Pilha;

void initPilha(Pilha* pilha) {pilha->topo = NULL;}

int estaVazia(Pilha* pilha){

    return pilha->topo == NULL;
}

void push(Pilha* pilha, char* novoNome, int novaIdade){

    // criamos um nó com o idade desejado
    No* novoNo = criarNo(novoNome, novaIdade);

    // checamos se a alocação de memória ocorreu com sucesso
    if (!novoNo){
        printf("\nPilha Sobrecarregada!");
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
        return pilha->topo->idade;
    } else{
        printf("\nA sua pilha esta vazia.");
        return INT_MIN;
    }
}

void verPilha(Pilha* pilha){
    printf("Visualizando pilha inteira...\n");
    for (No* i = pilha->topo; i != NULL;i = i->next){
        printf("%s, %d anos\n",i->nome, i->idade);
    }
}
 
int main(){

    // vamos criar nossa pilha!
    Pilha pilha;
    initPilha(&pilha);

    char nome[30];
    int idade;
    int limite = 0;

    printf("Bem vindo(a) a inicializacao da nossa Pilha!\nQuantos elementos deseja inserir?\n");
    scanf("%d", &limite);

    for(int i = 0; i < limite; i++){
        printf("Insira os dados do elemento %d\n", i);
        printf("Insira o nome do usuario: ");
        scanf("%s", nome);
        printf("Insira a idade do usuario: ");
        scanf("%d", &idade);
        push(&pilha, nome, idade);
    }

    // vamos printar o elemento do topo da pilha (deve ser o ultimo que inserimos, seguindo a lógica)
    printf("O elemento do topo da sua pilha eh %d\n", peek(&pilha));
    
    // vamos vizualizar toda a nossa pilha
    verPilha(&pilha);

    // // agora vamos remover dois elementos do topo
    // printf("Removendo dois elementos...\n");
    // pop(&pilha);
    // pop(&pilha);

    // // vamos conferir o elemento que ficou no topo
    // printf("O novo elemento do topo da sua pilha eh %d\n", peek(&pilha));

    // // vamos vizualizar toda a nossa pilha (denovo:D)
    // verPilha(&pilha);

    return 0;
}