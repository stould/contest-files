int lis(int array[], int n) {
    int best[n], prev[n];

    for(int i = 0; i < n; i++) {
        best[i] = 1;
        prev[i] = i;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(array[i] > array[j] && best[i] < best[j] + 1) {
                best[i] = best[j] + 1; prev[i] = j;
            }
        }
    }
    int ans = 0; for(int i = 0; i < n; i++) ans = max(ans, best[i]);
    return ans;
}
