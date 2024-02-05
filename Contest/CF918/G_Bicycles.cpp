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

const ll inf = 1e18;
const int nax = 1000 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

// O ((V+E)*log V)
struct node{
    ll dist;
    int u, sl;
    node(ll d, int u, int sl): dist(d), u(u), sl(sl){}
    bool operator> (node b)const {
        return dist > b.dist;
    }
};

vector <ii> g[nax];
int nsl[nax];
ll d[nax][nax];
void dijkstra(int s, int n){
  forn(i, n){
    forn(j, nax) d[i][j] = inf;
  }
  d[s][nsl[s]] = 0;
  priority_queue <node, vector <node>, greater<node>> q;
  q.push(node(0, s, nsl[s]));
  while(sz(q)){
    node nd = q.top();  q.pop();
    ll dist = nd.dist;
    int u = nd.u;
    int sl = nd.sl;
    if(dist > d[u][sl]) continue;
    // d(u);
    // d(sl);
    // d(dist);
    // cout << "#####" << el;
    for(auto& [v, w]: g[u]){
      int bsl = min(sl, nsl[v]);
      if (d[u][sl] + 1LL*sl*w < d[v][bsl]){
        d[v][bsl] = d[u][sl] + 1LL*sl*w;
        q.push(node(d[v][bsl], v, bsl));
      }
    }
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        forn(i, m){
            int u, v, w;
            cin >> u >> v >> w;
            --u;
            --v;
            g[u].pb(ii(v, w));
            g[v].pb(ii(u, w));
        }
        forn(i, n)cin >> nsl[i];
        dijkstra(0, n);
        ll ans = inf;
        forn(i, nax)ans = min(ans, d[n - 1][i]);
        cout << ans << el;
        forn(i, n)g[i].clear();
    }
}
