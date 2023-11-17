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
const ll mod = 1e9 + 7;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

const int N = 1e5 + 10;
ll t[N << 2], lazy[N << 2];
struct stree{
  int n, l, r;
  ll val;
  ll neutro = 0;
  stree(const vi& a): n(sz(a)){ build(1, 0, n - 1, a); }
  void build(int v, int tl, int tr, const vi& a){
    if(tl == tr){
        t[v] = a[tl];
        lazy[v] = 1;
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a);  build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
    lazy[v] = 1;
  }
  inline ll oper(ll a, ll b){ return (a + b) % mod; }
  inline void push(int v, int tl, int tr){
    if(lazy[v] != 1){
      t[v << 1] *= lazy[v];
      t[v << 1] %= mod;
      lazy[v << 1] *= lazy[v];
      lazy[v << 1] %= mod;
      t[(v << 1) | 1] *= lazy[v];  
      t[(v << 1) | 1] %= mod;
      lazy[(v << 1) | 1] *= lazy[v];
      lazy[(v << 1) | 1] %= mod;
      lazy[v] = 1;
    }
  }
  void upd(int v, int tl, int tr){
    if(tl > r || tr < l) return;
    if(l <= tl && tr <= r){
      t[v] *= val;
      t[v] %= mod;
      lazy[v] *= val;
      lazy[v] %= mod;
      return ;
    }
    push(v, tl, tr);  int tm = (tl + tr) >> 1;
    upd(v << 1, tl, tm);  upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  ll query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;
    if(l <= tl && tr <= r) return t[v];
    push(v, tl, tr);  int tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm + 1, tr));
  }
  void update(int ql, int qr, ll qval){  
    l = ql, r = qr, val = qval, upd(1, 0, n-1); }
  ll query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    cin >> n >> m;
    vi ones(n, 1);
    stree st(ones);
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int l, r, val;
            cin >> l >> r >> val;
            r--;
            st.update(l, r, val);
        }else{
            int l, r;
            cin >> l >> r;
            r--;
            cout << st.query(l, r) << el;
        }
    }
}
