#include <stdio.h>
#include <limits>
#include <math.h>
#include <stdlib.h>

using namespace std;

int n, m, t[10010], test = 1;

int main(void) {
    while(scanf("%d%d", &n, &m) && n != 0 && m != 0) { m -= 1;
        int menor = numeric_limits<int>::max();
        int maior = numeric_limits<int>::min();
        int count = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &t[i]); count += t[i];
            if(i == m) {
                int tmp = (int) count / (m + 1);
                if(tmp < menor) {
                    menor = tmp;
                }
                if(tmp > maior) {
                    maior = tmp;
                }
            } else if(i > m) {
                count = (count - t[i - (m + 1)]);
                int tmp = (int) count / (m + 1);
                if(tmp < menor) {
                    menor = tmp;
                }
                if(tmp > maior) {
                    maior = tmp;
                }
            }
        }
        printf("Teste %d\n%d %d\n\n", test++, menor, maior);
    }
    return 0;
}
