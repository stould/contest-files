#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) {
    a = (a > b) ? b : a;
}
template<typename T> void chmax(T& a, T b) {
    a = (a < b) ? b : a;
}
int in() {
    int x;
    scanf("%d", &x);
    return x;
}

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 610;
const int MAXM = 410;

const int INF = 10101010;

int N, M;

int C[MAXN];
int B[MAXM];

struct edge{
        int x,y;
        int c;
        int f;
        edge *next,*back;
        edge(){}
        edge(int x,int y,int c,edge* next):x(x),y(y),c(c),f(0),next(next),back(0){}
        void* operator new(size_t, void *p){
                return p;
        }
}*E[MAXN * MAXM + 10];
int source,sink;

int Q[MAXN * MAXM + 10];
int D[MAXN * MAXM + 10];

void BFS(){
        memset(D,-1,sizeof(D));
        int head=0,tail=0;
        Q[tail++]=source;
        D[source]=0;
        for(;;){
                int i=Q[head++];
                for(edge* e=E[i];e;e=e->next){
                        if(e->c==0)continue;
                        int j=e->y;
                        if(D[j]==-1){
                                D[j]=D[i]+1;
                                Q[tail++]=j;
                                if(j==sink)return;
                        }
                }
                if(head==tail)break;
        }
}
edge* cur[MAXN * MAXM + 10];
edge* path[MAXN * MAXM + 10];
int max_flow(){
        int res=0;
        int path_n;
        for(;;){
                BFS();
                if(D[sink]==-1)break;
                memcpy(cur,E,sizeof(E));
                path_n=0;
                int i=source;
                for(;;){
                        if(i==sink){
                                int mink=0;
                                int delta=INT_MAX;
                                for(int k=0;k<path_n;++k){
                                        if(path[k]->c < delta){
                                                delta = path[k]->c;
                                                mink=k;
                                        }
                                }
                                for(int k=0;k<path_n;++k){
                                        path[k]->c -= delta;
                                        path[k]->back->c += delta;
                                }
                                path_n=mink;
                                i=path[path_n]->x;
                                res+=delta;
                        }
                        edge* e;
                        for(e=cur[i];e;e=e->next){
                                if(e->c==0)continue;
                                if(D[i]+1==D[e->y])break;
                        }
                        cur[i]=e;
                        if(e){
                                path[path_n++]=e;
                                i=e->y;
                        }else{
                                D[i]=-1;
                                if(path_n==0)break;
                                path_n--;
                                i=path[path_n]->x;
                        }
                }
        }
        return res;
}
int sum;
edge *pool=new edge[MAXN * MAXM + 10],*data;
inline void add_edge(int x,int y,int w){
        E[x]=new((void*)data++) edge(x,y,w,E[x]);
        E[y]=new((void*)data++) edge(y,x,0,E[y]);
        E[x]->back = E[y];
        E[y]->back = E[x];
}


int main(void) {
    int i, j;
    for ( ; scanf("%d%d", &N, &M) == 2; ) {
        int s = 0;
        memset(E,0,sizeof(E));
        data=pool;
        source=0;
        sink=N + M + 2;

        for (i = 1; i <= N; i++) {
            C[i] = in();
            add_edge(source, i, C[i]);
        }

        int cnt[M];

        for (i = 1; i <= M; i++) {
            cnt[i] = in();
        }

        for (i = 1; i <= M; i++) {
            B[i] = in();

            s += B[i];

            add_edge(N + i, sink, B[i]);

            for (j = 0; j < cnt[i]; j++) {
                int curr = in();

                add_edge(curr, N + i, INF);
            }
        }

        int ans = s - max_flow();

        printf("%d\n", ans);
    }

    return 0;
}
