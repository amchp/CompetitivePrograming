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
#define RAYA cout << "######" << el;

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

struct stree{
  int n, l, r, val, idx;
  ll neutro = 0;
  ii neutrol = {0, -1};
  vl t;
  vector<ii> lazyAs;
  vector<pll> lazyAd;
  stree(int n): n(n), t(n << 2), lazyAs(n << 2, neutrol), lazyAd(n << 2, neutrol){}
  inline ll oper(ll a, ll b){ return a + b; }
  inline void updNodeAs(int v, int tl, int tr, ii nval){
    if(lazyAs[v].se >= nval.se)return;
    lazyAs[v] = nval;
    t[v] = ll(tr - tl + 1)*lazyAs[v].fi;
    if(lazyAs[v].se > lazyAd[v].se)lazyAd[v] = neutrol;
  }
  inline void pushAs(int v, int tl, int tr){
    if(lazyAs[v] == neutrol)return;
    int tm = (tl + tr) >> 1;
    updNodeAs(v << 1, tl, tm, lazyAs[v]);
    updNodeAs((v << 1) | 1, tm + 1, tr, lazyAs[v]);
  }
  inline void updNodeAd(int v, int tl, int tr, pll nval){
    lazyAd[v].fi += nval.fi;
    lazyAd[v].se = max(lazyAd[v].se, nval.se);
    t[v] += ll(tr - tl + 1)*nval.fi;
  }
  inline void pushAd(int v, int tl, int tr){
    int tm = (tl + tr) >> 1;
    updNodeAd(v << 1, tl, tm, lazyAd[v]);
    updNodeAd((v << 1) | 1, tm + 1, tr, lazyAd[v]);
  }
  inline void push(int v, int tl, int tr){
    pushAs(v, tl, tr);
    pushAd(v, tl, tr);
    lazyAs[v] = neutrol;
    lazyAd[v] = neutrol;
  }
  void updAs(int v, int tl, int tr){
    if(tl > r || tr < l) return;
    if(l <= tl && tr <= r){
      updNodeAs(v, tl, tr, {val, idx});
      return ;
    }
    push(v, tl, tr);  int tm = (tl + tr) >> 1;
    updAs(v << 1, tl, tm);  updAs((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void updAd(int v, int tl, int tr){
    // d(v);
    // d(tl);
    // d(tr);
    if(tl > r || tr < l) return;
    if(l <= tl && tr <= r){
      // d(t[v]);
      updNodeAd(v, tl, tr, {val, idx});
      // d(t[v]);
      return ;
    }
    // d(t[v]);
    // d(t[v << 1]);
    // d(t[(v << 1) | 1]);
    push(v, tl, tr);  int tm = (tl + tr) >> 1;
    updAd(v << 1, tl, tm);  updAd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  ll query(int v, int tl, int tr){
    // d(v);
    // d(tl);
    // d(tr);
    if(tl > r || tr < l) return neutro;
    if(l <= tl && tr <= r) return t[v];
    push(v, tl, tr);  int tm = (tl + tr) >> 1;
    ll lf = query(v << 1, tl, tm);
    ll rg = query((v << 1) | 1, tm + 1, tr);
    // d(lf);
    // d(rg);
    return oper(lf, rg);
  }
  void updateAs(int ql, int qr, int qval, int qidx){  
    l = ql, r = qr, val = qval, idx = qidx, updAs(1, 0, n-1); }
    void updateAd(int ql, int qr, int qval, int qidx){  
    l = ql, r = qr, val = qval, idx = qidx, updAd(1, 0, n-1); }
  ll query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1); }
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
        int op, l, r;
        cin >> op >> l >> r;
        r--;
        if(op == 1){
            int val;
            cin >> val;
            st.updateAs(l, r, val, i);
        }else if(op == 2){
            int val;
            cin >> val;
            // d(l);
            // d(r);
            // d(val);
            st.updateAd(l, r, val, i);
            // RAYA;
        }else{
            // d(l);
            // d(r);
            cout << st.query(l, r) << el;
            // RAYA;
        }
    }
}
