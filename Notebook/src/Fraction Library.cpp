struct fraction {
    int num, denom;
    fraction(int num, int denom): num(num), denom(denom){
    }
    fraction() { num = 0; denom = 0; }
    void reduce(fraction& f) {
        int l = gcd(f.num, f.denom);
        f.num = f.num/l;
        f.denom = f.denom/l;
    }
    fraction operator+(const fraction& f) {
        fraction ans;
        int l = lcm(denom, f.denom);
        ans.num = ((l / denom) * num) + ((l / f.denom) * f.num);
        ans.denom = l;
        reduce(ans);
        return ans;
    }
    fraction operator-(const fraction& f) {
        fraction ans;
        ans.num = num - f.num;
        ans.denom = denom - f.denom;
        reduce(ans);
        return ans;
    }
    fraction operator*(const fraction& f) {
        fraction ans;
        ans.num = num * f.num;
        ans.denom = denom * f.denom;
        reduce(ans);
        return ans;
    }
    fraction operator/(const fraction& f) {
        fraction ans;
        ans.num = num * f.denom;
        ans.denom = denom * f.num;
        reduce(ans);
        return ans;
    }
    bool operator!=(const fraction& f) {
        return num != f.num || denom != f.denom;
    }
    bool operator==(const fraction& f) {
        return num == f.num && denom == f.denom;
    }
    friend ostream &operator<<(ostream &out, fraction f) {
        out << f.num << "/" << f.denom << "\n";
        return out;
    }
    friend istream &operator>>(istream &in, fraction f) {
        in >> f.num >> f.denom;
        return in;
    }
};
