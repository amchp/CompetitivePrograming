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

const ll inf = 1e18;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct pt {  // for 3D add z coordinate
	ll x,y;
	pt(){}
	pt(ll x, ll y):x(x),y(y){}
    pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ll norm2(){return *this**this;}
    ll operator*(pt p){return x*p.x+y*p.y;}
    ll operator%(pt p){return x*p.y-y*p.x;}
    bool colinear(pt p, pt q){
		return (q-p)%(*this-p)==eps; 
    }
};

ll len, win;
pt p1, p2;

pt calc(int i, int j){
    ll x = p2.x;
    ll y = p2.y;
    if(i < 3){
        int dy = abs(3 - i);
        int y2 = dy / 2;
        dy %= 2;
        y += y2*2LL*win;
        y += dy*(win - p2.y)*2LL;
    }else if(i > 3){
        int dy = abs(i - 3);
        int y2 = dy / 2;
        dy %= 2;
        y -= y2*2LL*win;
        y -= dy*(p2.y)*2LL;
    }
    if(j < 3){
        int dx = abs(3 - j);
        int x2 = dx / 2;
        dx %= 2;
        x -= x2*2LL*len;
        x -= dx*(p2.x)*2LL;
    }else if(j > 3){
        int dx = abs(j - 3);
        int x2 = dx / 2;
        dx %= 2;
        x += x2*2LL*len;
        x += dx*(len - p2.x)*2LL;
    }
    return pt(x, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> len >> win;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    p1 = pt(x1, y1);
    p2 = pt(x2, y2);
    ll ans = inf;
    forn(i, 7){
        forn(j, 7){
            if(abs(3 - i) + abs(3 - j) != 3)continue;
            if((i == 0 || i == 6) && p1.x == p2.x)continue;
            if((j == 0 || j == 6) && p1.y == p2.y)continue;
            pt nP = calc(i, j);
            // d(i);
            // d(j);
            // d(nP.x);
            // d(nP.y);
            // d((nP - p1).norm2());
            ans = min(ans, (nP - p1).norm2());
        }
    }
    ld fAns = sqrt(ans);
    cout << fAns << el;
}
