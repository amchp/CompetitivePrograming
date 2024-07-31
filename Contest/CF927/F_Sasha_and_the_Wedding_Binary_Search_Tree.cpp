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
const int nax = 5e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;
const int mod = 998244353;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

vi a;
ii g[nax];
int val[nax];

int mlt(int a, int b){
    return 1LL*a*b%mod;
}

void dfs(int u){
    if(g[u].fi >= 0)dfs(g[u].fi);
    a.pb(val[u]);
    if(g[u].se >= 0)dfs(g[u].se);
}

int binpow(int b, int e) {
	int ans = 1;
	for (; e; b = 1LL*b*b%mod, e /= 2)
		if (e&1) ans = 1LL*ans*b%mod;
	return ans;
}

int inv(int x){
    return binpow(x, mod - 2);
}

int C(int n, int k){
    int ans = 1;
    fore(i, n - k + 1, n){
        ans = mlt(ans, i);
    }
    int dem = 1;
    for1(i, k){
        dem = mlt(dem, i);
    }
    return mlt(ans, inv(dem));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        a.clear();
        forn(i, n){
            int l, r;
            cin >> l >> r >> val[i];
            --l, --r;
            g[i].fi = l;
            g[i].se = r;
        }
        dfs(0);
        int ans = 1;
        int l = 1;
        int cnt = 0;
        forn(i, n){
            if(a[i] != -1){
                if(cnt != 0)ans = mlt(ans, C(a[i] - l + cnt, cnt));
                l = a[i];
                cnt = 0;
                continue;
            }
            cnt++;
        }
        if(cnt != 0)ans = mlt(ans, C(c - l + cnt, cnt));
        cout << ans << el;
    }
}
