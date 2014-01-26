#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <string.h>
#define ll long long
#define MAXN 100002

using namespace std;

int n, q, a, b, v[MAXN], freq[MAXN], tree[MAXN*4];

void build(int idx, int l, int r){
    if(l > r){
        return;
    }else{
        if(l == r){
            tree[idx] = l;
        }else{
            int mid = (l+r) >> 1;
            int gol = idx << 1;
            int gor = (idx << 1) + 1;
            build(gol, l, mid);
            build(gor, mid+1, r);
            int q1 = tree[gol];
            int q2 = tree[gor];
            if(freq[q1] <= freq[q2]){
                tree[idx] = q2;
            }else{
                tree[idx] = q1;
            }
        }
    }
}

int rmq(int idx, int x, int y, int bl, int br){
    if(bl > y || br < x || x > y){
        return -1;
    }else{
        if(x == bl && y == br){
            return tree[idx];
        }else{
            int mid = (x+y) >> 1;
            int gol = idx << 1;
            int gor = (idx << 1) + 1;
            int q1 = rmq(gol,x, mid, bl, min(br, mid));
            int q2 = rmq(gor, mid+1, y, max(mid + 1, bl), br);
            if(q1 == -1){
                return q2;
            }else if(q2 == -1){
                return q1;
            }else{
                if(freq[q1] <= freq[q2]){
                    return q2;
                }else{
                    return q1;
                }
            }
        }
    }
}

int main(void){
    while(~scanf("%d", &n) && n){
        scanf("%d", &q);
        scanf("%d", &v[0]);
        memset(freq,0,sizeof(freq));
        freq[0] = 1;
        for(int i = 1; i < n; i++){
            scanf("%d", &v[i]);
            if(v[i] == v[i-1]){
                freq[i] = freq[i-1] + 1;
            }else{
                freq[i] = 1;
            }
        }
        build(1, 0, n-1);
        for(int i = 0; i < q; i++){
            scanf("%d%d", &a, &b);
            a--;
            b--;
            if(a > b){
                swap(a,b);
            }
            int trueRange = rmq(1,0,n-1,a,b);
            //cout << trueRange << " " << a << " " << b << endl;
            if(a == 0 && b == n-1){
                printf("%d\n", freq[trueRange]);
            }else if(v[a] == v[b]){
                printf("%d\n", b-a+1);
            }else{
                int v1 = 0;
                if(trueRange - freq[trueRange] < a){
                    v1 = trueRange - a + 1;
                }else{
                    v1 = freq[trueRange];
                }
                int v2 = freq[rmq(1,0, n-1, trueRange+1, b)];
                if(v2 > v1){
                    printf("%d\n", v2);
                }else{
                    printf("%d\n", v1);
                }
            }
        }
    }
    return 0;
}
