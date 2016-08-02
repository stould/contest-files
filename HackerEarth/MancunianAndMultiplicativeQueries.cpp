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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;
const int LOGMAXVAL = 20;


int N, C, Q;
Int A[MAXN], FUNC[MAXN];

int val[MAXN];
int BLOCK_SIZE = sqrt(MAXN)+5; 
Int resp[MAXN];
Int seen[MAXN];
Int answer = 0;
 
struct pt{
    int l, r, id;
	
    pt(){}
    pt(int L, int R, int ID){
        l = L;
        r = R;
        id = ID;
    }
 
    bool operator < (const pt &o) const{
        return r < o.r;
    }
};
 
vector<vector<pt> > cons(BLOCK_SIZE);
 
void add(int pos){
    if(seen[A[pos]] > 0) {
        answer /= FUNC[seen[A[pos]];
    } else if (seen[val[pos]] > 1) {
        answer += 1;
    }
    seen[val[pos]]++;
}
 
void remove(int pos){
    if(seen[val[pos]] > 2){
        answer--;
    } else if (seen[val[pos]] == 2) {
        answer -= 2;
    }
    seen[val[pos]]--;
}
 
void process(int pos){
    int l = pos*BLOCK_SIZE, r = pos*BLOCK_SIZE;

    answer = 1;
    
    sort(cons[pos].begin(), cons[pos].end());
    
    for(int i = 0; i < (int) cons[pos].size(); i++){
        int ql, qr, id;
        ql = cons[pos][i].l;
        qr = cons[pos][i].r;
        id = cons[pos][i].id;
        
        while(r < qr){
            add(r);
            r++;
        }
        while(l < ql){
            remove(l);
            l++;
        }
        while(l > ql){
            l--;
            add(l);
        }
        resp[id] = answer; 
    }
    for(int j = l; j < r; j++){
        remove(j);
    }
}

int main(void) {
    cin >> N >> C >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i <= N; i++) {
        cin >> FUNC[i];
    }

    for (int i = 0; i < Q; i++) {
        pt newQ;
        cin >> newQ.l >> newQ.r;
        newQ.id = i;
        newQ.l--;
        cons[newQ.l / BLOCK_SIZE].push_back(newQ);
    }

    for(int i = 0; i < BLOCK_SIZE; i++){
        if(cons[i].size()){
            process(i);
        }
    }
    
    return 0;
}
