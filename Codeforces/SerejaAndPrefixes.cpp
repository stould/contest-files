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

int N, M;

struct interval {
    int op, len;
    Int from, to;
    Int value;
};

vector<interval> int_buf;

int dfs(int id, int pos) {
    cout << int_buf[id].from << " " << int_buf[id].to << " " << pos << "\n";
    if (int_buf[id].op == 1 && pos == int_buf[id].from) {
        return int_buf[id].value;
    } else {
        for (int i = 0; i < id; i++) {
            if (int_buf[i].from >= pos && int_buf[i].to <= pos) {
                return dfs(i, pos);
            }
        }
    }
    return -1;
}

int main(void) {
    freopen("i.in", "r", stdin);
    Int op, value, len, cnt;
    Int L = 1LL;

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> op;

        if (op == 1) {
            cin >> value;
            interval it;
            it.op = 1;
            it.from = L;
            it.to = L;
            it.value = value;
            int_buf.push_back(it);
            cout << "single = " << it.from << " " << it.to << "\n";
            L++;
        } else {
            cin >> len >> cnt;

            interval it;
            it.op = 2;
            it.len = len;
            it.from = L;
            it.to = L + cnt * len - 1;
            cout << "int = " << it.from << " " << it.to << "\n";
            int_buf.push_back(it);
            L += cnt * len;
        }
    }

    cin >> N;
    int id = 0;

    for (int i = 0; i < N; i++) {
        cin >> op;

        for ( ; ; ) {
            if (int_buf[id].from <= op && int_buf[id].to >= op) {
                break;
            }
            id++;
        }
        if (int_buf[id].op == 1) {
            //cout << int_buf[id].value << " ";
        } else {
            cout << "ans = " <<  dfs(id, op % int_buf[id].from + 1) << "\n";
        }
    }

    return 0;
}
