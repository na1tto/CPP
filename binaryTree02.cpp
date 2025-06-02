// Seguindo os estudos sobre Árvores Binárias, vamos aprender sobre a inserção de elementos dentro de uma árvore.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


struct No{
    int dado;
    No* esq,* dir;
    No(int d){
        dado = d;
        esq = dir = nullptr;
    }
};

// Função para inserir um novo nó a nossa Árvore Binária:

No* inserir(No* raiz, int chave){

    // Se a árvore está vazia, cria-se um nó raiz
    if (raiz == nullptr){
        raiz = new No(chave);
        return raiz;
    }

    // Cria uma fila para atravessar os níveis da árvore
    queue<No*> q;
    q.push(raiz);

    // Realiza a técnica de level order traversal até encontrarmos um espaço vazio:

    while(!q.empty()){
        No* temp = q.front();
        q.pop();

        // Se o nó filho da esquerda estiver vazio, insere um novo nó ali
        if (temp->esq == nullptr){
            temp->esq = new No(chave);
            break;
        }else {
            q.push(temp->esq);
        }

        // Se o nó filho da direita estiver vazio, insere um novo nó ali
        if (temp->dir == nullptr){
            temp->dir = new No(chave);
            break;
        }else {
            q.push(temp->dir);
        }
    }
    return raiz;
}

void inOrderDFS(No* no){
    if (no == nullptr) return;

    inOrderDFS(no->esq);
    cout << no->dado << " ";
    inOrderDFS(no->dir);
}

int main(){

    // Vamos incializar manualmente uma Árvore Binária base para testarmos nossa inserção
    No* raiz = new No(2);
    raiz->esq = new No(3);
    raiz->dir = new No(4);
    raiz->esq->esq = new No(5); 

    cout << "InOrder traversal antes da da insercao: ";
    inOrderDFS(raiz);
    cout << endl;

    int chave = 6;
    raiz = inserir(raiz, chave);

    cout << "InOrder traversal depois da insercao: ";
    inOrderDFS(raiz);
    cout <<endl;

    // Podemos ver que o nó é inserido à direita do nó de valor 3.

    return 0;
}