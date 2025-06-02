// Continuando a entender um pouco melhor sobre árvores binárias, vamos entender sobre a deleção nessa estrutura

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

// Função para deletar um nó da nossa árvore binária

No* deletarNo(No* raiz, int valor){
    if (raiz == nullptr) return nullptr;

    // usamos uma fila para atravessar a árvore binária com a técnica Breadth-First Search

    queue<No*> q;
    q.push(raiz);
    No* alvo = nullptr;

    // vamos achar o nó alvo
    while (!q.empty()){
        No* atual = q.front();
        q.pop();

        // checaremos se o nó possui o valor que queremos deletar
        if (atual->dado == valor){
            alvo = atual;
            break;
        }

        // adicionar os nós filhos à fila
        if (atual->esq) q.push(atual->esq);
        if (atual->dir) q.push(atual->dir);
    }
    // se o meu alvo não for encontrado, retorne a árvore original
    if (alvo == nullptr) return raiz;

    // agora vamos encontrar o nó mais a direita e o seu nó pai
    pair<No*, No*> ultimo = {nullptr, nullptr};
    queue<pair<No*, No*>> q1;
    q1.push({raiz, nullptr});

    while(!q1.empty()){
        auto atual = q1.front();
        q1.pop();

        // atualize o antigo
        ultimo = atual;

        if (atual.first->esq)
            q1.push({atual.first->dir, atual.first});
    }
    No* ultimoNo = ultimo.first;
    No* ultimoPai = ultimo.second;

    // substituir o valor alvo pelo último valor alvo
    alvo->dado = ultimoNo->dado;

    // remove o ultimo nó pai iterado
    if (ultimoPai){
        if (ultimoPai->esq==ultimoNo) ultimoPai->esq = nullptr;
        else ultimoPai->dir = nullptr;
    } else {
        // se o ultimo no for a raiz
        delete ultimoNo;
        return nullptr;
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

    No* raiz = new No(2);
    raiz->esq = new No(3);
    raiz->dir = new No(4);
    raiz->esq->esq = new No(5);
    raiz->esq->dir = new No(6);

    cout << "Ordem original da arvore antes da delecao: ";
    inOrderDFS(raiz);

    int valorDel;

    cout << "Insira o valor que deseja deletar: ";
    cin >> valorDel;
    raiz = deletarNo(raiz, valorDel);

    cout << "\nArvore apos a delecao de " << valorDel << " (In-order DFS): ";
    inOrderDFS(raiz);
    cout << endl;

    return 0;
}