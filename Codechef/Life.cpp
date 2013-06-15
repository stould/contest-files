#include <algorithm>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll v[10000000];

int i = 0;

int main(void) {
    freopen("i.in", "r", stdin);
    while(~scanf("%I64d", &v[i])) i++;

    i = 0;

    while(1) {
        if(v[i] == 42) break;
        printf("%I64d\n", v[i]);
        i++;
    }
    return 0;
}
