#include <iostream>

using namespace std;

/*
- carlos quer ser eleito bobo da corte
- N candidatos se inscreveram para a eleição
- em caso de empate, quem se inscreveu primeiro vence, entao carlos
  ficou noites e noites na frente do escritorio eleitoral e garantiu que sua
  inscrição fosse a primeira, portanto, em caso de empate o carlos sempre vecerá
- A urna irá gerar um relatório com N inteiros, correspondentes ao numero de vo-
  tos de cada participante, ordenados pela ordem de inscrição (carlos sempre o primeiro)
- Precisamos determinar se carlos foi eleito

------Entradas------

- um inteiro N, sendo 2 <= N <= 10^4, representando o numero de participantes, em seguida, ira receber N entradas
  que correspondem ao numero de votos de cada um
*/ 



int main(){
    int n;
    int entradas;
    int carlosVotos;
    cin >> n;

    cin >> entradas;
    carlosVotos = entradas;

    for (int i=0; i < n-1; i++){
        cin >> entradas;
        if (carlosVotos < entradas) {
            (cout << "N\n");
            return 0;
        }
    }
    cout << "S\n";
}