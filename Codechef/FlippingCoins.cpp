#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

struct BinaryIndexedTree {
    int n, *tree;
    BinaryIndexedTree(int n): n(n) {
        tree = new int[n];
        for(int i = 0; i < n; i++) tree[i] = 0;
    }
    int sum(int begin, int end) {
        if(begin == end) return readSingle(begin);
        if(begin == 1) return read(end);
        return read(begin) - read(end);
    }
    int read(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    void update_range(int begin, int end, int val) {
        while (end >= begin) {
            tree[end] = tree[end] == 0 ? 1 : 0;
            end -= (end & -end);
        }
    }
    void update(int idx ,int val) {
        while (idx <= n) {
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
    int readSingle(int idx) {
        int sum = tree[idx];
        if (idx > 0) {
            int z = idx - (idx & -idx);
            idx--;
            while (idx != z) {
                sum -= tree[idx];
                idx -= (idx & -idx);
            }
        }
        return sum;
    }
};

int i, j, a, b, c, n, q;

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d%d", &n, &q);
    BinaryIndexedTree bit(n+1);
    REP(i, q) {
        scanf("%d%d%d", &a, &b, &c); b += 1; c += 1;
        if(a == 0) {
            bit.update_range(b, c, 0);
        } else {
            printf("%d\n", bit.sum(b, c));
        }
    }
    return 0;
}

