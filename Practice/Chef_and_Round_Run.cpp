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
  for(int u: ts) if(scc[u] == -1) ++comp, dfs2(u);
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
        int n;
        cin >> n;
        forn(i, n){
            cin >> a[i];
            cnt[i] = 0;
            scc[i] = -1;
            seen[i] = 0;
            int nxt = (i + a[i] + 1) % n;
            // cout << i << ' ' << nxt << el;
            g[i].pb(nxt);
            gr[nxt].pb(i);
        }
        find_scc(n);
        int ans = 0;
        forn(i, n){
            // cout << scc[i] << ' ';
            if(cnt[scc[i]] > 1 || g[i][0] == i)++ans;
        }
        // cout << el;
        cout << ans << el;
        forn(i, n){
            g[i].pop_back();
            int nxt = (i + a[i] + 1) % n;
            gr[nxt].pop_back();
        }
        ts.clear();
    }
}
