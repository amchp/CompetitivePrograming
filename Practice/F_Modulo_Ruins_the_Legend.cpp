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

typedef __int128_t ll;
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

// ax + by = g
ll gcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while(b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
 
vector<ll> egcds(vector<ll> ns, ll &g) {
    g = 0;
    vector<ll> res;
    for(ll i : ns) {
        ll x, y;
        g = gcd(g, i, x, y);
        for(ll &r : res) r *= x;
        res.pb(y);
    }
    ll sum = 0;
    forn(i, sz(ns)) sum += ns[i] * res[i];
    assert(sum == g);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    cin >> n >> m;
    ll c1 = n;
    ll c2 = ((ll)n*(n + 1) / 2);
    ll c3 = 0;
    vi a(n);
    forn(i, n){
        cin >> a[i];
        c3 += a[i];
        c3 %= m;
    }
    ll g;
    vector<ll> coeff = egcds({c1, c2, m}, g);
    ll target = m - c3;
    ll stp = (target + g - 1) / g;
    ll res = stp * g - target;
    cout << (long long)res << el;
    ll s = (stp*coeff[0] % m + m) % m;
    ll d = (stp*coeff[1] % m + m) % m;

    cout << (long long)s << ' ' << (long long)d << el;
}
