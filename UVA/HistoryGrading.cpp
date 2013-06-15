#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n;

//LinearSerch is enough
int indexOf(vector<int>& b, int a, int n) {
    for(int i = 0; i < n; i++) {
        if(b[i] == a) return i;
    }
    return -1;
}

int lis(vector<int>& b, vector<int>& a, int n) {
    vector<int> m(n, 0);
    for(int k = 0; k < n; k++) {
        int mx = 0;
        for(int j = 0; j < k; j++) if(indexOf(b, a[k], n) > indexOf(b, a[j], n)) {
            if(m[j] > mx) mx = m[j];
        }
        m[k] = mx + 1;
    }
    return *max_element(m.begin(), m.end());
}
int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &n);

    vector<int> base(n, 0), actual(n, 0);
    for(int i = 0; i < n; i++) {
        scanf("%d", &base[i]);
    }
    while(scanf("%d", &actual[0]) == 1) {
        for(int i = 1; i < n; i++) {
            scanf("%d", &actual[i]);
        }
        printf("%d\n", lis(base, actual, n));
    }
    return 0;
}
