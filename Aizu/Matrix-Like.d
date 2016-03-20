import std.stdio;

int i, j, n;

void main() {
    while(1) {
        readf("%d", &n);
        if(n == 0) break;
        int[n+1][n+1] matrix;
        int[n+1] sumc;
        int[n+1] sumc;

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                readf("%d", &matrix[i][j]);
                sumc[j] += matrix[i][j];
                sumr[i] += matrix[i][j];
                if(j == n - 1) matrix[i][j+1] = sumr[j];
                if(i == n - 1) matrix[i+1][j] = sumc[i];
            }
        }
        for(i = 0; i <= n; i++) {
            for(j = 0; j <= n; j++) {
                printf("%5d", matrix[i][j]);
            }
            printf("\n");
        }
    }
}
