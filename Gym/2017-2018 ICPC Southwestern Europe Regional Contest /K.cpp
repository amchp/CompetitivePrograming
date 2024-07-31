#include <bits/stdc++.h>
#define el '\n'
#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r)for(int i = l; i <= (int)r; ++i)
#define fored(i, l, r)for(int i = r; i >= (int)l; --i)
#define all(a) a.begin(), a.end()
#define d(x) cerr<<#x<<" "<<x<<el
#define sz(x) x.size()
#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef array<int, 4> a4;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

const int nax = 1e4 + 100;
const ld inf = 1e17;
struct pt{
    ll x, y;
    pt(){}
    pt(ll x,ll y):x(x),y(y){}
    ll operator%(pt p){return x * p.y - y * p.x;}
    ll operator*(pt p){return x * p.x + y * p.y;}
    pt operator-(pt p){return {x - p.x, y-p.y};}
    ll norm2(){return *this**this;}
    ld norm(){return sqrt(norm2());}
    bool operator<(pt p)const{
        return x == p.x ? y < p.y : x < p.x;
    }
    bool operator ==(pt p)const{
        return x == p.x && y == p.y;
    }
    ll side(pt p, pt q){return (q-p) % (*this-p);}

};
const ld one = 1.0;
struct line
{
    pt v; ll c;
    line(){}
    line(pt p, pt q):v(q-p), c(v%p){}
    ll side(pt p){return v%p -c;}
    ld dist(pt p){assert(v.norm2() != 0); return abs(one*side(p) / v.norm());}
    ld distReal(pt p){return abs(one*side(p) / v.norm());}
};

vector<pt> chull(vector<pt> &p){
    if(sz(p) < 3) return p;
    vector<pt> r;
    sort(all(p));
    forn(i,sz(p)){
        while(sz(r) > 1 && r.back().side(r[sz(r)-2], p[i])>=0) r.pop_back();
        r.pb(p[i]);
    }
    r.pop_back();
    int k = sz(r);
    fored(i, 0, sz(p) -1){
        while(sz(r) > k + 1 &&r.back().side(r[sz(r)-2], p[i])>=0) r.pop_back();
        r.pb(p[i]);
    }
    r.pop_back();
    return r;
}

ld solve(vector<pt> &pts){
    int n = sz(pts);
   if(n <= 2)return 0;
    int j = -1;
    ld minDist = inf;
    line curline(pts[0], pts[1]);
    line minLine = curline;
    int minInd = -1;
    fore(i,2,n-1){
        ld di = curline.dist(pts[i]);
        if(j == -1 || di > curline.dist(pts[j])){
            j = i;
        }
    }
    minInd = j;
    minDist = curline.dist(pts[j]);
    fore(i,1, n-1){
        curline = line(pts[i], pts[(i+1) % n]);
        while(curline.dist(pts[(j-1+n)%n]) > curline.dist(pts[j]) || curline.dist(pts[(j+1)%n]) > curline.dist(pts[j]) ){
            if(curline.dist(pts[(j-1+n)%n]) > curline.dist(pts[(j+1+n)%n])){
                j = (j-1+n)%n;
            }else{
                j = (j + 1) % n;
            }
        }
        ld di = curline.dist(pts[j]) ;
        if(di < minDist){
            minDist = di;
            minLine = curline;
            minInd = j;
        }
    }
assert(minInd != -1);
    return minLine.distReal(pts[minInd]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.precision(21);
    int n, r;
    cin >> n >> r;
    vector<pt> pts(n);
    forn(i,n){
        int x,y;
        cin>>x>>y;
        pts[i] = {x,y};
    }
    sort(all(pts));

    vector<pt> ch = chull(pts);

    ch.erase(unique(all(ch)), ch.end());
    // for(auto [x,y] : ch){
    //     cout<<x<<" "<<y<<")"<<el;
    // }
    ld ans = solve(ch);
    cout<<ans<<el;
}