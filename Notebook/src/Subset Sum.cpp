//Subset-Sum -> (G = O valor total sendo testado, N = numero de valores disponiveis no array 'values'
int values[n];
bool subsetSum(int n, int g) {
    for(j = 0; j <= g; j++) sub[j] = 0;
    sub[0] = 1;
    for(j = 0; j < n; j++) if(values[j] != g) {
        for(int k = g; k >= values[j]; k--) {
            sub[k] |= sub[k - values[j]];
        }
    }
    return sub[g];
}
