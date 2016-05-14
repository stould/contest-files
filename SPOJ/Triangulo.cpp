#include <algorithm>
#include <stdio.h>

using namespace std;

int a, b, c;

char solve() {
    if(a < b) swap(a, b);
    if(a < c) swap(a, c);
    if(b < c) swap(b, c);

    if(a >= b + c) return 'n';
    if(a*a < b*b + c*c) return 'a';
    if(a*a > b*b + c*c) return 'o';
    return 'r';
}

int main(void) {
    scanf("%d%d%d", &a, &b, &c);
    printf("%c\n", solve());
    return 0;
}
