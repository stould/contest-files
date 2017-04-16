void fillL(void) {
    stack<int> s;

    for (int i = 0; i < N; i++) {
        if (s.empty()) {
            L[i] = i;
        } else {
            while (!s.empty() && P[s.top()] <= P[i]) {
                s.pop();
            }
            if (!s.empty()) {
                L[i] = s.top();
            } else {
                L[i] = i;
            }
        }
        s.push(i);
    }
}
