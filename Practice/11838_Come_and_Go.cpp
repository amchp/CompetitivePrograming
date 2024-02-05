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
const int nax = 1e6 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

vi g[nax], gr[nax], ts;
bool seen[nax];
int scc[nax], comp;
int a[nax], cnt[nax];
void dfs1(int u){
  seen[u] = 1;
  for(int v: g[u]) if(!seen[v]) dfs1(v);
  ts.pb(u);
}
void dfs2(int u){
  scc[u] = comp;
  ++cnt[comp];
  for(int v : gr[u]) if(scc[v] == -1) dfs2(v);
}
int find_scc(int n){ //TENER CREADO EL GRAFO REVERSADO gr
  forn(i, n) if(!seen[i]) dfs1(i);
  reverse(all(ts));
  for(int u: ts){
    // cout << scc[u] << ' ';
    if(scc[u] == -1) ++comp, dfs2(u);
  }
//   cout << el;
  return comp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    cin >> n >> m;
    while(n != 0 && m != 0){
        comp = 0;
        forn(i, n){
            seen[i] = 0;
            scc[i] = -1;
        }
        // // cout << n << el;
        forn(i, m){
            int u, v, p;
            cin >> u >> v >> p;
            // cout << u << ' ' << v << ' ' << p << el;
            --u;
            --v;
            g[u].pb(v);
            gr[v].pb(u);
            if(p == 2){
                g[v].pb(u);
                gr[u].pb(v);
            }
        }
        int ans = find_scc(n);
        // cout << ans << el;
        cout << (ans == 1) << el;
        forn(i, n){
            seen[i] = 0;
            scc[i] = -1;
            g[i].clear();
            gr[i].clear();
        }
        ts.clear();
        cin >> n >> m;
    }
}
