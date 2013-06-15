#include <iostream>
#include <set>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef long long ll;

ll i, j, n, tmp, linha[1800], coluna[1800], diag = 0;

int main(void) {
    scanf("%d", &n);
    set<ll> all;
    set<ll> helper;

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &tmp);
            coluna[j] += tmp;
            linha[i] += tmp;
            all.insert(tmp);
            if(i == j) diag += tmp;
            if(i == n) {
                helper.insert(coluna[j]);
            }
        }
        helper.insert(linha[i]);
        if(all.size() != n*i) break;
    }
    helper.insert(diag);

    bool ok = true;

    if(all.size() != n*n || helper.size() != 1) ok = false;

    if(ok) {
        cout << linha[1] << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
