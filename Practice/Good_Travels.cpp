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
typedef pair<bool, ll> pbll;

const int inf = 1e9;
const int nax = 1e6 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int sscc, secc;
int fn[nax];
ll fncc[nax];
pbll dp[nax];

vi g[nax], gr[nax], ts;
bool seen[nax];
int scc[nax], comp;
vi gcc[nax];
void dfs1(int u){
  seen[u] = 1;
  for(int v: g[u]) if(!seen[v]) dfs1(v);
  ts.pb(u);
}
void dfs2(int u){
  scc[u] = comp;
  fncc[comp] += fn[u];
  for(int v : gr[u]) if(scc[v] == -1) dfs2(v);
}
int find_scc(int n){ //TENER CREADO EL GRAFO REVERSADO gr
  forn(i, n) if(!seen[i]) dfs1(i);
  reverse(all(ts));
  memset(scc, -1, sizeof scc);
  for(int u: ts) if(scc[u] == -1) ++comp, dfs2(u);
  return comp;
}

pbll dfs(int ind){
    if(ind == secc){
        return {true, fncc[ind]};
    }
    pbll& ans = dp[ind];
    if(ans.se != -1)return ans;
    ans = {false, 0};
    for(int& v : gcc[ind]){
        pbll nxt = dfs(v);
        if(nxt.fi && ans.se < nxt.se + fncc[ind]){
            ans = {true, nxt.se + fncc[ind]};
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    --s;
    --e;
    forn(i, n)cin >> fn[i];
    forn(i, m){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
        gr[v].pb(u);
    }
    int ncc = find_scc(n);
    forn(i, n){
        vi& vec = gcc[scc[i]];
        for(int& v : g[i]){
            if(scc[i] == scc[v])continue;
            vec.pb(scc[v]);
        }
        sort(all(vec));
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        // cout << scc[i] << ' ' << fncc[scc[i]] << " : ";
        // for(int& v : vec){
        //     cout << v << ' ';
        // }
        // cout << el;
    }
    sscc = scc[s];
    secc = scc[e];
    forn(i, ncc){
        dp[i].se = -1;
    }
    ll ans = dfs(sscc).se;
    cout << ans << el;
}
