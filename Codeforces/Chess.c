#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int board[8][8];

int kdx[8] = {2, };
int kdy[8] = {1, };

int main() {
    char roo[2];
    char knight[2];

    fflush(stdin);

    scanf("%s%s", &roo, &knight);

    printf("%s", roo);

    return 0;
}
