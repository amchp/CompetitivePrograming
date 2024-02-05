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

int k;
vi g[nax];
int vis[nax];
vi ans;

int dfs(int u, int ds){
    vis[u] = ds;
    for(int& v : g[u]){
        if(vis[v] != 0){
            if(ds - vis[v] >= k){
                // d(ds - vis[v]);
                ans.pb(u + 1);
                // d(vis[v]);
                return vis[v];
            }
            continue;
        }
        int dep = dfs(v, ds + 1);
        if(dep != 0){
            // d(dep);
            // d(ds);
            if(ds >= dep)ans.pb(u + 1);
            return dep;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    cin >> n >> m >> k;
    forn(i, m){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    forn(i, n){
        if(vis[i] == 0)dfs(i, 1);
        if(sz(ans))break;
    }
    cout << sz(ans) << el;
    for(int& v : ans)cout << v << ' ';
    cout << el;
}
