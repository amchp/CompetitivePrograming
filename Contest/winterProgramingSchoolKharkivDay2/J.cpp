#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < n; ++i)
#define for1(i, n) for (int i = 1; i <= n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define el '\n'
#define all(x) x.begin(), x.end()
#define d(x) cout << #x << ' ' << x << el;
#define pb push_back
#define sz(x) x.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

struct node{
  ll mn;
  int ind, ans;
  node() {};
  node(ll mn, int ind, int ans): mn(mn), ind(ind), ans(ans){}
};

const int N = 1e5 + 10;
const ll inf = 1e18;
node t[N << 2];
int lazy[N << 2];
struct stree{
  int n, l, r, val, ind;
  node neutro = node(inf, -1, 0);
  stree(vl& a): n(sz(a)){
    forn(i, n << 2){
      lazy[i] = 0;
    }
    build(1, 0, n - 1, a);
  }
  inline node oper(node a, node b){
    if(a.mn < b.mn){
      a.ans += b.ans;
      return a;
    }
    b.ans += a.ans;
    return b;
  }
  inline void push(int v){
    if(lazy[v]){
      t[v << 1].mn += lazy[v];  
      lazy[v << 1] += lazy[v];
      t[(v << 1) | 1].mn += lazy[v];  
      lazy[(v << 1) | 1] += lazy[v];
      lazy[v] = 0;
    }
  }
  void build(int v, int tl, int tr, vl& a){
    if(tl == tr){
      if(a[tl] <= 0){
        t[v] = node(inf, tl, 1);
        return;
      }
      t[v] = node(a[tl], tl, 0);
      return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(int v, int tl, int tr){
    if(tl > r || tr < l) return;
    if(l <= tl && tr <= r){
      t[v].mn += val;  lazy[v] += val;
      return ;
    }
    push(v);  int tm = (tl + tr) >> 1;
    upd(v << 1, tl, tm);  upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd2(int v, int tl, int tr){
    if(tl == tr){
      t[v].mn = inf;
      t[v].ans = 1;
      return;
    }
    push(v);  int tm = (tl + tr) >> 1;
    if(ind <= tm)upd2(v << 1, tl, tm);
    else upd2((v << 1) | 1, tm+1, tr);
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
  void update2(int qind){
    ind = qind;
    upd2(1, 0, n - 1);
  }
  node query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1); }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vl a(n);
    forn(i, n){
      cin >> a[i];
    }
    stree st = stree(a);
    forn(i, q){
        int op, l, r;
        cin >> op >> l >> r;
        --l;
        --r;
        if(op == 1){
            cout << st.query(l, r).ans << el;
        }else{
            int e;
            cin >> e;
            // cout << l << ' ' << r << ' ' << e << el;
            st.update(l, r, -e);
            node nd = st.query(l, r);
            // d(nd.mn);
            while(nd.mn <= 0){
              st.update2(nd.ind);
              nd = st.query(l, r);
              // d(nd.mn);
            }
        }
    }
}