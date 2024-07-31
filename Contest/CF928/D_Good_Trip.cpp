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
typedef array<int, 3> a3; 

const int inf = 1e9;
const int nax = 2e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;
const int mod = 1e9 + 7;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct mint{
    int x;
    mint(){}
    mint(int x): x(x){}
    mint(ll x): x(x % mod){}
    mint operator+(mint b){
        int ans = x + b.x;
        if(ans > mod)ans -= mod;
        return ans;
    }
    mint operator-(mint b){
        int ans = x - b.x;
        if(ans < 0)ans += mod;
        return ans;
    }
    mint operator*(mint b){
        return 1LL*x*b.x%mod;
    }
};

mint binpow(mint b, int e){
    mint ans = 1;
    for(; e; b = b*b, e /= 2){
        if(e&1)ans = ans * b;
    }
    return ans;
}

mint inv(mint x){
    return binpow(x, mod - 2);
}

mint fact[nax];

mint C(int n, int r){
    return fact[n]*inv(fact[r]*fact[n - r]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    fact[0] = 1;
    for1(i, nax - 1)fact[i] = fact[i - 1]*mint(i);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        mint sm = 0;
        forn(i, m){
            int u, v, x;
            cin >> u >> v >> x;
            sm = sm + mint(x);
        }
        mint ae = C(n, 2);
        mint base = sm *mint(k)*inv(ae);
        mint avgadd = 0;
        mint csm = 0;
        for1(i, k){
            mint cp = inv(binpow(ae, i));
            mint ncp = binpow(ae - 1, k - i)*inv(binpow(ae, k - i));
            mint prob = cp * ncp;
            mint expadd = C(k, i)*csm*prob;
            avgadd = avgadd + expadd;
            csm = csm + i;
        }
        mint ans = base + avgadd*mint(m);
        cout << ans.x << el;
    }
}
