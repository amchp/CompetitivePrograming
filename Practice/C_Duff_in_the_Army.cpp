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

vi g[nax];
const int L = 24;
int timer;
pair<int, vi> up[nax][L+1];
int n;
int in[nax], out[nax];
vi mni[nax];

vi merge(vi& a, vi& b){
  vi c;
  int i = 0;
  int j = 0;
  while(i < sz(a) && j < sz(b)){
    if(a[i] == b[j]){
      c.pb(a[i]);
      ++i;
      ++j;
    }else if(a[i] < b[j]){
      c.pb(a[i]);
      ++i;
    }else{
      c.pb(b[j]);
      ++j;
    }
  }
  while(i < sz(a)){
    c.pb(a[i]);
    ++i;
  }
  while(j < sz(b)){
    c.pb(b[j]);
    ++j;
  }
  while(sz(c) > 10)c.pop_back();
  return c;
}

void dfs(int u, int p){
  in[u] = ++timer;
  up[u][0].fi = p;
  up[u][0].se = merge(mni[u], mni[p]);
  for1(i,L){
    up[u][i].fi = up[up[u][i-1].fi][i-1].fi;
    up[u][i].se = merge(up[u][i - 1].se, up[up[u][i - 1].fi][i - 1].se);
    // d(u);
    // d(i);
    // for(int& v: up[u][i].se){
    //   cout << v << ' ';
    // }
    // cout << el;
  }
  for(int v: g[u]){
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
vi sol(int u, int v){
  if(u == v)return mni[u];
  vi ans = {};
  int cur = u;
  for(int i= L; i>=0; --i){
    if(!anc(up[cur][i].fi,v)){
      ans = merge(ans, up[cur][i].se);
      cur = up[cur][i].fi;
      // d(cur);
      // d(i);
    }
  }
  if(!anc(cur, v)){
    ans = merge(ans, up[cur][0].se);
  }
  cur = v;
  for(int i= L; i>=0; --i){
    if(!anc(up[cur][i].fi, u)){
      ans = merge(ans, up[cur][i].se);
      cur = up[cur][i].fi;
      // d(cur);
      // d(i);
    }
  }
  if(!anc(cur, u)){
    ans = merge(ans, up[cur][0].se);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(20);
  int m, q;
  cin >> n >> m >> q;
  forn(i, n - 1){
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  for1(i, m){
    int u;
    cin >> u;
    --u;
    mni[u].pb(i);
  }
  // forn(i, n){
  //   for(int& v: mni[i]){
  //     cout << v << ' ';
  //   }
  //   cout << el;
  // }
  solve(0);
  while(q--){
    int u, v, a;
    cin >> u >> v >> a;
    --u;
    --v;
    vi ans = sol(u, v);
    int e = min(sz(ans), a) ;
    cout << e << ' ';
    forn(i, e){
      cout << ans[i] << ' ';
    }
    cout << el;
  }
}
