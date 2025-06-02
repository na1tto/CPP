// Vamos tentar entender as estruturas de árvores binárias utilizadas na programação! (em c++, nesse caso, talvez eu faça em C.)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

    // uma árvore binária é uma estrutura hierarquica composta por nós (elementos), partindo de um nó raiz (root), que pode ter até dois nós filhos
    // (childs), um nó maior e um nó menos do que o pai, que, por sua vez, podem ter seus próprios filhos, formando uma estrutura recursiva

    // Estrutura Básica de um nó na Árvore Binária: Dados, um ponteiro para o nó filho esquerdo e um ponteiro para o nó direito

    // Estrutura básica de um Nó, utilizando struct para linguagem procedural, pode ser feito como uma classe também
struct No {
    int dado;
    No* esq,* dir; // ponteiros esquerdo e direito

    No(int d){ // inicialização dos dados (como se fosse um construtor de classe)
        dado = d;
        esq = nullptr; // ponteiros dos nós inicializados como nulo
        dir = nullptr;
    }
};

// Formas de Atravessar uma Árvore Binária:

void inOrderDFS(No* no){
    if (no == nullptr) return;

    inOrderDFS(no->esq);
    cout << no->dado << " ";
    inOrderDFS(no->dir);
}


void preOrderDFS(No* no) {
    if (no == nullptr) return;
        
    cout << no->dado << " ";
    preOrderDFS(no->esq);
    preOrderDFS(no->dir);
}

void postOrderDFS(No* no){
    if (no == nullptr) return;

    inOrderDFS(no->esq);
    inOrderDFS(no->dir);
    cout << no->dado << " ";
}

// -> Breadth First Search (Estudar Depois, não entendi completamente)
void BFS(No* raiz){
    if (raiz == nullptr) return;
    queue<No*> q;
    q.push(raiz);

    while (!q.empty()){
        No* no = q.front();
        q.pop();

        cout << no->dado << " ";
        if (no->esq != nullptr) q.push(no->esq);
        if (no->dir != nullptr) q.push(no->dir);
    }
}

int main(){
    // Vamos tentar criar uma Árvore Binária com quatro nós (2, 3, 4, 5):

    // Começamos inicializando nossos nós e alocando memória para eles:
    No* primeiroNo = new No(2);
    No* segundoNo = new No(3);
    No* terceiroNo = new No(4);
    No* quartoNo = new No(5);

    // Agora vamos conectar esses nós, formando uma Árvore Binária!
    primeiroNo->esq = segundoNo;
    primeiroNo->dir = terceiroNo;
    segundoNo->esq = quartoNo;

    // Vamos criar uma nova árvore para popularmos a partir do seu nó raíz (forma diferente)
    No* raiz = new No(2);
    raiz->esq = new No(3);
    raiz->dir = new No(4);
    raiz->esq->esq = new No(5);
    
    cout << "Pre-order DFS: ";
    preOrderDFS(raiz);

    cout << "\nIn-order DFS: ";
    inOrderDFS(raiz);

    cout << "\nPost-oder DFS: ";
    postOrderDFS(raiz);

    cout << "\nBreadth-First Search: ";
    BFS(raiz);

    return 0;
}