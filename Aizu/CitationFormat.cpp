#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int n, v[51];

int main(void) {
    while(1) {
        scanf("%d", &n); if(n == 0) break;
        for(int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
        sort(v, v + n);
        vector<pair<int, int> > p;
        for(int i = 0; i < n; i++) {
            int begin = i, end = i;
            for(int j = i + 1; j < n;) {
                if(fabs(v[j] - v[j - 1]) > 1) {
                    i = j;
                    break;
                } else {
                    end = j;
                    j += 1;
                }
            }
            p.push_back(make_pair(v[begin], v[end]));
            i = end + 1;
        }
        for(int i = 0; i < p.size(); i++) {
            if(p[i].first != p[i].second) {
                if(i == v[n-1]) {
                    cout << p[i].first << "-" << p[i].second << endl;
                } else {
                    cout << p[i].first << "-" << p[i].second << " ";
                }
            } else {
                if(p[i].second == v[n-1]) {
                    cout << p[i].first << endl;
                } else {
                    cout << p[i].first << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}

using namespace std;

int pages[50];

int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d",pages+i);
        }
        vector<pair<int, int> > pset;
        for(int i=0;i<n;){
            int start = i;
            int end = i;
            for(int j=i+1;j<n;){
                if(abs(pages[j] - pages[j-1])>1){
                    i=j;
                    break;
                }
                else{
                    end = j;
                    j++;
                }
            }
            pset.push_back(make_pair(pages[start],pages[end]));
            i=end+1;
        }

        for(int i=0;i<pset.size();i++){
            if(pset[i].first != pset[i].second){
                printf("%d-%d%s",pset[i].first,pset[i].second,i==pset.size()-1 ? "\n" : " ");
            } else {
                printf("%d%s",pset[i].first,i==pset.size()-1 ? "\n" : " ");
            }
        }
    }
    return 0;
}
