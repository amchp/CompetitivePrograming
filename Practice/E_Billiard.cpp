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

pll extendedEuclid(ll a, ll b){ // a * x + b * y = __gcd(a,b)
	ll x,y;
	if (b==0) return {1,0};
	auto p=extendedEuclid(b,a%b);
	x=p.se;
	y=p.fi-(a/b)*x;
	if(a*x+b*y==-__gcd(a,b)) x=-x, y=-y;
	return {x,y};
}
pair<pll,pll> diophantine(ll a, ll b, ll r) {
  //a*x+b*y=r where r is multiple of __gcd(a,b);
	ll d=__gcd(a,b);
    a/=d; b/=d; r/=d;
	auto p = extendedEuclid(a,b);
	p.fi*=r; p.se*=r;
	// assert(a*p.fi+b*p.se==r);
	return {p,{-b,a}}; // solutions: p+t*ans.se
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    ll n, m, x, y, dx, dy;
    cin >> n >> m >> x >> y >> dx >> dy;
    int as = abs(dx) + abs(dy);
    if(as == 0){
        cout << -1 << el;
        return 0;
    }
    if(as == 1){
        if(dx != 0){
            if(y == 0 || y == m){
                if(dx == 1)cout << n << ' ' << y << el;
                else cout << 0 << ' ' << y << el;
            }else cout << -1 << el;
        }else{
            if(x == 0 || x == n){
                if(dy == 1)cout << x << ' ' << m << el;
                else cout << x << ' ' << 0 << el;
            }else cout << -1 << el;
        }
        return 0;
    }
    if(dx == -1)x = n - x;
    if(dy == -1)y = m - y;
    ll C = x - y;
    // d(C);
    if(C % __gcd(n, m) != 0){
        cout << -1 << el;
        return 0;
    }
    pair<pll,pll> ans = diophantine(n, -m, C);
    ll bx = ans.fi.fi;
    ll by = ans.fi.se;
    ll a = abs(ans.se.fi);
    ll b = abs(ans.se.se);
    // d(bx % a);
    // d(by % b);
    ll mv = 0;
    if(bx > a){
        mv = min(mv, -((bx - 1) / a));
    }
    if(by >= b){
        mv = min(mv, -((by - 1) / b));
    }
    if(bx <= 0){
        mv = max(mv, (abs(bx) + a) / a);
    }
    if(by <= 0){
        mv = max(mv, (abs(by) + b) / b);
    }
    bx = bx + a*mv;
    by = by + b*mv;
    --bx;
    --by;
    // d(bx);
    // d(by);
    int fdx = dx;
    int fdy = dy;
    int ax = bx & 1 ? 0 : n;
    int ay = by & 1 ? 0 : m;
    if(dx == -1)ax = n - ax;
    if(dy == -1)ay = m - ay;
    cout << ax << ' ' << ay << el;
}
