#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(ll i=0; i< (ll)n; ++i)
#define for1(i,n) for(ll i=1; i<= (ll)n; ++i)
#define fore(i,l,r) for(ll i=(ll)l; i<= (ll)r; ++i)
#define ford(i,n) for(ll i=(ll)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(ll i=(ll)r; i>= (ll)l; --i)
#define pb push_back
#define el '\n'
#define db(x) cerr << #x<< " " << x<<el
#define RAYA cerr << "#####" << el;
#define ri(n) scanf("%d",&n)
#define sz(v) ll(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pll;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;


const ll inf = 1e9;
const ld pi = acos(-1);
const ld eps= 1e-9;

ll dr[] = {1,-1,0, 0,1,-1,-1, 1};
ll dc[] = {0, 0,1,-1,1, 1,-1,-1};

ll numlvl = 300000;

vll dijkstra(const vector<vii>& g, ll s, int n){
  ll bn = n*numlvl;
  vll d(bn);
  forn(i, bn) d[i] = inf;
  d[s] = 0;
  forn(l, numlvl - 1){
    forn(u, n){
      int cu = u + l*n;
      if(d[cu] == inf)continue;
      for(auto& [v, w] : g[u]){
        int cv = v + (l + 1)*n;
        d[cv] = min(d[cv], d[cu] + w);
      }
    }
  }
  return d;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    ll p;
    cin >> p;
    vi n(p), m(p);
    vector<vector<vii>> g(p);
    vi dst(p);
    forn(i, p){
      cin >> n[i] >> m[i];
      g[i] = vector<vii>(n[i]);
      forn(j, n[i]){
        ll h;
        cin >> h;
        g[i][j].pb({j, h});
      }
      forn(_, m[i]){
        ll u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        g[i][u].pb({v, w});
      }
      cin >> dst[i];
      --dst[i];
    }
    
    vector<vll> ds(p);
    forn(i, p){
      ds[i] = dijkstra(g[i], 0, n[i]);
    }
    ll ans = inf;
    forn(l, numlvl){
      // db(l);
      ll cans = 0;
      forn(i, p){
        // db(ds[i][l*n[i] + dst[i]]);
        cans += ds[i][l*n[i] + dst[i]];
      }
      // db(cans);
      // RAYA;
      ans = min(ans, cans);
    }
    assert(ans < inf);
    cout << ans << el;
}