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
typedef vector<ll> vll;

const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

const ll inf = 1e18;
struct edge{
  int to, rev; ll cap, cos, f{0};
  edge(int to, int rev, ll cap, ll cos):to(to), rev(rev), cap(cap), cos(cos){}
};
struct MCMF{
  int n, s, t; 
  vector<vector<edge>> g;
  vi p;  vll dis;
  MCMF(int n, int s, int t): n(n), g(n), s(s), t(t){}
  void addEdge(int s, int t, ll cap, ll cos){
    g[s].pb(edge(t, sz(g[t]), cap, cos));
    g[t].pb(edge(s, sz(g[s])-1, 0, -cos));
  }
  void spfa(int v0){
    dis.assign(n, inf); dis[v0] = 0;
    p.assign(n, -1);
    vector<bool> inq(n);
    queue<int> q({v0});
    while(sz(q)){
      int u = q.front(); q.pop();
      inq[u] = 0;
      for(auto&[v, rev, cap, cos, f] : g[u]){
        if(cap - f > 0 && dis[v] > dis[u] + cos){
          dis[v] = dis[u] + cos, p[v] = rev;
          if(!inq[v]) inq[v] = 1, q.push(v);
        }
      }
    }
  }
  ll min_cos_flow(ll K){
    ll flow = 0, cost = 0;
    while(flow < K){
      spfa(s);
      if(dis[t] == inf) break;
      ll f = K - flow;    
      int cur = t; // Find flow
      while(cur != s){  
        int u = g[cur][p[cur]].to, rev = g[cur][p[cur]].rev;
        f = min(f, g[u][rev].cap - g[u][rev].f);
        cur = u;
      }
      flow += f,  cost += f * dis[t],  cur = t;     // Apply flow
      while(cur != s){
        int u = g[cur][p[cur]].to, rev = g[cur][p[cur]].rev;
        g[u][rev].f += f,  g[cur][p[cur]].f -= f;
        cur = u;
      }
    }
    if(flow < K) assert(0);
    return cost;
  }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    vi a(n);
    forn(i, n)cin >> a[i];
    MCMF mcmf = MCMF(n + 2, 0, 1);
    int ones = 0;
    forn(i, n){
        if(a[i] == 0){
            mcmf.addEdge(i + 2, 1, 1, 0);
        }else{
            mcmf.addEdge(0, i + 2, 1, 0);
            ++ones;
        }
    }
    mcmf.addEdge(2, 3, inf, 1);
    for1(i , n - 2){
        mcmf.addEdge(i + 2, i - 1 + 2, inf, 1);
        mcmf.addEdge(i + 2, i + 1 + 2, inf, 1);
    }
    mcmf.addEdge(n + 1, n, inf, 1);
    int ans = mcmf.min_cos_flow(ones);
    cout << ans << el;
}
