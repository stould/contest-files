#include <bits/stdc++.h>

using namespace std;

typedef long long Int;

int N;
Int P;

int main(void) {
    scanf("%d", &N);

    Int ans = 0;
    
    for (int i = 0; i < N; i++) {
        scanf("%I64d", &P);
        ans ^= P;
    }
    printf("%I64d\n", ans);
    return 0;
}
