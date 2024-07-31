#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cerr<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

const int mod = 1e9 + 7;

struct mint{
  int x;
  mint(): x(0) {}
  mint(ll x): x(x % mod){}
  mint operator+(mint b){
    int ans = x + b.x;
    if(ans >= mod)ans -= mod;
    return ans;
  }
  mint operator*(mint b){
    return 1LL*x*b.x % mod;
  }
};

vector<ii> g[nax];
int len[nax], dep[nax], in[nax], out[nax], head[nax], par[nax], idx;
int up[nax], down[nax];
int dir[nax];
void dfs_sz( int u, int d ) {
  dep[u] = d;
  int &sz = len[u]; sz = 1;
  forn(i, sz(g[u])) {
    auto& [v, _] = g[u][i];
    if( v == par[u] ) continue;
    par[v] = u; dfs_sz(v, d+1);
    sz += len[v];
    if(len[ g[u][0].fi ] < len[v]) swap(g[u][0], g[u][i]);
  }
  return ;
}
void dfs_hld( int u, int dr) {
  dir[idx] = dr;
  // d(u);
  // d(idx);
  // d(head[u]);
  in[u] = idx++;
  for( auto& [v, ndr] : g[u] ) {
    if( v == par[u] ) continue;
    head[v] = (v == g[u][0].fi ? head[u] : v);
    dfs_hld(v, ndr);
  }
  out[u] = idx-1;
}

void update_hld( int u, int v ) {
  // d(u);
  // d(v);
  while( head[u] != head[v] ) {
    int hu = head[u];
    int hv = head[v];
    if( dep[hu] < dep[ hv] ){
      // d(in[hv]);
      // d(in[v] + 1);
      // cerr << el;
      down[in[hv]] += 1;
      down[in[v] + 1] -= 1; 
      v = par[hv];
    }else{
      // d(in[hu]);
      // d(in[u] + 1);
      // cerr << el;
      up[in[hu]] += 1;
      up[in[u] + 1] -= 1;
      u = par[hu];
    }
  }
  if (dep[u] == dep[v]) return ;
  if( dep[u] > dep[v] ){
    // d(in[v] + 1);
    // d(in[u] + 1);
    // cerr << el;
    up[in[v] + 1] += 1;
    up[in[u] + 1] -= 1;
  }else{
    // d(in[u] + 1);
    // d(in[v] + 1);
    // cerr << el;
    down[in[u] + 1] += 1;
    down[in[v] + 1] -= 1;
  }
}

void build(int root) {
  idx = 0;
  par[root] = head[root] = root;
  dfs_sz(root, 0);
  dfs_hld(root, 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n;
    cin >> n;
    forn(i, n - 1){
      int u, v, dr;
      cin >> u >> v >> dr;
      --u, --v;
      g[u].pb({v, dr});
      g[v].pb({u, -dr});
    }
    build(0);
    int m;
    cin >> m;
    vi lst(m + 1);
    lst[0] = 0;
    for1(i, m){
      cin >> lst[i];
      --lst[i];
    }
    for1(i, m){
      int prv = lst[i - 1];
      int cur = lst[i];
      update_hld(prv, cur);
    }
    mint ans = 0;
    int smup = 0;
    int smdw = 0;
    vector<mint> smp2(m + 2);
    mint p2 = 2;
    smp2[1] = 1;
    fore(i, 2, m + 1){
      smp2[i] = smp2[i - 1] + p2;
      p2 = p2*2;
    }
    forn(i, n){
      // d(i);
      // d(dir[i]);
      smup += up[i];
      smdw += down[i];
      // d(smup);
      // d(smdw);
      if(dir[i] == 1){
        ans = ans + smp2[smup];
      }else if(dir[i] == -1){
        ans = ans + smp2[smdw];
      }
    }
    cout << ans.x << el;
}