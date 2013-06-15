#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int n;

struct bota {
    int tamanho;
    char pe;
};

bool func(bota a, bota b) {
    return a.tamanho < b.tamanho;
}

int main(void) {
    ios::sync_with_stdio(false);
    while(cin >> n) {
        int ans = 0;
        vector<bota> v(n); vector<bool> used(n, false);
        for(int i = 0; i < n; i++) {
            cin >> v[i].tamanho >> v[i].pe;
        }
        sort(v.begin(), v.end(), func);
        for(int i = 0; i < n; i++) if(!used[i]) {
            for(int j = i + 1; j < n && v[i].tamanho == v[j].tamanho; j++) {
                if(!used[j] && v[i].pe != v[j].pe) {
                    ans += 1;
                    used[i] = used[j] = true;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
