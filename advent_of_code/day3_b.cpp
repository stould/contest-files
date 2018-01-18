#include <bits/stdc++.h>

using namespace std;

long long count(long long n){
    return 1 + 4 * n * n;
}

long long searchCoord(long long val){
    long long lo = 0, hi = val, ans = 0;
    while(lo <= hi){
        long long mid = lo + (hi - lo) / 2;
        long long values = count(mid);
        if(values >= val){
            hi = mid - 1;
            ans = mid;
        }else if(values < val){
            lo = mid + 1;
        }
    }
    return ans;
}

long long dl[4] = {0,+1,0,-1};
long long dc[4] = {+1,0,-1,0};

int main(){
    long long val;
    cin >> val;
    long long l = -searchCoord(val), c = l;
    long long side = abs(l) * 2;
    long long total = count(abs(l));
    long long dpos = 0;
    if(total == val) {
        cout << abs(l) * 2 << endl;
    }else{
        c++;
        while(val != total){
            for(int i = 0; i < side - 1; i++){
                total--;
                if(total == val){
                    break;
                }
                l += dl[dpos];
                c += dc[dpos];
            }
            dpos++;
        }
        cout << abs(l) + abs(c) << endl;
    }
    return 0;
}
