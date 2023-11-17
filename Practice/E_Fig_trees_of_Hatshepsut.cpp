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

#define neutro 0
struct stree{
  int n;   vector<int> t, lazy;
  stree(int m){
    n = m;    t.resize(n<<2);
    lazy.resize(n<<2);
  }
  stree(vector<int> &a){
    n = sz(a); t.resize(n<<2);   lazy.resize(n<<2);
    build(1,0, n-1, a);
  }
  inline int oper(int a, int b){ return a + b; }
  void build(int v, int tl, int tr, vector<int> &a){
    if(tl==tr){
      t[v]= a[tl]; return ;
    }
    int tm = tl + (tr-tl)/ 2;
    build(v*2, tl, tm, a);
    build(v*2+1, tm+1, tr, a);
    t[v] = oper(t[v*2], t[v*2+1]);
  }
  void push(int v) {
    t[v*2] += lazy[v]; lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v]; lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
  }
  void upd(int v, int tl, int tr, int l, int r, int val) {
    if(tl>r || tr<l) return ;
    if (l <= tl && tr <= r) {
      t[v] += val;
      lazy[v] += val; return ;
    }
    push(v);
    int tm = tl + (tr-tl)/ 2;
    upd(v*2, tl, tm, l, r, val);
    upd(v*2+1, tm+1, tr, l, r, val);
    t[v] = oper(t[v*2], t[v*2+1]);
  }
  int query(int v, int tl, int tr, int l, int r) {
    if(tl>r || tr<l) return neutro;
    if (l <= tl && tr <= r) return t[v];
    push(v);
    int tm = tl + (tr-tl)/ 2;
    return oper(query(v*2, tl, tm, l, r),
               query(v*2+1, tm+1, tr, l, r));
  }
  void upd(int v, int tl, int tr, int l, int r) {
    if(tl>r || tr<l) return ;
    if (l <= tl && tr <= r) {
      t[v] += val;
      lazy[v] += val; return ;
    }
    push(v);
    int tm = tl + (tr-tl)/ 2;
    upd2(v*2, tl, tm, l, r);
    upd2(v*2+1, tm+1, tr, l, r);
    t[v] = oper(t[v*2], t[v*2+1]);
  }
  void upd(int l, int r, int val){ upd(1,0,n-1,l, r,val); }
  void upd2(int l, int r){ upd2(1, 0, n-1, l, r); }
  int query(int l, int r){ return query(1,0,n-1,l,r); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, q;
    cin >> n >> q;
    vi a(n);
    forn(i, n)cin >> a[i];
    stree st(a);
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int l, r;
            cin >> l >> r;
            st.upd2(l, r);
        }else if(op == 2){
            int l, r; x;
            cin >> l >> r >> x;
            st.upd(l, r, x);
        }else if(op == 3){
            int l, r;
            cin >> l >> r;
            st.query(l, r);
        }
    }
}
