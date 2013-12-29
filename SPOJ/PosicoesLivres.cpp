#include <stdio.h>
#include <algorithm>

using namespace std;

int N, M, P;
int slot, x1, x2, y1, y2;
int subpartes, i,j, k, board[550][550];

int main(void) {
    for ( ; scanf("%d%d%d", &N, &M, &P) == 3; ) {
        slot = N * M;
        for (i = 0; i < N; i++) {
            for(j = 0; j < M; j++) {
                board[i][j] = 0;
            }
        }

        for (i = 0; i < P; i++) {
            int d = scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

            for (j = min(x1, x2); j <= max(x1, x2); j++) {
                for (k = min(y1, y2); k <= max(y1, y2); k++) {
                    if (board[j-1][k-1] == 0) {
                        board[j-1][k-1] = 1;
                        slot--;
                    }
                }
            }
        }

        if (slot == 0) {
            printf("There is no empty spots.\n");
        } else if (slot == 1) {
            printf("There is one empty spot.\n");
        } else {
            printf("There are %d empty spots.\n", slot);
        }
    }
    return 0;
}
