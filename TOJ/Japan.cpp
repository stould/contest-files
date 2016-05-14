#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int T, N, M, K;

struct pair {
    int f, s;
};

int tree[1010];
pair buf[1000009];

int compare(const void *a, const void *b) {
    pair *aa = (pair*) a;
    pair *bb = (pair*) b;

    if (aa->f == bb->f) {
        return aa->s > bb->s;
    } else {
        return aa->f > bb->f;
    }
}

void update(int index, int value) {
    int i;

    for (i = index; i < 1010; i += (i&-i)) {
        tree[i] += value;
    }
}

long long int sum(int index) {
    int i;
    long long int ans = 0LL;

    for (i = index; i > 0; i -= (i&-i)) {
        ans += tree[i];
    }

    return ans;
}


int main(void) {
    int i, test;

    scanf("%d", &T);

    for (test = 1; test <= T; test++) {
        scanf("%d%d%d", &N, &M, &K);

        for (i = 0; i < K; i++) {
            scanf("%d%d", &buf[i].f, &buf[i].s);
        }

        qsort(buf, K, sizeof(pair), compare);

        memset(tree, 0, sizeof(tree));

        long long int ans = 0LL;

        for (i = 0; i < K; i++) {
            ans += i - sum(buf[i].s);
            update(buf[i].s, 1);
        }

        printf("Test case %d: %lld\n", test, ans);
    }

    return 0;
}
