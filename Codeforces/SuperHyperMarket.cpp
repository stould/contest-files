#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-7;

struct qpos {
    int id;
    int len;
    int l1, l2;
    double coef;
    qpos(int _id) {
        id = _id;
        len = 0;
        l1 = l2 = 0;
        coef = 0.0;

    }
  
    void add(int val) {
        if (len == 0) {
            l1 = val;
        } else if (len == 1) {
            l2 = val;      
        } else {
            l1 = l2;
            l2 = val;
        }
        len += 1;

        if (len == 1) {
            coef = l1;      
        } else {
            coef = ((l1 + l2) / 2.0) * len;
        }
    }
  
    bool operator<(const qpos& other) const {
        if (fabs(coef - other.coef) < EPS) {
            return id > other.id;
        } else {
            return coef > other.coef;
        }
    }
};

int N, M;

int main() {
    cin >> N >> M;

    priority_queue<qpos> q;

    int P;
  
    for (int i = 0; i < N; i++) {
        cin >> P;
        if (i < M) {
            q.push(qpos(i));
        }
    
        qpos now = q.top();
        q.pop();
    
        //cout << now.l1 << " " << now.l2 << " " << now.len  << " => " << now.coef << "\n";
    
        cout << now.id + 1 << " ";
    
        now.add(P);  
    
        q.push(now);
    }

    cout << "\n";
    return 0;
}
