#include <stdio.h>
void troco_guloso(int valor, int moedas[], int n) {
 printf("Troco para %d centavos:\n", valor);

 // Para cada tipo de moeda, do maior para o menor
 for (int i = 0; i < n; i++) {
 // Quantas moedas deste valor podemos usar?
 int num_moedas = valor / moedas[i];

 // Se usarmos alguma, atualizamos o valor restante
 if (num_moedas > 0) {
 printf("%d moeda(s) de %d centavos\n",
 num_moedas, moedas[i]);
 valor -= num_moedas * moedas[i];
 }
 }

 if (valor > 0) {
 printf("Impossível dar troco exato!\n");
 }
}
int main() {
 // Moedas disponíveis (em centavos)
 int moedas[] = {100, 50, 25, 10, 5};
 int n_moedas = 6;

 // Valor para dar troco
 int valor = 73;

 troco_guloso(valor, moedas, n_moedas);

 return 0;
}
/* Saída:
Troco para 73 centavos:
0 moeda(s) de 100 centavos
1 moeda(s) de 50 centavos
0 moeda(s) de 25 centavos
2 moeda(s) de 10 centavos
0 moeda(s) de 5 centavos
3 moeda(s) de 1 centavos
*/