#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (ll i = 0; i < (ll)n; ++i)
#define for1(i, n) for (ll i = 1; i <= (ll)n; ++i)
#define fore(i, l, r) for (ll i = (ll)l; i <= (ll)r; ++i)
#define ford(i, n) for (ll i = (ll)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (ll i = (ll)r; i >= (ll)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((ll)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll, ll> ii;
typedef pair<char, ll> pci;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef vector<ll> vl;

const ll inf = 1e9;
const ll nax = 1e6 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

ll dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
ll dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct node{
    ll sum, cnt;
    node(): sum(0), cnt(0){}
    node(ll s, ll c): sum(s), cnt(c){}
};

const ll N = 1e6 + 10;
node t[N << 2];
ll lazy[N << 2];
struct stree{
  ll n, l, r, pos;
  ll val, neutro = 0;
  stree(ll n): n(n){ 
    forn(i, n << 2){
      t[i] = node(0, 0); 
      lazy[i] = 0; 
    }
  }
  inline node oper(node a, node b){ 
    return node(a.sum + b.sum, a.cnt + b.cnt);
  }
  inline void push(ll v){
    if(lazy[v]){
      t[v << 1] = node(0, 0);  
      lazy[v << 1] = lazy[v];
      t[(v << 1) | 1] = node(0, 0);  
      lazy[(v << 1) | 1] = lazy[v];
      lazy[v] = 0;
    }
  }
  ll updl(ll v, ll tl, ll tr){
    if(tl > r || tr < l) return 0;
    if(l <= tl && tr <= r){
      ll ans = t[v].cnt;
      t[v] = node(0, 0);  lazy[v] = 1;
      return ans;
    }
    push(v);  ll tm = (tl + tr) >> 1;
    ll ans = updl(v << 1, tl, tm),  ans2 = updl((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
    return ans + ans2;
  }
  void upd(ll v, ll tl, ll tr){
    if(tl == tr){ t[v] = node(tl * val, val);  return; }
    push(v);
    ll tm = (tl + tr) >> 1;
    if(pos <= tm) upd(v << 1, tl, tm);
    else upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  node query(ll v, ll tl, ll tr){
    if(tl > r || tr < l) return node();
    if(l <= tl && tr <= r) return t[v];
    push(v);  ll tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm + 1, tr));
  }
  ll updatel(ll ql, ll qr){  
    l = ql, r = qr;
    return updl(1, 0, n-1); }
  void update(ll qpos, ll qval){
    pos = qpos;
    val = qval;
    upd(1, 0, n - 1);
  }
  ll query(ll ql, ll qr){ l = ql, r = qr;  return query(1, 0, n-1).sum; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vi a(n);
        ll strt = -1;
        forn(i, n){
            cin >> a[i];
            if(a[i] == 0)strt = i;
        }
        ++strt;
        strt %= n;
        ll cur = strt;
        cur %= n;
        ll ans = 0;
        ll ind = 0;
        stree st(n + 1);
        st.update(n, 1);
        do{
            ll tst = st.query(0, n);
            // d(tst);
            ans = max(tst, ans);
            // d(a[cur]);
            ll cnt = st.updatel(a[cur] + 1, n - 1);
            st.update(a[cur], cnt + 1);
            ++cur;
            cur %= n;
        }while(cur != strt);
        cout << ans << el;
    }
}
