#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAXN 2005
 
int N, M, L;
int P[MAXN], cpy[MAXN], mem[MAXN], used[MAXN];
int map[MAXN];
 
int cmp(const void* a, const void* b) {
    int* aa = (int*) a;
    int* bb = (int*) b;
 
    return (*aa) - (*bb);
}
 
int main(void) {
    for ( ; scanf("%d%d", &M, &L) == 2 && M + L != 0; ) {
        scanf("%d", &N);
        int i, j, all = 0;
        for (i = 0; i < N; i++) {
            scanf("%d", &P[i]);        
            cpy[i] = P[i];
            all += P[i];
        }
        qsort(P, N, sizeof(int), cmp);
        int id = 0, sum = 0, ok = 1;
 
        for (i = 0; i < N; i++) {
            sum += P[i];
            if (sum > M) {
                sum -= P[i];
                if (all - sum > L) {
                    ok = 0;
                }
                break;
            }
            mem[id++] = P[i];
        }
        if (ok) {
            memset(used, 0, sizeof(used));
            for (i = 0; i < id; i++) {
                for (j = 0; j < N; j++) {
                    if (!used[j] && mem[i] == cpy[j]) {
                        used[j] = 1;
                        mem[i] = j + 1;
                    }  
                }
            }          
            printf("%d ", id);
            qsort(mem, id, sizeof(int), cmp);
            for (i = 0; i < id; i++) {
                printf("%d", mem[i]);
                if (i != id - 1) printf(" ");
            }
            printf("\n");
        } else {
            puts("Impossible to distribute");
        }
    }
    return 0;
}
