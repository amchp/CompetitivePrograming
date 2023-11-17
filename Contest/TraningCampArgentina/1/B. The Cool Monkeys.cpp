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

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

const ll inf = 1e16;

struct Dinic {
  struct edge {
    int to, rev;
    ll f, cap;
    edge(int to, int rev, ll cap, ll f = 0)
        : to(to), rev(rev), f(f), cap(cap) {}
  };
  vector<vector<edge>> g;
  vector<int> q, dist, work;
  int n, s, t;

  Dinic(int n_) {
    n = n_;
    g.resize(n);
    q.resize(n);
  }

  void addEdge(int s, int t, ll cap) {
    // cout << s << ' ' << t << ' ' << cap << el;
    g[s].pb(edge(t, sz(g[t]), cap));
    g[t].pb(edge(s, sz(g[s]) - 1, 0));
  }

  bool bfs() {
    dist.assign(n, -1), dist[s] = 0;
    int qt = 0;
    q[qt++] = s;
    for (int qh = 0; qh < qt; ++qh) {
      int u = q[qh];
      for (edge e : g[u]) {
        int v = e.to;
        if (dist[v] < 0 && e.f < e.cap)
          dist[v] = dist[u] + 1, q[qt++] = v;
      }
    }
    return dist[t] >= 0;
  }

  ll dfs(int u, ll f) {
    if (u == t)
      return f;
    for (int &i = work[u]; i < sz(g[u]); ++i) {
      edge &e = g[u][i];
      if (e.cap <= e.f)
        continue;
      int v = e.to;
      if (dist[v] == dist[u] + 1) {
        ll df = dfs(v, min(f, e.cap - e.f));
        if (df > 0) {
          e.f += df, g[v][e.rev].f -= df;
          return df;
        }
      }
    }
    return 0;
  }

  ll maxFlow(int s_, int t_) {
    s = s_, t = t_;
    ll max_flow = 0;
    while (bfs()) {
      work.assign(n, 0);
      while (ll delta = dfs(s, inf))
        max_flow += delta;
    }
    // todos los nodos con dist[u]!=-1 vs los que tienen dist[v]==-1 forman el
    // min-cut, (u,v)
    return max_flow;
  }

  vector<ii> cut;
  vector<bool> seen;
  void dfs_cut(int u) {
    seen[u] = 1;
    for (edge &e : g[u]) {
      if (!seen[e.to]) {
        if (dist[e.to] == -1 && e.cap != 0) {
          cut.pb({u, e.to});
        } else if (e.f < e.cap) {
          dfs_cut(e.to);
        }
      }
    }
  }
  vector<ii> min_cut() {
    seen.assign(n, false);
    dfs_cut(s);
    sort(all(cut));
    cut.resize(unique(all(cut)) - cut.begin());
    return cut;
  }
};

ll m, T;

ll sol(vl &a, vl &b) {
  ll n1 = a.size();
  ll n2 = b.size();
  ll n = 2 * (n1 + n2) + 2;
  Dinic g = Dinic(n);
  forn(i, n1 + n2) { g.addEdge(2 * i, 2 * i + 1, 1); }
  forn(i, m) {
    int ind = n1 - i - 1;
    g.addEdge(n - 2, 2 * ind, inf);
    g.addEdge(2 * (n1 + i) + 1, n - 1, inf);
  }
  forn(i, n1) {
    forn(j, n2) {
      if (abs(a[i] - b[j]) < T) {
        g.addEdge(2 * i + 1, 2 * (n1 + j), inf);
        g.addEdge(2 * (n1 + j) + 1, 2 * i, inf);
      }
    }
  }
  ll ans = g.maxFlow(n - 2, n - 1);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(20);
  ll n1, n2;
  cin >> m >> n1 >> n2 >> T;
  vl a(n1), b(n2);
  forn(i, n1) { cin >> a[i]; }
  forn(i, n2) { cin >> b[i]; }
  sort(all(a));
  sort(all(b));
  if (m == sol(a, b) || m == sol(b, a))
    cout << "S" << el;
  else
    cout << "N" << el;
}
