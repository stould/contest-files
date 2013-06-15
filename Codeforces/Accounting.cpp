#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;


int main() {
    int a, x = -10000, n, b, tot = -1;
    bool ok = false;

    scanf("%d %d %d", &a, &b, &n);

    while(x <= 10000) {
        x += 1;
        tot = (int) a * pow(x, n);
        if(tot == b) { ok = true; break; }
    }

    if(ok) {
        printf("%d", x);
    } else {
        printf("No solution");
    }
    return 0;
}
