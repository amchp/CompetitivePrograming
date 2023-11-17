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
const int nax = 2e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;
const ll MOD = 998244353;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

ll fac[nax];

ll binpow(ll b, int e) {
	ll ans = 1;
	for (; e; b = 1LL*b*b%MOD, e /= 2)
		if (e&1) ans = 1LL*ans*b%MOD;
	return ans;
}

int inv(int x){
    return binpow(x, MOD - 2);
}

void cal(vi& a){
    if(sz(a) == 0){
        cout << 0 << ' ' << 1 << el;
        return;
    }
    int mnM = 0;
    ll f = 1;
    ll lF = 1;
    forn(i, sz(a)){
        mnM += a[i] - 1;
        f *= fac[a[i]];
        f %= MOD;
        lF *= fac[a[i] - 1];
        lF %= MOD;
    }
    // cout << mnM << el;
    // cout << lF << el;
    f *= (fac[mnM] * inv(lF)) % MOD;
    f %= MOD;
    cout << mnM << ' ' << f << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    fac[0] = 1;
    for1(i, nax){
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        char lst = s[0];
        int cnt = 1;
        vi a;
        for1(i, sz(s) - 1){
            if(lst == s[i])cnt++;
            else{
                if(cnt > 1)a.pb(cnt);
                cnt = 1;
            }
            lst = s[i];
        }
        if(cnt > 1)a.pb(cnt);
        cal(a);
    }
}
