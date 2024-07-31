#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;
const int iter = 70;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};
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
    ld norm2(){ return *this**this; }
	ld norm(){ return sqrt(norm2()); }
    bool operator<(pt p)const{ // for sort, convex hull/set/map
		return x < p.x - eps || (abs(x - p.x) <= eps && y < p.y - eps); }
    ld side(pt p, pt q){ return (q-p) % (*this-p); }
};
// / max_dist between 2 points (pa, pb) of 2 Convex polygons (a, b)
ld rotating_callipers(vector<pt>& a, vector<pt>& b){
  pair<ll, int> start = {-1, -1};
  if(sz(a) == 1) swap(a, b);
  forn(i, sz(a)) start = max(start, {(b[0] - a[i]).norm2(), i});
  if(sz(b) == 1) return start.fi;

  ld r = 0;
  for(int i = 0, j = start.se; i<sz(b); ++i){
    for(;; j = (j+1) % sz(a)){
      r = max(r, (b[i] - a[j]).norm2());
      if((b[(i+1) % sz(b)] - b[i]) % (a[(j+1) % sz(a)] - a[j]) <= eps) break;
    }
  }
  return r;
}

int n, m;
vector<pt> pla;
vector<pt> plb;

ld f(ld x, ld y){
    vector<pt> tpla = pla;
    forn(i, sz(pla)){
        tpla[i].x += x;
        tpla[i].y += y;
    }
    if(n == 1){
        ld ans = 0;
        forn(i, sz(plb)){
            ans = max(ans, (plb[i] - tpla[0]).norm2());
        }
        return ans;
    }
    if(m == 1){
        ld ans = 0;
        forn(i, sz(tpla)){
            ans = max(ans, (plb[0] - tpla[i]).norm2());
        }
        return ans;
    }
    return rotating_callipers(tpla, plb);
}

ld xa;
ld ya;

ld ternary_search_y(ld l, ld r, ld x) {
  forn(_, iter){
    ld m1 = l + (r - l) / 3;
    ld m2 = r - (r - l) / 3;
    ld f1 = f(x, m1), f2 = f(x, m2);
    if (f1 > f2) l = m1;
    else r = m2;
  }
  ya = l;
  return f(x, l); 
}

ld mn = -1e6;
ld mx = 1e6;

ld ternary_search_x(ld l, ld r) {
  forn(_, iter){
    ld m1 = l + (r - l) / 3;
    ld m2 = r - (r - l) / 3;
    ld f1 = ternary_search_y(mn, mx, m1), f2 = ternary_search_y(mn, mx, m2);
    if (f1 > f2) l = m1;
    else r = m2;
  }
  xa = l;
  return ternary_search_y(mn, mx, l);
}

vector<pt> chull(vector<pt>& p){ 
  if(sz(p) < 3) return p;
  vector<pt> r;
  sort(all(p));  // first x, then y
  forn(i, sz(p)){ // lower hull
    while(sz(r) > 1 && r.back().side(r[sz(r)-2], p[i]) >= 0) r.pop_back();
    r.pb(p[i]);
  }
  r.pop_back();
  int k = sz(r);
  fored(i, 0, sz(p)-1){ // upper hull
    while(sz(r) > k+1 && r.back().side(r[sz(r)-2], p[i]) >= 0) r.pop_back();
    r.pb(p[i]);
  }
  r.pop_back();
  return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    cin >> n;
    vector<pt> a(n);
    forn(i, n){
        int x, y;
        cin >> x >> y;
        a[i] = pt(x, y);
    }
    cin >> m;
    vector<pt> b(m);
    forn(i, m){
        int x, y;
        cin >> x >> y;
        b[i] = pt(x, y);
    }
    pla = chull(a);
    plb = chull(b);
    // d(f(-3, -1.5));
    ld ans = ternary_search_x(mn, mx);
    cout << sqrt(ans) << ' ' << xa << ' ' << ya << el;
}