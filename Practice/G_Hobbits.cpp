#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct pt{
	ld x, y;
	pt(){}
	pt(ld x, ld y): x(x), y(y){}
	pt(ld ang): x(cos(ang)), y(sin(ang)){}  // Polar unit point: ang(randians)
  // ------- BASIC OPERATORS -------  //        
  pt operator+(pt p){ return pt(x+p.x, y+p.y); }
	pt operator-(pt p){ return pt(x-p.x, y-p.y); }
	pt operator*(ld t){ return pt(x*t, y*t); }
	pt operator/(ld t){ return pt(x/t, y/t); }
	ld operator*(pt p){ return x*p.x + y*p.y; }
	ld operator%(pt p){ return x*p.y - y*p.x; }
  // ------- COMPARISON OPERATORS -------  // 
  bool operator==(pt p){ return abs(x - p.x) <= eps && abs(y - p.y) <= eps; }
	bool operator<(pt p)const{ // for sort, convex hull/set/map
		return x < p.x - eps || (abs(x - p.x) <= eps && y < p.y - eps); }
	bool operator!=(pt p){ return !operator==(p); }
  // -------------- NORMS --------------  // 
	ld norm2(){ return *this**this; }
	ld norm(){ return sqrt(norm2()); }
	pt unit(){ return *this/norm(); }
	// ------------ SIDE, LEFT------------ //
  ld side(pt p, pt q){ return (q-p) % (*this-p); }// C is: >0 L, ==0 on AB, <0 R
	bool left(pt p, pt q){ // Left of directed line PQ? (eps == 0 if integer)
		return side(p, q) > eps; } // (change to >= -eps to accept collinear)
  // -------------- ANGLES -------------- //
  ld angle(){ return atan2(y, x); } // Angle from origin, in [-pi, pi]
  ld min_angle(pt p){ return acos(*this*p / (norm()*p.norm())); } // In [0, pi]
  ld angle(pt a, pt b, bool CW){ // Angle< AB(*this) > in direction CW
    ld ma = (a - b).min_angle(*this - b);
    return side(a, b) * (CW ? -1 : 1) <= 0 ? ma : 2*pi - ma; }
  bool in_angle(pt a, pt b, pt c, bool CW=1){ // Is pt inside infinite angle ABC 
    return angle(a, b, CW) <= c.angle(a, b, CW); } // From AB to AC in CW direction
  // -------------- ROTATIONS -------------- //
	pt rot(pt p){ return pt(*this % p,*this * p); }// use ccw90(1,0), cw90(-1,0)
	pt rot(ld ang){ return rot(pt(sin(ang), cos(ang))); } // CCW, ang (radians)
	pt rot_around(ld ang, pt p){ return p + (*this - p).rot(ang); }
  pt perp(){ return rot(pt(1, 0)); }
  // -------------- SEGMENTS -------------- //
  bool in_disk(pt p, pt q){ return (p - *this) * (q - *this) <= 0; }
  bool on_segment(pt p, pt q){ return side(p, q) == 0 && in_disk(p, q); }
};

struct line{
  pt v;  ld c;
  line(){}
  line(pt p, pt q): v(q - p), c(v % p){}
  line(pt v, ld c): v(v), c(c){}
  line(ld a, ld b, ld c): v({b, -a}), c(c){}
  bool operator<(line l){ return v % l.v > 0; } 
  bool operator/(line l){ return v % l.v == 0; } // abs() <= eps
  pt operator^(line l){ // LINE - LINE Intersection
    if(*this / l) return pt(inf, inf);  // PARALLEL
    return (l.v*c - v*l.c) / (v % l.v); 
  }
  ld side(pt p){ return v % p - c; }
  bool has(pt p){ return v % p == c; }
  pt proj(pt p) { return p - v.perp() * side(p) / v.norm2(); }
  pt refl(pt p) { return proj(p) * 2 - p; }
  bool cmp_proj(pt p, pt q){ return v * p < v * q; }
  ld dist(pt p){ return abs(side(p)) / v.norm(); }
  ld dist2(pt p){ return side(p) * side(p) / double(v.norm2()); } 
  
  bool operator==(line l){ return *this / l && c == l.c; }
	ld angle(line l){ return v.min_angle(l.v); }   ///angle bet. 2 lines
  line perp_at(pt p) { return {p, p + v.perp() }; }
  line translate(pt t) { return {v, c + (v % t)}; }
  line shift_left(ld dist){ return {v, c + dist * v.norm()}; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, h;
    cin >> n >> h;
    vector<pt> pts(n);
    forn(i, n){
        int x, y;
        cin >> x >> y;
        pts[i] = pt(x, y);
    }
    pt eye = pts.back();
    eye.y += h;
    vector<pt> path;
    path.pb(pts.back());
    ld ans = 0;
    ford(i, n - 1){
        pt& nxt = pts[i];
        pt& prv = path.back();
        // d(i);
        if(nxt.left(eye, prv)){
            // cout << "RIGHT" << el;
            continue;
        }
        if(prv == pts[i + 1]){
            // cout << "WHOLE" << el;
            ans += (nxt - prv).norm();
            path.pb(nxt);
            continue;
        }
        // cout << "PART" << el;
        line l = line(nxt, pts[i + 1]);
        line l2 = line(eye, prv);
        pt itst = l ^ l2;
        assert(itst != pt(inf, inf));
        ans += (nxt - itst).norm();
        path.pb(itst);
        path.pb(nxt);
    }
    // cout << el;
    cout << ans << el;
}
