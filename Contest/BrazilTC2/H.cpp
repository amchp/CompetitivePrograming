#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define ai128(x) x.begin(), x.end()
#define el '\n'
#define sz(x) x.size()
#define fi first
#define se second
#define pb push_back
#define d(x) cerr << #x << ' ' << x << el;

using namespace std;

typedef __int128_t i128;
typedef vector<int> vi;
typedef vector<i128> vi128;
typedef pair<int, int> ii;
typedef long double ld;

const i128 inf = 1e18;

struct pt{
    i128 x, y;
    pt(){}
    pt(i128 x, i128 y): x(x), y(y){}
    pt operator-(pt p){ return pt(x - p.x, y - p.y); }
    pt operator*(i128 t){ return pt(x*t, y*t); }
    pt operator/(i128 t){ return pt(x/t, y/t); }
    i128 operator*(pt p){ return x*p.x + y*p.y; }
    i128 operator%(pt p){ return x*p.y - y*p.x; }
    bool operator<(pt p){return x != p.x ? x < p.x : y < p.y; }
    bool operator==(pt p){ return x == p.x && y == p.y; }
    i128 side(pt p, pt q){
        return (q-p) % (*this - p);
    }
    bool in_disk(pt p, pt q){ return (p - *this) * (q - *this) <= 0; }
    bool on_segment(pt p, pt q){ return side(p, q) == 0 && in_disk(p, q); }
};

void segment_intersection(pt a, pt b, pt c, pt d, vector<pt>& out){
    i128 sa = a.side(c, d), sb = b.side(c, d);
    i128 sc = c.side(a, b), sd = d.side(a, b);
    if(sa*sb < 0 && sc*sd < 0){
        if(sb - sa == 0)while(true);
        else out.pb((a*sb - b*sa) / (sb - sa));
    }
    for(pt p : {c, d}) if(p.on_segment(a, b)) out.pb(p);
    for(pt p : {a, b}) if(p.on_segment(c, d)) out.pb(p);
}

typedef pair<pt, pt> ppt;

i128 ans = 0;
i128 mnx = inf;
i128 mny = inf;
i128 mxx = -inf;
i128 mxy = -inf;


vector<ppt> read_sq(){
    vector<ppt> sq(4);
    long long rx, ry;
    i128 x, y;
    cin >> rx >> ry;
    x = rx;
    y = ry;
    mnx = min(mnx, x);
    mny = min(mny, y);
    mxx = max(mxx, x);
    mxy = max(mxy, y);
    pt one = pt(x, y);
    cin >> rx >> ry;
    x = rx;
    y = ry;
    mnx = min(mnx, x);
    mny = min(mny, y);
    mxx = max(mxx, x);
    mxy = max(mxy, y);
    i128 dx = x - (one.x);
    i128 dy = y - (one.y);
    ans = max(ans, dx*dy);
    pt two = pt(x, y);
    pt three = pt(two.x, one.y);
    pt four = pt(one.x, two.y);
    sq[0] = {one, three};
    sq[1] = {three, two};
    sq[2] = {four, two};
    sq[3] = {one, four};
    return sq;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        mnx = inf;
        mny = inf;
        mxx = -inf;
        mxy = -inf;
        ans = 0;
        vector<ppt> sq1 = read_sq();
        vector<ppt> sq2 = read_sq();
        vector<pt> inter;
        forn(i, 4){
            forn(j, 4){
                // d(i);
                // d(j);
                segment_intersection(sq1[i].fi, sq1[i].se, sq2[j].fi, sq2[j].se, inter);
            }
        }
        sort(ai128(inter));
        inter.erase(unique(ai128(inter)), inter.end());
        // for(pt p : inter)cout << p.x << ' ' << p.y << el;
        // d(ans);
        if(sz(inter) == 0){
            unsigned long long fans = ans;
            cout << fans << el;
            continue;
        }
        // assert(sz(inter) == 2);
        pt mn = pt(inf, inf);
        pt mx = pt(-inf, -inf);
        for(pt& p : inter){
            mn.x = min(mn.x, p.x);
            mn.y = min(mn.y, p.y);
            mx.x = max(mx.x, p.x);
            mx.y = max(mx.y, p.y);
        }
        i128 dx = mx.x - mn.x;
        i128 dy = mxy - mny;
        // d(dx);
        // d(dy);
        ans = max(ans, dx*dy);
        dx = mxx - mnx;
        dy = mx.y - mn.y;
        // d(dx);
        // d(dy);
        ans = max(ans, dx*dy);
        unsigned long long fans = ans;
        cout << fans << el;
    }
    return 0;
}