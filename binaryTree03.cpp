// Seguindo os aprendizados sobre Árvores Binárias, vamos aprender como realizamos uma pesquisa dentro dessa estrutura

#include <iostream>

using namespace std;

struct No{
    int dado;
    No* esq,* dir;
    No(int d){
        dado = d;
        esq = dir = nullptr;
    }
}; 

// Função para pesquisar um valor dentro de uma árvore usando DFS (Depth-First Search)
bool buscaDFS(No* raiz, int valor){
    // caso base: se a árvore está vazia ou se chegamos ao nó folha
    if (raiz == nullptr) return false;

    // se o dado do nó é igual ao valor que estamos buscando
    if (raiz->dado == valor) return true;

    // buscaremos recursivamente o valor nas subárvores esquerda e direita
    bool res_esq = buscaDFS(raiz->esq, valor);
    bool res_dir = buscaDFS(raiz->dir, valor);

    return res_esq || res_dir;

}

int main(){

    No* raiz = new No(2);
    raiz->esq = new No(3);
    raiz->dir = new No(4);
    raiz->esq->esq = new No(5);
    raiz->esq->dir = new No(6);

    cout << "Insira o valor que deseja buscar na nossa Arvore: " << endl;
    int valor;
    cin >> valor;

    if (buscaDFS(raiz, valor))
        cout << valor << " foi encontrado na Arvore Binaria!\n";
    else
        cout << valor << " nao foi encontrado na Arvore Binaria!\n"; 

    return 0;
}