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

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

const int N = 1e5 + 10;
struct stree{
  int n, l, r, idx;
  ll val;
  vl neutro = {0, 0, 0, 0};
  vector<vl> t;
  vector<ii> lazy;
  stree(int n): n(n), t(n << 2, vl(4, 0)), lazy(n << 2, {-1, 0}){}
  inline vl oper(vl& a, vl& b){
    vl ans(4);
    ans[0] = max({a[0], b[0], a[2] + b[1]});
    ans[1] = max(a[1], a[3] + b[1]);
    ans[2] = max(b[2], b[3] + a[2]);
    ans[3] = a[3] + b[3];
    return ans;
  }
  inline void oper2(int v, int tl, int tr){
    if(lazy[v].se < 0){
      t[v][0] = 0;
      t[v][1] = lazy[v].se;
      t[v][2] = lazy[v].se;
    }else{
      t[v][0] = ll(lazy[v].se)*(tr - tl + 1);
      t[v][1] = ll(lazy[v].se)*(tr - tl + 1);
      t[v][2] = ll(lazy[v].se)*(tr - tl + 1);
    }
    t[v][3] = ll(lazy[v].se)*(tr - tl + 1);
  }
  inline void push(int v, int tl, int tr){
    int tm = (tl + tr) >> 1;
    if(lazy[v].fi > lazy[v << 1].fi){
      lazy[v << 1] = lazy[v];
      oper2(v << 1, tl, tm);
    }
    if(lazy[v].fi > lazy[(v << 1) | 1].fi){
      lazy[(v << 1) | 1] = lazy[v];
      oper2((v << 1) | 1, tm + 1, tr);
    }
    lazy[v] = {-1, 0};
  }
  void upd(int v, int tl, int tr){
    if(tl > r || tr < l) return;
    if(l <= tl && tr <= r){
      lazy[v] = {idx, val};
      oper2(v, tl, tr);
      return ;
    }
    push(v, tl, tr);  int tm = (tl + tr) >> 1;
    upd(v << 1, tl, tm);  upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  vl query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;
    if(l <= tl && tr <= r) return t[v];
    push(v, tl, tr);  int tm = (tl + tr) >> 1;
    vl lf = query(v << 1, tl, tm);
    vl rg = query((v << 1) | 1, tm + 1, tr);
    return oper(lf, rg);
  }
  void update(int ql, int qr, int qval, int qidx){  
    l = ql, r = qr, val = qval, idx = qidx, upd(1, 0, n-1); }
  ll query(){ l = 0, r = n - 1;  return query(1, 0, n-1)[0]; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    cin >> n >> m;
    stree st(n);
    forn(i, m){
        int l, r, val;
        cin >> l >> r >> val;
        r--;
        st.update(l, r, val, i);
        cout << st.query() << el;
    }
}
