/*
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
--------NAO ESTA RESOLVIDO AINDA--------
*/

#include <iostream>

using namespace std;

int main(){
  // testando a aceleração de leitura do c++
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 0, m = 0, d = 0, somatorio = 0, qntDias = 0;
  double media = 0.0;
  cin >> n >> m;

  for (int i=0; i<30; i++){
    cin >> d;
    somatorio += d;
    //printf("%d\n", somatorio);
  }

  media = (somatorio/30);
  int mediaInt = static_cast<int>(media);

  //printf("Quantidade de novos inscritos: %d\nQuantidade media de inscritos nos ultimos 30 dias %.2f\n", somatorio, media);

  while(n < m){
     n += mediaInt;
     qntDias++;
     //printf("Qnt. inscritos: %d/%d \nQnt. dias: %d\n", n,m,qntDias);
   }
   cout << qntDias << "\n";

  return 0;
}
