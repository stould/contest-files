#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int n, tmp, teste = 1;
char c;

int count(vector<int> v, int ct) {
    int ans = 0;
    for(int i = 0; i < v.size(); i++) if(v[i] == ct) ans++;
    return ans;
}

int main(void) {
    while(scanf("%d", &n) && n != 0) {
        vector<int> ans[6];
        for(int x = 0; x < n; x++) {
            map<char, vector<int> > mp;
            map<char, vector<int> >::iterator it;
            for(char i = 'A'; i <= 'E'; i++) {
                for(int j = 0; j < 2; j++) {
                    scanf("%d", &tmp); mp[i].push_back(tmp);
                }
            }
            for(int i = 0; i < 6; i++) {
                scanf(" %c", &c);
                ans[i].push_back(mp[c][0]);
                ans[i].push_back(mp[c][1]);
            }
        }
        printf("Teste %d\n", teste++);
        for(int i = 0; i < 6; i++) {
            int helper = 0;
            for(int j = 0; j < 10; j++) {
                if(count(ans[i], j) == n) helper = j;
            }
            if(i == 5) {
                printf("%d\n", helper);
            } else {
                printf("%d ", helper);
            }
        }
        printf("\n");
    }
    return 0;
}
