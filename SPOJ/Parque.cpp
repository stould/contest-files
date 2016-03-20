#include <stdio.h>
#include <string.h>

#define REP(i, n) for((i) = 0; (i) < (n); i++)
#define FOR(i, a, n) for((i) = (a); (i) < (n); i++)
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAXN 105

char s[MAXN], t[MAXN];
int m[MAXN][MAXN];
char d[MAXN][MAXN];

void pd() {
    int i, j;
    REP(i, MAXN) {
        m[i][0] = m[0][i] = i;
    }
    FOR(i, 1, MAXN) {
        FOR(j, 1, MAXN) {
            if(s[i] == t[j]) {
                m[i][j] = m[i-1][j-1] + 1;
                d[i][j] = 'D';
            } else {
                if(m[i-1][j] <= m[i][j-1]) {
                    m[i][j] = m[i-1][j] + 1;
                    d[i][j] = 'U';
                } else {
                    m[i][j] = m[i][j-1] + 1;
                    d[i][j] = 'L';
                }
            }
        }
    }
}

void reconstruct_path(int i, int j) {
    int k;
    if(i == 0) {
        for(k=1; k<=j; k++)
            putchar(t[k]);
        return;
    }
    if(j == 0) {
        for(k=1; k<=i; k++)
            putchar(s[k]);
        return;
    }

    switch(d[i][j]) {
    case 'U':
        reconstruct_path(i-1, j);
        putchar(s[i]);
        break;

    case 'L':
        reconstruct_path(i, j-1);
        putchar(t[j]);
        break;

    case 'D':
        reconstruct_path(i-1, j-1);
        putchar(s[i]);
        break;
    }
}


int main() {
    int i, x = 0, n0, n1;
    char line[2][MAXN];
    while(1) {
        gets(line[0]);
        if(line[0][0] == '#') break;
        gets(line[1]);
        n0 = strlen(line[0]);
        n1 = strlen(line[1]);

        for(i=0; i<MAXN; i++)
            s[i] = t[i] = 0;

        for(i=1; i<=n0; i++)
            s[i] = line[0][i-1];

        for(i=1; i<=n1; i++)
            t[i] = line[1][i-1];
        pd();
        printf("Teste %d\n", ++x);
        reconstruct_path(n0, n1);
        printf("\n\n");
    }

    return 0;
}
