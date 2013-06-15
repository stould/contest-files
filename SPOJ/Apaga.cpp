#include <stdio.h>
#include <stdlib.h>

char numero[1000000], numero2[10000000];
int n, d, i, j, p;

int busca(char x, char *v, int inicio, int fim) {
    int meio;
    while (inicio <= fim) {
        meio = (inicio+fim)/2;
        if (v[meio] < x) fim = meio-1;
        else inicio = meio+1;
    }
    return inicio;
}

int main() {
    while(scanf("%d%d", &n, &d) == 2 && !(n == 0 && d == 0)) {
        scanf("%s", numero);
        numero2[0] = numero[0];
        j = 0;
        for (i = 1; i < n; i++) {
            if (i <= d) {
                p = busca (numero[i], numero2, 0, j);
            } else {
                p = busca (numero[i], numero2, i-d, j);
            }
            if(p < n - d) {
                numero2[p] = numero[i];
                j = p;
            }
        }
        numero2[n-d] = '\0';
        printf("%s\n", numero2);
    }
    return 0;
}
