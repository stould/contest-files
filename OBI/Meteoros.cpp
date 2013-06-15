#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int i, n, xa, xb, ya, yb, mx, my, t = 1;

int main(void) {
    while(scanf("%d%d%d%d", &xa, &ya, &xb, &yb)) {
        if(!xa && !xb && !ya && !yb) break;
        scanf("%d", &n);
        int in = 0;
        for(i = 0; i < n; i++) {
            scanf("%d%d", &mx, &my);
            if(mx >= xa && mx <= xb && my <= ya && my >= yb) {
                in += 1;
            }
        }
        printf("Teste %d\n%d\n\n", t++, in);
    }
    return 0;
}
