#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

#define double long double
const double inf = 1e100;
const double eps = 1e-12;
const double PI = acos(-1.0);
int sign(double x) {
    return (x > eps) - (x < -eps);
}
struct PT {
    double x, y;
    PT() {
        x = 0, y = 0;
    }
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &a) const {
        return PT(x + a.x, y + a.y);
    }
    PT operator - (const PT &a) const {
        return PT(x - a.x, y - a.y);
    }
    PT operator * (const double a) const {
        return PT(x * a, y * a);
    }
    friend PT operator * (const double &a, const PT &b) {
        return PT(a * b.x, a * b.y);
    }
    PT operator / (const double a) const {
        return PT(x / a, y / a);
    }
    bool operator == (PT a) const {
        return sign(a.x - x) == 0 && sign(a.y - y) == 0;
    }
    bool operator != (PT a) const {
        return !(*this == a);
    }
    bool operator < (PT a) const {
        return sign(a.x - x) == 0 ? y < a.y : x < a.x;
    }
    bool operator > (PT a) const {
        return sign(a.x - x) == 0 ? y > a.y : x > a.x;
    }
    double norm() {
        return sqrt(x * x + y * y);
    }
    double norm2() {
        return x * x + y * y;
    }
    PT perp() {
        return PT(-y, x);
    }
    double arg() {
        return atan2(y, x);
    }
    PT truncate(double r) { // returns a vector with norm r and having same direction
        double k = norm();
        if (!sign(k)) return *this;
        r /= k;
        return PT(x * r, y * r);
    }
};
inline double dot(PT a, PT b) {
    return a.x * b.x + a.y * b.y;
}
inline double dist2(PT a, PT b) {
    return dot(a - b, a - b);
}
inline double dist(PT a, PT b) {
    return sqrt(dot(a - b, a - b));
}
inline double cross(PT a, PT b) {
    return a.x * b.y - a.y * b.x;
}
inline double cross2(PT a, PT b, PT c) {
    return cross(b - a, c - a);
}
inline int orientation(PT a, PT b, PT c) {
    return sign(cross(b - a, c - a));
}
PT perp(PT a) {
    return PT(-a.y, a.x);
}
PT rotateccw90(PT a) {
    return PT(-a.y, a.x);
}
PT rotatecw90(PT a) {
    return PT(a.y, -a.x);
}
PT rotateccw(PT a, double t) {
    return PT(a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t));
}
PT rotatecw(PT a, double t) {
    return PT(a.x * cos(t) + a.y * sin(t), -a.x * sin(t) + a.y * cos(t));
}
double SQ(double x) {
    return x * x;
}
double rad_to_deg(double r) {
    return (r * 180.0 / PI);
}
double deg_to_rad(double d) {
    return (d * PI / 180.0);
}
double get_angle(PT a, PT b) {
    double costheta = dot(a, b) / a.norm() / b.norm();
    return acos(max((double)-1.0, min((double)1.0, costheta)));
}
struct seg {
    PT p, q;
    int id;
    seg(PT a, PT b, int c) {
        p = a; q = b; id = c;
    }
    double eval_y(double x) const {
        if (fabs(p.x - q.x) < eps) return p.y;
        return p.y + (q.y - p.y) *(x - p.x) / (q.x - p.x);
    }
    void print() {
        cout << "p = [" << p.x << "," << p.y << "], ";
        cout << "q = [" << q.x << "," << q.y << "]\n";
    }
};
inline bool intersect1d (double l1, double r1, double l2, double r2) {
    if (l1 > r1)  swap (l1, r1);
    if (l2 > r2)  swap (l2, r2);
    return max (l1, l2) <= min (r1, r2) + eps;
}
bool intersect (const seg & a, const seg & b) {
    return intersect1d (a.p.x, a.q.x, b.p.x, b.q.x)
           && intersect1d (a.p.y, a.q.y, b.p.y, b.q.y)
           && cross2 (a.p, a.q, b.p) * cross2 (a.p, a.q, b.q) <= eps
           && cross2 (b.p, b.q, a.p) * cross2 (b.p, b.q, a.q) <= eps;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;

    while (tc--) {
        PT a, b, c, d, p, q;
        cin >> p.x >> p.y;
        cin >> q.x >> q.y;
        cin >> a.x >> a.y;
        cin >> d.x >> d.y;
        if (a.x > d.x) swap(a.x, b.x);
        if (a.y > d.y) swap(a.y, b.y);
        b = PT(a.x, d.y);
        c = PT(d.x, a.y);

        seg P(p, q, 1);
        seg A(a, b, 0);
        seg B(c, a, 0);
        seg C(b, c, 0);
        seg D(b, d, 0);
        // P.print();
        // A.print();B.print();
        // C.print();D.print();
        // cout << "A : " << intersect(A, P) << endl;
        // cout << "B : " << intersect(B, P) << endl;
        // cout << "C : " << intersect(C, P) << endl;
        // cout << "D : " << intersect(D, P) << endl;
        if (intersect(A, P) or intersect(B, P) or intersect(C, P) or intersect(D, P)) {
            cout << "T" << endl;
        } else {
            cout << "F" << endl;
        }
    }
    return 0;
}