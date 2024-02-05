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

const int L = 24;
int timer, up[nax][L+1], n;
int in[nax], out[nax];
int cnt[nax];
int ans[nax];
vector<ii> g[nax];
void dfs(int u, int p){
  in[u] = ++timer;
  up[u][0] = p;
  for1(i,L) up[u][i] = up[up[u][i-1]][i-1];
  for(auto& [v, i]: g[u]){
    if(v==p) continue;
    dfs(v,u);
  }
  out[u] = ++timer;
}
bool anc(int u, int v){
  return in[u]<= in[v] && out[u]>= out[v];
}
void solve(int root){
  timer = 0;
  dfs(root,root);
}
int lca(int u, int v){
  if(anc(u,v)) return u;
  if(anc(v,u)) return v;
  for(int i= L; i>=0; --i){
    if(!anc(up[u][i],v))
      u = up[u][i];
  }
  return up[u][0];
}



int dfs2(int u, int p){
    int paths = cnt[u];
    int upd = -1;
    for(auto& [v, i]: g[u]){
        if(v==p){
            upd = i;
            continue;
        }
        paths += dfs2(v,u);
    }
    if(upd != -1)ans[upd] = paths;
    return paths;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    forn(i, n - 1){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].pb({v,i});
        g[v].pb({u, i});
    }
    dfs(0, 0);
    int k;
    cin >> k;
    while(k--){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        int a = lca(u, v);
        ++cnt[u];
        ++cnt[v];
        cnt[a] -= 2;
    }
    dfs2(0, 0);
    forn(i, n - 1)cout << ans[i] << ' ';
    cout << el;
}
