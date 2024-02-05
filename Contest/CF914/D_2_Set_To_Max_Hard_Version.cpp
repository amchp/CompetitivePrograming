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

struct stree{
  int neutro = 1e9, n, l, r, pos, val;  vi t;
  stree(int n): n(n), t(n << 2){}
  stree(const vi& a): n(sz(a)), t(n<<2){ build(1, 0, n-1, a); }
  inline int oper(int a, int b){ return a < b ? a : b; }
  void build(int v, int tl, int tr, const vi& a){// solo para el 2. constructor
    if(tl == tr){ t[v] = a[tl];  return; }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  int query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    if(l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm+1, tr));
  }
  void upd(int v, int tl, int tr){
    if(tl == tr){ t[v] = val;  return; }
    int tm = (tl + tr) >> 1;
    if(pos <= tm) upd(v << 1, tl, tm);
    else upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(int idx, int num){ pos = idx, val = num, upd(1, 0, n-1);}
  int query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1);}
};

struct streel{
  int n, l, r, val, neutro = 0;
  vi t, lazy;
  streel(int n): n(n), t(n << 2), lazy(n << 2){}
  streel(const vi& a): n(sz(a)), t(n<<2), lazy(n<<2, 0){ build(1, 0, n-1, a); }
  inline int oper(int a, int b){ return a > b ? a : b; }
  void build(int v, int tl, int tr, const vi& a){
    if(tl == tr){ 
        t[v] = a[tl];
        return; 
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  inline void push(int v){
    if(lazy[v]){
      t[v << 1] = max(t[v << 1], lazy[v]);  lazy[v << 1] = max(lazy[v], lazy[v << 1]);
      t[(v << 1) | 1] = max(t[(v << 1) | 1], lazy[v]); lazy[(v << 1) | 1] = max(lazy[(v << 1) | 1], lazy[v]);
      lazy[v] = 0;
    }
  }
  void build(int v, int tl, int tr, vi& a){
    if(tl == tr){
      t[v] = a[tl]; return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(int v, int tl, int tr){
    if(tl > r || tr < l) return;
    if(l <= tl && tr <= r){
      t[v] = max(t[v], val);  lazy[v] = max(lazy[v], val);
      return ;
    }
    push(v);  int tm = (tl + tr) >> 1;
    upd(v << 1, tl, tm);  upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  int query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;
    if(l <= tl && tr <= r){
        return t[v];
    }
    push(v);  int tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm + 1, tr));
  }
  void update(int ql, int qr, int qval){  
    l = ql, r = qr, val = qval, upd(1, 0, n-1); }
  int query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1); }
};


stree st(0);
streel stl(0);

bool check(int l, int r, int v){
    int mn = st.query(l, r);
    int mx = stl.query(l, r);
    return mn == v && mx == v;
}

bool sol(){
    int n;
    cin >> n;
    vi a(n), b(n);
    vector<vi> pA(n + 100);
    forn(i, n){
        cin >> a[i];
        pA[a[i]].pb(i);
    }
    forn(i, n){
        cin >> b[i];
    }
    vector<ii> oper;
    forn(i, n){
        if(a[i] > b[i])return false;
        if(a[i] < b[i])oper.pb({b[i], i});
    }
    st = stree(b);
    stl = streel(a);
    sort(all(oper));
    for(auto& [v, i] : oper){
        if(stl.query(i, i) == v)continue;
        vi& vec = pA[v];
        auto it = lower_bound(all(vec), i);
        if(it != vec.end()){
            int hi = (*it);
            if(check(i, hi, v)){
                stl.update(i, hi, v);
                continue;
            }
        }
        if(it != vec.begin()){
            it--;
            int lo = (*it);
            if(check(lo, i, v)){
                stl.update(lo, i, v);
                continue;
            }
        }
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        if(sol())cout << "YES" << el;
        else cout << "NO" << el;
    }
}
