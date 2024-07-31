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

const int nax = 1e5 + 200;
const ld pi = acos(-1);

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

typedef double ld;
const ld eps = 1e-9, inf = 1e12;
struct pt {  // for 3D add z coordinate
  ld x, y;
  pt(){}
  pt(ld x, ld y): x(x), y(y){}
  pt operator-(pt p){return pt(x - p.x, y - p.y);}
  pt operator*(ld t){return pt(x * t, y * t);}
  pt operator/(ld t){return pt(x / t, y / t);}
  ld operator%(pt p){return x * p.y - y * p.x;}
  ld operator*(pt p){return x * p.x + y * p.y;}
  ld norm2(){ return *this**this; }
  ld norm(){ return sqrt(norm2()); }
  ld side(pt p, pt q){ return (q-p) % (*this-p); }
  bool left(pt p, pt q){ // Left of directed line PQ? (eps == 0 if integer)
		return side(p, q) > eps; } 
};

struct halfplane {
  pt p, v;  ld c, angle;
  halfplane(){}
  halfplane(pt p, pt q): p(p), v(q - p), c(v % p), angle(atan2(v.y, v.x)){}
  bool operator<(halfplane b)const{ return angle < b.angle; }
  bool operator/(halfplane l){ return abs(v % l.v) <= eps; } // 2D
  pt operator^(halfplane l){ return *this / l ? pt(inf, inf) : (l.v*c - v*l.c) / (v % l.v);}
  bool out(pt q){ return v % q < c; } // try < c-eps
};

vector<pt> intersect(vector<halfplane>& b){
  vector<pt> bx = {{inf, inf}, {-inf, inf}, {-inf, -inf}, {inf, -inf}};
  forn(i, 4) b.pb(halfplane(bx[i], bx[(i+1) % 4]));
  sort(all(b));
  int n = sz(b), q = 1, h = 0;
  vector<halfplane> c(sz(b) + 10);
  forn(i, n){
    while(q < h && b[i].out(c[h] ^ c[h-1])) --h;
    while(q < h && b[i].out(c[q] ^ c[q+1])) ++q;
    c[++h] = b[i];
    if(q < h && abs(c[h].v % c[h-1].v) < eps){
      if(c[h].v * c[h-1].v <= 0) return {};
      h--;
      if(b[i].out(c[h].p)) c[h] = b[i];
    }
  }
  while(q < h-1 && c[q].out(c[h] ^ c[h-1])) --h;
  while(q < h-1 && c[h].out(c[q] ^ c[q+1])) ++q;
  if(h - q <= 1) return {};
  c[h+1] = c[q];
  vector<pt> s;
  fore(i, q, h) s.pb(c[i] ^ c[i+1]);
  return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    ld D;
    cin >> n >> D;
    vector<halfplane> hpl(n);
    pt org = pt(0, 0);
    forn(i, n){
        pt p, q;
        cin >> p.x >> p.y >> q.x >> q.y;
        if(org.left(p, q))hpl[i] = halfplane(p, q);
        else hpl[i] = halfplane(q, p);
    }
    int l = -1;
    int r = n;
    ld D2 = D*D;
    while(l + 1 < r){
        int m = l + (r - l) / 2;
        vector<halfplane> chpl(m);
        forn(i, m){
            chpl[i] = hpl[i];
        }
        vector<pt> pts = intersect(chpl);
        bool pass = false;
        for(pt& p : pts){
            pass |= !(p.norm2() - D2  < eps);
        }
        if(pass){
            l = m;
        }else{
            r = m;
        }
    }
    assert(l > 1);
    if(r == n)cout << '*' << el;
    else cout << l + 1 << el;
}
