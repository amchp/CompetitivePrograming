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

const ll inf = 1e18;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct node{
  bool pass, clm;
  ll mn, mx;
  node(){}
  node(ll mn, ll mx, bool clm, bool pass): mn(mn), mx(mx), clm(clm), pass(pass){}
};


const int N = 3e5 + 10;
node t[N << 2];
ll lazy[N << 2];
struct stree{
  int n, l, r, val;
  node neutro = node(inf, -inf, false, true);
  inline node oper(node a, node b){
    bool pass = true;
    if(a.clm && b.clm){
      pass = a.pass && b.pass && a.mx < b.mn;
    }
    return node(min(a.mn, b.mn), max(a.mx, b.mx), , pass);
  }
  inline void push(int v){
    if(lazy[v]){
      t[v << 1].mn += lazy[v];
      t[v << 1].mx += lazy[v];
      lazy[v << 1] += lazy[v];
      t[(v << 1) | 1].mn += lazy[v]; 
      t[(v << 1) | 1].mx += lazy[v];
      lazy[(v << 1) | 1] += lazy[v];
      lazy[v] = 0;
    }
  }
  stree(vi& a){
    build(1, 0, n - 1, a);
  }
  void build(int v, int tl, int tr, vi& a){
    if(tl == tr){
      t[v] = node(a[tl], a[tr], true); return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(int v, int tl, int tr){
    if(tl > r || tr < l) return;
    if(l <= tl && tr <= r){
      t[v].mn += val;
      t[v].mx += val;
      lazy[v] += val;
      return ;
    }
    push(v);  int tm = (tl + tr) >> 1;
    upd(v << 1, tl, tm);  upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  node query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;
    if(l <= tl && tr <= r) return t[v];
    push(v);  int tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm + 1, tr));
  }
  void update(int ql, int qr, int qval){  
    l = ql, r = qr, val = qval, upd(1, 0, n-1); }
  bool query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1).pass; }
  void checklocalmin(int ql, int qr){

  }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    vi a(n);
    forn(i, n)cin >> a[i];
    int q;
    cin >> q;
    stree st(a);
    while(q--){
        string op;
        int l, r;
        cin >> op >> l >> r;
        if(op == "check"){
            if(st.query(l, r))cout << "YES" << el;
            else cout << "NO" << el;
        }else{
            st.update(l, r);
            st.checklocalmin(l - 1, l - 1);
            st.checklocalmin(r + 1, r + 1);
        }
    }
}
