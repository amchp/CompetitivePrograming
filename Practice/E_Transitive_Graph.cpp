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

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

vi g[nax], gr[nax], ts;
bool seen[nax];
int scc[nax], comp;
vi gcc[nax];
int cnt[nax];
ll val[nax], cval[nax];
pll dp[nax];
void dfs1(int u){
    seen[u] = 1;
    for(int v: g[u]) if(!seen[v]) dfs1(v);
    ts.pb(u);
}
void dfs2(int u){
    scc[u] = comp;
    cval[comp] += val[u];
    cnt[comp]++;
    for(int v : gr[u]) if(scc[v]  == -1) dfs2(v);
}
void dfs3(int u){
    seen[u] = 1;
    for(int v: g[u]){
        if(scc[u] != scc[v])gcc[scc[u]].pb(scc[v]);
        if(seen[v])continue;
        dfs3(v);
    }
}

pll dfs4(int u){
    pll& ans = dp[u];
    if(ans != pll{-1, -1})return ans;
    ans = {cnt[u], -cval[u]};
    for(int& v : gcc[u]){
        pll nxt = dfs4(v);
        nxt.fi += cnt[u];
        nxt.se -= cval[u];
        ans = max(ans, nxt);
    }
    return ans;
}

int find_scc(int n){ //TENER CREADO EL GRAFO REVERSADO gr
    forn(i, n) if(!seen[i]) dfs1(i);
    reverse(all(ts));
    memset(scc, -1, sizeof scc);
    for(int u: ts){
        if(scc[u] == -1){
            dfs2(u);
            ++comp;
        }
    }
    forn(i, n)seen[i] = false;
    // forn(i, n)cout << scc[i] << ' ';
    // cout << el;
    forn(i, n)if(!seen[i])dfs3(i);
    return comp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        comp = 0;
        forn(i, n){
            g[i].clear();
            gr[i].clear();
            gcc[i].clear();
            cin >> val[i];
            cval[i] = 0;
            dp[i] = {-1, -1};
            cnt[i] = 0;
            seen[i] = false;
        }
        set<ii> ed;
        forn(i, m){
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            ed.insert({u, v});
        }
        for(auto& [u, v] : ed){
            g[u].pb(v);
            gr[v].pb(u);
        }
        int ncomp = find_scc(n);
        // cout << ncomp << el;
        pll ans = {0, 0};
        // forn(i, ncomp){
        //     cout << i << " : ";
        //     for(int v : gcc[i]){
        //         cout << v << ' ';
        //     }
        //     cout << el;
        // }
        forn(i, ncomp){
            if(dp[i] == pll{-1, -1}){
                ans = max(ans, dfs4(i));
            }
        }
        // forn(i, ncomp){
        //     cout << cnt[i] << ' ' << -cval[i]  << el;
        //     // cout << dp[i].fi << ' ' << dp[i].se << el;
        // }
        // cout << el;
        cout << ans.fi << ' ' << -ans.se << el;
    }
}
