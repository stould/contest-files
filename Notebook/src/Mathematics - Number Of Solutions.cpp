// given a linear equation of the form:
// c1*x1 + c2*x2 + ... + ck*xk = N,
// find the number of real solutions.
// start = 0, end = k-1, rhs = N
Int f(int start, int end, int rhs) {
    if(rhs == 0) return 1;
    
    Int ans = 0;
    for(int i=start; i<=end; i++) {
        if(c[i] <= rhs) {
            ans += f(i, end, rhs - c[i]);
        }
    }
    return ans;
}
