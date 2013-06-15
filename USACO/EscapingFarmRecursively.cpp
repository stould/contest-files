#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

int best = 0;

bool check(int a, int b) {
    while(a > 0 && b > 0) {
        if((a % 10) + (b % 10) >= 10) {
            return false;
        }
        a /= 10;
        b /= 10;
    }
    return true;
}

void rec(int index, int sum, vector<long long>& w, int ct, int n) {
    if(ct > best) best = ct;
    if(index >= n) return;
    if(check(sum, w[index])) {
        rec(index + 1, sum + w[index], w, ct + 1, n);
    } else {
        rec(index + 1, sum, w, ct, n);
    }
}

int main() {
    clock_t t1, t2;
    t1 = clock();

    freopen("Escaping/I.8", "r", stdin);

    int N;
    scanf("%d", &N);

    vector<long long> w(N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &w[i]);
    }

    rec(0, 0, w, 0, N);

    t2 = clock();

    printf("%d\n%.2f", best, (((float)t2 - (float)t1) / 1000000.0F));

    return 0;
}

