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
#define db(x) cout<< #x<< " " << x<<el
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
typedef array<ll, 20> a20;

const ll inf = 1e9;
const ll kax = 1e6+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

ll dr[] = {1,-1,0, 0,1,-1,-1, 1};
ll dc[] = {0, 0,1,-1,1, 1,-1,-1};

ll phi[kax + 1];

struct node{
  ll sm = 0;
  ll szs = 0, x = 0;
  bool eq = false, lz = false;
  node(){}
  node(ll x, bool eq, ll szs): sm(x), x(x), eq(eq), szs(szs){}
  node(node& a, node& b){
    sm = a.sm + b.sm;
    eq = (a.eq && b.eq) && (a.x == b.x);
    x = eq ? a.x : -1;
    szs = a.szs + b.szs;
  }
  void lazy(ll val){
    x = val;
    sm = 1LL*x*szs;
    eq = true;
    lz = true;
  }
  void lazy1(){
    assert(eq);
    lz = true;
    x = phi[x];
    sm = 1LL*x*szs;
  }
};

const ll N = 2e5 + 200;
node t[N << 2];
struct stree{
  ll n, l, r, val, lz;
  ll neutro = 0;
  stree(vi& a){
    n = sz(a);
    build(1, 0, n-1, a);
  }
  inline void push(ll v){
    if(t[v].lz){
      t[v << 1].lazy(t[v].x);
      t[(v << 1) | 1].lazy(t[v].x);
      t[v].lz = false;
    }
  }
  void build(ll v, ll tl, ll tr, vi& a){
    if(tl == tr){
      t[v] = node(a[tl], true, 1);
      return;
    }
    ll tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = node(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(ll v, ll tl, ll tr){
    if(tl > r || tr < l) return;
    if(l <= tl && tr <= r){
      if(lz == 1 && t[v].eq){
        t[v].lazy1();
        return;
      }if(lz == 2){
        t[v].lazy(val);
        return;
      }
    }
    push(v);  ll tm = (tl + tr) >> 1;
    upd(v << 1, tl, tm);  upd((v << 1) | 1, tm+1, tr);
    t[v] = node(t[v << 1], t[(v << 1) | 1]);
  }
  ll query(ll v, ll tl, ll tr){
    if(tl > r || tr < l) return neutro;
    if(l <= tl && tr <= r){
      return t[v].sm;
    }
    push(v);  ll tm = (tl + tr) >> 1;
    return query(v << 1, tl, tm) + query((v << 1) | 1, tm + 1, tr);
  }
  void update(ll ql, ll qr, ll qval, ll qlz){  
    l = ql, r = qr, val = qval, lz = qlz,  upd(1, 0, n-1);
  }
  ll query(ll ql, ll qr){
    l = ql, r = qr;  return query(1, 0, n-1);
  }
};

void phi_1_to_n() {
  ll n = kax;
  phi[0] = 0;
  phi[1] = 1;
  for (ll i = 2; i <= n; i++)
    phi[i] = i - 1;
  for (ll i = 2; i <= n; i++)
    for (ll j = 2 * i; j <= n; j += i)
      phi[j] -= phi[i];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    phi_1_to_n();
    // Input
    ll n, q;
    cin >> n >> q;
    vi a(n);
    forn(i, n)cin >> a[i];
    stree st(a);
    forn(_, q){
      ll type, l, r;
      cin >> type >> l >> r;
      --l, --r;
      if(type == 1){
        st.update(l, r, 0, 1);
      }else if(type == 2){
        ll x;
        cin >> x;
        st.update(l, r, x, 2);
      }else if(type == 3){
        cout << st.query(l, r) << el;
      }
    }
}