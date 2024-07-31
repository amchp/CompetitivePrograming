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
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

const int len = 1e7, neutro = 1e9 + 100;
struct node{ 
  int mn, l, r; 
  node(): mn(inf){}
  node(int mn, int l, int r): mn(mn), l(l), r(r){}
};
struct stree{
  vi rts{0};  vector<node> t;
  int n, idx{0}, l, r, val;
  inline int oper(int a, int b){ return a < b ? a : b; }
  stree(const vi &a): n(sz(a)), t(len){ build(0, n-1, a); }
  int build(int tl, int tr, const vi &a){
    int v = idx++;
    if(tl == tr){ t[v].mn = a[tl]; return v; }
    int tm = (tl + tr) >> 1;
    t[v].l = build(tl, tm, a),  t[v].r = build(tm + 1, tr, a);
    t[v].mn = oper(t[t[v].l].mn, t[t[v].r].mn);
    return v;
  }
  int que(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;
    if(l <= tl && tr <= r){
      return t[v].mn;
    }
    int tm = (tl + tr) >> 1;
    return oper(que(t[v].l, tl, tm), que(t[v].r, tm + 1, tr));
  }
  int upd(int prv, int tl, int tr){
    if(tl > r || tr < l) return -1;
    int v = idx++;
    t[v] = t[prv];
    if(l <= tl && tr <= r) {
      t[v].mn = val;
      return v;
    }
    int tm = (tl + tr) >> 1;
    int vl = upd(t[v].l, tl, tm);
    if(vl != -1)t[v].l = vl;
    int vr = upd(t[v].r, tm + 1, tr);
    if(vr != -1)t[v].r = vr;
    t[v].mn = oper(t[v].mn, oper(t[t[v].l].mn, t[t[v].r].mn));
    return v;
  }
  int query(int v, int cl, int cr){
    l = cl, r = cr; 
    return que(rts[min(v, sz(rts) - 1)], 0, n-1);
  }
  void update(int cl, int cr, int x){ l = cl, r = cr, val = x, rts.pb(upd(rts.back(), 0, n-1)); }
  void updatec(int cl, int cr, int x){ l = cl, r = cr,  val = x, rts[sz(rts) - 1] = upd(rts.back(), 0, n-1); }
};

int a[nax], in[nax], out[nax], idx = 0, hgt[nax];
vi g[nax];
bool vis[nax];

void dfs(int u, int d){
  in[u] = idx++;
  hgt[u] = d;
  vis[u] = true;
  for(int& v : g[u]){
      if(vis[v])continue;
      dfs(v, d + 1);
  }
  out[u] = idx++;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(20)<< fixed;
  int n, r;
  cin >> n >> r;
  --r;
  forn(i, n)cin >> a[i];
  forn(i, n - 1){
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(r, 1);
  vi sta(idx, inf);
  stree st = stree(sta);
  forn(i, n)vis[i] = false;
  queue<int> q;
  q.push(r);
  vis[r] = true;
  while(!q.empty()){
    int fu = q.front();
    q.pop();
    int e = sz(q);
    st.update(in[fu], out[fu], a[fu]);
    for(int& v : g[fu]){
      if(vis[v])continue;
      q.push(v);
      vis[v] = true;
    }
    forn(_, e){
      int u = q.front();
      q.pop();
      st.updatec(in[u], out[u], a[u]);
      for(int& v : g[u]){
        if(vis[v])continue;
        q.push(v);
        vis[v] = true;
      }
    }
  }
  int m;
  cin >> m;
  int ans = 0;
  forn(i, m){
    int p, q;
    cin >> p >> q;
    int x = (p + ans) % n;
    int k = (q + ans) % n;
    // d(x);
    // d(k);
    ans = st.query(hgt[x] + k, in[x], out[x]);
    assert(ans != neutro);
    cout << ans << el;
  }
}