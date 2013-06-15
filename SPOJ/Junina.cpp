#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int N, S, ans, cnt, used[25], graph[25][25];

void dfs(int curr, int value) {
    if (cnt > ans) {
        ans = cnt;
    }

    for (int i = curr; i < N; i++) if(!used[i]) {
        used[i] = 1;
        for (int j = i + 1; j < N; j++) {
            if (graph[i][j] == 1) {
                used[j]++;
            }
        }

        cnt += 1;
        dfs(i + 1, cnt);
        cnt -= 1;

        for (int j = i + 1; j < N; j++) {
            if (graph[i][j] == 1) {
                used[j]--;
            }
        }
        used[i] = 0;
    }
}

int main(void) {
    int test = 1;
    while(scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) {
            used[i] = 0;
            for (int j = 0; j < N; j++) {
                graph[i][j] = 0;
            }
        }

        for (int i = 0; i < N; i++) {
            while(scanf("%d", &S) == 1 && S) {
                S -= 1;
                graph[i][S] = graph[S][i] = 1;
            }
        }

        ans = cnt = 0;

        dfs(0, 0);

        printf("Teste %d\n%d\n\n", test++, ans);
    }
    return 0;
}
