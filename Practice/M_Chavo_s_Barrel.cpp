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
#define db(x) cout<< #x<< " " << x<<el
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

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};


struct pt{
    ld x, y;
    pt(){}
    pt(ld x, ld y): x(x), y(y) {}
    pt operator+(pt p){ return pt(x+p.x, y+p.y); }
	pt operator-(pt p){ return pt(x-p.x, y-p.y); }
	pt operator*(ld t){ return pt(x*t, y*t); }
	pt operator/(ld t){ return pt(x/t, y/t); }
	ld operator*(pt p){ return x*p.x + y*p.y; }
	ld operator%(pt p){ return x*p.y - y*p.x; }
    ld norm2(){ return *this**this; }
    ld norm(){ return sqrt(norm2()); }
    pt rot(pt p){ return pt(*this % p,*this * p); }
};

ld R;
pt c1, c2, zr = {0, 0};
ld r1, r2;

ld f(ld x, ld y){
    pt cur = {x, y};
    ld dst1 = r1 - (cur - c1).norm();
    ld dst2 = r2 - (cur - c2).norm();
    if(dst1 < eps || dst2 < eps)return 0;
    ld dst3 = R - cur.norm();
    return min({dst1, dst2, dst3});
}

pt fr(ld x, ld r, pt c){
    ld dx = x - c.x;
    ld sq = sqrt(r*r - dx*dx);
    return {-sq + c.y, sq + c.y};
}

pt inter(ld x){
    pt y1 = fr(x, r1, c1), y2 = fr(x, r2, c2);
    ld l = max(y1.x, y2.x), r = min(y1.y, y2.y);
    l = max(l, ld(-R));
    r = min(r, ld(R));
    return {l, r};
}

ld ternary_search_2(ld x){
    auto [l, r] = inter(x);
    if(l > r)return 0;
    forn(_, 70){
        ld m1 = l + (r - l) / 3;
        ld m2 = r - (r - l ) / 3;
        ld f1 = f(x, m1);
        ld f2 =  f(x, m2);
        if(f1 < f2) l = m1;
        else r = m2;
    }
    return f(x, l);
}

ld bnr(ld l, ld r){
    forn(_, 70){
        ld md = l + (r - l) / 2;
        auto [ly, ry] = inter(md);
        if(ly <= ry)l = md;
        else r = md;
    }
    return l;
}

ld bnr2(ld l, ld r){
    forn(_, 70){
        ld md = l + (r - l) / 2;
        auto [ly, ry] = inter(md);
        if(ly <= ry)r = md;
        else l = md;
    }
    return r;
}

ld ternary_search(){
    ld l = bnr2(-R, 0);
    ld r = bnr(0, R);
    forn(_, 70){
        ld m1 = l + (r - l) / 3;
        ld m2 = r - (r - l ) / 3;
        ld f1 = ternary_search_2(m1);
        ld f2 =  ternary_search_2(m2);
        if(f1 < f2) l = m1;
        else r = m2;
    }
    return ternary_search_2(l);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    cin >> R;
    cin >> c1.x >> c1.y;
    cin >> c2.x >> c2.y;
    r1 = (c1 - zr).norm();
    r2 = (c2 - zr).norm();
    cout << ternary_search() << el;
}