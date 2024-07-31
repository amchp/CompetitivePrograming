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
#define d(x) cout<< #x<< " " << x<<el
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


const int inf = 1e9 + 100;
const int nax = 1e3+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

vi g[nax], gr[nax], ts, gcc[nax];
bool seen[nax];
int cnt[nax], dp[nax];
int scc[nax], comp;
void dfs1(int u){
  seen[u] = 1;
  for(int v: g[u]) if(!seen[v]) dfs1(v);
  ts.pb(u);
}
void dfs2(int u){
  scc[u] = comp;
  for(int v : gr[u]) if(scc[v] == -1) dfs2(v);
}
int find_scc(int n){ //TENER CREADO EL GRAFO REVERSADO gr
  forn(i, n) if(!seen[i]) dfs1(i);
  reverse(all(ts));
  forn(i, n)scc[i] = -1;
  comp = 0;
  for(int u: ts) if(scc[u] == -1) dfs2(u), ++comp;
  return comp;
}

int dfs3(int u){
  int& ans = dp[u];
  if(ans != -1)return ans;
  ans = 0;
  for(int& v : gcc[u]){
    ans = max(ans, dfs3(v));
  }
  ans += cnt[u];
  return ans;
}

int sol(){
  int n, m;
  cin >> n >> m;
  ts.clear();
  forn(u, n){
    g[u].clear();
    gr[u].clear();
    gcc[u].clear();
    seen[u] = false;
    cnt[u] = 0;
    dp[u] = -1;
  }
  forn(i, m){
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].pb(v);
    gr[v].pb(u);
  }
  int sn = find_scc(n);
  forn(u, n){
    ++cnt[scc[u]];
    for(int& v : g[u]){
      if(scc[u] == scc[v])continue;
      gcc[scc[u]].pb(scc[v]);
    }
  }
  int ans = 0;
  forn(u, sn){
    ans = max(ans, dfs3(u));
  }
  // assert(ans != 1);
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(20)<< fixed;
  int t;
  cin >> t;
  while(t--){
    cout << sol() << el;
  }
}