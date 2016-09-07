///----Closes pair with divide and conquer----///
struct point{
    double x, y;
    point(double a, double b): x(a), y(b){}
    point(){};
};

bool compareX(point a, point b){
    return a.x < b.x;
}

bool compareY(point a, point b){
    return a.y < b.y;
}
 
double bruteForce(vector<point> &p){
    double ans = 40000.*40001.;
    for(int i = 0; i < p.size(); i++){
        for(int j = i + 1; j < p.size(); j++){
            double dst = hypot(p[j].x - p[i].x, p[j].y - p[i].y);
            if(dst < ans){
                ans = dst;
            }
        }
    }
    return ans;
}
 
double strip(vector<point> &p, double d){
    sort(p.begin(), p.end(), compareY);
    double ans = d;
    for(int i = 0; i < p.size(); i++){
        for(int j = i + 1; j < p.size() && (p[j].y - p[i].y) < d; j++){
            double dst = hypot(p[j].x - p[i].x, p[j].y - p[i].y);
            if(dst < ans){
                ans = dst;
            }
        }
    }
    return ans;
}
 
double X, Y;
int n;
double closest(vector<point> v){
    int n = v.size();
    if(n <= 3){
            return bruteForce(v);
    }
    vector<point> left;
    vector<point> right;
    int mid = n >> 1;
    for(int i = 0; i < mid; i++){
        left.push_back(v[i]);
    }
    for(int i = mid; i < n; i++){
        right.push_back(v[i]);
    }
 
    double lh = closest(left);
    double rh = closest(right);
    double d = min(lh,rh);
    vector<point> stripArray;
    for(int i = 0; i < n; i++){
        if(fabs(v[i].x - v[mid].x) < d){
            stripArray.push_back(v[i]);
        }
    }
    return min(d, strip(stripArray,d));
}
 
sort(pos.begin(), pos.begin()+n, compareX);
double ans = closest(pos);
