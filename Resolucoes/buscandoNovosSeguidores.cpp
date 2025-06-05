/*
BEECROWD | 3139

- Morgana é streamer e quer entrar no programa de parceria da plataforma
- para entrar é necessário um determinado número de inscritos no canal
- Morgana percebeu que todos os dias ganha, em quantidade de inscrições,
  o teto da média de inscrições dos últimos 30 dias
- precisamos calcular essa média e determinar, de acordo com o número atual
  de inscritos dela e a quantidade necessária para a parceria, em quantos dias
  ela alcancará as inscrições necessárias para entrar

--------ENTRADAS--------

- Primeira linha - dois inteiros N e M, que representam o número atual
  de inscritos da Morgana e o número alvo para entrar na parceria
- Segunda linha - uma sequência de 30 inteiros Di separados por espaço
  que representam o número de inscrições ganhas em cada dia no interva
  dos 30 dias anteriores

--------SAIDAS--------

- mostrar em quantos dias ela irá alcançar a meta de inscricoes para entrar
  no programa de parceria
*/

#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  queue<int> ultimos30dias;
  int soma = 0;

  for (int i = 0; i < 30; i++) {
    int d;
    cin >> d;
    ultimos30dias.push(d);
    soma += d;
  }

  int dias = 0;

  while (n < m) {
    double media = soma / 30.0;
    int ganho = ceil(media);

    n += ganho;
    dias++;

    // Atualiza janela deslizante
    soma -= ultimos30dias.front();
    ultimos30dias.pop();
    soma += ganho;
    ultimos30dias.push(ganho);
  }

  cout << dias << "\n";

  return 0;
}
