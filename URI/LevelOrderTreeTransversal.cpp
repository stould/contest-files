#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

int C, N;

int tree[5000 * 4];


struct node {
    int v;

    node* l;
    node* r;

    node(){
        r = NULL;
        l = NULL;
    }

    node(int _v) {
        v = _v;
        l = NULL;
        r = NULL;
    }
};

node* root;

void add(node **n, int value) {
    if ((*n) == NULL) {
        (*n) = new node(value);
        //printf("%d %d\n", n->v, value);
    } else {
        if ((*n)->v > value) {
            add(&(*n)->l, value);
        } else {
            add(&(*n)->r, value);
        }
    }
}

int main(void) {
    //freopen("i.in", "r", stdin);
    C = in();

    int x;
    int i;

    for (x = 1; x <= C; x++) {
        N = in();

        root = NULL;

        for (i = 0; i < N; i++) {
            int curr = in();
            add(&root, curr);
        }

        queue<node*> q;

        q.push(root);

        printf("Case %d:\n", x);

        for ( ;!q.empty(); ) {
            node* curr = q.front(); q.pop();

            if (curr->l != NULL) {
                q.push(curr->l);
            }
            if (curr->r != NULL) {
                q.push(curr->r);
            }
            printf("%d", curr->v);
            if (!q.empty()) {
                printf(" ");
            }
        }
        puts("\n");
    }
    return 0;
}
