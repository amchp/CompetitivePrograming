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
#define db(x) cout<< #x<< " " << x<<el
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


const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

// Corte minimo: vertices con dist[v]>=0 (del lado de src) VS.  dist[v]==-1 (del lado del dst)
// Para el caso de la red de Bipartite Matching (Sean V1 y V2 los conjuntos mas proximos a src y dst respectivamente):
// Reconstruir matching: para todo v1 en V1 ver las aristas a vertices de V2 con it->f>0, es arista del Matching
// Min Vertex Cover: vertices de V1 con dist[v]==-1 + vertices de V2 con dist[v]>0
// Max Independent Set: tomar los vertices NO tomados por el Min Vertex Cover
// Max Clique: construir la red de G complemento (debe ser bipartito!) y encontrar un Max Independet Set
// Min Edge Cover: tomar las aristas del matching + para todo vertices no cubierto hasta el momento, tomar cualquier arista de el
// Complexity O(V^2*E)
const ll inf = 1e18;
struct edge {
  int to, rev; ll cap, f{0};
  edge(int to, int rev, ll cap): to(to), rev(rev), cap(cap){}
};
struct Dinic{
  int n, s, t; ll max_flow = 0;
  vector<vector<edge>> g;
  vi q, dis, work;
  Dinic(int n, int s, int t): n(n), s(s), t(t), g(n), q(n){}
  void addEdge(int s, int t, ll cap){
    g[s].pb(edge(t, sz(g[t]), cap));
    g[t].pb(edge(s, sz(g[s])-1, 0));
  }
  
  bool bfs(){
    dis.assign(n, -1), dis[s] = 0;
    int qt = 0;
    q[qt++] = s;
    forn(qh, qt){
      int u = q[qh];
      for(auto& [v, _, cap, f]: g[u])
        if(dis[v] < 0 && f < cap) dis[v] = dis[u] + 1, q[qt++] = v;
    }
    return dis[t] >= 0;
  }
  ll dfs(int u, ll cur){
    if(u == t) return cur;
    for(int& i = work[u]; i < sz(g[u]); ++i){
      auto& [v, rev, cap, f] = g[u][i];
      if(cap <= f) continue;
      if(dis[v] == dis[u] + 1){
        ll df = dfs(v, min(cur, cap - f));
        if(df > 0){
          f += df, g[v][rev].f -= df;
          return df;
        }
      }
    }
    return 0;
  }
  ll maxFlow(){
    ll cur_flow = 0;
    while(bfs()){
      work.assign(n, 0);
      while(ll delta = dfs(s, inf)) cur_flow += delta;
    }
    max_flow += cur_flow;
    // todos los nodos con dis[u]!=-1 vs los que tienen dis[v]==-1 forman el min-cut, (u,v)
    return max_flow; 
  }
  vii min_cut(){
    maxFlow();
    vii cut;
    forn(u, n){
      if(dis[u] == -1) continue;
      for(auto& e: g[u]) if(dis[e.to] == -1) cut.pb({u, e.to});
    }
    sort(all(cut)),  cut.resize(unique(all(cut)) - cut.begin());
    return cut;
  }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int g, c, t;
    cin >> g >> c >> t;
    vll ing(g), cks(c), tls(t);
    forn(i, c)cin >> cks[i];
    forn(i, g)cin >> ing[i];
    forn(i, t)cin >> tls[i];
    vll cst(c);
    forn(i, c){
        cst[i] += cks[i];
        forn(j, g){
            ll cnt;
            cin >> cnt;
            cst[i] -= cnt*ing[j];
        }
    }
    vector<vi> gr(c);
    forn(i, c){
        int k;
        cin >> k;
        forn(_, k){
            int tl;
            cin >> tl;
            --tl;
            gr[i].pb(tl);
        }
    }
    int N = c + t + 2;
    int s = N - 2, to = N - 1;
    Dinic dnc = Dinic(N, s, to);
    ll ans = 0;
    forn(i, c){
        if(cst[i] <= 0)continue;
        dnc.addEdge(s, i, cst[i]);
        ans += cst[i];
    }
    forn(i, t){
        dnc.addEdge(i + c, to, tls[i]);
    }
    forn(i, c){
        for(int& tl : gr[i]){
            dnc.addEdge(i, tl + c, inf);
        }
    }
    ll mncut = dnc.maxFlow();
    ans -= mncut;
    cout << ans << el;
}