#include <stdio.h>

using namespace std;

int a, n, aux, all = 0;

int main(void) {
    scanf("%d", &n);
    for(aux = 0; aux < n; aux++) {
        scanf("%d", &a); all += a;
    }
    printf("%d\n", all);
    return 0;
}
