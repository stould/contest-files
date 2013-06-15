#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Edge {
    int from, to;
    Edge(int f, int t) {
        from = f;
        to = t;
    }

    bool operator<(const Edge& a, const Edge& b) {
        return a.from < b.from;
    }
};

typedef vector<Edge> memo;

bool visited[101];

int main() {
    int test = 1;
    int n, f, t, i, j;

    cin >> n;

    while(n) {
        j = 0;
        while(f && t) {
            cin >> f >> t;
            memo.push_back(Edge(f, t));
        }
        sort(memo.begin(), memo.end());
        while(!visited[j]) {

        }
        cin >> n;
    }

    return 0;
}
