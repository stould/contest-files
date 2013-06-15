#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int board[8][8];

int kdx[8] = {1, 2,  2,  1, -1, -2, -2, -1};
int kdy[8] = {2, 1, -1, -2, -2, -1,  1,  2};

int dx[2] = {-1, -1};
int dy[2] = {-1,  1};

bool isValid(int i, int j) {
    if(i >= 0 && j >= 0 && i < 8 && j < 8) return true;
    return false;
}

using namespace std;

int main() {
    int i, j, k, xa, ya, ways = 0;
    string rook, knight;

    memset(board, 0, sizeof(board));

    cin >> rook >> knight;

    board[7 - (rook[1] - '1')][(rook[0] - 'a')] = 2;
    board[7 - (knight[1] - '1')][knight[0] - 'a'] = 2;

    for(i = 0; i < 8; i++) {
        xa = kdx[i] + (7 - (knight[1] - '1'));
        ya = kdy[i] + knight[0] - 'a';

        if(isValid(xa, ya) && board[xa][ya] == 0) {
            board[xa][ya] = 1;
        }
    }

    for(i = 0; i < 2; i++) {
        xa = dx[i] + (7 - (rook[1] - '1'));
        ya = dy[i] + rook[0] - 'a';

        if(isValid(xa, ya) && board[xa][ya] == 0) {
            board[xa][ya] = 1;
        }
    }

    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            if(board[i][j] == 0) {
                bool ok = false;
                for(k = 0; k < 8; k++) {
                    xa = i + kdx[k];
                    ya = j + kdy[k];

                    if(isValid(xa, ya)) {
                        if(board[xa][ya] == 2) {
                            ok |= true;
                        }
                    }
                }
                if(ok == false) {
                    ways++;
                }
            }
        }
    }
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
    cout << ways << endl;
    return 0;
}
