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
#define d(x) cerr << #x << " " << x << el
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
typedef array<int, 4> a4;

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m, q;
    cin >> n >> m >> q;
    vector<ii> g(m);
    forn(i, m){
        cin >> g[i].fi >> g[i].se;
        --g[i].fi, --g[i].se;
    }
    vector<vi> dp(n, vi(n, inf));
    vector<vector<a4>> qrs(m);
    forn(i, q){
        int l, r, s, t;
        cin >> l >> r >> s >> t;
        --s;
        --t;
        --l;
        qrs[l].pb({s, t, r, i});
    }
    vector<bool> ans(q, false);
    ford(i, m){
        int u = g[i].fi;
        int v = g[i].se;
        forn(j, n){
            dp[u][j] = min(dp[u][j], dp[v][j]);
            dp[v][j] = min(dp[u][j], dp[v][j]);
        }
        dp[u][v] = i + 1;
        dp[v][u] = i + 1;
        // d(i);
        for(a4& qr : qrs[i]){
            int s = qr[0];
            int t = qr[1];
            int r = qr[2];
            int ind = qr[3];
            // d(ind);
            // d(s);
            // d(t);
            // d(dp[s][t]);
            // d(r);
            ans[ind] = dp[s][t] <= r;
            // d((dp[s][t] <= r));
        }
    }
    forn(i, q){
        if(ans[i])cout << "Yes" << el;
        else cout << "No" << el;
    }
}
