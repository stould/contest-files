#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
 
using namespace std;
 
int i, j, n, len;
char s[300];
 
int main(void) {
    while(scanf("%d", &n) == 1 && n != 0) {
        scanf("%s", s); len = strlen(s);
        int m = int(len/n);
        char mx[m][n];
        int index = 0;
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                if(i % 2 != 0) {
                    mx[i][n - j - 1] = s[index++];
                } else {
                    mx[i][j] = s[index++];
                }
            }
        }
        string ans = "";
        for(j = 0; j < n; j++) {
            for(i = 0; i < m; i++) {
                ans += mx[i][j];
            }
        }
        printf("%s\n", ans.c_str());
    }
    return 0;
}
