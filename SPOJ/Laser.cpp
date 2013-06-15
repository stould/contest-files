#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

int i, a, c, cut, maior, m[100010];

int main(void) {
    while(~scanf("%d%d", &a, &c) && !(a == 0 && c == 0)) {
        cut = maior = 0;
        REP(i, c) {
            scanf("%d", &m[i]);
            if(i > 0) {
                if(m[i] > m[i - 1] && m[i] > maior) {
                    cut += m[i] - maior;
                }
                if(m[i] < m[i - 1]) {
                    cut += m[i - 1] - m[i];
                }
            }
            maior = max(maior, m[i]);
        }
        cut += a - maior;
        printf("%d\n", cut);
    }
    return 0;
}

