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
#define RAYA cout << "#####" << el;
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef __int128_t i128;
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
const ll mod = 1e9 + 7;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

ll log_a_to_base_b(ll a, ll b)
{
    ll cnt = 1;
    i128 cur = b;
    while(cur*b <= a){
        cur *= b;
        cnt++;
    }
    return cnt;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int q;
    cin >> q;
    while(q--){
        long long l, r;
        cin >> l >> r;
        ll lb = log_a_to_base_b(l, 2);
        ll ub = log_a_to_base_b(r, 2);
        ll ans = 0;
        // cout << (1LL << lb) << ' ' << (1LL << (ub + 1)) - 1  << el;
        fore(i, lb, ub){
            ll il = (1LL << i);
            ll ir = (1LL << (i + 1)) - 1;
            il = max(il, ll(l));
            ir = min(ir, ll(r));
            ll a = log_a_to_base_b(il, i);
            ll b = log_a_to_base_b(ir, i);
            assert(b - a <= 1);
            if(a == b){
                ans += ((a)*((ir - il + 1LL) % mod)) % mod;
                ans %= mod;
                continue;
            }
            ll xl = il;
            ll xr = ir;
            while(xl + 1 < xr){
                ll m = xl + (xr - xl) / 2;
                ll c = log_a_to_base_b(m, i);
                if(a == c){
                    xl = m;
                }else{
                    xr = m;
                }
            }
            assert(il <= xl);
            assert(xr <= ir);
            assert(xl + 1 == xr);
            ans += (a*((xl - il + 1LL) % mod)) % mod;
            ans %= mod;
            ans += (b*((ir - xr + 1LL) % mod)) % mod;
            ans %= mod;
        }
        cout << int(ans) << el;
    }
}
