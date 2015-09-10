#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef unsigned long long Hash;
#define maxn 1000010

Hash CC;
Hash C[maxn];
Hash B;
Hash h[maxn], poww[maxn];
char s[maxn];
int n;

inline int V (char c){
    return c-'a';
}

void pre (){
    h[0] = 0ULL; 
    for (int i = 1; i <= n; i++) {
		h[i] = h[i-1]*B+V(s[i-1]);
	}
    poww[0] = 1ULL;
    for (int i = 1; i <= n; i++) {
		poww[i] = poww[i-1]*B;
	}
    C[0] = CC;
    for (int i = 1; i <= n; i++) {
		C[i] = C[i-1]*CC;
	}
}

Hash calcula (int a, int b){
    return h[b]-h[a]*poww[b-a]+C[b-a];
}

int main (){
    CC = 5831ULL;
    B = 33ULL;
    scanf("%s", s);
    n = strlen(s);
    pre();

    while (1){
        int a, b; scanf("%d %d", &a, &b);
        cout << calcula (a, b) << endl;
    }

    return 0;
}


