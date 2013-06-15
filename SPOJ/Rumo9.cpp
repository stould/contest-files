#include <iostream>
#include <stdio.h>

using namespace std;

int rec(int n) {
    if(n < 9 || n % 9 != 0) {
        return 0;
    } else {
        return 1 + rec(n / 9);
    }
}

string s;

int main(void) {
    freopen("i.in", "r", stdin);
    while(cin >> s) {
        int sum = 0;
        for(int i = 0; i < (int) s.size(); i++) {
            sum += s[i] - '0';
        }
        if(s == "0") break;

        int t = rec(sum);

        if(t == 0) {
            cout << s << " is not a multiple of 9." << endl;
        } else {
            cout << s << " is a multiple of 9 and has 9-degree " << t << endl;;
        }
    }
    return 0;
}
#include <stdio.h>

char *somaNumero(char numero[10000]);
int grau;

int main() {
  char numero[10000];

  while(1) {
    scanf("%s", numero);
    if(numero[0] == '0') break;

    grau = 0;
    char numero_aux[10000];
    strcpy(numero_aux, numero);
    if(verificaMultiplo(somaNumero(numero_aux))) {
      if(grau == 0) grau = 1;
      printf("%s is a multiple of 9 and has 9-degree %d.\n", numero, grau);
    } else
      printf("%s is not a multiple of 9.\n", numero);
  }

}

int verificaMultiplo(char numero[10000]) {
  if(numero[0] == '9')
    return 1;
  return 0;
}

char *somaNumero(char numero[10000]) {
  int i = 0, soma = 0;

  for(;numero[i] != '\0'; i++)
    soma += numero[i];

  soma -= 48 * i;
  sprintf(numero, "%d", soma);
  if(i == 1)
    return numero;

  grau++;
  return somaNumero(numero);
}
