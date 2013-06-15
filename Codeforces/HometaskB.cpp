#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

using namespace std;

int n, tmp;
set<int> s;

int main(void) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        s.insert(tmp);
    }
    return 0;
}
