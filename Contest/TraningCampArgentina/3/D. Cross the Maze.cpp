#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

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
#define RAYA cout << "=============================" << endl
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

const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 0};
int dc[] = {0, 0, 1, -1, 0};
char mk[] = {'D', 'U', 'R', 'L', 'S'};

const ll inf = 1e18;

struct Dinic{
  struct edge {
    int to, rev; ll f, cap;
    edge(int to, int rev, ll cap, ll f=0) : to(to), rev(rev), f(f), cap(cap) {}
  };
  vector<vector<edge>> g;
  vector<int> q, dist, work;
  int n, s, t;

  Dinic(int n_){
    n = n_; g.resize(n);
    q.resize(n);
  }

  void addEdge(int s, int t, ll cap){
      g[s].pb(edge(t, sz(g[t]), cap));
      g[t].pb(edge(s, sz(g[s])-1, 0));
  }

  bool bfs(){
    dist.assign(n,-1), dist[s]=0;
    int qt=0;
    q[qt++]=s;
    for(int qh=0; qh<qt; ++qh){
      int u =q[qh];
      for(edge e: g[u]){
        int v=e.to;
        if(dist[v]<0 && e.f < e.cap)
          dist[v]=dist[u]+1, q[qt++]=v;
      }
    }
    return dist[t]>=0;
  }

  ll dfs(int u, ll f){
    if(u==t) return f;
    for(int &i=work[u]; i<sz(g[u]); ++i){
      edge &e = g[u][i];
      if(e.cap<=e.f) continue;
      int v=e.to;
      if(dist[v]==dist[u]+1){
        ll df=dfs(v, min(f, e.cap-e.f));
        if(df>0){
          e.f+=df, g[v][e.rev].f-= df;
          return df;
        }
      }
    }
    return 0;
  }

  ll maxFlow(int s_, int t_){
    s = s_, t = t_;
    ll max_flow=0;
    while(bfs()){
      work.assign(n,0);
      while(ll delta=dfs(s,inf))
        max_flow+=delta;
    }
    // todos los nodos con dist[u]!=-1 vs los que tienen dist[v]==-1 forman el min-cut, (u,v)
    return max_flow;
  }

  vector<ii> cut;
  vector<bool> seen;
  void dfs_cut(int u){
    seen[u] = 1;
    for(edge &e : g[u]){
      if(!seen[e.to]){
        if(dist[e.to]==-1 && e.cap!=0){
          cut.pb({u,e.to});
        }else if(e.f < e.cap){
          dfs_cut(e.to);
        }
      }
    }
  }
  vector<ii> min_cut(){
    seen.assign(n, false);
    dfs_cut(s);
    sort(all(cut));
    cut.resize(unique(all(cut)) - cut.begin());
    return cut;  
  }
};

int n, a, b;

int getCoord(int x, int y, int t, bool out) {
  int time = t * a * b;
  int pos = x * b;
  return 2 * (y + pos + time) + out + 2;
}

ii getReverseCoord(int node){
  ii ans;
  node -= 2;
  node /= 2;
  ans.se = node % b;
  node /= b;
  ans.fi = node % a;
  return ans;
}

Dinic din = Dinic(0);
vector<ii> s, e;
int exitNodes;

void addLayer(int t1, int t2){
  forn(i, a) {
      forn(j, b) {
        int node = getCoord(i, j, t1, true);
        forn(k, 5) {
          if(i + dr[k] < 0 || i + dr[k] >= a || j + dc[k] < 0 || j + dc[k] >= b)continue;
          int dNode = getCoord(i + dr[k], j + dc[k], t2, false);
          din.addEdge(node, dNode, 1);
        }
      }
    }
}

void dfs(int ind, vector<char> &moves){
  // cout << ind << ' ';
  if(ind >= exitNodes){
    int indE = ind - exitNodes;
    int x = e[indE].first;
    int y = e[indE].second;
    cout << x + 1 << ' ' << y + 1 << ' ';
    return;
  }
  forn(j, din.g[ind].size()){
    if(din.g[ind][j].f == 1){
      int to = din.g[ind][j].to;
      ii coordF = getReverseCoord(ind);
      ii coordT = getReverseCoord(to);
      int x = coordF.fi;
      int y = coordF.se;
      int dx = coordT.fi;
      int dy = coordT.se;
      int out = to < exitNodes;
      if(out){
        forn(k, 5){
          if(x + dr[k] == dx && y + dc[k] == dy){
            moves.pb(mk[k]);
            break;
          }
        }
      }
      dfs(to + out, moves);
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(20);
  cin >> n >> a >> b;
  forn(i, n) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    s.pb(make_pair(x, y));
  }
  forn(i, n) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    e.pb(make_pair(x, y));
  }
  int tTime = 200;
  int dN = getCoord(0, 0, tTime, false) + n;
  exitNodes = getCoord(0, 0, tTime, false);
  din = Dinic(dN);
  forn(i, n) {
    int x = s[i].fi;
    int y = s[i].se;
    din.addEdge(0, getCoord(x, y, 0, false), 1);
    din.addEdge(exitNodes + i, 1, 1);
  }
  for1(t, tTime - 1) {
    forn(i, n) {
      int x = e[i].fi;
      int y = e[i].se;
      din.addEdge(getCoord(x, y, t, true), exitNodes + i,
                  inf);
    }
  }
  int nodes = exitNodes / 2;
  for1(i, nodes - 1) { din.addEdge(2 * i, 2 * i + 1, 1); }
  int mF = 0;
  int t = 0;
  while (mF != n) {
    addLayer(t, t+1);
    t++;
    mF += din.maxFlow(0, 1);
  }
  cout << t << el;
  forn(i, n){
    int x = s[i].fi;
    int y = s[i].se;
    cout << x + 1 << ' ' << y + 1 << ' ';
    vector<char> moves;
    dfs(getCoord(x, y, 0, 0)+1, moves);
    forn(j, moves.size()){
      cout << moves[j];
    }
    forn(j, t - (int)moves.size()){
      cout << 'P';
    }
    cout << el;
  }
}
