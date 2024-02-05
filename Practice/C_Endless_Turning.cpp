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

struct pt
{
    ld x, y;
    pt() {}
    pt(ll x, ll y) : x(x), y(y) {}
    // ------- BASIC OPERATORS -------  //
    pt operator+(pt p) { return pt(x + p.x, y + p.y); }
    pt operator-(pt p) { return pt(x - p.x, y - p.y); }
    pt operator*(ld t) { return pt(x * t, y * t); }
    pt operator/(ld t) { return pt(x / t, y / t); }
    ld operator*(pt p) { return x * p.x + y * p.y; }
    ld operator%(pt p) { return x * p.y - y * p.x; }
};
struct line
{
    pt v;
    ld c;
    line() {}
    line(pt p, pt q) : v(q - p), c(v % p) {}
    line(pt v, ld c) : v(v), c(c) {}
    bool operator<(line l) { return v % l.v > 0; }
    bool operator/(line l) { return v % l.v == 0; } // abs() <= eps
    pt operator^(line l)
    { // LINE - LINE Intersection
        if (*this / l)
            return pt(inf, inf); // PARALLEL
        return (l.v * c - v * l.c) / (v % l.v);
    }
    ld side(pt p) { return v % p - c; }
    bool has(pt p) { return v % p == c; }

    bool operator==(line l) { return *this / l && c == l.c; }
};

int r;
pair<line, string> streets[110];

bool not_valid(pt& curP, pt& inter, pt& ans, bool right, bool up){
    if(right){
        if(curP.x >= inter.x || ans.x < inter.x)return false;
    }else{
        if(curP.x <= inter.x || ans.x > inter.x)return false;
    }
    if(up){
        if(curP.y >= inter.y || ans.y < inter.y)return false;
    }else{
        if(curP.y <= inter.y || ans.y > inter.y)return false;
    }
    return true;
}

pair<int, pt> nxt_line(int cur, pt curP, bool right, bool up){
    pt ans;
    ans.x = right ? inf : -inf;
    ans.y = up ? inf : -inf;
    int ind = -1;
    forn(i, r){
        if(cur == i)continue;
        pt inter = streets[cur].first ^ streets[i].first;
        if(not_valid(curP, inter, ans, right, up))continue;
        ans = inter;
        ind = i;
    }
    return {ind, ans};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int x, y;
    ll n;
    cin >> r >> n >> x >> y;
    pt st = pt(x, y);
    int init = 0;
    forn(i, r){
        cin >> streets[i].se;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        streets[i].fi = line(pt(x1, y1), pt(x2, y2));
        if(streets[i].fi.has(st))init = i;
        d(streets[i].fi.c);
    }
    vi ord;
    ord.pb(init);
    int cur = init;
    pt curP = st;
    int nxt;
    pt nxtP;
    bool curR = true;
    bool curU = streets[cur].fi.c < 0;
    do{
        d(curR);
        d(curU);
        tie(nxt, nxtP) = nxt_line(cur, curP, curR, curU);
        if(nxt == -1){
            cout << streets[cur].se << el;
            return 0;
        }
        if(streets[cur].fi.c >= 0 && streets[nxt].fi.c < 0)curR = !curR;
        if(streets[cur].fi.c <= 0 && streets[nxt].fi.c > 0)curU = !curU;T
        cur = nxt;
        curP = nxtP;
        n--;
        if(n == 0){
            cout << streets[cur].se << el;
            return 0;
        }
    }while(cur != init);
    cout << streets[ord[n % sz(ord)]].se << el;
}
