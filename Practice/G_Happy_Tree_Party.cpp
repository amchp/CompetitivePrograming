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
#define d(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) ll(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vi;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef vector<ld> vd;
typedef __int128_t i128;


const ll inf = 1e18 + 100;
const ll nax = 2e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;
const ll neutro = 1;

ll dr[] = {1,-1,0, 0,1,-1,-1, 1};
ll dc[] = {0, 0,1,-1,1, 1,-1,-1};

inline ll oper(ll a, ll b){ 
    if(inf / a <= b){
        return inf;
    }
    return a*b;
}

struct stree{
  ll n, l, r, pos;
  ll val;  vll t;
  stree(){}
  stree(ll n): n(n), t(n << 2){}
  stree(const vll& a): n(sz(a)), t(n<<2){ build(1, 0, n-1, a); }
  void build(ll v, ll tl, ll tr, const vll& a){// solo para el 2. constructor
    if(tl == tr){ t[v] = a[tl];  return; }
    ll tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  ll query(ll v, ll tl, ll tr){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    if(l <= tl && tr <= r) return t[v];
    ll tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm+1, tr));
  }
  void upd(ll v, ll tl, ll tr){
    if(tl == tr){ t[v] = val;  return; }
    ll tm = (tl + tr) >> 1;
    if(pos <= tm) upd(v << 1, tl, tm);
    else upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(ll idx, ll num){ pos = idx, val = num, upd(1, 0, n-1);}
  ll query(ll ql, ll qr){ 
    assert(ql != 0);
    assert(ql <= qr);
    assert(qr < n);
    l = ql, r = qr;  return query(1, 0, n-1);
  }
};

stree st;
vector<pll> g[nax];
ll len[nax], dep[nax], in[nax], out[nax], head[nax], par[nax], idx;
vll arr;
ll xs[nax];
void dfs_sz(ll u, ll d) {
  dep[u] = d;
  ll &sz = len[u]; sz = 1;
  for( auto &[v, ind] : g[u] ) {
    if( v == par[u] ) continue;
    par[v] = u; dfs_sz(v, d+1);
    sz += len[v];
    if(len[ g[u][0].fi ] < len[v]){
        swap(g[u][0].fi, v);
        swap(g[u][0].se, ind);
    }
  }
  return ;
}
void dfs_hld(ll u) {
  in[u] = idx++;
   /// to initialize the segment tree
  for( auto& [v, ind]  : g[u] ) {
    if( v == par[u] ){
        arr[in[u]] = xs[ind];
        continue;
    }
    head[v] = (v == g[u][0].fi ? head[u] : v);
    dfs_hld(v);
  }
  out[u] = idx-1;
}
void upd_hld( ll u, ll val ) {
  st.upd(in[u], val);
}
ll query_hld( ll u, ll v ) {
  ll val = neutro;
  while( head[u] != head[v] ) {
    if( dep[ head[u] ] < dep[ head[v] ] ) swap(u, v);
    val = oper(val, st.query(in[ head[u] ], in[u]));
    u = par[ head[u] ];
  }
  if (dep[u] == dep[v]) return val;
  if( dep[u] > dep[v] ) swap(u, v);
  val = oper(val, st.query(in[u] + 1, in[v]));
  return val;
}
void build(ll root) {
  idx = 0; /// DS index [0, n)
  par[root] = head[root] = root;
  arr[0] = neutro;
  dfs_sz(root, 0);
  dfs_hld(root);
  st = stree(arr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    ll n, m;
    cin >> n >> m;
    arr.resize(n);
    vector<pll> uv(n - 1);
    forn(i, n - 1){
        ll u, v;
        ll x;
        cin >> u >> v >> x;
        --u, --v;
        xs[i] = x;
        uv[i] = {u, v};
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    build(0);
    forn(_, m){
        ll op, u;
        ll v;
        cin >> op >> u >> v;
        --u;
        if(op == 1){
            --v;
            ll y;
            cin >> y;
            ll div = query_hld(u, v);
            cout << y / div << el;
        }
        if(op == 2){
            ll ndu = uv[u].fi;
            ll ndv = uv[u].se;
            if(par[ndu] == ndv){
                swap(ndu, ndv);
            }
            assert(par[ndv] == ndu);
            upd_hld(ndv, v);
        }
    }
}